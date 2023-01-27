// https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

Node *deleteNode(Node *head, int x)
{
    Node *current = head;
    Node *previouse = NULL;
    x--;
    while (x--)
    {
        previouse = current;
        current = current->next;
    }
    if (NULL == previouse)
    {
        head = current->next;
        delete current;
        return head;
    }
    previouse->next = current->next;
    delete current;
    return head;
}