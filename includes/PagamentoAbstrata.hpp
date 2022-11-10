#ifndef PAGAMENTOABSTRATA_H
#define PAGAMENTOABSTRATA_H

#include "Data.hpp"


class PagamentoAbstrata{

Data data;
float valorAPagar;

public:

PagamentoAbstrata(Data data, float valorApagar);
~PagamentoAbstrata();

//getters
Data getData();
float getValorAPagar();

//setters
void setData(Data data);
void setValorAPagar(float valorAPagar);

};

#endif