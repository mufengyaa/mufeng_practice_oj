	void inorder(TreeNode* root,TreeNode*& prev){
		if(root==nullptr){
			return;
		}
		inorder(root->left,prev);
		root->left=prev;
		if(prev){ //prev会为空,所以需要判断,不然就越界了
			prev->right=root;
		}
		prev=root; //因为之后要进root的后继结点了,所以需要更新prev
		inorder(root->right,prev);
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree==nullptr){
			return nullptr;
		}
		TreeNode *prev=nullptr,*tmp=pRootOfTree;
		while(tmp->left!=nullptr){ //拿到链表的第一个结点
			tmp=tmp->left;
		}
		inorder(pRootOfTree,prev);
		return tmp;
    }
