#include "Programa.h"

Programa::Rutina::Rutina(string nombre) {
    _idRutina = nombre;
}

vector<Instruccion> Programa::Rutina::instrucciones() const {
    return _instrucciones;
}

void Programa::Rutina::agregarInstruccion(Instruccion instruccion) {
    _instrucciones.push_back(instruccion);
}

string Programa::Rutina::idRutina() const {
    return _idRutina;
}

int Programa::Rutina::longitud() const {
    return _instrucciones.size();
}

Programa::Programa() {}

bool Programa::esRutinaExistente(string idRutina) const {
    return  (this->_rutinas.count(idRutina) == 1);
}

Programa::Rutina* Programa::posRutina(string idRutina) const {
    this->_rutinas.at(idRutina);
}

void Programa::agregarInstruccion(string idRutina, Instruccion instruccion) {
    if(esRutinaExistente(idRutina)){

    }else{
        Rutina rutinaNueva = Rutina(idRutina);
        rutinaNueva.agregarInstruccion(std::move(instruccion));
        _rutinas.[idRutina] = rutinaNueva;
    }
}

int Programa::longitud(string idRutina) const {
    return _rutinas[posRutina(idRutina)].longitud();
}

Instruccion Programa::instruccion(string idRutina, int i) const {
    return _rutinas[posRutina(idRutina)].instrucciones()[i];
}


