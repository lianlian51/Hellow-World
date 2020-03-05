/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/


class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // 如果链表为空，直接返回空
        if(NULL == pHead)
            return NULL;
        
        //定义一个cur遍历pHead
        ListNode* cur = pHead;
        
        //定义两个结构体类型的变量，后面加（），赋初值
        ListNode lessHead(0);
        ListNode greatHead(0);
        
        //定义两个链表，指向两个结构体类型的变量
        ListNode* lessTail = &lessHead;
        ListNode* greatTail = &greatHead;
        
        //开始遍历pHead，分割数组
        while(cur)
        {
            if(cur->val<x)
            {
                //将小的放在lessHead后面
                lessTail->next = cur;
                lessTail = cur;
            }
            else 
            {
                //大的放在greatHed后面
                greatTail->next = cur;
                greatTail = cur;
            }
            //cur向后走
            cur = cur->next;
        }
        
        //连接两个链表
        lessTail->next = greatHead.next;
        //将greatHead链表结尾置为空
        greatTail->next = NULL;
        //返回链表
        return lessHead.next;
    }
};
