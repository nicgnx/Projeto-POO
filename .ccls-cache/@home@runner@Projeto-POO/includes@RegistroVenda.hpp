#ifndef REGISTRO_VENDA_H
#define REGISTRO_VENDA_H


#include "Estoque.hpp"
#include "Data.hpp"
#include "Lote.hpp"
#include <vector>
#include <iostream>

class RegistroVenda {

  std::string cpfCnpj;
  int idProduto;
  int quantidade;
  float precoUnitario; 
  std::vector<int> idLotes;
  Data dataVenda;

public:
  RegistroVenda(
      std::string cpfCnpj,int idProduto, int quantidade, float precoUnitario,  Data dataVenda
  );
  ~RegistroVenda();
  // getters

  std::string getCpfCnpj();
  int getIdProduto();
  int getQuantidade();
  Data getDataVenda();
  std::vector<int> getLotes();
  float getPrecoUnitario();


  // setters

  void setCpfCnpj(int cpfCnpj);
  void setIdProduto(int idProduto);
  void setQuantidade(int quantidade);
  void setDataVenda(Data dataVenda);
  void setLotes(Lote* lote);
  void setPrecoUnitario(float precoUnitario);


  // outros metodos
  // bool verificaVenda();
  void executaVenda();
  void printRegistro();
};

#endif