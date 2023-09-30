#include<iostream>

int main(){
    int n,m;
    std::cin>>n>>m;
    int graph[n+1][n+1] = {{0}};
    for(int i=0;i<m;i++){
        int a,b;
        std::cin>>a;
        std::cin>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}