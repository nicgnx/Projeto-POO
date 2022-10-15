#ifndef LOGIN_H
#define LOGIN_H

#include "Data.hpp"
#include "Usuario.hpp"
#include <string>

class Login
 {
    private:
      Usuario* usuario;
      Data logadoEm;
      static Login* instance;

      //Construtor e Destrutor
      Login(Usuario*);
      ~Login();
      

    public:
      static Login* logar(Usuario*);
      static Login* getInstance();
      static void deslogar();
      static std::string getUsuarioNome();
      static Usuario* getUsuario();
      
 };

#endif //LOGIN_H