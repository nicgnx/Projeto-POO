#ifndef ITENS_DESEJADOS_H
#define ITENS_DESEJADOS_H

#include <string>
#include "Estoque.hpp"

class ItensDesejados {
protected:
  std::string produto;
  int idProduto;
  float precoUnitario;
  int quantidade;
  float valorTotal;
  bool disponibilidade;
  ;

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