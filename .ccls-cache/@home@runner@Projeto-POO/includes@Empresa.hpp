#ifndef EMPRESA_H
#define EMPRESA_H

#include "../includes/Funcionario.hpp"
#include "../includes/Cliente.hpp"
#include "../includes/Cargo.hpp"
#include "../includes/Departamento.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/HistoricoDeLogs.hpp"
#include "../includes/Permissao.hpp"
#include "Veiculo.hpp"
#include "Turno.hpp"
#include <string>
#include <vector>

class Empresa {
private:
  static Empresa* empresa;
  Empresa(
    std::string nome,
    std::string cnpj,
    std::vector <Funcionario*> funcionarios,
    std::vector <Cliente*> clientes,
    std::vector <Cargo*> cargos,
    std::vector <Departamento*> departamentos,
    Estoque* estoque,
    HistoricoDeLogs* historico,
    std::vector <Permissao*> permissoes,    
    std::vector <Veiculo*> frotaVeiculos,
    std::vector <Turno*> turnos
  );
  Empresa();
  ~Empresa();

// Atributes
  std::string nome;
  std::string cnpj;
  std::vector <Funcionario*> funcionarios;
  std::vector <Cliente*> clientes;
  std::vector <Cargo*> cargos;
  std::vector <Departamento*> departamentos;
  Estoque* estoque;
  HistoricoDeLogs* historico;
  std::vector <Permissao*> permissoes; 
  std::vector <Veiculo*> frotaVeiculos;
  std::vector <Turno*> turnos;


public:

  // Operators 
   Empresa(const Empresa&);
   Empresa& Empresa=(const Empresa&);

  // Getters
  Empresa* getInstancia();
  std::string getNome();
  std::string getCnpj();
  std::vector <Funcionario*> getFuncionarios();
  std::vector <Cliente*> getClientes();
  std::vector <Cargo*> getCargos();
  std::vector <Departamento*> getDepartamentos();
  Estoque* getEstoque();
  HistoricoDeLogs* getHistoricoDeLogs();
  std::vector <Permissao*> getPermissoes();
  std::vector <Veiculo*> getFrotaVeiculos();
  std::vector <Turno*> getTurnos();

  // Setters
  void setNome(std::string nome);
  void setCnpj(std::string cnpj);
  void setFuncionarios(std::vector<Funcionario*>);
  void setClientes(std::vector<Cliente*>);
  void setCargos(std::vector <Cargo*> cargos);
  void setDepartamentos(std::vector <Departamento*> departamentos);
  void setEstoque(Estoque* estoque);
  void setHistoricoDeLogs(HistoricoDeLogs* historico);
  void setPermissoes(std::vector<Permissao*> permissoes);
  void setFrotaVeiculos(vector<Veiculo*> frotaVeiculos);
  void setTurnos(vector<Turno*> turnos);
};

#endif // EMPRESA_H