#ifndef VENDA_H
#define VENDA_H

#include "Data.hpp"
#include "Cliente.hpp"
#include "Lote.hpp"
#include <vector>

class Venda{
  
  Data dataVenda;
  Cliente* cliente;
  int quantidade;
  vector<Lote*> lotes;
  
public:
  Venda(Data dataVenda, Cliente* cliente, int quantidade);
  ~Venda();
//getters
  Data getDataVenda();
  Cliente getCliente();
  int getQuantidade();
  int getLotes();

//setters
  void setDataVenda(Data data);
  void setCliente(Cliente* cliente);
  void setQuantidade(int quantidade);
  void setLotes(Lote* lote);

//outros metodos
  bool VerificaEstoque();
  void executaVenda();
  


};

#endif 