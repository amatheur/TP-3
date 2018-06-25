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

    void asignarVariable(string idVariable, int valor);

    void ejecutar(string Rutina);

    int valorVariable(string idVariable) const;

    class Variable {
    public:
        // Crea una variable de id idVariable y valor 0
        Variable(string idVariable);

        //Asigna el valor "valor" a la variable
        void asignarValor(int valor);

        //devuelve el valor de la variable
        int valor() const;

        //devuelve el id de la variable
        string id() const;

    private:
        int _valor;
        string _idVariable;

    };

private:
    vector<int> _pila;
    vector<Variable> _memoria;
    Programa _programa;

    //devuelve la posicion de la variable en el vector de variables de la calculadora, si no existe, devuelve -1
    int posVariable(string idVariable) const;

    //devuelve true si la variable existe dentro del vector de variables de la calculadora, y false en caso contrario
    bool variableExiste(string idVariable) const;

    //devuelve el ultimo valor del vector_pila, y lo elimina del mismo, si no hay valores almacenados en _pila, devuelve 0
    int devolverYSacarDePila();
};

#endif /*__CALCULADORA_H__*/
