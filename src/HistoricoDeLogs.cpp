#include "../includes/HistoricoDeLogs.hpp"

HistoricoDeLogs::HistoricoDeLogs() {
  this->historico.clear();
}
HistoricoDeLogs::~HistoricoDeLogs() {}
HistoricoDeLogs* HistoricoDeLogs::historicoDeLogs = NULL;

// Getters
HistoricoDeLogs* HistoricoDeLogs::getInstancia() {
  if (historicoDeLogs == NULL)
    historicoDeLogs = new HistoricoDeLogs();
  return historicoDeLogs;
}

std::vector<LogAbstrata*> HistoricoDeLogs::getHistorico(){return this->historico;}

// Setters
void HistoricoDeLogs::setLog(LogAbstrata *Log){
  if(typeid(*Log) == typeid(LogLeitura) || typeid(*Log) == typeid(LogEscrita)){
    this->historicoCompleto.push_back(Log);
  }
  else{
    this->historicoCompleto.push_back(Log);
    this->historico.push_back(Log);}
  }
  

void HistoricoDeLogs::printLog(){
  for(int i = 0; i < this->historico.size(); i++){
    this->historico[i]->printLog();
  }
}


void HistoricoDeLogs::printLogCompleto(){
  for(int i = 0; i < this->historicoCompleto.size(); i++){
    this->historicoCompleto[i]->printLog();
  }
}
