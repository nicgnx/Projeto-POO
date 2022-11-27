#include "../includes/Cliente.hpp"
#include "../includes/Data.hpp"
#include "../includes/Empresa.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/Fornecedor.hpp"
#include "../includes/Login.hpp"
#include "../includes/MateriaPrima.hpp"
#include "../includes/Orcamento.hpp"
#include "../includes/OrdemDeMateriaPrima.hpp"
#include "../includes/Turno.hpp"

#include "../constants/PERMISSOES.hpp"
#include <iostream>
#include <vector>

// instancia as permissoes do sistema (hardcoded mesmo), conforme a struct
// declarada em /constants
Permissao* perm1 =
  new Permissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO, "Permissao para cadastrar/editar funcionario");
Permissao* perm2 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE, "Permissao para cadastrar/editar cliente");
Permissao* perm3 = new Permissao(PERMISSOES::EDITAR_SALARIO, "Permissao para editar salario");
Permissao* perm4 = new Permissao(PERMISSOES::DEMITIR_FUNCIONARIO, "Permissao para demitir funcionario");
Permissao* perm5 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_PRODUTO, "Permissao para cadastrar/editar produto");
Permissao* perm6 = new Permissao(PERMISSOES::EMITIR_ORDEM_PRODUCAO, "Permissao para emitir ordem de produção");
Permissao* perm7 = new Permissao(PERMISSOES::COMPRAR_PRODUTO, "Permissao para comprar produto");
Permissao* perm8 = new Permissao(PERMISSOES::EDITAR_PERMISSOES, "Permissao para editar permissoes de usuarios");
Permissao* perm9 = new Permissao(PERMISSOES::EDITAR_EMPRESA, "Permissao para editar dados da empresa");
Permissao* perm10 = new Permissao(PERMISSOES::MANUSEAR_ESTOQUE, "Permissao para manusear o estoque");

