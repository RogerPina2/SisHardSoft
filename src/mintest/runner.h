#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    pid_t filho;
    
    int size = sizeof(all_tests)/sizeof(test_data);
    if (argc > 1) {

        printf("Running %s\n", argv[1]);
        printf("=====================\n\n");
        
        int teste_rodando = 1;  
        for (int i = 0; i < size; i++) {
            
            int cmp_str = strcmp(all_tests[i].name, argv[1]);
            if (cmp_str == 0) {

                if (all_tests[i].function() >= 0) { 
                    printf("%s: [PASS]\n", all_tests[i].name);
                } 
                else {
                    printf("%s: [ERRO]\n", all_tests[i].name);
                }
                
                teste_rodando = 0;
                break;
            }
        }
 
        if (teste_rodando == 1) {
            printf("ERROR! No test named %s\n", argv[1]);
        }
        return 0;
    }

    printf("Running %d tests:\n", size);
    printf("=====================\n\n");
    int pass_count = 0;
    for (int i = 0; i < size; i++) {
        
        filho = fork();
        if (filho == 0) {
            if (all_tests[i].function() >= 0) {
                printf("%s: [PASS]\n", all_tests[i].name);
                pass_count++;

                return 0;
            }
            else {
                printf("%s: [ERRO]\n", all_tests[i].name);
            }
            return 1;
        }
    }
    
    int status;
    for (int i = 0; i < size; i++) {
        wait(&status);
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) != 0) {
                printf("%s: [ERRO]\n", all_tests[i].name);
            }
        }
        if (WIFSIGNALED(status)) {
            printf("%s: [ERRO]\n", all_tests[i].name);
        }
    }


    printf("\n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}
