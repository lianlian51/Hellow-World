/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//C语言中一般加上这个
typedef struct ListNode ListNode;

bool hasCycle(struct ListNode *head) {
    //快慢指针访问，如果成环，则返回true
    ListNode* fast = head;
    ListNode* slow = head;

    //检测head是否为空链表
    if(head == NULL)
       return false;

    //快慢指针遍历，如果最后地址相等，则表示成环
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
           return true;
    }

    return false;
}
