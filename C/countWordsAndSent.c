//Please read all the comments and remove the unnecessary things!
//If you don't know what is unnecessary - read the comments!
//The comments show the main logic of the code - so read them!
//After you have understood what the logic is and have tested the code - remove all comments!
//Change the name of the file by clicking File/Save as

//Start 
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//The functions we are using
int counterForWords(FILE *);//Function for counting the words! Type int because it returns the count of the words!
int counterForSent(FILE *);//Function for counting the sentences! 

//Start of the main function
int main()
{
    FILE *fp;//pointer to the file we want to open
    char dir[100];//directory of the file
    
    //Input the directory of the file
    printf("Please enter the path to the file you want to open!\nPath: ");
    scanf("%s", dir);
    //if the file cannot be open
    while(!(fp = fopen(dir, "r")))
    {
               system("cls");//clean the screen 
               printf("Wrong path! Please try again!\nPath: ");//show that message
               scanf("%s", dir);//scan the new dir
    }//and if that thing is wrong again we d the loop again
    //the loop ends when right directory is entered 
    
    printf("Words: %d\n", counterForWords(fp));//show the result for the words
    
    rewind(fp);//rewind the pointer to use it again for the sentences too
    
    printf("Sentences: %d\n", counterForSent(fp));//show the result for the sentences
    
    fclose(fp);//close the file
    
    system("pause");//remove if you are using Visual studio
    return 0;
}
//End of the main function

//Start counterForWords function
int counterForWords(FILE *fp)
{
    int ch, countWords = 0;//some variables
    for(;;)//infinite for loop
    {
           ch = fgetc(fp);//get the current symbol from the file
           if(ch == EOF)//if the end of the document is reached
                 break;//break the for loop
           if(isalpha(ch))//if the symbol is a letter
           {
                          countWords++;//count it as a word
                          while(isalpha(ch=fgetc(fp)));//and while there are still words move to the next symbol
           }
    }
    return countWords;//return the number of words in the text
}
//End of counterForWords function

//Start counterForSent function 
int counterForSent(FILE *fp)
{
    int ch, countSent = 0;// some variables 
    for(;;)//infinite loop
    {
           ch = fgetc(fp);//get the current symbol in the document
           if(ch == EOF)//checks it whether the end of the file is reached
                 break;//if it is so, break the for loop
           if(ch == '.' || ch == '!' || ch == '?' || ch == EOF)//if one of these symbols is met
                          countSent++;//count the sentence
    }
    return countSent;//return the number of sentences
}
//End of counterForSent function
//End                     
                     
           
    
