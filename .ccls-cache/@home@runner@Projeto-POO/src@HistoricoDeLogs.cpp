#include "../includes/HistoricoDeLogs.hpp"

HistoricoDeLogs::HistoricoDeLogs() {
  
}
HistoricoDeLogs::~HistoricoDeLogs() {
  
}
std::vector <LogLeitura*>  HistoricoDeLogs::listaLogLeitura(Data dataInicial, Data dataFinal) {
  std::vector <LogLeitura*> logs;
  for (auto it : this->historico) {
    if (it.second->getData() >= dataInicial && it.second->getData() <= dataFinal)
      logs.push_back(it.second);
  }
  return logs;
}

std::vector <LogEscrita*>  HistoricoDeLogs::listaLogEscrita(Data dataInicial, Data dataFinal) {
  std::vector <LogEscrita*> logs;
  for (auto it : this->historico) {
    if (it.second->getData() >= dataInicial && it.second->getData() <= dataFinal)
      logs.push_back(it.second);
  }
  return logs;
}

std::vector <LogExcecao*>  HistoricoDeLogs::listaLogExcecao(Data dataInicial, Data dataFinal) {
  std::vector <LogExcecao*> logs;
  for (auto it : this->historico) {
    if (it.second->getData() >= dataInicial && it.second->getData() <= dataFinal)
      logs.push_back(it.second);
  }
  return logs;
}