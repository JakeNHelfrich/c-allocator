#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

#define PAGE_SIZE sysconf(_SC_PAGE_SIZE)

// Always allocates a single page of memory.
// For my M1 Macbook Pro the page size is 16kb.
void *my_malloc() {
    void *ptr =  mmap(NULL, PAGE_SIZE, PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    return ptr;
}

void my_memcpy(void *dst, void *src, size_t n) {
    for(int i = 0; i < n; i++) {
        ((unsigned char *)dst)[i] = ((unsigned char*)src)[i];
    }
}

int main() {
    char *message;
    
    message = my_malloc();
    printf("%p\n", message);
    my_memcpy(message, "abc", 3);
    printf("%s\n", (char *) message);
    
    return 0;
}