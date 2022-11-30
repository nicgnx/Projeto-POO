#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>
#include <iomanip>
#include "../includes/PagamentoAbstrata.hpp"

enum Parcelamento { A_VISTA, x1, x2, x3, x4, x5, x6 };

class Credito : public PagamentoAbstrata {

  Parcelamento parcelamento;

public:
  Credito(Data data, float valorAPagar, Parcelamento parcelamento);

  // getters
  Parcelamento getParcelamento();

  // setters
  void setParcelamento(Parcelamento parcelamento);

  //métodos 
  virtual void printaPagamento() override;
};

#endif