int solucao_q2 (int a) {
    if (a <= 0) {
        return -1;
    }
    int i = 0;
    while (a > 17) {
        a *= 2;
        i++;
    }
    return i*23;
}