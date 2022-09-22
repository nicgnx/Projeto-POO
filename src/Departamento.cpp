#include "../includes/Departamento.hpp"


Departamento::Departamento(std::string nome) {
  this->nome = nome;
}

std::string Departamento::getNome(){
  return this->nome;
}

void Departamento::setNome(std::string nome){
  this->nome = nome;
}