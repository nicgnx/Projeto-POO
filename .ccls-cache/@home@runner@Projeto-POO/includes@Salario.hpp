#ifndef SALARIO_H
#define SALARIO_H

#include "Data.hpp"
#include <string>

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
  Salario();
  ~Salario();

  // getters
  double getSalarioBase();
  double getVariacaoSalarial();
  Data getData();
  Motivo getMotivacao();

  // setters
  void setSalarioBase(double salarioBase);
  void setVariacaoSalarial(double variacaoSalarial);
  void setData(Data data);
  void setMotivacao(Motivo motivacao);
};

#endif // SALARIO_H