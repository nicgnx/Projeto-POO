#ifndef LOGABSTRATA_H
#define LOGABSTRATA_H


#include "../includes/Data.hpp"
#include <iostream>


class LogAbstrata{

  protected:
    std::string usuario;
    int idUsuario;
    Data data;
    std::string classeAcessada;
    std::string instanciaAcessada;


  public:
    LogAbstrata() = default;
  
    std::string getUsuario();
    int getIdUsuario();
    Data getData();
    std::string getClasseAcessada();
    std::string getInstanciaAcessada();


    void setUsuario(std::string usuario);
    void setIdUsuario(int idUsuario);
    void setData(Data data);
    void setClasseAcessada(std::string classeAcessada);
    void setInstanciaAcessada(std::string instanciaAcessada);
    virtual void printLog() const = 0;
    
};

#endif