#include "../includes/Credito.hpp"

Credito::Credito(Data data, float valorAPagar, Parcelamento parcelamento) {
  this->parcelamento = parcelamento;
  this->data = data;
  this->valorAPagar = valorAPagar;
};

Parcelamento Credito::getParcelamento() { return this->parcelamento; };

void Credito::setParcelamento(Parcelamento parcelamento) {
  this->parcelamento = parcelamento;
};
