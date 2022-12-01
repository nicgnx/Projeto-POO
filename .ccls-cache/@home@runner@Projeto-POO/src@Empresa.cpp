#include "../includes/Empresa.hpp"

Empresa* Empresa::empresa = NULL;

// Construtores e Destrutores

Empresa::Empresa() {
  Funcionario* root = new Funcionario("root");
  root->setNome("root");
  root->setcpfCnpj("000000");
  this->funcionarios.push_back(root);
}

Empresa::~Empresa() { empresa = NULL; }

Empresa::Empresa(
  std::string nome, std::string cnpj, std::vector<Funcionario*> funcionarios,
  std::vector<Cliente*> clientes, std::vector<Cargo*> cargos,
  std::vector<Departamento*> departamentos, Estoque* estoque,
  HistoricoDeLogs* historico, std::vector<Permissao*> permissoes,
  std::vector<Veiculo*> frotaVeiculos, std::vector<Turno*> turnos
) {

  this->nome = nome;
  this->cnpj = cnpj;
  this->clientes = clientes;
  this->funcionarios = funcionarios;
  this->cargos = cargos;
  this->departamentos = departamentos;
  this->estoque = estoque;
  this->historico = historico;
  this->permissoes = permissoes;
  this->frotaVeiculos = frotaVeiculos;
  this->turnos = turnos;
}

// getters
Empresa* Empresa::getInstancia() {
  if (empresa == NULL) {
    empresa = new Empresa();
  }
  return empresa;
}

std::string Empresa::getNome() { return this->nome; }

std::string Empresa::getCnpj() { return this->cnpj; }

std::vector<Funcionario*> Empresa::getFuncionarios() {
  return this->funcionarios;
}

std::vector<Cliente*> Empresa::getClientes() { return this->clientes; }

std::vector<Cargo*> Empresa::getCargos() { return this->cargos; }

std::vector<Departamento*> Empresa::getDepartamentos() {
  return this->departamentos;
}

Estoque* Empresa::getEstoque() { return this->estoque; }

HistoricoDeLogs* Empresa::getHistoricoDeLogs() { return this->historico; }

std::vector<Permissao*> Empresa::getPermissoes() { return this->permissoes; }

std::vector<Veiculo*> Empresa::getFrotaVeiculos() {
  return this->frotaVeiculos;
}

std::vector<Turno*> Empresa::getTurnos() { return this->turnos; }

// Setters
void Empresa::setNome(std::string nome) { this->nome = nome; }

void Empresa::setCnpj(std::string cnpj) { this->cnpj = cnpj; }

void Empresa::setFuncionarios(std::vector<Funcionario*> funcionarios) {
  this->funcionarios = funcionarios;
}

void Empresa::setClientes(std::vector<Cliente*> clientes) {
  this->clientes = clientes;
}

void Empresa::setCargos(std::vector<Cargo*> cargos) { this->cargos = cargos; }

void Empresa::setDepartamentos(std::vector<Departamento*> departamentos) {
  this->departamentos = departamentos;
}

void Empresa::setEstoque(Estoque* estoque) { this->estoque = estoque; }

void Empresa::setHistoricoDeLogs(HistoricoDeLogs* historico) {
  this->historico = historico;
}

void Empresa::setPermissoes(std::vector<Permissao*> permissoes) {
  this->permissoes = permissoes;
}

void Empresa::setFrotaVeiculos(vector<Veiculo*> frotaVeiculos) {
  this->frotaVeiculos = frotaVeiculos;
}

void Empresa::setTurnos(vector<Turno*> turnos) { this->turnos = turnos; }

// Métodos

void Empresa::cadastrarFuncionario(Funcionario* funcionario) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO,"CADASTRAR_EDITAR_FUNCIONARIO","Empresa","Empresa","cadastrarFuncionario");

  std::vector<Funcionario*> funcionarios = this->getFuncionarios();
  funcionarios.push_back(funcionario);
  this->setFuncionarios(funcionarios);
}

 void Empresa::cadastraVeiculo(Veiculo* veiculo){
   this->frotaVeiculos.push_back(veiculo);
 }

