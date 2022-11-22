#ifndef REGISTRO_VENDA_H
#define REGISTRO_VENDA_H

#include "../includes/Orcamento.hpp"
#include "./Estoque.hpp"
#include "Data.hpp"
#include "Lote.hpp"
#include <vector>

class RegistroVenda {
  std::string cliente;
  std::string cpfCnpj;
  std::string email;
  Data dataVenda;
  float valorVenda;
  std::vector<itensDesejados*> itens;
  std::vector<int> idLotes;

public:
  RegistroVenda(
    std::string cliente, std::string cpfCnpj, std::string email, Data dataVenda, Orcamento* orcamento
  );
  ~RegistroVenda();
  // getters
  std::string getCliente();
  int getCpfCnpj();
  std::string getEmail();
  int getIdProduto();
  int getQuantidade();
  Data getDataVenda();
  std::vector<int> getLotes();
  float getPrecoUnitario();
  float getValorVenda();

  // setters
  void setCliente(std::string cliente);
  void setCpfCnpj(int cpfCnpj);
  void setEmail(std::string email);
  void setIdProduto(int idProduto);
  void setQuantidade(int quantidade);
  void setDataVenda(Data dataVenda);
  void setLotes(Lote* lote);
  void setPrecoUnitario();
  void setValorVenda();

  // outros metodos
  // bool verificaVenda();
  void executaVenda();
  void printRegistro();
};

#endif