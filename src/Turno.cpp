#include "../includes/Turno.hpp"

// Construtores e Destrutores
Turno::Turno(
   std::string nomeTurno, float horaEntrada, float minutosEntrada, float horaSaida, float minutosSaida,
    tipoTurno periodo
) {
  this->nomeTurno = nomeTurno;
  this->horarioEntrada = horaEntrada + minutosEntrada/60;
  this->horarioSaida = horaSaida + minutosSaida/60;
  this->periodo = periodo;
}

Turno::Turno() {}
Turno::~Turno() {}

// Getters
std::string Turno::getNomeTurno() { return this->nomeTurno; }

float Turno::getHorarioEntrada() { return this->horarioEntrada; }

float Turno::getHorarioSaida() { return this->horarioSaida; }

tipoTurno Turno::getPeriodo() { return this->periodo; }

// Setters

void Turno::setNomeTurno(std::string nomeTurno) { this->nomeTurno = nomeTurno; }

void Turno::setHorarioSaida(float horarioSaida) {
  this->horarioSaida = horarioSaida;
}

void Turno::setHorarioEntrada(float horarioEntrada) {
  this->horarioEntrada = horarioEntrada;
}

void Turno::setPeriodo(tipoTurno periodo) { this->periodo = periodo; }