void Empresa::cadastrarCliente(Cliente* cliente) {
  Login::getInstance()->verificaPermissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE,"CADASTRAR_EDITAR_CLIENTE","Empresa","Empresa","cadastrarCliente");
  
  std::vector<Cliente*> clientes = this->getClientes();
  clientes.push_back(cliente);
  this->setClientes(clientes);
}

Cargo* Empresa::getCargoByName(std::string nomeCargo) {
  for (auto it : this->getCargos()) {
    if (it->getCargo() == nomeCargo) {
      return it;
    };
  }

  // se chegou aqui nao achou o cargo
  std::cout << "Cargo buscado não existe na empresa!" << std::endl;
  throw "Cargo buscado não existe na empresa!";
}

Departamento* Empresa::getDepartamentoByName(std::string nomeDepartamento) {
  for (auto it : this->getDepartamentos()) {
    if (it->getDepartamento() == nomeDepartamento) {
      return it;
    };
  }

  // se chegou aqui nao achou o departamento
  std::cout << "Departamento buscado não existe na empresa!" << std::endl;
  throw "Departamento buscado não existe na empresa!";
}

Turno* Empresa::getTurnoByName(std::string nomeTurno) {
  for (auto it : this->getTurnos()) {
    if (it->getNomeTurno() == nomeTurno) {
      return it;
    };
  }

  // se chegou aqui nao achou o turno
  std::cout << "Turno buscado não existe na empresa!" << std::endl;
  throw "Turno buscado não existe na empresa!";
}

void Empresa::demiteFuncionario(Funcionario* funcionario) {
  //primeira coisa é verificar permissao do usuario logado
  Login::getInstance()->verificaPermissao(PERMISSOES::DEMITIR_FUNCIONARIO,"DEMITIR_FUNCIONARIO","Empresa","Empresa","demiteFuncionario");

    // throw "Usuario logado nao possui permissao demitir funcionario!";
  

  // agora exclui ele da empresa
  std::vector<Funcionario*> funcionarios = this->getFuncionarios();
  bool found = false;
  for (int i = 0; i < funcionarios.size(); i++) {
    if (funcionarios[i] == funcionario) {
      for (int j = i; j < (funcionarios.size() - 1); j++) {
        funcionarios[j] = funcionarios[j + 1];
      }
      found = true;
      funcionarios.pop_back();
      empresa -> setFuncionarios(funcionarios);
      break;
    }
  }

  if (!found)
    cout << "\nFuncionario nao encontrado para demitir!";
  else
    cout << "\nFuncionario demitido com sucesso!";
  cout << endl;
}

/*void Empresa::Compra(Orcamento* orcamento, Data dataCompra,Cliente* cliente){
  if (!Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO)) {
    std::cout << "Usuario logado nao possui permissao comprar produto!"
              << std::endl;
    throw "Usuario logado nao possui permissao comprar produto!";
  }
  cliente->compra(orcamento,dataCompra);
}*/

/*Orcamento* Empresa::solicitaOrcamento(std::map<int, int> itensDesejados,Cliente* cliente){
  if (!Login::getInstance()->verificaPermissao(PERMISSOES::COMPRAR_PRODUTO)) {
    std::cout << "Usuario logado nao possui permissao COMPRAR_PRODUTO!"
              << std::endl;
    throw "Usuario logado nao possui permissao COMPRAR_PRODUTO!";
  }
  return cliente->solicitaOrcamento(itensDesejados);
}*/

void Empresa::reabasteceMateriaPrima(int idMateriaPrima, int quantidade, tipoReabastece valor,Funcionario* funcionario){
  //Login::getInstance()->verificaPermissao(PERMISSOES::EMITIR_ORDEM_PRODUCAO,"EMITIR_ORDEM_PRODUCAO");
  Estoque::getInstancia()->reabasteceEstoqueMP(idMateriaPrima,quantidade,valor); 
}

void Empresa::reabasteceProduto(int idProduto, int quantidade, tipoReabastece valor,Funcionario* funcionario){
  //Login::getInstance()->verificaPermissao(PERMISSOES::EMITIR_ORDEM_PRODUCAO,"EMITIR_ORDEM_PRODUCAO");
  Estoque::getInstancia()->reabasteceEstoqueProduto(idProduto,quantidade,valor);
}