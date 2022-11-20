#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include "Data.hpp"
#include "LogEscrita.hpp"
#include "LogExcecao.hpp"
#include "LogLeitura.hpp"
#include <map>
#include <vector>

enum tipoLog { Escrita, Leitura, Excecao };

class HistoricoDeLogs {
private:
  static HistoricoDeLogs* historicoDeLogs;
  HistoricoDeLogs();
  ~HistoricoDeLogs();
  std::map<int, vector<LogLeitura*>> historicoLeitura;
  std::map<int, vector<LogEscrita*>> historicoEscrita;
  std::map<int, vector<LogExcecao*>> historicoExcecao;

public:
  // Operators
  HistoricoDeLogs(const HistoricoDeLogs&);
  HistoricoDeLogs& operator=(const HistoricoDeLogs&);

  // Getters
  static HistoricoDeLogs* getInstacia();
  std::vector<LogLeitura*>
  listaLogLeitura(int idUsuario, Data inicial, Data final);
  std::vector<LogEscrita*>
  listaLogEscrita(int idUsuario, Data inicial, Data final);
  std::vector<LogExcecao*>
  listaLogExcecao(int idUsuario, Data inicial, Data final);

  // Setters
  void setLogLeitura(int idUsuario, LogLeitura* Log);
  void setLogEscrita(int idUsuario, LogEscrita* Log);
  void setLogExcecao(int idUsuario, LogExcecao* Log);

  // Methods
  void printLog(tipoLog log, int idUsuario, Data inicial, Data final);
};

#endif // HISTORICODELOGS_H