#include "../includes/Turno.hpp"

// Construtores e Destrutores
Turno::Turno(
   std::string nomeTurno, float horaEntrada, float minutosEntrada, float horaSaida, float minutosSaida,
    tipoTurno periodo
) {
  this->nomeTurno = nomeTurno;
  this->horarioEntrada.first = horaEntrada;
  this->horarioEntrada.second = minutosEntrada;
  this->horarioSaida.first =  horaSaida;
  this->horarioSaida.second = minutosSaida;
  this->periodo = periodo;
}

Turno::Turno() {}
Turno::~Turno() {}

// Getters
std::string Turno::getNomeTurno() { return this->nomeTurno; }

std::pair<float,float> Turno::getHorarioEntrada() { return this->horarioEntrada; }

std::pair<float,float>Turno::getHorarioSaida() { return this->horarioSaida; }

tipoTurno Turno::getPeriodo() { return this->periodo; }

float Turno::getHorarioEntradaCompleto(){
  float horario = this->horarioEntrada.second/60;

  horario += this->horarioEntrada.first;
  return horario;
};

// Setters

void Turno::setNomeTurno(std::string nomeTurno) { this->nomeTurno = nomeTurno; }

void Turno::setHorarioSaida(float horaSaida, float minutosSaida) {
  this->horarioSaida.first =  horaSaida;
  this->horarioSaida.second = minutosSaida;
}

void Turno::setHorarioEntrada(float horaEntrada, float minutosEntrada) {
   this->horarioEntrada.first = horaEntrada;
  this->horarioEntrada.second = minutosEntrada;
}

void Turno::setPeriodo(tipoTurno periodo) { this->periodo = periodo; }
