#pragma warning(disable:4996)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (--n)
    {
        fast = fast->next;
    }
    struct ListNode* prev = slow;
    while (fast->next)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }
    if (prev == slow)
    {
        head = slow->next;
        return head;
    }
    prev->next = slow->next;
    return head;
}