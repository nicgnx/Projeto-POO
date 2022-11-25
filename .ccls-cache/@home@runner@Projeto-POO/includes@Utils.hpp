#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <string>
#include "HistoricoDeLogs.hpp"

class Utils {

public:
  Utils();
  ~Utils();

  bool verificaCPF(std::string cpf);
  bool verificaCNPJ(std::string cnpj);
  /*static bool criaLog(int idPermissao, std::string classeAcessada, std::string instaciaAcessada, std::string metodo, std::string atributoAcessado, std::string atributoAntes, std::string atributoDepois);
};*/

#endif // UTILS_H