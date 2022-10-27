#ifndef LOG_EXCECAO_H
#define LOG_EXCECAO_H

class LogExcecao {
protected:
  std::string metodo;

public:
  // Construtores e Destrutores
  LogExcecao(
    std::string metodo
  );
  LogExcecao();
  ~LogExcecao();

  // Getters
  std::string getMetodo ();

  // Setters
  void setMetodo(std::string metodo);
};


#endif // LOG_EXCECAO_H