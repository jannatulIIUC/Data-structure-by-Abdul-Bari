
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

int count (struct Node *p)
{
    int c = 0 ;
    while (p)
    {
        c++ ;
        p = p-> next ;
    }
    return c ;
}

int main ()
{
    struct Node *temp ;
    int A[] = {3 , 5 , 7 , 9 , 10} ;
    create(A , 5) ;
    printf ("Count = %d\n" , count(first) ) ;
}
