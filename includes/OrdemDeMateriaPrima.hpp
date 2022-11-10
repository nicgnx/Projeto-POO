#ifndef ORDEMDEMATERIAPRIMA_H
#define ORDEMDEMATERIAPRIMA_H

#include <string>
#include "Data.hpp"

class OrdemDeMateriaPrima {
  private:
    std::string materiaPrima;
    int quantidade;
    Data data;


  public:
    OrdemDeMateriaPrima(int, std::string, Data);
    ~OrdemDeMateriaPrima();

    //getters
    std::string getMateriaPrima();
    int getquantidade();
    Data getData();

    //setters
    void setMateriaPrima(std::string);
    void setQuantidade(int);
    void setData(Data);
} 

#endif // ORDEMDEMATERIAPRIMA_H