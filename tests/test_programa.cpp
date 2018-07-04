#include "gtest/gtest.h"

#include "../src/Instruccion.h"
#include "../src/Programa.h"

TEST(test_programa, rutinaExistente) {
    Programa p;
    p.AgregarInstruccion("a", Instruccion(10));
    p.AgregarInstruccion("a", Instruccion(oAdd));
    EXPECT_EQ(p.Longitud("a"), 2);
    EXPECT_NE(p.Longitud("b"), 1);
    p.AgregarInstruccion("b", Instruccion(oWrite, "z"));
    EXPECT_EQ(p.Longitud("a")>0, true);
    EXPECT_EQ(p.Longitud("b")>0, true);
}

TEST(test_programa, longitud) {
    Programa p;
    p.AgregarInstruccion("foo", Instruccion(10);
    EXPECT_EQ(p.Longitud("foo"), 1);
    p.AgregarInstruccion("foo", Instruccion(oAdd));
    EXPECT_EQ(p.Longitud("foo"), 2);
    p.AgregarInstruccion("foo", Instruccion(12));
    EXPECT_EQ(p.Longitud("foo"), 3);
    p.AgregarInstruccion("foo", Instruccion(oMul));
    EXPECT_EQ(p.Longitud("foo"), 4);
}

TEST(test_programa, instruccion) {
    Programa p;
    p.AgregarInstruccion("X", Instruccion(oRead, "x"));
    p.AgregarInstruccion("X", Instruccion(2));
    p.AgregarInstruccion("X", Instruccion(oMul));
    p.AgregarInstruccion("X", Instruccion(oRead, "y"));
    p.AgregarInstruccion("X", Instruccion(oAdd));
    EXPECT_EQ(p.Longitud("X"), 5);
    EXPECT_EQ(p.instruccion("X", 0).operacion(), oRead);
    EXPECT_EQ(p.instruccion("X", 0).Variable(), "x");
    EXPECT_EQ(p.instruccion("X", 1).operacion(), oPush);
    EXPECT_EQ(p.instruccion("X", 1).Valor(), 2);
    EXPECT_EQ(p.instruccion("X", 2).operacion(), oMul);
    EXPECT_EQ(p.instruccion("X", 3).operacion(), oRead);
    EXPECT_EQ(p.instruccion("X", 3).Valor(), "y");
    EXPECT_EQ(p.instruccion("X", 4).operacion(), oAdd);
}

TEST(test_programa, dosRutinas) {
    Programa p;
    p.agregarInstruccion("A", Instruccion(READ, "a"));
    p.agregarInstruccion("B", Instruccion(WRITE, "b"));
    p.agregarInstruccion("A", Instruccion(JUMP, "c"));
    p.agregarInstruccion("B", Instruccion(JUMPZ, "d"));
    p.agregarInstruccion("A", Instruccion(READ, "e"));

    EXPECT_EQ(p.longitud("A"), 3);
    EXPECT_EQ(p.longitud("B"), 2);
    EXPECT_EQ(p.instruccion("A", 0).operacion(), READ);
    EXPECT_EQ(p.instruccion("A", 0).nombre(), "a");
    EXPECT_EQ(p.instruccion("A", 1).operacion(), JUMP);
    EXPECT_EQ(p.instruccion("A", 1).nombre(), "c");
    EXPECT_EQ(p.instruccion("A", 2).operacion(), READ);
    EXPECT_EQ(p.instruccion("A", 2).nombre(), "e");

    EXPECT_EQ(p.instruccion("B", 0).operacion(), WRITE);
    EXPECT_EQ(p.instruccion("B", 0).nombre(), "b");
    EXPECT_EQ(p.instruccion("B", 1).operacion(), JUMPZ);
    EXPECT_EQ(p.instruccion("B", 1).nombre(), "d");
}

