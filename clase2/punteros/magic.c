#include <stdio.h>

int main() {
    int magic = 0x00796177;

    printf("magic = %0X\n", magic);
    printf("magic = \"%s\"\n", (char *)(&magic));

    return 0;
}
