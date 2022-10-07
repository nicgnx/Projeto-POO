#ifndef PRODUTO_H
#define PRODUTO_H

#include "../includes/Categoria.hpp"
#include "../includes/Lote.hpp"
#include "../includes/PrecoProduto.hpp"
#include <string>
#include <vector>

class Produto {
  std::string nome;
  int idProduto;
  vector <PrecoProduto*> precos;
  Categoria categoria;
  int loteMinimo;
  int estoqueMinimo;
  vector <Lote*> lotes;

public:
  // Construtores e Destrutores
  Produto(
    std::string nome, 
    int idProduto, 
    PrecoProduto* precoInicial,
    Categoria categoria, 
    int loteMinimo, 
    int estoqueMinimo
  );
  Produto();
  ~Produto();

  // Getters
  std::string Produto::getNome();
  int Produto::getIdProduto();
  vector <PrecoProduto*> Produto::getPrecos();
  Categoria Produto::getCategoria();
  int Produto::getLoteMinimo();
  int Produto::getEstoqueMinimo();
  Lote Produto::getLote(int idLote);
  vector <Lote*> Produto::getAllLotes();

  // Setters
  void Produto::setNome(std::string nome);
  void Produto::setIdProduto(int idProduto);
  void Produto::setPreco(PrecoProduto* preco);
  void Produto::setCategoria(Categoria categoria);
  void Produto::setLoteMinimo(int loteMinimo);
  void Produto::setEstoqueMinimo(int estoqueMinimo);
  void Produto::setLote(Lote* lote);

  // misc
  void updatePreco();
};


#endif // PRODUTO_H