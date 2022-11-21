#include "../includes/LogExcecao.hpp"

LogExcecao::LogExcecao(
  std::string usuario, int idUsuario, Data data, std::string classeAcessada,
  std::string instanciaAcessada, std::string metodo
) {
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->instanciaAcessada = instanciaAcessada;
  this->metodo = metodo;
}

LogExcecao::LogExcecao() {}

LogExcecao::~LogExcecao() {}

std::string LogExcecao::getMetodo() { return this->metodo; }

void LogExcecao::setMetodo(std::string metodo) { this->metodo = metodo; };

void LogExcecao::printLog() {
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n"
            << "                                         Log de Excecao\n\n"
            << "Usuário:                          " << this->usuario << "\n"
            << "idUsuario:                        " << this->idUsuario << "\n"
            << "Data (UTC):                       ";
  this->data.printData();
  std::cout << "Tentativa de acesso a classe:     " << this->classeAcessada
            << "\n"
            << "Instancia desejada:               " << this->instanciaAcessada
            << "\n"
            << "Metodo Desejado:                  " << this->metodo << "\n"
            << "---------------------------------------------------------------"
               "-------------------------------------\n\n";
}