int findKthLargest(vector<int>& nums, int k) {
        // //大堆
        // priority_queue<int> q(nums.begin(),nums.end());
        // while(--k){
        //     q.pop();
        // }
        // return q.top();
 
        //小堆
         priority_queue<int,vector<int>,greater<int>> q(nums.begin(),nums.begin()+k);
         for(auto i=nums.begin()+k;i!=nums.end();++i){
             if(*i>q.top()){
                q.pop();
                q.push(*i);
             }
         }
         return q.top();
    }
