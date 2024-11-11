#include <stdio.h>

char *MESSAGE = "Hello World!\n";
void *my_malloc(size_t size) {
    return MESSAGE;
}

int main() {
    char *message = my_malloc(sizeof(char));

    printf("%s", message);
    return 0;
}