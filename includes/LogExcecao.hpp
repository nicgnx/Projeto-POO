#ifndef LOG_EXCECAO_H
#define LOG_EXCECAO_H

#include "LogAbstrata.hpp"

class LogExcecao : public LogAbstrata{
private:
  std::string metodo;

public:
  // Construtores e Destrutores
  LogExcecao(std::string usuario, int idUsuario, Data data,std::string classeAcessada, std::string instanciaAcessada,std::string metodo);
  LogExcecao();
  ~LogExcecao();

  // Getters
  std::string getMetodo();

  // Setters
  void setMetodo(std::string metodo);

  //Methods
  void printLog() override;
};


#endif // LOG_EXCECAO_H