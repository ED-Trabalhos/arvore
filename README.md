
# 🌳 Estudo e Implementação de Estruturas de Dados: Árvores

![Linguagem](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Contribuidores](https://img.shields.io/badge/Contributors-3-purple?style=flat-square)
![Tipo](https://img.shields.io/badge/Projeto-Acadêmico-blueviolet?style=flat-square)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow?style=flat-square)
![Licença](https://img.shields.io/badge/License-MIT-green?style=flat-square)
![Último Commit](https://img.shields.io/github/last-commit/ED-Trabalhos/arvore?style=flat-square)

Este repositório é dedicado ao estudo de seis tipos fundamentais da estrutura de dados "Árvore". Foram implementados dois tipos de árvore. Cada tipo de árvore está contido em sua própria pasta, demonstrando suas operações principais, características e casos de uso.

## 🌲 Estruturas Implementadas

O projeto está organizado nas seguintes pastas, cada uma contendo a implementação de um tipo de árvore específico:

1.  **[Árvore Binária de Busca (BST)](./bst/)** (`./bst/`)
    * Uma árvore binária onde o nó esquerdo contém uma chave menor que a do nó pai, e o nó direito contém uma chave maior. É eficiente para buscas, inserções e deleções em $O(\log n)$ em média.

2.  **Árvore AVL**
    * Uma BST autobalanceada. A diferença de altura entre as subárvores esquerda e direita (fator de balanceamento) de qualquer nó é no máximo 1. Garante operações em $O(\log n)$ no pior caso.

3.  **Árvore Rubro-Negra (Red-Black Tree)**
    * Outra BST autobalanceada que usa "cores" (vermelho ou preto) nos nós para garantir que o caminho mais longo da raiz até qualquer folha não seja mais que o dobro do caminho mais curto.

4.  **Árvore B (B-Tree)**
    * Uma generalização de árvores de busca projetada para otimizar o acesso em disco. É comumente usada em bancos de dados e sistemas de arquivos, pois minimiza o número de leituras de disco.

5.  **Trie (Árvore de Prefixos)**
    * Uma estrutura de árvore usada para armazenar coleções de strings. É altamente eficiente para buscas baseadas em prefixos, como em funcionalidades de *autocomplete*.

6.  **[Heap Binário (Binary Heap)](./binary-heap/)** (`./binary-heap/`)
    * Uma árvore binária completa que satisfaz a propriedade do heap (Min-Heap ou Max-Heap). É a estrutura de dados fundamental para implementar filas de prioridade.

## 🚀 Como Usar

Cada pasta (`bst`, `heap`) contém os arquivos de código-fonte e, possivelmente, um `README.md` específico com instruções sobre como compilar e executar os exemplos.

Para começar, clone este repositório:

```bash
git clone https://github.com/ED-Trabalhos/arvore
```

Navegue até a pasta da estrutura de dados de seu interesse:

```bash
# Exemplo
cd arvore/bst
```

Compile os arquivos:

```bash
gcc main.c arvore.c -o arvore
```

Por fim, execute o binário gerado:

```bash
./arvore
```

## 👩‍💻 Contribuidores

<table border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td align="center" valign="top">
      <a href="https://github.com/andreasgunther">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/113151524?v=4&w=100&h=100&fit=cover&mask=circle" 
             width="100px;" alt="Foto do Contribuidor 1"/>
        <br />
        <sub><b>Andreas Gunther</b></sub>
      </a>
    </td>
    <td align="center" valign="top">
      <a href="https://github.com/davicarvalh0">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/168906459?v=4&w=100&h=100&fit=cover&mask=circle" 
             width="100px;" alt="Foto do Contribuidor 2"/>
        <br />
        <sub><b>Davi Carvalho</b></sub>
      </a>
    </td>
    <td align="center" valign="top">
      <a href="https://github.com/Marcosmh7xb">
        <img src="https://images.weserv.nl/?url=avatars.githubusercontent.com/u/130499268?v=4&w=100&h=100&fit=cover&mask=circle" 
             width="100px;" alt="Foto do Contribuidor 3"/>
        <br />
        <sub><b>Marcos Henrique</b></sub>
      </a>
    </td>
  </tr>
</table>

## 📄 Licença

Este projeto é para fins educacionais. Sinta-se à vontade para usá-lo como referência. Licenciado sob a Licença MIT - veja o arquivo [LICENSE.md](LICENSE.md) para detalhes.