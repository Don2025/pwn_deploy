#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void greet() {
    printf("Hello Guys! Welcome To HBU!\n");
    printf("I'm t0ur1st who is a well-wisher. I really wanna tell you what the flag is!\n");
    printf("Tell me what's your name?");
}

void backdoor() {
    system("bin/sh");
}

int main(int argc, char const *argv[]) {
    init();
    greet();
    char buf[32];
    gets(buf);
    printf("Hello %s\n", buf);
    return 0;
}