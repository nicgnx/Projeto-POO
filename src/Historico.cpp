#include "../includes/Historico.hpp"
#include "../includes/Data.hpp"
#include <string>

Historico::Historico(Data data, std::string registro) {
    this->data = data;
    this->registro = registro;
}

Historico::~Historico() {}

Data Historico::getData() { return this->data; }

std::string Historico::getRegistro() { return this->registro; }

void Historico::setData(Data data) { this->data = data; }

void Historico::setRegistro(std::string registro) { this->registro = registro; }
