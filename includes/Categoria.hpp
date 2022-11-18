#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

class Categoria {
private:
    std::string categoria;

public:
    Categoria(std::string categoria);
    Categoria();
    ~Categoria();
    std::string getCategoria();
    void setCategoria(std::string categoria);
};

#endif // CATEGORIA_H