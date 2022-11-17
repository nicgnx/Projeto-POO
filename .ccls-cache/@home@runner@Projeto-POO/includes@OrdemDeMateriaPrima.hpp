#ifndef ORDEMDEMATERIAPRIMA_H
#define ORDEMDEMATERIAPRIMA_H

#include <string>
#include "Data.hpp"
#include "Fornecedor.hpp"
#include <iostream>

class OrdemDeMateriaPrima {
  private:
    std::string materiaPrima;
    int quantidade;
    Data data;
    Fornecedor* fornecedor;
    


  public:
    OrdemDeMateriaPrima(int, std::string, Data);
    ~OrdemDeMateriaPrima();

    //getters
    std::string getMateriaPrima();
    int getquantidade();
    Data getData();
    Fornecedor* getFornecedor();

    //setters
    void setMateriaPrima(std::string);
    void setQuantidade(int);
    void setData(Data);
    void setFornecedor(Fornecedor*);

    //Métodos
    Fornecedor* melhorPreco(int idMateriaPrima, std::vector<Fornecedor*> fornecedores);
} 

#endif // ORDEMDEMATERIAPRIMA_H