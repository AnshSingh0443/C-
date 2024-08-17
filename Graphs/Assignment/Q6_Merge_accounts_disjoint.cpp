#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

//https://leetcode.com/problems/accounts-merge/description/

using namespace std;
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u]>rank[v]){
            parent[v]=u;
            rank[u]++;
        }else{
            parent[u]=v;
            rank[v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //union and find from disjoint sets?
        //logic->
        //accounts[i][]->ith account
        //account[i][0]->name of ith account
        //acount[i][j>0]->emails of that ith account

        //same email-> same account->name --->merge/union-->account
        int n=accounts.size();//->no of accounts
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            // each account is treated as an indidivuall intially ie they are parent of themself
            parent[i]=i;
        }
        
        //we will make a map to keep track of which email belong to which accounnt
        unordered_map<string,int>mp;
        //merge condition->if we ecounter a eamil which already belongs to a ceratin diff account we can merge these accounts
        for(int i=0;i<n;i++){
            auto account=accounts[i];
            //traverse all emails of that account (start from 1 becuz 0 pr accounnt name hai)
            for(int j=1;j<account.size();j++){
                string &mail=account[j];
                //if the mail does not exisit in map add it
                auto it=mp.find(mail);
                if(it==mp.end()){
                    //mail belongs to ith mail
                    mp[mail]=i;
                }else{
                    //mail already exists for an account->merge with that account
                    unionSet(i,it->second,parent,rank); 
                }
            }
        }
        //now parent vector->jis accouts/index ka parent->parent[i]-->same hai vo merge honge
        //first map k according phle mail store kar do using parent
        unordered_map<int,set<string>>preans;
        //why set->mail sorted mai chaiye acc to qn
        for(auto it:mp){
            auto accountno=it.second;
            auto mail=it.first;
            accountno=findParent(parent,accountno);
            //insert mail acc to paernt
            preans[accountno].insert(mail);
            
        }

        //but we need to return ans in vector<vector<string>>
        vector<vector<string>>ans;
        for(auto it:preans){
            int account_no=it.first;
            auto mails=it.second;
            vector<string>v;
            v.push_back(accounts[account_no][0]);//insert name
            for(auto mail:mails){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;

        
    }

int main(){
    return 0;
}