#include <bits/stdc++.h>

using namespace std;

void store(unordered_map<int,vector<int>> m,unordered_map<int,int> &visited,int n,vector<int> &h){
    queue<int> q;
    q.push(n);
    visited[n]=1;
    while(!q.empty()){
        int p=q.front();
        h.push_back(p);
        q.pop();
        for(auto i:m[p]){
            if(!visited[i]){
                visited[i]=1;
                h.push_back(i);

            }
        }
    }
}

vector<int> bfs(int v,vector<pair<int,int>> edges){
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> visited;
    for(auto i:edges){
        m[i.first].push_back(i.second);
        m[i.second].push_back(i.first);
    }
    vector<int> h;
    for(int i=0;i<v;i++){
        if(!visited[i]){
             store(m,visited,i,h);
        }
    }
    return h;
}

void storedfs(unordered_map<int,vector<int>> m,unordered_map<int,int> &visited,int n,vector<int> &h){
    h.push_back(n);
    visited[n]=1;
    for(auto i:m[n]){
        if(!visited[i]){
            storedfs(m,visited,i,h);
        }
    }
  
}

vector<vector<int>> dfs(int v,vector<pair<int,int>> edges){
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> visited;
    for(auto i:edges){
        m[i.first].push_back(i.second);
        m[i.second].push_back(i.first);
    }
    vector<vector<int>> k;
    for(int i=0;i<v;i++){
        if(!visited[i]){
             vector<int> h;
             storedfs(m,visited,i,h);
             k.push_back(h);
        }
    }    


    return k;

}

bool isCycbfs(int n,unordered_map<int,int> &visited,unordered_map<int,vector<int>> m){
queue<int> q;
unordered_map<int,int> pr;
pr[n]=-1;
q.push(n);
visited[n]=1;
while(!q.empty()){
    int p=q.front();
    q.pop();
    for(auto i:m[p]){
        if(visited[i]==1 and pr[i]!=p){
            return true;
        }
        else{
            q.push(i);
            visited[i]=1;
            pr[i]=p;
        }
    }

}

return false; 

}


bool isCycdfs(int n,int pr,unordered_map<int,int> &visited,unordered_map<int,vector<int>> m){
  visited[n]=1;

  for(auto i:m[n]){
    if(visited[i]==1 ){
        bool h=isCycdfs(i,n,visited,m);
        if(h==true){
            return true;
        }
    }
    else if(pr!=i){
        return true;
    }
  }
   

}

bool isCyc(int v,vector<pair<int,int>> edges){
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> visited;
    for(auto i:edges){
        m[i.first].push_back(i.second);
       
    }
    
    for(int i=0;i<v;i++){
        
        int r=-1;
        bool p=isCycbfs(i,visited,m);
        // bool p=isCycdfs(i,r,visited,m);
        if(p==true){
            return true;
        }
    }
    return false;
}


bool isCyc(int v,vector<pair<int,int>> edges){
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> visited;
    for(auto i:edges){
        m[i.first].push_back(i.second);
              
    }
    
    for(int i=0;i<v;i++){
        int r=-1;
        bool p=isCycbfs(i,visited,m);
        // bool p=isCycdfs(i,r,visited,m);
        if(p==true){
            return true;
        }
    }
    return false;
}

vector<int> kahn(int v,vector<pair<int,int>> edges){
  unordered_map<int,vector<int>> m;
  unordered_map<int,int> visited;
  for(auto i:edges){
        m[i.first].push_back(i.second);
  }
    map<int,int> indegree;

    queue<int> q;
    for(auto i:m){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    for(auto i:indegree){
      if(i.second==0){
        q.push(i.first);
      }
    }
    vector<int> h;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        h.push_back(p);

        for(auto i:m[p]){
            indegree[i]--;
            if(indegree[i]==0){
             q.push(i);
            }
        }




    }

    return h;
}



void toposort(int n,unordered_map<int,int> visited,stack<int> h,unordered_map<int,vector<int>> m){

    visited[n]=1;
    for(auto i:m[n]){
        if(!visited[i]){
            toposort(i,visited,h,m);
        }
    }
    h.push(n);
}

vector<int> topologicalsort(int v,vector<pair<int,int>> edges){
    unordered_map<int,vector<int>> m;
    unordered_map<int,int> visited;
    for(auto i:edges){
        m[i.first].push_back(i.second);
              
    }
    stack<int> h;
    vector<int> k;
    for(int i=0;i<v;i++){
        toposort(i,visited,h,m);
    }
    while(!h.empty()){
       k.push_back(h.top());
       h.pop();

    }
    return k;
}

vector<int> shortestpath(vector<pair<int,int>> edges,int src,int dest,int v){

    unordered_map<int,vector<int>> m;
    for(auto i:edges){
        m[i.first].push_back(i.second);
        m[i.second].push_back(i.first);
    }
    
    unordered_map<int,int> k;
    queue<int> q;
    // src or 1st node;
    
    q.push(1);
   
    k[1]=-1;

    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(auto i:m[n]){
            if(k[i]==0){
                q.push(i);
                
                k[i]=n;
            }
        }


    }
    vector<int> h;
    
    while(dest!=src ){
        // if it goes in a cycle
        
        h.push_back(dest);
        dest=k[dest];
        if(h.size()> v||dest==-1){
            return {};
        }

        

        
    }
    reverse(h.begin(),h.end());

  return h;


}

int partition(int arr[],int l,int r){
    int j=-1;
    for(int i=0;i<r;i++){
        if(arr[i]<arr[r]){
            j++;
            swap(arr[i],arr[j]);
        }
        
    }
    j++;
    swap(arr[j],arr[r]);
    return j;


}


void quicksort(int arr[],int l,int r){

    if(l<r){
      int k=partition(arr,l,r);
      quicksort(arr,l,k-1);
      quicksort(arr,k+1,r);


    }
}

void merge(int arr[],int l,int r,int m){

    int a=m-l+1;
    int b=r-m;

    int k[a],h[b];

    for(int i=0;i<a;i++){
       k[i]=arr[i+l];
    }
    for(int i=0;i<b;i++){
        h[i]=arr[i+m+1];
    }

    int r=0,e=0;
    for(int i=l;i<=r;i++){
        if(k[e]<h[r]){
            arr[i]=k[e++];
        }
        else{
            arr[i]=k[r++];
        }
    }

    
}

void mergesort(int arr[],int l,int r){

    if(l<r){
        int m=l+(l-r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,r,m);


    }
}







#include <bits/stdc++.h>

using namespace std;

int main() {  

  return 0;
}























// void dijkstra(int v,vector<pair<pair<int,int>,int>> m,int edges,int  src){
//       unordered_map<int,vector<pair<int,int>>> adjList;
//     for(auto i:m){     
//         adjList[i.first.first].push_back({i.first.second,i.second});
//         adjList[i.first.second].push_back({i.first.first,i.second});
//     }


//     set<pair<int,int>> st;


//     vector<int> vertices;
//     for(int i=0;i<v;i++){
//         vertices[i]=INT_MAX;
//     }
//     vertices[src]=0;
    

//     st.push({0,src});

//     while(!st.empty()){

//         pair<int,int> r=st.top();


//      if(r.first+r.second<vertices[r.first]){

//         auto i=st.find({vertices[r.first],r.first});


//      }


        




        

        
//     }



    




    



    


// }

















