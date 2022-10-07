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
  float PrecoProduto::getPrecoBase();
  float PrecoProduto::getPercentualVariacao();
  Data PrecoProduto::getDataVariacao(); 

  // Setters
  void PrecoProduto::setPrecoBase(float precoBase);
  void PrecoProduto::setPercentualVariacao(float percentualVariacao);
  void PrecoProduto::setDataVariacao(Data dataVariacao);
};


#endif // PRECO_PRODUTO_H