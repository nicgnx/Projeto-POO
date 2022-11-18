#include "../includes/PagamentoAbstrata.hpp"

PagamentoAbstrata::~PagamentoAbstrata(){};

Data PagamentoAbstrata::getData() { return this->data; };

float PagamentoAbstrata::getValorAPagar() { return this->valorAPagar; };

void PagamentoAbstrata::setData(Data data) { this->data = data; };

void PagamentoAbstrata::setValorAPagar(float valorAPagar) {
    this->valorAPagar = valorAPagar;
};
