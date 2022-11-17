#ifndef ORDEMDEMATERIAPRIMA_H
#define ORDEMDEMATERIAPRIMA_H

#include <string>
#include "Data.hpp"
#include "Fornecedor.hpp"
#include "MateriaPrima.hpp"
#include <iostream>

class OrdemDeMateriaPrima {
  private:
    MateriaPrima materiaPrima;
    int quantidade;
    Data data;
    Fornecedor* fornecedor;
    


  public:
    OrdemDeMateriaPrima(MateriaPrima materiaPrima,int quantidade, Data data);
    ~OrdemDeMateriaPrima();

    //getters
    MateriaPrima getMateriaPrima();
    int getquantidade();
    Data getData();
    Fornecedor* getFornecedor();

    //setters
    void setMateriaPrima(MateriaPrima);
    void setQuantidade(int);
    void setData(Data);
    void setFornecedor(Fornecedor*);

    //Métodos
    Fornecedor* melhorPreco(int idMateriaPrima, std::vector<Fornecedor*> fornecedores);
    void printOrdemDeMP();
} 

#endif // ORDEMDEMATERIAPRIMA_H