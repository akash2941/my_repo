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

void deleteBeg()
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      if(temp -> prev == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         head = temp -> next;
         head -> prev = NULL;
         free(temp);
      }
      printf("\nDeletion success!!!( Begning ) ");
   }
}
void deleteEnd()
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      if(temp -> prev == temp -> next)
      {
         head = NULL;
        // free(temp);
      }
      else{
         while(temp -> next != NULL)
         {
          temp = temp -> next;
         }
         temp -> prev -> next = NULL;
        // free(temp);
      }
      printf("\nDeletion success!!! ( At the End )");
   }
}
void deleteSpecific(int delValue)
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct Node *temp = head;
      while(temp -> data != delValue)
      {
         if(temp -> next == NULL)
         {
            printf("\nGiven node is not found in the list!!!");
         }
         else
         {
            temp = temp -> next;
         }
      }
      if(temp == head)
      {
         head = NULL;
         //free(temp);
      }
      else
      {
         temp -> prev -> next = temp -> next;
         //free(temp);
      }
      printf("\nDeletion success!!!");
   }
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    display();

    deleteBeg();
    display();

    deleteEnd();
    display();

    deleteSpecific(40);
    display();

}

