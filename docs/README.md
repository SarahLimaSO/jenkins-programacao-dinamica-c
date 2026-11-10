# Algoritmos de Programação Dinâmica

## Sobre o projeto

Este projeto foi desenvolvido como atividade acadêmica da disciplina de **Gerência de Configuração (GC)**, com foco na utilização do **Jenkins** para automação do processo de integração contínua (CI).

A proposta consiste em aplicar os conhecimentos da disciplina por meio da integração de ferramentas e práticas de engenharia de software, como versionamento, conteinerização, automação de builds, análise estática e testes automatizados. Além dos requisitos da atividade, foram incorporadas outras tecnologias com o objetivo de ampliar a experiência prática.

Para a implementação e validação dessas práticas, foi desenvolvido um programa em **C** que reúne métodos de algoritmos de Programação Dinâmica, aplicando conceitos de projeto e análise de algoritmos estudados na disciplina de Projeto e Análise de Algoritmos (PAA).

A implementação inicial contempla o algoritmo da **Maior Subsequência Comum (LCS – Longest Common Subsequence)**, que recebe duas strings e identifica uma subsequência de maior comprimento compartilhada entre elas, apresentando tanto o comprimento quanto os caracteres que compõem essa subsequência.

A solução utiliza programação dinâmica para armazenar resultados intermediários em uma matriz, evitando o recálculo de subproblemas e tornando a execução mais eficiente.

## Algoritmos implementados

### Maior Subsequência Comum (LCS)

O algoritmo LCS recebe duas strings e determina a maior subsequência comum entre elas, apresentando seu comprimento e uma das sequências de caracteres encontradas.

Uma subsequência é formada pela remoção de zero ou mais caracteres de uma string, sem alterar a ordem relativa dos caracteres restantes. Diferentemente de uma substring, seus caracteres não precisam estar em posições consecutivas.

**Exemplo:**

- String 1: `ABCBDAB`
- String 2: `BDCABA`
- Comprimento da LCS: `4`
- Uma possível subsequência comum: `BCBA`

**Abordagem utilizada:**

A solução utiliza programação dinâmica, construindo uma matriz que armazena os resultados dos subproblemas. Após o preenchimento da matriz, é realizado um procedimento de reconstrução para identificar os caracteres que compõem uma das maiores subsequências comuns. O resultado mostra uma das possíveis saídas para a maior subsequência comum entre as strings de entrada.

**Complexidade:**

- Tempo: \(O(m * n)\)
- Espaço: \(O(m * n)\)

Em que `m` e `n` representam os comprimentos das duas strings de entrada.

## Tecnologias e ferramentas

| Tecnologia | Finalidade |
|---|---|
| **C** | Linguagem utilizada na implementação dos algoritmos. |
| **GCC** | Compilador do código-fonte. |
| **CMake** | Configuração e gerenciamento do processo de build. |
| **CTest** | Execução e gerenciamento dos testes automatizados. |
| **Cppcheck** | Análise estática do código-fonte. |
| **Git** | Controle de versão do projeto. |
| **GitHub** | Hospedagem do repositório e gerenciamento do código-fonte. |
| **Jenkins** | Automação do processo de integração contínua (CI). |
| **Docker** | Conteinerização e padronização do ambiente de execução. |

## Gerência de Configuração

O desenvolvimento contempla a aplicação de práticas de Gerência de Configuração, com foco na organização, rastreabilidade e qualidade do software.

Entre as práticas adotadas estão:

- **Versionamento:** utilização do Git e GitHub para registrar e acompanhar as alterações do projeto.
- **Conteinerização:** utilização do Docker para padronizar o ambiente de desenvolvimento e execução.
- **Integração contínua:** utilização do Jenkins para automatizar as etapas de obtenção do código-fonte, análise estática, compilação e execução de testes.
- **Testes automatizados:** utilização do CTest para verificar o comportamento das implementações.
- **Análise estática:** utilização do Cppcheck para auxiliar na identificação de possíveis problemas no código-fonte.

## Como compilar e executar

O projeto oferece duas formas de compilação e execução: automatizada, por meio do Jenkins, e manual, utilizando CMake e Make.

### Pré-requisitos

Para compilar e executar o projeto manualmente, são necessárias as seguintes ferramentas:

- GCC
- CMake
- Make

Para executar as verificações de qualidade, também são utilizadas:

- CTest
- Cppcheck

Docker e Jenkins são utilizados nos processos automatizados e na padronização do ambiente.

### Execução automática (Jenkins)

O Jenkins é utilizado para automatizar o processo de integração contínua (CI), por meio de um pipeline definido no arquivo `Jenkinsfile`.

O pipeline está organizado em quatro etapas:

1. **Checkout:** obtém o código-fonte do repositório por meio do comando `checkout scm`.
2. **Análise estática:** executa o Cppcheck para identificar possíveis problemas no código-fonte localizado no diretório `src/`.
3. **Build:** configura o projeto com CMake e realiza a compilação dos arquivos.
4. **Test:** executa os testes automatizados configurados no CTest, apresentando os resultados e possíveis falhas.

A execução do pipeline permite verificar automaticamente a qualidade e a integridade do código durante o desenvolvimento.

### Execução manual

Para compilar e executar o projeto manualmente, siga os passos abaixo a partir da raiz do repositório.

**1. Crie a pasta `build` e acesse-a:**

```bash
mkdir build
cd build
```

**2. Configure o projeto com CMake:**

```bash
cmake ..
```

**3. Compile o código-fonte:**

```bash
make
```

**4. Execute o programa:**

```bash
./prog-dinamica
```

### Execução dos testes

Após configurar e compilar o projeto, execute os testes automatizados utilizando:

```bash
ctest --output-on-failure
```

Os testes são definidos no `CMakeLists.txt` e executados por meio do script `tests/executa_testes.sh`, que compara a saída do programa com os resultados esperados.

Atualmente, estão configurados três casos de teste:

- `teste_1`
- `teste_2`
- `teste_3`

### Análise estática

Para realizar a análise estática do código-fonte com Cppcheck, execute na raiz do projeto:

```bash
cppcheck --enable=warning src/
```

## Objetivos de aprendizagem

O desenvolvimento deste projeto busca consolidar conhecimentos em duas áreas principais:

**Projeto e Análise de Algoritmos (PAA)**

- Implementação de algoritmos utilizando programação dinâmica.
- Identificação e resolução de subproblemas.
- Análise de complexidade de tempo e espaço.

**Gerência de Configuração (GC)**

- Aplicação de versionamento.
- Automatização do processo de build e testes.
- Utilização de Docker para padronização de ambientes.
- Configuração de pipelines de integração contínua com Jenkins.
- Integração de ferramentas de análise estática e testes automatizados.

## Status do projeto

- **Versão atual:** algoritmo da Maior Subsequência Comum (LCS) implementado e funcional.

## Autor

**Sarah Lima**

Graduanda em Engenharia de Software pela Universidade Federal do Amazonas (UFAM).

Projeto desenvolvido como atividade acadêmica da disciplina de Gerência de Configuração (GC), integrando conhecimentos de engenharia de software, automação e desenvolvimento de algoritmos.