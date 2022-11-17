#pragma once

#include <string>
#include "../includes/Produto.hpp"
#include "../includes/OrdemDeProducao.hpp"
#include <map>
#include <list>
#include <iostream>
#include <deque>

class Estoque {
  private:
    static Estoque* estoque;
    Estoque();
    ~Estoque();

    // Atributes
    std::map <int,Produto*> produto; // Parâmetros: idProduto, Produto
    std::map <int,std::deque<Lote*>> lotes; // Parâmetros: idProduto, Lote
    std::map <int,MateriaPrima*> materiaPrima; // Parâmetros: idMateriaPrima, MateriaPrima
    std::map <int,int> lotesMP; // Parâmetros: idMateriaPrima, Quantidade

  public:
  // Operators 
    Estoque(const Estoque&);
    Estoque& operator=(const Estoque&);

  //getters
    static Estoque* getInstancia();
    std::map <int,Produto*> getListaDeProdutos();
    Produto* getProduto(int idProduto);
    Lote* getLote(int idProduto, int idLote);
    std::map <int,MateriaPrima*> getMateriaPrima();
    std::map <int,int> getLotesMP();
    

  //Métodos
    vector <int> retiraLotes(int idProduto,int quantidade);
    void retiraMateriaPrima(int idMateriaPrima,int quantidade);
    int  verificaEstoque(int idProduto);
    void cadastraProduto(std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco);
    void cadastraMateriaPrima(int id,std::string nome, std::string unidade, int estoqueMinimo);
    void cadastraLote(int idProduto, Lote* lote);
    void solicitaLote();
    void reabasteceEstoqueProduto(int idProduto);
    void reabasteceEstoqueProduto(int idProduto, int quantidade);
    void reabasteceEstoqueMP(int idMateriaPrima);
    void reabasteceEstoqueMP(int idMateriaPrima, int quantidade);
    void printListaDeProdutos();
    void printListaDeMateriasPrimas();
    void printListaDeLotes(int idProduto);
};

