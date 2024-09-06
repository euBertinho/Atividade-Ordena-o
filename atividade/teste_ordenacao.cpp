#include <iostream>
#include <chrono>
#include "ordenacao.hpp"

const int SELECAO = 1;
const int INSERCAO = 2;
const int MERGE = 3;

void print_usage() {
  std::cout << "Programa para ordenação de números ineiros.\n\n";
  std::cout << "\tUso: teste_ordenacao [Opção]\n";
  std::cout << "\n";
  std::cout << "Onde 'Opção' é uma das opções a seguir:\n\n";
  std::cout << "\t -s: ordenação por seleção (padrão).\n";
  std::cout << "\t -i: ordenação por inserção.\n";
  std::cout << "\t -m: ordenação por merge-sort.\n";
  std::cout << "\t -h: Mostra instruções de uso de programa.\n\n";
}

int define_metodo(int argc, char** argv) {
  int metodo = SELECAO;
  if (argc > 2) {
    std::cout << "*** Quantidade de parâmetros inválidos *** \n\n";
    print_usage();
    exit(1);
  }
  if (argc == 2) {
    if (argv[1][0] != '-') {
      print_usage();
      exit(0);
    }
    else if (argv[1][1] == 's') {
      metodo = SELECAO;
    }
    else if (argv[1][1] == 'i') {
      metodo = INSERCAO;
    }
    else if (argv[1][1] == 'm') {
      metodo = MERGE;
    }
    else {
      print_usage();
      exit(2);
    }
  }
  return metodo;
}

void imprime_array(int a[], int n) {
  int i;
  if (n > 0) {
    std::cout << a[0];
    for (i = 1; i < n; ++i)
      std::cout << " " << a[i];
    std::cout << "\n";
  }
}

int main(int argc, char** argv) {
  int n, i, metodo = define_metodo(argc, argv);
  std::cin >> n;
  int a[n];
  for (i = 0; i < n; ++i)
    std::cin >> a[i];
  auto beg = std::chrono::high_resolution_clock::now();
  switch (metodo) {
  case SELECAO: selecao(a, n);
    break;
  case INSERCAO: insercao(a, n);
    break;
  case MERGE: merge_sort(a, 0, n-1);
    break;
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
  std::cerr << duration.count() << std::endl;
  if (not ordenado(a, n)) {
    std::cerr << "\033[0;31mErro:\033[0m Array não ordenado. Saindo...\n";
    exit(-1);
  }
  // imprime_array(a,n);
  return 0;
}
