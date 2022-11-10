#include "../includes/Venda.hpp"

#include <iostream>


Venda::Venda(std::string cliente, int cpfCnpj, std::string email, int idProduto, int quantidade, Data dataVenda){
  this->cliente = cliente;
  this->cpfCnpj = cpfCnpj;
  this->email = email;
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  this->dataVenda = dataVenda;

}

Venda::~Venda(){}
// Getters

std::string Venda::getCliente(){
  return this->cliente;
}

int Venda::getCpfCnpj(){
  return this->cpfCnpj;
}

std::string Venda::getEmail(){
  return this->email;
}

int Venda::getIdProduto(){
  return this->idProduto;
}

int Venda::getQuantidade(){
  return this->quantidade;
}

Data Venda::getDataVenda(){
  return this->dataVenda;
}


std::vector <int> Venda::getLotes(){
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
  this->precoUnitario = estoque->getProduto(this->idProduto)->getPrecos()->getPrecoBase();
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
  this->idLotes = estoque->retiraLotes(this->idProduto, this->quantidade);
  setPrecoUnitario();
  setValorVenda();
  printVenda();
}

void Venda::printVenda(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "   Compra realizada com sucesso! Segue abaixo as informações da compra.\n\n";
  std::cout << "   Cliente: " << this->cliente << "\n";
  std::cout << "   Data: "; this->dataVenda.printData(); std::cout << "\n";
  std::cout << "   Produto: " << Estoque::getInstancia()->getProduto(this->idProduto)->getNome() << "\n";
  std::cout << "   Quantidade: " << this->quantidade << "\n";
  std::cout << "   Preço da unidade: " << this->precoUnitario << "\n";
  std::cout << "   Valor Total: " << this->valorVenda << "\n";
  std::cout << "   Lotes:";
  for(int num = 0;num < idLotes.size(); num++){
    num == idLotes.size() - 1 ? std::cout << " " << idLotes[num] : std::cout << " " << idLotes[num] << ",";
  }
  std::cout << "\n\n";
  std::cout << "----------------------------------------------------------------------------------------------------\n";
}