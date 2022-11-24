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
  vector<ItensDesejados*> carrinho;
  float valorTotal;
 
  PedidoDeCompra* pedido;

public:
  // Construtores e Destrutores
  Orcamento(
    std::string cliente, std::string cpfCnpj, std::string email,
    std::map<int, int> itensDesejados);
  Orcamento();
  ~Orcamento();

  // getters
  std::string getCliente();
  std::string getCpfCnpj();
  std::string getEmail();
  vector<ItensDesejados*> getCarrinho();
  float getValorTotal();
  Data getData();
  PedidoDeCompra* getPedido();

  // setters
  void setCliente(std::string cliente);
  void setCpfCnpj(int cpfCnpj);
  void setEmail(std::string email);
  void setCarrinho(vector<ItensDesejados*> carrinho);
  void setValorTotal(float valorTotal);
  void setData(Data data);
  void setPedido(PedidoDeCompra* pedido);

  // misc
  void calculaValorTotal();
  void printaOrcamento();
  PedidoDeCompra* gerarPedidoDeCompra(Data DataCompra
  );
};

#endif 