/***************************************
 *
 *  Name: Kiana Kim
 *
 *  Homework: 3b
 *  
 *  Class: ICS212
 * 
 *  Instructor: Ravi Narayan
 *
 *  Date: February 3,2021
 *
 *  File: database.h
 *
 *  Description:
 *      This file contains the prototypes for the database functions
 *      for Homeework 3b.
 */
#include "record.h"

void addRecord (struct record **, int, char [ ], char [ ]);
void printAllRecords(struct record *);
int findRecord (struct record *, int);
int deleteRecord(struct record **, int);
