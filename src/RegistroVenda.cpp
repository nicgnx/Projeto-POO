#include "../includes/RegistroVenda.hpp"

#include <iostream>

RegistroVenda::RegistroVenda(
    std::string cliente, int cpfCnpj, std::string email, int idProduto,
    int quantidade, Data dataVenda
) {
    this->cliente = cliente;
    this->cpfCnpj = cpfCnpj;
    this->email = email;
    this->idProduto = idProduto;
    this->quantidade = quantidade;
    this->dataVenda = dataVenda;
}

RegistroVenda::~RegistroVenda() {}
// Getters

std::string RegistroVenda::getCliente() { return this->cliente; }

int RegistroVenda::getCpfCnpj() { return this->cpfCnpj; }

std::string RegistroVenda::getEmail() { return this->email; }

int RegistroVenda::getIdProduto() { return this->idProduto; }

int RegistroVenda::getQuantidade() { return this->quantidade; }

Data RegistroVenda::getDataVenda() { return this->dataVenda; }

std::vector<int> RegistroVenda::getLotes() { return this->idLotes; }

float RegistroVenda::getPrecoUnitario() { return this->precoUnitario; }

// Setters

void RegistroVenda::setDataVenda(Data data) { this->dataVenda = data; }

void RegistroVenda::setCliente(std::string cliente) { this->cliente = cliente; }

void RegistroVenda::setCpfCnpj(int cpfCnpj) { this->cpfCnpj = cpfCnpj; }

void RegistroVenda::setEmail(std::string email) { this->email = email; }

void RegistroVenda::setIdProduto(int idProduto) { this->idProduto = idProduto; }

void RegistroVenda::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

void RegistroVenda::setLotes(Lote* lote) {
    this->idLotes.push_back(lote->getIdLote());
}

void RegistroVenda::setPrecoUnitario() {
    Estoque* estoque = Estoque::getInstancia();
    this->precoUnitario =
        estoque->getProduto(this->idProduto)->getPrecos()->getPrecoBase();
}

/*bool RegistroVenda::verificaVenda(){
  Estoque* estoque = Estoque::getInstancia();
    if(this->quantidade > estoque->verificaEstoque(this->idProduto)){
      return false;
      }
    else {return true;}
}*/

void RegistroVenda::executaVenda() {
    Estoque* estoque = Estoque::getInstancia();
    this->idLotes = estoque->retiraLotes(this->idProduto, this->quantidade);
    setPrecoUnitario();
    setValorVenda();
    printRegistro();
}

void RegistroVenda::printRegistro() {
    std::cout
        << "---------------------------------------------------------------"
           "-------------------------------------\n\n";
    std::cout << "   Compra realizada com sucesso! Segue abaixo as informações "
                 "da compra.\n\n";
    std::cout << "   Cliente: " << this->cliente << "\n";
    std::cout << "   Data: ";
    this->dataVenda.printData();
    std::cout << "\n";
    std::cout << "   Produto: "
              << Estoque::getInstancia()->getProduto(this->idProduto)->getNome()
              << "\n";
    std::cout << "   Quantidade: " << this->quantidade << "\n";
    std::cout << "   Preço da unidade: " << this->precoUnitario << "\n";
    std::cout << "   Valor Total: " << this->valorVenda << "\n";
    std::cout << "   Lotes:";
    for (int num = 0; num < idLotes.size(); num++) {
        num == idLotes.size() - 1 ? std::cout << " " << idLotes[num] :
                                    std::cout << " " << idLotes[num] << ",";
    }
    std::cout << "\n\n";
    std::cout
        << "---------------------------------------------------------------"
           "-------------------------------------\n";
}