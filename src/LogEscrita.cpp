#include "../includes/LogEscrita.hpp"

LogEscrita::LogEscrita(
  std::string usuario, std::string idUsuario, Data data, std::string classeAcessada,
  std::string instanciaAcessada, std::string atributoAcessado,
  std::string atributoAntes, std::string atributoDepois
) {
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->instanciaAcessada = instanciaAcessada;
  this->atributoAcessado = atributoAcessado;
  this->atributoAntes = atributoAntes;
  this->atributoDepois = atributoDepois;
}

LogEscrita::~LogEscrita() {}

std::string LogEscrita::getAtributoAcessado() { return this->atributoAcessado; }

std::string LogEscrita::getAtributoAntes() { return this->atributoAntes; }

std::string LogEscrita::getAtributoDepois() { return this->atributoDepois; }

void LogEscrita::setAtributoAcessado(std::string atributoAcessado) {
  this->atributoAcessado = atributoAcessado;
}

void LogEscrita::setAtributoAntes(std::string atributoAntes) {
  this->atributoAntes = atributoAntes;
}

void LogEscrita::setAtributoDepois(std::string atributoDepois) {
  this->atributoDepois = atributoDepois;
}

void LogEscrita::printLog() {
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n"
            << "                                         Log de Escrita\n\n";
            LogAbstrata::printLog();
  std::cout << "Instancia Acessada:  " << this->instanciaAcessada << "\n"
            << "Atributo Acessado:   " << this->atributoAcessado << "\n"
            << "Atributo Antes:      " << this->atributoAntes << "\n"
            << "Atributo Depois:     " << this->atributoDepois << "\n"
            << "---------------------------------------------------------------"
               "-------------------------------------\n\n";
}