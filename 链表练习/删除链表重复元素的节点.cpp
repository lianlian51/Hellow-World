/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
       ListNode* cur =pHead;
       ListNode* prev = NULL;
        
        //先找到重复元素的范围，然后进行逐个删除
        while(cur)
        {
            // 找到重复元素范围
            ListNode* start = cur;
            ListNode* end = cur->next;
            while(end)
            {
                //如果是start->val， end->val相等的话，就让end往后走，直到不相等
                if(start->val != end->val)
                    break;
                end = end->next;
            }
            
            //此时范围已经确定
            
            //判断一下，如果end是start的next，则表示范围中没有重复元素
            if(start->next == end)
            {
                //prev标记cur，cur往后走
                prev = cur;
                cur = cur->next;
            }
            else{
                    while(start != end)
                    {
                        //逐个是头部有相等的元素，删除的方法
                        if(start == pHead)
                        {
                            pHead = pHead->next;
                            free(start);
                            start = pHead;
                        }
                        else
                        {
                            //去除特殊情况之后的删除方法
                            prev->next = start->next;
                            free(start);
                            start = prev->next;
                        }
                    }
              cur  = start;
            }
        }
        return pHead;
    }
};
