#include "../includes/Funcionario.hpp"

// Construtores e Destrutores
Funcionario::Funcionario() {}

Funcionario::Funcionario(
  std::string nome, std::string cpfCnpj, std::string email, std::string senha,
  Data dataNascimento, std::string endereco, std::string matricula, Cargo cargo,
  Departamento departamento, Historico historico, Salario salario, Turno* turno, std::pair<float,float> cordenada
) {
  this->nome = nome;
  this->cpfCnpj = cpfCnpj;
  this->email = email;
  this->senha = senha;
  this->dataNascimento = dataNascimento;
  this->endereco = endereco;
  this->matricula = matricula;
  this->cargo = cargo;
  this->departamento = departamento;
  this->historico.push_back(historico);
  this->salario.push_back(salario);
  this->turno = turno;
  this->cordenada = cordenada;
  Login* usuario = Login::getInstance();
  HistoricoDeLogs* historico = HistoricoDeLogs::getInstancia();
  historico->setLog(new LogCriacaoDelecao(usuario->getUsuario()->getNome(),usuario->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",nome,cpfCnpj,CRIACAO));

}

Funcionario::~Funcionario() {}

// Getters
Data Funcionario::getDataNascimento() { return this->dataNascimento; }

std::string Funcionario::getEndereco() { return this->endereco; }

std::string Funcionario::getMatricula() { return this->matricula; }

Cargo Funcionario::getCargo() { return this->cargo; }

Historico Funcionario::getHistorico() { return this->historico.back(); }

vector<Historico> Funcionario::getHistoricoCompleto() {
  return this->historico;
}
Departamento Funcionario::getDepartamento() { return this->departamento; }

double Funcionario::getSalarioAtual() {
  Salario salario = this->salario.back();
  return salario.getSalarioBase();
}

Turno* Funcionario::getTurno() { return this->turno; }



 std::pair<float,float> Funcionario::getCordenada(){
   return this->cordenada;
 }

float Funcionario::getDistancia(){
  return this->distancia;
}

std::string Funcionario::getHorarioEmbarque(){
  return this->horarioEmbarque;
}
// Setters
void Funcionario::setDataNascimento(Data dataNascimento) {
  this->dataNascimento = dataNascimento;
}

void Funcionario::setEndereco(std::string endereco) {
  this->endereco = endereco;
}

void Funcionario::setMatricula(std::string matricula) {
  this->matricula = matricula;
}

void Funcionario::setCargo(std::string cargo) { this->cargo.setCargo(cargo); }

void Funcionario::addHistorico(Historico historico) {
  this->historico.push_back(historico);
}

void Funcionario::setDepartamento(std::string departamento) {
  this->departamento.setDepartamento(departamento);
}

void Funcionario::setNovoSalario(Salario salario) {
  this->salario.push_back(salario);
}

void Funcionario::setTurno(Turno* turno) { this->turno = turno; }

void Funcionario::setDistancia(float distancia){
  this->distancia = distancia;
}

void Funcionario::setHorarioEmbarque(std::string horarioEmbarque){
  this->horarioEmbarque = horarioEmbarque;
}