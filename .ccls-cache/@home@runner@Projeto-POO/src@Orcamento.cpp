#include "../includes/Orcamento.hpp"
#include <string>

Orcamento::Orcamento(
  std::string cliente, std::string cpfCnpj, std::string email,
  std::map<int, int> itensDesejados) {
  
  this->cliente = cliente;
  this->cpfCnpj = cpfCnpj;
  this->email = email;
  this->data = Data().dateNow();
  
  for(auto it = itensDesejados.begin(); it != itensDesejados.end(); it++){
      ItensDesejados* itens = new ItensDesejados((*it).first,(*it).second);
      
      itens->verificaDisponibilidade(itens->getIdProduto());
    
      this->carrinho.push_back(itens);  
    
  }
}

Orcamento::~Orcamento() {}

std::string Orcamento::getCliente() { return this->cliente; };

std::string Orcamento::getCpfCnpj() { return this->cpfCnpj; };

std::string Orcamento::getEmail() { return this->email; };

std::vector<ItensDesejados*> Orcamento::getCarrinho() { return this->carrinho; };

float Orcamento::getValorTotal() { return this->valorTotal; };

Data Orcamento::getData() { return this->data; };

PedidoDeCompra* Orcamento::getPedido() { return this->pedido; };

void Orcamento::setCliente(std::string cliente) { this->cliente = cliente; };

void Orcamento::setCpfCnpj(int cpfCnpj) { this->cpfCnpj = cpfCnpj; };

void Orcamento::setEmail(std::string email) { this->email = email; };

void Orcamento::setCarrinho(vector<ItensDesejados*> carrinho) {
  this->carrinho = carrinho;
};

void Orcamento::setValorTotal(float valorTotal) {
  this->valorTotal = valorTotal;
};

void Orcamento::setData(Data data) { this->data = data; };

void Orcamento::setPedido(PedidoDeCompra* pedido) { this->pedido = pedido; };

// bool Orcamento::verificaOrcamento(vector<ItensDesejados> carrinho){

// };

void Orcamento::printOrcamento(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n"
            << "                            Empresa - Orçamento para " << getCliente() << " (" << getCpfCnpj() << ")\n\n"
            << "Produtos: " << "\n\n";
    std::vector<ItensDesejados*> itens = getCarrinho();
    for(auto i = itens.begin(); i != itens.end(); i++){
      std::cout << "Nome: " << (*i)->getProduto() << "ID: " << (*i)->getIdProduto();
    }
};

PedidoDeCompra* Orcamento::gerarPedidoDeCompra(Data dataCompra){
  PedidoDeCompra* pedido = new PedidoDeCompra(getCarrinho(),   dataCompra, getValorTotal(), getCpfCnpj());

  setPedido(pedido);
  
};

void Orcamento::calculaValorTotal(){

  for(auto it = this->carrinho.begin(); it != this->carrinho.end(); it++){
    this->valorTotal += (*it)->getValorTotal();
  }
  
}
