#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include "LogAbstrata.hpp"
#include <vector>
#include <iostream>


class HistoricoDeLogs {
private:
  static HistoricoDeLogs* historicoDeLogs;
  HistoricoDeLogs();
  ~HistoricoDeLogs();
  std::vector<LogAbstrata*> historico;

public:
  // Operators
  HistoricoDeLogs(const HistoricoDeLogs&);
  HistoricoDeLogs& operator=(const HistoricoDeLogs&);

  // Getters
  static HistoricoDeLogs* getInstancia();
  std::vector<LogAbstrata*> getHistorico();

  // Setters
  void setLog(LogAbstrata* Log);

  // Métodos
  void printLog();
};

#endif // HISTORICODELOGS_H