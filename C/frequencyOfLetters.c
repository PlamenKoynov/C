#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char arr[255];//masiv ot simvoli, w kojto dyrjim izrechenieto
    int i = 0, j = 0, counter = 1;//malko promenliwi za obhojdane na masiwa i za broene
    gets(arr);//chetene na niza
    while(arr[i] != '\0')//obhojdane na wseki simvol
    {
                if(arr[i] != '`' && arr[i] != ' ' && arr[i] != '\t')//prowerka dali ne wlizame w simwol koito sme minali 
                {
                          for(j = i + 1; arr[j] != '\0'; j++)//obhojdane na wsichki simwoli sled arr[i]
                                if(arr[j] == arr[i])//prowerka ako simwolyt e syshtiiq kato arr[i]
                                {
                                          arr[j] = '`';//checkwame go kato minat za da ne go broim sled towa pak
                                          counter++;//uwelichawame broqcha s 1
                                }
                                printf("%c - %d\n", arr[i], counter);//izwejdame simwola i broq na podobnite simwoli
                }
                 counter = 1;//prawim si broqcha otnowo 1 
                 i++;//minawame na sledwashtiq element
    }
    system("pause");
    return 0;
}
                                 
