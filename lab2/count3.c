#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node nd;
nd *create(nd *head, int n, int t)
{
    nd *tmp, *new = malloc(sizeof(nd));
    int temp = (n / t) % 10;
    new->data = n;
    new->next = NULL;
    if (head == NULL)
        head = new;
    else
    {
        if (((head->data / t) % 10) > temp)
        {
            new->next = head;
            head = new;
        }

        else
        {
            tmp = head;
            while (tmp->next != NULL && (tmp->next->data / t) % 10 <= temp)
            {
                tmp = tmp->next;
            }
            new->next = tmp->next;
            tmp->next = new;
        }
    }
    return head;
}
void radix_sort(int *a, int n)
{
    int i, j, k, temp, copy[n];
    nd *head;
    temp = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > temp)
            temp = a[i];
    }
    int d = 0, rem;
    while (temp != 0)
    {
        d++;
        rem = temp % 10;
        temp = temp / 10;
    }
    int t = 1;
    for (i = 1; i <= d; i++)
    {
        head = NULL;
        for (j = 0; j < n; j++)
        {
            head = create(head, a[j], t);
        }
        nd *tmp = head;
        for (j = 0; j < n && tmp != NULL; j++)
        {
            a[j] = tmp->data;
            tmp = tmp->next;
        }
        t = t * 10;
    }
}
int main()
{
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int a[n], i;
    printf("Enter the elements one by one:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Entered elments:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    radix_sort(a, n);

    printf("Sorted Elements:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

}