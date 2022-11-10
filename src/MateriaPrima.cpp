#include "../includes/MateriaPrima.hpp"

MateriaPrima::MateriaPrima(int id, std::string nome, std::string unidade, int estoqueMinimo) {
  this->nome = nome;
  this->id = id;
  this->estoqueMinimo = estoqueMinimo;
  this->unidade = unidade;
}
MateriaPrima::~MateriaPrima() {
  
}
//getters
int MateriaPrima::getId() {
  return this->id;
}
std::string MateriaPrima::getNome() {
  return this->nome;
}
std::string MateriaPrima::getUnidade() {
  return this->unidade;
}
int MateriaPrima::getEstoqueMinimo() {
  return this->estoqueMinimo;
}

//setters
void MateriaPrima::setNome(std::string nome) {
  this->nome = nome;
}
void MateriaPrima::setUnidade(std::string unidade) {
  this->unidade = unidade;
}
void MateriaPrima::setEstoqueMinimo(int estoqueMinimo) {
  this->estoqueMinimo = estoqueMinimo;
}
