#pragma once

#include <string>
#include "../includes/Produto.hpp"
#include "../includes/OrdemDeProducao.hpp"
#include "OrdemDeMateriaPrima.hpp"
#include "Fornecedor.hpp"
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
    std::map <int,int> estoqueMP; // Parâmetros: idMateriaPrima, Quantidade
    std::vector<Fornecedor*> fornecedores;

    //Métodos Privados
    enum tipoRetorno {N_REALIZADO,REALIZADO,N_REALIZADO_MP,REALIZADO_MP};
    void auxPrintReabasteceEstoque(tipoRetorno mens, int idProduto);
    void reabasteceEstoqueProduto(int idProduto);
    void reabasteceEstoqueMP(int idMateriaPrima);
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
    std::vector<Fornecedor*> getFornecedores();
    

  //Métodos
    void cadastraFornecedo
    vector <int> retiraLotes(int idProduto,int quantidade);
    void retiraMateriaPrima(int idMateriaPrima,int quantidade);
    int  verificaEstoqueProduto(int idProduto);
    int  verificaEstoqueMP(int idMateriaPrima);
    void cadastraProduto(std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco);
    void cadastraMateriaPrima(int id,std::string nome, std::string unidade, int estoqueMinimo);
    void cadastraLote(int idProduto, Lote* lote);
    void solicitaLote();
    void reabasteceEstoqueProduto(int idProduto, int quantidade);
    void reabasteceEstoqueMP(int idMateriaPrima, int quantidade);
    void printListaDeProdutos();
    void printListaDeMateriasPrimas();
    void printListaDeLotes(int idProduto);
};

