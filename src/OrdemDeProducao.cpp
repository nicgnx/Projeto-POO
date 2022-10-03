#include "../includes/OrdemDeProducao.hpp"

OrdemDeProducao::OrdemDeProducao(Produto* produto, Data data, int quantidade, Status status) {
  this->produto = produto;
  this->data = data;
  this->quantidade = quantidade;
  this->status = status;
}

OrdemDeProducao::~OrdemDeProducao() {
  
}
//getters
Produto* OrdemDeProducao::getProduto() {
  return this->produto;
}
Data OrdemDeProducao::getData() {
  return this->data;
}
int OrdemDeProducao::getQuantidade() {
  return this->quantidade;
}
Status OrdemDeProducao::getStatus() {
  return this->status;
}

//setters
void OrdemDeProducao::setProduto(Produto* produto) {
  this->produto = produto;
}
void OrdemDeProducao::setData(Data data) {
  this->data = data;
}
void OrdemDeProducao::setQuantidade(int quantidade) {
  this->quantidade = quantidade;
}
void OrdemDeProducao::setStatus(Status status) {
  this->status = status;
}