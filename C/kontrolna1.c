#include<stdio.h>
#include<stdlib.h>

void printRomb(int);
void saveToFile(int **, int, int);
void readDiagonal();

int main()
{
    int rows, cols, n, i = 0, j = 0;
    int **arr;
    printf("Please enter the size of the figure: ");
    scanf("%d", &n);
    printRomb(n);
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    arr = (int **) malloc(rows * sizeof(int));
    for(i = 0; i <= rows - 1; i++)
          arr[i] = (int *) malloc (cols * sizeof(int));
    for(i = 0; i <= rows - 1; i++)
          for(j = 0; j <= cols - 1; j++)
          {
                printf("Enter element array[%d][%d] : ", i + 1, j + 1);
                scanf("%d", &arr[i][j]);
          }
    saveToFile(arr, rows, cols);
    for(i = 0; i <= n - 1; i++)
          free(arr[i]);
    free(arr);
    readDiagonal();
    system("pause");
    return 0;
}

void printRomb(int n)
{
     int space = 0, in = -1, i = 0, j = 0;
     space = n - 1; 
     for(i = 0; i <= n - 1; i++)
     {
           for(j = 0; j <= space; j++)
                 printf(" ");
           printf("*");
           space--;
           for(j = 1; j <= in; j++)
           {
                 printf(" ");
                 if(j == in) 
                      printf("*");
           }
           in+= 2;
           printf("\n");
     }
     space = 1;
     in -= 4;
     for(i = n - 2; i >= 0; i--)
     {
           for(j = 0; j <= space; j++)
                 printf(" ");
           printf("*");
           space++;
           for(j = 1; j <= in; j++)
           {
                 printf(" ");
                 if(j == in) 
                      printf("*");
           }
           in -= 2;
           printf("\n");
     }
}

void saveToFile(int **arr, int n, int m)
{
     FILE *fp;
     char dir[100];
     int i = 0, j = 0;
     printf("Please enter the path to the file: ");
     scanf("%s", &dir);
     printf("Note that if you don't have file there, it would be created automatically!\n");
     fp = fopen(dir, "w");
     fprintf(fp, "%d %d \n", n, m);
     for(i = 0; i <= n - 1; i++)
     {
           for(j = 0; j <= m - 1; j++)
                 fprintf(fp, "%d ", arr[i][j]);
           fprintf(fp, "\n");
     }
     fclose(fp);
}

void readDiagonal()
{
     FILE *fp;
     char dir[100];
     int **matrix, n, m, i = 0, j = 0, dig = 0; 
     printf("Please enter the path to file you want to open: ");
     scanf("%s", &dir);
     if(!(fp = fopen(dir, "rt")))
     {
             do
             {
                          system("cls");
                          printf("Wrong path! Please enter again: ");
                          scanf("%s", &dir);
             }
             while(!(fp = fopen(dir, "rt")));
     }
     fscanf(fp, "%d %d", &n, &m);
     for(i = 1; i <= n; i++)
     {
           //printf("%d %d\n", i, j);
           for(j = 1; j <= m; j++)
           {
                 fscanf(fp,"%d", &dig);
                 if(i == j)
                      printf("%d ", dig);
           }
     }
     printf("\n");
     fclose(fp);
}
           
     
