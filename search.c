#include <stdio.h>

int linear(const char *L, size_t len, char t);
int binary(const char *L, size_t len, char t);

int main(void){
    char L[5] = {'A', 'B', 'C', 'D', 'E'};
    size_t len = sizeof(L) / sizeof(L[0]);
    printf("t: ");
    char t;
    scanf(" %c", &t);
    printf("Linear Search\n");
    linear(L, len, t);
    printf("Binary Search\n");
    binary(L, len, t);
    return 0;
}

int linear(const char *L, size_t len, char t){
    for (size_t i = 0; i < len; i++){
        if (L[i] == t){
            printf("Found: %zu\n", i);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

int binary(const char *L, size_t len, char t){
    if (len == 0){
        printf("Not Found\n");
        return 1;
    }
    int i = 0;
    int j = (int)len - 1;
    while (i <= j){
        int m = i + (j - i) / 2;
        if (L[m] == t){
            printf("Found: %i\n", m);
            return 0;
        } else if (L[m] < t){
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    printf("Not Found\n");
    return 1;
}