#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H

class OrdemDeProducao {
  private:
    Produto* produto;
    Data dataOrdem;
    int quatidate;
  public:
    OrdemDeProducao();
    ~OrdemDeProducao();

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