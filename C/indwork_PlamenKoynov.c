#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr, size, i = 0, j = 0, temp;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);
    
    arr = (int *)malloc(size * sizeof(int));
    
    for(i = 0; i <= size - 1; i++)
    {
          printf("Element %d: ", i + 1);
          scanf("%d", arr + i);
    }
    
    system("cls");
    
    for(i = 0; i <= size - 1; i++)
          for(j = 0; j <= size - i - 2; j++)
                if(*(arr + j) < *(arr + j + 1))
                {
                         temp = *(arr + j);
                         *(arr + j) = *(arr + j + 1);
                         *(arr + j + 1) = temp;
                }
    
    printf("Elements after sorting: \n");
    for(i = 0; i <= size - 1; i++) 
          printf("Element %d: %d\n", i + 1, *(arr + i));
    
    free(arr);
    system("pause");
    return 0;
}
