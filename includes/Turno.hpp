#ifndef TURNO_H
#define TURNO_H

#include <string>
#include "Login.hpp"

enum tipoTurno { MANHA, TARDE, NOITE };

class Turno {

  // Atributos
private:
  std::string nomeTurno;
  float horarioEntrada;
  float horarioSaida;
  tipoTurno periodo;

public:
  // Construtoree e Destrutores
  Turno(
    std::string nomeTurno, float horaEntrada, float minutosEntrada, float horaSaida, float minutosSaida,
    tipoTurno periodo
  );
  Turno();
  ~Turno();

  // Getters
  std::string getNomeTurno();
  float getHorarioEntrada();
  float getHorarioSaida();
  tipoTurno getPeriodo();

  // Setters
  void setNomeTurno(std::string nomeTurno);
  void setHorarioEntrada(float horarioEntrada);
  void setHorarioSaida(float horarioSaida);
  void setPeriodo(tipoTurno periodo);
};

#endif