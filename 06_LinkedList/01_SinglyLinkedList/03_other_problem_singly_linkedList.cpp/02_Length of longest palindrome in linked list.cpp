// https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);

/* Driver program to test above function*/
int main()
{
    int T, n, l;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }

        cout << maxPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* The Node is defined
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int isPalindrome(Node *left, Node *right)
{
    int count = 0;
    while (NULL != left && NULL != right && left->data == right->data)
    {
        left = left->next;
        right = right->next;
        count++;
    }
    return 2 * count;
}
int maxPalindrome(Node *head)
{
    Node *prev, *next;
    prev = next = NULL;
    Node *current = head;
    int ans = 0;
    while (NULL != current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        int oddpalind = 0;
        if (NULL != next)
            oddpalind = isPalindrome(prev, next->next);
        int evenpalind = isPalindrome(prev, next);
        ans = max(ans, max(oddpalind + 1, evenpalind));
    }
    return ans;
}