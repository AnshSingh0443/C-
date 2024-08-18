#include<iostream>
#include<vector>

using namespace std;
//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        ListNode*prev=head;
        if(prev==NULL){
            return ans;
        }
        ListNode*curr=head->next;
        if(curr==NULL){
            return ans;
        }
        ListNode*nxt=head->next->next;
        if(nxt==NULL){
            return ans;
        }

        int firstCP=-1;
        int LastCP=-1;
        int mindis=INT_MAX;
        int i=1;
        while(nxt){
            //cp->either local maxima or local minima
            bool isCP=((curr->val > prev->val && curr->val >nxt->val) ||
                        (curr->val <prev->val && curr->val <nxt->val )) ? true:false;

            if(isCP && firstCP==-1){
                //cp hai aur first cp hai then
                firstCP=i;
                LastCP=i;
            }
            else if(isCP){
                //not first cp
                //2 cp hai->cal min dis
                mindis=min(mindis,i-LastCP);
                //update last cp to this i
                LastCP=i;
            }
            ++i;
           prev=prev->next;
           curr=curr->next;
           nxt=nxt->next;
        }
        if(LastCP==firstCP){
            //only 1 cp was found
            return ans;
        }
        else{
            ans[0]=mindis;
            ans[1]=LastCP-firstCP;
        }
        return ans;
        
    }

int main(){

}