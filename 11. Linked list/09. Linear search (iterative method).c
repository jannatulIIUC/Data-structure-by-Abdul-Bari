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

struct Node * LSearch (struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p -> data)
            return p ;

        p = p-> next ;
    }
    return NULL ;

};


int main ()
{
    struct Node *temp ;
    int A[] = {3, 5, 700, 9, 1, 5, 140} ;
    create(A, 8) ;

    temp = LSearch(first, 1121) ;

    if (temp)
        printf ("Key is found %d\n", temp -> data );
    else
        printf ("Key is not found\n");

    return 0 ;
}


