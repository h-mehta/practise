
/*

Link: https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75

547. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

*/


class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, bool* visited, int node){
        visited[node] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i]==1 && !visited[i]){
                dfs(isConnected, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        bool* visited = new bool[isConnected.size()];
        memset(visited, false, isConnected.size()*sizeof(bool));

        int no_of_provinces = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(isConnected, visited, i);
                no_of_provinces++;
            }
        }
        return no_of_provinces;
    }
};





