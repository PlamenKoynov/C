#include<stdio.h>
#include<stdlib.h>

void compare(int *, int *);

int main()
{
    int mas1[10], mas2[10], i = 0;
    
    printf("Please enter your first array!\n");
    for(i = 0; i <= 9; i++)
    {
          printf("Element number %d: ", i + 1);
          scanf("%d", &mas1[i]);
    }
    
    printf("Please enter your second array!\n");
    for(i = 0; i <= 9; i++)
    {
          printf("Element number %d: ", i + 1);
          scanf("%d", &mas2[i]);
    }
    
    compare(mas1, mas2);
    printf("Everything is ready!\n");
    system("pause");
    return 0;
}

void compare(int *arr1, int *arr2)
{
     FILE *fp;
     char dir[100];
     int i = 0, temp, j = 0;
     printf("Please enter the path you want to open for writing!\nPath: ");
     scanf("%s", dir);
     fp = fopen(dir, "w");
    
     for(i = 0; i <= 9; i++)
     {
           for(j = 0; j <= 9; j++)
            if(arr1[i] > arr2[j])
            {
                       temp = arr1[i];
                       arr1[i] = arr2[j];
                       arr2[j] = temp;
                       break;
            }
     }
     
     for(i = 0; i <= 9; i++)
      fprintf(fp, "%d ", arr2[i]);
}
