#include "../include/functionsAux.h"
#include "../include/const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined (__MINGW32__) || defined (_MSC_VER) || defined(_WIN32) || defined(WIN32)
    #ifndef WINDOWS_OS
        #define WINDOWS_OS
        #define limparTela() system("cls")
        #include <conio.h>
    #endif
#else
    #ifndef OTHERS_OS
        #define OTHERS_OS
        #define limparTela() system("clear")
        #include "../include/getch.h"
    #endif
#endif

void selecionarDificuldade(char *arquivo)
{
    char opcao;
    
    printf("\n%6s+--------------------------------+", " ");
    printf("\n%6s|          DIFICULDADE           |", " ");
    printf("\n%6s+---+----------------------------+", " ");
    printf("\n%6s| F | Facil                      |", " ");
    printf("\n%6s| M | Medio                      |", " ");
    printf("\n%6s| D | Dificil                    |", " ");
    printf("\n%6s| B | Brutal                     |", " ");
    printf("\n%6s+---+----------------------------+", " ");

    do
    {
        opcao = getch();
    } while (!((opcao == 'f' || opcao == 'F') ||
               (opcao == 'm' || opcao == 'M') ||
               (opcao == 'd' || opcao == 'D') ||
               (opcao == 'b' || opcao == 'B')));

    if (opcao == 'f' || opcao == 'F')
        strcpy(arquivo, FILE_QUESTS_EASY);
    else if (opcao == 'm' || opcao == 'M')
        strcpy(arquivo, FILE_QUESTS_MEDIUM);
    else if (opcao == 'd' || opcao == 'D')
        strcpy(arquivo, FILE_QUESTS_HARD);
    else if (opcao == 'b' || opcao == 'B')
        strcpy(arquivo, FILE_QUESTS_BRUTAL);
    
    limparTela();
}

void desenharMesa(Stack *baralho, Stack *baralho_descarte, List *mao, Queue *tarefas, int *recursos, int turno, int config_suits)
{
    printf("%14sRECURSOS", " ");
    desenharRecursos(recursos, config_suits);
    printf("\n\n%14sTAREFAS", " ");
    desenharTarefas(tarefas, 1, turno, config_suits);
    printf("\n\n%18sTURNOS: %03d", " ", turno);
    printf("\n +------+%28s+------+", " ");
    printf("\n |%c=====|%28s|%s     |", 63, " ", (lenStack(baralho_descarte) == 0) ? " " : converteNaipe(getElementStack(baralho_descarte) -> main_value, config_suits));
    printf("\n |==%c%c==| %02d%22s%02d |  %s%s  |", 63, 63, lenStack(baralho), " ", lenStack(baralho_descarte), (lenStack(baralho_descarte) == 0) ? " " : (strcmp(getElementStack(baralho_descarte) -> main_value.face, "10") == 0) ? "" : "0", (lenStack(baralho_descarte) == 0) ? " " : getElementStack(baralho_descarte) -> main_value.face);
    printf("\n |=====%c|%28s|     %s|", 63, " ", (lenStack(baralho_descarte) == 0) ? " " : converteNaipe(getElementStack(baralho_descarte) -> main_value, config_suits));
    printf("\n +------+%28s+------+\n", " ");
    desenharMao(mao, config_suits);
    desenharMenu(recursos[BONUS], config_suits);
}

void desenharMenu(int bonus, int config_suits)
{
    printf("\n%6s+---+----------------------------+", " ");
    printf("\n%6s| 1 | Reposicionar Cartas        |", " ");
    printf("\n%6s| 2 | Descartar Cartas           |", " ");
    printf("\n%6s| 3 | Cumprir Tarefa             |", " ");
    printf("\n%6s| 4 | Reembaralhar Tudo (%s : %02d) |", " ", (config_suits) ? SUIT_BONUS : NO_SUIT_BONUS, bonus);
    printf("\n%6s| 5 | Finalizar Turno            |", " ");
    printf("\n%6s+---+----------------------------+", " ");
}

