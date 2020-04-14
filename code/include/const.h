#ifndef CONST_H
#define CONST_H

#define FILE_QUESTS_BRUTAL "./files/quests_brutal.txt" // Arquivo com todas as quests BRUTAIS
#define FILE_QUESTS_MEDIUM "./files/quests_medium.txt" // Arquivo com todas as quests MEDIAS
#define FILE_QUESTS_HARD   "./files/quests_hard.txt"   // Arquivo com todas as quests DIFICEIS
#define FILE_QUESTS_EASY   "./files/quests_easy.txt"   // Arquivo com todas as quests FACEIS
#define FILE_RECORDS       "./files/records.txt"       // Arquivo com todos os recordes
#define FILE_DECK          "./files/deck.txt"          // Arquivo com todas as cartas
#define APPEND             "a"                         // Modo de abertura do arquivo - anexo
#define WRITE              "w"                         // Modo de abertura do arquivo - escrita
#define READ               "r"                         // Modo de abertura do arquivo - leitura

#define FOUR_KIND  20 // pontuação quadra
#define THREE_KIND  5 // pontuação trinca
#define PAIR        2 // pontuação par
#define STRAIGHT    2 // pontuação sequência mesmo valor
#define FLUSH       3 // pontuação mesmo naipe

#define HEARTS   0 // Posição do recurso COPAS
#define DIAMONDS 1 // Posição do recurso OUROS
#define CLUBS    2 // Posição do recurso PAUS
#define SPADES   3 // Posição do recurso ESPADAS
#define BONUS    4 // Posição do recurso BONUS

#define QTY_CARDS      52 // Quantidade de cartas existentes no jogo
#define QTY_POINTS      5 // Quantidade de Recursos existentes
#define QTY_CARDS_HAND  5 // Quantidade de cartas possíveis na mão
#define QTY_SUITS       4 // Quantidade de naipes no jogo

#define ARGV_SUITS    "-suits=on"
#define ARGV_GOD_MODE "-gm=on"

#define SUIT_HEART   "♥"
#define SUIT_DIAMOND "♦"
#define SUIT_CLUBS   "♣"
#define SUIT_SPADE   "♠"
#define SUIT_BONUS   "Ð"

#define NO_SUIT_HEART   "C"
#define NO_SUIT_DIAMOND "O"
#define NO_SUIT_CLUB    "P"
#define NO_SUIT_SPADE   "E"
#define NO_SUIT_BONUS   "*"

#endif
