#ifndef TURNO_H
#define TURNO_H

#include <string>

enum tipoTurno {MANHA,TARDE,NOITE};

class Turno{

//Atributos
private:
  std::string nomeTurno;
  int horarioEntrada;
  int horarioSaida;
  tipoTurno periodo;

public:
//Construtoree e Destrutores
  Turno(std::string nomeTurno,int horarioEntrada,int horarioSaida,tipoTurno periodo);
  Turno();
  ~Turno();

//Getters
  std::string getNomeTurno();
  int getHorarioEntrada();
  int getHorarioSaida();
  tipoTurno getPeriodo();

//Setters
  void setNomeTurno(std::string nomeTurno);
  void setHorarioEntrada(int horarioEntrada);
  void setHorarioSaida(int horarioSaida);
  void setPeriodo(tipoTurno periodo);
};

#endif