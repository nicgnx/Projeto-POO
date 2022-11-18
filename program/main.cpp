#include "../includes/Cliente.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/Funcionario.hpp"
#include "../includes/Permissao.hpp"
#include <iostream>

int localizaID(std::string nome) {
  Estoque* estoque = Estoque::getInstancia();
  auto listaDeProdutos = estoque->getListaDeProdutos();
  bool go = true;
  for (auto it = listaDeProdutos.begin(); go || it != listaDeProdutos.end();
       ++it) {
    if (listaDeProdutos[it->first]->getNome() == nome) {
      go = false;
      return listaDeProdutos[it->first]->getIdProduto();
    }
  }
  std::cout << "Esse produto não existe";
}

int main() {
  /*


    Funcionario Alan("Alan", "125.254.366-98",
  "alan@testeemail.com","senha123", Data (1985, 8, 24, 0, 0, 0), "Rua dos
  Bobos nº 0", "202233665", Cargo("Estagiario"), Departamento ("IT"),
  Historico (Data(2022,9,29,15,59,00),"Contratação do Alan"),Salario
  (1000.95,0,Data(2022,29,9,15,59,00), Gerencia));


    Funcionario Cesar("Cesar", "125.214.366-98",
  "cesar@testeemail.com","senha321", Data (1975, 8, 12, 0, 0, 0), "Rua
  conceicao nº 12", "202233665", Cargo("Tecnico"), Departamento
  ("Engenharia"), Historico (Data(2022,9,29,15,59,00),"Contratação do
  Cesar"),Salario (2000.95,0,Data(2022,29,9,15,59,00), Gerencia));



    std::cout << " Funcionario: " << Alan.getNome() << "\n CPF: " <<
  Alan.getcpfCnpj() << "\n e-mail: " << Alan.getEmail() << "\n Endereço: " <<
  Alan.getEndereco() << "\n Matricula: " << Alan.getMatricula() << "\n
  Salario: " << Alan.getSalarioAtual() << "\n Cargo: " <<
  Alan.getCargo().getCargo() << "\n Departamento: " <<
  Alan.getDepartamento().getDepartamento() << "\n Historico: \n   - Data: ";
  Alan.getHistorico().getData().printData();
  std::cout << "   - Registro: " << Alan.getHistorico().getRegistro() << "\n
  Salario: " << Alan.getSalarioAtual() << "\n \n \n";

    if(Alan.getSenha() == "senha123"){
      std::cout << "senha ok";
    }

    Permissao func_nivel1(1,"altera salario, adiciona historico");

    if(funcionario.getIdPermissao() == 1){
      Alan.setNovoSalario(Salario (2000.95,0,Data(2022,29,9,15,59,00));
    }
  */

  Cliente agroBrasil(
    "Agro Brasil", "comercial@agrobrasil.com.br", "senha", "1236548", PJ,
    551125487
  );
  Estoque* estoque = Estoque::getInstancia();

  // Cadastrar Produtos

  estoque->cadastraProduto(
    "Adubo Nutrien", 100, 35,
    new PrecoProduto(29.90, 0.0, Data(2022, 10, 8, 22, 0, 0))
  );
  estoque->cadastraProduto(
    "Adubo PhosAgro", 100, 325,
    new PrecoProduto(59.90, 0.0, Data(2022, 10, 8, 22, 0, 0))
  );
  estoque->cadastraProduto(
    "Adubo Yara Brasil", 50, 100,
    new PrecoProduto(39.90, 0.0, Data(2022, 10, 8, 22, 0, 0))
  );
  estoque->cadastraProduto(
    "Adubo Mosaic", 75, 80,
    new PrecoProduto(89.90, 0.0, Data(2022, 10, 8, 22, 0, 0))
  );
  estoque->cadastraProduto(
    "Adubo Heringer", 30, 470,
    new PrecoProduto(49.90, 0.0, Data(2022, 10, 8, 22, 0, 0))
  );

  // Reabastece estoque

  estoque->reabasteceEstoque(localizaID("Adubo Nutrien"));
  estoque->reabasteceEstoque(localizaID("Adubo Yara Brasil"));
  estoque->reabasteceEstoque(localizaID("Adubo PhosAgro"));
  estoque->reabasteceEstoque(localizaID("Adubo Mosaic"));
  estoque->reabasteceEstoque(localizaID("Adubo Heringer"));
  std::cout << "\n\n\n";
  estoque->printListaDeProdutos();
  std::cout << "\n\n\n";

  // Compra produtos

  agroBrasil.compra(
    localizaID("Adubo Nutrien"), 61, Data(2022, 10, 8, 22, 0, 0)
  );
  agroBrasil.compra(
    localizaID("Adubo Yara Brasil"), 83, Data(2022, 10, 8, 22, 0, 0)
  );
  agroBrasil.compra(
    localizaID("Adubo PhosAgro"), 27, Data(2022, 10, 8, 22, 0, 0)
  );
  agroBrasil.compra(
    localizaID("Adubo Mosaic"), 69, Data(2022, 10, 8, 22, 0, 0)
  );
  agroBrasil.compra(
    localizaID("Adubo Mosaic"), 130, Data(2022, 10, 8, 22, 0, 0)
  );
  agroBrasil.compra(
    localizaID("Adubo Heringer"), 54, Data(2022, 10, 8, 22, 0, 0)
  );
  std::cout << "\n\n\n";
  estoque->printListaDeProdutos();
  std::cout << "\n\n\n";
}