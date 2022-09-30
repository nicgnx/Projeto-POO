#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

class Categoria {
private:
  std::string nomeCateg;

public:
  Categoria(std::string nomeCateg);
  Categoria();
  ~Categoria();
  std::string getNomeCateg();
  void setNomeCateg(std::string nome);
};

#endif // CATEGORIA_H