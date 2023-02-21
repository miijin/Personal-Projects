#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char answer[100] = "";
int validAnswer = 1;

struct message {
    char message[100];
};

struct message msg[] = {
    {"Olá! Seja bem-vindo(a) a minha interação!\n"}, // 0
    {"Por favor, informe seu nome de exibição para que possamos começar.\n"}, // 1
    {"Digite seu nome de exibição: "}, // 2
    {"Por favor, digite um nome válido.\n"}, // 3
    {"Está preparado para começar nossa imersão? (S / N)\n"}, // 4
    {"Então vamos embarcar nessa jornada, espero que se divirta!"}, // 5
    {"Você ainda não está preparado para nossa imersão? Em que podemos ajudar para sua progressão?\n"},
    {"Aqui estão suas opções: \n1. Alterar meu nome\n2. Encerre a imersão\n"}, // 7
    {"Você deseja encerrar a interação? Tudo bem, te vejo na próxima!"} //8
};

int main() {
    system("cls");
    CaracterByCaracter(msg[0].message);
    CaracterByCaracter(msg[1].message);

    char displayName[100];
    nameAndRename(displayName);
    char greeting[100];
    sprintf(greeting,"Olá, %s! ", displayName);
    CaracterByCaracter(greeting);
    CaracterByCaracter(msg[4].message);

    while (1) {
        printf("%s: ", displayName);
        scanf("%99s", answer);
        validAnswer = 1;

        if (strcasecmp(answer, "sim") == 0 || strcasecmp(answer, "s") == 0) {
            CaracterByCaracter(msg[5].message);
            break;
        }
        else if (strcasecmp(answer, "não") == 0 || strcasecmp(answer, "n") == 0) {
            memset(answer, 0, sizeof(answer));
            CaracterByCaracter(msg[6].message);
            CaracterByCaracter(msg[7].message);
            printf("%s: ", displayName);
            scanf("%99s", answer);
            if (strcmp(answer, "1") == 0) {
                nameAndRename(displayName);
                char resetName[100];
                sprintf(resetName, "Você redefiniu seu nome para %s. Deseja continuar ou redefinir novamente?\n1. Continuar\n2. Redefinir novamente\n", displayName);
                CaracterByCaracter(resetName);
                memset(answer, 0, sizeof(answer));
                printf("%s: ", displayName);
                scanf("%99s", answer);
                if (strcasecmp(answer, "1") == 0) {
                    printf("Ok! Tudo pronto %s, agora vamos imergir na nossa interação!", displayName);
                    break;
                }
                else if (strcasecmp(answer, "2") == 0) {
                    nameAndRename(displayName);
                    printf("Ok! Tudo pronto %s, agora vamos imergir na nossa interação!", displayName);
                }
            }
            else if (strcmp(answer, "2") == 0) {
                CaracterByCaracter(msg[8].message);
                return 1;
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
    sleep(1);
    system("cls");
}

void CaracterByCaracter(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(0000);
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