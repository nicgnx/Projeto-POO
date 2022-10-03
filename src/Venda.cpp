#include "../includes/Venda.hpp"
#include <iostream>

Venda::Venda(Data dataVenda, Cliente* cliente, int quantidade){
  this->dataVenda = dataVenda;
  this->cliente = cliente;
  this->quantidade = quantidade;
  
  }

  Data Venda::getDataVenda(){
    return this->dataVenda;
  }

  Cliente Venda::getCliente(){
    return this->cliente;
  }

  int Venda::getQuantidade(){
    return this->quantidade;
  }

  int Venda::getLotes(){
    for(int it = lotes.begin(); it++; it != lotes.end()){
       return this->it.getNumLote();
    }
  }



