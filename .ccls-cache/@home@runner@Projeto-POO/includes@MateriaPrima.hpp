#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H

#include <string>

class MateriaPrima {
  private:
    int id;
    std::string nome;
    std::string unidade;
    int estoqueMinimo;


  public:
    MateriaPrima(int, std::string, std::string, int );
    ~MateriaPrima();

    //getters
    int getId();
    std::string getNome();
    std::string getUnidade();
    int getEstoqueMinimo();

    //setters
    void setNome(std::string);
    void setUnidade(std::string);
    void setEstoqueMinimo(int);
} 

#endif // MATERIAPRIMA_H