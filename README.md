# Lista_Circular

# 🎵 Playlist Circular em C

Este é um sistema de gerenciamento de playlist implementado em linguagem C utilizando uma **lista circular**. Com ele, é possível adicionar, remover e navegar entre músicas de forma cíclica, simulando a experiência de um reprodutor musical.

## 🚀 Funcionalidades

- ✅ Adicionar músicas à playlist  
- ✅ Remover músicas da playlist  
- ✅ Avançar para a próxima música  
- ✅ Voltar para a música anterior  
- ✅ Alternar o modo de repetição (ligado/desligado)  
- ✅ Listar todas as músicas cadastradas  
- ✅ Buscar música pelo título  
- ✅ Simular a reprodução das músicas em sequência  

## 🧱 Estrutura

O sistema é composto por três arquivos principais:

- `main.c`: Interface do menu principal, onde o usuário interage com a playlist.
- `playlist.c`: Implementação das funções de manipulação da playlist.
- `playlist.h`: Cabeçalho contendo as definições das structs e assinaturas das funções.

## 🛠️ Compilação

Para compilar o programa, use um compilador C (como `gcc`). Exemplo:

bash
 gcc -o app_playlist playlist.c main.c

E para executar:
 app_playlist

Basta seguir as opções e inserir as informações quando solicitado.

📌 Observações
A playlist é circular: ao chegar na última música, a próxima será a primeira novamente.

O modo de repetição permite que a mesma música seja tocada indefinidamente até ser desativado.
 
