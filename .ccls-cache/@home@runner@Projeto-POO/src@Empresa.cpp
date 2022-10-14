#include "../includes/Empresa.hpp"

Empresa::Empresa(
  std::string nome,
  std::string cnpj,
  vector <Cargo*> cargos,
  vector <Departamento*> departamentos
) {
  this->nome = nome;
  this->cnpj = cnpj;
  this->cargos = cargos;
  this->departamentos = departamentos;
}

std::string Empresa::getNome() {
  return this->nome;
};

std::string Empresa::getCnpj() {
  return this->cnpj;
};

vector <Cargo*> Empresa::getCargos() {
  return this->cargos;
};

vector <Departamento*> Empresa::getDepartamentos() {
  return this->departamentos;
};


void Empresa::setNome(std::string nome) {
  this->nome = nome;
}

void Empresa::setCnpj(std::string cnpj) {
  this->cnpj = cnpj;
}

void Empresa::setCargos(vector <Cargo*> cargos) {
  this->cargos = cargos;
}

void Empresa::setDepartamentos(vector <Departamento*> departamentos) {
  this->departamentos = departamentos;
}

