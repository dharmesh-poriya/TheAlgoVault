// https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

Node *deleteNode(Node *head_ref, int x)
{
    Node *current = head_ref;
    x--;
    while (x--)
    {
        current = current->next;
    }
    if (current == head_ref)
    {
        head_ref->prev = NULL;
        return head_ref->next;
    }
    if (!current->next)
    {
        current->prev->next = NULL;
        return head_ref;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    return head_ref;
}