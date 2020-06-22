#include "mintest/macros.h"
#include <unistd.h>

/*
int test1() {
    test_printf("Hello! %d %f\n", 3, 3.14);
    return 0;
}

int test2() {
    test_assert(1 == 0, "This always fails!");
    printf("This never runs!\n");
    test_assert(1 == 1, "Neither this.");
    return 0;
}

int test3() {
    test_printf("<-- Name of the function before the printf!\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}
*/

int falha_de_segmentacao() {

    int vetor[5];
    vetor[6] = 11;
    return 0;
}
 
int divisao_por_zero() {

    int var = 7/0;
    return 0;
}
 
int loop_infinito() {

    while (1) {
    }
    return 0;
}
 
int muito_trabalho() {

    int trabalho = 0;
    int contador = 10;
    for (int i = trabalho; i <= contador; i++) {
        trabalho++;
    }

    while (trabalho <= 2*contador){
        trabalho++;
    }
 
    for (int i = 0; i <= (trabalho + contador); i++) {
        printf("Trabalho %d\n", i);
    }
 
    return 0;
}
 
int falha_passa() {

    test_assert(1 == 0, 'fail');
    test_assert(1 == 1, 'pass');
    return 0;
}
 
int passa_falha() {

    test_assert(0 == 0, 'pass');
    test_assert(0 == 1, 'fail');
    return 0;
}

int muito_prints() {

    int prints = 0;
    for (int i = prints; i <= 123; i++) {
        printf("Print %d\n", i);
    }
 
    return 0;
}
  
int teste_rapido() {
    return 0;
}
 
int teste_devagar() {
 
    printf("Teste devagar!\n");
    sleep(20);
    return 0;
}

// test_list = { TEST(test1), TEST(test2), TEST(test3) };

test_list = { 
    TEST(falha_de_segmentacao), 
    TEST(divisao_por_zero ), 
    TEST(loop_infinito), 
    TEST(muito_trabalho), 
    TEST(falha_passa), 
    TEST(passa_falha), 
    TEST(muito_prints), 
    TEST(teste_rapido), 
    TEST(teste_devagar) 
};

#include "mintest/runner.h"