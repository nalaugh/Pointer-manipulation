/***********************************************
 * Name: (YOUR NAME)**
 * Date: (THE DUE DATE)**
 * Assignment: Project 1 -Sequence and Order validation
 * *************************************************
 * Read in a file then out put the file with the line
 * numbers and columbs in order.
 * ************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void stringSort(int*strings, int nstring, int (*compfun)());
int numsstrcmp(int string1, int string2);
void printArray(int*array, int size);
/***********************************************
 * Description: Read int the file and send it to the files to be sorted
 * Input:the name of the file
 * Output: no true output
***********************************************/
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Please input the file name\n");
        return 0;
    }
    FILE *fp;
    char FirstLine[36];
    fp = fopen(argv[1], "r");
    if (fp == 0)
    {
        printf("Error opening the file\n");
        exit(0);
    }
    int lines = 0;//line marker
    fscanf(fp,"%s",FirstLine) ;
    int numLine = FirstLine[0]-'0';
    printf("%d list\n\nPrints the sorted lines\n", numLine);
    int totalnumber = 0;
    int **line=malloc(sizeof(int*) * numLine);
    int *final = malloc(sizeof(int) * numLine);
    int *original = malloc(sizeof(int) * numLine);
    int *shift = malloc(sizeof(int) * numLine);
    while (lines <numLine){

        char lineRead[100];
        fscanf(fp,"%s", lineRead);
        int numbers = lineRead[0]-'0';
        *(line+lines)= malloc( sizeof(int)*numbers);
        int  set[numbers];
        *(final+lines) = numbers;
        *(original+lines) = numbers;
        int setnumb =0;

        for (int i = 1; i<strlen(lineRead);i++)
        {
            if(lineRead[i] !=','&&lineRead[i]!=':'&&lineRead[i] !=' ')
            {
                if(lineRead[i] == '-')
                {
                    char temp = (lineRead[i+1]-'0');
                    set[setnumb] = 0-(int)temp;
                    i++;
                }
                else
                {
                    set[setnumb] = lineRead[i]-'0';
                }
                setnumb++;
            }
        }
        int key[numbers];

        stringSort(set, numbers,numsstrcmp);
        for (int i = 0; i< numbers;i++)
        {
            key[i] = set[i];
        }
        for (int i = 0; i< numbers;i++)
        {
            *(*(line+lines)+i)= key[i];
        }

        totalnumber +=numbers;
        printArray(*(line+lines), numbers);//print the sorted line

        lines++;

    }

    stringSort(final, numLine,numsstrcmp);//forting the line length
    printf("This shows the length before and after the sort\n");
    printArray(original, numLine);//printing the origingal order
    printArray(final, numLine);//printing the sorted
    
    int k=0;//marker
    for(int j =0; j<numLine;j++)
    {
        k = 0;
        while(*(final+j)!=*(original+k))
        {
            k++;
        }
        *(shift+j) = k;//shift marker
    }
    printf("This prints the list from shortest to longest\n");
    for(int i = 0; i<numLine;i++)
    {
        printArray(*(line+*(shift+i)), *(final+i));//Print the final array
    }
    //freeing the memory
    free(line);
    free(final);
    free(original);
    return 0;
}
/***********************************************
 * Description: sort the pointer
 * Input: the pointer the size and the pointer to the function
 * Output: no true output
***********************************************/
void stringSort(int*strings, int nstring, int (*compfun)())
{
    int i, j;
    int didswap;
    do{
        didswap =0;
        for(i=0; i<nstring-1;i++)
        {
            j=i+1;
            if((*compfun)(*(strings+i),*(strings+j))>0)
            {
                int temp= strings[i];
                *(strings+i) = *(strings+j);
                *(strings+j) = temp;
                didswap =1;
            }
        }
    }while(didswap);

}
/***********************************************
 * Description: Swap the items
 * Input: the two items to be swapped
 * Output: no true output
***********************************************/
int numsstrcmp(int string1, int string2)
{
    int n1 =string1;
    int n2 =string2;
    if(n1<n2)
    {
        return -1;
    }
    else if(n1==n2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/***********************************************
 * Description: print the array
 * Input: the pointer to be printed and the size
 * Output: the printed list.
***********************************************/
void printArray(int*array, int size)
{
    for(int i =0; i<size;i++)
    {
        printf("%d ", *(array+i));
    }
    printf("\n\n");
}

