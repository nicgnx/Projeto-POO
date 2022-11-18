#include "../includes/OrdemDeProducao.hpp"

OrdemDeProducao::OrdemDeProducao(
    std::string produto, int idProduto, Data data, int quantidade
) {
    this->produto = produto;
    this->idProduto = idProduto;
    this->data = data;
    this->quantidade = quantidade;
}

OrdemDeProducao::~OrdemDeProducao() {}

// Métodos

Lote* OrdemDeProducao::solicitaLote() {
    return new Lote(this->idProduto, this->data, this->quantidade);
}

// getters
int OrdemDeProducao::getIdProduto() { return this->idProduto; }
Data OrdemDeProducao::getData() { return this->data; }
int OrdemDeProducao::getQuantidade() { return this->quantidade; }

// setters
void OrdemDeProducao::setIdProduto(int idProduto) {
    this->idProduto = idProduto;
}
void OrdemDeProducao::setData(Data data) { this->data = data; }
void OrdemDeProducao::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}
