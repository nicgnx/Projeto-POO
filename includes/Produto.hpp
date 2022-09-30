#ifndef PRODUTO_H
#define PRODUTO_H

#include "../includes/Categoria.hpp"
#include "../includes/Lote.hpp"
#include <string>

class Produto {
    std::string produto;
    int codigo;
    float valor;
    Categoria categoria;
    int loteMinimo;
    int estoqueMinimo;
    vector <Lote*> lotes;

public:

    // Construtores e Destrutores
    Produto(std::string produto, int codigo, float valor, Categoria categoria, int loteMinimo, int estoqueMinimo);
    Produto();
    ~Produto();

    // Getters
    std::string Produto::getProduto();
    int Produto::getCodigo();
    float Produto::getValor();
    Categoria Produto::getCategoria();
    int Produto::getLoteMinimo();
    int Produto::getEstoqueMinimo();
    Lote Produto::getLote(int numLote);
    vector <Lote*> Produto::getLoteTodos();

    // Setters
    void Produto::setProduto(std::string produto);
    void Produto::setCodigo(int codigo);
    void Produto::setValor(float valor);
    void Produto::setCategoria(Categoria categoria);
    void Produto::setLoteMinimo(int loteMinimo);
    void Produto::setEstoqueMinimo(int estoqueMinimo);
    void Produto::setLote(int numLote);
    void Produto::setLoteTodos(vector <Lote*> lotes)
};





#endif // PRODUTO_H