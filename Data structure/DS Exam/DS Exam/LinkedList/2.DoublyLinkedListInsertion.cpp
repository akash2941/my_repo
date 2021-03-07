#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node * head = NULL;

void insertAtBeginning(int input)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = input;
    newNode -> prev = NULL;
    if(head == NULL)
    {
       newNode -> next = NULL;
       head = newNode;
    }
    else
    {
       newNode -> next = head;
       head = newNode;
    }
    printf("\nInsertion success!!!");
}
void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(head == NULL)
   {
      newNode -> prev= NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != NULL)
      {
          temp = temp -> next;
      }

      temp -> next = newNode;
      newNode -> prev = temp;
   }
   printf("\nInsertion success!!!");
}
void insertAfter(int input, int location)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = input;
   if(head == NULL)
   {
      newNode -> prev = newNode -> next = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp1 = head, *temp2;
      while(temp1 -> data != location)
      {
         if(temp1 -> next == NULL)
         {
            printf("Given node is not found in the list!!!");
         }
         else
         {
            temp1 = temp1 -> next;
         }
      }
      temp2 = temp1 -> next;
      temp1 -> next = newNode;
      newNode -> prev = temp1;
      newNode -> next = temp2;
      temp2 -> prev = newNode;
      printf("\nInsertion success!!!");
   }
}

void display()
{
   if(head == NULL)
      printf("\nList is Empty!!!");
   else
   {
      struct Node *temp = head;
      printf("\nList elements are: \n");
      printf("NULL <--- ");
      while(temp -> next != NULL)
      {
         printf("%d <===> ",temp -> data);
         temp=temp->next;
      }
      printf("%d ---> NULL", temp -> data);
      cout<<endl;
   }
}

int main()
{
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);

    display();

    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    display();


    insertAfter(90,40);
    insertAfter(80,20);

    display();


}
