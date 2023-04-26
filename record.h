/***********************
 *
 *
 *  Name: Kiana Kim
 *
 *  Homework:  Project 2
 *
 *  Class: ICS 212
 *
 *  Instructor: Ravi Narayan
 *
 *  Date: April 12, 2023
 *
 *  File: record.h
 *
 *  Description: Structure Definition for "record"
 *
 *  ******************************/
struct record
{
    int			accountno;
    char 		name[30];
    char		address[50];
    struct record * 	next;
};
