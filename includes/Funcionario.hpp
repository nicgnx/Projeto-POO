#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

#include "usuario.hpp"
#include "Data.hpp"
#include "Cargo.hpp"
#include "Departamento.hpp"
#include "Salario.hpp"
#include "Historico.hpp"

class Funcionario : public Usuario {
  Data dataNascimento;
  std::string endereco;
  std::string matricula;
  Cargo cargo;
  Departamento departamento;
  Historico historico[];
  Salario salario[];   

public:
  Funcionario();
  ~Funcionario();

  // getters
  Data getDataNascimento();
  std::string getEndereco();
  std::string getMatricula();
  Cargo getCargo();
  Historico getHistorico();
  Departamento getDepartamento();
  float getSalarioAtual();

  // setters
  void setDataNascimento(Data);
  void setEndereco(std::string);
  void setMatricula(std::string);
  void setCargo(std::string);
  void updateHistorico(Historico Historico);
  void setSalarioAtual(float);
  void setDepartamento(Departamento); 
};

#endif