#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct 
{
       char *name;
       int health;
}Cowboy;

Cowboy *allocCowboys()
{
     Cowboy *f;
     f = malloc(sizeof(Cowboy));
     f->name = malloc(sizeof(char) * 30);
     f->health = 100;
     return f;
}

Cowboy *release(Cowboy *f)
{
       free(f->name);
       free(f);
       return NULL;
}

void game(Cowboy *first, Cowboy *second)
{
     int damage, exit = 0, flag = 0;
     unsigned int player = 1, rnd = 0;
     srand(time(NULL)); 
     while(first->health > 0 && second->health > 0)
     {
                         damage = rand() % 31;
                         if(damage >= 0 && damage <= 5)
                         {
                                   if(player % 2 != 0)
                                             printf("%s missed hit!\n", first->name);
                                   else
                                             printf("%s missed hit!\n", second->name);
                                   player++;
                                   rnd++;
                                   continue;
                         }
                         if(player % 2 != 0)
                         {
                                   printf("%s dealed %d damage to %s!\n", first->name, damage, second->name);
                                   if(second->health < 50 && damage == 30)
                                             flag = 1;
                                   if(damage == 30)
                                             printf("%s with critical hit!!!\n", first->name);
                                   second->health -= damage;
                         }
                         if(player % 2 == 0)
                         {
                                   printf("%s dealed % d damage to %s!\n", second->name, damage, first->name);
                                   if(first->health < 50 && damage == 30)
                                             flag = 1;
                                   if(damage == 30)
                                             printf("%s with critical hit!!!\n", second->name);
                                   first->health -= damage;
                         }
                         if(first->health <= 0 && second ->health > 0)
                                          printf("We have a winner: %s!\n", second->name);
                         if(second->health <= 0 && first->health > 0)
                                           printf("We have a winner: %s!\n", first->name);
                         if(flag == 0)
                                    player++;
                         else
                                    flag = 0;
                         rnd++;
                         printf("Round % d || %s's health = %d\t%s's health: %d\n", rnd, first->name, first->health, second->name, second->health);
     }
}                                        
int main()
{
    Cowboy *first = allocCowboys();
    Cowboy *second = allocCowboys();
    
    printf("Enter the name of the first cowboy: ");
    scanf("%s", first->name);
    printf("Enter the name of the second cowboy: ");
    scanf("%s", second->name);
    
    system("cls");
    
    game(first, second);
    
    release(first);
    release(second);
    system("pause");
    return 0;
}
