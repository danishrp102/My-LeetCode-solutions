// Problem link: https://leetcode.com/problems/validate-binary-tree-nodes/description/

// Explanation:
// The given binary tree is valid iff there is only one root for the tree (the problem requires this condition to be satisfied)
// The inDegree of the root node (the number of nodes directing to the root node) must be zero (by definition)
// For the binary tree to be valid, the inDegree of the nodes other than the root node must be 1 for it to form a valid binary tree
// So we calculate inDegrees for all the nodes in the tree and there must be exactly one node with inDegree = 0 (root node) and rest of the (n - 1) nodes must have an inDegree of 1
// After this condition is satisfied, it is required that from the root node, all the other nodes must be reachable i.e, the count of the nodes reached from the root node should be equal to the total number of nodes given i.e. n
// If the count is equal to n, the tree is valid, else invalid

class Solution {
public:

    int solve(int node, vector <int> &leftChild, vector <int> &rightChild) {
        if(node == -1)
            return 0;
        return 1 + solve(leftChild[node], leftChild, rightChild) + solve(rightChild[node], leftChild, rightChild);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector <int> inDegree(n, 0);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1)
                inDegree[leftChild[i]]++;
            if(rightChild[i] != -1)
                inDegree[rightChild[i]]++;
        }

        int a1 = 0, a2 = 0, root = -1;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0)
                a1++, root = i;
            else if(inDegree[i] == 1)
                a2++;
        }

        if(a1 != 1 || a2 != (n - 1))
            return false;

        int ans = solve(root, leftChild, rightChild);
        return (ans == n);
    }
};
