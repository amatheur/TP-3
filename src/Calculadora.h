#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include "Programa.h"
#include <iostream>
#include <vector>
#include <string>

class Calculadora {
public:
    class Variable;

    Calculadora(Programa programa);

    void asignarVariable(Id idVariable, int valor);

    void ejecutar(Id Rutina);

    int valorVariable(Id idVariable) const;

    class Variable {
    public:
        // Crea una variable de id idVariable y valor 0
        Variable(Id idVariable);

        //Asigna el valor "valor" a la variable
        void asignarValor(int valor);

        //devuelve el valor de la variable
        int valor() const;

        //devuelve el id de la variable
        Id id() const;

    private:
        int _valor;
        Id _idVariable;

    };

private:
    vector<int> _pila;
    vector<Variable> _memoria;
    Programa _programa;

    //devuelve la posicion de la variable en el vector de variables de la calculadora, si no existe, devuelve -1
    int posVariable(Id idVariable) const;

    //devuelve true si la variable existe dentro del vector de variables de la calculadora, y false en caso contrario
    bool variableExiste(Id idVariable) const;

    //devuelve el ultimo valor del vector_pila, y lo elimina del mismo, si no hay valores almacenados en _pila, devuelve 0
    int devolverYSacarDePila();
};

#endif /*__CALCULADORA_H__*/
