#ifndef LOTE_H
#define LOTE_H

#include "Produto.hpp"
#include "Data.hpp"

class Lote {
  private:
    int idProduto;
    Data data;
    int quantidade;
    const int idLote;
    static int lotesTotais = 0;

  public:
    Lote(int, Data, int);
    Lote();
    ~Lote();

    

    //getters
    int getIdProduto();
    Data getData();
    int getQuantidade();
    int getIdLote();
    int getLotesTotais();

    //setters
    void setIdProduto(int produto);
    void setData(Data data);
    void setQuatidade(int quatidade);
    
};

#endif // LOTE_H