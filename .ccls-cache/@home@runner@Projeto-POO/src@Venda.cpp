#include "../includes/Venda.hpp"
#include <iostream>

Venda::Venda(Data dataVenda, Cliente* cliente, int quantidade){
  this->dataVenda = dataVenda;
  this->cliente = cliente;
  this->quantidade = quantidade;
  
  }

  