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
Cliente::Cliente() {
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Cliente","Vazio","Vazio",CRIACAO));
}
Cliente::~Cliente() {}


// Getters
tipoPessoa Cliente::getTipoPessoa() { return this->tipo; }

unsigned int Cliente::getTelefone() { return this->telefone; }

std::vector<Orcamento*> Cliente::getOrcamentosAprovados(){return this->orcamentosAprovados;}

//Setters
void Cliente::setTipoPessoa(tipoPessoa tipo) { this->tipo = tipo; }

void Cliente::setTelefone(unsigned int telefone) { this->telefone = telefone; }

void Cliente::setOrcamentosAprovados(Orcamento* orcamento){this->orcamentosAprovados.push_back(orcamento);}


// Métodos
void Cliente::compra(Orcamento* orcamento, Data dataCompra) {  
  Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO,"COMPRAR_PRODUTO","Cliente",this->cpfCnpj,"compra");
    orcamento->gerarPedidoDeCompra(dataCompra);
  setOrcamentosAprovados(orcamento);
}

Orcamento* Cliente::solicitaOrcamento(std::map<int,int>itensDesejados){
  Orcamento* orcamento = new Orcamento(this->nome, this->cpfCnpj, this->email,itensDesejados);  
  return orcamento;
}