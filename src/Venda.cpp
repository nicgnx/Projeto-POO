#include "../includes/Venda.hpp"
#include <iostream>

Venda::Venda(int idProduto, Data dataVenda, Cliente* cliente, int quantidade){
  
  this->idProduto = idProduto;
  this->dataVenda = dataVenda;
  this->cliente = cliente;
  this->quantidade = quantidade;
  
  }

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
      else if(this->quantidade <= estoque->verificaEstoque(this->idProduto)){
      return true;
        }
  }

  void Venda::executaVenda(){
  
  }