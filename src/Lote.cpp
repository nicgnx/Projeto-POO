#include "../includes/Lote.hpp"

Lote::Lote(Produto* produto, Data data, int quantidade):
  NUMLOTE(this->lotesTotais) {
  this->data = data;
  this->produto = produto;
  this->quantidade = quantidade;
  this->lotesTotais += 1;
  }

Lote::Lote():
  NUMLOTE(this->lotesTotais) {
  this->lotesTotais += 1;
}

Lote::~Lote() {
  
}

//getters
Produto* Lote::getProduto() {
  return this->produto;
}
Data Lote::getData() {
  return this->data;
}
int Lote::getQuantidade() {
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
void Lote::setQuatidade(int quantidade) {
  this->quantidade = quantidade;
  
}

