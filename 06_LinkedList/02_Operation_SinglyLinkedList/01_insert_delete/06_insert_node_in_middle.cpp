// https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1

Node *middleNode(Node *head)
{
    Node *slow, *fast;
    slow = head;
    fast = head->next;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *insertInMiddle(Node *head, int x)
{
    if (!head)
        return head;
    Node *middle = new Node(x);
    Node *prevMiddle = middleNode(head);
    middle->next = prevMiddle->next;
    prevMiddle->next = middle;
    return head;
}