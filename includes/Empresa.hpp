#ifndef EMPRESA_H
#define EMPRESA_H

#include "../includes/Cargo.hpp"
#include "../includes/Departamento.hpp"
#include <string>
#include <vector>

class Empresa {
private:
  std::string nome;
  std::string cnpj;
  std::vector <Cargo*> cargos;
  std::vector <Departamento*> departamentos;

public:
  Empresa(
    std::string nome,
    std::string cnpj,
    std::vector <Cargo*> cargos,
    std::vector <Departamento*> departamentos
  );
  Empresa();
  ~Empresa();

  // Getters
  std::string getNome();
  std::string getCnpj();
  std::vector <Cargo*> getCargos();
  std::vector <Departamento*> getDepartamentos();

  // Setters
  void setNome(std::string nome);
  void setCnpj(std::string cnpj);
  void setCargos(std::vector <Cargo*> cargos);
  void setDepartamentos(std::vector <Departamento*> departamentos);
};

#endif // EMPRESA_H