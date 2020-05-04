// Comando para compilar seu programa:
// gcc -Og solucao_q1.c q1.o -o q1

// TODO: implementar solucao_q1 abaixo

int solucao_q1 (int a, int b, int c, int d) {
    if (a + b >= c + d) {
        return  4*a + 5*b + 5*c*d;
    }

    return 5*a + 4*b + 5*c*d;
}