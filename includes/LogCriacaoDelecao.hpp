#ifndef LOGCRIACAODELECAO_H
#define LOGCRIACAODELECAO_H

#include <string>
#include "LogAbstrata.hpp"
#include <iostream>

enum operacao {CRIACAO,DELECAO};

class LogCriacaoDelecao : public LogAbstrata{

private:
  std::string instancia;
  std::string id;
  std::string tipoOperacao;
public:
  // Contrutores e Destrutores
  LogCriacaoDelecao();
  ~LogCriacaoDelecao();
  LogCriacaoDelecao(std::string usuario,std::string idUsuario,Data data,std::string classeAcessada,std::string instanciaCriada,std::string id,operacao operacao);
  LogCriacaoDelecao(std::string instanciaCriada,operacao operacao);

  // Getters
  std::string getInstancia();
  std::string getId();
  std::string getOperacao();

  // Setters
  void setInstancia(std::string instancia);
  void setId(std::string id);
  void setOperacao(std::string operacao);

  // Métodos
  virtual void printLog();
};

#endif // LOGCRIACAODELECAO_H