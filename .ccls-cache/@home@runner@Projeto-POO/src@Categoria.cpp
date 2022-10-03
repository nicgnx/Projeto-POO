#include "../includes/Categoria.hpp"

Categoria::Categoria(std::string categoria) {
  this->categoria = categoria;
}

Categoria::Categoria(){
  this->categoria.clear();
}

Categoria::~Categoria(){}


std::string Categoria::getCategoria (){
  return this->categoria;
}

void Categoria::setCategoria (std::string categoria){
  this->categoria = categoria;
}