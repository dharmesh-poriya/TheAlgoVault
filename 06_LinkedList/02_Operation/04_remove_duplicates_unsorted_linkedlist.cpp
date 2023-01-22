Node *removeDuplicates(Node *head)
{
    if (!head)
        return head;
    unordered_set<int> occured;
    Node *current = head->next;
    Node *prev = head;
    occured.insert(head->data);
    while (current)
    {
        if (occured.end() == occured.find(current->data))
        {
            occured.insert(current->data);
            prev = prev->next = current;
        }
        current = current->next;
    }
    prev->next = current;
    return head;
}