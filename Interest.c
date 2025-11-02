#include <stdio.h> //xell

//function for clearing buffer input validation
void clear(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

//function for input validation
double getnum(const char *prompt){
    double num;
    int valid;

    do{
        printf(" %s", prompt);
        valid = scanf(" %lf", &num);
    
        if(valid != 1){
            printf("Invalid Input! Numbers only\n");
        }
        clear();
    }while(valid != 1);
    return num;
}

//function to ask what kind of rate
char getrate(){
    char rate;
    int valid;

    do{  
        do{
            printf("\nAnnual(a) or Monthly(m): ");
            valid = scanf(" %c", &rate);

            if(valid != 1){
                printf("Invalid Input! m or a only\n");
            }
            clear();
        }while(valid != 1);
        return rate;

        if(rate != 'm' && rate != 'M' && rate != 'A' && rate != 'a'){
            printf("Invalid Input! m or a only\n");
        }
    }while(rate != 'm' && rate != 'M' && rate != 'A' && rate != 'a');
}

int main(){
    double p, r, t, c, sim, sia, tot1, tot2;
    char type, choice;

printf("Welcome to The Simple Interest Calculator!");

do{     //loop to repeat entire process

//input of numbers
    p = getnum("\n\nEnter Principal: ");
    r = getnum("\nEnter Rate(%): ");
    type = getrate();
    t = getnum("\nEnter Time(months): ");
    c = 100;

//Calculations per rate

    sim = (p*(r/c)*t);      //monthly
    tot1 = p + sim;

    sia= (p*(r/c)*(t/12)); //annually
    tot2 = p + sia;


//printing of results

    if(type == 'm' || type == 'M'){
        printf("\n\nSimple Interest: %.2lf", sim);
        printf("\nTotal Balance: %.2lf", tot1);
    }

    if(type == 'A' || type == 'a'){
        printf("\n\nSimple Interest: %.2lf", sia);
        printf("\nTotal Balance: %.2lf", tot2);
    }
    
//ask to repeat
    do{  
        printf("\n\nCalculate Again? (y/n): ");
            scanf(" %c", &choice);

            if(choice != 'N' && choice != 'n' && choice != 'y' && choice != 'Y'){
                printf("Invalid Input! y or n only");
            }
    }while(choice != 'N' && choice != 'n' && choice != 'y' && choice != 'Y');
                
}while(choice != 'N' && choice != 'n');

printf("\nThank you for using The Simple Interest Calculator!");

return 0;
}