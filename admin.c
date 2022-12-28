#include <stdio.h>
#include "standard.h"
#include "admin.h"
#include <time.h>
#include "conio.h"
#include "client.h"
#include <stdlib.h>
#include <string.h>

uint8 check_admin(int user_dd,int password){
    uint8 error_Status =ERR_OK;

    if (user_dd==USER_ID && password==USER_PASS){
    printf("\n----------------------Welcome Admin ------------------------- \n");

    }
    else{
        printf("wrong data... \n");
        error_Status=ERR_NOTOK;
    }
    return error_Status;
}


void data (bank_account *s){
    int counter_fullname;
    do {
        counter_fullname=0;
        printf("enter full name ");
        scanf(" %[^\n]",s->fullname);
        for (int i=0 ;s->fullname [i]!='\0';++i){
            if (s->fullname [i]==' ')counter_fullname++;
            }
            // printf("%d",counter_fullname);
            if(counter_fullname <3)
             printf("NOTE: Enter Full Name at least 4 Names \n");

    }while (counter_fullname <3);

    printf("enter address ");
    scanf(" %[^\n]",s->addres);
    printf("enter balance ");
    scanf("%hu",&s->balance);

    //--------------------------  age  ---------------------------
    uint16 flag2=1;
    while (flag2 !=0){
            printf("enter age ");
            scanf("%d",&s->age);

                if (s->age <90 && s->age>=21){
                    printf("enter your national id ");
                    scanf("%s",s->National_id);
                        if (strlen(s->National_id)<13){
                            printf("NOTE: National Id Must Be 14 Character\n");
                        }
                        else{
                            s->guardian_Status=0;
                            flag2 =0;
                        }
                    
                }
                else if (s->age<21 ){
                    printf("enter guardian id ");
                    scanf("%s",s->guardian_id);
                    if (strlen(s->guardian_id)<13){
                            printf("NOTE: National Id Must Be 14 Character\n");
                        }
                        else{
                            s->guardian_Status=1;
                            flag2 =0;
                        }
                   
                }
                else{
                    printf("Wrong...");

                }
    }

    //--------------generate random password------------------------
    srand(time(0));
    s->password=rand ()%100 ;

    //------------generate random acc id ------------------------------
    s->account_id =rand()%10 +1000000000;
    //------------ set account status to be default active ----------------
    s->acc_status=ACTIVE;

}


 void  create_node (bank_account ** head ){
    bank_account * current = *head;
    bank_account *new=NULL;
    new =(bank_account *)malloc (sizeof(bank_account));
                
        data(new);
        new->next=NULL;
        if (*head ==NULL)
        {  
            // printf("head equl null before adding node\n");
            *head=new;
            // printf("head after adding node = %d\n",*head);
            printf("new account password %hu\n",new->password);
            printf("new account id %lu\n",new->account_id);
            printf("new account status %d\n",new->acc_status);

        }
        else if (*head != NULL){
            bank_account * temp=*head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new;
            // printf("head not equal null");
            printf("new account password %hu\n",new->password);
            printf("new account id %lu\n",new->account_id);
            printf("new account status %d\n",new->acc_status);
            

        }
 }




void open_acc (bank_account *head){
uint8 action_Required;
uint32 transfered_to;
uint16 transfered_money;
uint8 status_change;
uint16 amount_money;
uint16 deposite;
uint32 account_id;
uint16 password;
uint8 flag=1;
bank_account * current= head;
if (head ==NULL){
    printf("No acount exist to be open\n");
}
else{
        printf("kindly enter your account id \n");
        scanf("%lu",&account_id);
        printf("kindly enter your password \n");
        scanf("%hu",&password);
        
    while ((current !=NULL ) && flag!=0) //|| head->next ==NULL
    {      
        if(current->account_id==account_id && current->password==password  ){
            //  printf("there are accounts added (head not = null)\n");
            printf("\n ------------------Welcome to %s account --------------------\n",current->fullname);
            printf("enter action required \n 1-make transaction 2-change account status 3-get cash 4-deposite 5-back \n");
            scanf("%d",&action_Required);
            switch (action_Required)
            {
            case 1 : if( current->acc_status==ACTIVE){
                    printf("enter account id to transfer to \n");
                    scanf("%lu",&transfered_to);
                    printf("enter amount of money to transfer \n");
                    scanf("%hu",&transfered_money);   
                     if (current->balance >=transfered_money){
                            printf("enough money \n");
                            bank_account * temp= head;
                        while (temp !=NULL ){
                            if (temp ->account_id == transfered_to){
                            temp ->balance +=transfered_money;
                            current ->balance -=transfered_money;
                            }
                            temp=temp->next;
                            }
                           printf("now your balance is %hu \n",current->balance); 
                           }
                    
                        }
                        else {
                                printf("account not active \n");
                        }
                            
                break;
            case 2 :
                    printf("enter status required 1-active 2-restricted 3-closed \n");
                    scanf("%d",&status_change);
                    if(status_change==1)current->acc_status=CLOSED;
                    else if(status_change==2)current->acc_status=RESTRICTED;
                    else if (status_change==3)current->acc_status=ACTIVE;
                    else printf("wrong choice");

                    printf("now your account status is %d 1-active 2-restricted 3-closed \n",current->acc_status);
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
                    }else {
                                printf("account not active \n");
                            }
                    break;
            case 4 :if( current->acc_status==ACTIVE){
                    printf("enter amount of money to deposite \n");
                    scanf("%hu",&deposite);
                    current->balance += deposite;
                    printf("now your balance is %hu \n",current->balance);
                    }
                    else {
                                printf("account not active \n");
                            }
                    break;
            case 5 :
                    flag=0;
                    break;
            default:
                break;
            }
        }
        current=current->next;
    }
}

}




