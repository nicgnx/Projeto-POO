#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <map>

#include "MateriaPrima.hpp"

class Fornecedor {
  private:
    std::string nome;
    std::map<int,float> produtosFornecidos;
    
  public:
    Fornecedor(std::string nome);
    ~Fornecedor();


    //getters
    std::map<int,float> getMateriaPrima();
    std::string getNome();

    //setters
    void setMateriaPrima(int idMateriaPrima,float preco);
    void setNome(std::string nome);

    //Métodos
    float enviaPreco(int idMateriaPrima);
    bool possuiProduto(int idMateriaPrima);

} 

#endif // FORNECEDOR_H