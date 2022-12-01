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
  
  
// Item 1 - intancia a classe Empresa.
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


// Item 2 - Usuário logado com acesso a todas as permissões exceto excluir funcionários
  
  empresa->cadastrarFuncionario(new Funcionario(
        "Funcionario 0", "26872026065", "0@testeemail.com", "senha123", Data(1985, 8, 24, 0, 0, 0), "Rua dos Bobos nº 0",
        "202233665", Cargo("Vendedor"), Departamento("Vendas"),
        Historico(Data(2022, 9, 29, 15, 59, 00), "Contratação do 0"),
        Salario(1000.95, 0, Data(2022, 29, 9, 15, 59, 00), Gerencia), new Turno("Matutino", 8, 12, 16, 20, MANHA), cordenada1));
  
  Funcionario* user0 = empresa->getFuncionarios()[1];
  user0->setPermissoes(funcionarios);

// Item 3 - Comprovamento do Singletom de Login
  
  login->logar(user0);
  

// Item 4 - Cadastrar três funcionarios
  
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

  user1->setPermissoes(funcionarios);
  user2->setPermissoes(funcionarios);
  user3->setPermissoes(funcionarios);

// Item 5 - Cadastrar Clientes

  empresa->cadastrarCliente(new Cliente ("Carlos","carlos@empresa.com","Senha125","74536547898",PF,1258479635));
  Cliente* Carlos = empresa->getClientes()[0];
  Carlos->setPermissoes(clientes);

  empresa->cadastrarCliente(new Cliente ("Casas Pernambuco","cliente@casaspernambuco.com","Senha135","12547885",PJ,1258479635));
  Cliente* casasPernambuco = empresa->getClientes()[1];
  casasPernambuco->setPermissoes(clientes);


// Item 6 - Cadastro do produto Mesa e das materias primas Madeira, Plático, Alumínio, Parafusos
  
  Estoque* estoque = empresa->getEstoque();
  estoque->cadastraMateriaPrima(10,"Madeira","g",1000);
  estoque->cadastraMateriaPrima(20,"Plástico","g",1000);
  estoque->cadastraMateriaPrima(30,"Aluminío","g",1000);
  estoque->cadastraMateriaPrima(40,"Parafusos","unidade",20);

  std::cout << "\n\n\n-----------------------------------   Criação das materias primas   -----------------------------------\n\n\n";
  estoque->printListaDeMateriasPrimas();

 

// Cadastra Fornecedores

  estoque->cadastraFornecedor(new Fornecedor ("Madeira&Madeira"));  
  estoque->cadastraFornecedor(new Fornecedor ("Casa do Marceneiro"));
  vector<Fornecedor*> fornecedores = estoque->getFornecedores();

  
  fornecedores[0]->setMateriaPrima(10,10.25);
  fornecedores[0]->setMateriaPrima(20,11.25);
  fornecedores[0]->setMateriaPrima(30,8.85);
  fornecedores[0]->setMateriaPrima(40,12.85);
  fornecedores[1]->setMateriaPrima(10,13.85);
  fornecedores[1]->setMateriaPrima(20, 6.30);
  fornecedores[1]->setMateriaPrima(30, 9.30);
  fornecedores[1]->setMateriaPrima(40, 25.30);

  std::cout << "\n\n\n-----------------------------------   Criação dos Fornecedores   -----------------------------------\n\n\n";
  estoque->printListaDeFornecedores();

  // Cadastra Produto
  estoque->cadastraProduto("Mesa",20,20,new PrecoProduto(50,0,Data().dateNow()));

  estoque->getProduto(1001)->setMateriasPrimas(10,450);
  estoque->getProduto(1001)->setMateriasPrimas(20,150);
  estoque->getProduto(1001)->setMateriasPrimas(30,100);
  estoque->getProduto(1001)->setMateriasPrimas(40,8);  

  std::cout << "\n\n\n-----------------------------------   Criação dos Produtos   -----------------------------------\n\n\n";

  estoque->printListaDeProdutos();

  std::cout << "\n\n\n-----------------------------------   Reabastecimento de Estoque   -----------------------------------\n\n\n";

// Item 7 - reabastece estoque minímo do produto

  estoque->reabasteceEstoqueProduto(1001, 0, MINIMO);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();

// Item 8 - Tenta excluir um funcionário cadastrado no sistema
std::cout << "\n\n\n -----------------------------------   Tentativa de Exclusão do Funcionario   -----------------------------------\n\n\n";
  empresa->demiteFuncionario(user2);
  
  } catch (char const* e) {
    std::cerr << e << "\n\n\n";

  } catch (ExecaoCustomizada e) {
    std::cerr << e.what() << "\n\n\n";
  
    Empresa* empresa = Empresa::getInstancia();
    Estoque* estoque = Estoque::getInstancia();
    Login* login = Login::getInstance();
    Cliente* casasPernambuco = empresa->getClientes()[1];
  
    // Retira 15 mesas para poder atender aos requerimentos do Item 9
    
    estoque->setEstoque(1001,5,1);
  
    // Lista de compras do cliente casasPernambuco
    std::map<int,int> listaDeCompras;
    listaDeCompras[1001] = 10;
  
    login->logar(casasPernambuco);

    // Item 9 - O cliente PJ solicita 10 mesas e paga 5% a mais por falta do produto e de materias primas para fabrica-lo
    
    Orcamento* C_orcamento = casasPernambuco->solicitaOrcamento(listaDeCompras);
    std::cout << "\n\n\n-----------------------------------   Solicitação de Orçamaento pelo Cliente PJ   -----------------------------------\n\n\n";
    C_orcamento->printOrcamento();

      std::cout << "\n\n\n-----------------------------------   Compra do Produto   -----------------------------------\n\n\n";
    casasPernambuco->compra(C_orcamento,Data().dateNow());

    login->logar(empresa->getFuncionarios()[1]);

    std::cout << "\n\n\n -----------------------------------   Ordem de Embarque dos Funcionários   -----------------------------------\n\n\n";
     
    // Item 10 - Instancia veiculos, calcula a rota e exibe a ordem de embarque dos passageiros
    
    Veiculo* veiculo1 = new Veiculo(4, empresa->getTurnoByName("Noturno"), empresa->getFuncionarios());
    Veiculo* veiculo2 = new Veiculo(4, empresa->getTurnoByName("Matutino"), empresa->getFuncionarios());
    empresa->cadastraVeiculo(veiculo1);
    empresa->cadastraVeiculo(veiculo2);
    // Exibindo Rotas do veiculo e horarios de embarque de cada funcionario  
    empresa->getFrotaVeiculos()[0]->exibeRota();
  std::cout << "\n\n\n -----------------------------------   Ordem de Embarque dos Funcionários   -----------------------------------\n\n\n";
    empresa->getFrotaVeiculos()[1]->exibeRota();
    
    // Item 11 - Exibe os Logs das operações



  std::cout << "\n\n\n-----------------------------------   Histórico de Logs   -----------------------------------\n\n\n";

    // Logs de Criação, Deleção, Login e Logout.
    HistoricoDeLogs::getInstancia()->printLog(); 

    /* Logs Completos

     Comentamos essa linha pois o sistema está gerando muito log.
  
     HistoricoDeLogs::getInstancia()->printLogCompleto(); */
  }
    
}