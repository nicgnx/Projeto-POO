#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include <map>
#include <vector>
#include "LogAbstrata.hpp"
#include "Data.hpp"


class historicoDeLogs {
  private:
    std::map <int, LogAbstrata*> historico;

  public:
    historicoDeLogs();
    ~historicoDeLogs();
    std::vector <LogAbstrata*> listaLog(Data, Data);
    
}




#endif // HISTORICODELOGS_H