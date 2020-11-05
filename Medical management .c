#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp,*ft;
char choice='y';
char NAME[30];

void home();

struct medicine
{
  char name[30],exp[11];
  int price;
}m;

void add_medicine()
{
	fp=fopen("Medicines.txt","a+");
    
    if(fp==NULL)
    {
    	system("cls");
		printf("\n\n\n\t\t\t\t\tFile Creation failed");
	    getch();
	    home();
	}
	
	choice='y';
	
	while(choice=='y' || choice=='Y')
	{
		system("cls");
		
		printf("\n\n Enter Details of the Medicine : ");
	    printf("\n\n Enter Name : ");
	    scanf("%s",m.name);
	    fflush(stdin);
	    printf("\n\n Enter Expiry Date : (dd/mm/yyyy) : ");
	    scanf("%s",m.exp);
	    printf("\n\n Enter Price : ");
	    scanf("%d",&m.price);
	    
	    fwrite(&m,sizeof(m),1,fp);
	    printf("\n\n Do you want to Add another Medicine : ");	    
	    fflush(stdin);
	    choice=getche();
	}
	
	fclose(fp);
}

void update_medicine()
{
	fp=fopen("Medicines.txt","a+");
	ft=fopen("Temp.txt","a+");
	
	system("cls");
	printf("\n Enter the Name of the Medicine : ");
    scanf("%s",NAME);
    
    while(fread(&m,sizeof(m),1,fp)==1)
    {
    	if(strcmp(m.name,NAME)==0)
    	{
    		system("cls");
    		printf("\n Enter the New Details of the Contact");
    		printf("\n\n Enter Name : ");
	    	scanf("%s",m.name);
	    	fflush(stdin);
	    	printf("\n\n Enter Expiry Date : (dd/mm/yyyy) : ");
	    	scanf("%s",m.exp);
	    	printf("\n\n Enter Price : ");
	    	scanf("%d",&m.price);
    		
    		fwrite(&m,sizeof(m),1,ft);
		}
		else
		{
			fwrite(&m,sizeof(m),1,ft);
		}
	}
	
	fclose(fp);
	fclose(ft);
	printf("\n\n Details Successfully Updated");
	getch();
	remove("Medicines.txt");
	rename("Temp.txt","Medicines.txt");
}

void delete_medicine()
{
	fp=fopen("Medicines.txt","a+");
	ft=fopen("Temp.txt","a+");
	
	system("cls");
	printf("\n Enter the Name of the Medicine : ");
	scanf("%s",NAME);
	
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmp(m.name,NAME))
		{
			fwrite(&m,sizeof(m),1,ft);
		}
	}
	
	fclose(fp);
	fclose(ft);
	printf("\n\n Details Removed Successfully"); 
	getch();
	remove("Medicines.txt");
	rename("Temp.txt","Medicines.txt");
}

void view_medicine()
{
	fp=fopen("Medicines.txt","a+");
	
	system("cls");
	printf("\n Enter the Name of the Medicine : ");
	fflush(stdin);
    scanf("%s",NAME);
    
    while(fread(&m,sizeof(m),1,fp)==1)
    {
    	if(strcmp(m.name,NAME)==0)
    	{
    		system("cls");
    		printf("\n\n Name of the Contact : %s",m.name);
    		printf("\n\n Expiry Date : %s",m.exp);
    		printf("\n\n Price : %d",m.price);    		
    		getch();
		}
	}
	
	fclose(fp);
}

void display_medicines()
{
	system("cls");
	fp=fopen("Medicines.txt","a+");
	
	printf("\n\n Name  : Expiry Date  : Price ");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		printf("\n\n %s : %s : %d",m.name,m.exp,m.price);	
	}
	getch();
	fclose(fp);
}

void home()
{
	int ch;
	
	while(1)
	{
	
	system("cls");	
	printf("\n\n\n\t\t Welcome to Medical Management System");
	printf("\n\n 1.Add Medicine");
	printf("\n\n 2.Update Medicine");
	printf("\n\n 3.Delete Medicine");
	printf("\n\n 4.View Medicine");
	printf("\n\n 5.Display all the Medicines");
	printf("\n\n 6.Exit MMS");
	
	printf("\n\n\n Choose from the above options : ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: 
		add_medicine();      
		break;
		case 2: 
		update_medicine();   
		break;
		case 3: 
		delete_medicine();   
		break;
		case 4: 
		view_medicine();     
		break;
		case 5: 
		display_medicines(); 
		break;
		case 6: 
		exit(0);
		default: 
		printf("\n\n Invalid Option Chosen "); 
		getch();
	}
	
	}	
}

int main()
{
	home();
}
