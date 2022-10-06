#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <string>
#include "../includes/Produto.hpp"
#include <map>

class Estoque {
private:
  vector <Produto*> produto;
  map <int idProduto,vector <Lotes*> lotes> quantidade;
  static Estoque* estoque;
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