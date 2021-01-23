28. WAP to Reverse a Sentence Using Recursion
Input : CDAC Mumbai
Output: iabmum CADC

#include <stdio.h>

using namespace std;
void reverseSentence();
int main() {
    printf("Enter a sentence: ");
    reverseSentence();
    return 0;
}

void reverseSentence() {
    char c;
    scanf("%c", &c);
    if (c != '\n') {
        reverseSentence();
        printf("%c", c);
    }
}

