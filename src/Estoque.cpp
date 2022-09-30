#include "../includes/Estoque.hpp"

Estoque::Estoque(Produto *produto, int quantidade) {
  this->produto = produto;
  this->quantidade = quantidade;
}

Estoque::Estoque(){
  this->produto.clear();
  this->quantidade.clear();
}

Estoque::~Estoque(){}

//getters
Produto Estoque::getProduto (){
  return this->produto;
}
int Estoque::getQuantidade(){
  return this->quantidade;
}

//setters
void Estoque::setProduto (Produto *produto){
  this->produto = produto;
}
void Estoque::setQuantidade (int qtd){
  this->quantidade = qtd;
}

//atualizar estoque
void Estoque::atualizaEstoque(){
  
}