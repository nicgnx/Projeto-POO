#include "../includes/Boleto.hpp"

Boleto::Boleto(Data data, float valorAPagar, Periodo periodo) {
    this->periodo = periodo;
    this->data = data;
    this->valorAPagar = valorAPagar;
};

Periodo Boleto::getPeriodo() { return this->periodo; };

void Boleto::setPeriodo(Periodo periodo) { this->periodo = periodo; };
