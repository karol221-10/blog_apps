#include <iostream>
#include <memory>
#include <vector>
using namespace std;
struct TreeNode {
    weak_ptr<TreeNode> parent;
    vector<shared_ptr<TreeNode>> children;
    int key;
};
void addChildren(shared_ptr<TreeNode> root,int value) {
    shared_ptr<TreeNode> child = make_shared<TreeNode>();
    child->key = value;
    root->children.push_back(child);
    child->parent = root;
}
void printValue(shared_ptr<TreeNode> root,int level = 1) {
    if(root==nullptr) {
        cout<<"Root is empty"<<endl;
        return;
    }
    int new_level = level+1;
    for(int i = 0;i<root->children.size();i++) {
        printValue(root->children[i],new_level);
    }
    cout<<"Level: "<<level<<endl;
    cout<<"Value: "<<root->key<<endl;
}
int main()
{
    shared_ptr<TreeNode> root = make_shared<TreeNode>();
    root->key = 10;
    addChildren(root,30);
    addChildren(root,15);
    addChildren(root->children[0],20);
    addChildren(root->children[0],17);
    printValue(root);
    cout<<"Clear tree"<<endl;
    root.reset();
    printValue(root);
    return 0;
}
