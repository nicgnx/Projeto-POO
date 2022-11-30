#include "../includes/Produto.hpp"

int* Produto::staticIdProduto = NULL;

Produto::Produto(
  std::string nome,std::map<int,int> materiasPrimas, Categoria categoria, int loteMinimo, int estoqueMinimo,
  PrecoProduto* preco
) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto"," ","Contrutor Produto");
  this->nome = nome;
  this->idProduto = getID();
  this->materiasPrimas = materiasPrimas;
  this->precos.push_back(preco);
  this->categoria = categoria;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Produto",nome,to_string(idProduto),CRIACAO));
}

Produto::Produto(std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto"," ","Contrutor Produto");
  this->nome = nome;
  this->idProduto = getID();
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->precos.push_back(preco);
  
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Produto",nome,to_string(idProduto),CRIACAO));
}

Produto::Produto() { this->idProduto = getID(); } // construtor padrão

Produto::~Produto() {} // destrutor

// Getters

int Produto::getID() {
  if (staticIdProduto == NULL) {
    staticIdProduto = new int;
    *staticIdProduto = 1000;
  }
  *staticIdProduto += 1;
  return *staticIdProduto;
}

std::string Produto::getNome() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getNome");
  return this->nome; 
}

int Produto::getIdProduto() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getIdProduto");
  return this->idProduto;
}

std::map<int,int> Produto::getMateriasPrimas(){
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getMateriasPrimas");
  return this->materiasPrimas;
}

PrecoProduto* Produto::getPrecos() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getPrecos");
  return this->precos.back();
}

Categoria Produto::getCategoria() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getCategoria");
  return this->categoria; 
}

int Produto::getLoteMinimo() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getLoteMinimo");
  return this->loteMinimo; 
}

int Produto::getEstoqueMinimo() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"Produto",
to_string(this->idProduto),"getEstoqueMinimo");
  return this->estoqueMinimo; 
}

// Setters

void Produto::setNome(std::string nome) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"setNome");
  this->nome = nome; 
}

void Produto::setIdProduto(int idProduto) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"setIdProduto");
  this->idProduto = idProduto;
}

void Produto::setMateriasPrimas(int idMateriaPrima, int quantidade){
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"setMateriaPrima");
  this->materiasPrimas[idMateriaPrima] = quantidade;
}

void Produto::setCategoria(Categoria categoria) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"setCategoria");
  this->categoria = categoria; 
}

void Produto::setLoteMinimo(int loteMinimo) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"setLoteMinimo");
  this->loteMinimo = loteMinimo;
}

void Produto::setEstoqueMinimo(int estoqueMinimo) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"SetEstoqueMinimo");
  this->estoqueMinimo = estoqueMinimo;
}

// Métodos
void Produto::printMateriaPrima(){
  std::cout << "Materias Primas do Produto " << getNome() << "\n\n";
  for(auto i = this->materiasPrimas.begin(); i != this->materiasPrimas.end(); i++){
    std::cout << "ID: " << i->first << " Quantidade: " << i->second << "\n";
  } std::cout << "\n\n";
}

void Produto::novoPreco(float precoBase, float percentualVariacao, Data data) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"novoPreco");
  PrecoProduto* preco = new PrecoProduto(precoBase, percentualVariacao, data);
  this->precos.push_back(preco);
}

void Produto::novoPreco(PrecoProduto* preco) { 
 Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Produto",
to_string(this->idProduto),"novoPreco");
  this->precos.push_back(preco); 
}