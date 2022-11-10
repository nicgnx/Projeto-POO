#include "../includes/Orcamento.hpp"
#include <string>

Orcamento::Orcamento(
  std::string cliente,
  int cpfCnpj,
  std::string email,
  vector<ItensDesejados> carrinho,
  float valorTotal,
  Data data,
  PedidoDeCompra pedido
) {
  this->cliente = cliente;
  this->cpfCnpj = cpfCnpj;
  this->email = email;
  this->carrinho = carrinho;
  this->valorTotal = valorTotal;
  this->data = data;
  this->pedido = pedido;
}

Orcamento::~Orcamento() { }

std::string Orcamento::getCliente() {
  return this->cliente;
};

int Orcamento::getCpfCnpj() {
  return this->cpfCnpj;
};

std::string Orcamento::getEmail() {
  return this->email;
};

vector<ItensDesejados> Orcamento::getCarrinho() {
  return this->carrinho;
};

float Orcamento::getValorTotal() {
  return this->valorTotal;
}; 

Data Orcamento::getData() {
  return this->data;
};

PedidoDeCompra Orcamento::getPedido() {
  return this->pedido;
};

void Orcamento::setCliente(std::string cliente) {
  this->cliente = cliente;
};

void Orcamento::setCpfCnpj(int cpfCnpj) {
  this->cpfCnpj = cpfCnpj;
};

void Orcamento::setEmail(std::string email) {
  this->email = email;
};

void Orcamento::setCarrinho(vector<ItensDesejados> carrinho) {
  this->carrinho = carrinho;
}; 

void Orcamento::setValorTotal(float valorTotal) {
  this->valorTotal = valorTotal;
};

void Orcamento::setData(Data data) {
  this->data = data;
};

void Orcamento::setPedido(PedidoDeCompra pedido) {
  this->pedido = pedido;
};


bool Orcamento::verificaOrcamento(vector<ItensDesejados> carrinho) {
  
};

void Orcamento::printaOrcamento() {
  
};

PedidoDeCompra Orcamento::gerarPedidoDeCompra(vector<ItensDesejados> itens, string tipoPagamento, string forma) {
  
};

