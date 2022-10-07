#include "../includes/Produto.hpp"

Produto::Produto(
  std::string nome, 
  int idProduto, 
  PrecoProduto* precoInicial,
  Categoria categoria, 
  int loteMinimo, 
  int estoqueMinimo
) {
  vector <PrecoProduto*> initialPrecos;
  initialPrecos.push_back(precoInicial);
  
  this->nome = nome;
  this->idProduto = idProduto;
  this->precos = initialPrecos;
  this->categoria = categoria;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->lotes.clear();
}

Produto::Produto() { } // construtor padrão

Produto::~Produto() { } // destrutor

std::string Produto::getNome() {
  return this->nome;
}

int Produto::getIdProduto() {
  return this->idProduto;
}

vector <PrecoProduto*> Produto::getPrecos() {
  return this->precos;
}

Categoria Produto::getCategoria() {
  return this->categoria;
}

int Produto::getLoteMinimo(){
  return this->loteMinimo;
}

int Produto::getEstoqueMinimo() { 
  return this-> estoqueMinimo;
}

Lote Produto::getLote(int idLote) {
  for (unsigned int num = this->lotes.size(); num >= 0; num--) {
    if (this->lotes[num]->getIdLote() == idLote) {
      return *this->lotes[num];
      break;
    }
    
    if (num == 0) {
      throw "Lote não encontrado.";
    }
  }
}

vector <Lote*> Produto::getAllLotes(){
  return this->lotes;
}

void Produto::setNome(std::string nome) {
  this->nome = nome;
}

void Produto::setIdProduto(int idProduto) {
  this->idProduto = idProduto;
}

void Produto::setPreco(PrecoProduto* preco){
  this->precos.push_back(preco); 
}

void Produto::setCategoria(Categoria categoria) {
  this->categoria = categoria;
}

void Produto::setLoteMinimo(int loteMinimo) {
  this->loteMinimo = loteMinimo;
}

void Produto::setEstoqueMinimo(int estoqueMinimo) {
  this->estoqueMinimo = estoqueMinimo;
}

void Produto::setLote(Lote* lote){
  this->lotes.push_back(lote);
}
