#ifndef TURNO_H
#define TURNO_H

#include <string>


enum tipoTurno { MANHA, TARDE, NOITE };

class Turno {

  // Atributos
private:
  std::string nomeTurno;
  std::pair<float,float> horarioEntrada;
  std::pair<float,float> horarioSaida;
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
  std::pair<float,float> getHorarioEntrada();
  std::pair<float,float>  getHorarioSaida();
  tipoTurno getPeriodo();
  float getHorarioEntradaCompleto();

  // Setters
  void setNomeTurno(std::string nomeTurno);
  void setHorarioEntrada(float horaEntrada, float minutosEntrada);
  void setHorarioSaida(float horaSaida, float minutosSaida);
  void setPeriodo(tipoTurno periodo);
};

#endif