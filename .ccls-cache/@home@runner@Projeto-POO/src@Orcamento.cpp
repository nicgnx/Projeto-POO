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
  std::string print = " ";
  print = auxPrint(101-(50+getCliente().size()+getCpfCnpj().size()+getData().printData(true).size()));
  std::cout << "|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n|" << auxPrint(101) << "\n"
            << "|             Empresa - Orçamento para " << getCliente() << " (" << getCpfCnpj() << ") " << "- Data: " << getData().printData(true) << print
            << "\n|"<< auxPrint(101) <<"\n|" << auxPrint(101) << "\n| Produtos Desejados: " << auxPrint(101-21) << "\n|"<< auxPrint(101) <<"\n|"<< auxPrint(101) <<"\n|";
    std::vector<ItensDesejados*> itens = getCarrinho();
    for(int i = 0; i < itens.size(); i++){
      std::cout << " Nome:            " << itens[i]->getProduto() << auxPrint(101-(18+itens[i]->getProduto().size())) <<"\n|"<< auxPrint(101) << "\n|"
                << " ID:              " << itens[i]->getIdProduto() << auxPrint(101-(18+to_string(itens[i]->getIdProduto()).size())) <<"\n|"<< auxPrint(101) << "\n|"
                << " Quantidade:      " << itens[i]->getQuantidade() << auxPrint(101-(18+to_string(itens[i]->getQuantidade()).size())) <<"\n|"<< auxPrint(101) << "\n|"
                << " Preço Unitario:  R$ " << itens[i]->getPrecoUnitario() << auxPrint(101-(14+to_string(itens[i]->getPrecoUnitario()).size())) <<"\n|"<< auxPrint(101) << "\n|"
                << " Disponibilidade: ";
      itens[i]->getDisponibilidade() == false ? std::cout << "Em falta"<< auxPrint(101-26)<<"\n|"<< auxPrint(101) <<"\n|" : std::cout << "Em estoque"<< auxPrint(101-28)<<"\n|"<< auxPrint(101) <<"\n|";
      itens[i]->getDisponibilidade() == false ? std::cout << " Juros:           " << itens[i]->getJuros()*100 << "%" << auxPrint(101-20)<<"\n|"<< auxPrint(101) <<"\n|"  : std::cout << " Juros:           " << "Nenhum"<< auxPrint(101-24)<<"\n|"<< auxPrint(101) <<"\n|";
      std::cout << " Valor total:     R$ " << itens[i]->getValorTotal() << auxPrint(101-(14+to_string(itens[i]->getValorTotal()).size())) << "\n|"
                << "____________________________________________________________________________________________________|\n|"<< auxPrint(101) << "\n|"<< auxPrint(101) <<"\n|";
    }
  std::cout << " Valor total do Orçamento: R$ " << getValorTotal() << auxPrint(101-(23+to_string(getValorTotal()).size())) << "\n|" << auxPrint(101)<< "\n|";
  std::cout << "____________________________________________________________________________________________________|\n\n";
}

void printOrcamentoAprovado (Orcamento* orcamento){
  
}

std::string Orcamento::auxPrint(int tamanho){
  std::string print;
  print.insert(0,tamanho-1,' ');
  print.insert((tamanho-1),"|");
  return print;  
}