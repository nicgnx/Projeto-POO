#include "../includes/Turno.hpp"

// Construtores e Destrutores
Turno::Turno(
    std::string nomeTurno, int horarioEntrada, int horarioSaida,
    tipoTurno periodo
) {
    this->nomeTurno = nomeTurno;
    this->horarioEntrada = horarioEntrada;
    this->horarioSaida = horarioSaida;
    this->periodo = periodo;
}

Turno::Turno() {}
Turno::~Turno() {}

// Getters
std::string Turno::getNomeTurno() { return this->nomeTurno; }

int Turno::getHorarioEntrada() { return this->horarioEntrada; }

int Turno::getHorarioSaida() { return this->horarioSaida; }

tipoTurno Turno::getPeriodo() { return this->periodo; }

// Setters

void Turno::setNomeTurno(std::string nomeTurno) { this->nomeTurno = nomeTurno; }

void Turno::setHorarioSaida(int horarioSaida) {
    this->horarioSaida = horarioSaida;
}

void Turno::setHorarioEntrada(int horarioEntrada) {
    this->horarioEntrada = horarioEntrada;
}

void Turno::setPeriodo(tipoTurno periodo) { this->periodo = periodo; }
