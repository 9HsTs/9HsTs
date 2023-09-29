#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define clrscr() system("cls")
struct ATM
{
   int acno;
   char name[50];
   int amount;
};struct ATM A1[2]; //Currently array of two members, can be extended upto requirement!

void design();
void createacc();
void deposit();
void withdraw();
void balance();
void displayAccount();
void transfer();

int main(){
   int choice;
   clrscr();
   char ch1,ch2,ch3,ch4;
   pin: printf("\nEnter Your Pin:");
   ch1=getch();
   printf("*");
   ch2=getch();
   printf("*");
   ch3=getch();
   printf("*");
   ch4=getch();
   printf("*");
 if(ch1=='1' && ch2=='2' && ch3=='3' && ch4=='4')
 {
      do
      {
         design();
         printf("\n Enter Your Choice: ");
         scanf("%d",&choice);
         switch(choice){
            case 1: createacc();break;
            case 2: deposit();break;
            case 3: withdraw();break;
            case 4: balance();break;
            case 5: displayAccount();break;
            case 6: transfer();break;
            case 7: break;
            default:printf("\nInvalid Choice.....");
         }
      }while (choice!=7);
 }
 else
 {
   printf("\nInvalid PIN.....");
   goto pin;
 }
   return 0;
   
}

void design(){
   printf("\n-------------ATM INTERFACE-------------");
   printf("\n\t  1. Create Account");
   printf("\n\t  2. Deposit Amount");
   printf("\n\t  3. Withdrawal Amount");
   printf("\n\t  4. Check Balance");
   printf("\n\t  5. Show Account Details");
   printf("\n\t  6. Transfer");
   printf("\n\t  7. Quit");
   printf("\n----------------------------------------");
}

void createacc(){
   int i;
   for(i=0;i<2;i++){
    printf("\nEnter Account Number: ");
    scanf("%d",&A1[i].acno);
    printf("\nEnter Your Name: ");
    fflush(0);
    scanf("%s",A1[i].name);
    printf("\nEnter Amount: ");
    scanf("%d",&A1[i].amount);
   }
}

void displayAccount(){
   int i;
   printf("\nAccount No.\t Name\t     Balance");
   for(i=0;i<2;i++)
   {
      printf("\n\t%d",A1[i].acno);
      printf("\t   %s",A1[i].name);
      printf("\t   %d",A1[i].amount);
      printf("\n");
   }

}

void transfer(){
   printf("sorry... this function not available yet");
}

void deposit(){
   int accno,i;
   int amt,f=0;
   printf("\nEnter An Account Number: ");
   scanf("%d",&accno);
   for(i=0;i<2;i++){
      if(A1[i].acno==accno){
         f=1;
         printf("Name: %s",A1[i].name);
         printf("\nEnter An Amount For Deposit: ");
         scanf("%d",&amt);
         if(amt<0)
          printf("\nInvalid Amount.....");
         else
          A1[i].amount=A1[i].amount+amt;
         break; 
      }
   }
   if(f==0)
    printf("\nInvalid Account Number.... Please check.");
}

void withdraw(){
   int accno,i;
   int amt,f=0;
   printf("\nEnter An Account Number: ");
   scanf("%d",&accno);
   for(i=0;i<2;i++)
   {
      if(A1[i].acno==accno)
      {
         f=1;
         printf("Name: %s",A1[i].name);
         printf("\nEnter An Amount For Withdrawal: ");
         scanf("%d",&amt);
         if(amt<0 || amt>A1[i].amount)
          printf("\nInvalid Amount or Insufficient Balance.....");
         else
          A1[i].amount=A1[i].amount-amt;
         break; 
      }
   }
   if(f==0)
    printf("\nInvalid Account Number.... Please check.");
}

void balance(){
   int accno,i;
   printf("\nEnter An Account Number: ");
   scanf("%d",&accno);
   for(i=0;i<2;i++)
   {
      if(A1[i].acno==accno)
      {
         printf("\nAccount Numer: %d",A1[i].acno);
         printf("\nName: %s",A1[i].name);
         printf("\nBalance: %d",A1[i].amount);
      }
   }
}
