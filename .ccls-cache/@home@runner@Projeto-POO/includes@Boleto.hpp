#ifndef BOLETO_H
#define BOLETO_H

#include <iostream>
#include "../includes/PagamentoAbstrata.hpp"

enum Periodo { DIAS_30, DIAS_60, DIAS_90 };

class Boleto : public PagamentoAbstrata {

  Periodo periodo;

public:
  Boleto(Data data, float valorAPagar, Periodo periodo);

  // getters
  Periodo getPeriodo();

  // setters
  void setPeriodo(Periodo periodo);

  //métodos
  virtual void printaPagamento() override; 
};

#endif