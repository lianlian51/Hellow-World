#include "BSTree.hpp"

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
		std::cout << "5 ÕÒµ½ £¡" << std::endl;
	}
	else
	{
		std::cout << "5 É¾³ý £¡" << std::endl;
	}

	return 0;
}