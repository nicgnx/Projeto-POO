#include <iostream>
#include <iostream>
#include <vector>
#include "../includes/Data.hpp"
#include "../includes/Fornecedor.hpp"
#include "../includes/MateriaPrima.hpp"
#include "../includes/OrdemDeMateriaPrima.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/Cliente.hpp"
#include "../includes/Veiculo.hpp"
#include "../includes/Orcamento.hpp"
#include "../includes/HistoricoDeLogs.hpp"
#include "../includes/Funcionario.hpp"
#include "../includes/Turno.hpp"
#include "../includes/Departamento.hpp"
#include "../includes/Cargo.hpp"
#include "../includes/Historico.hpp"
#include "../includes/Salario.hpp"
#include "../includes/Login.hpp"
#include "../includes/Permissao.hpp"
#include "../constants/PERMISSOES.hpp"
#include "../includes/Empresa.hpp"


int main() {
try {

// Instancia as permissoes do sistema (hardcoded mesmo), conforme a struct declarada em /constants

  Permissao* perm1 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO, "Permissao para cadastrar/editar funcionario");
  Permissao* perm2 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE, "Permissao para cadastrar/editar cliente");
  Permissao* perm3 = new Permissao(PERMISSOES::EDITAR_SALARIO, "Permissao para editar salario");
  Permissao* perm4 = new Permissao(PERMISSOES::DEMITIR_FUNCIONARIO, "Permissao para demitir funcionario");
  Permissao* perm5 = new Permissao(PERMISSOES::MANUSEAR_ESTOQUE, "Permissao para cadastrar/editar produto");
  Permissao* perm6 = new Permissao(PERMISSOES::EMITIR_ORDEM_PRODUCAO, "Permissao para emitir ordem de produção");
  Permissao* perm7 = new Permissao(PERMISSOES::COMPRAR_PRODUTO, "Permissao para comprar produto");
  Permissao* perm8 = new Permissao(PERMISSOES::EDITAR_PERMISSOES, "Permissao para editar permissoes de usuarios");
  Permissao* perm9 = new Permissao(PERMISSOES::EDITAR_EMPRESA, "Permissao para editar dados da empresa");
  Permissao* perm10 = new Permissao(PERMISSOES::LEITURA_ESTOQUE, "Permissao para ler dados do estoque");

// Cria as permissões do sistema
  
  std::vector<Permissao*> todasPermissoes = {perm1, perm2, perm3, perm4, perm5, perm6, perm7, perm8, perm9,perm10};
  std::vector<Permissao*> clientes = {perm6,perm7,perm10};
  std::vector<Permissao*> funcionarios = {perm1, perm2, perm3, perm5, perm6, perm7, perm8, perm9,perm10};
  
  
// intancia a classe Empresa.
  Empresa* empresa = Empresa::getInstancia();
  empresa->setNome("Empresa teste");
  empresa->setCnpj("29843608000160");

// Criação de usuário root
    
  Funcionario* root = empresa->getFuncionarios()[0];  
  root->setPermissoes(todasPermissoes);
  
// Login do usuário root 
  Login* login = Login::getInstance();
  login->logar(root);
  

// Cargos da empresa
std::vector<Cargo*> cargosEmpresa = {new Cargo("Manutenção"), new Cargo("Vendedor"), new Cargo("Recrutamento")};
empresa->setCargos(cargosEmpresa);
  

// Departamentos da empresa
std::vector<Departamento*> departamentosEmpresa = {
  new Departamento("TI"),
  new Departamento("Vendas"),
  new Departamento("RH"),
};
empresa->setDepartamentos(departamentosEmpresa);

  
// Turnos da empresa
  std::vector<Turno*> turnosEmpresa = {
  new Turno("Matutino", 8, 12,17,12, MANHA), new Turno("Vespertino Parcial", 12, 16,20,16, TARDE),
  new Turno("Vespertino Integral", 12, 20,20,20, TARDE), new Turno("Noturno", 17, 24,23,24, NOITE)};
  empresa->setTurnos(turnosEmpresa);

// Inicia o Estoque da Empresa
  empresa->setEstoque(Estoque::getInstancia());

// Instância rotas dos usuários

  std::pair<float,float>cordenada1(-19.87367813744857,-43.94025917116399);
  std::pair<float,float>cordenada2(-19.900444311286034,-44.004921865846);
  std::pair<float,float>cordenada3(-19.906635803883297,-43.96399403849584);
  std::pair<float,float>cordenada4(-19.838356773138216,-43.943269610056625);


