#ifndef LOGIN_H
#define LOGIN_H

#include "Data.hpp"
#include "Usuario.hpp"
#include "LogExcecao.hpp"
#include "HistoricoDeLogs.hpp"
#include "LogLoginLogout.hpp"
#include "ExecaoCustomizada.hpp"
#include <string>

class Login {
private:
  Usuario* usuario;
  Data logadoEm;
  static Login* instance;

  // Construtor e Destrutor
  Login();
  ~Login();
  // Funções auxiliares
  bool auxVerificaPermissao(int idPermissao);
  void disparaExcecao(std::string frase,std::string classe,std::string instancia,std::string metodo);

public:
  static Login* getInstance();

  void logar(Usuario*);
  void deslogar();
  std::string getUsuarioNome();
  std::string getUsuarioSenha();
  Usuario* getUsuario();
  bool verificaPermissao(int,std::string permissao,std::string classe,std::string instancia,std::string metodo);
  bool verificaPermissao(int,int,std::vector<std::string>,std::string classe,std::string instancia,std::string metodo);
  bool verificaPermissao(int,int,int,std::vector<std::string>,std::string classe,std::string instancia,std::string metodo);
  bool verificaPermissao(int,int,int,int,std::vector<std::string>,std::string classe,std::string instancia,std::string metodo);
};

#endif // LOGIN_H