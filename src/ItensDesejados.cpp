#include "../includes/ItensDesejados.hpp"
#include <string>

ItensDesejados::ItensDesejados( int idProduto, int quantidade) {
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  
}

ItensDesejados::~ItensDesejados() {}

std::string ItensDesejados::getProduto() { return this->produto; };

int ItensDesejados::getIdProduto() { return this->idProduto; };

float ItensDesejados::getPrecoUnitario() { return this->precoUnitario; };

int ItensDesejados::getQuantidade() { return this->quantidade; };

float ItensDesejados::getValorTotal() { return this->valorTotal; };

bool ItensDesejados::getDisponibilidade() { return this->disponibilidade; };

void ItensDesejados::setProduto(std::string produto) {
  this->produto = produto;
};

void ItensDesejados::setIdProduto(int idProduto) {
  this->idProduto = idProduto;
};

void ItensDesejados::setPrecoUnitario(float precoUnitario) {
  this->precoUnitario = precoUnitario;
};

void ItensDesejados::setQuantidade(int quantidade) {
  this->quantidade = quantidade;
};

void ItensDesejados::setValorTotal(float valorTotal) {
  this->valorTotal = valorTotal;
};

void ItensDesejados::setDisponibilidade(bool disponibilidade) {
  this->disponibilidade = disponibilidade;
};

void ItensDesejados::calculaValorTotal(){

  this->disponibilidade == false ? this->valorTotal = this->quantidade * this->precoUnitario * 0.05 : this->valorTotal = this->quantidade * this->precoUnitario;
  
}

void ItensDesejados::verificaDisponibilidade(int idProduto){
  Estoque* estoque = Estoque::getInstancia();
  
  Produto* produto = estoque->getProduto(idProduto);

  this->produto = produto->getNome();
  this->precoUnitario = produto->getPrecos()->getPrecoBase();
 (estoque->verificaEstoqueProduto(idProduto) + estoque->capacidadeDeProducao(idProduto))<this->quantidade? this->disponibilidade = false : this->disponibilidade = true;

  calculaValorTotal();

  
};
