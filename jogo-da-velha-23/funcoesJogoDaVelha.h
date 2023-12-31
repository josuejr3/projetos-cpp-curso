#include <iostream>
#include <string>
#define DIM 3

using namespace std;

void menuInicial();
void jogo(string nome1, string nome2);
int vencer(char tab[DIM][DIM]);
void iniciaTab(char tab[DIM][DIM]);
void exibeTab(char tab[DIM][DIM]);
void exibeInstrucoes();