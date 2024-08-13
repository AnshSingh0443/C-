#include<iostream>
#include<vector>
using namespace std;

    vector<int> productExceptSelf(vector<int>& nums) {
        //BRUTEFORCE ->tle
        // vector<int>product;
        // for(int i=0;i<nums.size();i++){
        //     int elem=nums[i];
        //     int multip=1;
        //     for(int j=0;j<nums.size();j++){
        //         if(j==i){
        //             continue;
        //         }
        //         multip=multip*nums[j];
        //     }
        //     product.push_back(multip);
        // }
        // return product;


        //METHOD 2->DIVISON
        // vector<int>res;
        // int mul=1;
        // int mul_without_zero=1;
        // for(int i=0;i<nums.size();i++){
        //     mul=mul*nums[i];
        //     if(nums[i]!=0){
        //         mul_without_zero=mul_without_zero*nums[i];
        //     }

        // }
        // //check counnt of zeros
        // int count=0;
        // for(int i =0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         count++;
        //     }
        // }

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         //check if  another 0 is present count >1
        //         if(count>1){
        //             res.push_back(0);
        //         }else{
        //             res.push_back(mul_without_zero);
        //         }
                
        //     }else{
        //         int data=mul/nums[i];
        //         res.push_back(data);
        //     }
        // }
       
        // return res;

        //METHOD 3  
        //prifix and postfix product
        //(prefix)left product i right product(postfix)
        //so for i->res.push_back(left product*right product)
        //calculating prefix or left products
        // vector<int>prefix;
        // vector<int>res;
        // vector<int>postfix(nums.size(),0); 
        // //calcuating left product
        // prefix.push_back(1);
        // for(int i=1;i<nums.size();i++){
        //     int data=nums[i-1]*prefix[i-1];
        //     prefix.push_back(data);
        // }
        // //calulating right product
        // postfix[nums.size()-1]=1;
        // for(int i=nums.size()-2;i>=0;i--){
        //     postfix[i]=postfix[i+1]*nums[i+1];
        // }
        // //calulating result
        // for(int i=0;i<nums.size();i++){
        //     int data=(prefix[i]*postfix[i]);
        //     res.push_back(data);
        // }
        // return res;


        //METHOD 4->without creating array for postfix and prefix 
        //1st store prefix product in res
        //2nd then upadte res array by iterating on res and multiply->res[i]*right product
        int n = nums.size();
        vector<int> result(n, 1);   
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }   
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }
        return result;
    }

int main(){
    vector<int>nums={1,2,3,4};
    vector<int>res=productExceptSelf(nums);

    for(auto i:res){
        cout<<i<<" ";
    }

}