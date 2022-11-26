#include "../includes/Orcamento.hpp"
#include <string>

// Construtores e Destrutores

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
    
  } calculaValorTotal();
}

Orcamento::~Orcamento() {}

// Getters

std::string Orcamento::getCliente() { return this->cliente; };

std::string Orcamento::getCpfCnpj() { return this->cpfCnpj; };

std::string Orcamento::getEmail() { return this->email; };

std::vector<ItensDesejados*> Orcamento::getCarrinho() { return this->carrinho; };

float Orcamento::getValorTotal() { return this->valorTotal; };

Data Orcamento::getData() { return this->data; };

PedidoDeCompra* Orcamento::getPedido() { return this->pedido; };


// Setters

void Orcamento::setCliente(std::string cliente) { this->cliente = cliente; };

void Orcamento::setCpfCnpj(int cpfCnpj) { this->cpfCnpj = cpfCnpj; };

void Orcamento::setEmail(std::string email) { this->email = email; };

void Orcamento::setCarrinho(vector<ItensDesejados*> carrinho) {this->carrinho = carrinho;};

void Orcamento::setValorTotal(float valorTotal) {this->valorTotal = valorTotal;};

void Orcamento::setData(Data data) { this->data = data; };

void Orcamento::setPedido(PedidoDeCompra* pedido) { this->pedido = pedido; };


// Métodos

void Orcamento::calculaValorTotal(){
  for(int it = 0; it < this->carrinho.size(); it++){
    this->valorTotal += this->carrinho[it]->getValorTotal();
  }
}

void Orcamento::gerarPedidoDeCompra(Data dataCompra){
setPedido(new PedidoDeCompra(getCarrinho(), dataCompra, getValorTotal(), getCpfCnpj()));
}

void Orcamento::printOrcamento(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n"
            << "             Empresa - Orçamento para " << getCliente() << " (" << getCpfCnpj() << ") "
            << "- Data: "; getData().printData(); 
  std::cout << "\n\n\nProdutos Desejados: " << "\n\n\n";
    std::vector<ItensDesejados*> itens = getCarrinho();
    for(int i = 0; i < itens.size(); i++){
      std::cout << "Nome:            " << itens[i]->getProduto() << "\n\n"
                << "ID:              " << itens[i]->getIdProduto() << "\n\n"
                << "Quantidade:      " << itens[i]->getQuantidade() << "\n\n"
                << "Preço Unitario:  R$ " << itens[i]->getPrecoUnitario() << "\n\n"
                << "Disponibilidade: ";
      itens[i]->getDisponibilidade() == false ? std::cout << "Em falta\n\n" : std::cout << "Em estoque\n\n";
      itens[i]->getDisponibilidade() == false ? std::cout << "Juros:           " << itens[i]->getJuros()*100 << "%\n\n" : std::cout << "Juros:           " << "Nenhum\n\n";
      std::cout << "Valor total:     R$ " << itens[i]->getValorTotal() << "\n"
                << "-----------------------------\n\n\n";
    }
  std::cout << "Valor total do Orçamento: R$ " << getValorTotal() << "\n\n";
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
}

void printOrcamentoAprovado (Orcamento* orcamento){
  
}

