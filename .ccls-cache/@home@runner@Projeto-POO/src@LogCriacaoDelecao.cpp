#include "../includes/LogCriacaoDelecao.hpp"

// Construtores e Destrutores
LogCriacaoDelecao::LogCriacaoDelecao(){}

LogCriacaoDelecao::~LogCriacaoDelecao(){}

LogCriacaoDelecao::LogCriacaoDelecao(std::string usuario,std::string idUsuario,Data data,std::string classeAcessada,std::string instanciaCriada,std::string id,operacao operacao){
  this->usuario = usuario;
  this->idUsuario = idUsuario;
  this->data = data;
  this->classeAcessada = classeAcessada;
  this->instancia = instanciaCriada;
  this->id = id;
  operacao == CRIACAO ? this->tipoOperacao = "Criação" : this->tipoOperacao = "Deleção";
}

LogCriacaoDelecao::LogCriacaoDelecao(std::string instanciaCriada,operacao operacao){
  this->instancia = instanciaCriada;
  this->tipoOperacao = operacao;
  this->id = " ";
}

// Getters

std::string LogCriacaoDelecao::getInstancia(){return this->instancia;}

std::string LogCriacaoDelecao::getId(){return this->id;}

std::string LogCriacaoDelecao::getOperacao(){return this->tipoOperacao;}

// Setters

void LogCriacaoDelecao::setInstancia(std::string instancia){this->instancia = instancia;}

void LogCriacaoDelecao::setId(std::string id){this->id = id;}

void LogCriacaoDelecao::setOperacao(std::string operacao){this->tipoOperacao = operacao;}

// Métodos

void LogCriacaoDelecao::printLog(){
  std::cout << "----------------------------------------------------------------------\n\n"
            << "                            Log de " << this->tipoOperacao << "\n\n";
  LogAbstrata::printLog();
  std::cout << "Instancia:     " << getInstancia() << "\n";
  getId() != " " ? std::cout << "Id:            " << getId() << "\n" :  std::cout << "\n";
  std::cout << "Operação:      " << this->tipoOperacao << "\n" 
            << "----------------------------------------------------------------------\n\n";  
}