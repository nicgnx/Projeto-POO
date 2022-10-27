
#include "../includes/LogAbstrata.hpp"

Usuario* LogAbstrata::getUsuario(){
  return this->usuario;
}

Data LogAbstrata::getData(){
  return this->data;
}

std::string LogAbstrata::getClasseAcessada(){
  return this->classeAcessada;
}


void LogAbstrata::setUsuario(Usuario* usuario){
  this->usuario = usuario;
}
