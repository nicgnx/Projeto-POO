#include "../includes/Venda.hpp"
#include <iostream>

Venda::Venda(int idProduto, Data dataVenda, Cliente* cliente, int quantidade){
  
  this->idProduto = idProduto;
  this->dataVenda = dataVenda;
  this->cliente = cliente;
  this->quantidade = quantidade;
  this->precoUnitario = Estoque::getInstance()->getProduto(idProduto)->getPreco();
  setValorVenda();  
}

// Getters

Data Venda::getDataVenda(){
  return this->dataVenda;
}

Cliente* Venda::getCliente(){
  return this->cliente;
}

int Venda::getQuantidade(){
  return this->quantidade;
}

vector <int> Venda::getLotes(){
  return this->idLotes;
}

float Venda::getPrecoUnitario(){
  return this->precoUnitario;
}

float Venda::getValorVenda(){
  return this->valorVenda;
}

// Setters

void Venda::setDataVenda(Data data){
  this->dataVenda = data;
}

void Venda::setCliente(Cliente* cliente){
  this->cliente = cliente;
}

void Venda::setQuantidade(int quantidade){
  this->quantidade = quantidade;
}

void Venda::setLotes(Lote* lote){
  this->idLotes.push_back(lote->getIdLote());
}

void Venda::setPrecoUnitario(){
  Estoque* estoque = Estoque::getInstancia();
  this->precoUnitario = estoque->getProduto(this->idProduto)->getIdProduto();
}

void Venda::setValorVenda(){
  this->valorVenda = this->precoUnitario * this->quantidade;
}


bool Venda::verificaVenda(){
  Estoque* estoque = Estoque::getInstancia();
    if(this->quantidade > estoque->verificaEstoque(this->idProduto)){
      return false;
      }
    else {return true;}
}

void Venda::executaVenda(){
  Estoque* estoque = Estoque::getInstancia();
  this->idLotes = estoque->retiraLotes(this->IdProduto, this->quantidade);
  setValorVenda();
  printVenda();
}

void Venda::printVenda(){
  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "   Compra realizada com sucesso! Segue abaixo as informações da compra.\n\n";
  std::cout << "   Cliente: " << this->cliente->getNome(); << "\n"
  std::cout << "   Data: " << this->data.printData(); << "\n"
  std::cout << "   Produto: " << this->produto; << "\n"
  std::cout << "   Preço da unidade: " << this->precoUnitario << "\n"
  std::cout << "   Valor Total: " << this->valorVenda; << "\n"
  std::cout << "   Lotes:";
  for(int num = 0;num < idLotes.size(); num++){
    num == idLotes.size() - 1 ? std::cout << " " << idLotes[num] : std::cout << " " << idLotes[num] << ",";
  }
  std::cout << "\n\n";
  std::cout << "----------------------------------------------------------------------------------------------------\n";
}