#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H

#include "Produto.hpp"
#include "Data.hpp"
#include "Lote.hpp"
#include <string>


class OrdemDeProducao {
  private:
    std::string produto;
    int idProduto;
    Data data;
    int quantidade;

  public:
    OrdemDeProducao(std::string nome ,int idProduto, Data data , int quantidade);
    ~OrdemDeProducao();

    //getters
    int getIdProduto();
    Data getData();
    int getQuantidade();

    //setters
    void setIdProduto(int);
    void setData(Data);
    void setQuantidade(int);

    // Métodos
    Lote* solicitaLote();
}

#endif // ORDEMDEPRODUCAO_H