#include "../includes/LogExcecao.hpp"

LogExcecao::LogExcecao(
  std::string usuario, std::string idUsuario, Data data, std::string classeAcessada,
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
  std::cout << "----------------------------------------------------------------------\n\n"
            << "                            Log de Excecao\n\n";
  LogAbstrata::printLog();
  std::cout << "Instancia:     " << this->instanciaAcessada
            << "\n"
            << "Metodo:        " << this->metodo << "\n"
            << "----------------------------------------------------------------------\n\n";
}