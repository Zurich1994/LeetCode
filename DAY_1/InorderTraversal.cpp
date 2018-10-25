#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x){
		val = x;
		left = NULL;
		right = NULL;
	 }
};
vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> nodes;
    vector<int> result;
    TreeNode *now = root;
    do {
        while(now != NULL) {
            nodes.push(now);
            now = now->left;
        }
        if(!nodes.empty()) {
            now = nodes.top();
            nodes.pop();
            result.push_back(now->val);
            now = now->right;
        }
    }while(!nodes.empty() || now!=NULL);
    return result;
}
int main() {
    int a[4] = {1,-1,3,4};
    vector<int> result;
    vector<int>::iterator it;
    TreeNode tr(a[0]),t1(a[2]),t2(a[3]);
    tr.right = &t1;
    t1.left = &t2;
    result = inorderTraversal(&tr);
    for(it=result.begin();it!=result.end();it++)
        cout<<*it<<endl;
    return 1;
}
