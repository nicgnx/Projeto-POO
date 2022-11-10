#include "../includes/LogExcecao.hpp"

LogExcecao::LogExcecao(std::string usuario, int idUsuario, Data data, std::string classeAcessada,std::string metodo){
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->metodo = metodo;
}

LogExcecao::LogExcecao(){}

LogExcecao::~LogExcecao(){}

std::string LogExcecao::getMetodo(){
  return this->metodo;
}

void LogExcecao::setMetodo(){
  this->metodo;
}

void LogExcecao::printLog(){
  std::cout << "----------------------------------------------------------------------------------------------------\n"
            << "                                         Log de Excecao"
            << "Usuário:             " << this->usuario << ".\n"
            << "idUsuario:           " << this->idUsuario << ".\n"
            << "Data:                " << this->data.printData(); std::cout << ".\n"
            << "Classe Acesso:       " << this->classeAcessada << ".\n"
            << "Metodo Desejado:     " << this->metodo << ".\n"
            << "----------------------------------------------------------------------------------------------------\n\n";
}