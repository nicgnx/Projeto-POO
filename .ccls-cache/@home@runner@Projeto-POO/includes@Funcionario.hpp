#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

#include "Cargo.hpp"
#include "Data.hpp"
#include "Departamento.hpp"
#include "Historico.hpp"
#include "Salario.hpp"
#include "Turno.hpp"
#include "Usuario.hpp"

class Funcionario : public Usuario {
  Data dataNascimento;
  std::string endereco;
  std::string matricula;
  Cargo cargo;
  Departamento departamento;
  std::vector<Historico> historico;
  std::vector<Salario> salario;
  Turno* turno;

public:
  Funcionario();
  Funcionario(
    std::string nome, std::string cpfCnpj, std::string email, std::string senha,
    Data dataNascimento, std::string endereco, std::string matricula,
    Cargo cargo, Departamento departamento, Historico historico, Salario salario, Turno* turno
  );
  ~Funcionario();

  // getters
  Data getDataNascimento();
  std::string getEndereco();
  std::string getMatricula();
  Cargo getCargo();
  Historico getHistorico();
  vector<Historico> getHistoricoCompleto();
  Departamento getDepartamento();
  double getSalarioAtual();
  Turno* getTurno();

  // setters
  void setDataNascimento(Data dataNascimento);
  void setEndereco(std::string endereco);
  void setMatricula(std::string matricula);
  void setCargo(std::string cargo);
  void addHistorico(Historico historico);
  void setNovoSalario(Salario salario);
  void setDepartamento(std::string departamento);
  void setTurno(Turno* turno);
};

#endif // FUNCIONARIO_H