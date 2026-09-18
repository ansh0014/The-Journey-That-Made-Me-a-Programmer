// right now i am doing the check if dfs strings are plindromes 
// i have given a tree at node 0, consisting of n nodes, numbered from 0 to n-1. The tree is represented by an array parent of size n, where parent[i] is the parent of node i. since node 0 is the root parent[0]==-1
// i have given a string s of length n, where s[i] is the character assigned to node i
// consider an empty string dfsSdtr, and define a recusive function dfs(int x) that takes a node x as a parameter and performs the following steps in orders
// iterate over each child y of x in creasing order of their numbers. can call dfs(y).
// add the charcter s[x] to the end of the string dfsStr.
// note that dfsStr is shared acrsso all recusive calls of dfs.
// i need to find a boolean array answer of size n, where for each index i from 0 to n-1, i do the following
// empty the string dfsStr, and call dfs(i).
// if the resulting string dfsStr is a palindrome, then set answer[i] to rue. otherwise set anser[i] to false
// approach 
