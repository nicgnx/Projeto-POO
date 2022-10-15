#include "../includes/Login.hpp"
#include "../includes/Cliente.hpp"
#include "../third_party/doctest.h"

TEST_CASE("Construtor") {
    Cliente agroBrasil("Agro Brasil","comercial@agrobrasil.com.br", "1236548", PJ, 551125487);
    Cliente comunicaBrasil("Comunica Brasil","comercial@comunicabrasil.com.br", "83974141", PJ, 112548557);
    Login::logar(&agroBrasil);
    // Se um usuario estiver logado, qualquer tentatica de login ira retornar o endereço da instancia daquele usuario
    Login::logar(&comunicaBrasil);
    CHECK_EQ(Login::getUsuarioNome(), "Agro Brasil");
    Login::deslogar();
    CHECK_EQ(Login::getInstance(), nullptr);
    Login::logar(&comunicaBrasil);
    CHECK_EQ(Login::getUsuarioNome(), "Comunica Brasil");

}