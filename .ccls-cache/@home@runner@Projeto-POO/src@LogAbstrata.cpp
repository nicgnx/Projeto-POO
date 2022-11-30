
#include "../includes/LogAbstrata.hpp"
#include <iostream>

// Setters
std::string LogAbstrata::getUsuario() { return this->usuario; }

int LogAbstrata::getIdUsuario() { return this->idUsuario; }

Data LogAbstrata::getData() { return this->data; }

std::string LogAbstrata::getClasseAcessada() { return this->classeAcessada; }

std::string LogAbstrata::getInstanciaAcessada() {
  return this->instanciaAcessada;
}

// Getters
void LogAbstrata::setUsuario(std::string usuario) { this->usuario = usuario; }

void LogAbstrata::setIdUsuario(int usuario) { this->idUsuario = usuario; }

void LogAbstrata::setData(Data data) { this->data = data; }

void LogAbstrata::setInstanciaAcessada(std::string instanciaAcessada) {
  this->instanciaAcessada = instanciaAcessada;
}

void LogAbstrata::setClasseAcessada(std::string classeAcessada) {
  this->classeAcessada = classeAcessada;
}

// Metodos

void LogAbstrata::printLog(){
  std::cout << "Usuário:       " << getUsuario() << "\n"
            << "ID:            " << getIdUsuario() << "\n"
            << "Data:          " << this->data.printData(true) << "\n"
            << "Classe:        " << getClasseAcessada() << endl;
}