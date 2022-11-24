#include "../includes/Cliente.hpp"

#include <iostream>

Cliente::Cliente() {}

Cliente::Cliente(
  std::string nome, std::string email, std::string senha, std::string cpfCnpj,
  tipoPessoa tipo, unsigned int telefone
) {

  this->nome = nome;
  this->email = email;
  this->senha = senha;
  this->cpfCnpj = cpfCnpj;
  this->tipo = tipo;
  this->telefone = telefone;
}

Cliente::~Cliente() {}

tipoPessoa Cliente::getTipoPessoa() { return this->tipo; }

unsigned int Cliente::getTelefone() { return this->telefone; }

void Cliente::setTipoPessoa(tipoPessoa tipo) { this->tipo = tipo; }

void Cliente::setTelefone(unsigned int telefone) { this->telefone = telefone; }

void Cliente::compra(Orcamento* orcamento, Data dataCompra) {
  if (!Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO)) {
    throw "Usuario logado nao possui permissao para comprar produtos!";
  }

   orcamento->gerarPedidoDeCompra(dataCompra);
  
   //);

  // if (pedido.verificaVenda()) {
  //   pedido.executaVenda();
  // } else {
  //   std::cout << "-------------------------------------------------------------"
  //                "---------------------------------------\n\n";
  //   std::cout << "                             Não foi possível realizar a "
  //                "compra\n\n";
  //   std::cout << "        Não possuimos a quantidade desejada do produto [ ";
  //   std::cout << Estoque::getInstancia()->getProduto(idProduto)->getNome()
  //             << " ] no momento\n\n";
  //   std::cout << "        Quantidade em estoque: "
  //             << Estoque::getInstancia()->verificaEstoque(idProduto) << "\n\n";
  //   std::cout << "-------------------------------------------------------------"
  //                "---------------------------------------\n\n";
  // }
}

Orcamento* Cliente::solicitaOrcamento(std::map<int,int>itensDesejados){

  Orcamento* orcamento = new Orcamento(this->nome, this->cpfCnpj, this->email,itensDesejados);

  return orcamento;
}