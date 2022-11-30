#include "../includes/LogLeitura.hpp"
#include <iostream>

LogLeitura::LogLeitura(
  std::string usuario, std::string idUsuario, Data data, std::string classeAcessada,
  std::string instanciaAcessada, std::string informacao
) {
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->instanciaAcessada = instanciaAcessada;
  this->informacao = informacao;
}

LogLeitura::LogLeitura() {}

LogLeitura::~LogLeitura() {}

std::string LogLeitura::getInformacao() { return this->informacao; }

void LogLeitura::setInformacao(std::string informacao) {
  this->informacao = informacao;
}

void LogLeitura::printLog() {
  std::cout << "----------------------------------------------------------------------\n"
            << "                            Log de Leitura\n\n";
  LogAbstrata::printLog();
  std::cout << "Informação:    " << this->informacao << "\n"
            << "----------------------------------------------------------------------\n\n";
}