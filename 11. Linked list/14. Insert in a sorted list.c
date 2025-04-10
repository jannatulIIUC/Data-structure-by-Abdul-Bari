
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next ;
} *first = NULL ;

void create (int A[], int n)
{
    int i ;
    struct Node *t, *last ;
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

void Display (struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p -> data) ;
        p = p -> next ;
    }
}

void SortedInsert (struct Node *p, int x)
{
    struct Node *t, *q = NULL ;

    t = (struct Node *) malloc(sizeof(struct Node)) ;
    t -> data = x ;
    t -> next = NULL ;

    if (first == NULL)
        first = t ;

    else
    {
        while (p && p -> data  < x)
        {
            q = p ;
            p = p -> next ;
        }

        if (p == first)
        {
            t -> next = first ;
            first = t ;
        }

        else
        {
            t -> next = q -> next ;
            q -> next = t ;
        }
    }
}

int main ()
{
    int A[] = {3, 5, 7, 9, 10} ;
    create(A, 5) ;
    Display(first) ;

    SortedInsert(first,15);
    Display(first);
}
