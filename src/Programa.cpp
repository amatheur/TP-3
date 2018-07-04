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
    return  (this->_rutinas.Definido(idRutina) == 1);
}

Programa::Rutina* Programa::posRutina(string idRutina) const {
    this->_rutinas.Significado(idRutina);
}

void Programa::agregarInstruccion(string idRutina, Instruccion instruccion) {
    if(esRutinaExistente(idRutina)){
        (this->posRutina(idRutina))->agregarInstruccion(instruccion);

    }else{
        Rutina rutinaNueva = Rutina(idRutina);
        rutinaNueva.agregarInstruccion(std::move(instruccion));
        this->_rutinas[idRutina]= rutinaNueva;
    }
}

int Programa::longitud(string idRutina) const {
    if (this->esRutinaExistente(idRutina)){
    Rutina* Aux = (this->_rutinas.Significado(idRutina));
    Aux->instrucciones().size();
    }
}

Instruccion Programa::instruccion(string idRutina, int i) const {
    Rutina* Aux =  this->_rutinas[idRutina];
    return *Aux->instrucciones()[i];
}


