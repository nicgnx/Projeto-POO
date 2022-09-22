#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>


class Departamento {
private:
  std::string nome;

public:
  Departamento(std::string nome);
  ~Departamento();
  
  std::string getNome();
  void setNome(std::string nome);
};

#include "../src/Departamento.cpp"

#endif // DEPARTAMENTO_H