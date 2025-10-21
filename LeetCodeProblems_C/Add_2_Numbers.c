/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0){
        int sum = carry;

        if(l1 != NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2 != NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        carry = sum /10;
        int digit = sum % 10;
        tail->next = newNode(digit);
        tail = tail->next;

    }
    return dummy.next;
}