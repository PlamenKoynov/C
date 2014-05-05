#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reader(FILE *);

int main()
{
    FILE *fp;
    char dir[100];
    printf("Please enter the path to the file you want to open!\nPath: ");
    scanf("%s", dir);
    while(!(fp = fopen(dir, "rt")))
    {
               system("cls");
               printf("Wrong file! Try again!\nPath: ");
               scanf("%s", dir);
    }
    
    system("cls");
    reader(fp);
    
    printf("Have a good day!\n");
    system("pause");
    return 0;
}

void reader(FILE *pt)
{
     char ans = '0';
     int counter = 0, page = 1, exit = 0, ch; 
     while(exit == 0)
     {
               fflush(stdin);
               printf("%c", (ch = fgetc(pt)));
               counter++;
               if(ch == EOF)
               {
                     printf("\nThe end!\n");
                     break;
               }
               if(counter == 200)
               {
                          printf("\nNext page (n), previous page (p) or quit (q)?: ");
                          scanf("%c", &ans);
                          fflush(stdin);
                          while(page == 1 && ans == 'p')
                          {
                                     printf("Can't go back!Choose next page or quit: ");
                                     scanf("%c", &ans);
                                     fflush(stdin);
                          } 
                          system("cls");
                          counter = 0;
                          if(ans == 'p')
                          {
                                 page--;
                                 fseek(pt, ((page - 1) * 200), SEEK_SET);
                          }
                          else
                              if(ans == 'n')
                                 page++;
                              else if(ans == 'q')
                                   break;
               } 
     }
     fclose(pt);
}           
