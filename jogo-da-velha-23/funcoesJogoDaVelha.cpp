#include <iostream>
#include <string>
#include "funcoesJogoDaVelha.h"

using namespace std;

void exibeInstrucoes(){

    cout << "Mapa de Posicoes\n";
    cout << "7\t8\t9\n";
    cout << "4\t5\t6\n";
    cout << "1\t2\t3\n";

}




int vencer(char tab[DIM][DIM]){

    // Retorna 1 se X vencer e 2 se O vencer

    // CONFERE LINHAS PARA X
    for (int linhas = 0; linhas < DIM; ++linhas) {
        if (tab[linhas][0] == 'X' && tab[linhas][0] == tab[linhas][1] && tab[linhas][1] == tab[linhas][2]){
            return 1;
        }
    }
    // CONFERE LINHAS PARA O
    for (int linhas = 0; linhas < DIM; ++linhas) {
        if (tab[linhas][0] == 'O' && tab[linhas][0] == tab[linhas][1] && tab[linhas][1] == tab[linhas][2]){
            return 2;
        }
    }
    // CONFERE COLUNAS PARA X
    for (int colunas = 0; colunas < DIM; ++colunas) {
        if (tab[0][colunas] == 'X' && tab[0][colunas] == tab[1][colunas] && tab[1][colunas] == tab[2][colunas]){
            return 1;
        }
    }
    // CONFERE COLUNAS PARA O
    for (int colunas = 0; colunas < DIM; ++colunas) {
        if (tab[0][colunas] == 'O' && tab[0][colunas] == tab[1][colunas] && tab[1][colunas] == tab[2][colunas]){
            return 2;
        }
    }
    // VERIFICANDO DIAGONAL PRINCIPAL
    if (tab[0][0] != '-' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]){
        if (tab[0][0] == 'X'){
            return 1;
        } else if (tab[0][0] == 'O'){
            return 2;
        }
    }
    // VERIFICANDO DIAGONAL SECUNDARIA
    if (tab[0][2] != '-' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]){
        if (tab[0][2] == 'X'){
            return 1;
        } else if (tab[0][2] == 'O'){
            return 2;
        }
    }
    return 0;
}





void iniciaTab(char tab[DIM][DIM]){

    for (int linExib = 0; linExib < DIM; ++linExib) {
        for (int colExib = 0; colExib < DIM; ++colExib) {
            tab[linExib][colExib] = '-';
            // Atribui '-' aos espaços vazios do tabuleiro
        }
    }

}

void exibeTab(char tab[DIM][DIM]){

    for (int linExib = 0; linExib < DIM; ++linExib) {
        for (int colExib = 0; colExib < DIM; ++colExib) {
            cout << tab[linExib][colExib] << "      ";
        }
        cout << "\n";
    }
}



void jogo(string nome1, string nome2){


    char tablueiro[DIM][DIM];                         // Criando tabuleiro
    int linhaJogada, colunaJogada, estadoJogo = 1;
    int turnoPlayer = 1, totalRodadas = 1, opcaoRestart, posicaoJogada;                             // 1 é X e 2 é O
    string playerAtual;
    bool posicionouJogada = false;

    iniciaTab(tablueiro);
    int posicoes[9][2] = {{2,0}, {2,1}, {2, 2},{1,0}, {1,1}, {1,2},{0,0}, {0, 1}, {0,2}};


    while(totalRodadas <= 9 && estadoJogo == 1) {
        exibeTab(tablueiro);
        cout << "    RODADA: " << totalRodadas << "\n";

        if (turnoPlayer == 1){
            playerAtual = nome1;
        } else{
            playerAtual = nome2;
        }


        while (posicionouJogada == false) {
            cout << playerAtual << ", digite a posicao jogada: ";
            cin >> posicaoJogada;
            linhaJogada = posicoes[posicaoJogada-1][0];
            colunaJogada = posicoes[posicaoJogada-1][1];

            if (tablueiro[linhaJogada][colunaJogada] == 'X' || tablueiro[linhaJogada][colunaJogada] == 'O') {
                cout << "Posicao ja ocupada, tente novamente!\n";
            } else {
                posicionouJogada = true;
            }
        }


        if (turnoPlayer == 1) {
            tablueiro[linhaJogada][colunaJogada] = 'X';
            turnoPlayer = 2;
        } else{
            tablueiro[linhaJogada][colunaJogada] = 'O';
            turnoPlayer = 1;
        }

        if(vencer(tablueiro) == 1){
            cout << "O Jogador X venceu!\n";
            estadoJogo = 0;
        } else if(vencer(tablueiro) == 2){
            cout << "O Jogador O venceu!\n";
            estadoJogo = 0;
        }

        if (posicionouJogada == true) {
            totalRodadas++;
            posicionouJogada = false;
        }


    }
    exibeTab(tablueiro);
    cout << "FIM DE JOGO\n";
    cout << "Selecione uma Opcao\n";
    cout << "1. MENU INICIAL\n";
    cout << "2. REINICIAR\n";
    cout << "3. SAIR\n";
    cin >> opcaoRestart;

    if (opcaoRestart == 1) {
        menuInicial();
    }else if(opcaoRestart == 2){
        jogo(nome1, nome2);
    }else{
        exit(0);
    }


}





void menuInicial(){

    int opcaoEscolhidaUser = 0;
    string nomePlayer1, nomePlayer2;

    while(opcaoEscolhidaUser > 3 || opcaoEscolhidaUser < 1) {
        cout << "BEM VINDO AO JOGO";
        cout << "\n1. JOGAR";
        cout << "\n2. SOBRE";
        cout << "\n3. SAIR";
        cout << "\nDigite uma opcao e tecle ENTER:";
        cin >> opcaoEscolhidaUser;

        switch (opcaoEscolhidaUser) {
            case 1:
                // INICIA O JOGO
                cout << "Digite o nome do player 1:";
                cin >> nomePlayer1;
                cout << "Digite o nome do player 2:";
                cin >> nomePlayer2;
                jogo(nomePlayer1, nomePlayer2);
                break;
            case 2:
                cout << "created by: josue, dec 2023\n";
                break;
            case 3:
                exit(0);
                break;
        }
    }



}

