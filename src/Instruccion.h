#ifndef __INSTRUCCION_H__
#define __INSTRUCCION_H__

#include <iostream>
#include <vector>
#include <string>

#include "Utiles.h"

// Una instrucción está dada por un código de operación junto con una
// secuencia de parámetros de tipo entero.
//
// Actualmente todas las instrucciones de la máquina tienen a lo sumo
// un parámetro, y se espera que estén construidas de la siguiente manera:
//
//   PUSH     <numero>
//   ADD
//   SUB
//   MUL
//   READ     <nombre>
//   WRITE    <nombre>
//   JUMP     <nombre>
//   JUMPZ    <nombre>
//
class Instruccion {
public:
	// Precondición: la operación es PUSH
	Instruccion(Operacion operacion, int valor);

        // Precondición: la operación es ADD, SUB o MUL
	Instruccion(Operacion operacion);

        // Precondición: la operación es READ, WRITE, JUMP o JUMPZ
	Instruccion(Operacion operacion, string nombre);

	Operacion operacion() const;

	// Precondición: la operación es PUSH
	int valor() const;

        // Precondición: la operación es READ, WRITE, JUMP o JUMPZ
	string nombre() const;
private:
    Operacion _operacion;
    int _valor;
    string _nombre;
	// COMPLETAR
};

#endif /*__INSTRUCCION_H__*/

