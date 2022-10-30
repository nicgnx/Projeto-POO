#ifndef EMPRESA_H
#define EMPRESA_H

#include "../includes/Cargo.hpp"
#include "../includes/Departamento.hpp"
#include "../includes/Estoque.hpp"
#include "../includes/HistoricoDeLogs.hpp"
#include "../includes/Permissao.hpp"
#include <string>
#include <vector>

class Empresa {
private:
  static Empresa* empresa;
  Empresa(
    std::string nome,
    std::string cnpj,
    std::vector <Cargo*> cargos,
    std::vector <Departamento*> departamentos,
    Estoque* estoque,
    HistoricoDeLogs* historico,
    std::vector <Permissao*> permissoes    
  );
  Empresa();
  ~Empresa();

// Atributes
  std::string nome;
  std::string cnpj;
  std::vector <Cargo*> cargos;
  std::vector <Departamento*> departamentos;
  Estoque* estoque;
  HistoricoDeLogs* historico;
  std::vector <Permissao*> permissoes; 


public:

// Operators 
   Empresa(const Empresa&);
   Empresa& Empresa=(const Empresa&);

  // Getters
  std::string getNome();
  std::string getCnpj();
  std::vector <Cargo*> getCargos();
  std::vector <Departamento*> getDepartamentos();
  Estoque* getEstoque();
  HistoricoDeLogs getHistoricoDeLogs();
  std::vector <Permissao*> getPermissoes();

  // Setters
  void setNome(std::string nome);
  void setCnpj(std::string cnpj);
  void setCargos(std::vector <Cargo*> cargos);
  void setDepartamentos(std::vector <Departamento*> departamentos);
  void setEstoque(Estoque* estoque);
  void setHistoricoDeLogs(HistoricoDeLogs* historico);
  void setPermissoes(Permissao* permissoes);
};

#endif // EMPRESA_H