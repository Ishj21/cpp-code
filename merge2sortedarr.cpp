
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *getNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *sortedMerge(struct Node *a, struct Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return (result);
}

void removeDupli(Node *head)
{
    Node *current = head;

    Node *next_next;

    if (current == NULL)
        return;

    while (current->next != NULL)
    {

        if (current->data == current->next->data)
        {

            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}

Node *sortedMergeWithoutDuplicate(Node *head1, Node *head2)
{
    Node *head = sortedMerge(head1, head2);

    removeDupli(head);

    return head;
}

//insert printlist here

int main()
{
    Node *head1 = getNode(1);
    head1->next = getNode(2);
    head1->next->next = getNode(5);
    head1->next->next->next = getNode(6);
    head1->next->next->next->next = getNode(11);

    Node *head2 = getNode(2);
    head2->next = getNode(3);
    head2->next->next = getNode(6);
    head2->next->next->next = getNode(12);

    Node *head3;

    head3 = sortedMergeWithoutDuplicate(head1, head2);
    cout << "List 1: " << endl;
    printList(head1);
    cout << endl
         << "List 2: " << endl;
    printList(head2);
    cout << endl
         << "Merged List without Duplicates : " << endl;
    printList(head3);

    return 0;
}
