#ifndef QUEST_H
#define QUEST_H

typedef struct quest
{
    int turno;               // Turno de aparecimento
    int prazo;               // Prazo para ser cumprida
    int q_recursos_paus;     // Recursos de paus demandados
    int q_recursos_espadas;  // Recursos de espadas demandados
    int q_recursos_ouros;    // Recursos de ouros demandados
    int q_recursos_copas;    // Recursos de copas demandados
    int premio_reembaralhar; // Prêmios de reembaralhamento
    int mostrar;             // Mostrar ou não na tela - 1 = mostrar : 0 = não mostrar
    int concluida;           // Saber se foi concluída ou não - 1 = concluída : 0 = não concluída
    int pontuacao;           // Soma dos pontos totais para a conclusao das tarefas
} Quest;

#endif
