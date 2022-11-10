#include "../includes/Fornecedor.hpp"

Fornecedor::Fornecedor(std::string nome) {
  this->nome = nome;
}
Fornecedor::~Fornecedor() {
  
}

void Fornecedor::AdcionaMateriaPrima(MateriaPrima materiaPrima) {
  this->materiaPrima.push_back(materiaPrima);
}

//getters
std::vector <MateriaPrima> Fornecedor::getMateriaPrima() {
  return this->materiaPrima;
}
std::string Fornecedor::getNome() {
  return this->nome;
}

//setters
void Fornecedor::setMateriaPrima(std::vector <MateriaPrima> materiaPrima) {
  this->materiaPrima = materiaPrima;
}
void Fornecedor::setNome(std::string nome) {
  this->nome = nome;
}