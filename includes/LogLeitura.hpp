#ifndef LOG_LEITURA_H
#define LOG_LEITURA_H

#include "LogAbstrata.hpp"
#include <iostream>

class LogLeitura : public LogAbstrata {

private:
  std::string informacao;

public:
  // Construtores e Destrutores
  LogLeitura(std::string usuario, int idUsuario, Data data,std::string classeAcessada, std::string instanciaAcessada, std::string informacao);
  LogLeitura();
  ~LogLeitura();

  // Getters
  std::string getInformacao();

  // Setters
  void setInformacao(std::string informacao);

  // Methods

  void printLog() override;
};


#endif // LOG_LEITURA_H