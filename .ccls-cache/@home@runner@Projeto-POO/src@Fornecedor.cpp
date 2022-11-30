#include "../includes/Fornecedor.hpp"

Fornecedor::Fornecedor(std::string nome) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor"," ","Contrutor Fornecedor");
  this->nome = nome; 
}
Fornecedor::~Fornecedor() {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor"," ","Contrutor Fornecedor");
}

// getters

std::map<int, float> Fornecedor::getMateriaPrima() {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Fornecedor",this->nome,"getMateriaPrima");
  return this->produtosFornecidos;
}
std::string Fornecedor::getNome() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Fornecedor",this->nome,"getNome");
  return this->nome; }

// setters
void Fornecedor::setMateriaPrima(int idMateriaPrima, float preco) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor",this->nome,"setMateriaPrima");
  this->produtosFornecidos[idMateriaPrima] = preco;
}
void Fornecedor::setNome(std::string nome) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor",this->nome,"setMateriaPrima");
  this->nome = nome; }

// Métodos
float Fornecedor::enviaPreco(int idMateriaPrima) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Fornecedor",this->nome,"enviaPreco");
  return this->produtosFornecidos[idMateriaPrima];
}

bool Fornecedor::possuiProduto(int idMateriaPrima) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Fornecedor",this->nome,"possuiProduto");
  bool aux;
  this->produtosFornecidos.find(idMateriaPrima) !=
      this->produtosFornecidos.end() ?
    aux = 1 :
    aux = 0;
  return aux;
}

void Fornecedor::printProdutos() {
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n"
            << "                         Produtos ofertados pelo fornecedor "
            << this->nome << "\n\n";
  for (auto i = this->produtosFornecidos.begin();
       i != this->produtosFornecidos.end(); i++) {
    std::cout << "ID: " << i->first << "     "
              << "Preço: " << i->second << "\n";
  }
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n";
}