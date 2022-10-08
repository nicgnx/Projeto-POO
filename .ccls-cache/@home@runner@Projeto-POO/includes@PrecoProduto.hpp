#ifndef PRECO_PRODUTO_H
#define PRECO_PRODUTO_H

#include "../includes/Data.hpp"

class PrecoProduto {
  float precoBase;
  float percentualVariacao;
  Data dataVariacao;

public:
  // Construtores e Destrutores
  PrecoProduto(
    float precoBase, 
    float percentualVariacao, 
    Data dataVariacao
  );
  PrecoProduto();
  ~PrecoProduto();

  // Getters
  float getPrecoBase();
  float getPercentualVariacao();
  Data getDataVariacao(); 

  // Setters
  void setPrecoBase(float precoBase);
  void setPercentualVariacao(float percentualVariacao);
  void setDataVariacao(Data dataVariacao);
};


#endif // PRECO_PRODUTO_H