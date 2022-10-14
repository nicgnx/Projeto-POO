#ifndef LOTE_H
#define LOTE_H

#include "Produto.hpp"
#include "Data.hpp"

enum Status {
  Estoque,
  Vendido
};

class Lote {
  private:
    int idProduto;
    Data data;
    int quantidade;
    Status status;
    const int idLote;
    static int lotesTotais;

  public:
    Lote(int, int, Data);
    Lote();
    ~Lote();

    void updateLotes(int);
    
    //getters
    int getIdProduto();
    Data getData();
    int getQuantidade();
    int getIdLote();
    int getLotesTotais();
    Status getStatus();

    //setters
    void setIdProduto(int);
    void setData(Data);
    void setQuantidade(int);
    void setStatus(Status);
    
};

#endif // LOTE_H