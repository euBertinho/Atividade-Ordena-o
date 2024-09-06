#include "ordenacao.hpp"

/* TODO: Implementar função */
bool ordenado(int a[], unsigned int t){
  for (int i = 1; i < t; i++){
    if (a[i] < a[i - 1]) {
      return false;
    }
  }
  return true;
}

/* TODO: Implementar função */
void selecao(int a[], unsigned int t){
  int min, aux;
  for(int i = 0; i < t-1; ++i ){
    min = i;
    for (int j = i+1; j < t; ++j){
      if (a[j] < a[min])
      min = j;
    }
    if (a[i] != a[min]){
      aux = a[i];
      a[i] = a[min];
      a[min] = aux;
    }
  }
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
  for (int i = 1; i < t; i++) {
    int x = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > x) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
  }
}

/* TODO: Implementar função */
void merge(int a[], int i1, int j1, int i2, int j2) {
    int* temp = new int[j2 - i1 + 1]; // Simplificando o cálculo do tamanho
    int i = i1, j = i2, k = 0;

    // Intercala os dois subarrays
    while (i <= j1 && j <= j2) {
        if (a[i] <= a[j]) // Alteração para garantir a estabilidade
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Copia os elementos restantes
    while (i <= j1)
        temp[k++] = a[i++];
    while (j <= j2)
        temp[k++] = a[j++];

    // Copia de volta para o array original
    for (i = i1, k = 0; i <= j2; i++, k++)
        a[i] = temp[k];

    delete[] temp;
};

void merge_sort(int a[], int primeiro, int ultimo) {
    if (primeiro < ultimo) {
        int meio = (primeiro + ultimo) / 2;
        // Ordena recursivamente as duas metades
        merge_sort(a, primeiro, meio);
        merge_sort(a, meio + 1, ultimo);
        // Mescla as duas metades ordenadas
        merge(a, primeiro, meio, meio + 1, ultimo);
    }
};
