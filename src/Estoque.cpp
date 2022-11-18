#include "../includes/Estoque.hpp"

Estoque::Estoque() {}
Estoque::~Estoque() {}
Estoque* Estoque::estoque = NULL;

// getters
Estoque* Estoque::getInstancia() {
    if (estoque == NULL) {
        estoque = new Estoque();
    }
    return estoque;
}

std::map<int, Produto*> Estoque::getListaDeProdutos() { return this->produto; }

Produto* Estoque::getProduto(int idProduto) {
    std::map<int, Produto*>::iterator produto = this->produto.find(idProduto);
    if (produto == this->produto.end()) {
        std::cout << "Esse produto não existe!";
        throw("Esse produto não existe!");
    } else {
        return this->produto[idProduto];
    }
}

Lote* Estoque::getLote(int idProduto, int idLote) {
    for (int num = 0; num < this->lotes[idProduto].size(); num++) {
        if (this->lotes[idProduto][num]->getIdLote() == idLote) {
            return this->lotes[idProduto][num];
        }
    }
    throw("Esse lote não existe!");
}

// Métodos
int Estoque::verificaEstoqueProduto(int idProduto) {
    int estoqueDisponivel = 0;
    for (int num = 0; num < this->lotes[idProduto].size(); num++) {
        estoqueDisponivel += this->lotes[idProduto][num]->getQuantidade();
    }
    return estoqueDisponivel;
}

int Estoque::verificaEstoqueMP(int idMateriaPrima) {
    return this->estoqueMP[idMateriaPrima];
}

void Estoque::reabasteceEstoqueProduto(int idProduto) {
    if (verificaEstoqueProduto(idProduto) >
        this->produto[idProduto]->getEstoqueMinimo()) {
        auxPrintReabasteceEstoque(N_REALIZADO, idProduto);
    } else {
        if (this->produto[idProduto]->getEstoqueMinimo() >
            this->produto[idProduto]->getLoteMinimo()) {
            int aux = this->produto[idProduto]->getEstoqueMinimo() -
                      verificaEstoqueProduto(idProduto);
            OrdemDeProducao Solicitacao(
                this->produto[idProduto]->getNome(), idProduto,
                Data().dateNow(),
                ((aux / this->produto[idProduto]->getLoteMinimo()) + 1) *
                    this->produto[idProduto]->getLoteMinimo()
            );
            this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
            auxPrintReabasteceEstoque(REALIZADO, idProduto);
        } else {
            OrdemDeProducao Solicitacao(
                this->produto[idProduto]->getNome(), idProduto,
                Data().dateNow(), this->produto[idProduto]->getLoteMinimo()
            );
            this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
            auxPrintReabasteceEstoque(REALIZADO, idProduto);
        }
    }
}

void Estoque::reabasteceEstoqueProduto(int idProduto, int quantidade) {
    if (quantidade >= this->produto[idProduto]->getLoteMinimo()) {
        OrdemDeProducao Solicitacao(
            this->produto[idProduto]->getNome(), idProduto,
            Data(2022, 10, 15, 0, 0, 0), quantidade
        );
        this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
        auxPrintReabasteceEstoque(REALIZADO, idProduto);
    } else {
        std::cout << ("A quantidade solicitada é menor que o minímo permitido."
        );
    }
}

void Estoque::reabasteceEstoqueMP(int idMateriaPrima) {
    if (verificaEstoqueMP(idMateriaPrima) > this->estoqueMP[idMateriaPrima]) {
        auxPrintReabasteceEstoque(N_REALIZADO_MP, idMateriaPrima);
    } else {
        OrdemDeMateriaPrima Solicitacao(
            this->materiaPrima[idMateriaPrima],
            this->materiaPrima[idMateriaPrima]->getEstoqueMinimo(),
            Data().dateNow(), this->fornecedores
        );
        auxPrintReabasteceEstoque(REALIZADO_MP, idMateriaPrima);
        this->estoqueMP[idMateriaPrima] += Solicitacao.getQuantidade();
    }
}

void Estoque::reabasteceEstoqueMP(int idMateriaPrima, int quantidade) {
    OrdemDeMateriaPrima Solicitacao(
        this->materiaPrima[idMateriaPrima], quantidade, Data().dateNow(),
        this->fornecedores
    );
    auxPrintReabasteceEstoque(REALIZADO_MP, idMateriaPrima);
    this->estoqueMP[idMateriaPrima] += Solicitacao.getQuantidade();
}

vector<int> Estoque::retiraLotes(int idProduto, int quantidade) {
    vector<int> lotes;
    int aux, num = 0;
    vector<int> materiasPrimas;

    for (; num < this->lotes[idProduto].size(); num++) {
        aux = this->lotes[idProduto][num]->getQuantidade();
        if (aux >= quantidade) {
            aux = aux - quantidade;
            this->lotes[idProduto][num]->setQuantidade(aux);
            lotes.push_back(this->lotes[idProduto][num]->getIdLote());
            reabasteceEstoqueProduto(idProduto);
            return lotes;
        } else {
            if ((aux == 0) && (this->lotes[idProduto].size() > 1)) {
            } else {
                quantidade = quantidade - aux;
                this->lotes[idProduto][num]->setQuantidade(0);
                lotes.push_back(this->lotes[idProduto][num]->getIdLote());
            }
        }
    }
    std::cout << "Não era nem pra essa compra ter sido aprovada! Vai ficar sem "
                 "produto...";
    return lotes;
}

