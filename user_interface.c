/******************************** *
 *
 *  Name: Kiana Kim
 *
 *  Homework: 3b
 *  
 *  Class: ICS 212
 *
 *  Instructor: Ravi Narayan
 *
 *  Date: February 3, 2023
 *  
 *  File: user_interface.c
 *
 *  Description: 
 *      This file contains the driver and the user-interface functions
 *      for Homework 3b
 *
 *****************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "user_interface.h"
#include "record.h"

int debugmode = 0;

void getaddress (char [], int);
int checkMenu(char *, char **);
int checkIfNum(char *);

/*******************************************
 *
 *  Function name: main
 *  
 *  Description:   main function checks argv[] for "debugmode" 
 *                 and turns on debug statements as a result.
 *                 Similates Bank UI with possible commands,
 *                 add, printAll, find, delete, and quit. 
 *
 *  Parameters:    argc (int) : The number of elements in argv
 *                 argv (char*[]) : An array of arguments passed
 *                                  to the program.
 *
 *  Return values:  0 : runs successfully
 *                 -1 : something
 *
 *
 *******************************************/

int main(int argc, char* argv[])
{  
    char add[4] = "add";
    char print[9] = "printAll";
    char find[5] = "find";
    char delete[7] = "delete";
    char quit[5] = "quit";
    
    char * menu[5];
    char cmd_input[9];
    int state = -1;

    char new_num[11]; 
    int new_num_int = 0;
    char new_name[30];
    char new_address[30];
    char temp_c;

    int find_num;
    char user_input[9]; 
    char find_input[30];    
    char del_input[30];    
    int del_num = 0;

    *menu = add;
    *(menu + 1) = print;
    *(menu + 2) = find;
    *(menu + 3) = delete;
    *(menu + 4) = quit;
    
    if(argc == 2 && strncmp(argv[1], "debugmode", 9) == 0)
    {
        debugmode = 1;
        printf("DEBUG MODE ON\n");
    }

    printf("Welcome to the Bank of ICS 212. Please type one of the five MENU options below and press ENTER.\n\n");

    printf("%s: Adds a new record\n", add);
    printf("%s: Prints all records\n", print);
    printf("%s: Find record by Account No\n", find);
    printf("%s: Delete record by Account No\n", delete);
    printf("%s: Exit the program\n", quit);
    
    fgets(cmd_input, 9, stdin);

    state = checkMenu(cmd_input, menu);
    
    while(state != 4)
    {   
        if(state == -1)
        {
            printf("Please enter a valid response. ");
            state = 6;       
        }
        else if(state == 0)
        {
            printf("What is the Account Number?");
            fgets(new_num, 11, stdin);
            new_num_int = checkIfNum(new_num);
            
            while(new_num_int == 0)
            {
                printf("Please enter a valid account number. 10 digits or less. No characters.\n");
                fgets(new_num, 11, stdin);
                new_num_int = checkIfNum(new_num);
            }
     
            printf("\nWhat is the name associated with the record?");
            fgets(new_name, 30 ,stdin);
            
            
            printf("What is the address associated with this record? Type '+' and hit ENTER when you are done.\n");       
            getaddress(new_address, 30);
           
            printf("Acc: %d ", new_num_int);
            printf("Name: %s", new_name);
            printf("Address: %s", new_address);

            printf("\n\nNew Record Added to the Database. Thank you.\n");

            fgetc(stdin);
            state = 6; 
        }
        else if(state == 1)
        {
            printf("PRINT ALL RECORDS <IMPLEMENT HERE>\n");
            fgetc(stdin);
            state = 6;

        }
        else if(state == 2)
        {
            printf("Find a record by ID. Enter an ID:");
            fgets(find_input, 11, stdin);
            
            find_num = checkIfNum(find_input);    

            while(find_num == 0)
            {
                printf("Please enter a valid account number. 10 digits or less. Must be > 0\n");
                fgets(find_input, 11, stdin);
                find_num = checkIfNum(find_input);
            }
            
            printf("IMPLEMENT FIND RECORD HERE\n");
            printf("\n RECORD %d FOUND.\n\n", find_num);
            printf("PRINT RECORD HERE\n\n");
            fflush(stdin); 
            state = 6; 

        }
        else if(state == 3)
        {
            printf("Delete a record by ID. Enter an ID: ");
            fgets(del_input, 11, stdin);
            
            del_num = checkIfNum(del_input);

            while (del_num == 0)
            {
                printf("Please enter a valid account number. 10 digits or less. Must be > 0\n");
                fgets(del_input, 11, stdin);
                del_num = checkIfNum(del_input);
            }
            
            fflush(stdin);
            printf("Record under Account Number %d has been deleted.\n\n", del_num);
            state = 6; 
        }
        else if (state == 5)
        {
            printf("Please type one of the five MENU options below and press ENTER.\n\n");
            fflush(stdin);            

            printf("%s: Adds a new record\n", add);
            printf("%s: Prints all records\n", print);
            printf("%s: Find record by Account No\n", find);
            printf("%s: Delete record by Account No\n", delete);
            printf("%s: Exit the program\n", quit);

            fgets(user_input, 9, stdin);

            state = checkMenu(user_input, menu);
            fflush(stdin);
        }
        if(state == 6)
        {
            printf("Press Enter to return to the Main Menu."); 

            temp_c = fgetc(stdin);
            if(temp_c == '\n')
            {
                state = 5;
            }
        }
    }
    return 0;
}

