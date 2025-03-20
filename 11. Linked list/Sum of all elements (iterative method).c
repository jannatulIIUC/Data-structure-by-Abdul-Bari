
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next ;
} *first = NULL ;

void create (int A[] , int n)
{
    int i ;
    struct Node *t , *last ;
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

int sum (struct Node *p)
{
    int s = 0 ;
    while (p != NULL)
    {
        s += p -> data ;
        p = p -> next ;
    }
    return s ;
}

int main ()
{
    struct Node *temp ;
    int A[] = {3 , 5 , 7 , 9 , 10} ;
    create(A , 5) ;
    printf ("Sum = %d\n" , sum (first) ) ;
}
