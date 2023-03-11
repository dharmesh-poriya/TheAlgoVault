ListNode *getMiddle(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}