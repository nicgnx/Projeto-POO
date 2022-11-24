#pragma once

#include "OrdemDeProducao.hpp"
#include "Produto.hpp"
#include "MateriaPrima.hpp"
//#include "Login.hpp"
#include "Fornecedor.hpp"
#include "OrdemDeMateriaPrima.hpp"
//#include "../constants/PERMISSOES.hpp"

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>

class Estoque {
private:
  static Estoque* estoque;
  Estoque();
  ~Estoque();

  // Atributes
  std::map<int, Produto*> produto;        // Parâmetros: idProduto, Produto
  std::map<int, std::deque<Lote*>> lotes; // Parâmetros: idProduto, Lote
  std::map<int, MateriaPrima*> materiaPrima; // Parâmetros: idMateriaPrima, MateriaPrima
  std::map<int, int> estoqueMP; // Parâmetros: idMateriaPrima, Quantidade
  std::vector<Fornecedor*> fornecedores;

  // Métodos Privados
  enum tipoRetorno { N_REALIZADO, REALIZADO, N_REALIZADO_MP, REALIZADO_MP };
  enum tipoReabastece {MINIMO,ARBITRARIO};
  void auxPrintReabasteceEstoque(tipoRetorno mens, int idProduto);
  void auxReabasteceEstoqueProduto(int idProduto, int quantidade);
  std::vector<int> auxRetiraLotes(int idProduto, int quantidade);

public:
  // Operators
  Estoque(const Estoque&);
  Estoque& operator=(const Estoque&);

  // getters
  static Estoque* getInstancia();
  std::map<int, Produto*> getListaDeProdutos();
  Produto* getProduto(int idProduto);
  Lote* getLote(int idProduto, int idLote);
  MateriaPrima* getMateriaPrima(int idMateriaPrima);
  std::vector<Fornecedor*> getFornecedores();
  std::map<int,MateriaPrima*> getListaMateriaPrima();
  std::map<int,int> getEstoqueMP();

  // Métodos
  int capacidadeDeProducao(int idProduto);
  int verificaEstoqueProduto(int idProduto);
  int verificaEstoqueMP(int idMateriaPrima);
  void cadastraFornecedor(Fornecedor* fornecedor); 
  void cadastraProduto(std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco);
  void cadastraMateriaPrima(int id, std::string nome, std::string unidade, int estoqueMinimo);
  void cadastraLote(int idProduto, Lote* lote);
  void reabasteceEstoqueProduto(int idProduto, int quantidade, tipoReabastece valor);
  void reabasteceEstoqueMP1(int idMateriaPrima, int quantidade, tipoReabastece valor);

/** @brief A função reabasteceEstoqueMP() recebe como parâmetro:

@param ponteiro de Produto.
@param quantidade desejada.
@param tipo de operação de Reabastecimento.

Caso a variável valor seja:

MINIMO - A função irá reabastecer todas as materias primas que compoem o produto, de forma a conseguir produzir o estoque minimo do produto, independente da quantidade informada.

ARBITRARIO - A função irá reabastecer todas as materias primas que compoem o produto, de forma a conseguir produzir a quantidade informada.
*/
  void reabasteceEstoqueMP(Produto* produto, int quantidade, tipoReabastece valor);
  void retiraMateriaPrima(int idMateriaPrima, int quantidade);
  void retiraMateriaPrima(Produto* produto, int quantidade);
  vector<int> retiraLotes(int idProduto, int quantidade);
  void printListaDeProdutos();
  void printListaDeMateriasPrimas();
  void printListaDeLotes(int idProduto);
  void printListaDeFornecedores();
};
