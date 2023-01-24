// https://leetcode.com/problems/remove-duplicates-from-sorted-list/


ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return head;

    ListNode *current = head->next;
    ListNode *prev = head;

    while (current)
    {
        if (prev->val != current->val)
            prev = prev->next = current;
        current = current->next;
    }
    prev->next = nullptr;
    return head;
}