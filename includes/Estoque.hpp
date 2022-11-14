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
  public:
  // Operators 
    Estoque(const Estoque&);
    Estoque& operator=(const Estoque&);

  //getters
    static Estoque* getInstancia();
    std::map <int,Produto*> getListaDeProdutos();
    Produto* getProduto(int idProduto);
    Lote* getLote(int idProduto, int idLote);
    

  //Métodos
    vector <int> retiraLotes(int idProduto,int quantidade);
    int  verificaEstoque(int idProduto);
    void cadastraProduto(std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco);
    void cadastraLote(int idProduto, Lote* lote);
    void solicitaLote();
    void reabasteceEstoque(int idProduto);
    void reabasteceEstoque(int idProduto, int quantidade);
    void printListaDeProdutos();
    void printListaDeLotes(int idProduto);
};

