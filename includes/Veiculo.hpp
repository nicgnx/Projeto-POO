#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <sstream>
#include "../includes/Funcionario.hpp"
#include "../includes/Turno.hpp"
#include <string>
#include <vector>
#include <cmath>
#include<algorithm>
#include <iomanip>

class Veiculo {
  // Atributos
private:
  int capacidade;
  Turno* turno;
  std::vector<Funcionario*> funcionarios;
  std::vector<Funcionario*> rotasFuncionarios;
  float horarioPartida;

  // Métodos
  void verificaTurno();
  float calculaDistancia(float x1, float y1, float x2, float y2);
  void defineRota();
  void defineEmbarque(std::string horarioEmbarque, float distancia);
  void auxDefineRota(std::vector<Funcionario*>* auxVector, std::pair<float,float> cordenada);
  

public:
  // Construtores e Destrutores
  Veiculo(int capacidade, Turno* turno, std::vector<Funcionario*> funcionarios);
  Veiculo();
  ~Veiculo();
  void exibeRota();
  // Getters
  int getCapacidade();
  Turno* getTurno();
  float getHorarioPartida();
  std::vector<Funcionario*> getRotasFuncionarios();

  // Setters
  void setCapacidade(int capacidade);
  void setTurno(Turno* turno);
  void setRotasFuncionarios(std::vector<Funcionario*> rotasFuncionarios);
  void setHorarioPartida(float horarioPartida);
};

#endif // VEICULO_H