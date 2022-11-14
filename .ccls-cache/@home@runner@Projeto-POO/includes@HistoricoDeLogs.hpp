#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include <map>
#include <vector>
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"
#include "LogExcecao.hpp"
#include "Data.hpp"


class HistoricoDeLogs {
  private:
    std::map <int, LogLeitura*> historico;
    std::map <int, LogEscrita*> historico;
    std::map <int, LogExcecao*> historico;


  public:
    HistoricoDeLogs();
    ~HistoricoDeLogs();

    //Getters
    std::vector <LogLeitura*> listaLogLeitura(Data, Data);
    std::vector <LogEscrita*> listaLogEscrita(Data, Data);
    std::vector <LogExcecao*> listaLogExcecao(Data, Data);

    //Setters
    void setLogLeitura(LogLeitura *Log);
    void setLogEscrita(LogEscrita *Log);
    void setLogExcecao(LogExcecao *Log);
    
}




#endif // HISTORICODELOGS_H