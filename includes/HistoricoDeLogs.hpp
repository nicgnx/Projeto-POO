#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include <map>
#include <vector>
#include "LogAbstrata.hpp"
#include "Data.hpp"


class HistoricoDeLogs {
  private:
    std::map <int, LogAbstrata*> historico;

  public:
    HistoricoDeLogs();
    ~HistoricoDeLogs();
    std::vector <LogAbstrata*> listaLog(Data, Data);
    
}




#endif // HISTORICODELOGS_H