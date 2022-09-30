#include "../includes/Departamento.hpp"

Departamento::Departamento(std::string departamento) { this->departamento = departamento; }

Departamento::Departamento() { this->departamento.clear(); }

Departamento::~Departamento(){};

std::string Departamento::getDepartamento() { return this->departamento; }

void Departamento::setDepartamento(std::string departamento) { this->departamento = departamento; }