#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

struct args {
    double res;
    int tamanho;
    double *vec;
};

void *minha_thread(void *_arg) {
    struct args *args = (struct args*) _arg;

    for (int i = 0; i < args->tamanho; i++) {
        args->res += args->vec[i];
    }

    return NULL;
}

int main() {

    int n;
    printf("Digite o valor de n:\n");
    scanf("%d", &n);

    pthread_t *tids = malloc(2 * sizeof(pthread_t));
    struct args *argvec = malloc(2 * sizeof(struct args));
        
    double vec_args[n];
    for (int i = 0; i < n; i++) {
        double arg;

        printf("Argumento %d:\n", i+1);
        scanf("%lf", &arg);

        vec_args[i] = arg;
    }
    
    double v1[n/2];
    double v2[n - (n/2)];

    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (i < n/2) {
            v1[i] = vec_args[i];
        } 
        else {
            v2[contador] = vec_args[i];
            contador++;
        }
    }

    argvec[0].tamanho = n/2;
    argvec[1].tamanho = n - n/2;
    argvec[0].vec = v1;
    argvec[1].vec = v2;
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&tids[i], NULL, minha_thread, &argvec[i]); 
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(tids[i], NULL);
        printf("Res %d = %lf\n", i, argvec[i].res);
    }

    printf("resultado: %lf\n", argvec[0].res + argvec[1].res);
    
    return 0;
}