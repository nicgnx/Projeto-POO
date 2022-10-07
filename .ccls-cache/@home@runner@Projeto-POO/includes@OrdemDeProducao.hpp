#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H

#include "Produto.hpp"
#include "Data.hpp"
#include "Lote.hpp"


class OrdemDeProducao {
  private:
    Produto* produto;
    Data data;
    int quantidade;

  public:
    OrdemDeProducao(Produto*, Data, int);
    ~OrdemDeProducao();

    Lote* solicitaLote();

    //getters
    Produto* getProduto();
    Data getData();
    int getQuantidade();

    //setters
    void setProduto(Produto*);
    void setData(Data);
    void setQuantidade(int);
    
    
}

#endif // ORDEMDEPRODUCAO_H