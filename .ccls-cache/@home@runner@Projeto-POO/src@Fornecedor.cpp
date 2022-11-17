#include "../includes/Fornecedor.hpp"


Fornecedor::Fornecedor(std::string nome) {
  this->nome = nome;
}
Fornecedor::~Fornecedor() {
  
}


//getters

std::map<int,float> Fornecedor::getMateriaPrima() {
  return this->produtosFornecidos;
}
std::string Fornecedor::getNome() {
  return this->nome;
}

//setters
void Fornecedor::setMateriaPrima(int idMateriaPrima, float preco) {
  this->produtosFornecidos[idMateriaPrima] = preco;
}
void Fornecedor::setNome(std::string nome) {
  this->nome = nome;
}

//Métodos
float Fornecedor::enviaPreco(int idMateriaPrima){
  return this->produtosFornecidos[idMateriaPrima];
}

bool Fornecedor::possuiProduto(int idMateriaPrima){
  bool aux;
  this->produtosFornecidos.find(idMateriaPrima) != this->produtosFornecidos.end() ? aux = 1 : aux = 0;
  return aux;
}