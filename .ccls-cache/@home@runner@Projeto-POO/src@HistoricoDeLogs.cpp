#include "../includes/HistoricoDeLogs.hpp"

HistoricoDeLogs::HistoricoDeLogs() {
  this->historicoEscrita.clear();
  this->historicoExcecao.clear();
  this->historicoLeitura.clear();
}
HistoricoDeLogs::~HistoricoDeLogs() {}
HistoricoDeLogs* HistoricoDeLogs::historicoDeLogs = NULL;

// Getters
HistoricoDeLogs* HistoricoDeLogs::getInstacia() {
  if (historicoDeLogs == NULL)
    historicoDeLogs = new HistoricoDeLogs();
  return historicoDeLogs;
}

std::vector<LogLeitura*> HistoricoDeLogs::listaLogLeitura(
  int idUsuario, Data dataInicial, Data dataFinal
) {
  std::vector<LogLeitura*> logs;
  for (int i = 0; i < this->historicoLeitura[idUsuario].size(); i++) {
    Data dataUser = this->historicoLeitura[idUsuario][i]->getData();
    if (dataInicial < dataUser || dataInicial == dataUser) {
      if (dataFinal > dataUser || dataFinal == dataUser)
        logs.push_back(this->historicoLeitura[idUsuario][i]);
      else
        return logs;
    }
  }
  return logs;
}

std::vector<LogEscrita*> HistoricoDeLogs::listaLogEscrita(
  int idUsuario, Data dataInicial, Data dataFinal
) {
  std::vector<LogEscrita*> logs;
  for (int i = 0; i < this->historicoEscrita[idUsuario].size(); i++) {
    Data dataUser = this->historicoEscrita[idUsuario][i]->getData();
    if (dataInicial < dataUser || dataInicial == dataUser) {
      if (dataFinal > dataUser || dataFinal == dataUser)
        logs.push_back(this->historicoEscrita[idUsuario][i]);
      else
        return logs;
    }
  }
  return logs;
}

std::vector<LogExcecao*> HistoricoDeLogs::listaLogExcecao(
  int idUsuario, Data dataInicial, Data dataFinal
) {
  std::vector<LogExcecao*> logs;
  for (int i = 0; i < this->historicoExcecao[idUsuario].size(); i++) {
    Data dataUser = this->historicoExcecao[idUsuario][i]->getData();
    if (dataInicial < dataUser || dataInicial == dataUser) {
      if (dataFinal > dataUser || dataFinal == dataUser)
        logs.push_back(this->historicoExcecao[idUsuario][i]);
      else
        return logs;
    }
  }
  return logs;
}

void HistoricoDeLogs::setLogLeitura(int idUsuario, LogLeitura* Log) {
  this->historicoLeitura[idUsuario].push_back(Log);
}

void HistoricoDeLogs::setLogEscrita(int idUsuario, LogEscrita* Log) {
  this->historicoEscrita[idUsuario].push_back(Log);
}

void HistoricoDeLogs::setLogExcecao(int idUsuario, LogExcecao* Log) {
  this->historicoExcecao[idUsuario].push_back(Log);
}


void HistoricoDeLogs::printLog(
  tipoLog log, int idUsuario, Data inicial, Data final
) {
  switch (log) {
    case Escrita: {
      vector<LogEscrita*> logsE = listaLogEscrita(idUsuario, inicial, final);
      for (int i = 0; i < logsE.size(); i++) {
        logsE[i]->printLog();
      };
      break;
    }
    case Excecao: {
      vector<LogExcecao*> logsEx = listaLogExcecao(idUsuario, inicial, final);
      for (int i = 0; i < logsEx.size(); i++) {
        logsEx[i]->printLog();
      };
      break;
    }
    case Leitura: {
      vector<LogLeitura*> logsL = listaLogLeitura(idUsuario, inicial, final);
      for (int i = 0; i < logsL.size(); i++) {
        logsL[i]->printLog();
      };
      break;
    }
  }
}
