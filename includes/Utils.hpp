#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <string>

class Utils {

public:
    Utils();
    ~Utils();

    bool verificaCPF(std::string cpf);
    bool verificaCNPJ(std::string cnpj);
};

#endif // UTILS_H