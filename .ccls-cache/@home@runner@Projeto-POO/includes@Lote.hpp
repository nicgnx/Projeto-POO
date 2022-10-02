#ifndef LOTE_H
#define LOTE_H

#include "Produto.hpp"
#include "Data.hpp"

class Lote {
  private:
    Produto* produto;
    Data data;
    int quantidade;
    const int NUMLOTE;
    static int lotesTotais = 0;
  public:
    Lote(Produto*, Data, int);
    Lote();
    ~Lote();

    //getters
    Produto* getProduto();
    Data getData();
    int getQuatidade();
    int getNumLote();

    //setters
    void setProduto(Produto* produto);
    void setData(Data data);
    void setQuatidade(int quatidade);

    void atualizaLotes();
    
};

#endif // LOTE_H