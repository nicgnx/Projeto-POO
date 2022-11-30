#ifndef ITENS_DESEJADOS_H
#define ITENS_DESEJADOS_H

#include <string>
#include "Estoque.hpp"

class ItensDesejados {
protected:
  int idProduto;
  int quantidade;
  std::string produto;
  float precoUnitario;
  float valorTotal;
  bool disponibilidade;
  float juros;

public:
  // Construtores e Destrutores
  ItensDesejados(int idProduto, int quantidade);
  ItensDesejados();
  ~ItensDesejados();

  // getters
  std::string getProduto();
  int getIdProduto();
  float getPrecoUnitario();
  float getJuros();
  int getQuantidade();
  float getValorTotal();
  bool getDisponibilidade();

  // setters
  void setProduto(std::string produto);
  void setIdProduto(int idProduto);
  void setPrecoUnitario(float precoUnitario);
  void setJuros(float juros);
  void setQuantidade(int quantidade);
  void setValorTotal(float valorTotal);
  void setDisponibilidade(bool disponibilidade);

  // misc
  void calculaValorTotal();
  void verificaDisponibilidade(int idProduto);
};

#endif // ITENS_DESEJADOS_H