void desenharRecursos(int *recursos, int config_suits)
{
    printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
    printf("\n%5s| %03d | %03d | %03d | %03d |    | %03d |", " ", recursos[HEARTS], recursos[DIAMONDS], recursos[CLUBS], recursos[SPADES], recursos[BONUS]);
    printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
    if (config_suits)
        printf("\n%5s   %s     %s     %s     %s          %s   ", " ", SUIT_HEART, SUIT_DIAMOND, SUIT_CLUBS, SUIT_SPADE, SUIT_BONUS);
    else
        printf("\n%5s   C     O     P     E          *   ", " ");
}

void desenharMao(List *mao, int config_suits)
{
    ElementList *cards[] =
    {
        getElementList(mao, 0),
        getElementList(mao, 1),
        getElementList(mao, 2),
        getElementList(mao, 3),
        getElementList(mao, 4)
    };

    printf("\n +------+ +------+ +------+ +------+ +------+");
    printf("\n |%s     | |%s     | |%s     | |%s     | |%s     |", (cards[0] == NULL) ? " " : converteNaipe(cards[0] -> main_value, config_suits), (cards[1] == NULL) ? " " : converteNaipe(cards[1] -> main_value, config_suits), (cards[2] == NULL) ? " " : converteNaipe(cards[2] -> main_value, config_suits), (cards[3] == NULL) ? " " : converteNaipe(cards[3] -> main_value, config_suits), (cards[4] == NULL) ? " " : converteNaipe(cards[4] -> main_value, config_suits));
    printf("\n |  %s%s  | |  %s%s  | |  %s%s  | |  %s%s  | |  %s%s  |", (cards[0] == NULL) ? " " : (strcmp(cards[0] -> main_value.face, "10") == 0) ? "" : "0", (cards[0] == NULL) ? " " : cards[0] -> main_value.face, (cards[1] == NULL) ? " " : (strcmp(cards[1] -> main_value.face, "10") == 0) ? "" : "0", (cards[1] == NULL) ? " " : cards[1] -> main_value.face, (cards[2] == NULL) ? " " : (strcmp(cards[2] -> main_value.face, "10") == 0) ? "" : "0", (cards[2] == NULL) ? " " : cards[2] -> main_value.face, (cards[3] == NULL) ? " " : (strcmp(cards[3] -> main_value.face, "10") == 0) ? "" : "0", (cards[3] == NULL) ? " " : cards[3] -> main_value.face, (cards[4] == NULL) ? " " : (strcmp(cards[4] -> main_value.face, "10") == 0) ? "" : "0", (cards[4] == NULL) ? " " : cards[4] -> main_value.face);
    printf("\n |     %s| |     %s| |     %s| |     %s| |     %s|", (cards[0] == NULL) ? " " : converteNaipe(cards[0] -> main_value, config_suits), (cards[1] == NULL) ? " " : converteNaipe(cards[1] -> main_value, config_suits), (cards[2] == NULL) ? " " : converteNaipe(cards[2] -> main_value, config_suits), (cards[3] == NULL) ? " " : converteNaipe(cards[3] -> main_value, config_suits), (cards[4] == NULL) ? " " : converteNaipe(cards[4] -> main_value, config_suits));
    printf("\n +------+ +------+ +------+ +------+ +------+");
}

