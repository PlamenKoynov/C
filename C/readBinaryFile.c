#include <stdio.h> 
#include <ctype.h> 
void read_exe(char *pfilename)
{
	FILE *fp, *pt;//malko ukazatelcheta(samo pyrwiqt shte ti trqbwa, wtoriqt e za faila, 
                  //koito zapiswam, za da widq wschki rezultati)
	int c, i = 0;// i sluji za obhojdane na masiva buffer
	char buffer [255];//masiva buffer, koito zapazwa simvolite, koito se chetat
	pt = fopen("D:\\output.txt", "w");//otwarqm fail za zapis, za da widq wsichki rezultati
	fp = fopen(pfilename, "rb");//malko twoj kod
	if (fp == NULL)
	{
		perror("The file doesn't exist !");
	}
	while((c = fgetc(fp)) != EOF)//chete simvol po simvol ot fajla, dokato ne sreshtne EOF
	{
             while(isprint(c))//ako e simvol, koito moje da se printra
             {
                              buffer[i++] = c;//zapazwa go w bufera
                              c = fgetc(fp);//chete nov simvol
             }
             if(i >= 3)//prowerka, dali w buffera imame poweche ot 3 simwola, 
             fprintf(pt, "%s\n", buffer);//pechata buffera w tekstow fajl, za da se widqt wsichki rezultati
             memset(buffer, 0, sizeof(buffer));//zanulqwa masiwa
             i = 0;//mesti nachaloto na masiwa w nulewiq element
	}
	fclose(fp);
}
int main(void)
{
	read_exe("C:\\Windows\\System32\\calc.exe");
	system("pause");
    return 0;
}
