/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;


struct ListNode* insertionSortList(struct ListNode* head){
    //新建一个链表，最后返回插入完成
    ListNode* newhead = NULL;
    ListNode* cur = head;

    //让cur遍历原链表
    while(cur)
    {
        //让head往后走一下
        head = cur->next;

        ListNode* pos = newhead;
        ListNode* prev = NULL;
        //一，先找插入的位置
        while(pos)
        {
            if(pos->val >cur->val)
               break;
            
            //利用prev标记pos的上一个位置，便于之后插入
            prev = pos;
            pos = pos->next;
        }

        //二，将cur插入到newhead中
        if(pos == newhead)
        {  
            //cur的值小于newhead的所有，选择头插
            cur->next = newhead;
            newhead = cur;
        }
        else{
            //尾插和中间插入一样的，就合并在一起
            cur->next = pos;
            prev->next = cur;
        }
        
        //最后把head给cur
        cur = head;
    }
    return newhead;
}
