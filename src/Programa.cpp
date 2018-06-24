#include "Programa.h"

Programa::Rutina::Rutina(Id nombre) {
    _idRutina = nombre;
}

vector<Instruccion> Programa::Rutina::instrucciones() const {
    return _instrucciones;
}

void Programa::Rutina::agregarInstruccion(Instruccion instruccion) {
    _instrucciones.push_back(instruccion);
}

Id Programa::Rutina::idRutina() const {
    return _idRutina;
}

int Programa::Rutina::longitud() const {
    return _instrucciones.size();
}

Programa::Programa() {}

bool Programa::esRutinaExistente(Id idRutina) const {
    bool res = false;
    for(int i = 0; i < _rutinas.size(); i++){
        if(_rutinas[i].idRutina() == idRutina){
            res = true;
        }
    }
    return res;
}

int Programa::posRutina(Id idRutina) const {
    int res = -1;
    if(esRutinaExistente(idRutina)){
        for(int i = 0; i < _rutinas.size(); i++){
            if(_rutinas[i].idRutina() == idRutina)
            {
                res = i;
            }
        }
    }
    return res;
}

void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion) {
    if(esRutinaExistente(idRutina)){
        _rutinas[posRutina(idRutina)].agregarInstruccion(instruccion);
    }else{
        Rutina rutinaNueva = Rutina(idRutina);
        rutinaNueva.agregarInstruccion(instruccion);
        _rutinas.push_back(rutinaNueva);
    }
}

int Programa::longitud(Id idRutina) const {
    return _rutinas[posRutina(idRutina)].longitud();
}

Instruccion Programa::instruccion(Id idRutina, int i) const {
    return _rutinas[posRutina(idRutina)].instrucciones()[i];
}


