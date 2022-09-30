#include "../includes/Produto.hpp"

// Contrutores e Destrutores

Produto::Produto(std::string produto, int codigo, float valor, Categoria categoria, int loteMinimo, int estoqueMinimo){
  this->produto = produto;
  this->codigo = codigo;
  this->valor = valor;
  this->categoria = categoria;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->lotes.clear();
}

Produto::Produto(){}

~Produto::Produto(){}

// Getters

std::string Produto::getProduto(){
  return this->produto;
}


int Produto::getCodigo(){
  return this->codigo;
}


float Produto::getValor(){
  return this->valor;
}


Categoria Produto::getCategoria(){
  return this->categoria;
}


int Produto::getLoteMinimo(){
  return this->loteMinimo;
}


int Produto::getEstoqueMinimo(){ return this-> estoqueMinimo;}

Lote Produto::getLote(int numLote){
  for(){
    
  }

}

vector <Lote*> Produto::getLoteTodos(){
  return this->lotes;
}






