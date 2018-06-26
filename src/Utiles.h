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

/*
const Operacion PUSH = 1;
const Operacion ADD = 2;
const Operacion SUB = 3;
const Operacion MUL = 4;
const Operacion WRITE = 5;
const Operacion READ = 6;
const Operacion JUMP = 7;
const Operacion JUMPZ = 8;
*/


typedef std::string Variable;
typedef std::string Rutina;
typedef std::stack Pila;
typedef std::queue Cola;
typedef std::list Lista_Enlazada;
typedef std::map Diccionario_Lineal;
typedef std::set Conjunto_Lineal;

#endif /*__UTILES_H__*/
