#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>

class Departamento {
private:
    std::string departamento;

public:
    Departamento(std::string departamento);
    Departamento();
    ~Departamento();

    std::string getDepartamento();
    void setDepartamento(std::string departamento);
};

#endif // DEPARTAMENTO_H