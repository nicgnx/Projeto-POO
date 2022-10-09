#include "includes/Funcionario.hpp"
#include "includes/Cliente.hpp"
#include "includes/Estoque.hpp"
#include <iostream>

int localizaID(std::string nome){
  auto listaDeProdutos = Estoque::getInstancia()->getListaDeProdutos();
  bool go = true;
  for(auto it = listaDeProdutos.begin();go || it != listaDeProdutos.end();++it){
    if(listaDeProdutos[it->first]->getNome() == nome){
      go = false;
      return listaDeProdutos[it->first]->getIdProduto();
    }throw("Esse produto não existe");    
  }
}

int main() {

  /*Funcionario Alan("Alan", "125.254.366-98", "alan@testeemail.com", Data (1985, 8, 24, 0, 0, 0),
                   "Rua dos Bobos nº 0", "202233665", Cargo("Estagiario"), Departamento ("IT"), Historico (Data(2022,9,29,15,59,00),"Contratação do Alan"),Salario (1000.95,0,Data(2022,29,9,15,59,00), Gerencia));
  std::cout << " Funcionario: " << Alan.getNome() << "\n CPF: " << Alan.getcpfCnpj() << "\n e-mail: " << Alan.getEmail() << "\n Endereço: " << Alan.getEndereco() << "\n Matricula: " << Alan.getMatricula() << "\n Salario: " << Alan.getSalarioAtual() << "\n Cargo: " << Alan.getCargo().getCargo() << "\n Departamento: " << Alan.getDepartamento().getDepartamento() << "\n Historico: \n   - Data: ";
Alan.getHistorico().getData().printData();
std::cout << "   - Registro: " << Alan.getHistorico().getRegistro() << "\n Salario: " << Alan.getSalarioAtual() << "\n \n \n"; */

  Cliente agroBrasil("Agro Brasil","comercial@agrobrasil.com.br", "1236548", PJ, 551125487);
  Estoque* estoque = Estoque::getInstancia();
  estoque->cadastraProduto("Adubo Nutrien",100,35);
  estoque->reabasteceEstoque(localizaID("Adubo Nutrien"));
  estoque->printListaDeProdutos();
  estoque->printListaDeLotes(localizaID("Adubo Nutrien"));

  
  
}
