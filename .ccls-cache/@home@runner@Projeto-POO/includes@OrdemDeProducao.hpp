#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H

#include "Produto.hpp"
#include "Data.hpp"
#include "Lote.hpp"


class OrdemDeProducao {
  private:
    int idProduto;
    Data data;
    int quantidade;

  public:
    OrdemDeProducao(int, Data, int);
    ~OrdemDeProducao();

    Lote* solicitaLote();

    //getters
    int getIdProduto();
    Data getData();
    int getQuantidade();

    //setters
    void setIdProduto(int);
    void setData(Data);
    void setQuantidade(int);
    
    
}

#endif // ORDEMDEPRODUCAO_H