#include "../includes/LogLoginLogout.hpp"

// Construtores e Destrutores

LogLoginLogout::LogLoginLogout(){}

LogLoginLogout::LogLoginLogout(std::string usuario,std::string idUsuario,Data data,std::string classeAcessada,operacaoL operacao){
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  operacao == LOGIN ? this->tipoLogin = "Login" : this->tipoLogin = "Logout";
}

LogLoginLogout::~LogLoginLogout(){}

// Getters

std::string LogLoginLogout::getTipoLogin(){return this->tipoLogin;}

// Setters

void LogLoginLogout::setTipoLogin(std::string tipoLogin){this->tipoLogin = tipoLogin;}

// Métodos

void LogLoginLogout::printLog(){
  std::cout << "----------------------------------------------------------------------\n\n"
            << "                            Log de " << this->tipoLogin << "\n\n";
  LogAbstrata::printLog();
  std::cout << "Ação:          " << this->tipoLogin << "\n"
            << "----------------------------------------------------------------------\n\n";
}