#include "../includes/PedidoDeCompra.hpp"

// Construtores e Destrutores
PedidoDeCompra::PedidoDeCompra(float) {}
PedidoDeCompra::PedidoDeCompra() {}
PedidoDeCompra::~PedidoDeCompra() {}

// getters
float PedidoDeCompra::getValor() { return this->valor; }
Data PedidoDeCompra::getData() { return this->data; }
pagamentoAbstrata* PedidoDeCompra::getRegistroPagamento() {
    return this->registroPagamento;
}
std::vector<RegistroVenda*> PedidoDeCompra::getRegistroVenda() {
    return this->registroVenda;
}

// setters
void PedidoDeCompra::setValor(float valor) { this->valor = valor; }
void PedidoDeCompra::setRegistroVenda(std::vector<RegistroVenda*> registroVenda
) {
    this->registroVenda = registroVenda;
}
void PedidoDeCompra::setData(Data data) { this->data = data; }
void PedidoDeCompra::setRegistroPagamento(PagamentoAbstrata* registroPagamento
) {
    this->registroPagamento = registroPagamento;
}
// métodos
void PedidoDeCompra::registraPagamento() {}
vector<RegistroVenda> PedidoDeCompra::executaCompra(int, int) {}
void PedidoDeCompra::printaCompra() {}