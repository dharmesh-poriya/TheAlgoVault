// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return head;
    Node *current = head;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    return temp->prev;
}