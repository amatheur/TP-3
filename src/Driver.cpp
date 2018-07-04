//
// Created by Manuel on 4/7/2018.
//

#include "Driver.h"
#include "Calculadora.h"

Driver::Driver(){
    _prog = Programa();
}

Driver::~Driver() {

}

void Driver::begin(string rutina) {
    _prog.instruccion(rutina,0);
}

void Driver::end(string rutina) {
    _prog.instruccion(rutina,_prog.Longitud(rutina)-1);
}

void Driver::push(int n) {
    ;
}

void Driver::add() {

}

void Driver::sub() {

}

void Driver::mul() {

}

void Driver::read(string variable) {

}

void Driver::write(string variable) {

}

void Driver::jump(string rutina) {

}

void Driver::jumpz(string rutina) {

}

void Driver::comenzarEjecucion(string rutina, int capacidadVentana) {

}

void Driver::asignarVariable(string idVariable, int valor) {

}

bool Driver::ejecucionFinalizada() const {
    return false;
}

void Driver::ejecutarInstruccionActual() {

}

int Driver::topePila() const {
    return 0;
}

int Driver::valorVariable(string idVariable) const {
    return 0;
}

int Driver::valorHistoricoVariable(string idVariable, int t) const {
    return 0;
}

int Driver::instanteActual() const {
    return 0;
}
