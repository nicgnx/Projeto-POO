#include "../includes/MateriaPrima.hpp"

MateriaPrima::MateriaPrima() {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","MateriaPrima"," ","Contrutor MateriaPrima");
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima","","",CRIACAO));


}

MateriaPrima::MateriaPrima(int id, std::string nome, std::string unidade, int estoqueMinimo) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","MateriaPrima"," ","Contrutor MateriaPrima");
  this->nome = nome;
  this->id = id;
  this->estoqueMinimo = estoqueMinimo;
  this->unidade = unidade;
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima",nome,to_string(id),CRIACAO));
}
MateriaPrima::~MateriaPrima() {}

// Operators
bool MateriaPrima::operator==(MateriaPrima& mp) { return this->id == mp.id; }

// getters
int MateriaPrima::getId() { 

  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"MateriaPrima","Estoque","getId");

  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima","getId","id"));
  
  return this->id; 
}
std::string MateriaPrima::getNome() { 
  
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"MateriaPrima","Estoque","getNome");

  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima","getNome","nome"));
  
  return this->nome; 
}

std::string MateriaPrima::getUnidade() { 
  
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"MateriaPrima","Estoque","getUnidade");

  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima","getUnidade","unidade"));
  
  return this->unidade; 
}

int MateriaPrima::getEstoqueMinimo() { 
  
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"MateriaPrima","Estoque","getEstoqueMinimo");

  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogLeitura(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"MateriaPrima","getEstoqueMinimo","estoqueMinimo"));
  
  return this->estoqueMinimo; }

// setters
void MateriaPrima::setNome(std::string nome) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","MateriaPrima",to_string(this->id),"setNome");
  this->nome = nome; }
void MateriaPrima::setUnidade(std::string unidade) { 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","MateriaPrima",to_string(this->id),"setUnidade");
  this->unidade = unidade; }
void MateriaPrima::setEstoqueMinimo(int estoqueMinimo) {
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","MateriaPrima",to_string(this->id),"setEstoqueMinimo");
  this->estoqueMinimo = estoqueMinimo;
}

// Métodos

void MateriaPrima::printMateriaPrima() {
  std::cout << "---------------------------------------------------------------\n"
            << "                   Materia Prima - "
            << this->nome << "\n\n"
            << "Identificador:  " << this->id << "\n"
            << "Unidade:        " << this->unidade << "\n"
            << "Estoque Mínimo: " << this->estoqueMinimo << "\n"
            << "---------------------------------------------------------------\n";
}