void Estoque::cadastraLote(int idProduto, Lote* lote) {
    this->lotes[idProduto].push_back(lote);
}

void Estoque::retiraMateriaPrima(int idMateriaPrima, int quantidade) {
    this->estoqueMP[idMateriaPrima] =
        this->estoqueMP[idMateriaPrima] - quantidade;
    if (this->estoqueMP[idMateriaPrima] <
        this->materiaPrima[idMateriaPrima]->getEstoqueMinimo())
        reabasteceEstoqueMP(idMateriaPrima);
}

void Estoque::cadastraProduto(
    std::string nome, int loteMinimo, int estoqueMinimo, PrecoProduto* preco
) {
    Produto* produto = new Produto(nome, loteMinimo, estoqueMinimo, preco);
    this->produto[produto->getIdProduto()] = produto;
    this->lotes[produto->getIdProduto()].push_back(new Lote());
    this->lotes[produto->getIdProduto()][0]->setQuantidade(0);
}

bool Estoque::verificaAplicacaoJuros(int idProdutos, int quantidade) {}

void Estoque::printListaDeProdutos() {
    std::cout
        << "---------------------------------------------------------------"
           "-------------------------------------\n\n";
    std::cout
        << "                            Lista dos Produtos Cadastrados no "
           "Sistema\n\n";
    for (std::map<int, Produto*>::iterator it = produto.begin();
         it != produto.end(); ++it) {
        std::cout << "Produto: " << this->produto[it->first]->getNome()
                  << "     ID: " << this->produto[it->first]->getIdProduto()
                  << "     Quantidade: "
                  << verificaEstoqueProduto(
                         this->produto[it->first]->getIdProduto()
                     )
                  << "\n";
    }
    std::cout
        << "\n\n-----------------------------------------------------------"
           "-----------------------------------------\n\n";
}

void Estoque::printListaDeLotes(int id) {
    for (int num = 0; num < this->lotes[idProduto].size(); num++) {
        std::cout << "Produto: " << this->produto[idProduto]->getNome()
                  << "     ID: " << idProduto
                  << "     Lote: " << this->lotes[idProduto][num]->getIdLote()
                  << "     Quantidade: "
                  << this->lotes[idProduto][num]->getQuantidade() << "\n";
    }
}

void Estoque::auxPrintReabasteceEstoque(tipoRetorno mens, int id) {
    switch (mens) {
        case N_REALIZADO: {
            std::cout << "-----------------------------------------------------"
                         "--------"
                         "---------------------------------------\n\n";
            std::cout << "                  Solicitação de Reabastecimento de "
                         "Estoque "
                         "não realizada.\n\n";
            std::cout << "                  O estoque minímo do produto [ "
                      << this->produto[id]->getNome()
                      << " ] ainda não foi atingido.";
            std::cout
                << "\n\n                  Quantidade disponível no estoque: "
                << verificaEstoqueProduto(id);
            std::cout << "\n\n-------------------------------------------------"
                         "--------"
                         "-------------------------------------------\n\n\n";
            break;
        }
        case REALIZADO: {
            std::cout << "-----------------------------------------------------"
                         "--------"
                         "---------------------------------------\n\n";
            std::cout << "                  Solicitação de Reabastecimento do "
                         "Estoque "
                         "do produto [ "
                      << this->produto[id]->getNome() << " ]\n\n";
            std::cout << "                  ID: " << id << "\n";
            std::cout << "                  Lote: "
                      << lotes[id].back()->getIdLote() << "\n";
            std::cout << "                  Quantidade: "
                      << lotes[id].back()->getQuantidade() << "\n";
            std::cout << "\n\n-------------------------------------------------"
                         "--------"
                         "-------------------------------------------\n\n\n";
            break;
        }
        case N_REALIZADO_MP: {
            std::cout << "-----------------------------------------------------"
                         "--------"
                         "---------------------------------------\n\n";
            std::cout << "                  Solicitação de Reabastecimento de "
                         "Estoque "
                         "não realizada.\n\n";
            std::cout
                << "                  O estoque minímo da Materia Prima [ "
                << this->materiaPrima[id]->getNome()
                << " ] ainda não foi atingido.";
            std::cout
                << "\n\n                  Quantidade disponível no estoque: "
                << verificaEstoqueMP(id);
            std::cout << "\n\n-------------------------------------------------"
                         "--------"
                         "-------------------------------------------\n\n\n";
            break;
        }
        case REALIZADO_MP: {
            std::cout << "-----------------------------------------------------"
                         "--------"
                         "---------------------------------------\n\n";
            std::cout << "                  Solicitação de Reabastecimento do "
                         "Estoque "
                         "da Materia Prima [ "
                      << this->materiaPrima[id]->getNome() << " ]\n\n";
            std::cout << "                  ID: " << id << "\n";
            std::cout << "                  Quantidade: "
                      << lotes[id].back()->getQuantidade() << "\n";
            std::cout << "\n\n-------------------------------------------------"
                         "--------"
                         "-------------------------------------------\n\n\n";
            break;
        }
    }
}