#include "../includes/Produto.hpp"
#include <iostream>

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
  bool flag = 1;
  for(unsigned int num = this->lotes.size();flag;num--){
    if(this->lotes[num]->getNumLote() == numLote){
      return this->lotes[num];
    }
    if (num == 0){
      flag = 0;
      cout << "Lote não encontrado.";
    }
  }
}

vector <Lote*> Produto::getLoteTodos(){
  return this->lotes;
}


// Setters

void Produto::setProduto(std::string produto){
  this->produto = produto;
}
void Produto::setCodigo(int codigo){
  this->codigo = codigo;
}

void Produto::setValor(float valor){
  this->valor = valor;
}

void Produto::setCategoria(Categoria categoria){
  this->categoria = categoria;
}

void Produto::setLoteMinimo(int loteMinimo){
  this->loteMinimo = loteMinimo;
}

void Produto::setEstoqueMinimo(int estoqueMinimo){
  this->estoqueMinimo = estoqueMinimo;
}

void Produto::setLote(int numLote, Lote lote){
  this->lotes[numLote] = lote;
}

void Produto::setLoteTodos(vector <Lote*> lotes){
  this->lotes = lotes;
}
