#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <string>

class Estoque {
private:
  Produto *produto;
  int quantidade;

public:
  Estoque(Produto *produto, int quantidade);
  Estoque();
  ~Estoque();

//getters
  Prodtuo getProduto();
  int getQuantidade();

//setters
  void setProduto(Produto *produto);
  void setQuantidade(int qtd);

//atualizar estoque
  void atualizaEstoque();
};


#endif // ESTOQUE_H