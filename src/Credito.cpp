#include "../includes/Credito.hpp"

Credito::Credito(Data data, float valorAPagar, Parcelamento parcelamento) {
  this->parcelamento = parcelamento;
  this->data = data;
  this->valorAPagar = valorAPagar;
}

Parcelamento Credito::getParcelamento() { return this->parcelamento; }

void Credito::setParcelamento(Parcelamento parcelamento) {
  this->parcelamento = parcelamento;
}

void Credito::printaPagamento() {
  std::cout << "\n Metodo de Pagamento : Credito \n";
  std::cout << std::fixed << std::setprecision(2);
  std::cout << " Valor Total: R$" << this->valorAPagar;
  std::cout << "\n Valor por parcela: R$";
  switch(this->parcelamento) {
    case Parcelamento::A_VISTA:
      std::cout << this->valorAPagar << "\n";
      break;
    case Parcelamento::x1:
      std::cout << this->valorAPagar << "\n";
      break;
    case Parcelamento::x2:
      std::cout << this->valorAPagar/2 << "\n";
      break;
    case Parcelamento::x3:
      std::cout << this->valorAPagar/3 << "\n";
      break;
    case Parcelamento::x4:
      std::cout << this->valorAPagar/4 << "\n";
      break;
    case Parcelamento::x5:
      std::cout << this->valorAPagar/5 << "\n";
      break;
    case Parcelamento::x6:
      std::cout << this->valorAPagar/6 << "\n";
      break;
  }
}