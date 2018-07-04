#ifndef __UTILES_H__
#define __UTILES_H__

#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <set>

//typedef int Operacion;

typedef enum{oPush, oAdd, oSub, oMul, oWrite, oRead, oJump, oJumpz} Operacion;


typedef std::string Variable;
typedef std::string Rutina;

template <typename T>
typedef std::stack<T> Pila;

template <typename T>
typedef std::queue<T> Cola;

template <typename T>
typedef std::list<T> Lista_Enlazada;

template <typename T, typename S>
typedef std::map<T, S> Diccionario_Lineal;

template <typename T>
typedef std::set<T> Conjunto_Lineal;

#endif /*__UTILES_H__*/
