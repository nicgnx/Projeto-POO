#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H

#include "Produto.hpp"
#include "Data.hpp"

enum Status {
  Pendente,
  Executando,
  Concluido,
};

class OrdemDeProducao {
  private:
    Produto* produto;
    Data data;
    int quantidade;
    Status status;
  public:
    OrdemDeProducao(Produto*, Data, int, Status);
    ~OrdemDeProducao();

    //getters
    Produto* getProduto();
    Data getData();
    int getQuantidade();
    Status getStatus();

    //setters
    void setProduto(Produto*);
    void setData(Data);
    void setQuantidade(int);
    void setStatus(Status);
    
    
}

#endif // ORDEMDEPRODUCAO_H