#include "../includes/Lote.hpp"

//int Lote::lotesTotais = 1000;

Lote::Lote(int idProduto, int quantidade, Data data = Data::dataNow()):
  idLote(this->lotesTotais) {
  this->data = data;
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  this->lotesTotais += 1;
  this->status = Status::Estoque;
  }

Lote::Lote():
  idLote(this->lotesTotais) {
  this->lotesTotais += 1;
  this->status = Status::Estoque;
  this->data = Data::dataNow();
  this->idProduto = -1;
  this->quantidade = -1;
}

Lote::~Lote() {
  
}

void Lote::updateLotes(int quantidade) {
  this->quantidade -= quantidade;
  if (this->quantidade <= 0) {
    this->quantidade = 0;
    this->status = Status::Vendido;
  }
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
Status Lote::getStatus() {
  return this->status;
}

//setters
void Lote::setIdProduto(int idProduto) {
  this->idProduto = idProduto;
}
void Lote::setData(Data data) {
  this->data = data;
}
void Lote::setQuantidade(int quantidade) {
  this->quantidade = quantidade;
}
void Lote::setStatus(Status status) {
  this->status = status;
}

