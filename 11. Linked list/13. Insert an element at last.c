#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next ;
} *first = NULL , *last = NULL ;

void create (int A[] , int n)
{
    int i ;
    struct Node *t  ;
    first = (struct Node *) malloc(sizeof(struct Node)) ;
    first -> data = A[0] ;
    first -> next = NULL ;
    last = first ;

    for (i = 1 ; i < n ; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node)) ;
        t -> data = A[i] ;
        t -> next = NULL ;
        last -> next = t ;
        last = t ;
    }
}

void Display (struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d " , p -> data) ;
        p = p -> next ;
    }
}

void InsertLast (int x )
{
    struct Node *t ;
    t = (struct Node *) malloc(sizeof(struct Node)) ;
    t -> data = x ;
    t -> next = NULL ;
    if (first == NULL)
        first = last = t ;

    else {
        last -> next = t ;
        last = t ;
    }

}

int main ()
{
    struct Node *temp ;
    int A[] = {3 , 5 , 7 , 9 , 10} ;
    create(A , 5) ;

    printf("Before Insertion: ") ;

    Display(first) ;

    printf("\n") ;

    printf("After Insertion: ") ;

    InsertLast(8) ;
    Display(first) ;
}
