#include <bits/stdc++.h>

using namespace std;



void rev(queue<int> &q){

    stack<int> m;


    while(!q.empty()){
        int p=q.front();
        q.pop();
        m.push(p);
        
        
    }
    while(!m.empty()){
       q.push (m.top());
       m.pop();
    }
}

// vector<int> firstnegative(vector<int> v,int k){
//     vector<int>h;
// queue <int> q; 
// int m=0;
// for(int i=0;i<v.size();i++){
//     if(i<k){
//         q.push(v[i]);
//         if(m==0 and v[i]<0){
//             m=v[i];
            
//         }
//         if(i==k-1){
//             h.push_back(m);
//         }
//     }
    
//     else{
//         if(q.front()<0){
//             q.pop();
//             q.push(v[i]);
//             queue<int>d=q;
//             while(!d.empty() and d.front()>0){
//                 d.pop();
//             }
//             if(d.empty()){
//                 h.push_back(0);
//             }
//             else{
//                 m=d.front();
//                 h.push_back(m);
//             }
//         }
//         else{
//             h.push_back(m);
//             q.pop();
//             q.push(v[i]);

//         }
//     }

// }

// return h;
// }

vector<int> firstnegative(vector<int> v,int k){
  vector<int> h;
  queue<int> q;
  int m=0;
  for(int i=0;i<v.size();i++){
    if(i<k){
       q.push(v[i]);
       if(m==0 and v[i]<0){
        m=v[i];
       }
       if(i==k-1){
        h.push_back(m);
       }
    }
    else{
        q.push(v[i]);
        if(q.front()<0){
            q.pop();
            queue<int> r=q;
            while(!r.empty() and r.front()>0){
                r.pop();


            }
            if(!r.empty()){
                m=r.front();
                h.push_back(r.front());
            }
            else{
                h.push_back(0);
            }
        }
        else{
            h.push_back(m);
            q.pop();
        }


    }
  }
  return h;


}



queue<int> revkelement(queue<int>q,int k){
    queue<int> h;
    stack<int> p;
    while(k--){
      p.push(q.front());
      q.pop();
    }
    while(!p.empty()){
        h.push(p.top());
        p.pop();
           
    }
while(!q.empty()){
    h.push(q.front());
    q.pop();
}

   return h;

}


string nonreapeat(string h){
   map<int,int> m;
   int k=0;
   char p;
   string j;
  for(int i=0;i<h.length();i++){
      
     
        m[h[i]]++;
        
            while(m[h[p]]>1 and p<=i){
                p++;

            }
            if(p<=i){
                j+=h[p];
            }
            else{
                j+="#";
                p=i;
            }
        
      
      

       
  }

 return j;
    

}
string nonempty(string h){

    map<char,int> m;
    queue<char> q;
    string b;
    for(int i=0;i<h.size();i++){
        m[h[i]]++;
        q.push(h[i]);
        while(!q.empty()){
            if(m[q.front()]<=1){
                b+=q.front();
                break;
            }
            else{
                q.pop();
            }
        }

        if(q.empty()){
            b+="#";
        }
         
    }

    return b;
}


int countinuousarr(vector<vector<int>> v){
int start=0;
int bal=0,deficit=0;
for(int i=0;i<v.size();i++){
    bal+=v[i][0]-v[i][1];
    if(bal<0){

        start=i+1;
        deficit+=bal;
    }

}
if(bal+deficit>0){
    return start;
}
else{
    return -1;
}

}


queue<int> ret(vector<int> &v){

   queue<int> q;
   for(int i=0;i<v.size()/2;i++){
    q.push(v[i]);
    q.push(v[i+v.size()/2]);
     
      
   }

}

class kQueue{
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;
    public:
    kQueue(int n,int k){
        this->n=n;
        this->k=k;
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        arr=new int[n];
        freespot=0; 

    }

    void enqueue(int data,int qn){

        //overflow
        if(freespot==-1){
            cout<<"No space is left";
            return;
        }
        //freeindex
        int idx=freespot;
        freespot=next[idx];
         //check first element
        if(front[qn-1]==-1){
            front[qn-1]=idx;
        }
        else{
            //linking new elements
            next[rear[qn-1]]=idx;
        }

        next[idx]=-1;
        rear[qn-1]=idx;
        arr[qn-1]=idx;
    }

    int dequeue(int qn){
        if(front[qn-1]==-1){
            cout<<"Queue Underflow";
            return -1;
        }
        int idx=front[qn-1];
        front[qn-1]=next[idx];
        next[idx]=freespot;
       return arr[idx];

    }



};









int main() {  

//   queue <int> q;
        
//         q.push(15);
//         q.push(16);
//         q.push(17);

//         rev(q);
//         for(int i=0;i<q.size();i++){
//             cout<<q.front()<<" ";
//             q.pop();
//         }
// vector<int> v={-8,2,3,-6,10};
// for (auto i : firstnegative(v,2)){
// cout<<i<<" ";
// }
// cout<<endl;
//   queue<int> p,r;
//   p.push(1);
//   p.push(2);
//   p.push(3);
//   p.push(4);
//   p.push(5);

//  r= revkelement(p,3);
//  while(!r.empty()){
//     cout<<r.front()<<" ";
//     r.pop();
//  }


//continuoussubarray()



// cout<<nonempty("zz");

// vector<vector<int>> v={{6,5},{7,6},{4,7},{10,8},{6,6},{5,4}};
// queue<vector<int>> q;
// queue<int> o;
// int w;

// int s=0;
// int idx=-1;
// for(int i=0;i<2*v.size();i++){
//     i=(i%v.size());
//     s+=(v[i][0]-v[i][1]);
//     if(s>=0){
//       q.push(v[i]);
//       o.push(i);
//     }
//     else{
//         while(s<0){

//         if(!q.empty()){
//             vector<int> h=q.front();
//             s-=(h[0]-h[1]);
//             q.pop();
//             o.pop();
//         }
//         else{
//             s=0;
//         }

//         }
        

//     }

//     if(q.size()==v.size()){
//         w=o.front();
//         break;
//     }

  

//   stack<int> p,r;
//   p.push(20);


//   p.push(22);
//   p.push(23);
//   p.push(24);
//   p.push(25);
//   p.push(26);

// int size=(p.size()/2);

// while(size--){
//     r.push(p.top());
//     p.pop();


// }

// p.pop();
// while(!r.empty()){
   
//    p.push(r.top());
//    r.pop();
// }







    
    



// }

// cout<<w;

 

  return 0;
}