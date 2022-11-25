#include <iostream>
#include <iostream>
#include <vector>
#include "../includes/Data.hpp"
#include "../includes/Fornecedor.hpp"
#include "../includes/MateriaPrima.hpp"
#include "../includes/OrdemDeMateriaPrima.hpp"
#include "../includes/Estoque.hpp"

int main() {
  Estoque* estoque = Estoque::getInstancia();
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

  estoque->retiraLotes(1001,10);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();
  estoque->retiraLotes(1002,10);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();
  estoque->retiraLotes(1003,10);
  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();
  estoque->reabasteceEstoqueProduto(1001, 0, Estoque::MINIMO);
  estoque->reabasteceEstoqueProduto(1002, 0, Estoque::MINIMO);
  estoque->reabasteceEstoqueProduto(1003, 0, Estoque::MINIMO);

  estoque->printListaDeProdutos();
  estoque->printListaDeMateriasPrimas();
}
/*
#include "../includes/Funcionario.hpp"
#include "../includes/Cliente.hpp"
#include "../includes/Usuario.hpp"
#include "../includes/Permissao.hpp"
#include "../includes/Login.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/PrecoProduto.hpp"
#include "../includes/Turno.hpp"

#include "../constants/PERMISSOES.hpp"

// instancia as permissoes do sistema (hardcoded mesmo), conforme a struct declarada em /constants
Permissao* perm1 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_FUNCIONARIO, "Permissao para cadastrar/editar funcionario");
Permissao* perm2 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE, "Permissao para cadastrar/editar cliente");
Permissao* perm3 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_CLIENTE, "Permissao para editar salario");
Permissao* perm4 = new Permissao(PERMISSOES::DEMITIR_FUNCIONARIO, "Permissao para demitir funcionario");
Permissao* perm5 = new Permissao(PERMISSOES::CADASTRAR_EDITAR_PRODUTO, "Permissao para cadastrar/editar produto");
Permissao* perm6 = new Permissao(PERMISSOES::EMITIR_ORDEM_PRODUCAO, "Permissao para emitir ordem de produção");
Permissao* perm7 = new Permissao(PERMISSOES::COMPRAR_PRODUTO, "Permissao para comprar produto");
Permissao* perm8 = new Permissao(PERMISSOES::EDITAR_PERMISSOES, "Permissao para editar permissoes de usuarios");
Permissao* perm9 = new Permissao(PERMISSOES::EDITAR_EMPRESA, "Permissao para editar dados da empresa");
Permissao* perm10 = new Permissao(PERMISSOES::MANUSEAR_ESTOQUE, "Permissao para manusear o estoque");

int main() {
  std::cout << "Welcome! - Permissons Test" << std::endl;

  Usuario* user0 = new Funcionario(
    "Alan", 
    "125.254.366-98",
    "alan@testeemail.com",
    "senha123", 
    Data (1985, 8, 24, 0, 0, 0), 
    "Rua dos Bobos nº 0", 
    "202233665", 
    Cargo("Estagiario"), 
    Departamento ("IT"),
    Historico(Data(2022,9,29,15,59,00),"Contratação do Alan"),
    Salario(1000.95,0, Data(2022,29,9,15,59,00), Gerencia),
    new Turno("Turno teste", 10, 20, MANHA)
  );
  std::vector<Permissao*> user0Permissions = { perm1, perm2, perm5 };
  user0->setPermissoes(user0Permissions);

  Usuario* user1 = new Cliente(
    "Pedro Cliente", 
    "125.254.366-98",
    "pedrocliente@testeemail.com",
    "senha123", 
    PF,
    9999999
  );
  std::vector<Permissao*> user1Permissions = { perm7 };
  user1->setPermissoes(user1Permissions);

  // loga o funcionario
  Login* login = Login::getInstance();
  login->logar(user0);

  Estoque* estoque = Estoque::getInstancia();

  try {
    // cadastrar produto -> funcionario tem permissao
    estoque->cadastraProduto(
      "Produto X",
      20,
      10,
      new PrecoProduto(520.12, 0, Data().dateNow() )
    );
    std::cout << "Produto cadastrado com sucesso pelo funcionario" << std::endl;
  } catch(char const* e) {
    std::cerr << e << '\n';
  }

  // loga o cliente
  login -> deslogar();
  login -> logar(user1);

  try {
     // cadastrar produto -> cliente nao tem permissao
    Estoque* estoque = Estoque::getInstancia();
    estoque->cadastraProduto(
      "Produto Y",
      40,
      15,
      new PrecoProduto(700, 0, Data().dateNow() )
    );
    std::cout << "Produto cadastrado com sucesso pelo cliente" << std::endl;
  } catch(char const* e) {
    std::cerr << e << '\n';
  }

  // mostra os logs todos da aplicação

  return 0;

  
}*/