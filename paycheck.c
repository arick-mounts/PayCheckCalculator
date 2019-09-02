

/*
 *A program which calculates a paycheck, the taxes due, and the take home pay after taxes are deducted built on a menu system provided in the class
 * C @ TCC
 * Arick Mounts
 */


#include <stdio.h>   //header file for input/output

int menu(void);   //prototype definition
/*Place the function prototypes for your programs here! */
void hello(void);
void paycheck(void);


int main(void)
{
    int selection = menu();  //variable declaration and initialization via call to menu()
    //The line above also serves as the 'priming' read for the following while loop
    
    
    while(selection != 99) {
    
        // The switch statement is similar to a chained if-else except conditions fall through in C!
        switch(selection) {

        case 1:
           hello();  
           break;  
           
        case 2:
            paycheck();
           break;
         
        case 3: 
        
           break;

        case 4:
        
           break;  
           
         default: /* Optional - but a good idea expecially if you have no other error catching! */
            printf("Please enter a valid selection.\n");
        }
        
    selection = menu();    // get the next menu selection, otherwise, you have an eternal loop!
    }
    
   return 0;
}
 
int menu(void) {
    int choice;
    printf("***************************\n");
    printf(" 1. Hello \n");
    printf(" 2. Paycheck\n");
    printf(" 3. \n");
    printf(" 4. \n");
    printf("99. Exit\n");
    printf("Please select number and press enter:\n");
    printf("***************************\n");
    scanf("%d", &choice);
    return choice;   
}

/*
 * Chapter2: first.c
 * Julie Luscomb - Aug 2, 2017, 7:59:32 PM
 */
//#include <stdio.h> NOTE: Since everything is in one file, you do not need to include <stdio.h>


void hello(void) {
    printf("Hello, World!!!\n");
}/*

 */

 

void paycheck(void){
    const float RATE1 = .15, RATE2 = .20, RATE3 = .25, CUTOFF1 = 300.0, CUTOFF2 = 450.0, BASE1 = RATE1 *CUTOFF1, BASE2 = BASE1+(RATE2*(CUTOFF2-CUTOFF1));
    
    float rate = 10.0, hrs = 0.0, ot = 0.0, gross = 0.0, tax=0.0;
    
    printf("Please input the number of hours worked in a week\n");
    scanf("%f", &hrs);
    
    if ((ot = hrs-40) > 0){
        gross = ot *(rate*1.5) + (hrs-ot)* rate;

    }else 
        gross = hrs*rate;
    
    
    if (gross < CUTOFF1)
        tax = gross*RATE1;
    else if (gross<CUTOFF2)
        tax = BASE1+((gross-CUTOFF1)* RATE2);
    else 
        tax = BASE2 + ((gross-CUTOFF2)* RATE3);
    
    printf("Gross pay: $%.2f\nTaxes: $%.2f\nNet pay:$%f\n",gross, tax, gross-tax);
    
    
}