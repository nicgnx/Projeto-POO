#include "../includes/Estoque.hpp"


Estoque::~Estoque(){}

//getters

Produto* Estoque::getProduto (int idProduto){
  for(unsigned int num = this->produto.size(); num >= 0;num--){
    if(this->produto[num].getIdProduto() == idProduto){
      return this->produto[num];
    }
  }throw ("Esse produto não existe!");
}

int Estoque::getQuantidade(){
  return this->quantidade;
}

//setters
void Estoque::setProduto (int idProduto){
  for(unsigned int num = this->produto.size(); num >= 0;num--){
    if(this->produto[num].getIdProduto() == idProduto){
      return this->produto[num];
    }
  }throw ("Esse produto não existe!");
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