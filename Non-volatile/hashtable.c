#include "hashtable.h"

// Define the hashtable array
HashNode hashtable[TABLE_SIZE];

// Implementação da função para salvar a Hashtable em um arquivo
void saveHashtableToFile(const char* filename) {
    FILE *file = fopen(filename, "wb"); // Abrir o arquivo para escrita em modo binário
    if (file != NULL) {
        fwrite(hashtable, sizeof(HashNode), TABLE_SIZE, file); // Escrever a Hashtable no arquivo
        fclose(file);
    }
}

// Implementação da função para carregar a Hashtable de um arquivo
void loadHashtableFromFile(const char* filename) {
    FILE *file = fopen(filename, "rb"); // Abrir o arquivo para leitura em modo binário
    if (file != NULL) {
        fread(hashtable, sizeof(HashNode), TABLE_SIZE, file); // Ler a Hashtable do arquivo
        fclose(file);
    }
}
