#ifndef LOG_LEITURA_H
#define LOG_LEITURA_H

class LogLeitura {
protected:
  std::string informacao;

public:
  // Construtores e Destrutores
  LogLeitura(
    std::string inforacao
  );
  LogLeitura();
  ~LogLeitura();

  // Getters
  std::string getInformacao();

  // Setters
  void setInformacao(std::string informacao);
};


#endif // LOG_LEITURA_H