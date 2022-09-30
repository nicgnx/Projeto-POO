#include "../includes/Lote.hpp"

Lote::Lote(Produto* produto, Data data, int quantidade, int numLote):
  NUMLOTE(numLote) {
  this->data = data;
  this->produto = produto;
  this->quantidade = quantidade;
  }

Lote() {
  
}

Lote::~Lote() {
  
}

void Lote::atualizaLotes() {
  
}

//getters
Produto* Lote::getProduto() {
  return this->produto;
}
Data Lote::getData() {
  return this->data;
}
int Lote::getQuatidade() {
    return this->quantidade;
}
int Lote::getNumLote() {
  return this->NUMLOTE;
}

//setters
void Lote::setProduto(Produto* produto) {
  this->produto = produto;
}
void Lote::setData(Data data) {
  this->data = data;
}
void Lote::setQuatidade(int quatidade) {
  this->quantidade = quantidade;
  
}

