#ifndef PRODUTO_H
#define PRODUTO_H

#include "Categoria.hpp"
#include "PrecoProduto.hpp"
//#include "Login.hpp"
//#include "../constants/PERMISSOES.hpp"
#include "MateriaPrima.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Produto {
  static int* staticIdProduto;
  std::string nome;
  int idProduto;
  std::map<int,int> materiasPrimas;
  std::vector<PrecoProduto*> precos;
  Categoria categoria;
  int loteMinimo;
  int estoqueMinimo;

public:
  // Construtores e Destrutores
  Produto(
    std::string nome, std::map<int,int> materiasPrimas, Categoria categoria, int loteMinimo, int estoqueMinimo,
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
  std::map<int,int> getMateriasPrimas();
  PrecoProduto* getPrecos();
  Categoria getCategoria();
  int getLoteMinimo();
  int getEstoqueMinimo();
  int getID();

  // Setters
  void setNome(std::string nome);
  void setIdProduto(int idProduto);
  void setMateriasPrimas(int idMateriaPrima, int quantidade);
  void setCategoria(Categoria categoria);
  void setLoteMinimo(int loteMinimo);
  void setEstoqueMinimo(int estoqueMinimo);

  // misc
  void printMateriaPrima();
  void novoPreco(float precoBase, float percentualVariacao, Data data);
  void novoPreco(PrecoProduto* preco);
};

#endif // PRODUTO_H