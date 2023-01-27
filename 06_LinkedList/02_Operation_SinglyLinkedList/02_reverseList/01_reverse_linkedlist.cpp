// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Iterative method
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev, *next, *current;
        prev = next = nullptr;
        current = head;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// Recursive method
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// add first method
// → iteratively traversed linked list and pass each node to addFirst function and maintain one head.