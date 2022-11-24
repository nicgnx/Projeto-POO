#include <iostream>

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

  return 0;
}