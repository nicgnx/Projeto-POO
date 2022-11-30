#include "../includes/Cliente.hpp"

#include <iostream>

// Construtores e Destrutores
Cliente::Cliente(std::string nome, std::string email, std::string senha, std::string cpfCnpj,
  tipoPessoa tipo, unsigned int telefone) {

  this->nome = nome;
  this->email = email;
  this->senha = senha;
  this->cpfCnpj = cpfCnpj;
  this->tipo = tipo;
  this->telefone = telefone;
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente",nome,cpfCnpj,CRIACAO));
}
Cliente::Cliente(std::string cpfCnpj) {
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente","",cpfCnpj,CRIACAO));
  this->cpfCnpj = cpfCnpj;
}
Cliente::~Cliente() {}


// Getters
tipoPessoa Cliente::getTipoPessoa() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente",this->cpfCnpj,"tipo"));
  
  return this->tipo;
}

unsigned int Cliente::getTelefone() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente",this->cpfCnpj,"telefone"));
  
  return this->telefone;
}

std::vector<Orcamento*> Cliente::getOrcamentosAprovados(){
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente",this->cpfCnpj,"orcamentosAprovados"));
  
  return this->orcamentosAprovados;
}

//Setters
void Cliente::setTipoPessoa(tipoPessoa tipo) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE,"CADASTRAR_EDITAR_CLIENTE","Cliente",this->cpfCnpj,"setTipoPessoa");
  this->tipo = tipo; 
}

void Cliente::setTelefone(unsigned int telefone) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE,"CADASTRAR_EDITAR_CLIENTE","Cliente",this->cpfCnpj,"setTelefone");
  this->telefone = telefone; 
}

void Cliente::setOrcamentosAprovados(Orcamento* orcamento){
  std::vector<std::string> frases;
  frases.push_back("CADASTRAR_EDITAR_CLIENTE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Cliente",this->cpfCnpj,"setOrcamentosAprovados");
  this->orcamentosAprovados.push_back(orcamento);
}


// Métodos
void Cliente::compra(Orcamento* orcamento, Data dataCompra) {  
  Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO,"COMPRAR_PRODUTO","Cliente",this->cpfCnpj,"compra");
    orcamento->gerarPedidoDeCompra(dataCompra);
  setOrcamentosAprovados(orcamento);
}

Orcamento* Cliente::solicitaOrcamento(std::map<int,int>itensDesejados){
  Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO,"COMPRAR_PRODUTO","Cliente",this->cpfCnpj,"compra");
  Orcamento* orcamento = new Orcamento(this->nome, this->cpfCnpj, this->email,itensDesejados);  
  return orcamento;
}