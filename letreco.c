#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho_da_palavra 6
#define tamanho_real_da_palavra (tamanho_da_palavra - 1)
#define nome_do_arquivo "palavras.txt"

// Grupo 1
// Anderson da Silva
// Gabrielly Cristine
// Gustavo Alves
// Tiago Gabriel

int sortear_numero(int min, int max)
{
    srand(time(NULL));
    return (rand() % ((max + 1 - min) + min));
}

int contar_quantidade_de_palavras_no_arquivo()
{
    char palavras[tamanho_da_palavra];
    int numero_de_palavras = 0;

    FILE *arquivo = fopen(nome_do_arquivo, "r");
    while (fscanf(arquivo, "%s", palavras) != EOF)
    {
        numero_de_palavras++;
    }
    fclose(arquivo);
    return numero_de_palavras;
}

void gerar_palavra_aleatoria(char *palavra_do_jogo)
{
    int quantidade_de_palavras_no_arquivo = contar_quantidade_de_palavras_no_arquivo();
    int numero_aleatorio = sortear_numero(1, quantidade_de_palavras_no_arquivo);
    
    printf("\nHá %d palavras no jogo.", quantidade_de_palavras_no_arquivo);
    
    FILE *arquivo = fopen(nome_do_arquivo, "r");
    rewind(arquivo);
    for (int i = 0; i < numero_aleatorio; i++)
    {
        fscanf(arquivo, "%s", palavra_do_jogo);
    }
    fclose(arquivo);
}

// Grupo 2
// Alice Akaki
// Karolyne Muniz
// Luiz Henrique
// Maria Luiza

int checar_caractere_na_palavra(char *palavra_do_jogo, char caractere)
{
    int i = 0;

    while (palavra_do_jogo[i])
    {
        if (palavra_do_jogo[i] == caractere)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

void preencher_linha(char matriz[][tamanho_real_da_palavra], char *palavra_do_jogo, char *palavra_do_usuario, int linha)
{
    int i = 0;

    while (palavra_do_jogo[i])
    {
        if (palavra_do_jogo[i] == palavra_do_usuario[i])
        {
            matriz[linha][i] = palavra_do_usuario[i];
        }
        if (palavra_do_jogo[i] != palavra_do_usuario[i])
        {
            matriz[linha][i] = '+';
        }
        if (checar_caractere_na_palavra(palavra_do_jogo, palavra_do_usuario[i]) == 0)
        {
            matriz[linha][i] = '#';
        }
        i++;
    }
}

// Grupo 4
// Bruno McPherson
// João Guilherme
// João Pedro
// Thiago Paiva

void banner()
{
    printf("\n -------------------------------------------------  ");
    printf("\n|         ____ _______  ___   ____  ____  ____    |  ");
    printf("\n|  |     |        |    |   | |     |     |    |   |  ");
    printf("\n|  |     |____    |    |___| |____ |     |    |   |  ");
    printf("\n|  |     |        |    | \\   |     |     |    |   | ");
    printf("\n|  |____ |____    |    |  \\  |____ |____ |____|   | ");
    printf("\n|                                                 |  ");
    printf("\n ------------------------------------------------- ");
    printf("\n\nRegras:");
    printf("\n# (cerquilha) representa um caractere que não existe na palavra.");
    printf("\n+ (adição) representa um caractere que existe na palavra, porém está na posição errada.");
    printf("\nHá cinco tentativas para acertar uma palavra de cinco caracteres.");
}

int checar_tamanho_da_palavra(char *palavra_do_jogo)
{
    int i = 0;

    while (palavra_do_jogo[i] != '\0')
    {
        i++;
    }
    return i;
}

void ver_mascara_da_palavra(char palavra_do_jogo[])
{
    printf("\n ------------------------------------------------\n");
    printf("|");
    for (int i = 0; i < tamanho_real_da_palavra; i++)
    {
        printf("\t%c ", palavra_do_jogo[i]);
    }
    printf("       |");
    printf("\n ------------------------------------------------ ");
    printf("\n                                                   ");
    printf("\n");
}

// Grupo 5
// Deivison Lima
// Gabriel Sérgio
// Gustavo Klosinski
// Sandy Campos

int comparar_palavra(char *mascara, char *palavra_do_jogo, char *palavra_do_usuario)
{
    int cont = 0;

    for (int i = 0; i < tamanho_real_da_palavra; i++)
    {
        if (palavra_do_jogo[i] == palavra_do_usuario[i])
        {
            mascara[i] = palavra_do_jogo[i];
            cont++;
        }
    }
    return cont;
}

void preencher_mascara_da_matriz(char matriz[][tamanho_real_da_palavra])
{
    for (int i = 0; i < tamanho_real_da_palavra; i++)
    {
        for (int j = 0; j < tamanho_real_da_palavra; j++)
        {
            matriz[i][j] = '_';
        }
    }
}

// Extra
// William Cardoso

void ver_mascara_da_matriz(char matriz[][tamanho_real_da_palavra])
{
    for (int i = 0; i < tamanho_real_da_palavra; i++)
    {
        printf("\t");
        for (int j = 0; j < tamanho_real_da_palavra; j++)
        {
            printf("[ %c ] ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Grupo 3
// Gabriel Barros
// Guilherme Alves
// Ian Lavorente
// Kauã Reydisson

int main()
{
    char mascara[tamanho_da_palavra] = "_____";
    char *mascara_ptr = mascara;
    char matriz_de_palavras[tamanho_real_da_palavra][tamanho_real_da_palavra] = {};
    char palavra_do_jogo[tamanho_da_palavra] = "";
    char *palavra_do_jogo_ptr = palavra_do_jogo;
    char palavra_do_usuario[tamanho_da_palavra] = "";
    int numero_de_tentativas = 5;
    int tentativas_usadas = 1;

    banner();
    gerar_palavra_aleatoria(palavra_do_jogo_ptr);
    printf("\n");
    preencher_mascara_da_matriz(matriz_de_palavras);
    while (numero_de_tentativas > 0)
    {
        ver_mascara_da_palavra(mascara_ptr);
        ver_mascara_da_matriz(matriz_de_palavras);
        printf("\nEscreva uma palavra: ");
        scanf("%s", palavra_do_usuario);
        if (checar_tamanho_da_palavra(palavra_do_usuario) != 5)
        {
            printf("\nNúmero de letras diferente de cinco!");
            printf("\n");
            continue;
        }
        else
        {
            int cont = comparar_palavra(mascara, palavra_do_jogo, palavra_do_usuario);

            if (cont == tamanho_real_da_palavra)
            {
                printf("\nParabéns, você acertou! A palavra era: \"%s\".", palavra_do_jogo);
                printf("\nQuantidade de tentativas: %d", (tentativas_usadas - 1));
                printf("\n");
                break;
            }
            preencher_linha(matriz_de_palavras, palavra_do_jogo_ptr, palavra_do_usuario, (tentativas_usadas - 1));
        }
        numero_de_tentativas--;
        tentativas_usadas++;
    }
    return 0;
}