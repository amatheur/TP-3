#include "Calculadora.h"

Calculadora::Calculadora(Programa prog, Rutina rut, int tam) {
    _programa = DiccionarioTrie();
    _variables = DiccionarioTrie();
    _nInstruccionActual = 0;
    _instanteActual = 0;
    _tamVentana = tam;
    int nRutina = 0;
    Programa::ItPrograma itProg = prog.CrearIt();
    int nInstruccion;

    while(nRutina < prog.CantidadRutinas()){

        nInstruccion = 0;

        Rutina nombreRutActual = get<0>(itProg.Actual());

        ItRut itNuevaRut;

        if(_programa.Definido(nombreRutActual)){

            itNuevaRut = _programa.BuscarIterador(nombreRutActual);
        } else{
            Rut list;

            itNuevaRut = _programa.Definir(nombreRutActual, list);
        }
        Lista_Enlazada<Instruccion>::iterator itInstActual = get<1>(itProg.Actual()).begin();

        while(nInstruccion < get<1>(itProg.Actual()).size()){

            Instruccion instActual= *(itInstActual);
            if(instActual.operacion() == oWrite or instActual.operacion() == oRead){
                ItVar itVariable;
                if(!_variables.Definido(instActual.variable())){
                    _ventanas.push_front(Ventana(tam));
                    ItListVent itVentana = _ventanas.begin();
                    Lista_Enlazada<int> listVar;
                    Var nuevaVar(itVentana, listVar);
                    itVariable = _variables.Definir(instActual.variable(), nuevaVar);
                } else {
                    itVariable = _variables.BuscarIterador(instActual.variable());
                }
                InstConIt instConIt(instActual.operacion(), itVariable, _programa.CrearIt(), 0);
                get<1>(itNuevaRut.Actual()).push_back(instConIt);

            } else if(instActual.operacion() == oPush){
                int val = instActual.Valor();
                InstConIt instConIt(oPush, _variables.CrearIt(), _programa.CrearIt(), val);
                get<1>(itNuevaRut.Actual()).push_back(instConIt);

            } else {
                InstConIt instConIt(instActual.operacion(), _variables.CrearIt(), _programa.CrearIt(), 0);
                get<1>(itNuevaRut.Actual()).push_back(instConIt);
            }
            nInstruccion ++;
            itInstActual++;
        }
        itProg.Avanzar();
        nRutina ++;
    }
    _rutinaActual = _programa.BuscarIterador(rut);
    _instruccionAEjecutar = get<1>(_rutinaActual.Actual()).begin();
}

bool Calculadora::Finalizo() const{
    return (_nInstruccionActual >= get<1>(_rutinaActual.Actual()).size());
}

void Calculadora::Sigo() const {
    if(_nInstruccionActual < get<1>(_rutinaActual.Actual()).size() - 1){
        _instruccionAEjecutar++;
    }
}

int Calculadora::DevolverYSacarDePila() {
    int res = 0;
    if(!_pila.empty()){
        res = _pila.top();
        _pila.pop();
    }
    return res;
}

void Calculadora::EjecutarUnPaso() {
    InstConIt instActual = *(_instruccionAEjecutar);
    Operacion operacionActual = instActual._op;

    int s1 = 0;
    int s2 = 0;

    switch (operacionActual){
        case oPush:
            _pila.push(instActual._val);
            _nInstruccionActual++;
            Sigo();
            break;
        case oAdd:
            s1 = DevolverYSacarDePila();
            s2 = DevolverYSacarDePila();
            _pila.push(s1 + s2);
            _nInstruccionActual++;
            Sigo();
            break;
        case oSub:
            s1 = DevolverYSacarDePila();
            s2 = DevolverYSacarDePila();
            _pila.push(s2 - s1);
            _nInstruccionActual++;
            Sigo();
            break;
        case oMul:
            s1 = DevolverYSacarDePila();
            s2 = DevolverYSacarDePila();
            _pila.push(s2*s1);
            _nInstruccionActual++;
            Sigo();
            break;
        case oWrite:
            s1 = DevolverYSacarDePila();
            get<1>(get<1>(instActual._var.Actual())).push_back(s1);
            tuple<int, int> aRegistrar(_instanteActual, s1);
            (*(get<0>(get<1>(instActual._var.Actual())))).registrar(aRegistrar);
            _nInstruccionActual++;
            Sigo();
            break;
        case oRead:
            _pila.push(get<1>(get<1>(instActual._var.Actual())).back());
            _nInstruccionActual++;
            Sigo();
            break;
        case oJump:
            _rutinaActual = instActual._rut;
            _nInstruccionActual = 0;
            if(_nInstruccionActual < get<1>(_rutinaActual.Actual()).size() - 1){
                _instruccionAEjecutar = get<1>(_rutinaActual.Actual()).begin();
            }
            break;
        case oJumpz:
            s1 = DevolverYSacarDePila();
            if(s1 == 0){
                _rutinaActual = instActual._rut;
                _nInstruccionActual = 0;
                if(_nInstruccionActual < get<1>(_rutinaActual.Actual()).size() - 1){
                    _instruccionAEjecutar = get<1>(_rutinaActual.Actual()).begin();
                }
            } else {
                _nInstruccionActual++;
                Sigo();
            }
            break;
    }
    _instanteActual++;
}

void Calculadora::AsignarVariable(Variable var, int val) {
    get<1>(_variables.Significado(var)).back() = val;
    tuple aRegistrar(_instanteActual, val);
    (*(get<0>(_variables.Significado(var)))).registrar(aRegistrar);
}

int Calculadora::InstanteActual() const{
    return _instanteActual;
}

int Calculadora::IndiceInstActual() const {
    return _nInstruccionActual;
}

int Calculadora::BuscarEnVentana(Ventana<tuple<int, int>> &v, int instante, int inicio, int fin) const{
    if(inicio == fin){
        return get<1>(v[inicio]);
    }
    int medio = (inicio + fin) / 2;
    if(get<0>(v[medio]) <= instante){
        if(get<0>(v[medio + 1]) > instante){
            return get<1>(v[medio]);
        } else {
            return BuscarEnVentana(v, instante, medio + 1, fin);
        }
    } else {
        return BuscarEnVentana(v, instante, inicio, medio);
    }
}

int Calculadora::ValorHistorico(Variable var, int inst) const{
    if(inst >= get<0>((*(get<0>(_variables.Significado(var))))[0])){
        return BuscarEnVentana((*(get<0>(_variables.Significado(var)))), inst, 0, _tamVentana);
    } else {
        Lista_Enlazada<int>::iterator it = get<1>(_variables.Significado(var)).begin();
        advance(it, inst);
        return *(it);
    }
}

int Calculadora::ValorActual(Variable var) const{
    return get<1>(_variables.Significado(var)).back();
}

Pila<int> Calculadora::pila() const {
    return _pila;
}

Calculadora::InstConIt::InstConIt(Operacion op, ItVar var, ItRut rut, int val) {
    _op = op;
    _var = var;
    _rut = rut;
    _val = val;
}