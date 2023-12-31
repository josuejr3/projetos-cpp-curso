#include <iostream>
#include <string>
#include "funcoesJogoBatalhaNaval.h"
#include <locale>
#include <time.h>

using namespace std;

void exibeTabuleiro(char tabuleiro[DIM][DIM]){

    // Criando cores
    //char blue[] = {0x1b, '[', '1', ';', '3', '5', 'm', 0};
    //cout << blue << "\n";


    int linhasTabuleiro, colunasTabuleiro;

    cout << "    ______________________\n";
    for (int i = 0; i < 10; ++i) {
        if (i == 0){
            cout << "      ";
        } else{
            cout << "|";
        }
        cout << i;
    }
    cout << "\n";
    cout << "    ----------------------\n";


    for (linhasTabuleiro = 0; linhasTabuleiro < DIM; linhasTabuleiro++) {
        cout << "| " << linhasTabuleiro << " | ";
        for (colunasTabuleiro = 0; colunasTabuleiro < DIM; colunasTabuleiro++) {
            cout << tabuleiro[linhasTabuleiro][colunasTabuleiro] << " ";
        }
        cout << "\n";
    }
}


void revelaCasa(char mascara[DIM][DIM], int linhasUser, int colunasUser, int *pontos, string *mensagem){

    switch (mascara[linhasUser][colunasUser]) {
        case 'B':
            *(pontos) += 10;
            *mensagem = "            Parabens!\n          Voce acertou!\n";
            break;
        case 'A':
            *(mensagem) = "\n      Voce acertou a agua\n             :/\n";
            break;
    }

    cout << "\n           PONTOS: " << *pontos << "\n";
    cout << *(mensagem);
    exibeTabuleiro(mascara);

}

void posicionaBarcos(char tabuleiro[DIM][DIM]){

    int linhasBarco, colunasBarco, barcosPosicionados = 0;

    while(barcosPosicionados < 10){
        linhasBarco = rand() % 10;
        colunasBarco = rand() % 10;

        if (tabuleiro[linhasBarco][colunasBarco] == 'A'){
            tabuleiro[linhasBarco][colunasBarco] = 'B';
            barcosPosicionados++;
        }

    }

}



void iniciaTabuleiro(char tabuleiro[DIM][DIM], char mascara[DIM][DIM]){

    int linhasTabuleiro, colunasTabuleiro;
    for (linhasTabuleiro = 0; linhasTabuleiro < DIM; linhasTabuleiro++) {
        for (colunasTabuleiro = 0; colunasTabuleiro < DIM; colunasTabuleiro++) {
            tabuleiro[linhasTabuleiro][colunasTabuleiro] = 'A';
            mascara[linhasTabuleiro][colunasTabuleiro] = '*';
        }
    }
}

void jogo(string playerName){

    // INICIA O TABULEIRO
    cout << "\n         BATALHA NAVAL";

    string mensagem;


    int estadoDeJogo = 1;
    int tentativas = 0;
    int maxTentivas = 5;
    int tentativasRestantes = maxTentivas-tentativas;

    // Define tabuleiro e mascara
    char tabuleiro [DIM][DIM];
    char mascaraTab[DIM][DIM];


    // Inicia tabuleiro e mascara
    iniciaTabuleiro(tabuleiro, mascaraTab);       // Passado como referência
    posicionaBarcos(tabuleiro);
    cout << "\n";
    exibeTabuleiro(tabuleiro);
    exibeTabuleiro(mascaraTab);

    // Posiciona barcos;
    //posicionaBarcos(tabuleiro);

    int pontos = 0;

    while(tentativas < maxTentivas){

        cout << "\n          TENTATIVAS\n         RESTANTES: " << maxTentivas - tentativas << "\n";

        int linhaUser = -1, colunaUser = -1;

        while((linhaUser < 0 || colunaUser < 0) || (linhaUser > 9 || colunaUser > 9)){
            cout << "\n"<< playerName <<" Digite uma linha  (0 - 9):";
            cin >> linhaUser;
            cout << playerName << " Digite uma coluna (0 - 9):";
            cin >> colunaUser;
        }

        mascaraTab[linhaUser][colunaUser]= tabuleiro[linhaUser][colunaUser];

        revelaCasa(mascaraTab, linhaUser, colunaUser, &pontos, &mensagem);
        tentativas++;

    }

    int opcoesEndGame;

    cout << "          FIM DE JOGO.\n";
    exibeTabuleiro(tabuleiro);
    cout << "\n1. JOGAR NOVAMENTE";
    cout << "\n2. MENU INICIAL";
    cout << "\n3. SAIR\n";
    cin >> opcoesEndGame;

    if (opcoesEndGame == 1){
        jogo(playerName);
    } else if(opcoesEndGame == 2){
        menuPrincipal();
;    } else{
        exit(0);
    }


}


void menuPrincipal() {

    int opcaoEscolhida = 0;
    string playerName;

    while (opcaoEscolhida < 1 || opcaoEscolhida > 3) {
        cout << "--BEM VINDO A BATALHA NAVAL--";
        cout << "\n1. JOGAR\n";
        cout << "2. SOBRE\n";
        cout << "3. SAIR\n";
        cout << "Digite uma opcao e tecle ENTER:";
        cin >> opcaoEscolhida;

        switch (opcaoEscolhida) {
            case 1:
                cout << "\nDigite seu nome:";
                cin >> playerName;
                jogo(playerName);
                break;
            case 2:
                cout << "\ncreated by: Josue\nDec, 2023\n\n";
                int newOp;
                cout << "1. RETORNAR AO MENU\n";
                cout << "2. SAIR\n";
                cout << "Digite a opcao desejada:";
                cin >> newOp;
                if (newOp == 1){
                    menuPrincipal();
                } else{
                    exit(0);
                }
                break;
            case 3:
                exit(0);
                break;
        }
    }
}














