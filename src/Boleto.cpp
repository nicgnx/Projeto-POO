#include "../includes/Boleto.hpp"

Boleto::Boleto(Data data, float valorAPagar, Periodo periodo) {
  this->periodo = periodo;
  this->data = data;
  this->valorAPagar = valorAPagar;
};

Periodo Boleto::getPeriodo() { return this->periodo; }

void Boleto::setPeriodo(Periodo periodo) { this->periodo = periodo; }

void Boleto::printaPagamento() {
  std::cout << "\n Metodo de Pagamento : Boleto \n";
  std::cout << " Valor Total: " << this->valorAPagar;
  std::cout << "\n Prazo:";
  switch(this->periodo) {
    case Periodo::DIAS_30:
      std::cout << "30 Dias\n";
      break;
    case Periodo::DIAS_60:
      std::cout << "60 Dias\n";
      break;
    case Periodo::DIAS_90:
      std::cout << "90 Dias\n";
      break;
  }
}
