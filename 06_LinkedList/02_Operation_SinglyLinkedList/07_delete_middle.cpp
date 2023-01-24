// https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

Node *middleNode(Node *head)
{
    Node *prev, *slow, *fast;
    prev = NULL;
    slow = fast = head;
    while (fast and fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev;
}
Node *deleteMid(Node *head)
{
    if (!head)
        return head;
    Node *prev = middleNode(head);
    if (!prev)
    {
        return prev;
    }
    prev->next = prev->next->next;
    return head;
}