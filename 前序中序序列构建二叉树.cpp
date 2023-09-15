class Solution {
public:
    TreeNode* _build(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend) {
        if (inbegin > inend) { //数组不合法,说明不存在这个结点,所以返回空
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[prei]); //按照前序构建二叉树(因为先拿到的都是根结点)
        int begin = inbegin;
        // while(preorder[prei]!=inorder[begin]&&begin<=inend){
        //     begin++;
        // }
        for (; begin <= inend; ++begin) { //在中序中找到根结点
            if (preorder[prei] == inorder[begin]) {
                break;
            }
        }
        ++prei; //拿到下一个结点
        node->left = _build(preorder, inorder, prei, inbegin, begin - 1);//在找到的根结点,左区间是左子树
        node->right = _build(preorder, inorder, prei, begin + 1, inend);//同理
        return node;//左右子树构建完毕后,返回该结点
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prei = 0, inbegin = 0, inend = inorder.size();
        TreeNode* root = _build(preorder, inorder, prei, 0, (int)inorder.size() - 1);
        //注意这里的prei是引用
        return root; //最后返回的就是根结点
    }
};
