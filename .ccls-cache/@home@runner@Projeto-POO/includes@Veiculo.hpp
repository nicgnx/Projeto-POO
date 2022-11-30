#ifndef VEICULO_H
#define VEICULO_H

#include "../includes/Funcionario.hpp"
#include "../includes/Turno.hpp"
#include <string>
#include <vector>
#include <cmath>

class Veiculo {
  // Atributos
private:
  int capacidade;
  Turno* turno;
  std::vector<Funcionario*> funcionarios;
  std::vector<float> rotasFuncionarios;

  // Métodos
  void verificaTurno();
  float calculaDistancia(float x1, float y1, float x2, float y2);
  void defineRota();

public:
  // Construtores e Destrutores
  Veiculo(int capacidade, Turno* turno, std::vector<Funcionario*> funcionarios);
  Veiculo();
  ~Veiculo();

  // Getters
  int getCapacidade();
  Turno* getTurno();
  std::vector<Funcionario*> getRotasFuncionarios();

  // Setters
  void setCapacidade(int capacidade);
  void setTurno(Turno* turno);
  void setRotasFuncionarios(std::vector<Funcionario*> rotasFuncionarios);
};

#endif // VEICULO_H