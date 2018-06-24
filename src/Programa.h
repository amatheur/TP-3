#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <iostream>
#include <vector>
#include <string>

#include "Instruccion.h"


using namespace std;
// La clase Programa sirve para representar una secuencia de instrucciones.
//
//     Programa programa;
//
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 10));
//     programa.agregarInstruccion("A", Instruccion(OP_PUSH, 20));
//     programa.agregarInstruccion("A", Instruccion(OP_ADD));
//     programa.agregarInstruccion("A", Instruccion(OP_JUMP, "A"));
//
//     programa.agregarInstruccion("B", Instruccion(OP_PUSH, 30));
//     programa.agregarInstruccion("B", Instruccion(OP_WRITE, "x"));
//
// Corresponde a las siguientes rutinas:
//
//     --- A ---
//       push(10)
//       push(20)
//       add
//       jump(A)
//
//     --- B ---
//       push(30)
//       write(x)

class Programa {
public:
    class Rutina;
	// Inicialmente no hay ninguna rutina.
	Programa();

	// Agrega una instrucción a la rutina indicada.
	// Si la rutina indicada no existe, crea una nueva rutina
	// con dicho nombre.
	void agregarInstruccion(Id idRutina, Instruccion instruccion);

	// Devuelve True si idRutina representa una rutina existente.
	bool esRutinaExistente(Id idRutina) const;

	// Devuelve la longitud (cantidad de instrucciones) de la rutina
	// indicada.
	//
	// Precondición: esRutinaExistente(idRutina)
	int longitud(Id idRutina) const;

	// Devuelve la i-ésima instrucción de la rutina indicada.
	//
	// Precondición:
	//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
	Instruccion instruccion(Id idRutina, int i) const;

    class Rutina {
    public:
        //crea una rutina vacia, de id idRutina
        Rutina(Id nombre);

        // devuelve el vector de instrucciones de la rutina
        vector<Instruccion> instrucciones() const;

        //agraga una instruccion al vector de instrucciones de la rutina
        void agregarInstruccion(Instruccion instruccion);

        //devuelve el id de la rutina
        Id idRutina() const;

        //devuelve la longitud de la rutina
        int longitud() const;

    private:
        vector<Instruccion> _instrucciones;
        Id _idRutina;
    };

private:
	// COMPLETAR
    vector<Rutina> _rutinas;

    //devuelve la posicion de la rutina, si no existe, devuelve -1
    int posRutina(Id idRutina) const;

    

};

#endif /*__PROGRAMA_H__*/

