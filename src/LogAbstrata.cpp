
#include "../includes/LogAbstrata.hpp"

std::string LogAbstrata::getUsuario(){
  return this->usuario;
}

int LogAbstrata::getIdUsuario(){
  return this->idUsuario;
}

Data LogAbstrata::getData(){
  return this->data;
}

std::string LogAbstrata::getClasseAcessada(){
  return this->classeAcessada;
}


void LogAbstrata::setUsuario(std::string usuario){
  this->usuario = usuario;
}

void LogAbstrata::setIdUsuario(int usuario){
  this->idUsuario = usuario;
}

void LogAbstrata::setData(Data data){
  this->data = data;
}

void LogAbstrata::setClasseAcessada(std::string classeAcessada){
  this->classeAcessada = classeAcessada;
}
