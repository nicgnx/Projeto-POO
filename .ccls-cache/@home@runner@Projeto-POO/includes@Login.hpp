#ifndef LOGIN_H
#define LOGIN_H

#include "Data.hpp"
#include "Usuario.hpp"

class Login
 {
    private:
      Usuario* usuario = nullptr;
      Data logadoEm;
      static Login* instance = nullptr;

      //Construtor e Destrutor
      Login(Usuario*);
      ~Login();
      

    public:
      static Login& logar(Usuario*);
      void deslogar();
      
 };


#endif //LOGIN_H