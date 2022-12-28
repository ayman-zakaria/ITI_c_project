#ifndef _admin_h_
#define _admin_h_

//account status
#define ACTIVE      1
#define RESTRICTED  2
#define CLOSED      3

//admin data 
#define USER_ID     123
#define USER_PASS   11

//struct for all data for bank account

typedef struct Bank_account{
//data of structure 
uint8 fullname [50];
uint8 addres [50];
uint8 National_id[20];
uint32 account_id;
uint8  guardian_Status;
uint8 guardian_id[20];
uint8 acc_status;
uint16 balance;
uint16 age;
uint16 password;
// ptr of structure address node 
struct Bank_account * next;
}bank_account; //node

//ask admin user and pass to check
uint8 check_admin(int user_dd,int password);

// function to save data as struct node
void data (bank_account *s);
//create node from bank account struct return address in heap of data input
void create_node (bank_account **head);

/*make action on exist account 1-make transaction 
2-change acc status
3-get cash
4-deposite 
5-return 
*/
void open_acc (bank_account *head);




//exit system
void exit_f (void);





#endif