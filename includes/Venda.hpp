#ifndef VENDA_H
#define VENDA_H

#include "Data.hpp"
#include "Lote.hpp"
#include "./Estoque.hpp"
#include <vector>

class Venda{
  std::string cliente;
  int cpfCnpj;
  std::string email;
  int idProduto;
  int quantidade;
  Data dataVenda;
  float precoUnitario;
  std::vector<int> idLotes;
 
 
  
public:
  Venda(std::string cliente, int cpfCnpj, std::string email, int idProduto, int quantidade, Data dataVenda);
  ~Venda();
//getters
  std::string getCliente();
  int getCpfCnpj();
  std::string getEmail();
  int getIdProduto();
  int getQuantidade();
  Data getDataVenda();
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