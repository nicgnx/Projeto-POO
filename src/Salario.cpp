#include "../includes/Salario.hpp"

Salario::Salario(double salarioBase, double variacaoSalarial,  Motivo motivacao, Data data = Data::dataNow()) {
  this->salarioBase = salarioBase;
  this->variacaoSalarial = variacaoSalarial;
  this->data = data;
  this->motivacao = motivacao;
}

// Construtores 
Salario::Salario() {}

Salario::~Salario() {}

// Getters
double Salario::getSalarioBase() {
  return this->salarioBase;
}
double Salario::getVariacaoSalarial() {
  return this->variacaoSalarial;
}
Data Salario::getData() {
  return this->data;
}
Motivo Salario::getMotivacao() {
  return this->motivacao;
}

// Setters

void Salario::setSalarioBase(double novoSalarioBase) {
  this->salarioBase = novoSalarioBase;
}
void Salario::setVariacaoSalarial(double novoVariacaoSalarial) {
  this->variacaoSalarial = novoVariacaoSalarial;
}
void Salario::setData(Data novoData) {
  this->data = novoData;
}
void Salario::setMotivacao(Motivo novoMotivacao) {
  this->motivacao = novoMotivacao;
}
