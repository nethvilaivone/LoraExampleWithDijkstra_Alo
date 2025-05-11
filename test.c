#include <stdio.h>


int number(int n[] , int size)
{
for(int i = 0; i < size;i++){
    int minindex = i;
printf(" minindex = %d ", minindex);
    for(int j = i+1; j < size; j++){
   printf(" j = %d ", j);
        if(n[j] < n[minindex]){
            minindex = j;
        }
    }

int temp = n[i];
printf(" temp = %d ", temp);
n[i] = n[minindex];
n[minindex] = temp;
}
 
}

int main() {

   int numbers[5] = {222,67,32,2};
   int count = sizeof(numbers) / sizeof(numbers[0]);
   number(numbers, count);

   for (size_t i = 0; i < count; i++)
   {
         printf("%d ", numbers[i]);
   }
   
    printf("Hello, World!\n");
    return 0;
}