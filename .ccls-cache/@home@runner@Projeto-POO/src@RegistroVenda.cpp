#include "../includes/RegistroVenda.hpp"



RegistroVenda::RegistroVenda(std::string cpfCnpj,int idProduto, int quantidade, float precoUnitario,  Data dataVenda) {
  
  this->cpfCnpj = cpfCnpj;
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  this->precoUnitario = precoUnitario;
  this->dataVenda = dataVenda;

  executaVenda();

  
}

RegistroVenda::~RegistroVenda() {}
// Getters



std::string RegistroVenda::getCpfCnpj() { return this->cpfCnpj; }

int RegistroVenda::getIdProduto() { return this->idProduto; }

int RegistroVenda::getQuantidade() { return this->quantidade; }

Data RegistroVenda::getDataVenda() { return this->dataVenda; }

std::vector<int> RegistroVenda::getLotes() { return this->idLotes; }

float RegistroVenda::getPrecoUnitario() { return this->precoUnitario; }

// Setters


void RegistroVenda::setCpfCnpj(int cpfCnpj) { this->cpfCnpj = cpfCnpj; }

void RegistroVenda::setIdProduto(int idProduto) { this->idProduto = idProduto; }

void RegistroVenda::setQuantidade(int quantidade) { this->quantidade = quantidade; }

void RegistroVenda::setDataVenda(Data data) { this->dataVenda = data; }

void RegistroVenda::setLotes(Lote* lote) {
  this->idLotes.push_back(lote->getIdLote());
}

void RegistroVenda::setPrecoUnitario(float precoUnitario) {
   this->precoUnitario = precoUnitario;
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
  

  
}

void RegistroVenda::printRegistro() {
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n\n";
  std::cout << "   Compra realizada com sucesso! Segue abaixo as informações "
               "da compra.\n\n";
  std::cout << "   Cpf/Cnpj cliente: " << this->cpfCnpj << "\n";
  std::cout << "   Data: ";
  this->dataVenda.printData();
  std::cout << "\n";
  std::cout << "   Produto: "
            << Estoque::getInstancia()->getProduto(this->idProduto)->getNome()
            << "\n";
  std::cout << "   Quantidade: " << this->quantidade << "\n";
  std::cout << "   Preço da unidade: " << this->precoUnitario << "\n";
  // std::cout << "   Valor Total: " << this->valorVenda << "\n";
  std::cout << "   Lotes:";
  for (int num = 0; num < idLotes.size(); num++) {
    num == idLotes.size() - 1 ? std::cout << " " << idLotes[num] :
                                std::cout << " " << idLotes[num] << ",";
  }
  std::cout << "\n\n";
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n";
}