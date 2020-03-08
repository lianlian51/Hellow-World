/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    
    //监测数据是否为空
    if(head == NULL)
        return NULL;

    ListNode* fast = head;
    ListNode* slow = head;

    //判定是否有环
    bool iscircle = false;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            iscircle = true;
            break;
        }

    }

    if(!iscircle)
        return NULL;
       

    ListNode* pH = head;
    ListNode* pM = slow;

    //遍历链表，找到第一个入口点
    while(pM != pH)
    {
        pH = pH->next;
        pM = pM->next;
    }
    return pH;
}
