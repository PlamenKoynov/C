#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char number[100][100]; 
char words[][50] = {"", "edno", "dve", "tri", "chetiri", "pet", "shest", "sedem", "osem", "devet", "deset",
"edinadeset", "dvanadeset", "trinadeset", "chetirinadeset", "petnadeset", "shestnadeset", "sedemnadeset",
"osemnadeset", "devetnadeset"};
char deset[][50] = {"", "deset", "stotin", "hilqda", "hilqdi", "", "milion", "miliona", "", "miliard", "miliarda"};
char temp[50], special[50];

void printNumber(int);

int main()
{
    int num;
    printf("Molq vuvedete chislo: ");
    scanf("%d", &num);
    if(num == 0)
         printf("Nula\n");
    else
         printNumber(num);  
    system("pause");
    return 0;
}

void printNumber(int n)
{
    int index = 0, last, l, pr = 1, vr = 0, flag = 0, sign = 0, beg = 0; 
    if(n < 0)
    {
           printf("Minus ");
           sign = 1;
           n *= -1;
    }
    while(n != 0)
    {
              l = n % 1000;
              if(l == 0)
                   flag = 1;
              while(l != 0)
              {
                      last = l % 10;
                      if((l / 10) % 10 == 1 && vr % 3 == 0)
                      {
                               strcpy(number[index++], words[l % 100]);
                               l /= 100;
                               vr = vr + 2;
                               continue;
                      }
                      if(last == 0)
                      {
                              vr++;
                              l /= 10;
                              continue;
                      }
                      else if(last == 1 && vr == 2)
                               strcpy(number[index++], "sto");
                           else if(last == 2 && vr == 1)
                               strcpy(number[index++], "dvadeset");
                                else if((last == 2 || last == 3) && vr == 2)
                                {
                                     strcpy(temp, words[last]);
                                     strcpy(number[index++], strcat(temp, "sta"));
                                }
                                     else
                                     {
                                         strcpy(temp, words[last]);
                                         strcpy(number[index++], strcat(temp, deset[vr]));
                                     }
                                            if(vr == 0 &&  n / 10 != 0)
                            strcpy(number[index++], "i");
                      if((l / 100) % 10 == 0 && (l / 10) % 10 == 0 && (n / 1000) % 1000 != 0)
                            strcpy(number[index++], deset[(pr * 3) + 1]); 
                      vr++;
                      l /= 10;
              }
              pr++;
              vr = 0;
              n /= 1000;
    }
    if(flag == 1 && strcmp(number[index - 1], "edno"))
    {
            strcpy(special, deset[(pr - 2) * 3 + 1]);
    }
    if((!strcmp(number[index - 1], "edno")) && index >= 1 && pr > 2)
    {
                             if(index == 1)
                                      strcpy(number[index - 1], deset[(pr - 2) * 3]);
                             else
                             {
                                      strcpy(number[index - 2], deset[(pr - 2) * 3]);
                                      index--;
                             }
    }
    beg = index - 1;
    if(sign == 0)
            number[beg][0] = toupper(number[beg][0]);
    for(index = index - 1; index >=0;index--)
              printf("%s ", number[index]);
    if(strcmp(special, ""))
                        printf("%s", special);
    printf("\n");
}
