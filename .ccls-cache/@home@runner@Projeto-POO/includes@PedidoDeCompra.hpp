#ifndef PEDIDO_DE_COMPRA_H
#define PEDIDO_DE_COMPRA_H

#include "Data.hpp"
#include "ItensDesejados.hpp"
#include "PagamentoAbstrata.hpp"
#include "RegistroVenda.hpp"
#include <vector>

class PedidoDeCompra {
private:
  float valor;
  std::vector<RegistroVenda*> registroVenda;
  Data data;
  PagamentoAbstrata* registroPagamento;

public:
  // Construtores e Destrutores
  PedidoDeCompra(float);
  PedidoDeCompra();
  ~PedidoDeCompra();

  // getters
  float getValor();
  Data getData();
  PagamentoAbstrata* getRegistroPagamento();
  std::vector<RegistroVenda*> getRegistroVenda();

  // setters
  void setValor(float);
  void setRegistroVenda(std::vector<RegistroVenda*>);
  void setData(Data);
  void setRegistroPagamento(PagamentoAbstrata*);
  // métodos     TODO
  void registraPagamento();
  vector<RegistroVenda> executaCompra(int, int);
  void printaCompra();
};

#endif // PEDIDO_DE_COMPRA_H