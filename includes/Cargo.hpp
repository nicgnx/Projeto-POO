#ifndef CARGO_H
#define CARGO_H

#include "Departamento.hpp"


class Cargo {
private:
  std::string nome;

public:
  Cargo(std::string nome);
  ~Cargo();

  std::string getCargo();
  void setCargo(std::string nome);
};

#include "../src/Cargo.cpp"

#endif // CARGO_H