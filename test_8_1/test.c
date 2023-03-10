#pragma warning(disable:4996)
struct Node* creat_node(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->next = NULL;
    node->val = val;
    return node;
}
struct Node* copyRandomList(struct Node* head) {
    if (!head)
        return NULL;
    struct Node* cur = head;
    while (cur)
    {
        struct Node* newnode = creat_node(cur->val);
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode->next;
    }
    cur = head;
    while (cur)
    {
        if (cur->random == NULL)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    cur = head;
    struct Node* copy_head = cur->next;
    struct Node* copy = head;
    while (cur)
    {
        copy = cur->next;
        cur = copy->next;
        if (!cur)
        {
            copy->next = NULL;
            break;
        }
        copy->next = cur->next;
    }
    return copy_head;
}