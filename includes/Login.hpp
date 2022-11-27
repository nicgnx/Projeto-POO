#ifndef LOGIN_H
#define LOGIN_H

#include "Data.hpp"
#include "Usuario.hpp"
#include "LogExcecao.hpp"
#include "HistoricoDeLogs.hpp"
#include <string>

class Login {
private:
  Usuario* usuario;
  Data logadoEm;
  static Login* instance;

  // Construtor e Destrutor
  Login();
  ~Login();

public:
  static Login* getInstance();

  void logar(Usuario*);
  void deslogar();
  std::string getUsuarioNome();
  std::string getUsuarioSenha();
  Usuario* getUsuario();
  bool verificaPermissao(  
    int idPermissao, 
    std::string classeAcessada = "", 
    std::string instanciaAcessada = "", 
    std::string metodoAcessado = ""
  );
};

#endif // LOGIN_H