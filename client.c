#include <stdio.h>
#include "standard.h"
#include "admin.h"
#include <time.h>
#include "conio.h"
#include "client.h"
#include <stdlib.h>
#include <string.h>


void check_client (bank_account * head){
uint8 action_Required;
uint32 transfered_to;
uint16 transfered_money;
uint16 new_pass;
uint16 amount_money;
uint16 deposite;
uint32 account_id;
uint16 password;
uint8 flag=1;
bank_account * current= head;

if (head ==NULL ){
    printf("No acount exist to be open\n");
}
else{
        printf("kindly enter your account id \n");
        scanf("%lu",&account_id);
        printf("kindly enter your password \n");
        scanf("%hu",&password);
    while ((current !=NULL ) && flag!=0)
    {       
        if(current->account_id==account_id && current->password==password  ){
             printf("\n ------------------Welcome  %s  --------------------\n",current->fullname);
            printf("enter action required \n 1-make transaction 2-change password 3-get cash 4-deposite 5-back \n");
            scanf("%i",&action_Required);
            switch (action_Required)
            {
            case 1 : if( current->acc_status==ACTIVE){
                    printf("enter account id to transfer to \n");
                    scanf("%lu",&transfered_to);
                    printf("enter amount of money to transfer \n");
                    scanf("%hu",&transfered_money);
                     if (current->balance >=transfered_money){
                           bank_account * temp= head;
                         while (temp !=NULL ){
                            if (temp ->account_id ==transfered_to){
                                printf("enough money\n");
                            temp->balance +=transfered_money;
                            current->balance -=transfered_money;
                            }
                            temp=temp->next;}
                            }
                            printf("now your balance is %hu \n",current->balance);
                            }
                            else {
                                printf("account not active \n");
                                }
                break;
            case 2 :if( current->acc_status==ACTIVE){
                    printf("enter your new password (from 1 to 99)\n");
                    scanf("%hu",&new_pass);
                    current->password=new_pass;
                    printf("now your new password is %hu",current->password);
                    }
                    else {
                        printf("acoount not active ");
                    }
                    
                    break;
            case 3 :if( current->acc_status==ACTIVE){
                    printf("enter amount of money to withdraw \n");
                    scanf("%hu",&amount_money);
                    if (current->balance >= amount_money){
                        current->balance -= amount_money;
                        printf("Now your balance is %hu \n",current->balance);
                    }
                    else{
                        printf("sorry no enough money \n");
                    }
                    }
                    else {
                        printf("acoount not active ");
                    }
                    break;
            case 4 :if( current->acc_status==ACTIVE){
                    printf("enter amount of money to deposite \n");
                    scanf("%hu",&deposite);
                    current->balance += deposite;
                    printf("now your balance is %hu \n",current->balance);
                    }
                    else {
                                printf("account not active");
                            }
                    break;
            case 5 :
                    flag=0;
                    break;
            default:
                break;
            }
        }else{
            printf("wrong data.......... \n");
        }
     current=current->next;

    }
}
}

