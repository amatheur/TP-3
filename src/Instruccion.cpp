#include "Instruccion.h"
#include "Utiles.h"

Instruccion Instruccion::CrearInstPila(Operacion op){
    _op = op;
}

Instruccion Instruccion::CrearInstPush(int val) {
    _op = oPush;
    _val = val;
}

Instruccion Instruccion::CrearInstRut(Operacion op, Rutina rut){
    _op = op;
    _rut = rut;
}

Instruccion Instruccion::CrearInstVar(Operacion op, Variable var) {
    _op = op;
    _var = var;
}

Rutina Instruccion::Rutina() const {
    return _rut;
}

Variable Instruccion::Variable() const {
    return _var;
}

Operacion Instruccion::operacion() const {
    return _op;
}

int Instruccion::Valor() const {
    return _val;
}


/*
Instruccion::Instruccion(Operacion operacion, int valor){
    _operacion = operacion;
    _valor = valor;
}

Instruccion::Instruccion(Operacion operacion) {
    _operacion = operacion;
}

Instruccion::Instruccion(Operacion operacion, Id nombre) {
    _operacion = operacion;
    _nombre = nombre;
}

Operacion Instruccion::operacion() const {
    return _operacion;
}

int Instruccion::valor() const {
    return _valor;
}

Id Instruccion::nombre() const {
    return _nombre;
}



 */