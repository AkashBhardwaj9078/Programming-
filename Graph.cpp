#include <bits/stdc++.h>

using namespace std;

class graph{
    public :
    unordered_map<int,list<int>> m;

    void addEdge(int u,int v,bool k){
        m[v].push_back(u);
        if(k==false){
            // undirected
           m[u].push_back(v);
        }

    }

    void dis(){
        for(auto i:m){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};



vector<vector<int>> k(int n,int m,vector<vector<int>> h){

    vector<vector<int>> edges(n);
    for(auto i:h){
       edges[i[0]].push_back(i[1]);
       edges[i[1]].push_back(i[0]);
    }
     
     vector<vector<int>> adj;
    for(int i=0;i<n;i++){
        // index value at beginning
        adj[i].push_back(i);
        // then their corresponding neighbours 
        //  i index
        for(int j=0;j<edges[i].size();j++){
            adj[i].push_back(edges[i][j]);

        }


    }
  return adj;
    

} 


// void _bfs_(int vert,map<int,pair<int,int>> &k,map<int,list<int>> m,vector<int> & d){

//    queue<int> q;
//    q.push(vert);
//    k[vert].second=1;

   
//    while(!q.empty()){
//        int p=q.front();
//        q.pop();
//        if(k[p].first==0){
//         d.push_back(p);
//         k[p].first=1;
         
//         for(auto i:m[p]){
//             if(k[i].second!=1){
                
//               q.push(i);
//               k[i].second=1;
//             }
            
//         }
//        }
      
       
       
//    } 

// }

vector<int> bfs(int vert,vector<pair<int,int>> v){

   graph h;
   for(int i=0;i<v.size();i++){
    h.addEdge(v[i].first,v[i].second,0);
    h.addEdge(v[i].second,v[i].first,0);
   }
   map<int,pair<int,int>> k;
   vector<int> d;
   queue<int> q;
   q.push(vert);
   k[vert].second=1;

   
   while(!q.empty()){
       int p=q.front();
       q.pop();
       if(k[p].first==0){
        d.push_back(p);
        k[p].first=1;
         
        for(auto i:h.m[p]){
            if(k[i].second!=1){
                
              q.push(i);
              k[i].second=1;
            }
            
        }
       }
      
       
       
   } 
return d;
}

void _bfs(unordered_map<int,list<int>> adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
     queue<int> q;
     q.push(node);
     visited[node]=1;

     while(!q.empty()){
        int n=q.front();
        ans.push_back(n);
        q.pop();
        
            for(auto j:adjList[n]){

                if(visited[j]){

                }
                if(!visited[j]){
                    q.push(j);
                    visited[j]=1;
                }
            }
    
        
     }
   


}









vector<int> bfs2(int vect,vector<pair<int,int>> v){
  
  unordered_map<int,list<int>> adjList;

  unordered_map<int,bool> visited;

  for(auto i:v){
    adjList[i.first].push_back(i.second);
    adjList[i.second].push_back(i.first);
  }
   
  
  vector<int> ans;
  
  for(int i=0;i<vect;i++){
    if(!visited[i]){
       _bfs(adjList,visited,ans,i); 
    }  

  }
   
 return ans;

}

void Dfs(int node, map<int,bool> &visited,unordered_map<int,vector<int>> m,vector<int> &ans,map<int,int> &k){

//   for(int i=0;i<m[node].size();i++){
//     if(!visited[m[node][i]]){
//         ans.push_back(m[node][i]);
//         visited[m[node][i]]=1;
         
//         Dfs(m[node][i],visited,m,ans);

        

//     }

//   }

  if(k[node]<m[node].size()){
    int i=k[node];
    
    if(!visited[m[node][i]]){
        k[node]++;
        ans.push_back(m[node][i]);
        visited[m[node][i]]=1;
        
         
        Dfs(m[node][i],visited,m,ans,k);
    }
    

  }
 else{
    return ;
 }

}

vector<int> dfs(int v,vector<pair<int,int>> &edges){
    unordered_map<int,vector<int>> m;
    map<int,int> k;

    for(auto i: edges){
        m[i.first].push_back(i.second);
        m[i.first].push_back(i.second);
        k[i.first]=0;
        k[i.second]=0;
        
    }
   map<int,bool> visited;
   vector<int> ans;
   


    for(int i=0;i<v;i++){
       Dfs(i,visited,m,ans,k);
    }
    return ans;
}

void DFS(int node,unordered_map<int,vector<int>> m,unordered_map<int,bool> &visited,vector<int> &h){
    if(!visited[node]){
        h.push_back(node);
        visited[node]=1;
    }
    for(auto i:m[node]){
        if(!visited[node]){
            DFS(i,m,visited,h);
        }
    }
}


vector<vector<int>> depthforsearch(int v,vector<pair<int,int>> edges){
  unordered_map<int,vector<int>> m;
  unordered_map<int,bool> visited;
  for(auto i:edges){
    m[i.first].push_back(i.second);
    m[i.second].push_back(i.first);
  }
  vector<vector<int>> k;
  for(int i=0;i<v;i++){
    vector<int> h;
    DFS(i,m,visited,h);
    k.push_back(h);
  }
}


bool iscyclic(int node, unordered_map<int,vector<int>> adjList,unordered_map<int,bool> &visited){
    unordered_map<int,int> parent;
    parent[node]=-1;
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int n=q.front();
        q.pop();

        for(auto i: adjList[n]){
              if(visited[i]==1 and parent[n]!=i ){

            return true;
        }
        else if(visited[i]==0){
            q.push(i);
            visited[i]=1;
            parent[i]=n;
        }



        }
        
      
    }
    return false;
}


bool cylic(int k,vector<pair<int,int>> edges){

 unordered_map<int,vector<int>> adjList;
    for(auto i: edges){
    adjList[i.first].push_back(i.second);
    adjList[i.second].push_back(i.first);
  }

  unordered_map<int,bool> visited;
  

  for(int i=0;i<k;i++){

    bool p=iscyclic(i,adjList,visited);
    if(p==true){
        return true;
    }
  }


  return false;
}

bool iscyclicDFS(int node,  
 unordered_map<int,vector<int>> adjList,unordered_map<int,bool> &visited,int parent){
visited[node]=1;
    
    for(auto i:adjList[node]){
        if(!visited[i]){
            bool p=iscyclicDFS(i,adjList,visited,node);
            if(p==true){
                return ;
            }
            
        }
        else if(i!=parent){
            return true;
        }
        
    }

   return false;

}

bool cylicDFS(int k,vector<pair<int,int>> edges){

 unordered_map<int,vector<int>> adjList;
    for(auto i: edges){
    adjList[i.first].push_back(i.second);
    adjList[i.second].push_back(i.first);
  }

  unordered_map<int,bool> visited;
  
 int parent=-1;
  for(int i=0;i<k;i++){

    bool p=iscyclicDFS(i,adjList,visited,-1);
    if(p==true){
        return true;
    }
  }


  return false;
}
bool iscycdirdfs(int node,unordered_map<int,vector<int>> adjList, unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited){

    visited[node]=1;
    dfsvisited[node]=1;
    for(auto i:adjList[node]){
        if(!visited[i]){
            bool k=iscycdirdfs(i,adjList,visited,dfsvisited);
            if(k==true){
                return true;
            }

        }
        else if(dfsvisited[i]){
            return true;
        }
    }
    dfsvisited[node]=0;
    return false;

}

bool cyclicdirected(int v,vector<pair<int,int>> edges){
 
 unordered_map<int,vector<int>> adjList;
    for(auto i: edges){
    adjList[i.first].push_back(i.second);   
  }
   unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;

    for(int i=0;i<v;i++){
        bool k= iscycdirdfs(i,adjList,visited,dfsvisited);
        if(k==true){
            return true;
        }
    }
   return false;

}


void toposort(int node,unordered_map<int,bool> &visited,stack<int> &p,unordered_map<int,vector<int>> &adjList){
   visited[node]=1;
   for(auto i:adjList[node]){
    if(!visited[i]){
        toposort(i,visited,p,adjList);
    }
   }
   
   
 p.push(node);


}


vector<int> topologicalsort(int v,vector<pair<int,int>> edges){
   
   unordered_map<int,vector<int>> adjList;
   for(auto i: edges){
    adjList[i.first].push_back(i.second);   
  }
  unordered_map<int,bool> visited;
  stack<int> p;
  for(int i=0;i<v;i++){
    if(!visited[i]){
     toposort(i,visited,p,adjList);
    }
  }
 vector<int> h;
 while(!p.empty()){
    h.push_back(p.top());
    p.pop();
 }
 return h;


}



vector<int> kahn(int v,vector<pair<int,int>> edges){

    unordered_map<int,vector<int>> adjList;
    for(auto i:edges){
        adjList[i.first].push_back(i.second);

    }
   
   vector<int> indegree(v);
   for(auto i:adjList){
    for(auto j:i.second){
       indegree[j]++;
    }
   }
     
  queue<int> q;
  for(int i=0;i<v;i++){
    if(indegree[i]==0){
        q.push(i);
    }
  }
  vector<int> h;
  while(!q.empty()){

    int n=q.front();
    h.push_back(n);
    q.pop();
    for(auto j:adjList[n]){
        indegree[j]--;
        if(indegree[j]==0){
            q.push(j);
        }
    }



    


  }

  return h;

  



}












int main() {  

int v;
cin>>v;
int edges;
cin>>edges;
graph h;
vector<pair<int,int>> k;
for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    k.push_back({u,v});
    h.addEdge(u,v,0);
}
h.dis();


for(auto i:bfs2(v,k)){
    cout<<i<<" ";
}
cout<<endl;

// for(auto i:bfs(0,k)){
//     cout<<i<<" ";
// }
// cout<<endl;

for(auto i:dfs(v,k)){
    cout<<i<<" ";
}












  

  return 0;
}