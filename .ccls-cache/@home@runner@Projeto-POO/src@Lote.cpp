#include "../includes/Lote.hpp"

int Lote::lotesTotais = 0;

Lote::Lote(int idProduto, Data data, int quantidade)
  : idLote(this->lotesTotais) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Lote",to_string(this->idLote),"Construtor Lote");

  this->data = data;
  this->idProduto = idProduto;
  this->quantidade = quantidade;
  this->lotesTotais += 1;
  this->status = Status::ESTOQUE;
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Lote",to_string(idProduto),to_string(this->idLote),CRIACAO));
}

Lote::Lote() : idLote(this->lotesTotais) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Lote",to_string(this->idLote),"Construtor Lote");

  
  this->lotesTotais += 1;
  this->status = Status::ESTOQUE;
  this->data = data.dateNow();
  this->idProduto = -1;
  this->quantidade = -1;
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"Lote","",to_string(this->idLote),CRIACAO));
}

Lote::~Lote() {}

void Lote::updateLotes(int quantidade) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Lote",to_string(this->idLote),"updateLotes");
  this->quantidade -= quantidade;
  if (this->quantidade <= 0) {
    this->quantidade = 0;
    this->status = Status::VENDIDO;
  }
}

// getters
int Lote::getIdProduto() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getIdProduto");
  return this->idProduto; 
}

Data Lote::getData() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getData");
  return this->data; 
}

int Lote::getQuantidade() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getQuantidade");
  return this->quantidade; 
}

int Lote::getIdLote() { std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getLote");
  return this->idLote; 
}

int Lote::getLotesTotais() { std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getLotesTotais");
  return this->lotesTotais; 
}

Status Lote::getStatus() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","getStatus");
  return this->status; 
}

// setters
void Lote::setIdProduto(int idProduto) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Lote",to_string(this->idLote),"setIdProduto");
  this->idProduto = idProduto;
}

void Lote::setData(Data data) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Lote",to_string(this->idLote),"setData");
  this->data = data; 
}

void Lote::setQuantidade(int quantidade) { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"Lote",to_string(this->idLote),"setQuantidade");

  this->quantidade = quantidade; 
}

void Lote::setStatus(Status status) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","Lote",to_string(this->idLote),"setStatus");
  this->status = status; 
}
