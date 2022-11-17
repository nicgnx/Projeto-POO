#ifndef PAGAMENTOABSTRATA_H
#define PAGAMENTOABSTRATA_H

#include "Data.hpp"


class PagamentoAbstrata{

protected:
  Data data;
  float valorAPagar;

public:  
  virtual ~PagamentoAbstrata() = default;
  
  //getters
  Data getData();
  float getValorAPagar();
  
  //setters
  void setData(Data data);
  void setValorAPagar(float valorAPagar);

};

#endif