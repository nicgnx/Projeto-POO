#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include "LogAbstrata.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"
#include <vector>
#include <iostream>
#include <typeinfo> 


class HistoricoDeLogs {
private:
  static HistoricoDeLogs* historicoDeLogs;
  HistoricoDeLogs();
  ~HistoricoDeLogs();
  std::vector<LogAbstrata*> historico;
  std::vector<LogAbstrata*> historicoCompleto;

public:
  // Operators
  HistoricoDeLogs(const HistoricoDeLogs&);
  HistoricoDeLogs& operator=(const HistoricoDeLogs&);

  // Getters
  static HistoricoDeLogs* getInstancia();
  std::vector<LogAbstrata*> getHistorico();
  std::vector<LogAbstrata*> getHistoricoCompleto();

  // Setters
  void setLog(LogAbstrata* Log);

  // Métodos
  void printLog();
  void printLogCompleto();
};

#endif // HISTORICODELOGS_H