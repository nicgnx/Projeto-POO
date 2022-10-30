#include "../includes/HistoricoDeLogs.hpp"

HistoricoDeLogs::HistoricoDeLogs() {
  
}
HistoricoDeLogs::~HistoricoDeLogs() {
  
}
std::vector <LogAbstrata*>  HistoricoDeLogs::listaLog(Data dataInicial, Data dataFinal) {
  std::vector <LogAbstrata*> logs;
  for (auto it : this->historico) {
    if (it.second->getData() >= dataInicial && it.second->getData() <= dataFinal)
      logs.push_back(it.second);
  }
  return logs;
}