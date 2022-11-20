## Distribuição

- Materia Prima, OrdemDeMateriaPrima, Fornecedor: Erick
- Orcamento, PedidoDeCompra, ItensDesejados: Raphael

## Padronizações

- nome de variaveis, atributos e métodos: lowerCamelCase
- nome de classes: UpperCamelCase
- constantes, defines e macros: ALL_CAPS
- usar dois espaços para tabs
- usar this para acessar os atributos e métodos

## Listando ações do sistema

1. Logar
2. Cadastrar / Editar Funcionario
3. Cadastrar / Editar Cliente
4. Editar Salário
5. Demitir de Funcionario
6. Cadastrar Produto / Lotes
7. Editar produto
8. Comprar produto

## Formatação automática

```

cd src
clang-format -i *.cpp
cd ../program
clang-format -i *.cpp
cd ../includes
clang-format -i *.hpp

```

ou

```

.\format.bat

```

## Compilação Manual


```

g++ -std=c++14 -Wall main.cpp -o main.exe
.\main.exe

```

