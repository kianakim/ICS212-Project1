/********************************
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
 *  File: database.c
 *
 *  Description: 
 *
 ******************************/
#include <stdio.h>
#include "database.h"

extern int debugmode;

/*****************************************************************
 *
 * Function name: addRecord
 *  
 *  DESCRIPTION:   A userinterface function
 *                 This function obtains the values of the ... from the user
 *                 
 *                Parameters:    count (int) : contains the number of 
 *                               arguments which will be processed
 *
 *  Return values:  0 : success
 *                 -1 : the value was not found
 *
****************************************************************/

void addRecord (struct record ** records, int acc_num, char * name, char * address)
{

}


/*****************************************************************
 *
 *   Function name: printAllRecords
 *
 *   DESCRIPTION:   A userinterface function
 *                  This function obtains the values of the ... from the user
 *      
 *   Parameters:    count (int) : contains the number of arguments
 *                                which will be processed
 *       
 *   Return values:  0 : success
 *                  -1 : the value was not found
 *    
 ****************************************************************/

void printAllRecords(struct record * records)
{

}

/*************************************************
 *  
 *  Function name: findRecord
 *
 *   DESCRIPTION:   A userinterface function
 *                  This function obtains the values of the ... from the user
 *   
 *   Parameters:    count (int) : contains the number of arguments
 *                                which will be processed
 *     
 *   Return values:  0 : success
 *                  -1 : the value was not found
 *        
****************************************************************/
int findRecord (struct record * records, int acc_num)
{
    return 0;
}

/*********************************************************
 *  
 *    Funotion name: deleteRecord
 *
 *    DESCRIPTION:   A userinterface function
 *                   This function obtains the values of the ... from the user
 *  
 *    Parameters:    count (int) : contains the number of arguments
 *                                 which will be processed
 *   
 *    Return values:  0 : success
 *                   -1 : the value was not found
 *     
 ****************************************************************/
int deleteRecord(struct record ** records, int acc_num)
{
    return 0;
}

