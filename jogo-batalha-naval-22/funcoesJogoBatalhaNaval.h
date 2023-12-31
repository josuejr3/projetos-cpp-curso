#define DIM 10
#include <iostream>
#include <string>

using namespace std;


void menuPrincipal();
void exibeTabuleiro(char tabuleiro[DIM][DIM]);
void revelaCasa(char mascara[DIM][DIM], int linhasUser, int colunasUser, int *pontos, string *mensagem);
void posicionaBarcos(char tabuleiro[DIM][DIM]);
void iniciaTabuleiro(char tabuleiro[DIM][DIM], char mascara[DIM][DIM]);
void jogo(string playerName);
