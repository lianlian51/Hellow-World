//二叉树的层序遍历
//这里需要用到队列，所以要先把队列的头文件拿过来才可以用
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return NULL;

	QueueInit(&q);
	//取pRoot 的根节点入队列
	QueuePush(&q,pRoot);

	//1.先标记队列里的节点
	//2.出队列
	//3.然后判断，将有孩子的节点入队列
	//4.循环上面
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		QueuePop(&q);

		printf("%d ", pCur->val);

		if (pCur->pleft)
			QueuePush(&q, pCur->pleft);

		if (pCur->pright)
			QueuePush(&q, pCur->pright);
	}
	printf("\n");
}
