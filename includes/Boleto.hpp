#ifndef BOLETO_H
#define BOLETO_H


#include "../includes/PagamentoAbstrata.hpp"

enum Periodo {30, 60, 90};

class Boleto : public PagamentoAbstrata{


Periodo periodo;


public:

  Boleto(Data data, float valorAPagar, Periodo periodo);
  
  //getters
  Periodo getPeriodo();

  //setters
  void setPeriodo(Periodo periodo);

};

#endif