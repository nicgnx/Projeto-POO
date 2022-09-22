#include "../includes/Salario.hpp"

Salario::Salario(double salarioBase, double variacaoSalarial, Data data, Motivo motivacao) {
  this->salarioBase = salarioBase;
  this->variacaoSalarial = variacaoSalarial;
  this->data = data;
  this->motivacao = motivacao;
}

Salario::~Salario() {
  
}
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