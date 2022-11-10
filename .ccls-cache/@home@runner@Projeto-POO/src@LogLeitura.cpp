#include "../includes/LogLeitura.hpp"

LogLeitura::LogLeitura(std::string usuario, int idUsuario, Data data, std::string classeAcessada, std::string informacao){
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->informacao = informacao;
}

LogLeitura::LogLeitura(){}

LogLeitura::~LogLeitura(){}

std::string LogLeitura::getInformacao(){
  return this->informacao;
}

void LogLeitura::setInformacao(std::string informacao){
  this->informacao = informacao;
}

void LogLeitura::printLog(){
  std::cout << "----------------------------------------------------------------------------------------------------"
            << "                                         Log de Leitura"
            << "Usuário:             " << this->usuario << ".\n"
            << "idUsuario:           " << this->idUsuario << ".\n"
            << "Data:                " << this->data << ".\n"
            << "Classe Acesso:       " << this->classeAcessada << ".\n"
            << "Informação Acessada: " << this->informacao << ".\n"
            << "----------------------------------------------------------------------------------------------------";
}