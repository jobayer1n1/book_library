#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

typedef char* string;

int BOOK_COUNT = 0;

struct books{
    string name ;
    int available;
}book[100];

string get_string(char print[])
{
    printf("%s",print);

    string a = malloc(sizeof(char));
    char c;
    int i = 0 ;
    fflush(stdin);
    while((c=fgetc(stdin))!='\n')
    {
        a[i]=c;
        i++;
        a = realloc(a,sizeof(char));
    }
    a[i]='\0';
    return a;
}

string fget_string(FILE* file)
{
    string a = malloc(sizeof(char));
    char c;
    int i = 0 ;
    while((c=fgetc(file))!='\n'&&c!=EOF)
    {
        a[i]=c;
        i++;
        a = realloc(a,sizeof(char));
    }
    a[i]='\0';
    return a;
}
int fget_int(FILE* file)
{
    string a = malloc(sizeof(char));
    char c;
    int i = 0 ;
    while((c=fgetc(file))!='\n'&&c!=EOF)
    {
        a[i]=c;
        i++;
        a = realloc(a,sizeof(char));
    }
    a[i]='\0';
    return atoi(a);
}

void add()
{
    fflush(stdin);
    book[BOOK_COUNT].name = get_string("Enter the book name : ");

    printf("Enter 1 if available | 0 if not available\n : ");
    scanf("%d",&book[BOOK_COUNT].available);

    FILE* file = fopen("booklist.txt","a");
    fprintf(file,"%s\n%d\n",book[BOOK_COUNT].name,book[BOOK_COUNT].available);
    fclose(file);
    BOOK_COUNT++;
}

void load_booklist()
{
    FILE* file = fopen("booklist.txt","r");
    if(file == NULL) return;

    while(!feof(file))
    {
        book[BOOK_COUNT].name = fget_string(file);
        book[BOOK_COUNT].available = fget_int(file);
        BOOK_COUNT++;
    }

}

void print_booklist()
{
    printf("U HAVE %d BOOK/S IN YOUR LIBRARY\n\n",BOOK_COUNT);
    for(int i = 0 ; i < BOOK_COUNT ;i++)
    {
        printf("----- %d ------\n",i+1);
        printf("NAME : %s\nSTATUS : ",book[i].name);
        if(book[i].available) printf("Available\n");
        else printf("Not available\n");
    }
    while(!kbhit())
    {

    }
}
void search(string name)
{
    printf("STATUS : ");
    for(int i = 0 ; i<BOOK_COUNT ;i++)
    {
        if(strcmp(name,book[i].name)==0)
        {
            if(book[i].available) printf("available\n");
            else printf("not available\n");
            return;
        }
        if(i==BOOK_COUNT-1)
        {
            if(strcmp(name,book[i].name))
                printf("no match\n");
        }
    }
}
int main()
{
    load_booklist();
    char c;
    while(c!='e')
    {
        printf("YOU HAVE %d BOOKS IN YOUR LIBRARY\n\n",BOOK_COUNT);
        printf("1->add a book\n");
        printf("2->see listed books\n");
        printf("3->search book\n\n");
        fflush(stdin);
        scanf("%c",&c);
        if(c=='1')
        {
            system("cls");
            add();
        }
        else if(c=='2')
        {
            system("cls");
            print_booklist();
        }
        else if(c=='3')
        {
            while(c!='h')
            {
                system("cls");
                string name = get_string("Book name : ");
                search(name);
                scanf("%c",&c);
            }
        }
        else printf("wrong input\n");
        system("cls");
    }

}