int desenharTarefas(Queue *q, int completo, int turno, int config_suits)
{
    int cont_tarefas_ativas = 0;
    for (ElementQueue *aux = q -> first; aux != NULL; aux = aux -> previous)
    {
        Quest current = aux -> main_value;
        if (current.mostrar)
        {
            cont_tarefas_ativas++;
            printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
            printf("\n%5s| %03d | %03d | %03d | %03d |    | %03d |", " ", current.q_recursos_copas, current.q_recursos_ouros, current.q_recursos_paus, current.q_recursos_espadas, current.prazo + current.turno - turno);
            printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
            if (!completo)
                break;
        }
    }

    if (cont_tarefas_ativas == 0)
    {
        printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
        printf("\n%5s|     |     |     |     |    |     |", " ");
        printf("\n%5s+-----+-----+-----+-----+    +-----+", " ");
    }

    if (config_suits)
        printf("\n%5s   %s     %s     %s     %s        PRAZO   ", " ", SUIT_HEART, SUIT_DIAMOND, SUIT_CLUBS, SUIT_SPADE);
    else
        printf("\n%5s   C     O     P     E        PRAZO   ", " ");

    return cont_tarefas_ativas;
}

void adicionarRecursos(int *recursos_totais, int quantidade, int config_suits)
{
    char opcao;

    printf("%19sRECURSOS", " ");
    desenharRecursos(recursos_totais, config_suits);
    printf("\n\n\n%13sVoce tem +%02d recursos", " ", quantidade);
    printf("\n%10saonde deseja adiciona-los?", " ");
    printf("\n%6s+---+----------------------------+", " ");
    printf("\n%6s| C | Copas                      |", " ");
    printf("\n%6s| O | Ouros                      |", " ");
    printf("\n%6s| P | Paus                       |", " ");
    printf("\n%6s| E | Espadas                    |", " ");
    printf("\n%6s+---+----------------------------+", " ");
    do
    {
        opcao = getch();
    } while (!((opcao == 'c' || opcao == 'C') ||
               (opcao == 'o' || opcao == 'O') ||
               (opcao == 'p' || opcao == 'P') ||
               (opcao == 'e' || opcao == 'E')));

    if (opcao == 'C' || opcao == 'c')
        recursos_totais[HEARTS] += quantidade;
    else if (opcao == 'O' || opcao == 'o')
        recursos_totais[DIAMONDS] += quantidade;
    else if (opcao == 'P' || opcao == 'p')
        recursos_totais[CLUBS] += quantidade;
    else if (opcao == 'E' || opcao == 'e')
        recursos_totais[SPADES] += quantidade;
    
    limparTela();
}

char *converteNaipe(Card carta, int config_suits)
{
    if (config_suits)
        return (carta.suit == 'C') ? SUIT_HEART :
               (carta.suit == 'O') ? SUIT_DIAMOND :
               (carta.suit == 'P') ? SUIT_CLUBS : SUIT_SPADE;
    
    return (carta.suit == 'C') ? "C" : (carta.suit == 'O') ? "O" : (carta.suit == 'P') ? "P" : "E";
}

int preencherQuests(Queue *q, char *arquivo)
{
    int q_tarefas = 0;
    Quest *tarefas = (Quest *) malloc(sizeof(Quest));
    Quest aux;
    
    FILE *f = fopen(arquivo, READ);
    if (f == NULL)
        return 0;
    
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%d %d %d %d %d %d %d", &tarefas[i].turno, &tarefas[i].prazo, &tarefas[i].q_recursos_paus, &tarefas[i].q_recursos_espadas, &tarefas[i].q_recursos_ouros, &tarefas[i].q_recursos_copas, &tarefas[i].premio_reembaralhar);

        tarefas[i].concluida = 0;
        tarefas[i].mostrar = 0;

        if (tarefas[i].turno == 1)
            tarefas[i].mostrar = 1;

        tarefas[i].pontuacao = tarefas[i].q_recursos_paus + tarefas[i].q_recursos_espadas + tarefas[i].q_recursos_ouros + tarefas[i].q_recursos_copas;
        
        i++;
        q_tarefas++;
        tarefas = (Quest *) realloc(tarefas, sizeof(Quest) * (q_tarefas + 1));
    }
    fclose(f);

    for (int bolha = 0; bolha < q_tarefas - 1; bolha++)
    {
        for (i = bolha + 1; i < q_tarefas; i++)
        {
            if (tarefas[i].turno < tarefas[bolha].turno)
            {
                aux = tarefas[bolha];
                tarefas[bolha] = tarefas[i];
                tarefas[i] = aux;
            }
        }
    }

    i = 0;
    while (i < q_tarefas)
    {
        insertElementQueue(q, tarefas[i]);
        i++;
    }

    return q_tarefas;
}

