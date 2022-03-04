#include <stdio.h>
#include <string.h>

/*
* Person type
*/
typedef struct Person {
    char* name;
    int age;
    void (*greeting)();

} Person;

// Function declaration
void say_english_greeting();
void say_vietnamese_greeting();

int main (int argc, char* argv[]) {
    // 1. Function pointer declaration
    void (*greeting)();

    // 2. Function pointer initialization
    if (argc > 1) {
        greeting = !strcmp("vietnamese", argv[1]) ? &say_vietnamese_greeting : &say_english_greeting;
    } else {
        printf("Please pass a 'greeting' argument!\n");
        return 1;
    }

    Person my_person = { "Henry Carvil", 19, greeting };

    my_person.greeting();

    return 0;
}

void say_english_greeting() {
    printf("Hello!!!\n");
}

void say_vietnamese_greeting() {
    printf("Xin chao!!!\n");
}