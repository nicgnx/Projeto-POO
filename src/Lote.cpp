#include "../includes/Lote.hpp"

int Lote::lotesTotais = 0;

Lote::Lote(int idProduto, Data data, int quantidade)
    : idLote(this->lotesTotais) {
    this->data = data;
    this->idProduto = idProduto;
    this->quantidade = quantidade;
    this->lotesTotais += 1;
    this->status = Status::ESTOQUE;
}

Lote::Lote() : idLote(this->lotesTotais) {
    this->lotesTotais += 1;
    this->status = Status::ESTOQUE;
    this->data = data.dateNow();
    this->idProduto = -1;
    this->quantidade = -1;
}

Lote::~Lote() {}

void Lote::updateLotes(int quantidade) {
    this->quantidade -= quantidade;
    if (this->quantidade <= 0) {
        this->quantidade = 0;
        this->status = Status::VENDIDO;
    }
}

// getters
int Lote::getIdProduto() { return this->idProduto; }
Data Lote::getData() { return this->data; }
int Lote::getQuantidade() { return this->quantidade; }
int Lote::getIdLote() { return this->idLote; }
int Lote::getLotesTotais() { return this->lotesTotais; }
Status Lote::getStatus() { return this->status; }

// setters
void Lote::setIdProduto(int idProduto) { this->idProduto = idProduto; }
void Lote::setData(Data data) { this->data = data; }
void Lote::setQuantidade(int quantidade) { this->quantidade = quantidade; }
void Lote::setStatus(Status status) { this->status = status; }
