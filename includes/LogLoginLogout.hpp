#ifndef LOGLOGINLOGOUT_H
#define LOGLOGINLOGOUT_H

#include "LogAbstrata.hpp"
#include <iostream>
#include <string>

enum operacaoL {LOGIN,LOGOUT};

class LogLoginLogout : public LogAbstrata{

private:
  std::string tipoLogin;

public:
// Contrutores e Destrutores
  LogLoginLogout();
  ~LogLoginLogout();
  LogLoginLogout(std::string usuario,std::string idUsuario,Data data,std::string classeAcessada,operacaoL operacao);

// Getters
  std::string getTipoLogin();

// Setters
  void setTipoLogin(std::string tipoLogin);

// Métodos
  void printLog();
};

#endif //LOGLOGINLOGOUT_H