#include "../includes/Login.hpp"
#include "../includes/Cliente.hpp"
#include "../includes/Funcionario.hpp"
#include "../third_party/doctest.h"

#include "../includes/LogLeitura.hpp"
#include "../includes/LogExcecao.hpp"

TEST_CASE("Construtor") {
    Cliente agroBrasil("Agro Brasil","comercial@agrobrasil.com.br", "1236548", "123.456.78-456", PJ, 551125487);
    Cliente comunicaBrasil("Comunica Brasil","comercial@comunicabrasil.com.br", "83974141", "856.478.566-55", PJ, 112548557);
    Login::logar(&agroBrasil);
    // Se um usuario estiver logado, qualquer tentativa de login ira retornar o endereço da instancia daquele usuario
    Login::logar(&comunicaBrasil);
    CHECK_EQ(Login::getUsuarioNome(), "Agro Brasil");
    Login::deslogar();
    CHECK_EQ(Login::getInstance(), nullptr);
    Login::logar(&comunicaBrasil);
    CHECK_EQ(Login::getUsuarioNome(), "Comunica Brasil");
  
    
}

TEST_CASE("Construtor2"){

  
  Funcionario Alan("Alan", "125.254.366-98", "alan@testeemail.com","senha123", Data (1985, 8, 24, 0, 0, 0),
                   "Rua dos Bobos nº 0", "202233665", Cargo("Estagiario"), Departamento ("IT"), Historico (Data(2022,9,29,15,59,00),"Contratação do Alan"),Salario (1000.95,0,Data(2022,29,9,15,59,00), Gerencia));
  

  
  std::cout << " Funcionario: " << Alan.getNome() << "\n CPF: " << Alan.getcpfCnpj() << "\n e-mail: " << Alan.getEmail() << "\n Endereço: " << Alan.getEndereco() << "\n Matricula: " << Alan.getMatricula() << "\n Salario: " << Alan.getSalarioAtual() << "\n Cargo: " << Alan.getCargo().getCargo() << "\n Departamento: " << Alan.getDepartamento().getDepartamento() << "\n Historico: \n   - Data: ";
Alan.getHistorico().getData().printData();
std::cout << "   - Registro: " << Alan.getHistorico().getRegistro() << "\n Salario: " << Alan.getSalarioAtual() << "\n \n \n"; 

  if(Alan.getSenha() == "senha123"){
    std::cout << "senha ok";
  }

  
TEST_CASE("login"){

  LogAbstrata* log =  new LogLeitura("cesar", 1, Data (1985, 8, 24, 0, 0, 0), "Venda", "executaVenda", "executou a venda para o cliente");
  LogAbstrata* log2 =  new LogExcecao("fulano", 2,Data (1985, 8, 24, 0, 0, 0), "Estoque", "VerificaEstoque nao permitido", "Verifica estoque");
  log.printLog();
  log2.printLog();
  }
  
}