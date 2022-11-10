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