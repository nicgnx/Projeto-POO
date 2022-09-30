#include "../includes/Categoria.hpp"

Categoria::Categoria(std::string nome) {
  this->nomeCateg = nome;
}

Categoria::Categoria(){
  this->nomeCateg.clear();
}

Categoria::~Categoria(){}


std::string Categoria::getNomeCateg (){
  return this->nomeCateg;
}

void Categoria::setNomeCateg (std::string nome){
  this->nomeCateg = nome;
}