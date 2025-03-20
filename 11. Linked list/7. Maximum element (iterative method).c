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

int Max (struct Node *p)
{
    int max = INT_MIN ;

    while (p)
    {
        if (p -> data > max)
            max = p -> data ;
        p = p -> next ;
    }

    return max ;

}

int main ()
{
    struct Node *temp ;
    int A[] = {3 , 5 , 700 , 9 , 1 , 5 , 140} ;
    create(A , 8) ;
    printf ("Max = %d\n" , Max(first) );
}

