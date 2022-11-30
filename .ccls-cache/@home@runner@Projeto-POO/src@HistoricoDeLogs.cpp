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
void HistoricoDeLogs::setLog(LogAbstrata *Log){this->historico.push_back(Log);}

void HistoricoDeLogs::printLog(){
  for(int i = 0; i < this->historico.size(); i++){
    this->historico[i]->printLog();
  }
}
