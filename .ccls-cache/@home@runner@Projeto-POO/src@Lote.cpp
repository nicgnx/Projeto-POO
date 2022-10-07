#include "../includes/Lote.hpp"

Lote::Lote(int idProduto, Data data, int quantidade):
  idLote(this->lotesTotais) {
  this->data = data;
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  this->lotesTotais += 1;
  }

Lote::Lote():
  idLote(this->lotesTotais) {
  this->lotesTotais += 1;
}

Lote::~Lote() {
  
}

void Lote::updateLotes() {
  
}

//getters
int Lote::getIdProduto() {
  return this->idProduto;
}
Data Lote::getData() {
  return this->data;
}
int Lote::getQuantidade() {
    return this->quantidade;
}
int Lote::getIdLote() {
  return this->idLote;
}
int Lote::getLotesTotais() {
  return this->lotesTotais;
}

//setters
void Lote::setIdProduto(int idProduto) {
  this->idProduto = idProduto;
}
void Lote::setData(Data data) {
  this->data = data;
}
void Lote::setQuatidade(int quantidade) {
  this->quantidade = quantidade;
  
}

