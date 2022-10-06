#ifndef VENDA_H
#define VENDA_H

#include "Data.hpp"
#include "Cliente.hpp"
#include "Lote.hpp"
#include <vector>

class Venda{

  int idProduto
  Data dataVenda;
  Cliente* cliente;
  int quantidade;
  vector<int> lotes;
  float precoUnitario;
  float valorVenda;
  Estoque& estoque;
  
public:
  Venda(int idProduto, Data dataVenda, Cliente* cliente, int quantidade);
  ~Venda();
//getters
  int idProduto
  Data getDataVenda();
  Cliente* getCliente();
  int getQuantidade();
  vector <int> getLotes();
  float precoUnitario;
  float valorVenda;

//setters
  void setDataVenda(Data data);
  void setCliente(Cliente* cliente);
  void setQuantidade(int quantidade);
  void setLotes(vector <int> lote);
  void setPrecoUnitario(float precoUnitario);
  void setValorVenda(float valorVenda);
  void setEstoque(Estoque& estoque);

//outros metodos
  bool verificaVenda();
  void executaVenda();
};

#endif 