#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char answer[100] = "";

struct message {
    char message[100];
};

struct message msg[] = {
    {"Olá! Seja bem-vindo(a) a minha interação!\n"},
    {"Por favor, informe seu nome para que possamos começar.\n"},
    {"Digite seu nome: "},
    {"Por favor, digite um nome válido.\n"},
    {"Está preparado para começar nossa imersão? (S / N)\n"},
    {"Então vamos embarcar nessa jornada, espero que se divirta!"},
    {"Você ainda não está preparado para nossa imersão? Em que podemos ajudar para sua progressão?\n"},
    {"Aqui estão suas opções: \n1. Alterar meu nome\n2. Encerre a imersão\n"} // 7
};

int main() {
    system("cls");
    //Apresentação da interação.
    CaracterByCaracter(msg[0].message);
    CaracterByCaracter(msg[1].message);

    char name[100];
    while (1) {
        CaracterByCaracter(msg[2].message);
        scanf("%99s", name);

        int validName = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i])) {
                CaracterByCaracter(msg[3].message);
                validName = 0;
                break;
            }
        }
        if (validName == 1) {
            break;
        }
    }
    // Iniciando a interação.
    char greeting[100];
    sprintf(greeting,"Olá, %s! ", name);
    CaracterByCaracter(greeting);
    CaracterByCaracter(msg[4].message);
    scanf("%99s", answer);

    if (strcasecmp(answer, "sim") == 0 || strcasecmp(answer, "s") == 0) {
        CaracterByCaracter(msg[5].message);
    }
    else {
        memset(answer, 0, sizeof(answer));
        CaracterByCaracter(msg[6].message);
        CaracterByCaracter(msg[7].message);
        if (strcmp(answer, "1") == 0 || strcmp(answer, "Alterar meu nome") == 0) {
            printf("OK!");
        }
    }
}

void CaracterByCaracter(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(50000);
    }
}
