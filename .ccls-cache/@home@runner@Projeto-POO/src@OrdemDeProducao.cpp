#include "../includes/OrdemDeProducao.hpp"

OrdemDeProducao::OrdemDeProducao(Produto* produto, Data data, int quantidade) {
  this->IdProduto = produto;
  this->data = data;
  this->quantidade = quantidade;
}

OrdemDeProducao::~OrdemDeProducao() {
  
}

Lote* OrdemDeProducao::solicitaLote() {
  Lote* lote = new Lote(this->IdProduto, this->data, this->quantidade);
  return lote;
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
