#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Playlist* nova_playlist() {
    Playlist* p = (Playlist*)malloc(sizeof(Playlist));
    p->atual = NULL;
    p->tamanho = 0;
    p->repetir = 0;
    return p;
}

void destruir_playlist(Playlist* p) {
    if (!p || !p->atual) {
        free(p);
        return;
    }

    Musica* m = p->atual->proxima;
    Musica* temp;

    while (m != p->atual) {
        temp = m;
        m = m->proxima;
        free(temp);
    }

    free(p->atual);
    free(p);
}

void inserir_musica(Playlist* p, const char* titulo, const char* artista, int duracao) {
    Musica* nova = (Musica*)malloc(sizeof(Musica));
    strncpy(nova->titulo, titulo, 99);
    strncpy(nova->artista, artista, 99);
    nova->titulo[99] = '\0';
    nova->artista[99] = '\0';
    nova->duracao = duracao;

    if (!p->atual) {
        nova->proxima = nova;
        p->atual = nova;
    } else {
        Musica* fim = p->atual;
        while (fim->proxima != p->atual) {
            fim = fim->proxima;
        }
        fim->proxima = nova;
        nova->proxima = p->atual;
    }
    p->tamanho++;
}

int excluir_musica(Playlist* p, const char* titulo) {
    if (!p->atual) return 0;

    Musica* m = p->atual;
    Musica* ant = NULL;

    do {
        if (strcmp(m->titulo, titulo) == 0) {
            if (!ant) {
                if (m->proxima == m) {
                    p->atual = NULL;
                } else {
                    Musica* fim = m;
                    while (fim->proxima != m) fim = fim->proxima;
                    p->atual = m->proxima;
                    fim->proxima = p->atual;
                }
            } else {
                ant->proxima = m->proxima;
                if (m == p->atual) p->atual = m->proxima;
            }
            free(m);
            p->tamanho--;
            return 1;
        }
        ant = m;
        m = m->proxima;
    } while (m != p->atual);

    return 0;
}

void avancar_musica(Playlist* p) {
    if (p->atual) p->atual = p->atual->proxima;
}

void retroceder_musica(Playlist* p) {
    if (!p->atual) return;

    Musica* anterior = p->atual;
    while (anterior->proxima != p->atual) {
        anterior = anterior->proxima;
    }
    p->atual = anterior;
}

void toggle_repetir(Playlist* p) {
    p->repetir = !p->repetir;
}

void mostrar_musicas(const Playlist* p) {
    if (!p->atual) {
        printf("Playlist vazia.\n");
        return;
    }

    Musica* m = p->atual;
    do {
        printf("Titulo: %s | Artista: %s | Duracao: %ds\n", m->titulo, m->artista, m->duracao);
        m = m->proxima;
    } while (m != p->atual);
}

Musica* encontrar_musica(const Playlist* p, const char* titulo) {
    if (!p->atual) return NULL;

    Musica* m = p->atual;
    do {
        if (strcmp(m->titulo, titulo) == 0) return m;
        m = m->proxima;
    } while (m != p->atual);

    return NULL;
}

void mostrar_atual(const Playlist* p) {
    if (p->atual) {
        printf("Tocando agora: %s | Artista: %s | Duracao: %ds\n",
               p->atual->titulo, p->atual->artista, p->atual->duracao);
    } else {
        printf("Nada tocando. Playlist vazia.\n");
    }
}
