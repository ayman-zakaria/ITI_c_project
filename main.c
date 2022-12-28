#include <stdio.h>
#include "standard.h"
#include "admin.h"
#include <time.h>
#include "conio.h"
#include "client.h"
#include <stdlib.h>
#include <string.h>


void main (void){
uint8 choice1;
uint8 restart_app=1, restart_admin=1,restart_client=1;
uint8 restart_admin_counter=0,restart_client_counter=0;
uint8 choice_admin;
bank_account *head=NULL;

 while (restart_app !=0)

 {  
    printf("press 1 to login by Admin \n");
    printf("press 2 to login by Client \n");
    printf("press 3 to restart again\n");
    scanf("%d",&choice1);
switch(choice1){
        case 1:{
                while (restart_admin!=0 && restart_admin_counter <3)
                {
                    int user_s,pass;
                    printf("Enter id ");
                    scanf("%d",&user_s);
                    printf("enter pass ");
                    scanf("%d",&pass);
                    
                    if(check_admin(user_s,pass) == 1)
                    {   
                        
                       
                       printf("Choose action to do press 1 to create account 2 to open account 3 exit system\n");
                       scanf("%i",&choice_admin);
                       if (choice_admin==1){
                        create_node (&head);
                       }
                       else if (choice_admin ==2){
                         open_acc(head);
                       }
                       else if (choice_admin==3){
                        restart_app=0;
                        system ("cls");
                       }
                                restart_admin_counter=0;
                                break;
                    }
                    else
                    {
                        printf("Login By Admin again \n");
                        restart_admin=1;
                        restart_admin_counter++;
                        if(restart_admin_counter==3){
                        system("cls");
                        printf("Login Failed, Restarting App... \n");
                        }    
                    }
                }
               
            }
            break;
        case 2:{
           check_client(head);
            }
            break;
        case 3 :
            system("cls");
            printf("Restart again \n");
            restart_app=1;
            break;
        default :
            restart_app=0;
        break;
    }

}

}