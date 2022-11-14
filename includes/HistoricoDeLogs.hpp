#ifndef HISTORICODELOGS_H
#define HISTORICODELOGS_H

#include <map>
#include <vector>
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"
#include "LogExcecao.hpp"
#include "Data.hpp"

enum tipoLog {Escrita,Leitura,Excecao};

class HistoricoDeLogs {
  private:
    std::map <int, vector<LogLeitura*>> historicoLeitura;
    std::map <int, vector<LogEscrita*>> historicoEscrita;
    std::map <int, vector<LogExcecao*>> historicoExcecao;


  public:
    HistoricoDeLogs();
    ~HistoricoDeLogs();

    //Getters
    std::vector <LogLeitura*> listaLogLeitura(int idUsuario,Data inicial, Data final);
    std::vector <LogEscrita*> listaLogEscrita(int idUsuario,Data inicial, Data final);
    std::vector <LogExcecao*> listaLogExcecao(int idUsuario,Data inicial, Data final);

    //Setters
    void setLogLeitura(int idUsuario, LogLeitura *Log);
    void setLogEscrita(int idUsuario, LogEscrita *Log);
    void setLogExcecao(int idUsuario, LogExcecao *Log);

    //Methods
    void printLog(tipoLog log,int idUsuario, Data inicial, Data final);
    
};




#endif // HISTORICODELOGS_H