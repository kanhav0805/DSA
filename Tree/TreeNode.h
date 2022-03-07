//header file that contains the tree node class
#include<vector>
using namespace std;
template <typename T>
class TreeNode
{
	public:
	T data;//to store the data of type passes by the user
	vector<TreeNode*> children;//to store the address of the children
	//constructor of the class treenode
	TreeNode(T data)
	{
		this->data = data;
	}
};
