#include "gtest/gtest.h"
#include "../src/Calculadora.h"
#include "../src/Programa.h"
#include "../src/Instruccion.h"

/*
TEST(test_calculadora, variables){

    Variable x("x");
    EXPECT_EQ(x.id(), "x");
    x.asignarValor(2);
    EXPECT_EQ(2, x.valor());
}

TEST(test_calculadora, asignarVariable){
    Programa p;
    Calculadora c(p);
    c.asignarVariable("x", 2);
    EXPECT_EQ(2, c.valorVariable("x"));
}
*/
TEST(test_calculadora, ejecutarPUSH){
    Programa p;
    p.AgregarInstruccion("MAIN", Instruccion(2));
    p.AgregarInstruccion("MAIN", Instruccion(oWrite, "y"));
    Calculadora c(p, "MAIN", 12);
    c.AsignarVariable("y", 0);
    c.EjecutarUnPaso();
    EXPECT_EQ(c.ValorActual("y"), 2);

}
/*
TEST(test_calculadora, ejecutarManejoVariables){
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "y"));
    Calculadora c(p);
    c.asignarVariable("x", 2);
    c.asignarVariable("y", 0);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("y"), 2);

}

TEST(test_calculadora, saltos) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 5));
    p.agregarInstruccion("A", Instruccion(JUMP, "B"));
    p.agregarInstruccion("B", Instruccion(WRITE, "x"));

    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 5);
}

TEST(test_calculadora, saltosz0){
    Programa p;
    p.agregarInstruccion("A", Instruccion(PUSH, 0));
    p.agregarInstruccion("A", Instruccion(JUMPZ, "B"));
    p.agregarInstruccion("B", Instruccion(PUSH, 2));
    p.agregarInstruccion("B", Instruccion(WRITE,"x"));

    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 2);
}

TEST(test_calculadora, saltoszVacio){
    Programa p;
    p.agregarInstruccion("A", Instruccion(JUMPZ, "B"));
    p.agregarInstruccion("B", Instruccion(PUSH, 2));
    p.agregarInstruccion("B", Instruccion(WRITE,"x"));

    Calculadora c(p);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"), 2);
}

TEST(test_calculadora, terminarRutinaNoDef){
    Programa p1;
    p1.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p1.agregarInstruccion("A", Instruccion(JUMP, "FIN"));
    p1.agregarInstruccion("A", Instruccion(READ, "y"));
    p1.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c1(p1);
    c1.asignarVariable("y",2);
    c1.ejecutar("A");
    EXPECT_EQ(c1.valorVariable("x"), 0);

    Programa p2;
    p2.agregarInstruccion("A", Instruccion(WRITE, "x"));
    p2.agregarInstruccion("A", Instruccion(JUMPZ, "FIN"));
    p2.agregarInstruccion("A", Instruccion(PUSH, 2));
    p2.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c2(p2);
    c2.ejecutar("A");
    EXPECT_EQ(c1.valorVariable("x"), 0);

}


TEST(test_calculadora, suma){
    Programa p1;
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 30));
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 10));
    p1.agregarInstruccion("MAIN", Instruccion(ADD));
    p1.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c1(p1);
    c1.ejecutar("MAIN");
    EXPECT_EQ(c1.valorVariable("x"), 40);

    Programa p2;
    p2.agregarInstruccion("MAIN", Instruccion(ADD));
    p2.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c2(p2);
    c2.ejecutar("MAIN");
    EXPECT_EQ(c2.valorVariable("x"), 0);

    Programa p3;
    p3.agregarInstruccion("MAIN", Instruccion(PUSH, 30));
    p3.agregarInstruccion("MAIN", Instruccion(ADD));
    p3.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c3(p3);
    c3.ejecutar("MAIN");
    EXPECT_EQ(c3.valorVariable("x"), 30);
}

TEST(test_calculadora, resta){
    Programa p1;
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 10));
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 5));
    p1.agregarInstruccion("MAIN", Instruccion(SUB));
    p1.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c1(p1);
    c1.ejecutar("MAIN");
    EXPECT_EQ(c1.valorVariable("x"), 5);

    Programa p2;
    p2.agregarInstruccion("MAIN", Instruccion(SUB));
    p2.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c2(p2);
    c2.ejecutar("MAIN");
    EXPECT_EQ(c2.valorVariable("x"), 0);

    Programa p3;
    p3.agregarInstruccion("MAIN", Instruccion(PUSH, 30));
    p3.agregarInstruccion("MAIN", Instruccion(SUB));
    p3.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c3(p3);
    c3.ejecutar("MAIN");
    EXPECT_EQ(c3.valorVariable("x"), -30);
}

TEST(test_calculadora, mult){
    Programa p1;
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 30));
    p1.agregarInstruccion("MAIN", Instruccion(PUSH, 10));
    p1.agregarInstruccion("MAIN", Instruccion(MUL));
    p1.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c1(p1);
    c1.ejecutar("MAIN");
    EXPECT_EQ(c1.valorVariable("x"), 300);

    Programa p2;
    p2.agregarInstruccion("MAIN", Instruccion(MUL));
    p2.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c2(p2);
    c2.ejecutar("MAIN");
    EXPECT_EQ(c2.valorVariable("x"), 0);

    Programa p3;
    p3.agregarInstruccion("MAIN", Instruccion(PUSH, 30));
    p3.agregarInstruccion("MAIN", Instruccion(MUL));
    p3.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c3(p3);
    c3.ejecutar("MAIN");
    EXPECT_EQ(c3.valorVariable("x"), 0);
}


TEST(test_calculadora, ejecutar) {
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));

    Calculadora c(p);
    c.asignarVariable("x", 38);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 40);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 42);
}
  */