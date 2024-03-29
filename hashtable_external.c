#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    // Table is empty
}

void print_table(){
    printf("START\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        } else{ 
            printf("\t%i\t ", i);
            person *tmp = hash_table[i];
            while (tmp != NULL){
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            
            printf("\n");
        }
    }
    printf("END\n");
}

bool hash_table_insert(person *p){
    if (p ==NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
} 

person *hash_table_delete(char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;

    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp != NULL) return NULL;
    if(prev == NULL){
        hash_table[index] = tmp->next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
    
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
    return tmp;
}

void reset_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        person *current = hash_table[i];
        while (current != NULL) {
            person *next = current->next;
            free(current);
            current = next;
        }
        hash_table[i] = NULL;
    }
}

int main(){
 
    init_hash_table();
    print_table();

    person lucas = {.name="Lucas",.age=256};
    person luisa = {.name="Luisa",.age=18};
    person nazira = {.name="Nazira",.age=32};
    person ron = {.name="ron",.age=4};

    hash_table_insert(&lucas);
    hash_table_insert(&luisa);
    hash_table_insert(&nazira);
    hash_table_insert(&ron);

    print_table();

    person *tmp = hash_table_lookup("Lucas");

    if (tmp == NULL){
         printf("NOT FOUND\n");
    }else{
        printf("FOUND %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Nadir");

    if (tmp == NULL){
         printf("NOT FOUND\n");
    }else{
        printf("FOUND %s.\n", tmp->name);
    }

    hash_table_delete("Luisa");

    print_table();

    // Reset the hashtable
    init_hash_table();

    print_table();

    return 0;
}