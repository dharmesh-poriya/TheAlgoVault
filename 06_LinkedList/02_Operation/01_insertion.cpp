Node *insertAtBegining(Node *head, int x)
{
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
    if (!head)
    {
        return insertAtBegining(head, x);
    }
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    Node *newNode = new Node(x);
    current->next = newNode;
    return head;
}