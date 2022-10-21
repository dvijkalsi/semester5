// 3. Design a data structure to maintain a set S of n distinct integers that supports the following 
// two operations:
// a) INSERT(x, S): insert integer x into S
// b) REMOVE-BOTTOM-HALF(S): remove the smallest n/2 integers from S. 
// c) write a program by using UDFs that give the worse-case time complexity of the two operations 
//    INSERT(x, 5) in 0(1) time and REMOVE-BOTTOM-HALF(S) in 0(n) time. 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct set
{
    int *ar;
    int top;
};

struct set *create_set()
{
    struct set *s=(struct set *)malloc(sizeof(struct set));
    s->ar=(int *)malloc(MAX*sizeof(int));
    s->top=0;
    return s;
}

void insert(struct set *s,int x)
{
    // s->ar[s->top]=x;
    // s->top++;
    int i;
    for(i=0;i<s->top;i++)
    {
        if(s->ar[i]==x)
        {
            return;
        }
    }
    for(i=s->top-1;i>=0&&s->ar[i]>x;i--)
    {
        s->ar[i+1]=s->ar[i];
    }
    s->ar[i+1]=x;
    s->top++;

}

void remove_bottom_half(struct set *s)
{
    int i;
    int j=0;
    for(i=s->top/2;i<s->top;++i)
    {
        s->ar[j++]=s->ar[i];
    }
    s->top=s->top/2;
}

void print_set(struct set *s)
{
    printf("\nset: ");
    int i;
    for(i=0;i<s->top;i++)
    {
        printf("%d ",s->ar[i]);
    }
    printf("\n");
}

int main()
{
    struct set *s=create_set();
    insert(s,1);
    insert(s,2);
    insert(s,4);
    insert(s,15);
    insert(s,4);
    insert(s,6);
    insert(s,7);
    // insert(s,8);
    // insert(s,9);
    // insert(s,10);
    // insert(s,11);
    // insert(s,12);
    print_set(s);
    remove_bottom_half(s);
    print_set(s);
    return 0;
}