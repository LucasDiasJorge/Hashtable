#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

// Estrutura para o nó da Hashtable
typedef struct {
    int key;
    int value;
} HashNode;

// Hashtable
HashNode hashtable[TABLE_SIZE];

// Função para salvar a Hashtable em um arquivo
void saveHashtableToFile(const char* filename) {
    FILE *file = fopen(filename, "wb"); // Abrir o arquivo para escrita em modo binário
    if (file != NULL) {
        fwrite(hashtable, sizeof(HashNode), TABLE_SIZE, file); // Escrever a Hashtable no arquivo
        fclose(file);
    }
}

// Função para carregar a Hashtable de um arquivo
void loadHashtableFromFile(const char* filename) {
    FILE *file = fopen(filename, "rb"); // Abrir o arquivo para leitura em modo binário
    if (file != NULL) {
        fread(hashtable, sizeof(HashNode), TABLE_SIZE, file); // Ler a Hashtable do arquivo
        fclose(file);
    }
}

int main() {
    // Exemplo de inicialização da Hashtable (preenchimento aleatório)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i].key = i;
        hashtable[i].value = i * 10;
    }

    // Salvar a Hashtable em um arquivo
    saveHashtableToFile("hashtable_data.bin");

    // Limpar a Hashtable (para simular uma nova execução do programa)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i].key = -1;
        hashtable[i].value = -1;
    }

    // Carregar a Hashtable do arquivo
    loadHashtableFromFile("hashtable_data.bin");

    // Exemplo de impressão da Hashtable carregada
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Key: %d, Value: %d\n", hashtable[i].key, hashtable[i].value);
    }

    return 0;
}
