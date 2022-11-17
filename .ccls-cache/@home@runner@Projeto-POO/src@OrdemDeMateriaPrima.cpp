#include "../includes/OrdemDeMateriaPrima.hpp"

OrdemDeMateriaPrima::OrdemDeMateriaPrima(MateriaPrima materiaPrima,int quantidade,Data data) {
  this->quantidade = quantidade;
  this->materiaPrima = materiaPrima;
  this->data = data;
}
OrdemDeMateriaPrima::~OrdemDeMateriaPrima() {}

// getters
std::string OrdemDeMateriaPrima::getMateriaPrima() {return this->materiaPrima;}

int OrdemDeMateriaPrima::getquantidade() { return this->quantidade; }

Data OrdemDeMateriaPrima::getData() { return this->data; }

// setters
void OrdemDeMateriaPrima::setMateriaPrima(std::string materiaPrima) {this->materiaPrima = materiaPrima;}

void OrdemDeMateriaPrima::setQuantidade(int quantidade) {this->quantidade = quantidade;}

void OrdemDeMateriaPrima::setData(Data data) { this->data = data; }

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
    } return fornecedor;
  }
}

void OrdemDeMateriaPrima::printOrdemDeMP(){
  std::cout << "----------------------------------------------------------------------------------------------------\n"
            << "                              Resumo da Ordem de Reabasdtecimento de Materia Prima\n\n"
            << ""
}