#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>

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
    {"Estou focando ao máximo pela melhor experiência do usuário.\nEspero que realmente goste e aproveite a minha interação!\n"}, //12
    {"Bem, vamos começar primeiramente fazendo algumas personalização para seu painel.\n"}, // 13
    {"O que você você quer personalizar primeiro?\n1. Alterar a cor do nome\n2. Mudar a borda\n3. O que são essas configurações?\n"}, // 14
    {"Essas primeiras personalizações são para que o usuário se sinta na liberdade de ter o painel ao seu gosto pessoal.\n"}, // 15
    {"A primeira personalização é de nome, onde você poderá alterar a cor do seu nome para que seja exibido de forma mais clara para o usuário e diferenciar das demais falas.\n"}, //16
    {"A segunda personalização é de borda, onde o usuário poderá alterar a a borda e as cores do seu painel, onde será exibido após a configuração.\n"} //17
};

// Prototypes
void CaracterByCaracter(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(50000);
    }
}

void CBC(int indexMSG, struct message messageMSG[]) {
    char compactMSG[1000];
    memset(compactMSG, 0, sizeof(compactMSG));

    for (int i = 0; i < indexMSG; i++) {
        strcat(compactMSG, messageMSG[i].message);
    }
    // CaracterByCaracter Integrado
    for (int j = 0; j < strlen(compactMSG); j++) {
        printf("%c", compactMSG[j]);
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
            printf("\r%s   ", waiting);
            fflush(stdout);
            usleep(250000);
            printf("\r%s", waiting);
        }
    }
    cls();
}

void cls() {
    usleep(200000);
    system("cls");
}

int main() {
    system("cls");
    // Iniciando a apresentação
    CBC(2, msg);

    // Usuário define seu nome de exibição.
    char displayName[100];
    nameAndRename(displayName);
    cls();
    char greeting[100];
    sprintf(greeting,"Olá, %s! ", displayName);
    CaracterByCaracter(greeting);
    CBC(1, &msg[4]);

    while (1) {
        printf("%s: ", displayName);
        scanf("%99s", answer);
        validAnswer = 1;

        // Alternativas escolhidas pelo usuário.
        if (strcasecmp(answer, "sim") == 0 || strcasecmp(answer, "s") == 0) {
            cls();
            CBC(1, &msg[5]);
            break;
        }
        else if (strcasecmp(answer, "não") == 0 || strcasecmp(answer, "n") == 0) {
            cls();
            memset(answer, 0, sizeof(answer));
            CBC(2, &msg[6]);
            while (1) {
                validAnswer = 1;
                printf("%s: ", displayName);
                scanf("%99s", answer);

                // Usuário redefinindo seu nome de exibição.
                if (strcmp(answer, "1") == 0) {
                    cls();
                    nameAndRename(displayName);
                    cls();
                    char resetName[100];
                    sprintf(resetName, "Você redefiniu seu nome para \"%s\".\nDeseja continuar ou redefinir novamente?\n1. Continuar\n2. Redefinir novamente\n", displayName);
                    CaracterByCaracter(resetName);
                    memset(answer, 0, sizeof(answer));
                    while (1) {
                        validAnswer = 1;
                        printf("%s: ", displayName);
                        scanf("%99s", answer);
                        if (strcasecmp(answer, "1") == 0) {
                            cls();
                            CBC(1, &msg[9]);
                            break;
                        }
                        else if (strcasecmp(answer, "2") == 0) {
                            cls();
                            nameAndRename(displayName);
                            CBC(1, &msg[9]);
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
                    cls();
                    CBC(1, &msg[8]);
                    cls();
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
    cls();
    waitingMoment();

    // Apresentando a interação
    char introducing[100];
    sprintf(introducing, "Olá %s! Que bom que você chegou até aqui!\nVamos começar com uma pequena apresentação sobre o projeto!", displayName);
    CaracterByCaracter(introducing);
    sleep(1);
    cls();
    CBC(3, &msg[10]);
    sleep(1);
    // Encerrando a apresentação da interação
    cls();
    waitingMoment();

    // Painel principal (config)
    
    CBC(2, &msg[13]);
    printf("%s: ", displayName);
    scanf("%s", answer);
    if (strcmp(answer, "1") == 0) {
        // Alterar nome
        cls();
    }
    if (strcmp(answer, "2") == 0) {
        // Alterar borda
        cls();
    }
    if (strcmp(answer, "3") == 0) {
        // Sobre as personalizações
        cls();
        CBC(3, &msg[15]);
    }
}