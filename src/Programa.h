#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <iostream>
#include <vector>
#include <string>
#include "DiccionarioTrie.h"
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
	void agregarInstruccion(string idRutina, Instruccion instruccion);

	// Devuelve True si idRutina representa una rutina existente.
	bool esRutinaExistente(string idRutina) const;

	// Devuelve la longitud (cantidad de instrucciones) de la rutina
	// indicada.
	//
	// Precondición: esRutinaExistente(idRutina)
	int longitud(string idRutina) const;

	// Devuelve la i-ésima instrucción de la rutina indicada.
	//
	// Precondición:
	//   esRutinaExistente(idRutina) && 0 <= i && i < longitud(idRutina)
	Instruccion instruccion(string idRutina, int i) const;

    class Rutina {
    public:
        //crea una rutina vacia, de id idRutina
        Rutina(string nombre);

        // devuelve el vector de instrucciones de la rutina
        vector<Instruccion> instrucciones() const;

        //agraga una instruccion al vector de instrucciones de la rutina
        void agregarInstruccion(Instruccion instruccion);

        //devuelve el id de la rutina
        string idRutina() const;

        //devuelve la longitud de la rutina
        int longitud() const;

    private:
        vector<Instruccion> _instrucciones;
        string _idRutina;
    };

private:
	// COMPLETAR
    DiccionarioTrie _rutinas;

    //devuelve la posicion de la rutina, si no existe, devuelve -1
    Rutina* posRutina(string idRutina) const;

    

};

#endif /*__PROGRAMA_H__*/

