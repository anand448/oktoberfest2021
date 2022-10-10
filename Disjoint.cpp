#include <iostream>
#include <vector>

using namespace std;

int find1(int x, vector<int> &root){             //union & find function to find root node (without path compression)
    return root[x];
}
// Time-Complexity: O(1)

void union1(int x, int y, vector<int> &root){
    int rootx=find1(x,root);
    int rooty=find1(y,root);
    if(rootx!=rooty){
        for(int i=0;i<root.size();i++){
            if(root[i]==rooty){
                root[i]=rootx;
            }
        }
    }
}
// Time-Complexity: O(n)

int find2(int x, vector<int> &root){            //union & find function to connect two nodes (without rank optimization)
    while(x!=root[x])
        x=root[x];
    return x;
}
// Time-Complexity: O(n)

void union2(int x, int y, vector<int> &root){            
    int rootx=find2(x,root);
    int rooty=find2(y,root);
    if(rootx!=rooty)
        root[rooty]=rootx;
}
// Time-Complexity: O(n)

int find3(int x, vector<int> &root){            //union & find function to connect two nodes (with rank optimization)
    while(x!=root[x])
        x=root[x];
    return x;
}
// Time-Complexity: O(log(n))

void union3(int x, int y, vector<int> &root, vector<int> &rank){           
    int rootx=find3(x,root);
    int rooty=find3(y,root);
    if(rootx!=rooty)
        if(rank[rootx]>rank[rooty])
            root[rooty]=rootx;
        else if(rank[rootx]<rank[rooty])
            root[rootx]=rooty;
        else{
            root[rootx]=rooty;
            rank[rootx]++;
        }      
}
// Time-Complexity: O(log(n))

int find4(int x, vector<int> &root){            //union function to connect two nodes (with rank optimization & path compression)
    if(x==root[x])
        return x;
    return root[x]=find4(root[x],root);
}
// Time-Complexity: O(alpha(n))

int union4(int x, int y, vector<int> &root, vector<int> &rank){
    int rootx=find4(x,root);
    int rooty=find4(y,root);
    if(rootx!=rooty)
        if(rank[rootx]>rank[rooty])
            root[rooty]=rootx;
        else if(rank[rootx]<rank[rooty])
            root[rootx]=rooty;
        else{
            root[rootx]=rooty;
            rank[rootx]++;
        } 
}
// Time-Complexity: O(alpha(n))        alpha function is called Inverse Ackermann Function which in practice is assumed as constant

int main(){
    int n;
    cin >> n;
    vector<int> root(n);
    for(int i=0;i<n;i++)
        root[i]=i;

    vector<int> rank(n,0)/*,size(n,1)*/;          //rank array (or size array) stores the rank of tree (stores the size of tree - no. of nodes in tree)
}