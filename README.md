# Sistema de Gestão Hoteleira em C

Este projeto implementa um **Sistema de Gestão Hoteleira** em linguagem C, permitindo ao usuário cadastrar e gerenciar dados de hotéis, operadores, hóspedes, produtos, fornecedores, categorias de acomodações, acomodações propriamente ditas, reservas, transações e feedback. O sistema oferece duas formas de persistência de dados: arquivos texto (`.txt`) e arquivos binários (`.bin`).

---

## Índice

1. [Funcionalidades](#funcionalidades)
2. [Tecnologias e Dependências](#tecnologias-e-dependências)
3. [Estrutura de Arquivos](#estrutura-de-arquivos)
4. [Compilação](#compilação)
5. [Execução](#execução)
6. [Como Utilizar](#como-utilizar)
7. [Módulos Principais](#módulos-principais)
8. [Contribuição](#contribuição)
9. [Licença](#licença)

---

## Funcionalidades

* Cadastro e atualização de dados do hotel
* Gestão de operadores (cadastro, atualização e exclusão)
* Gestão de hóspedes, produtos, fornecedores, categorias e acomodações
* Criação, consulta e migração de reservas (TXT ↔ BIN)
* Módulo de transações e controle financeiro
* Módulo de feedback de clientes
* Importação e exportação de dados
* Interface de menu em linha de comando, com controle de permissões de acesso

---

## Tecnologias e Dependências

* Linguagem: C (ISO C99)
* Compilador: GCC (ou equivalente compatível com C99)
* Bibliotecas padrão (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, etc.)

---

## Estrutura de Arquivos

```plaintext
├── main.c             # Ponto de entrada do programa
├── menu.c             # Implementação dos menus de navegação
├── funcoes.c          # Funções utilitárias e de busca de registros
├── memoria.c          # Gestão de alocação dinâmica para RAM
├── ArquivosBin.c      # Leitura e escrita em arquivos binários
├── arquivosTXT.c      # Leitura e escrita em arquivos texto
├── ReservasBin.c      # Operações de reserva em binário
├── reservasTXT.c      # Operações de reserva em texto
├── structs.h          # Definições de estruturas principais
├── funcoes.h          # Protótipos de funções utilitárias
├── menu.h             # Protótipos do menu
├── memoria.h          # Protótipos de gerenciamento de memória
├── ArquivosBin.h      # Protótipos de leitura/escrita binária
├── arquivosTXT.h      # Protótipos de leitura/escrita texto
├── ReservasBin.h      # Protótipos de operações de reserva binária
├── reservasTXT.h      # Protótipos de operações de reserva texto
└── README.md          # Documentação do projeto
```

## Compilação

### Codigo para compilar no terminal

```bash
gcc main.c menu.c funcoes.c memoria.c ArquivosBin.c arquivosTXT.c ReservasBin.c reservasTXT.c -o hotel_manager -std=c99 -I.
```
---

## Execução

Após compilar, execute:

```bash
./hotel_manager
```

Você será guiado por menus para escolher entre operações de cadastro, reservas, transações, feedback e importação/exportação.

---

## Como Utilizar

1. **Login e Permissões**: O primeiro operador cadastrado ganha todas as permissões. Operadores subsequentes podem ter permissões personalizadas.
2. **Escolha de Persistência**: O sistema permite alternar entre salvar os dados em arquivos texto (`.txt`) ou binários (`.bin`).
3. **Navegação por Menu**: Use as opções numéricas para navegar pelos módulos:

   * **Módulo de Cadastros**: hotel, operadores, hóspedes, produtos, fornecedores, categorias e acomodações.
   * **Módulo de Reservas**: criação, consulta e migração de reservas.
   * **Módulo de Transações**: controle de vendas, contas a receber, contas a pagar, fluxo de caixa.
   * **Módulo de Feedback**: cadastro e análise de feedback de clientes.
   * **Módulo de Importação/Exportação**: backup e restauração de dados.

---

## Módulos Principais

* **structs.h**: definições de estruturas para hotel, operador, hóspede, produto, fornecedor, categoria, acomodação, reserva e financeiro.
* **ArquivosBin.c / arquivosTXT.c**: funções de *serialize*/*deserialize* para BIN e TXT.
* **reservasTXT.c / ReservasBin.c**: lógica específica para reservas.
* **funcoes.c**: buscas de registros, validações de código único.
* **menu.c**: implementação da interface de usuário por console.
* **memoria.c**: uso de memória dinâmica para armazenar dados em RAM.

---

## Contribuição

Contribuições são bem-vindas! Para colaborar:

1. Faça um *fork* do repositório.
2. Crie uma *branch* com sua feature: `git checkout -b feature/nome-da-feature`.
3. Faça *commit* das suas alterações: `git commit -m 'Adiciona ...'`.
4. Envie para o *branch* original: `git push origin feature/nome-da-feature`.
5. Abra um *Pull Request*.

---

