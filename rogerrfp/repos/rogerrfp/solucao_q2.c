// Comando para compilar seu programa:
// gcc -Og solucao_q2.c q2.o -o q2

// TODO: implementar solucao_q2 abaixo

void solucao_q2 (int a, int b, int *p) {
    while (a > 1) {
        a = a/2;
        *p = *p + 2;
    }
    while (b > 33) {
        b = b/8;
        *p = *p - 10;
    }
}