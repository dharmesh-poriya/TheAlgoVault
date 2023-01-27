// iterative

bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

// recursive

bool search(struct Node* head, int x)
{
    if (!head)
        return false;
    if (head->key == x)
        return true;
    return search(head->next, x);
}