int preencherBaralho(List *mao, char *arquivo)
{
    FILE *f = fopen(arquivo, READ);
    Card carta;

    if (f == NULL)
        return 0;
    
    while (!feof(f))
    {
        fscanf(f, "%s %c %d %[^\n]s", carta.face, &carta.suit, &carta.value, carta.name);
        insertElementList(mao, carta, 0);
    }

    fclose(f);

    return 1;    
}

void embaralhar(List *mao, Stack *baralho)
{
    int tam_mao = lenList(mao);
    int sorteio;
    Card aux;

    srand(time(NULL));

    for (int i = tam_mao; i > 0; i--)
    {
        sorteio = rand() % i;
        aux = getElementList(mao, sorteio) -> main_value;
        removeIndexList(mao, sorteio);
        insertElementStack(baralho, aux);
    }
}

void recolherCartas(List *mao, Stack *baralho, Stack *descarte)
{
    Card aux;

    while (lenStack(baralho) != 0)
    {
        aux = getElementStack(baralho) -> main_value;
        removeElementStack(baralho);
        insertElementList(mao, aux, 0);
    }

    while (lenStack(descarte) != 0)
    {
        aux = getElementStack(descarte) -> main_value;
        removeElementStack(descarte);
        insertElementList(mao, aux, 0);
    }
}

void comprarCartas(List *mao, Stack *baralho)
{
    Card aux;

    while (lenList(mao) < 5 && lenStack(baralho) != 0)
    {
        aux = getElementStack(baralho) -> main_value;
        removeElementStack(baralho);
        insertElementList(mao, aux, -1);
    }
}

