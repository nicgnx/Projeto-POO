#ifndef LOG_ESCRITA_H
#define LOG_ESCRITA_H
#include "LogAbstrata.hpp"


class LogEscrita : public LogAbstrata{
private:
  std::string atributoAntes;
  std::string atributoDepois;

public:
  // Construtores e Destrutores
  LogEscrita(
    std::string atributoAntes,
    std::string atributoDepois
  );
  LogEscrita();
  ~LogEscrita();

  // Getters
  std::string getAtributoAntes();
  std::string getAtributoDepois();

  // Setters
  void setAtributoAntes(std::string atributoAntes);
  void setAtributoDepois(std::string atributoDepois);
};


#endif // LOG_ESCRITA_H