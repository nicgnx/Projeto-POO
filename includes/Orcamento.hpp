#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "ItensDesejados.hpp"
#include "PedidoDeCompra.hpp"
#include <vector>
#include <map>

class Orcamento {
protected:
  std::string cliente;
  std::string cpfCnpj;
  std::string email;

  Data data;
  std::vector<ItensDesejados*> carrinho;
  float valorTotal;
 
  PedidoDeCompra* pedido;

public:
  // Construtores e Destrutores
  Orcamento(std::string cliente, std::string cpfCnpj, std::string email,    std::map<int, int> itensDesejados);
  ~Orcamento();

  // getters
  std::string getCliente();
  std::string getCpfCnpj();
  std::string getEmail();
  std::vector<ItensDesejados*> getCarrinho();
  float getValorTotal();
  Data getData();
  PedidoDeCompra* getPedido();

  // setters
  void setCliente(std::string cliente);
  void setCpfCnpj(int cpfCnpj);
  void setEmail(std::string email);
  void setCarrinho(std::vector<ItensDesejados*> carrinho);
  void setValorTotal(float valorTotal);
  void setData(Data data);
  void setPedido(PedidoDeCompra* pedido);

  // Métodos
  void calculaValorTotal();
  void gerarPedidoDeCompra(Data DataCompra);
  void printOrcamento();
  void printOrcamentoAprovado(Orcamento* orcamento);//
};

#endif 