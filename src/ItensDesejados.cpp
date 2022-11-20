#include "../includes/ItensDesejados.hpp"
#include <string>

ItensDesejados::ItensDesejados(
  std::string produto, int idProduto, float precoUnitario, int quantidade,
  float valorTotal, bool disponibilidade
) {
  this->produto = produto;
  this->idProduto = idProduto;
  this->precoUnitario = precoUnitario;
  this->quantidade = quantidade;
  this->valorTotal = valorTotal;
  this->disponibilidade = disponibilidade;
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

float ItensDesejados::calculaCompra(float precoUnitario, int quantidade){

};

bool ItensDesejados::verificaDisponibilidade(int idProduto){

};
