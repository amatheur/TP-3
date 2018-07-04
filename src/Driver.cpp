//
// Created by Manuel on 4/7/2018.
//

#include "Driver.h"
#include "Calculadora.h"

Driver::Driver() {
    _prog = Programa();
}

Driver::~Driver() {

}

void Driver::begin(string rutina) {
    _actual = rutina;
}

void Driver::end(string rutina) {
    _actual = "";
}

void Driver::push(int n) {
    _prog.AgregarInstruccion(_actual,Instruccion(n));
}

void Driver::add() {
    _prog.AgregarInstruccion(_actual,Instruccion(oAdd));
}

void Driver::sub() {
    _prog.AgregarInstruccion(_actual,Instruccion(oSub));
}

void Driver::mul() {
    _prog.AgregarInstruccion(_actual,Instruccion(oMul));
}

void Driver::read(string variable) {
    _prog.AgregarInstruccion(_actual,Instruccion(oRead, variable));
}

void Driver::write(string variable) {
    _prog.AgregarInstruccion(_actual,Instruccion(oWrite, variable));
}

void Driver::jump(string rutina) {
    _prog.AgregarInstruccion(_actual,Instruccion(oJump,rutina));
}

void Driver::jumpz(string rutina) {
    _prog.AgregarInstruccion(_actual,Instruccion(oJumpz,rutina));
}

void Driver::comenzarEjecucion(string rutina, int capacidadVentana) {
    _calc = Calculadora(_prog, rutina, capacidadVentana);
}

void Driver::asignarVariable(string idVariable, int valor) {
    _calc.AsignarVariable(idVariable, valor);
}

bool Driver::ejecucionFinalizada() const {
    return _calc.Finalizo();
}

void Driver::ejecutarInstruccionActual() {
    _calc.EjecutarUnPaso();
}

int Driver::topePila() const {
    if(!_calc.pila().empty()) {
        return _calc.pila().top();
    }else{
        return 0;
    }
}

int Driver::valorVariable(string idVariable) const {
    return _calc.ValorActual(idVariable);
}

int Driver::valorHistoricoVariable(string idVariable, int t) const {
    return _calc.ValorHistorico(idVariable, t);
}

int Driver::instanteActual() const {
    return _calc.InstanteActual();
}
