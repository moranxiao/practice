#pragma warning(disable:4996)
struct ListNode* FindKthToTail(struct ListNode* head, int k) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (k--)
    {
        if (!fast)
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}