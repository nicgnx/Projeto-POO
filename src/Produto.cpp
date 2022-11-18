#include "../includes/Produto.hpp"

int* Produto::staticIdProduto = NULL;

Produto::Produto(
  std::string nome, Categoria categoria, int loteMinimo, int estoqueMinimo,
  PrecoProduto* preco
) {

  this->nome = nome;
  this->idProduto = getID();
  this->precos.push_back(preco);
  this->categoria = categoria;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
}

Produto::Produto(
  std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco
) {
  this->nome = nome;
  this->idProduto = getID();
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->precos.push_back(preco);
}

Produto::Produto() { this->idProduto = getID(); } // construtor padrão

Produto::~Produto() {} // destrutor

// Getters

int Produto::getID() {
  if (staticIdProduto == NULL) {
    staticIdProduto = new int;
    *staticIdProduto = 0;
  }
  *staticIdProduto += 1;
  return *staticIdProduto;
}

std::string Produto::getNome() { return this->nome; }

int Produto::getIdProduto() { return this->idProduto; }

PrecoProduto* Produto::getPrecos() { return this->precos.back(); }

Categoria Produto::getCategoria() { return this->categoria; }

int Produto::getLoteMinimo() { return this->loteMinimo; }

int Produto::getEstoqueMinimo() { return this->estoqueMinimo; }

// Setters

void Produto::setNome(std::string nome) { this->nome = nome; }

void Produto::setIdProduto(int idProduto) { this->idProduto = idProduto; }

void Produto::setCategoria(Categoria categoria) { this->categoria = categoria; }

void Produto::setLoteMinimo(int loteMinimo) { this->loteMinimo = loteMinimo; }

void Produto::setEstoqueMinimo(int estoqueMinimo) {
  this->estoqueMinimo = estoqueMinimo;
}

// Métodos

void Produto::novoPreco(float precoBase, float percentualVariacao, Data data) {
  PrecoProduto* preco = new PrecoProduto(precoBase, percentualVariacao, data);
  this->precos.push_back(preco);
}

void Produto::novoPreco(PrecoProduto* preco) { this->precos.push_back(preco); }