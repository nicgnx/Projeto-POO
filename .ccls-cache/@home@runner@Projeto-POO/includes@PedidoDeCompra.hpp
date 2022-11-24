#ifndef PEDIDO_DE_COMPRA_H
#define PEDIDO_DE_COMPRA_H

#include "Data.hpp"
#include "ItensDesejados.hpp"
#include "PagamentoAbstrata.hpp"
#include "RegistroVenda.hpp"
#include <vector>

const std::vector<std::string>tiposDePagamento = {"boleto", "credito"};
const std::vector<std::string>formasDePagamento = {"30", "60", "90", "a_vista", "x1", "x2", "x3", "x4", "x5", "x6"};
class PedidoDeCompra {
private:
  float valorDaCompra;
  std::vector<RegistroVenda*> registroVenda;
  Data dataPedido;
  PagamentoAbstrata* registroPagamento;

public:
  // Construtores e Destrutores
  PedidoDeCompra(std::vector<ItensDesejados*> itens, Data dataPedido, float valorDaCompra, std::string cpfCnpj);
  PedidoDeCompra();
  ~PedidoDeCompra();

  // getters
  float getValorDaCompra();
  Data getDataPedido();
  PagamentoAbstrata* getRegistroPagamento();
  std::vector<RegistroVenda*> getRegistroVenda();

  // setters
  void setValorDaCompra(float);
  void setRegistroVenda(std::vector<RegistroVenda*> registroVenda);
  void setDataPedido(Data dataPedido);
  void setRegistroPagamento(PagamentoAbstrata*);
  // métodos
  void registraPagamento(std::string, std::string);
  void executaCompra();
  void printaCompra();
};

#endif // PEDIDO_DE_COMPRA_H