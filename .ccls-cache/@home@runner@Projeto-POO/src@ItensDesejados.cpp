#include "../includes/ItensDesejados.hpp"
#include <string>

ItensDesejados::ItensDesejados(
  std::string produto,
  int idProduto,
  float precoUnitario,
  int quantidade,
  float valorTotal,
  bool disponibilidade
) {
  this->produto = produto;
  this->idProduto = idProduto;
  this->precoUnitario = precoUnitario;
  this->quantidade = quantidade;
  this->valorTotal = valorTotal;
  this->disponibilidade = disponibilidade;
}

ItensDesejados::~ItensDesejados() {}

  std::string ItensDesejados::getProduto();
  int ItensDesejados::getIdProduto();
  float ItensDesejados::getPrecoUnitario();
  int ItensDesejados::getQuantidade(); 
  float ItensDesejados::getValorTotal();
  bool ItensDesejados::getDisponibilidade();

void Historico::setData(Data data) { this->data = data; }

void Historico::setRegistro(std::string registro) { this->registro = registro; }

