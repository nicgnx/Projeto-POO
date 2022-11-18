#include "../includes/Veiculo.hpp"

// Construtores e Destrutores
Veiculo::Veiculo(
    int capacidade, Turno* turno, vector<Funcionario*> rotasFuncionarios
) {
    this->capacidade = capacidade;
    this->turno = turno;
    this->rotasFuncionarios = rotasFuncionarios;
    verificaTurno();
    defineRota();
}
Veiculo::Veiculo() { this->capacidade = 0; }
Veiculo::~Veiculo() {}

// Getters

int Veiculo::getCapacidade() { return this->capacidade; }

Turno* Veiculo::getTurno() { return this->turno; }

vector<Funcionario*> Veiculo::getRotasFuncionarios() {
    return this->rotasFuncionarios;
}

// Setters

void Veiculo::setCapacidade(int capacidade) { this->capacidade = capacidade; }

void Veiculo::setTurno(Turno* turno) {
    this->turno = turno;
    verificaTurno();
    defineRota();
}

void Veiculo::setRotasFuncionarios(vector<Funcionario*> rotasFuncionarios) {
    this->rotasFuncionarios = rotasFuncionarios;
    verificaTurno();
    defineRota();
}

// Métodos

void Veiculo::verificaTurno() {
    vector<Funcionario*> aux;
    for (int i = 0; i < this->rotasFuncionarios.size(); i++) {
        if (this->rotasFuncionarios[i]->getTurno()->getPeriodo() !=
            this->turno->getPeriodo()) {
        } else
            aux.push_back(this->rotasFuncionarios[i]);
    }
    this->rotasFuncionarios = aux;
}