#include "../includes/Funcionario.hpp"

Funcionario::Funcionario() {
  
}

Funcionario::~Funcionario() {

}

Data Funcionario::getDataNascimento() {
  return this->dataNascimento;
}

std::string Funcionario::getEndereco() {
  return this->endereco;
}

std::string Funcionario::getMatricula() {
  return this->matricula;
}

Cargo Funcionario::getCargo() {
  return this->cargo;
}

Historico Funcionario::getHistorico() {
  // implementar aqui, tem que buscar na classe Histórico
}

Departamento Funcionario::getDepartamento() {
  return this->departamento;
}

float Funcionario::getSalarioAtual() {
  // implementar aqui, tem que buscar na classe Salario
}

void Funcionario::setDataNascimento(Data dataNascimento) {
  this->dataNascimento = dataNascimento;
}

void Funcionario::setEndereco(std::string endereco) {
  this->endereco = endereco;
}

void Funcionario::setMatricula(std::string matricula) {
  this->matricula = matricula;
}

void Funcionario::setCargo(Cargo cargo) {
  this->cargo = cargo;
}

void Funcionario::updateHistorico(Historico historico) {
  // implementar aqui, tem que trabalhar com vetor Historico[]
}

void Funcionario::setDepartamento(Departamento departamento) {
  this->departamento = departamento;
}

void Funcionario::setSalarioAtual() {
  // implementar aqui, tem que trabalhar com vetor Salario[]
}