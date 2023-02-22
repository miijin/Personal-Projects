#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Variáveis Globais
char answer[100] = "";
int validAnswer = 1;

struct message {
    char message[1000];
};

struct message msg[] = {
    {"Olá! Seja bem-vindo(a) a nossa interação!\n"}, // 0
    {"Por favor, informe seu nome de exibição para que possamos começar.\n"}, // 1
    {"Digite seu nome de exibição: "}, // 2
    {"Por favor, digite um nome válido.\n"}, // 3
    {"Está preparado para começar nossa imersão? (\033[32mSim\033[0m / \033[31mNão\033[0m)\n"}, // 4
    {"Então vamos embarcar nessa jornada, espero que se divirta!\n"}, // 5
    {"Você ainda não está preparado? Em que podemos ajudar para sua progressão?\n"}, // 6
    {"Aqui estão suas opções: \n1. Alterar meu nome\n2. \033[31mEncerre a imersão\033[0m\n"}, // 7
    {"Você deseja encerrar a interação? Tudo bem, te vejo na próxima!"}, // 8
    {"OK! Tudo pronto para começar nossa interação! Vamos começar!"}, // 9
    {"Esse projeto foi criado no intuito de proporcionar uma experiência interativa ao usuário.\n"}, // 10
    {"O desenvolvedor desse projeto sou eu, \033[1;33mKennedy Miyake\033[0m.\nEsse é meu primeiro grande projeto, com base em todos meus aprendizados em programação.\n"}, // 11
    {"Estou focando ao máximo pela melhor experiência do usuário.\nEspero que realmente goste e aproveite a minha interação!\n"} //12
};

int main() {
    system("cls");

    // Iniciando a apresentação
    CaracterByCaracter(msg[0].message);
    CaracterByCaracter(msg[1].message);

    // Usuário define seu nome de exibição.
    char displayName[100];
    nameAndRename(displayName);
    clear();
    char greeting[100];
    sprintf(greeting,"Olá, %s! ", displayName);
    CaracterByCaracter(greeting);
    CaracterByCaracter(msg[4].message);

    while (1) {
        printf("%s: ", displayName);
        scanf("%99s", answer);
        validAnswer = 1;

        // Alternativas escolhidas pelo usuário.
        if (strcasecmp(answer, "sim") == 0 || strcasecmp(answer, "s") == 0) {
            CaracterByCaracter(msg[5].message);
            break;
        }
        else if (strcasecmp(answer, "não") == 0 || strcasecmp(answer, "n") == 0) {
            clear();
            memset(answer, 0, sizeof(answer));
            CaracterByCaracter(msg[6].message);
            CaracterByCaracter(msg[7].message);
            while (1) {
                validAnswer = 1;
                printf("%s: ", displayName);
                scanf("%99s", answer);

                // Usuário redefinindo seu nome de exibição.
                if (strcmp(answer, "1") == 0) {
                    clear();
                    nameAndRename(displayName);
                    clear();
                    char resetName[100];
                    sprintf(resetName, "Você redefiniu seu nome para \"%s\".\nDeseja continuar ou redefinir novamente?\n1. Continuar\n2. Redefinir novamente\n", displayName);
                    CaracterByCaracter(resetName);
                    memset(answer, 0, sizeof(answer));
                    while (1) {
                        validAnswer = 1;
                        printf("%s: ", displayName);
                        scanf("%99s", answer);
                        if (strcasecmp(answer, "1") == 0) {
                            clear();
                            CaracterByCaracter(msg[9].message);
                            break;
                        }
                        else if (strcasecmp(answer, "2") == 0) {
                            clear();
                            nameAndRename(displayName);
                            CaracterByCaracter(msg[9].message);
                            break;
                        }
                        else {
                            printf("Não compreendi sua resposta. Por favor, digite novamente\n");
                            validAnswer = 0;
                        }
                        if (validAnswer == 1) {
                            break;
                        }
                    }
                }
                else if (strcmp(answer, "2") == 0) {
                    clear();
                    CaracterByCaracter(msg[8].message);
                    clear();
                    return 1;
                }
                else {
                    printf("Não compreendi sua resposta. Por favor, digite novamente\n");
                    validAnswer = 0;
                }
                if (validAnswer == 1) {
                    break;
                }
            }
        }
        else {
            printf("Não compreendi sua resposta. Por favor, digite novamente\n");
            validAnswer = 0;
        }
        if (validAnswer == 1) {
            break;
        }
    }
    memset(answer, 0, sizeof(answer));
    // Encerrando a apresentação
    clear();
    waitingMoment();
    clear();

    // Apresentando a interação
    char introducing[100];
    sprintf(introducing, "Olá %s! Que bom que você chegou até aqui!\nVamos começar com uma pequena apresentação sobre o projeto!", displayName);
    CaracterByCaracter(introducing);
    sleep(1);
    clear();
    CaracterByCaracter(msg[10].message);
    CaracterByCaracter(msg[11].message);
    CaracterByCaracter(msg[12].message);
    sleep(1);
    // Encerrando a apresentação da interação
    clear();
    waitingMoment();
    clear();

    // Painel principal
    
}

// Funções adicionadas
void CaracterByCaracter(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(50000);
    }
}

void nameAndRename(char *name) {
    memset(name, 0, sizeof(name));
    while (1) {
        CaracterByCaracter(msg[2].message);
        scanf("%99s", name);
        validAnswer = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                CaracterByCaracter(msg[3].message);
                validAnswer = 0;
                break;
            }
        }
        if (validAnswer == 1) {
            break;
        }
    }
}

void waitingMoment() {
    char waiting[100] = "Carregando";
    CaracterByCaracter(waiting);

    int dots = 0;
    for (int i = 0; i < 15; i++) {
        printf(".");
        fflush(stdout);
        usleep(200000);
        dots++;
        if (dots == 3) {
            dots = 0;
            printf("\rCarregando   ");
            fflush(stdout);
            usleep(250000);
            printf("\rCarregando");
        }
    }
}

void clear() {
    usleep(200000);
    system("cls");
}