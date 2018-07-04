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
                if(!_variables.Definido(instActual.Variable())){
                    _ventanas.push_front(Ventana(tam));
                    ItListVent itVentana = _ventanas.begin();
                    Lista_Enlazada<int> listVar;
                    Var nuevaVar(itVentana, listVar);
                    itVariable = _variables.Definir(instActual.Variable(), nuevaVar);
                } else {
                    itVariable = _variables.BuscarIterador(instActual.Variable());
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

bool Calculadora::Finalizo() {
    return (_nInstruccionActual >= get<1>(_rutinaActual.Actual()).size())
}
/*
void Calculadora::ejecutar(Id Rutina) {
    int numeroInstruccion = 0;
    Id rutinaActual = Rutina;
    Instruccion instActual = _programa.instruccion(rutinaActual, numeroInstruccion);

    int longRutinaActual = _programa.longitud(rutinaActual);

    bool enRango = 0 <= numeroInstruccion && numeroInstruccion < longRutinaActual;

    while(_programa.esRutinaExistente(rutinaActual) && enRango){
        int s1 = 0;
        int s2 = 0;

        switch (instActual.operacion()){
            case PUSH:
                _pila.push_back(instActual.valor());
                break;
            case ADD:
                s1 = devolverYSacarDePila();
                s2 = devolverYSacarDePila();
                _pila.push_back(s1 + s2);
                break;
            case SUB:
                s1 = devolverYSacarDePila();
                s2 = devolverYSacarDePila();
                _pila.push_back(s2 - s1);
                break;
            case MUL:
                s1 = devolverYSacarDePila();
                s2 = devolverYSacarDePila();
                _pila.push_back(s2*s1);
                break;
            case WRITE:
                s1 = devolverYSacarDePila();
                asignarVariable(instActual.nombre(), s1);
                break;
            case READ:
                _pila.push_back(valorVariable(instActual.nombre()));
                break;
            case JUMP:
                rutinaActual = instActual.nombre();
                numeroInstruccion =-1;
                break;
            case JUMPZ:
                s1 = devolverYSacarDePila();
                if(s1 == 0){
                    rutinaActual = instActual.nombre();
                    numeroInstruccion = -1;
                }
                break;
        }
        numeroInstruccion += 1;
        
        if(_programa.esRutinaExistente(rutinaActual)){
            longRutinaActual = _programa.longitud(rutinaActual);
            enRango = 0 <= numeroInstruccion && numeroInstruccion < longRutinaActual;
            if(enRango) {
                instActual = _programa.instruccion(rutinaActual, numeroInstruccion);
            }
        }


    }
}
*/
