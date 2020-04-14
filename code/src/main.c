#include "../include/doublyLinkedList.h"
#include "../include/functionsAux.h"
#include "../include/binaryTree.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/const.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#if defined (__MINGW32__) || defined (_MSC_VER) || defined(_WIN32) || defined(WIN32)
    #ifndef WINDOWS_OS
        #define WINDOWS_OS
        #include <conio.h>
        #define limparTela() system("cls")
        #define redimensionarTela() system("MODE con cols=46 lines=37")
    #endif
#else
    #ifndef OTHERS_OS
        #define OTHERS_OS
        #include "../include/getch.h"
        #define redimensionarTela() system("clear")
        #define limparTela() system("clear")
    #endif
#endif


int main(int argc, char const *argv[])
{
    int recursos_totais[QTY_POINTS];

    int altura_min_arvore = 0;
    int pontuacao_total = 0;
    int config_suits = 0;
    int god_mode = 0;
    int turno = 1;
    int hack = 0;

    char arquivo_tarefas[30];
    char opcao;

    Queue *tarefas = createQueue();
    Queue *tarefas_expiradas = createQueue();
    Queue *tarefas_concluidas = createQueue();

    List *mao = createList();
    List *mao_descarte = createList();

    Stack *descarte = createStack();
    Stack *baralho = createStack();

    Tree arvore = createTree();

    redimensionarTela();
    limparTela();
    setlocale(LC_CTYPE, "english");

    if (argc == 2 && strcmp(argv[1], ARGV_GOD_MODE) == 0)
        god_mode = 1;

    else if (argc == 2 && strcmp(argv[1], ARGV_SUITS) == 0)
        config_suits = 1;

    else if (argc == 3 && ((strcmp(argv[1], ARGV_SUITS) == 0 && strcmp(argv[2], ARGV_GOD_MODE) == 0) || (strcmp(argv[1], ARGV_GOD_MODE) == 0 && strcmp(argv[2], ARGV_SUITS) == 0)))
    {
        god_mode = 1;
        config_suits = 1;
    }

    else if (argc == 1);

    else
    {
        printf("\n So eh permitido o uso das flags:\n");
        printf("\n %9s  Usar GOD_MODE", ARGV_GOD_MODE);
        printf("\n %9s  Usar desenho dos naipes\n", ARGV_SUITS);
        printf("\n Precione qualquer tecla para sair.\n");

        getch();
        exit(1);
    }

    for (int i = 0; i < QTY_POINTS; i++)
        recursos_totais[i] = 0;

    preencherBaralho(mao, FILE_DECK);
    embaralhar(mao, baralho);
    comprarCartas(mao, baralho);

    selecionarDificuldade(arquivo_tarefas);
    preencherQuests(tarefas, arquivo_tarefas);

    do
    {
        desenharMesa(baralho, descarte, mao, tarefas, recursos_totais, turno, config_suits);

        do
        {
            opcao = getch(); /* davigc */ if (opcao == 'd'){opcao = getch();if (opcao == 'a'){opcao = getch();if (opcao == 'v'){opcao = getch();if (opcao == 'i'){opcao = getch();if (opcao == 'g'){opcao = getch();if (opcao == 'c'){recursos_totais[BONUS] += 5;hack = 1;break;}}}}}} 
                             /*  sair  */ else if (opcao == 's'){opcao = getch();if (opcao == 'a'){opcao = getch();if (opcao == 'i'){opcao = getch();if (opcao == 'r'){break;}}}}
        } while (!(opcao >= '1' && opcao <= '5'));

        limparTela();

        if (opcao == '1' && lenList(mao) > 1)
        {
            List *nova_mao = createList();

            do
            {
                desenharMao(mao, config_suits);
                printf("\n +--%s--+ +--%s--+ +--%s--+ +--%s--+ +--%s--+\n", (getElementList(mao, 0) == NULL) ? "XX" : "01", (getElementList(mao, 1) == NULL) ? "XX" : "02", (getElementList(mao, 2) == NULL) ? "XX" : "03", (getElementList(mao, 3) == NULL) ? "XX" : "04", (getElementList(mao, 4) == NULL) ? "XX" : "05");
                desenharMao(nova_mao, config_suits);
                printf("\n +--%s--+ +--%s--+ +--%s--+ +--%s--+ +--%s--+", (getElementList(nova_mao, 0) == NULL) ? "XX" : "01", (getElementList(nova_mao, 1) == NULL) ? "XX" : "02", (getElementList(nova_mao, 2) == NULL) ? "XX" : "03", (getElementList(nova_mao, 3) == NULL) ? "XX" : "04", (getElementList(nova_mao, 4) == NULL) ? "XX" : "05");

                printf("\n\n Realoque as cartas desejadas.");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '1' && opcao <= '5'));

                limparTela();

                if (opcao == '1' && getElementList(mao, 0) != NULL)
                {
                    insertLastList(nova_mao, getElementList(mao, 0) -> main_value);
                    removeIndexList(mao, 0);
                }
                else if (opcao == '2' && getElementList(mao, 1) != NULL)
                {
                    insertLastList(nova_mao, getElementList(mao, 1) -> main_value);
                    removeIndexList(mao, 1);
                }
                else if (opcao == '3' && getElementList(mao, 2) != NULL)
                {
                    insertLastList(nova_mao, getElementList(mao, 2) -> main_value);
                    removeIndexList(mao, 2);
                }
                else if (opcao == '4' && getElementList(mao, 3) != NULL)
                {
                    insertLastList(nova_mao, getElementList(mao, 3) -> main_value);
                    removeIndexList(mao, 3);
                }
                else if (opcao == '5' && getElementList(mao, 4) != NULL)
                {
                    insertLastList(nova_mao, getElementList(mao, 4) -> main_value);
                    removeIndexList(mao, 4);
                }
            } while (lenList(mao) > 0);

            removeList(mao);
            mao = nova_mao;
        }
        else if (opcao == '2' && lenList(mao) > 0)
        {
            int q_cartas_descarte = 0;
            mao_descarte = createList();

            do
            {
                desenharMao(mao, config_suits);
                printf("\n +--%s--+ +--%s--+ +--%s--+ +--%s--+ +--%s--+", (getElementList(mao, 0) == NULL) ? "XX" : "01", (getElementList(mao, 1) == NULL) ? "XX" : "02", (getElementList(mao, 2) == NULL) ? "XX" : "03", (getElementList(mao, 3) == NULL) ? "XX" : "04", (getElementList(mao, 4) == NULL) ? "XX" : "05");

                printf("\n\n Descarte as cartas desejadas (0 p/ sair).");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '0' && opcao <= '5'));

                if (opcao == '1' && getElementList(mao, 0) != NULL)
                {
                    Card aux_carta = getElementList(mao, 0) -> main_value;

                    insertLastList(mao_descarte, aux_carta);

                    insertElementStack(descarte, aux_carta);

                    removeIndexList(mao, 0);

                    addElementTree(arvore, aux_carta.value);
                }
                else if (opcao == '2' && getElementList(mao, 1) != NULL)
                {
                    Card aux_carta = getElementList(mao, 1) -> main_value;

                    insertLastList(mao_descarte, aux_carta);

                    insertElementStack(descarte, aux_carta);

                    removeIndexList(mao, 1);

                    addElementTree(arvore, aux_carta.value);
                }
                else if (opcao == '3' && getElementList(mao, 2) != NULL)
                {
                    Card aux_carta = getElementList(mao, 2) -> main_value;

                    insertLastList(mao_descarte, aux_carta);

                    insertElementStack(descarte, aux_carta);

                    removeIndexList(mao, 2);

                    addElementTree(arvore, aux_carta.value);
                }
                else if (opcao == '4' && getElementList(mao, 3) != NULL)
                {
                    Card aux_carta = getElementList(mao, 3) -> main_value;

                    insertLastList(mao_descarte, aux_carta);

                    insertElementStack(descarte, aux_carta);

                    removeIndexList(mao, 3);

                    addElementTree(arvore, aux_carta.value);
                }
                else if (opcao == '5' && getElementList(mao, 4) != NULL)
                {
                    Card aux_carta = getElementList(mao, 4) -> main_value;

                    insertLastList(mao_descarte, aux_carta);

                    insertElementStack(descarte, aux_carta);

                    removeIndexList(mao, 4);

                    addElementTree(arvore, aux_carta.value);
                }

                limparTela();
            } while (opcao != '0' && lenList(mao) > 0);
            opcao = ' ';

            q_cartas_descarte = lenList(mao_descarte);

            // adicionar pontuação de cada carta
            for (int i = 0; i < q_cartas_descarte; i++)
            {
                Card aux_carta = getElementList(mao_descarte, i) -> main_value;

                if (aux_carta.suit == 'C')
                    recursos_totais[HEARTS] += aux_carta.value;
                else if (aux_carta.suit == 'O')
                    recursos_totais[DIAMONDS] += aux_carta.value;
                else if (aux_carta.suit == 'P')
                    recursos_totais[CLUBS] += aux_carta.value;
                else if (aux_carta.suit == 'E')
                    recursos_totais[SPADES] += aux_carta.value;
            }
            // cálcular pontos extras
            if (q_cartas_descarte > 1)
                calcularPontuacaoExtra(mao_descarte, recursos_totais, config_suits);

            // deletar cartas descartadas
            removeList(mao_descarte);
        }
        else if (opcao == '3')
        {
            ElementQueue *atual = getElementQueue(tarefas);

            if (atual -> main_value.mostrar)
            {
                printf("%16sSEUS RECURSOS", " ");
                desenharRecursos(recursos_totais, config_suits);
                printf("\n\n%11sNESSESSARIO PARA CONCLUIR", " ");
                desenharTarefas(tarefas, 0, turno, config_suits);
                if (recursos_totais[HEARTS]   >= atual -> main_value.q_recursos_copas &&
                    recursos_totais[DIAMONDS] >= atual -> main_value.q_recursos_ouros &&
                    recursos_totais[CLUBS]    >= atual -> main_value.q_recursos_paus  &&
                    recursos_totais[SPADES]   >= atual -> main_value.q_recursos_espadas)
                {
                    printf("\n\n Deseja concluir essa missao (s/n)? ");

                    do
                    {
                        opcao = getch();
                    } while (!((opcao == 's' || opcao == 'S') ||
                               (opcao == 'n' || opcao == 'N')));

                    if (opcao == 's' || opcao == 'S')
                    {
                        recursos_totais[HEARTS] -= atual -> main_value.q_recursos_copas;
                        recursos_totais[DIAMONDS] -= atual -> main_value.q_recursos_ouros;
                        recursos_totais[CLUBS] -= atual -> main_value.q_recursos_paus;
                        recursos_totais[SPADES] -= atual -> main_value.q_recursos_espadas;

                        recursos_totais[BONUS] += atual -> main_value.premio_reembaralhar;

                        pontuacao_total += atual -> main_value.pontuacao * (atual -> main_value.prazo + atual -> main_value.turno - turno);

                        atual -> main_value.concluida = 1;
                        atual -> main_value.mostrar = 0;

                        insertElementQueue(tarefas_concluidas, atual -> main_value);
                        removeElementQueue(tarefas);
                    }
                }
                else
                {
                    printf("\n\n Sem recursos suficientes.\n\n Precione qualquer tecla para sair.");
                    getch();
                }
            }
            else
            {
                printf("\n\n Sem tarefas no momento.\n\n Precione qualquer tecla para sair.");
                getch();
            }

            limparTela();
        }
        else if (opcao == '4')
        {
            if (god_mode)
                recursos_totais[BONUS]++;
            if (recursos_totais[BONUS] <= 0)
            {
                printf("\n\n Sem recurso BONUS suficiente.\n\n Precione qualquer tecla para sair.");
                getch();
                limparTela();
                continue;
            }

            recursos_totais[BONUS]--;

            recolherCartas(mao, baralho, descarte);
            embaralhar(mao, baralho);
            comprarCartas(mao, baralho);

            printf("\n\n Reembaralhamento concluido com sucesso.\n\n Precione qualquer tecla para sair.");
            getch();
            limparTela();
        }
        else if (opcao == '5')
        {
            turno++;

            for (ElementQueue *aux = tarefas -> first; aux != NULL; aux = aux -> previous)
            {
                if (aux -> main_value.turno == turno)
                    aux -> main_value.mostrar = 1;
                else if (aux -> main_value.turno + aux -> main_value.prazo == turno)
                    aux -> main_value.mostrar = 0;
            }

            for (ElementQueue *aux = tarefas -> first; aux != NULL && !(aux -> main_value.mostrar); aux = aux -> previous)
            {
                if (aux -> main_value.concluida)
                    insertElementQueue(tarefas_concluidas, aux -> main_value);
                else
                    insertElementQueue(tarefas_expiradas, aux -> main_value);

                removeElementQueue(tarefas);
            }

            // completar cartas da mão
            comprarCartas(mao, baralho);
        }

        // finalizar jogo se as tarefas terminarem
        if (lenQueue(tarefas) == 0 || opcao == 'r')
            break;
    } while (opcao != '0');

    if (!hack && !god_mode) // só calcular a pontuação final e mostrar se n usar HACK e GOD MODE
    {
        altura_min_arvore = heightMinTree(arvore);

        for (int i = 0; i < QTY_POINTS - 1; i++) // somar os recursos (- BONUS) e dividir por 2 
            pontuacao_total += recursos_totais[i] / 2;

        pontuacao_total *= altura_min_arvore;

        for (ElementQueue *aux = tarefas_expiradas -> first; aux != NULL; aux = aux -> next) // retirar os pontos das tarefas não concluídas
            pontuacao_total -= aux -> main_value.pontuacao;

        printf("\n\n%17sFIM DE JOGO!\n\n%10sPontuacao alcancada: %05d.\n\n%6sPrecione qualquer tecla para sair.", " ", " ", pontuacao_total, " ");
        getch();

        limparTela();
    }

    return 0;
}
