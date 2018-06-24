#include "Calculadora.h"

Calculadora::Variable::Variable(Id idVariable) {
    _idVariable = idVariable;
    _valor = 0;
}

void Calculadora::Variable::asignarValor(int valor) {
    _valor = valor;
}

int Calculadora::Variable::valor() const{
    return _valor;
}

Id Calculadora::Variable::id() const{
    return _idVariable;
}

Calculadora::Calculadora(Programa programa) {
    _programa = programa;
}

int Calculadora::posVariable(Id idVariable) const{
    int res = -1;
    for(int i = 0; i < _memoria.size(); i++){
        if(idVariable == _memoria[i].id()){
            res = i;
        }
    }
    return res;
}

bool Calculadora::variableExiste(Id idVariable) const{
    return posVariable(idVariable) != -1;
}

void Calculadora::asignarVariable(Id idVariable, int valor) {
    if(variableExiste(idVariable)){
        _memoria[posVariable(idVariable)].asignarValor(valor);
    }else{
        Variable var = Variable(idVariable);
        var.asignarValor(valor);
        _memoria.push_back(var);
    }
}

int Calculadora::valorVariable(Id idVariable) const {
    if (variableExiste(idVariable)) {
        return _memoria[posVariable(idVariable)].valor();
    } else {
        return 0;
    }
}

int Calculadora::devolverYSacarDePila(){
    int res = 0;
    if(_pila.size() != 0){
        res = _pila[_pila.size() - 1];
        _pila.pop_back();
    }
    return res;
}

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

