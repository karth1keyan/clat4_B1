#include<stdio.h>
#include<stdlib.h>
struct Inv{
    char itm[100];
    char name[100];
    char rate[100];
    char qty[100];
} t;

FILE *fi;

void add_item();
void display();
void menu(void);

int main(){
    menu();

}

void menu(void)
{
	int choice;
	system("cls");
	main:
	printf("\n======================== Product Management System ========================");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress <1> Add Products");
	printf("\n\t\tPress <2> display Products");
	printf("\n\t\tPress <3> Exit!");	
	
	printf("\n\n\t\tEnter your choice[1-3]: ");
	scanf("%i", &choice);
	
	switch(choice)	
	{
		case 1:
			add_item();
			break;
		case 2:
		    display();
			break;
		case 3:
		printf("System Exit");
		    printf("EXIT PROGRAME");
		    break;
		default:
		    printf("Invalid Choice! System Exit\n");
	}
	
}
void add_item(){
    char i;
    fi=fopen("inventory.txt","w");
    //int itm,rate,qty;char name[20];
    printf("\nEnter item id: ");
    scanf("%s",&t.itm);

    printf("\nEnter item name: ");
    scanf("%s",&t.name);

    printf("\nEnter rate: ");
    scanf("%s",&t.rate);

    printf("\nEnter Quantity: ");
    scanf("%s",&t.qty);
    fprintf(fi,"%s %s %s %s\n",&t.itm,&t.name,&t.rate,&t.qty);

    printf("\nBook Added Successfully");
    system("pause");
    fclose(fi);
    menu();
}

void display(){
    char ch,i;
 
    fi = fopen("inventory.txt", "r");
 
    if (NULL == fi) {
        printf("file can't be opened \n");
    }
    printf("content of this file are \n");
 
    do {
        ch = fgetc(fi);
        printf("%c", ch);
 
    } while (ch != EOF);
 
    fclose(fi);
    system("pause");
    menu();
}