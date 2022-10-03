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
void Estoque::setQuantidade (int quantidade){
  this->quantidade = quantidade;
}

//atualizar estoque
void Estoque::atualizaEstoque(){
  int estoque = 0;
  bool flag = 1;
  

  for(unsigned int num = this->produto->getLoteTodos().size();flag;num--){
    estoque += this->produto->getLoteTodos()[num]->getQuantidade();
    if(num == 0){flag = 0;}
  }
  setQuantidade(estoque);
}