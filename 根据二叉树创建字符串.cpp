    void front_order(TreeNode* root,string& ans){
        if(root==nullptr){
            return ;
        }
        ans+=to_string(root->val);
        if(root->left||root->right){ 
    //左需要特殊判断,左右均有/只有右/只有左,都需要打印左,即使是空括号
            ans+='(';
            front_order(root->left,ans);
            ans+=')';
        }
        if(root->right){ //右只需要在它存在时打印
            ans+="(";
            front_order(root->right,ans);
            ans+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        front_order(root,ans);
        return ans;
    }
