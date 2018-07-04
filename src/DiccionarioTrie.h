#ifndef DICC_TRIE_H_
#define DICC_TRIE_H_

#include <string>
#include <vector>
#include "Utiles.h"

using namespace std;

template<typename T>
class DiccionarioTrie {
public:

    DiccionarioTrie(); // Equivale a Vacio

    ~DiccionarioTrie();

    bool Definido(const string &clave) const;

    T& Significado(const string &clave);

    T& Significado(const string &clave) const;

private:
    struct Nodo {
        Nodo** siguientes;
        T* significado;

        Nodo();
        ~Nodo();
    };

    Nodo* _raiz;

    void _destroy(Nodo* &raiz);

public:
    class ItDiccTrie{
        friend class DiccionarioTrie<T>;

    public:

        tuple<string, T&> Actual();

        tuple<string, T&> Actual() const;

        void Avanzar();

        ItDiccTrie();

    private:

        Pila<Nodo*> _padres;
        Nodo* _actual;
        string _clave;


        ItDiccTrie(Nodo* actual, Pila<Nodo*> padres, string clave);

        bool HaySiguiente(Nodo* actual, int desde) const;

        int Siguiente(Nodo* actual, int desde);

        void AvanzarAux();


    };

    ItDiccTrie Definir(const string &clave, T significado);

    ItDiccTrie CrearIt();

    ItDiccTrie BuscarIterador(string clave);

};

#include "DiccionarioTrie.hpp"

#endif // DICC_TRIE_H_
