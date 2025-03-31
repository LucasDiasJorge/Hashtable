#include "Person.h"

#define TABLE_SIZE 10000

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

int main() {

    init_hashtable();

    if (insert("Lucas", 22)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
