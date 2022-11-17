#ifndef PEDIDO_DE_COMPRA_H
#define PEDIDO_DE_COMPRA_H

#include "ItensDesejados.hpp"
#include "RegistroVenda.hpp"
#include "PagamentoAbstrata.hpp"
#include "Data.hpp"
#include <vector>

class PedidoDeCompra {
  private:
    float valorDaCompra;
    std::vector <RegistroVenda*> registroVenda;
    Data data;
    PagamentoAbstrata* registroDePagamento;

  public:
    // Construtores e Destrutores
    PedidoDeCompra(float);
    PedidoDeCompra();
    ~PedidoDeCompra();

    //getters
    float getValor();
    Data getData();
    pagamentoAbstrata* getRegistropagamento();
    std::vector<RegistroVenda*> getRegistroVenda();
    
    //setters
    void setValor(float);
    void setRegistroVenda(std::vector <RegistroVenda*>);
    void setData(Data);
    void setRegistroPagamento(PagamentoAbstrata*);
    //métodos
};


#endif // PEDIDO_DE_COMPRA_H