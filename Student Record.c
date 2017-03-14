//
//  main.c
//  student record
//
//  Created by Apple on 02/04/16.
//  Copyright (c) 2016 Gronical App Studios. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insert ( char name[] , int rollnumber , int math , int physics , int chemistry );
void delete ( int rollnumber);
void modify ( int rollnumber );
void display();
void displayroll(int);
struct node{
    char stuname[20];
    int maths , phys , chem , roll;
    struct node* link;
};
struct node* start;
int n;
int main()
{
    start = NULL;
    int choice , rollnumber , math , physics , chemistry ,i , rolldel , rollmod , rolldisp;
    char name[20];
    while (1) {
        printf("\n\n1.Create List\n2.Insert\n3.Delete\n4.Modify\n5.Display All Record\n6.Display Record\n7.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                printf("\nHow many records : ");
                scanf("%d",&n);
                for (i = 0; i<n; i++) {
                    printf("\nEnter Name : ");
                    scanf("%s" , name);
                    printf("\nEnter roll number : ");
                    scanf("%d" , &rollnumber);
                    printf("\nEnter marks in maths : ");
                    scanf("%d" , &math);
                    printf("\nEnter marks in physics : ");
                    scanf("%d" , &physics);
                    printf("\nEnter marks in chemistry : ");
                    scanf("%d" , &chemistry);
                    insert(name, rollnumber, math, physics, chemistry);
                }
                break;
            case 2:
                printf("\nHow many records : ");
                scanf("%d",&n);
                for (i = 0; i<n; i++) {
                    printf("\nEnter Name : ");
                    scanf("%s" , name);
                    printf("\nEnter roll number : ");
                    scanf("%d" , &rollnumber);
                    printf("\nEnter marks in maths : ");
                    scanf("%d" , &math);
                    printf("\nEnter marks in physics : ");
                    scanf("%d" , &physics);
                    printf("\nEnter marks in chemistry : ");
                    scanf("%d" , &chemistry);
                    insert(name, rollnumber, math, physics, chemistry);
                }
                break;
            case 3:
                printf("\nEnter students's roll number : ");
                scanf("%d" , &rolldel);
                delete(rolldel);
                break;
            case 4:
                printf("\nEnter students's roll number : ");
                scanf("%d" , &rollmod);
                modify(rollmod);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nEnter students's roll number : ");
                scanf("%d" , &rolldisp);
                displayroll(rolldisp);
                break;
            case 7:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
void insert ( char name[] , int rollnumber , int math , int physics , int chemistry )
{
    struct node* temp ,*temp1;
    temp= malloc(sizeof(struct node));
    temp->roll = rollnumber;
    temp->maths = math;
    temp->phys = physics;
    temp->chem = chemistry;
    strcpy(temp->stuname, name);
    if (start == NULL) {
        start = temp;
        temp->link = NULL;
        return;
    }
    temp1 = start;
    if (name[0] < (temp1->stuname[0])) {
        temp->link = start;
        start = temp;
    }
    else
    {
        int i = 0;
        while ((temp1->link != NULL)&&(temp1->link->stuname[i] < name[i])&&name[i]!='\0') {
            if (name[i] == temp1->stuname[i])
                i++;
            else
                temp1 = temp1->link;
        }
        if (temp1->link == NULL) {
            temp1->link = temp;
            temp->link = NULL;
        }
        else
        {
            temp->link = temp1->link;
            temp1->link = temp;
        }
    }
    
}
void delete ( int rollnumber )
{
    struct node* q , *temp1;
    q = start;
    temp1 = start;
    temp1=temp1->link;
    if (rollnumber == q->roll) {
        start = q->link;
        free(q);
        return;
    }
    while (q->link!=NULL) {
        if (rollnumber == q->link->roll) {
            if (temp1->link == NULL) {
                free(temp1);
                q->link = NULL;
                return;
            }
            q->link = temp1->link;
            free(temp1);
            return;
        }
        q =q->link;
        temp1 = temp1->link;
    }
}
void modify ( int rollnumber )
{
    struct node* temp;
    char newname[20];
    int choice , newroll , newphy,newmath,newchem;
    temp = start;
    printf("\nWhat You want to modify:-\n1.Name\n2.Roll Number\n3.Maths marks\n4.Physics Marks\n5.Chemistry Marks");
    printf("\nEnter Choice : ");
    scanf("%d" , &choice);
    switch (choice) {
        case 1:
            printf("\nEnter New Name : ");
            scanf("%s" , newname);
            while ((temp->link != NULL)&&(rollnumber!=temp->roll)) {
                temp = temp->link;
            }
            newroll = temp->roll;
            newmath = temp->maths;
            newchem = temp->chem;
            newphy = temp->phys;
            delete(temp->roll);
            insert(newname, newroll, newmath, newphy  , newchem);
            printf("\n___Record Updated___");
            break;
        case 2:
            printf("\nEnter New Roll Number : ");
            scanf("%d" , &newroll);
            while ((temp->link != NULL)&&(rollnumber!=temp->roll)) {
                temp = temp->link;
            }
            temp->roll = newroll;
            printf("\n___Record Updated___");
            return;
            break;
        case 3:
            printf("\nEnter New Maths Marks : ");
            scanf("%d" , &newmath);
            while ((temp->link != NULL)&&(rollnumber!=temp->roll)) {
                temp = temp->link;
            }
            temp->maths = newmath;
            printf("\n___Record Updated___");
            return;
            break;
        case 4:
            printf("\nEnter New Physics marks : ");
            scanf("%d" , &newphy);
            while ((temp->link != NULL)&&(rollnumber!=temp->roll)) {
                temp = temp->link;
            }
            temp->phys = newphy;
            printf("\n___Record Updated___");
            return;
            break;
        case 5:
            printf("\nEnter New Chemistry marks : ");
            scanf("%d" , &newchem);
            while ((temp->link != NULL)&&(rollnumber!=temp->roll)) {
                temp = temp->link;
            }
            temp->chem = newchem;
            printf("\n___Record Updated___");
            return;

            break;
            
        default:
            break;
    }
}
void display ( )
{
    struct node* temp;
    if (start == NULL) {
        printf("\n_____No Record to Display____");
        return;
    }
    temp = start;
    while (temp->link != NULL) {
        printf("\nName : %s" , temp->stuname);
        printf("\nRoll No. : %d" , temp->roll);
        printf("\nMaths Marks : %d", temp->maths);
        printf("\nPhysics Marks : %d" , temp->phys);
        printf("\nChemistry Marks : %d\n" , temp->chem);
        temp=temp->link;
    }
    printf("\nName : %s" , temp->stuname);
    printf("\nRoll No. : %d" , temp->roll);
    printf("\nMaths Marks : %d", temp->maths);
    printf("\nPhysics Marks : %d" , temp->phys);
    printf("\nChemistry Marks : %d\n" , temp->chem);
}
void displayroll ( int rollnumber )
 {
 struct node* temp;
 temp = start;
 while ((temp->link != NULL) && (temp->roll != rollnumber)) {
 temp=temp->link;
 }
 printf("\nName : %s" , temp->stuname);
 printf("\nRoll No. : %d" , temp->roll);
 printf("\nMaths Marks : %d", temp->maths);
 printf("\nPhysics Marks : %d" , temp->phys);
 printf("\nChemistry Marks : %d\n" , temp->chem);
 }