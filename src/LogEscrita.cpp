#include "../includes/LogEscrita.hpp"

LogEscrita::LogEscrita(std::string atributoAcessado, std::string atributoAntes, std::string atributoDepois){
  this->atributoAcessado = atributoAcessado;
  this->atributoAntes = atributoAntes;
  this->atributoDepois = atributoDepois;
}

std::string LogEscrita::getAtributoAcessado(){
  return this->atributoAcessado;
}

std::string LogEscrita::getAtributoAntes(){
  return this->atributoAntes;
}

std::string LogEscrita::getAtributoDepois(){
  return this->atributoDepois;
}

void LogEscrita::setAtributoAcessado (std::string atributoAcessado){
  this->atributoAcessado = atributoAcessado;
}

void LogEscrita::setAtributoAntes(std::string atributoAntes){
  this->atributoAntes = atributoAntes;
}

void LogEscrita::setAtributoDepois(std::string atributoDepois){
  this->atributoDepois = atributoDepois;
}

void LogEscrita::printLog(){
  std::cout << "----------------------------------------------------------------------------------------------------\n"
            << "                                         Log de Escrita"
            << "Usuário:             " << this->usuario << ".\n"
            << "idUsuario:           " << this->idUsuario << ".\n"
            << "Data:                " << this->data.printData(); std::cout << ".\n"
            << "Classe Acesso:       " << this->classeAcessada << ".\n"
            << "Atributo Acessado:   " << this->atributoAcessado << ".\n"
            << "Atributo Antes:      " << this->atributoAntes << ".\n"
            << "Atributo Depois:     " << this->atributoDepois << ".\n"
            << "----------------------------------------------------------------------------------------------------\n\n";
}