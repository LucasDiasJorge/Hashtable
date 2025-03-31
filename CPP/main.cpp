#include "Person.h"

#define TABLE_SIZE 10000
#define DELETED_NODE ((Person*) (0xFFFFFFFFFFFFFFFFUL))

Person* hashtable[TABLE_SIZE];

void init_hashtable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

// Função de hash (djb2)
unsigned int hash(const Person& person) {
    unsigned int hash_value = 5381;

    for (char c : person.name) {
        hash_value = ((hash_value << 5) + hash_value) + c;
    }

    return hash_value % TABLE_SIZE;
}

bool insert(const std::string& name, int age) {

    Person* new_person = new Person(name, age);

    unsigned int index = hash(*new_person);

    if (hashtable[index] != nullptr) {
        delete new_person;
        return false;
    }

    hashtable[index] = new_person;
    return true;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashtable[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hashtable[i] == DELETED_NODE) {
            printf("\t%i\t---<DELETED>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hashtable[i]->name.c_str());
        }
    }
    printf("END\n");
}

int main() {

    init_hashtable();

    if (insert("Lucas", 22)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    print_table(); // index 7981

    return 0;
}
