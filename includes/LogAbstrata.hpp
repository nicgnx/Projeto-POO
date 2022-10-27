#ifndef LOGABSTRATA_H
#define LOGABSTRATA_H

#include "../includes/HistoricoDelogs.hpp"
#include "../includes/Usuario.hpp"
#include "../includes/Data.hpp"


class LogAbstrata{

  protected:
    Usuario* usuario;
    Data data;
    std::string classeAcessada;


  public:
    virtual LogAbstrata() = default;
  
    Usuario* getUsuario();
    Data getData();
    std::string getClasseAcessada();

    void setUsuario(Usuario* usuario);
    void setData(Data data);
    void setClasseAcessada(std::string classeAcessada);

    std::string printLog();
}

#endif