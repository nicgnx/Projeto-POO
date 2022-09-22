#ifndef SALARIO_H
#define SALARIO_H

#include <string>
#include "Data.hpp"


enum Motivo {
  Dissidio,
  Gerencia,
};

class Salario {
    double salarioBase;
    double variacaoSalarial;
    Data data;
    Motivo motivacao;

public:

    Salario(double, double, Data, Motivo);
    ~Salario();

    //getters
    double getSalarioBase();
    double getVariacaoSalarial();
    Data getData();
    Motivo getMotivacao();

    //setters
    void setSalarioBase(double);
    void setVariacaoSalarial(double);
    void setData(Data);
    void setMotivacao(Motivo);

};

#include "../src/Salario.cpp"

#endif