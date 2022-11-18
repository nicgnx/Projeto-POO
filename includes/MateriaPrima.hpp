#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H

#include <iostream>
#include <string>

class MateriaPrima {
private:
    int id;
    std::string nome;
    std::string unidade;
    int estoqueMinimo;

public:
    MateriaPrima();
    MateriaPrima(int, std::string, std::string, int);
    ~MateriaPrima();

    // Operators
    bool operator==(MateriaPrima& mp2);

    // getters
    int getId();
    std::string getNome();
    std::string getUnidade();
    int getEstoqueMinimo();

    // setters
    void setNome(std::string);
    void setUnidade(std::string);
    void setEstoqueMinimo(int);

    // Métodos
    void printMateriaPrima();
};

#endif // MATERIAPRIMA_H