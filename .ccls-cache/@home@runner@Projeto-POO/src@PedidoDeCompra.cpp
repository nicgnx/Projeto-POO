#include "../includes/PedidoDeCompra.hpp"

    // Construtores e Destrutores
    PedidoDeCompra::PedidoDeCompra(float) {
      
    }
    PedidoDeCompra::PedidoDeCompra() {
      
    }
    PedidoDeCompra::~PedidoDeCompra() {
      
    }

    //getters
    float PedidoDeCompra::getValor() {
      
    }
    Data PedidoDeCompra::getData() {
      
    }
    pagamentoAbstrata* PedidoDeCompra::getRegistropagamento() {
      
    }
    std::vector<RegistroVenda*> PedidoDeCompra::getRegistroVenda() {
      
    }
    
    //setters
    void PedidoDeCompra::setValor(float valor) {
      
    }
    void PedidoDeCompra::setRegistroVenda(std::vector <RegistroVenda*> registroVenda) {
      this->registroVenda = registroVenda;
    }
    void PedidoDeCompra::setData(Data data) {
      
    }
    void PedidoDeCompra::setRegistroPagamento(PagamentoAbstrata* registroPagamento) {
      
    }
    //métodos