/*****************************************************************
 *
 *     Function name: getaddress
 *
 *     DESCRIPTION:   A userinterface function
 *                    This function obtains the values of the ... from the user
 *
 *     Parameters:    address (char *) : contains the number of arguments
 *                                  which will be processed
 *
 *                    max_size (int) : contains the size of character array,
 *                                 address
 *     Return values: none
 *
 ****************************************************************/

void getaddress(char * address, int max_size)
{
    char temp_c;
    int counter = 0;    
 
    temp_c = fgetc(stdin); 
   
    if(debugmode == 1)
    {
        printf("\naddress (START): %s\n", address);
        printf("max_size (START): %d\n", max_size); 
    }

    while(temp_c != '+' && counter < max_size)
    {
        
        if(debugmode == 1)
        {
            printf("\ntemp_c: %c (counter = %d)\n", temp_c, counter);
        }
        address[counter] = temp_c;
        counter += 1;
        
        temp_c = fgetc(stdin);   
    }

    if(debugmode == 1)
    {
        printf("address (END): %s\n", address);
    }
    
}


/*****************************************************************
 *     
 *     Function name: checkMenu
 *  
 *     DESCRIPTION:   A user-interface function
 *                    This function obtains the char array from the user
 *                    and the menu options from the main function and
 *                    compares the two. 
 *    
 *     Parameters:    address (char *) : contains the number of arguments
 *                                       which will be processed
 *         
 *                    max_size (int) : contains the size of character array,
 *                                      address
 *
 *     Return values: -1 : returns -1 if input does not match menu options 
 *                    0 : returns 0 if input matches "add"
 *                    1 : returns 1 if input matches "print"
 *                    2 : returns 2 if input matches "find"
 *                    3 : returns 3 if input matches "delete"
 *                    4 : returns 4 if input matches "quit"
 *           
 ****************************************************************/

