#ifndef HISTORICO_H
#define HISTORICO_H

#include "Data.hpp"
#include <string>


class Historico {
    Data data;
    std::string registro;

public:
    Historico(int,int,int,int,int,int,std::string);
    ~Historico();
    Data getData();
    std::string getRegistro();
   void setData(Data);
   void setRegistro(std::string);
};

#include "../src/Historico.cpp"

#endif