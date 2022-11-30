#include "../includes/OrdemDeProducao.hpp"

OrdemDeProducao::OrdemDeProducao(std::string produto, int idProduto, Data data, int quantidade) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeMateriaPrima",to_string(this->idProduto),"Construtor OrdemDeMateriaPrima");
  
  this->produto = produto;
  this->idProduto = idProduto;
  this->data = data;
  this->quantidade = quantidade;
  
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"OrdemDeProducao",produto,to_string(idProduto),CRIACAO));
}

OrdemDeProducao::~OrdemDeProducao() {}

// Métodos

Lote* OrdemDeProducao::solicitaLote() {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeMateriaPrima",to_string(this->idProduto),"Construtor OrdemDeMateriaPrima");

  return new Lote(this->idProduto, this->data, this->quantidade);
}

// getters
int OrdemDeProducao::getIdProduto() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeProducao",to_string(idProduto),"getIdProduto");
  return this->idProduto;
}

Data OrdemDeProducao::getData() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeProducao",to_string(idProduto),"getData");
  return this->data; 
}

int OrdemDeProducao::getQuantidade() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeProducao",to_string(idProduto),"getQuantidade");
  return this->quantidade; 
}

// setters
void OrdemDeProducao::setIdProduto(int idProduto) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeProducao",to_string(this->idProduto),"setIdProduto");
  this->idProduto = idProduto;
}

void OrdemDeProducao::setData(Data data) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor",to_string(this->idProduto),"setData");
  this->data = data; 
}

void OrdemDeProducao::setQuantidade(int quantidade) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Fornecedor",to_string(this->idProduto),"setQuantidade");
  this->quantidade = quantidade;
}
