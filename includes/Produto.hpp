#ifndef PRODUTO_H
#define PRODUTO_H

#include "../includes/Categoria.hpp"
#include "../includes/PrecoProduto.hpp"
#include <string>
#include <vector>

class Produto {
  static int* staticIdProduto;
  std::string nome;
  int idProduto;
  vector<PrecoProduto*> precos;
  Categoria categoria;
  int loteMinimo;
  int estoqueMinimo;

public:
  // Construtores e Destrutores
  Produto(
    std::string nome, Categoria categoria, int loteMinimo, int estoqueMinimo,
    PrecoProduto* preco
  );
  Produto();
  Produto(
    std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco
  );
  ~Produto();

  // Getters
  std::string getNome();
  int getIdProduto();
  PrecoProduto* getPrecos();
  Categoria getCategoria();
  int getLoteMinimo();
  int getEstoqueMinimo();
  int getID();

  // Setters
  void setNome(std::string nome);
  void setIdProduto(int idProduto);
  void setCategoria(Categoria categoria);
  void setLoteMinimo(int loteMinimo);
  void setEstoqueMinimo(int estoqueMinimo);

  // misc
  void novoPreco(float precoBase, float percentualVariacao, Data data);
  void novoPreco(PrecoProduto* preco);
};

#endif // PRODUTO_H