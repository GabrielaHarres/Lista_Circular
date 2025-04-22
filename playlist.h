#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Musica {
    char titulo[100];
    char artista[100];
    int duracao;
    struct Musica* proxima;
} Musica;

typedef struct {
    Musica* atual;
    int tamanho;
    int repetir;
} Playlist;

Playlist* nova_playlist();
void destruir_playlist(Playlist* p);
void inserir_musica(Playlist* p, const char* titulo, const char* artista, int duracao);
int excluir_musica(Playlist* p, const char* titulo);
void avancar_musica(Playlist* p);
void retroceder_musica(Playlist* p);
void toggle_repetir(Playlist* p);
void mostrar_musicas(const Playlist* p);
Musica* encontrar_musica(const Playlist* p, const char* titulo);
void mostrar_atual(const Playlist* p);

#endif
