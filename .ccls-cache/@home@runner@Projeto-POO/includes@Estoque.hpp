#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <string>
#include "../includes/Produto.hpp"

class Estoque {
private:
  Produto *produto;
  int quantidade;

public:
  Estoque(Produto *produto, int quantidade);
  Estoque();
  ~Estoque();

//getters
  Produto getProduto();
  int getQuantidade();

//setters
  void setProduto(Produto *produto);
  void setQuantidade(int quantidade);

//atualizar estoque
  void atualizaEstoque();
};


#endif // ESTOQUE_H