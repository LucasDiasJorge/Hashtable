#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
} people;

people * hash_table[TABLE_SIZE];

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
        }else{
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
    printf("END\n");
}

bool hash_table_insert(people *p){
    if (p ==NULL) return false;
    int index = hash(p->name);
    if(hash_table[index] != NULL) return false;
    hash_table[index] = p;
    return true;
}

people *hash_table_delete(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name,TABLE_SIZE) == 0){
        people *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }else{
        return NULL;
    }
}

people * hash_table_lookup(char *name){
    int index = hash(name);
    if(hash_table[index] != NULL && strncmp(hash_table[index]->name, name,TABLE_SIZE) == 0){
        return hash_table[index];
    }else{
        return NULL;
    }
}

int main(){
 
    init_hash_table();
    print_table();

    people lucas = {.name="Lucas",.age=256};
    people luisa = {.name="Luisa",.age=18};
    people nazira = {.name="Nazira",.age=32};
    people ron = {.name="ron",.age=4};

    hash_table_insert(&lucas);
    hash_table_insert(&luisa);
    hash_table_insert(&nazira);
    hash_table_insert(&ron);

    print_table();

    people *tmp = hash_table_lookup("Lucas");

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

    return 0;
}