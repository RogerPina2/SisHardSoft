int solucao_faz_contas (long a, long b, long *p){
    if (a > 0) {
        *p = 5*b + 4*a;
        return 1;
    }
    *p = 7*a + 8*b;
    return 0;
}

void solucao_q1 (long a, long b) {
    long p = 0;
    while (p >= 0) {
        solucao_faz_contas(a,b,&p);
        a += 1;
        b -= 2;
    }
}
