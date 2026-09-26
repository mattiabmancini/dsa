#include <stdio.h>

int selection(int *L, size_t len);
int bubble(int *L, size_t len);
int merge(int *L, size_t len);

int main(void){
    int L[6] = {1, 3, 5, 2, 4, 6};
    size_t len = sizeof(L) / sizeof(L[0]);
    printf("Selection Sort\n");
    selection(L, len);
    printf("Bubble Sort\n");
    bubble(L, len);
    printf("Merge Sort\n");
    merge(L, len);
    return 0;
}

int selection(int *L, size_t len){
    for (size_t i = 0; i < len; i++){
        int s = L[i];
        size_t k = i;
        for (size_t j = i + 1; j < len; j++){
            if (L[j] < s){
                s = L[j];
                k = j;
            }
        }
        int temp = L[i];
        L[i] = L[k];
        L[k] = temp;
    }
    for (size_t i = 0; i < len; i++){
        printf("%i", L[i]);
    }
    printf("\n");
    return 0;
}

int bubble(int *L, size_t len){
    for (size_t i = 0; i + 1 < len; i++){
        int c = 0;
        for (size_t j = 0; j < len - i - 1; j++){
            if (L[j] > L[j + 1]){
                int temp = L[j];
                L[j] = L[j + 1];
                L[j + 1] = temp;
                c = 1;
            }
        }
        if (c == 0){
            break;
        }
    }
    for (size_t i = 0; i < len; i++){
        printf("%i", L[i]);
    }
    printf("\n");
    return 0;
}

int merge(int *L, size_t len){
    size_t s = 1;
    while (s < len){
        for(size_t i = 0; i + s < len; i += s * 2){
            int A[s];
            size_t Bs;
            if (i + s * 2 <= len){
                Bs = s;
            } else {
                Bs = len - (i + s);
            }
            int B[Bs];
            for (size_t j = 0; j < s; j++){
                A[j] = L[i + j];
            }
            for (size_t j = 0; j < Bs; j++){
                B[j] = L[i + j + s];
            }
            int C[s + Bs];
            size_t a = 0, b = 0, c = 0;
            while (a < s && b < Bs){
                if (A[a] < B[b]){
                    C[c++] = A[a++];
                } else {
                    C[c++] = B[b++];
                }
            }
            while (a < s){
                C[c++] = A[a++];
            }
            while (b < Bs){
                C[c++] = B[b++];
            }
            for (size_t k = 0; k < c; k++){
                L[i + k] = C[k];
            }
        }
        s *= 2;
    }
    for (size_t i = 0; i < len; i++){
        printf("%i", L[i]);
    }
    printf("\n");
    return 0;
}