int checkMenu(char * user_input, char ** menu)
{
    int i;
    int cmd_lengths[5] = {3, 8, 4, 6, 4};
    int temp;    
    int return_val = -1;
    

    char * duplicates[20];

    char add_dup1[2] = "ad";
    char add_dup2[1] = "a";
    char add_dup3[3] = "Add";
    char add_dup4[3] = "ADD";

    char print_dup1[1] = "p";
    char print_dup2[2] = "pr";
    char print_dup3[5] = "print";
    char print_dup4[5] = "Print";
    char print_dup5[2] = "pa";
    char print_dup6[5] = "PRINT";

    char find_dup1[1]= "f";
    char find_dup2[2] = "fi";
    char find_dup3[3] = "fin";
    char find_dup4[4] = "Find";
    char find_dup5[4] = "FIND";

    char del_dup1[1] = "d";
    char del_dup2[2] = "de";
    char del_dup3[3] = "del";
    char del_dup4[6] = "Delete";
    char del_dup5[6] = "DELETE";
    int dup_lengths[20] = {2, 1, 3, 3, 1, 2, 5, 5, 2, 5, 1, 2, 3, 4, 4, 1, 2, 3, 6, 6};

    *duplicates = add_dup1;
    *(duplicates + 1) = add_dup2;
    *(duplicates + 2) = add_dup3;    
    *(duplicates + 3) = add_dup4;
    *(duplicates + 4) = print_dup1;
    *(duplicates + 5) = print_dup2;
    *(duplicates + 6) = print_dup3;
    *(duplicates + 7) = print_dup4;
    *(duplicates + 8) = print_dup5;
    *(duplicates + 9) = print_dup6;
    *(duplicates + 10) = find_dup1;
    *(duplicates + 11) = find_dup2;
    *(duplicates + 12) = find_dup3;
    *(duplicates + 13) = find_dup4;
    *(duplicates + 14) = find_dup5;
    *(duplicates + 15) = del_dup1;
    *(duplicates + 16) = del_dup2;
    *(duplicates + 17) = del_dup3;
    *(duplicates + 18) = del_dup4;
    *(duplicates + 19) = del_dup5;
    
    for (i = 0; i < 5; i++)
    {
        temp = strncmp(menu[i], user_input, cmd_lengths[i]);
        if(debugmode == 1)
        {
            printf("%s vs. %s (%d)\n", menu[i], user_input, cmd_lengths[i]);
        }
        if(temp == 0)
        {
            return_val = i;
            if(debugmode == 1)
            {
                printf("return_val: %d\n", return_val);
            }
        }
    }
    if(return_val == -1)
    {
        if(debugmode == 1)
        {
            printf("no direct match. scanning duplicates\n");
        }
        for(i = 0; i < 20; i++)
        {
            temp = strncmp(duplicates[i], user_input, dup_lengths[i]);
            if(debugmode == 1)
            {
                printf("%s vs. %s (%d)\n", duplicates[i], user_input, dup_lengths[i]);
            }
            if (temp == 0)
            {   
                printf("match found.\n");
                if(i < 4)
                {
                    return_val = 0;
                }
                else if(i < 10)
                {
                    return_val = 1;
                }
                else if(i < 15)
                {
                    return_val = 2;
                }
                else if(i < 20)
                {
                    return_val = 3;
                }
            }
        }
    }
    if(debugmode == 1)
    {
        printf("return_val: %d\n", return_val);
    }

    return return_val;
}

/*****************************************************************
 *
 *   Function name: checkIfNum
 *  
 *    DESCRIPTION:   A user-interface function
 *                   This function obtains the char array from the 
 *                   user and returns the int value representation
 *                   of the string
 *      
 *    Parameters:    user_input (char *) : contains the number of arguments
 *                                      which will be processed
 *          
 *    Return values: 0 : returns 0 if input is not string of numbers
 *                   n : returns number as (int)
 *             
 ****************************************************************/

int checkIfNum(char * user_input)
{
    int i;
    char temp_c;
    char acc_digits[11];
    int multiplier = 1;
    int temp;
    int num = 0;
    int stop = 0;

    for(i = strlen(user_input) - 1; i >= 0; i--)
    {   
        temp_c = user_input[i];
        
        if(debugmode == 1)
        {
            printf("temp_c: %c\n", temp_c);
        }

        if((temp_c > 47) && (temp_c < 58) && (stop == 0))
        {
            temp = (int) temp_c;
            acc_digits[i] =  temp - 48;

            num += acc_digits[i] * multiplier;

            multiplier *= 10;
      
        }
        
    }
    return num;

}

 
