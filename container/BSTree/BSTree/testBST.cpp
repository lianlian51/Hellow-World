// #include "BSTree.hpp"
//#include "AVLTree.hpp"
//#include <iostream>
//using namespace std;
#if 0
int main()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : arr)
		t.Insert(e);

	t.InOrder();

	t.Erase(0);
	t.InOrder();
	std::cout << std::endl;
	t.Erase(5);
	t.InOrder();
	std::cout << std::endl;
	t.Erase(9);
	t.InOrder();

	if (t.Find(5))
	{
		std::cout << "5 找到 ！" << std::endl;
	}
	else
	{
		std::cout << "5 删除 ！" << std::endl;
	}

	return 0;
}
#endif

#if 0
int main()
{
	int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr2[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int> avl1, avl2;
	for (auto& e : arr1)
		avl1.Insert(e);
	for (auto& e : arr2)
		avl2.Insert(e);

	bool isBalance = avl1.isBalanceTree();
	if (isBalance)
	{
		std::cout << "avl1 是平衡的！！！" << std::endl;
	}
	else
	{
		std::cout << "avl1 是不平衡的！！！" << std::endl;
	}
	avl1.InOrder();
	std::cout << std::endl;

	isBalance = avl2.isBalanceTree();
	if (isBalance)
	{
		std::cout << "avl2 是平衡的！！！" << std::endl;
	}
	else
	{
		std::cout << "avl2 是不平衡的！！！" << std::endl;
	}
	avl2.InOrder();
	std::cout << std::endl;


	return 0;
}

#endif


// #include "RBTree.hpp"
// #include "map.h"
// #include "set.h"

#include "hashBucket.hpp"
int main()
{
	// TestAVLTree();
	// TestRBTree();
	// TestMap();
	// TestSet();
	TestHashBucket();
	return 0;
}