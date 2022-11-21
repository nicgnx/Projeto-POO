#ifndef LOG_ESCRITA_H
#define LOG_ESCRITA_H

#include "LogAbstrata.hpp"
#include <iostream>

class LogEscrita : public LogAbstrata {
private:
  std::string atributoAcessado;
  std::string atributoAntes;
  std::string atributoDepois;

public:
  // Construtores e Destrutores
  LogEscrita(
    std::string usuario, int idUsuario, Data data, std::string classeAcessada,
    std::string instanciaAcessada, std::string atributoAcessado,
    std::string atributoAntes, std::string atributoDepois
  );
  LogEscrita();
  ~LogEscrita();

  // Getters
  std::string getAtributoAcessado();
  std::string getAtributoAntes();
  std::string getAtributoDepois();

  // Setters
  void setAtributoAcessado(std::string atributoAcessado);
  void setAtributoAntes(std::string atributoAntes);
  void setAtributoDepois(std::string atributoDepois);

  // Methods
  void printLog();
};

#endif // LOG_ESCRITA_H