// cadastrar 4 funcionarios
  
  empresa->cadastrarFuncionario(new Funcionario(
        "Funcionario 0", "26872026065", "0@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
        "202233665", Cargo("Vendedor"), Departamento("Vendas"),
        Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 0"),
        Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), new Turno("Matutino", 8, 12, 16, 20, MANHA), cordenada1));
  
  Funcionario* user0 = empresa->getFuncionarios()[1];

  Funcionario* user1 = new Funcionario(
    "Funcionario 1", "12525436601", "1@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Vendedor"), *empresa->getDepartamentoByName("Vendas"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 1"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Noturno"), cordenada2);
  Funcionario* user2 = new Funcionario(
    "Funcionario 2", "12525436602", "2@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Manutenção"), *empresa->getDepartamentoByName("TI"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 2"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Matutino"),cordenada3
  );
  Funcionario* user3 = new Funcionario(
    "Funcionario 3", "12525436603", "3@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
    "202233665", *empresa->getCargoByName("Recrutamento"), *empresa->getDepartamentoByName("RH"),
    Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 3"),
    Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), empresa->getTurnoByName("Matutino"), cordenada4
  );

  empresa->cadastrarFuncionario(user1);
  empresa->cadastrarFuncionario(user2);
  empresa->cadastrarFuncionario(user3);
  
  //Instancia Veiculo  
    
  Veiculo* veiculo = new Veiculo(4, empresa->getTurnoByName("Matutino"), empresa->getFuncionarios());
//exibindo Rotas do veiculo e horarios de embarque de cada funcionario
 veiculo->exibeRota();
 
  Estoque* estoque = empresa->getEstoque();
  estoque->cadastraMateriaPrima(10,"Madeira","Kg",10);



  estoque->cadastraMateriaPrima(20,"Prego","Kg",20);
  estoque->cadastraMateriaPrima(30,"Borracha","L",10);
  estoque->cadastraMateriaPrima(40,"Barra de Ferro","Kg",10);
  estoque->cadastraMateriaPrima(50,"Parafuso","U",20);
  estoque->cadastraMateriaPrima(60,"Plastico","Kg",10);
  std::cout << "-----------------------------------   Criação das materias primas   -----------------------------------\n\n\n";
  estoque->printListaDeMateriasPrimas();

  estoque->cadastraFornecedor(new Fornecedor ("Madeira&Madeira"));  
  estoque->cadastraFornecedor(new Fornecedor ("Casa do Marceneiro"));
  estoque->cadastraFornecedor(new Fornecedor ("Só Artesanal"));
  estoque->cadastraFornecedor(new Fornecedor ("Leroy Merlin"));

  vector<Fornecedor*> fornecedores = estoque->getFornecedores();

  
  fornecedores[0]->setMateriaPrima(10,10.25);
  fornecedores[0]->setMateriaPrima(20,9.25);
  fornecedores[1]->setMateriaPrima(20,9.85);
  fornecedores[1]->setMateriaPrima(30,11.85);
  fornecedores[2]->setMateriaPrima(30,5.85);
  fornecedores[2]->setMateriaPrima(40, 6.30);
  fornecedores[3]->setMateriaPrima(40, 8.30);
  fornecedores[3]->setMateriaPrima(50, 8.30);
  fornecedores[3]->setMateriaPrima(60, 8.30);
  std::cout << "-----------------------------------   Criação dos Fornecedores   -----------------------------------\n\n\n";
  estoque->printListaDeFornecedores();

  estoque->cadastraProduto("Mesa",10,30,new PrecoProduto(15,0,Data().dateNow()));
  estoque->cadastraProduto("Cadeira",15,10,new PrecoProduto(5,0,Data().dateNow()));
  estoque->cadastraProduto("Copo",50,100,new PrecoProduto(2,0,Data().dateNow()));

  estoque->getProduto(1001)->setMateriasPrimas(10,5);
  estoque->getProduto(1001)->setMateriasPrimas(20,15);
  estoque->getProduto(1002)->setMateriasPrimas(10,5);
  estoque->getProduto(1002)->setMateriasPrimas(50,15);  
  estoque->getProduto(1002)->setMateriasPrimas(40,3);
  estoque->getProduto(1002)->setMateriasPrimas(30,1);
  estoque->getProduto(1003)->setMateriasPrimas(60,2);

  std::cout << "-----------------------------------   Criação dos Produtos   -----------------------------------\n\n\n";

  estoque->printListaDeProdutos();

  std::cout << "-----------------------------------   Reabastecimento de Estoque   -----------------------------------\n\n\n";

  estoque->reabasteceEstoqueProduto(1001, 0, MINIMO);
  estoque->reabasteceEstoqueProduto(1002, 0, MINIMO);
  estoque->reabasteceEstoqueProduto(1003, 0, MINIMO);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();

  empresa->cadastrarCliente(new Cliente ("Carlos","carlos@empresa.com","Senha125","74536547898",PF,1258479635));
  Cliente* Carlos = empresa->getClientes()[0];
  Carlos->setPermissoes(clientes);

  std::map<int,int> listaDeCompras;
  listaDeCompras[1001] = 5;
  listaDeCompras[1002] = 20;
  listaDeCompras[1003] = 40;

  login->logar(Carlos);
  Orcamento* C_orcamento = Carlos->solicitaOrcamento(listaDeCompras);
  C_orcamento->printOrcamento();
  Carlos->compra(C_orcamento,Data().dateNow());
  //HistoricoDeLogs::getInstancia()->printLog();
  //HistoricoDeLogs::getInstancia()->printLogCompleto();

  
  } catch (char const* e) {
    std::cerr << e << '\n';
  HistoricoDeLogs::getInstancia()->printLog();
  } catch (ExecaoCustomizada e) {
    std::cerr << e.what() << '\n';
  HistoricoDeLogs::getInstancia()->printLog();
  }
    
}