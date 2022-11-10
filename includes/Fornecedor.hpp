#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <vector>

#include "MateriaPrima.hpp"

class Fornecedor {
  private:
    std::vector <MateriaPrima> materiaPrima;
    std::string nome;


  public:
    Fornecedor(std::string);
    ~Fornecedor();

    void AdcionaMateriaPrima(MateriaPrima);

    //getters
    std::vector <MateriaPrima> getMateriaPrima();
    std::string getNome();

    //setters
    void setMateriaPrima(std::vector <MateriaPrima>);
    void setNome(std::string);
} 

#endif // FORNECEDOR_H