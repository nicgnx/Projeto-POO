#include "../includes/Empresa.hpp"

Empresa* Empresa::empresa = NULL;

Empresa::Empresa(
  std::string nome,
  std::string cnpj,
  std::vector <Cargo*> cargos,
  std::vector <Departamento*> departamentos,
  Estoque* estoque,
  HistoricoDeLogs* historico,
  std::vector <Permissao*> permissoes 
) {
  this->nome = nome;
  this->cnpj = cnpj;
  this->cargos = cargos;
  this->departamentos = departamentos;
  this->estoque = estoque;
  this->historico = historico;
  this->permissoes = permissoes;
}

// getters
Estoque* Estoque::getInstancia(){
  if(estoque == NULL){
  estoque = new Estoque();
  } return estoque;
}

std::string Empresa::getNome() {
  return this->nome;
};

std::string Empresa::getCnpj() {
  return this->cnpj;
};

std::vector <Cargo*> Empresa::getCargos() {
  return this->cargos;
};

std::vector <Departamento*> Empresa::getDepartamentos() {
  return this->departamentos;
};


void Empresa::setNome(std::string nome) {
  this->nome = nome;
}

void Empresa::setCnpj(std::string cnpj) {
  this->cnpj = cnpj;
}

void Empresa::setCargos(std::vector <Cargo*> cargos) {
  this->cargos = cargos;
}

void Empresa::setDepartamentos(std::vector <Departamento*> departamentos) {
  this->departamentos = departamentos;
}

