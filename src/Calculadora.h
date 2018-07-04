#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include "Programa.h"
#include "Ventana.h"
#include <iostream>
#include <vector>
#include <string>

class Calculadora {

public:


    Calculadora(Programa prog, Rutina rut, int tam);

    bool Finalizo() const;

    void EjecutarUnPaso();

    void AsignarVariable(Variable var, int val);

    int InstanteActual();

    int IndiceInstActual();

    int ValorHistorico(Variable var, int inst);

    int ValorActual(Variable var);

    Pila<int> pila();

private:
    struct InstConIt;

    typedef tuple<Lista_Enlazada<Ventana<tuple<int, int>>>::iterator, Lista_Enlazada<int>> Var;
    typedef Lista_Enlazada<InstConIt> Rut;
    typedef DiccionarioTrie<tuple<Lista_Enlazada<Ventana<tuple<int, int>>>::iterator,Lista_Enlazada<int>>>::ItDiccTrie ItVar;
    typedef DiccionarioTrie<Lista_Enlazada<InstConIt>>::ItDiccTrie ItRut;
    typedef Lista_Enlazada<Ventana<tuple<int, int>>> ListVent;
    typedef Lista_Enlazada<Ventana<tuple<int, int>>>::iterator ItListVent;



    struct InstConIt{

        Operacion _op;
        ItVar _var;
        ItRut _rut;
        int _val;

        InstConIt(Operacion op, ItVar var, ItRut rut, int val);

    };

    DiccionarioTrie<Lista_Enlazada<InstConIt>> _programa;

    DiccionarioTrie<Var> _variables;

    ListVent _ventanas;

    ItRut _rutinaActual;

    Lista_Enlazada<InstConIt>::iterator _instruccionAEjecutar;

    int _nInstruccionActual;

    int _instanteActual;

    Pila<int> _pila;

    int _tamVentana;

    void Sigo() const;

    int DevolverYSacarDePila();

};

#endif /*__CALCULADORA_H__*/
