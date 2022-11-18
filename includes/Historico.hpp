#ifndef HISTORICO_H
#define HISTORICO_H

#include "Data.hpp"
#include <string>

class Historico {
    Data data;
    std::string registro;

public:
    Historico(
        int ano, int mes, int dia, int hora, int minuto, int segundo,
        std::string registro
    );
    Historico(Data data, std::string registro);
    ~Historico();
    Data getData();
    std::string getRegistro();
    void setData(Data data);
    void setRegistro(std::string registro);
};

#endif // HISTORICO_H