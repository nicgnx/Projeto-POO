#include "../includes/OrdemDeMateriaPrima.hpp"

OrdemDeMateriaPrima::OrdemDeMateriaPrima(){}

OrdemDeMateriaPrima::OrdemDeMateriaPrima(MateriaPrima* materiaPrima,int quantidade,Data data, std::vector<Fornecedor*> fornecedores) {
  this->quantidade = quantidade;
  this->materiaPrima = materiaPrima;
  this->data = data;
  this->fornecedor = melhorPreco(materiaPrima.getId(),fornecedores);
}
OrdemDeMateriaPrima::~OrdemDeMateriaPrima() {}

// getters
MateriaPrima* OrdemDeMateriaPrima::getMateriaPrima() {return this->materiaPrima;}

int OrdemDeMateriaPrima::getQuantidade() { return this->quantidade; }

float OrdemDeMateriaPrima::getValorFinal(){ return this->valorFinal; }

Data OrdemDeMateriaPrima::getData() { return this->data; }

Fornecedor* OrdemDeMateriaPrima::getFornecedor(){ return this->fornecedor; }

// setters
void OrdemDeMateriaPrima::setMateriaPrima(MateriaPrima* materiaPrima) {this->materiaPrima = materiaPrima; }

void OrdemDeMateriaPrima::setQuantidade(int quantidade) {this->quantidade = quantidade; }

void OrdemDeMateriaPrima::setValorFinal(float valorFinal){ this->valorFinal = valorFinal; }

void OrdemDeMateriaPrima::setData(Data data) { this->data = data; }

void OrdemDeMateriaPrima::setFornecedor(Fornecedor* fornecedor){ this->fornecedor = fornecedor; }

//Métodos 
Fornecedor* OrdemDeMateriaPrima::melhorPreco(int idMateriaPrima, std::vector<Fornecedor*> fornecedores){
  std::vector<Fornecedor*> auxFornecedores;
  Fornecedor* fornecedor = NULL;
  for(int i = 0; i < fornecedores.size(); i++){
    if(fornecedores[i]->possuiProduto(idMateriaPrima))
      auxFornecedores.push_back(fornecedores[i]);
  }
  if (auxFornecedores.size() <= 0){
    std::cout << "Não temos fornecedores dessa materia prima.";
    return fornecedor;
  } else{
    float preco = 0.0;
    for(int i = 0; i < auxFornecedores.size(); i++){
      if(i != 0){
        if(preco > auxFornecedores[i]->enviaPreco(idMateriaPrima)){
          preco = auxFornecedores[i]->enviaPreco(idMateriaPrima);
          fornecedor = auxFornecedores[i];
        } 
      }
      else{
        preco = auxFornecedores[i]->enviaPreco(idMateriaPrima);
        fornecedor = auxFornecedores[i];
      }
    } 
    this->valorFinal = this->quantidade * fornecedor->enviaPreco(this->materiaPrima->getId());
    return fornecedor;
  }
}

void OrdemDeMateriaPrima::printOrdemDeMP(){
  std::cout << "----------------------------------------------------------------------------------------------------\n"
            << "                      Resumo da Ordem de Reabastecimento de Materia Prima\n\n"
            << "Materia Prima: " << this->materiaPrima->getNome() << "\n"
            << "Identificador: " << this->materiaPrima->getId() << "\n"
            << "Quantidade:    " << this->quantidade<< "\n"
            << "Preço:         R$ " << this->fornecedor->enviaPreco(this->materiaPrima->getId()) << "\n"
            << "Valor Final:   R$ " << this->valorFinal << "\n"
            << "Fornecedor:    " << this->fornecedor->getNome() << "\n"
            << "Data (UTC):    ";   this->data.printData(); std::cout << "\n"
            << "----------------------------------------------------------------------------------------------------\n";
}