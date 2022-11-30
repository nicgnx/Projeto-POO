#include "../includes/Funcionario.hpp"

// Construtores e Destrutores
Funcionario::Funcionario(std::string cpfCnpj) {
  Login* login = Login::getInstance();
  if(login->getUsuario() == nullptr){
    HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
    historic->setLog(new LogCriacaoDelecao("system","0000000",Data().dateNow(),"Funcionario","root","000000",CRIACAO));
    this->cpfCnpj = cpfCnpj;
  }else{
    Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios"," ","Construtor Funcionario");
    HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
    historic->setLog(new LogCriacaoDelecao(nome,cpfCnpj,Data().dateNow(),"Funcionario","Vazio",cpfCnpj,CRIACAO));
    }
  }

Funcionario::Funcionario(std::string nome, std::string cpfCnpj, std::string email, std::string senha,
  Data dataNascimento, std::string endereco, std::string matricula, Cargo cargo,
  Departamento departamento, Historico historico, Salario salario, Turno* turno, std::pair<float,float> cordenada) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios"," ","Construtor Funcionario");
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
  Login* login = Login::getInstance();
  if(login->getUsuario() == nullptr){
    HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
    historic->setLog(new LogCriacaoDelecao("root","0000000",Data().dateNow(),"Funcionario",nome,cpfCnpj,CRIACAO));
  }else{
    HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
    historic->setLog(new LogCriacaoDelecao(nome,cpfCnpj,Data().dateNow(),"Funcionario",nome,cpfCnpj,CRIACAO));}
}

Funcionario::~Funcionario() {}

// Getters
Data Funcionario::getDataNascimento() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"dataNascimento"));
  return this->dataNascimento; 
}

std::string Funcionario::getEndereco() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"endereco"));
  return this->endereco;
}

std::string Funcionario::getMatricula() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"matricula"));
  return this->matricula;
}

Cargo Funcionario::getCargo() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"cargo"));
  return this->cargo;
}

Historico Funcionario::getHistorico() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"historico (uma instância)"));
  return this->historico.back();
}

vector<Historico> Funcionario::getHistoricoCompleto() {
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"historico"));
  return this->historico;
}

Departamento Funcionario::getDepartamento() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"departamento"));
  return this->departamento;
}

double Funcionario::getSalarioAtual() {
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"salario"));
  Salario salario = this->salario.back();
  return salario.getSalarioBase();
}

Turno* Funcionario::getTurno() { 
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"turno"));
  return this->turno; }



 std::pair<float,float> Funcionario::getCordenada(){
   Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"cordenada"));
   return this->cordenada;
 }

float Funcionario::getDistancia(){
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"distancia"));
  return this->distancia;
}

std::string Funcionario::getHorarioEmbarque(){
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Funcionario",this->cpfCnpj,"horarioEmbarque"));
  return this->horarioEmbarque;
}
// Setters
void Funcionario::setDataNascimento(Data dataNascimento) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setDataNascimento");
  this->dataNascimento = dataNascimento;
}

void Funcionario::setEndereco(std::string endereco) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setEndereco");
  this->endereco = endereco;
}

void Funcionario::setMatricula(std::string matricula) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setMatricula");
  this->matricula = matricula;
}

void Funcionario::setCargo(std::string cargo) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setCargo");
  this->cargo.setCargo(cargo); }

void Funcionario::addHistorico(Historico historico) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"addHistorico");
  this->historico.push_back(historico);
}

void Funcionario::setDepartamento(std::string departamento) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setDepartamento");
  this->departamento.setDepartamento(departamento);
}

void Funcionario::setNovoSalario(Salario salario) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setNovoSalario");
  this->salario.push_back(salario);
}

void Funcionario::setTurno(Turno* turno) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setTurno");
  this->turno = turno; }

void Funcionario::setDistancia(float distancia){
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setDistancia");
  this->distancia = distancia;
}

void Funcionario::setHorarioEmbarque(std::string horarioEmbarque){
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Funcionarios",this->cpfCnpj,"setHorarioEmbarque");
  this->horarioEmbarque = horarioEmbarque;
}