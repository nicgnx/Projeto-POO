#ifndef ORDEMDEMATERIAPRIMA_H
#define ORDEMDEMATERIAPRIMA_H

#include "Data.hpp"
#include "Fornecedor.hpp"
#include "MateriaPrima.hpp"
#include <iostream>
#include <string>

class OrdemDeMateriaPrima {
private:
    MateriaPrima* materiaPrima;
    int quantidade;
    float valorFinal;
    Data data;
    Fornecedor* fornecedor;

public:
    OrdemDeMateriaPrima();
    OrdemDeMateriaPrima(
        MateriaPrima* materiaPrima, int quantidade, Data data,
        std::vector<Fornecedor*> fornecedores
    );
    ~OrdemDeMateriaPrima();

    // getters
    MateriaPrima* getMateriaPrima();
    int getQuantidade();
    float getValorFinal();
    Data getData();
    Fornecedor* getFornecedor();

    // setters
    void setMateriaPrima(MateriaPrima*);
    void setQuantidade(int);
    void setValorFinal(float);
    void setData(Data);
    void setFornecedor(Fornecedor*);

    // Métodos
    Fornecedor*
    melhorPreco(int idMateriaPrima, std::vector<Fornecedor*> fornecedores);
    void printOrdemDeMP();
};

#endif // ORDEMDEMATERIAPRIMA_H