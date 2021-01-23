17. WAP to Armstrong Numbers Between Two
Integers

#include <stdio.h>
#include <math.h>
int main() {
   int low = 100;
   int high = 400;
   printf("The amstrong numbers between %d and %d is \n",low,high);
   for (int i = low+1; i < high; ++i) {
      int x = i;
      int n = 0;
      while (x != 0) {
         x /= 10;
         ++n;
      }
      int pow_sum = 0;
      x = i;
      while (x != 0) {
         int digit = x % 10;
         pow_sum += pow(digit, n);
         x /= 10;
      }
      if (pow_sum == i)
         printf("%d ", i);
   }
   printf("\n");
   return 0;
}

