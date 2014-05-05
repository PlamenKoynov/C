#include<stdio.h>
#include<stdlib.h>

int main()
{
    double lf;
    char arr[255]; 
    int size = 0, i = 0, dec = 1, sum = 0, sign = 0;
    printf("Enter your number in scientific notation: ");
    scanf("%s", arr);
    size = strlen(arr);
    for(i = size - 1; arr[i] != 'e'; i--)
    {
          if(isdigit(arr[i]))
          {
                    sum  += dec * (arr[i] - '0');
                    arr[i] = '0';
          }
          if(arr[i] == '+')
                    sign = 1;
          arr[i] = '0';
          if(i == 0)
          {
               printf("Your digit is not in scientific notation!\n");
               return -1;
          }
    }
    lf = atof(arr);
    if(sign == 1)
            lf *= pow(10, sum);
    else 
            lf /= pow(10, sum);
    printf("Your number: %g\n", lf);
    return 0;
}
