#ifndef VEICULO_H
#define VEICULO_H

#include "../includes/Funcionario.hpp"
#include "../includes/Turno.hpp"
#include <string>
#include <vector>

class Veiculo {
    // Atributos
private:
    int capacidade;
    Turno* turno;
    vector<Funcionario*> rotasFuncionarios;

    // Métodos
    void verificaTurno();
    floar calculaDistancia();
    void defineRota();

public:
    // Construtores e Destrutores
    Veiculo(
        int capacidade, Turno* turno, vector<Funcionario*> rotasFuncionarios
    );
    Veiculo();
    ~Veiculo();

    // Getters
    int getCapacidade();
    Turno* getTurno();
    vector<Funcionario*> getRotasFuncionarios();

    // Setters
    void setCapacidade(int capacidade);
    void setTurno(Turno* turno);
    void setRotasFuncionarios(vector<Funcionario*> rotasFuncionarios);
}

#endif // VEICULO_H