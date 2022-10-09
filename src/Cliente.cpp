#include "../includes/Cliente.hpp"

#include <iostream>


Cliente::Cliente(){}

Cliente::Cliente(std::string nome, std::string email, std::string cpfCnpj, tipoPessoa tipo, unsigned int telefone){

  this->nome = nome;
  this->email = email;
  this->cpfCnpj = cpfCnpj;
  this->tipo = tipo;
  this->telefone = telefone;
}

Cliente::~Cliente() {}

unsigned int Cliente::getTelefone(){
  return this->telefone;
}

tipoPessoa Cliente::getTipoPessoa(){
  return this->tipo;
}

void Cliente::setTipoPessoa(tipoPessoa tipo){
  this->tipo = tipo;
}

void Cliente::setTelefone(unsigned int telefone){
  this->telefone = telefone;
}

void Cliente::compra (int idProduto, int quantidade, Data dataCompra){
  Venda pedido(idProduto,quantidade,dataCompra,getNome());
  if(pedido.verificaVenda()){
    pedido.executaVenda();
  } else {
    std::cout << "----------------------------------------------------------------------------------------------------\n\n";
    std::cout << "                             Não foi possível realizar a compra\n\n"; 
    std::cout << "        Não possuimos a quantidade desejada do produto [ "; 
    std::cout << Estoque::getInstancia()->getProduto(idProduto)->getNome() << " ] no momento\n\n";  
    std::cout << "        Quantidade em estoque: " << Estoque::getInstancia()->verificaEstoque(idProduto) << "\n\n";  
    std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  }
}