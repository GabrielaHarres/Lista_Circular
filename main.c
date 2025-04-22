#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "playlist.h"

void limpar_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Playlist* pl = nova_playlist();
    int opcao;
    char titulo[100], artista[100];
    int duracao;

    inserir_musica(pl, "Dynamite", "BTS", 7);
    inserir_musica(pl, "Boy With Luv", "BTS", 7);
    inserir_musica(pl, "Gimme Chocolate!!!", "Babymetal", 7);
    inserir_musica(pl, "Cosmic", "RedVelvet", 7);
    inserir_musica(pl, "Psycho", "RedVelvet", 7);

    do {
        printf("\n===== MENU PLAYLIST =====\n");
        printf("1. Adicionar musica\n");
        printf("2. Remover musica\n");
        printf("3. Proxima musica\n");
        printf("4. Musica anterior\n");
        printf("5. Alternar repeticao\n");
        printf("6. Listar musicas\n");
        printf("7. Buscar musica\n");
        printf("8. Exibir musica atual\n");
        printf("9. Tocar (simulacao)\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_input();

        switch (opcao) {
            case 1:
                printf("Titulo: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                printf("Artista: ");
                fgets(artista, sizeof(artista), stdin);
                artista[strcspn(artista, "\n")] = '\0';
                printf("Duracao: ");
                scanf("%d", &duracao);
                limpar_input();
                inserir_musica(pl, titulo, artista, duracao);
                break;
            case 2:
                printf("Remover titulo: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                excluir_musica(pl, titulo) ? printf("Removida.\n") : printf("Nao encontrada.\n");
                break;
            case 3:
                avancar_musica(pl);
                break;
            case 4:
                retroceder_musica(pl);
                break;
            case 5:
                toggle_repetir(pl);
                printf("Repetir %s\n", pl->repetir ? "ATIVADO" : "DESATIVADO");
                break;
            case 6:
                mostrar_musicas(pl);
                break;
            case 7:
                printf("Buscar por titulo: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                Musica* m = encontrar_musica(pl, titulo);
                if (m) printf("Encontrada: %s | %s | %ds\n", m->titulo, m->artista, m->duracao);
                else printf("Nao encontrada.\n");
                break;
            case 8:
                mostrar_atual(pl);
                break;
            case 9:
                if (!pl->atual) {
                    printf("Playlist vazia.\n");
                    break;
                }
                printf("Tocando... (Ctrl+C para parar)\n");
                while (1) {
                    Musica* tocando = pl->atual;
                    for (int i = 1; i <= tocando->duracao; i++) {
                        printf("\rTocando: %s [%d/%d seg]", tocando->titulo, i, tocando->duracao);
                        fflush(stdout);
                        sleep(1);
                    }
                    printf("\n");
                    if (!pl->repetir) avancar_musica(pl);
                    mostrar_atual(pl);
                }
                break;
        }
    } while (opcao != 0);

    destruir_playlist(pl);
    return 0;
}
