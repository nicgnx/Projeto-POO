#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>

class Utils {

public:
  Utils();
  ~Utils();

  bool verificaCPF(std::string cpf);
  bool verificaCNPJ(std::string cnpj);
};

#endif // UTILS_H