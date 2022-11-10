#ifndef LOGABSTRATA_H
#define LOGABSTRATA_H

#include "../includes/HistoricoDelogs.hpp"
#include "../includes/Usuario.hpp"
#include "../includes/Data.hpp"


class LogAbstrata{

  protected:
    std::string usuario;
    std::string idUsuario;
    Data data;
    std::string classeAcessada;


  public:
    virtual LogAbstrata() = default;
  
    std::string getUsuario();
    int getIdUsuario();
    Data getData();
    std::string getClasseAcessada();

    void setUsuario(std:string usuario);
    void setIdUsuario(int idUsuario);
    void setData(Data data);
    void setClasseAcessada(std::string classeAcessada);
}

#endif