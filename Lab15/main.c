#include <stdio.h>
void printDigitsForward(int n) {
    if (n < 10) {
        printf("%d ", n); 
        return;
    }
    int digit = n % 10; 
    printDigitsForward(n / 10); 
    printf("%d ", digit); 
}
void printDigitsBackward(int n) {
    if (n < 10) {
        printf("%d ", n); 
        return;
    }
    int digit = n % 10; 
    printf("%d ", digit); 
    printDigitsBackward(n / 10); 
}

int main() {
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    printf("Forward: ");
    printDigitsForward(n);
    printf("\nBackward: ");
    printDigitsBackward(n);

    return 0;
}
