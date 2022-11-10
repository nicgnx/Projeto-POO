#ifndef VENDA_H
#define VENDA_H

#include "Data.hpp"
#include "Lote.hpp"
#include "./Estoque.hpp"
#include <vector>

class Venda{

  int idProduto;
  Data dataVenda;
  Cliente* cliente;
  int quantidade;
  std::vector<int> idLotes;
  float precoUnitario;
  float valorVenda;
 
  
public:
  Venda(int idProduto, int quantidade, Data dataVenda, std::string cliente);
  ~Venda();
//getters
  int getIdProduto();
  Data getDataVenda();
  Cliente* getCliente();
  int getQuantidade();
  std::vector <int> getLotes();
  float getPrecoUnitario();
  float getValorVenda();

//setters
  void setDataVenda(Data data);
  void setCliente(Cliente* cliente);
  void setQuantidade(int quantidade);
  void setLotes(Lote* lote);
  void setPrecoUnitario();
  void setValorVenda();


//outros metodos
  bool verificaVenda();
  void executaVenda();
  void printVenda();
};

#endif 