int calcularPontuacaoExtra(List *cartas_descartadas, int recursos_totais[], int config_suits)
{
    int tam_descarte = lenList(cartas_descartadas);

    ElementList *cartas[] = {
        getElementList(cartas_descartadas, 0),
        getElementList(cartas_descartadas, 1),
        getElementList(cartas_descartadas, 2),
        getElementList(cartas_descartadas, 3),
        getElementList(cartas_descartadas, 4),
    };

    if (tam_descarte == 5) // descarte 5 cartas
    {
        if (cartas[0] -> main_value.value == cartas[1] -> main_value.value &&
            cartas[0] -> main_value.value == cartas[2] -> main_value.value &&
            cartas[0] -> main_value.value == cartas[3] -> main_value.value) // quadra
        {
            adicionarRecursos(recursos_totais, FOUR_KIND, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value == cartas[1] -> main_value.value &&
                 cartas[0] -> main_value.value == cartas[2] -> main_value.value) // trinca
        {
            adicionarRecursos(recursos_totais, THREE_KIND, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value == cartas[1] -> main_value.value) // par
        {
            adicionarRecursos(recursos_totais, PAIR, config_suits);
            return 1;
        }
        
        if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
            cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value &&
            cartas[2] -> main_value.value + 1 == cartas[3] -> main_value.value &&
            cartas[3] -> main_value.value + 1 == cartas[4] -> main_value.value) // sequencia valor 5
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 5, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
                 cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value &&
                 cartas[2] -> main_value.value + 1 == cartas[3] -> main_value.value) // sequencia valor 4
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 4, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
                 cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value) // sequencia valor 3
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value) // sequencia valor 2
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 2, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
            cartas[1] -> main_value.suit == cartas[2] -> main_value.suit &&
            cartas[2] -> main_value.suit == cartas[3] -> main_value.suit &&
            cartas[3] -> main_value.suit == cartas[4] -> main_value.suit) // sequencia naipe 5
        {
            adicionarRecursos(recursos_totais, FLUSH * 5, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
                 cartas[1] -> main_value.suit == cartas[2] -> main_value.suit &&
                 cartas[2] -> main_value.suit == cartas[3] -> main_value.suit) // sequencia naipe 4
        {
            adicionarRecursos(recursos_totais, FLUSH * 4, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
                 cartas[1] -> main_value.suit == cartas[2] -> main_value.suit) // sequencia naipe 3
        {
            adicionarRecursos(recursos_totais, FLUSH * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit) // sequencia naipe 2
        {
            adicionarRecursos(recursos_totais, FLUSH * 2, config_suits);
            return 1;
        }

        return 0;
    }
    else if (tam_descarte == 4) // descarte 4 cartas
    {
        if (cartas[0] -> main_value.value == cartas[1] -> main_value.value &&
            cartas[0] -> main_value.value == cartas[2] -> main_value.value &&
            cartas[0] -> main_value.value == cartas[3] -> main_value.value) // quadra
        {
            adicionarRecursos(recursos_totais, FOUR_KIND, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value == cartas[1] -> main_value.value &&
                 cartas[0] -> main_value.value == cartas[2] -> main_value.value) // trinca
        {
            adicionarRecursos(recursos_totais, THREE_KIND, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value == cartas[1] -> main_value.value) // par
        {
            adicionarRecursos(recursos_totais, PAIR, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
            cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value &&
            cartas[2] -> main_value.value + 1 == cartas[3] -> main_value.value) // sequencia valor 4
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 4, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
                 cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value) // sequencia valor 3
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value) // sequencia valor 2
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 2, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
            cartas[1] -> main_value.suit == cartas[2] -> main_value.suit &&
            cartas[2] -> main_value.suit == cartas[3] -> main_value.suit) // sequencia naipe 4
        {
            adicionarRecursos(recursos_totais, FLUSH * 4, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
                 cartas[1] -> main_value.suit == cartas[2] -> main_value.suit) // sequencia naipe 3
        {
            adicionarRecursos(recursos_totais, FLUSH * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit) // sequencia naipe 2
        {
            adicionarRecursos(recursos_totais, FLUSH * 2, config_suits);
            return 1;
        }

        return 0;
    }
    else if (tam_descarte == 3) // descarte 3 cartas
    {
        if (cartas[0] -> main_value.value == cartas[1] -> main_value.value &&
            cartas[0] -> main_value.value == cartas[2] -> main_value.value) // trinca
        {
            adicionarRecursos(recursos_totais, THREE_KIND, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value == cartas[1] -> main_value.value) // par
        {
            adicionarRecursos(recursos_totais, PAIR, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value &&
            cartas[1] -> main_value.value + 1 == cartas[2] -> main_value.value) // sequencia valor 3
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value) // sequencia valor 2
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 2, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit &&
            cartas[1] -> main_value.suit == cartas[2] -> main_value.suit) // sequencia naipe 3
        {
            adicionarRecursos(recursos_totais, FLUSH * 3, config_suits);
            return 1;
        }
        else if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit) // sequencia naipe 2
        {
            adicionarRecursos(recursos_totais, FLUSH * 2, config_suits);
            return 1;
        }

        return 0;
    }
    else if (tam_descarte == 2) // descarte 2 cartas
    {
        if (cartas[0] -> main_value.value == cartas[1] -> main_value.value) // par
        {
            adicionarRecursos(recursos_totais, PAIR, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.value + 1 == cartas[1] -> main_value.value) // sequencia valor 2
        {
            adicionarRecursos(recursos_totais, STRAIGHT * 2, config_suits);
            return 1;
        }

        if (cartas[0] -> main_value.suit == cartas[1] -> main_value.suit) // sequencia naipe 2
        {
            adicionarRecursos(recursos_totais, FLUSH * 2, config_suits);
            return 1;
        }

        return 0;
    }

    return 0;
}
