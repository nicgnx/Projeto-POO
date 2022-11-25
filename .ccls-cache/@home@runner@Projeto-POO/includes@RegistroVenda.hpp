#ifndef REGISTRO_VENDA_H
#define REGISTRO_VENDA_H


#include "Estoque.hpp"
#include "Data.hpp"
#include "Lote.hpp"
#include <vector>
#include <iostream>

enum STATUS{
  AGUARDANDO,
  PROCESSANDO,
  CONCLUIDO
};

class RegistroVenda {

  std::string cpfCnpj;
  int idProduto;
  int quantidade;
  float precoUnitario; 
  std::vector<int> idLotes;
  Data dataVenda;
  STATUS status;


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
  STATUS getStatus();


  // setters

  void setCpfCnpj(int cpfCnpj);
  void setIdProduto(int idProduto);
  void setQuantidade(int quantidade);
  void setDataVenda(Data dataVenda);
  void setLotes(Lote* lote);
  void setPrecoUnitario(float precoUnitario);
  void setStatus(STATUS);

  // outros metodos
  // bool verificaVenda();
  void executaVenda();
  void printRegistro();
};

#endif