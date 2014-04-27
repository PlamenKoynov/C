//Read the comments! They will guide you through the logic of the code
//Remove the unnecessary things! If you don't know what is unnecessary - read the comments
//There is a weakness in the program:
//1. It doesnt check whether there is disk D on the PC so that to create the temp document
//2. It doesn't put tabs if it meets new line, which is not mentioned in the problem
//After reading ALL the comments, remove them and after that upload the solution
//And, by the way, change the name by clicking File/Save as/ and save it as you wish. 

//Start
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaration
    FILE *fp, *pt; //pointers to the files you want to open and the temp file
    char dir[100]; //directory of the file
    int flag = 0, ch, i = 0, counter = 0;//some integer variables
//End of declaration

void addToTemp(FILE *fp, FILE *pt); //copy the changed content of the file to the temp file
void addToExist(FILE *pt, FILE *fp); //copy the temp file with the changes to the existing file 

//Start of the main function
int main()
{
    //Input of the file directory. If the file is not found the loop starts again and continues 
    //untill the right file is entered
    do
    {
             if(flag != 0)
                     printf("Can't open the file in %s!\n", dir);
             printf("Please enter the directory of the file you want to open: !\nPath: ");
             scanf("%s", dir);
    }
    while(!(fp = fopen(dir, "r+")));
    //End of the entering the path to the file

    //Open temporary file in D so that we can transfer the changed content of the first file
    pt = fopen("D:\\temp.txt", "w+");
    
    //Call the function addToTemp where the transfer starts
    addToTemp(fp, pt);
    
    //Rewind the two pointers: one for the original file and one for the temp file.
    //We do that because we need to copy the temp file in the original file
    //and we need to start doing that from the begining 
    rewind(pt);
    rewind(fp);
    
    //Call the function addToExit to copy the temp file in the original file    
    addToExist(pt, fp);
    
    //Close both files because we did our job and that is the end of the process
    fclose(fp);
    fclose(pt);
    
    //Remove the temp file from the system
    remove("D:\\temp.txt");
    
    printf("Changes are made!\n");//Text to the user that the process is ready
    system("pause");//Remove that if you are using Visual studio
    return 0;
} 
//End of the main

//Start the addToTemp function
void addToTemp(FILE *fp, FILE *pt)
{
     for(;;)//an infinite loop that goes from the begining to the end of the original file
     { 
            
            ch = fgetc(fp);//get the current symbol
            if(ch == EOF)//checks whether it is not the end of the file
            {
                  fputc('\0', pt);//if it is the end, put the EOF in the temporary file
                  break;//break the for loop  
            }
            if(ch == '{')//if we are up to a '{' sign
            {
                  fputc('\n', pt);//we put a new line
                  for(i = 0; i <= counter - 1; i++)
                       fputc('\t', pt);//and after that the necessary amount of tabs
                  counter++;//increase the counter by one because we are now on a lower level and we need more tabs
                  fputc('{', pt);//put the '{'
                  fputc('\n', pt);//and put a new line again
                  for(i = 0; i <= counter - 1; i++)
                       fputc('\t', pt);//put some tabs, so that the text that is going to be enterd next is aligned
            }
            else if(ch == '}')// we do the same and for the closing brace
            {
                  fputc('\n', pt);
                  counter--;
                  for(i = 0; i <= counter - 1; i++)
                       fputc('\t', pt);
                  fputc('}', pt);
                  fputc('\n', pt);
                  counter--;
                  for(i = 0; i <= counter - 1; i++)
                       fputc('\t', pt);
            }
            else//if we are up to a symbol which is not { or } we put the normal symbol 
                  fputc(ch, pt);
    }
}
//End the addToTemp function

//Start the addToExist function
void addToExist(FILE *pt, FILE *fp)
{
    for(;;)//infinite for loop
    {
           ch = fgetc(pt);//read each symbol
           if(ch == EOF)//checks whether it is the end of the file
                 break;//if it is the end, breaks the for loop
           fputc(ch, fp);//else put the symbol in the original file
    }       
}
//End the addToTemp function
//End 
