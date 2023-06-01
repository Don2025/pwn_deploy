#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void greet() {
    printf("Hello Guys! Welcome To HBU!\n");
    printf("I'm t0ur1st who is a well-wisher. I really wanna tell you what the flag is!\n");
    printf("However Liang Brother said that you guys must solve 100 math calculations in 20 seconds to get flag!\n");
    printf("Oh my God! How to do that? Maybe we can make a calculator. Now Enjoy It!\n");
}

void *timer_thread(void *arg) {
    sleep(20);
    printf("\nAh Oh... Time's Up!\n");
    printf("One More Try?!\n");
    exit(0);
}

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char generate_random_operator() {
    char operators[] = {'+', '-', 'x', '/'};
    int index = rand() % 4;
    return operators[index];
}

double calculate_result(int num1, int num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case 'x':
            return num1 * num2;
        case '/':
            return (double)num1 / num2;
        default:
            return 0;
    }
}

int main(int argc, char const *argv[]) {
    init();
    greet();
    srand(time(NULL));
    int score = 0;
    pthread_t timer;
    pthread_create(&timer, NULL, timer_thread, NULL);
    for (int i = 0; i < 100; ++i) {
        int num1 = generate_random_number(1, 100);
        int num2 = generate_random_number(1, 100);
        char operator = generate_random_operator();
        double result, answer;
        printf("Question %d: What is %d %c %d?\n", i + 1, num1, operator, num2);
        printf("Input Answer: ");
        if(scanf("%lf", &answer) != 1) {
            printf("Invalid Input!\nI can't give bad guys flag...Bye\n");
            exit(0);
        }
        getchar();
        result = calculate_result(num1, num2, operator);
        double tolerance = 1e-6;
        if(fabs(result - answer) < tolerance) {
            printf("Correct!\n");
            ++score;
        } else {
            if(operator != '/') {
                printf("Wrong! The Correct Answer is %d.\n", (int)result);
            } else {
                printf("Wrong! The Correct Answer is %lf.\n", result);
            }
            printf("One More Try?!\n");
            return 0;
        }
    }
    pthread_cancel(timer);
    pthread_join(timer, NULL);
    printf("Congratuation! Here You GO!\n");
    system("/bin/sh");
    return 0;
}