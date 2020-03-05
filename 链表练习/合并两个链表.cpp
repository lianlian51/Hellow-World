/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //检测l1和l2是否为空
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1; 
    
    //newHead最后返回的链表头，tail是中间插入的指针
    ListNode* newHead = NULL;
    ListNode* tail = NULL;

    //定义两个指针指向两个链表
    ListNode* pL1 = l1;
    ListNode* pL2 = l2;

    //newHead指向val小的
    if(pL1->val > pL2->val)
    {
        newHead = pL2;
        pL2 = pL2->next;
    }
    else
    {
        newHead = pL1;
        pL1 = pL1->next; 
    }

    //让tail指向newHead
    tail = newHead;


    //开始连接两个链表
    while(pL1 && pL2)
    {
        if(pL1->val > pL2->val)
        {
            //pL2连接到tail后面
            tail->next = pL2;
            pL2 = pL2->next;
        }
    else
        {
           //pL1连接到tail后面
           tail->next = pL1;
           pL1 = pL1->next; 
        }
        tail = tail->next;
    }


    //判断两个链表中是否还有值
    if(pL1)
        tail->next = pL1;
    else
        tail->next = pL2;

    return newHead;
    }
};