int main() {
  // instancia a empresa do sistema, com as caracteristicas
  Empresa* empresa = Empresa::getInstancia();
  empresa->setNome("Empresa teste");
  empresa->setCnpj("29843608000160");

  // cargos da empresa
  std::vector<Cargo*> cargosEmpresa = {new Cargo("Manutenção"), new Cargo("Vendedor"), new Cargo("Recrutamento")};
  empresa->setCargos(cargosEmpresa);

  // turnos da empresa
  std::vector<Turno*> turnosEmpresa = {
    new Turno("Matutino", 8, 12, MANHA), new Turno("Vespertino Parcial", 12, 16, TARDE),
    new Turno("Vespertino Integral", 12, 20, TARDE), new Turno("Noturno", 18, 24, NOITE)};
  empresa->setTurnos(turnosEmpresa);

  // departamentos da empresa
  std::vector<Departamento*> departamentosEmpresa = {
    new Departamento("TI"),
    new Departamento("Vendas"),
    new Departamento("RH"),
  };
  empresa->setDepartamentos(departamentosEmpresa);

  empresa->setEstoque(Estoque::getInstancia());

  std::vector<Permissao*> todasPermissoes = {perm1, perm2, perm3, perm4, perm5, perm6, perm7, perm8, perm9, perm10};
  empresa->setPermissoes(todasPermissoes);

  // uma vez criada a empresa, cria usuario com todas permissoes, exceto demitir
  // funcionario
  Funcionario* user0 = new Funcionario(
    "Funcionario 0", "12525436600", "0@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Vendedor"), *empresa->getDepartamentoByName("Vendas"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 0"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Vespertino Parcial")
  );
  std::vector<Permissao*> user0Permissions = {perm1, perm2, perm3, perm5, perm6, perm7, perm8, perm9, perm10};
  user0->setPermissoes(user0Permissions);
  empresa->cadastrarFuncionario(user0);

  // loga esse usuario
  Login* login = Login::getInstance();
  login->logar(user0);


  // cadastrar 3 funcionarios
  Funcionario* user1 = new Funcionario(
    "Funcionario 1", "12525436601", "1@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Vendedor"), *empresa->getDepartamentoByName("Vendas"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 1"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Matutino")
  );
  Funcionario* user2 = new Funcionario(
    "Funcionario 2", "12525436602", "2@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Manutenção"), *empresa->getDepartamentoByName("TI"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 2"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Noturno")
  );
  Funcionario* user3 = new Funcionario(
    "Funcionario 3", "12525436603", "3@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Recrutamento"), *empresa->getDepartamentoByName("RH"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 3"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Vespertino Integral")
  );

  // comprova funcionamento do singleton de Login
  login->logar(user1);

  // todos tem permissoes de funcionario comum
  std::vector<Permissao*> permissoesFuncionarioComum = {perm2, perm5, perm6, perm10};
  user1->setPermissoes(permissoesFuncionarioComum);
  user2->setPermissoes(permissoesFuncionarioComum);
  user3->setPermissoes(permissoesFuncionarioComum);

  empresa->cadastrarFuncionario(user1);
  empresa->cadastrarFuncionario(user2);
  empresa->cadastrarFuncionario(user3);

  // cadastrar 2 clientes: PF e PJ
  Cliente* cliente0 = new Cliente("Cliente 0", "12525436604", "cliente0@testeemail.com", "senha123", PF, 9999999);
  Cliente* cliente1 = new Cliente("Cliente 1", "12525436605", "cliente10@testeemail.com", "senha123", PJ, 9999999);
  std::vector<Permissao*> permissoesClienteComum = {perm7};
  cliente0->setPermissoes(permissoesClienteComum);
  cliente1->setPermissoes(permissoesClienteComum);

  empresa->cadastrarCliente(cliente0);
  empresa->cadastrarCliente(cliente1);

  // tenta excluir (demitir) um funcionario -> nao possui permissao!
  empresa->demiteFuncionario(user1);

  // cadastra produto Mesa
  // antes de cadastrar o produto, tem que cadastrar matérias primas e fornecedores
  Estoque* estoque = empresa->getEstoque();

  estoque->cadastraMateriaPrima(10, "Madeira", "Kg", 10);
  estoque->cadastraMateriaPrima(20, "Prego", "Kg", 20);
  estoque->cadastraMateriaPrima(30, "Borracha", "L", 10);
  estoque->cadastraMateriaPrima(40, "Barra de Ferro", "Kg", 10);
  estoque->cadastraMateriaPrima(50, "Parafuso", "U", 20);
  estoque->cadastraMateriaPrima(60, "Plastico", "Kg", 10);

  std::cout << "-----------------------------------   Criação das materias "
               "primas   -----------------------------------\n\n\n";
  estoque->printListaDeMateriasPrimas();

  estoque->cadastraFornecedor(new Fornecedor("Madeira&Madeira"));
  estoque->cadastraFornecedor(new Fornecedor("Casa do Marceneiro"));
  estoque->cadastraFornecedor(new Fornecedor("Só Artesanal"));
  estoque->cadastraFornecedor(new Fornecedor("Leroy Merlin"));

  vector<Fornecedor*> fornecedores = estoque->getFornecedores();

  fornecedores[0]->setMateriaPrima(10, 10.25);
  fornecedores[0]->setMateriaPrima(20, 9.25);
  fornecedores[1]->setMateriaPrima(20, 9.85);
  fornecedores[1]->setMateriaPrima(30, 11.85);
  fornecedores[2]->setMateriaPrima(30, 5.85);
  fornecedores[2]->setMateriaPrima(40, 6.30);
  fornecedores[3]->setMateriaPrima(40, 8.30);
  fornecedores[3]->setMateriaPrima(50, 8.30);
  fornecedores[3]->setMateriaPrima(60, 8.30);

  std::cout << "-----------------------------------   Criação dos Fornecedores "
               "  -----------------------------------\n\n\n";
  estoque->printListaDeFornecedores();

  estoque->cadastraProduto("Mesa", 10, 30, new PrecoProduto(15, 0, Data().dateNow()));
  estoque->cadastraProduto("Cadeira", 15, 10, new PrecoProduto(5, 0, Data().dateNow()));
  estoque->cadastraProduto("Copo", 50, 100, new PrecoProduto(2, 0, Data().dateNow()));

  estoque->getProduto(1001)->setMateriasPrimas(10, 5);
  estoque->getProduto(1001)->setMateriasPrimas(20, 15);
  estoque->getProduto(1002)->setMateriasPrimas(10, 5);
  estoque->getProduto(1002)->setMateriasPrimas(50, 15);
  estoque->getProduto(1002)->setMateriasPrimas(40, 3);
  estoque->getProduto(1002)->setMateriasPrimas(30, 1);
  estoque->getProduto(1003)->setMateriasPrimas(60, 2);

  std::cout << "-----------------------------------   Criação dos Produtos   "
               "-----------------------------------\n\n\n";

  estoque->printListaDeProdutos();

  std::cout << "-----------------------------------   Reabastecimento de "
               "Estoque   -----------------------------------\n\n\n";

  estoque->reabasteceEstoqueProduto(1001, 0, Estoque::MINIMO);
  estoque->reabasteceEstoqueProduto(1002, 0, Estoque::MINIMO);
  estoque->reabasteceEstoqueProduto(1003, 0, Estoque::MINIMO);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();

  std::map<int, int> listaDeCompras;
  listaDeCompras[1001] = 5;
  listaDeCompras[1002] = 20;
  listaDeCompras[1003] = 40;

  // loga com o cliente0
  login->deslogar();
  login->logar(cliente0);

  Orcamento* C_orcamento = cliente0->solicitaOrcamento(listaDeCompras);
  C_orcamento->printOrcamento();
  cliente0->compra(C_orcamento, Data().dateNow());

  return 0;
}