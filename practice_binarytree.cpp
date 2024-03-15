#include <bits/stdc++.h>

using namespace std;

class node{
    public:
   int data;
   node* left;
   node* right; 
   node( int dat){
    data=dat;
    left=NULL;
    right=NULL;
   }
};


node* binarytree(node* &root){
      cout<<"enter data"<<endl;
      int data;
      cin>>data;
       root= new node(data);
      if(data==-1){
        return NULL;
      }
      
    
        cout<<"enter left of "<<data<<endl;
         root->left=binarytree(root->left);
      
      
      cout<<"enter right of "<<data<<endl;
      root->right=binarytree(root->right);

      return root;





}
// node* buildtree(node* root){
//     cout<<"enter root:";
//     int a;
//     cin>>a;
//     root =new node(a);
//     if(a==-1){
//         return ;
//     }
    

//     cout<<"enter left value"<<endl;
//     root->left=buildtree(root->left);
//     cout<<"enter right value"<<endl;
//     root->right=buildtree(root->right);




    



//  return root;
// }

// LNR->inorder
// NLR->preorder
// // RLN->postorder
// void inordertraversal(node* &root){

    
//   node* temp=root;
// //   cout<<root->data; preorder
//   if(temp->left){
//     inordertraversal(temp->left);
//   }
// //    cout<<root->data; inorder

//   if(temp->right){
//     inordertraversal(temp->right);
//   }
// //    cout<<root->data; postorder
// }


void inordertraversal(node* &root){
node* temp=root;
if(temp==NULL){
    return;
}

if(temp->left){
    inordertraversal(temp->left);
}
cout<<temp->data<<" ";

if(temp->right){
    inordertraversal(temp->right);
}
}
// void printtree(node* root){
//     node* temp=root;
//     queue<node*> q;
//     q.push(temp);
//     q.push(NULL);

//     while(!q.empty()){
//         node* n=q.front();
//         q.pop();

//         if(n==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//         cout<<n->data<<" ";          
//         if(n->left){
//             q.push(n->left);
//         }
//         if(n->right){
//             q.push(n->right);
//         }
//         } 
//     }



// }







void printtree(node* &root){
    queue<node*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp= q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }

}

// void zigzag(vector<vector<int>> &k,node* root){
//    queue<node*> q;

//     q.push(root);
//     q.push(NULL);
//     int p=0;
//     while(!q.empty()){
//       int s=q.size();
//       vector<int> h(s);
//       for(int i=0;i<s;i++){
//         node* r=q.front();
//         q.pop();
        
//         if(p==1){
//             h[i]=r->data;
          
//         }
//         else{
//            h[s-1-i]=r->data;
//         }



//         if(r->left){
//             q.push(r->left);
//         }
//         if(r->right){
//             q.push(r->right);
//         }

//       }
//       p=1-p;
//       k.push_back(h);



//     }


// }





void store(vector<int> &h,node* root){
    queue<node*> q;
    q.push(root);
    int c=0;
    while(!q.empty()){
        int size=q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();


            if(c==0){
              v[i]= temp->data;
            }
            else{
              v[size-1-i]=temp->data;
            }

            if(temp->left){
                q.push(temp->left);

            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        c=1-c;
        for(auto i:v){
           h.push_back(i);
        }

    }

}




 





void  lefttrav(node* root,vector<int> &v){
     if(root==NULL||(root->left==NULL and root->right==NULL)){
        return ;
     }
     v.push_back(root->data);
     if(root->left){
        lefttrav(root->left,v);
     }
     else{
        lefttrav(root->right,v);
     }

}


void leaves(node* root,vector<int> &v){
    if(root==NULL){
       return;
    }
    if(root->left==NULL and root->right==NULL){
        v.push_back(root->data);
        return;
    }
    if(root->left){
        leaves(root->left,v);
    }
    if(root->right){
        leaves(root->right,v);
    }

}

void righttrav( vector <int> &v,node* root){

    if(root==NULL||root->left==NULL and root->right==NULL){
        return ;
    }
   

    if(root->right){
        righttrav(v,root->right);
    }
    else{
        righttrav(v,root->left);
    }   
    v.push_back(root->data);
}

void boundarytrav(node* root,vector<int> & v){
    lefttrav(root,v);
    leaves(root,v);
    righttrav(v,root->right);
}





















// void verttraversal(node* &root,vector<int> &v){
//     if(root==NULL){
//         return ;
//     }


//     map<int,map<int,vector<int>>> m;  
//     queue<pair<node*,pair<int,int>>> q;
//     q.push(make_pair(root,make_pair(0,0)));
    
//     while(!q.empty()){
//         pair<node*,pair<int,int>> temp=q.front();
//         q.pop();

//         m[temp.second.first][temp.second.second].push_back(temp.first->data);

//         if(temp.first->left){
//             q.push(make_pair(root->left,make_pair(temp.second.first-1,temp.second.second+1)));
//         }
//         if(temp.first->right){
//             q.push(make_pair(root->right,make_pair(temp.second.first+1,temp.second.second+1)));
//         }      

//     }

//     for(auto i:m){
//         for(auto j:i.second){
//             for(auto k:j.second){
//                 v.push_back(k);
//             }
//         }
//     }

// }





void leftbottraversal(node* root,vector<int> &v){
    if(root==NULL){
        return ;
    }
    if(root->left){
        leftbottraversal(root->left,v);
    } 
    v.push_back(root->data);
}
void rightnormaltraversal(node* root,vector<int> &v){
    if(root==NULL){
        return ;
    }

    v.push_back(root->data);
    if(root->right){
       rightnormaltraversal(root->right,v);
    }
    
}




void  viewt(node* &root,vector<int> &v){
    leftbottraversal(root,v);
    rightnormaltraversal(root->right,v);
    

}

void  view(node* root,vector<int> v){
  map<int,vector<int>> m;
  queue <pair<node*,int>> q;
  q.push(make_pair(root,0));
  while(!q.empty()){
     pair<node*,int>temp=q.front();
     q.pop();
     if(m[temp.second].empty()){
       m[temp.second].push_back(temp.first->data);
     }
     if(temp.first->left){
        q.push(make_pair(root->left,temp.second-1));

     }
     if(temp.first->right){
        q.push(make_pair(root->right,temp.second+1));
     }

     
     

   
  }

  for(auto i:m){
    v.push_back(i.second[0]);
  }

}


void  leftview(node* root,vector<int> &v){
         
         map<int,int> m;
         queue <pair<node*,int>> q;

         q.push(make_pair(root,0));

         while(!q.empty()){
            pair<node*,int> temp=q.front();
            q.pop();
            if(m.find(temp.second)==m.end()){
              m[temp.second]=(temp.first->data);
            }
            if(temp.first->left){
                q.push(make_pair(temp.first->left,temp.second+1));
            }
            if(temp.first->right){
                q.push(make_pair(temp.first->right,temp.second+1));
            }
            
         }
         

         for(auto i:m){
            v.push_back(i.second);
         }


}



void bottomview(node* root,vector<int> &v){
    
    map<int,int> m;
   queue<pair<node*,int>> q;
   q.push(make_pair(root,0));
   
   while(!q.empty()){
     pair<node*,int> r=q.front();
     q.pop();
     m[r.second]=r.first->data;
     if(root->left){
        q.push(make_pair(root->left,r.second-1));
     }
     if(root->right){
        q.push(make_pair(root->right,r.second+1));
     }
     
     
   }

   for(auto i:m){
    v.push_back(i.second);
   }


   

}

void longestsumpath(node* root,int sum,int &m){
    m=max(m,sum);
    // if(root->left==NULL and root->right==NULL){
    //      return;
    // }
    if(root->left){
        longestsumpath(root->left,sum+root->data,m);
    }
    if(root->right){
        longestsumpath(root->right,sum+root->data,m);
    }
}


void sumonlongestline(node* root,int sum,int len,int &lenm,int &ans){
    if(root==NULL){
        return;
    }
    
    if(root->left==NULL and root->right==NULL and len>=lenm){
        
        lenm=len;
        if(len==lenm){
            ans=max(ans,sum);
        }
        else{
            ans=sum;
        }
            

    }
    

    if(root->left){
        sumonlongestline(root->left,sum+(root->data),len+1,lenm,ans);
    }
    if(root->right){
        sumonlongestline(root->right,sum+(root->data),len+1,lenm,ans);
    }

}


// void lca(node* n1,node* n2,node* root){

//      if(root==NULL){

//      }
//      store(cordinates,value) all the way along the path,and  whenever n1 or n2 is found;break;
//      and take last intersecting element of both the sets

     



// }

void lca(node* n1,node* n2,node* root,vector<node*> v1,vector<node*> &v3,vector<node*> &v4){
        
if(root==NULL){
            return ;
        }
       
    v1.push_back(root);
if(root==n1){
            v3=v1; 
            return;           
        }
if(root==n2){
            v4=v1;
            return;
        }
if(root->left){
            lca(n1,n2,root->left,v1,v3,v4);
        }
if(root->right){
            lca(n1,n2,root->right,v1,v3,v4);
        }
              
}

node* lastelement(vector<node*> v1,vector<node*> v2){
    int m=min(v1.size(),v2.size());
    while(v1[m]!=v2[m] and m>=0){
        m--;
    }
    if(m>0){
        return v1[m];
    }
    else{
       return NULL;
    }
}

node* lca2(node* root ,node* n1,node * n2){
  if(root==NULL){
    return NULL;
  }
  if(root==n1||root==n2){
   return  root;
  }

  if(lca2(root->left,n1,n2)==NULL and lca2(root->right,n1,n2)==NULL){
      return NULL;
  }
  if(lca2(root->left,n1,n2)!=NULL and lca2(root->right,n1,n2)==NULL){
     return lca2(root->left,n1,n2);
  }
  if(lca2(root->left,n1,n2)==NULL and lca2(root->right,n1,n2)!=NULL){
     return lca2(root->right,n1,n2);
  }
  if(lca2(root->left,n1,n2)!=NULL and lca2(root->right,n1,n2)!=NULL){
    return root;
  }

}





void countksum1(node* root,int k,int sum,int &count){
    
    if(root==NULL){
        return;
    } 
     if(sum==k){
        count++;
    } 
    if(root->left==NULL and root->right==NULL){
        if(sum+root->data==k){
            count++;
        }
    }
    
    if(root->left){
        countksum1(root->left,k,0,count);
        if(sum<k){
         countksum1(root->left,k,sum+root->data,count);
        }
        
    }
    if(root->right){
        countksum1(root->right,k,0,count);
        if(sum<k){
          countksum1(root->right,k,sum+root->data,count);
        }
        
    } 
    
     
}
void countksum1(node* root,int k,vector<int> v,int &count){
    
    if(root==NULL){
        return ;
    }
   
    v.push_back(root->data);
    countksum1(root->left,k,v,count);
    countksum1(root->right,k,v,count);

    int sum=0;
    for(int i=v.size()-1;i>=0;i--){
        sum+=v[i];
        if(sum==k){
            count++;
        }
    }

    v.pop_back();

}


// node* kthancestor(node* root,node* n1,vector<node*> v,int k){
//      if(root==NULL){
//        return NULL;
//      }
//      v.push_back(root);
//      if(root==n1){
//         return v[v.size()-k];
//      }
//      kthancestor(root->left,n1,v,k);
//      kthancestor(root->right,n1,v,k);
//      v.pop_back();
     

// }

pair<node*,int> kthancfromnode(node* root,node* n,int lev,int k){
      if(root==NULL){
        return {NULL,-1};
      }
      if(root==n){
        return {root,k};
      }
      pair<node*,int> p=kthancfromnode(root->left,n,lev+1,k);
      pair<node*,int> r=kthancfromnode(root->right,n,lev+1,k);
      if(p.first!=NULL and r.first==NULL){
         if(p.second-lev==k){
            return {root,INT_MAX};
         }
         else{
            return p;
         }
      }
      if(p.first==NULL and r.first!=NULL){
         if(r.second-lev==k){
            return {root,INT_MAX};
         }
         else{
            return r;
         }
      }
      if(p.first==NULL and r.first==NULL){
        return {NULL,-1};
      }


}




node* kthanc(node* root,int &k,node* n){
   if(root==NULL){
    return NULL;
   }
   if(root==n){
    return root;
   }
   if(kthanc(root->left,k,n)==NULL and kthanc(root->right,k,n)!=NULL){
        k--;
        if(k==0){
            return root;
        }
        else{
          return kthanc(root->right,k,n);
        }
   }
   if(kthanc(root->left,k,n)!=NULL and kthanc(root->right,k,n)==NULL){
        k--;
        if(k==0){
            return root;
            
        }
        else{
          return kthanc(root->left,k,n);
        }
   }
   

}


// int alternatedescentsum(node* root){
//     if(root==NULL){
//         return 0;
//     }
//   else if(root->left==NULL and root->right==NULL){
//             return 0;
//     }
//    else if(root->left==NULL and root->right!=NULL){
//             return  alternatedescentsum(root->right->right)+alternatedescentsum(root->right->left);
//     }
//   else  if(root->left!=NULL and root->right==NULL){
//             return  alternatedescentsum(root->left->right)+alternatedescentsum(root->left->left);
//     }
//   else  return (root->data+ alternatedescentsum(root->left->left)+alternatedescentsum(root->left->right)+alternatedescentsum(root->right->left)+alternatedescentsum(root->right->right));

// }

// int maxsumofnonadj(node* root){

//     return max(alternatedescentsum(root),(alternatedescentsum(root->left)+alternatedescentsum(root->right)));
// }

// void maxsumofnonadj(node* root,int k,int &sum1,int &sum2){
//     if(root==NULL){
//         return;
//     }
//     if(k%2==0){
//         sum1+=root->data;
//     }
//     if(k%2==1){
//         sum2+=root->data;
//     }
//     maxsumofnonadj(root->left,k+1,sum1,sum2);
//     maxsumofnonadj(root->right,k+1,sum1,sum2);

// }

// int mx(node* root){
//possible to have elements from same level and some might be excluded also
//     int num1,num2;
//     maxsumofnonadj(root,0,num1,num2);
//     return max(num1,num2);
// }

pair<int,int> nonadjsum(node* root){
     if(root==NULL){
        return {0,0};
     }

     pair<int,int> r=nonadjsum(root->left);
     pair<int,int> s=nonadjsum(root->right);

     return {r.first+s.first+root->data,max(r.first,r.second)+max(s.first,s.second)};}
void mapped(int arr[],map<int,int> m,int n){

    for(int i=0;i<n;i++){
        m[arr[i]]=i;
    }


}

 node* solve(int in[],int pre[],int &idx,int instart,int inend,int n,map<int,int> m){
           if(idx>=n|| instart > inend){
                 return NULL;
           }  
           int pos; 
        //    int pos=m[pre[idx]];
           for(int i=0;i<n;i++){
            if(in[i]==pre[idx]){
                pos=i;
                break;
            }
           }  
           node* ret=new node(pre[idx]);
           idx++;
           ret->left=solve(in,pre,idx,instart,pos-1,n,m);
           ret->right=solve(in,pre,idx,pos+1,inend,n,m);
           return ret;

 }





void buildtree(int in[],int pre[],node* &root,int n){
   int preordrind=0;
   map<int,int> m;
   mapped(in,m,n);
    root=solve(in,pre,preordrind,0,n-1,n,m);
}

class heap{
    public:
    int arr[100];
    int index=0;

    heap(){
        arr[0]=-1;
        index++;

    }

    void  insertion(int val){
        
       index++;
       int size=index;
       arr[size]=val;
       while(arr[size/2]<arr[size] and size>1){
            swap(arr[size/2],arr[size]);
            size/=2;


       }

    }


    void deletion(){
        if(index==0){
            cout<<"not possible";
            return ;
        }


        arr[1]=arr[index];
        index--;
        int k=1;
    
        while(k<index){
            
            if(2*k<=index and arr[k]<arr[2*k]){
                swap(arr[k],arr[2*k]);
                k=2*k;
            }
            else if(2*k+1<=index and arr[k]<arr[2*k+1]){
                swap(arr[k],arr[2*k+1]);
                k=2*k+1;
            }
            else{
                break;
            }
            
        }

        

    }

    bool heapcheck(){
        int i=index/2;
        for(int j=i;j>=0;j--){
            if(2*j+1<=index){
                if(arr[i]<arr[2*i] || arr[i]<arr[2*i+1]){

                    return false;
                } 
            }
            else{
                if(arr[i]<arr[2*i]){
                    return false;
                }
            }



        }


     return true;
    }

    void print(){
        for(int i=1;i<=index;i++){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};


void  heapify(int arr[],int n,int i){
    int j=i;
    
    if(2*i<=n and arr[i]<arr[2*i]){
        i=2*i;
    }
    if(2*i<=n and arr[i]<arr[2*i+1]){
        i=2*i+1;
    }
    if(j!=i){
        swap(arr[j],arr[i]);
        heapify(arr,n,j);
    }
}


void num(  pair<int,int> h,int r,int & k,map<pair<int,int>,int> &m)
{
    if(m[h]!=1){
       if(r>k){
            k=r;
        }
        m[h]=0; 
 
        num({h.first-1,h.second+1},r+1,k,m); 
        num({h.first+1,h.second+1},r+1,k,m); 
        num({h.first+1,h.second-1},r+1,k,m);  
        num({h.first-1,h.second-1},r+1,k,m); 
            
                
    }
    
}


// void morris(node* r){
 
//  node* temp=r;

 



// while(temp!=NULL){

//     if(temp->left==NULL){
//        cout<<temp->data<<" ";
//        temp=temp->right;
//     }

//     else{
//         node* curr=temp->left;
//         while(curr->left!=NULL and curr->right!=NULL){
          
//         curr=curr->right;
//         }
//         if(curr->right==NULL){
//         curr->right=temp;
//         temp=temp->left;
//         }

    
//         else{
//         temp->right=NULL;
//         cout<<temp->data<<" ";
//         temp=temp->right;
//         }


//     }
// }
// }

// void morrisNLR(node* r){
//     node* temp=r;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
 
//         if(temp->left!=NULL){
//             temp=temp->right;         
//         }
//         else{
//             node* curr=temp->left;
//             while(curr->right==NULL){
//                 curr=curr->right;
//             }
//             if()



//         }
//     }

// }











// void num(  pair<int,int> h,int r,int & k,map<pair<int,int>,int> &m)
// {
//     if(visited[h]!=NULL){
//        if(r>k){
//             k=r;
//         }
//         visited[h]=NULL;
// 

//               if(r->left){


    // }
// 
// 
// 


// 
// 
   
        
 
//         num(r-left),r+1,k,m); 
//         num({r-right,r+1,k,m); 
//         num(m[r],r+1,k,m);  
//         
            
                
//     }
    
// }



int minburn(node* root, node* j){

    map<pair<int,int>,int> m;
    pair<int,int> h;
     
    queue<pair<pair<int,int>,node*>> q;
    q.push({{0,0},root});
    while(!q.empty()){
        pair<pair<int,int>,node*> r= q.front();
        if(r.second==j){
              
              h=r.first;
              m[r.first]=1;

        }
        if(r.second->left){
           q.push({{r.first.first-1,r.first.second+1},r.second->left});
        }

         if(r.second->right){
           q.push({{r.first.first+1,r.first.second+1},r.second->right});
        }
    }

    int k=0;
    int i=0;
    num(h,k,i,m);
    return i;
    

  
}
// count fun(int )















int main() { 

//   node* root=NULL;
//   root= binarytree(root);
//   printtree(root);
//   cout<<endl;
//   vector<int> v;
//   store(v,root);


//   for(auto i:v){
//     cout<<i<<" ";
//   }
//   cout<<endl;
//   vector<int> k,a,m;
//   boundarytrav(root, k);

//   for(int i=0;i<k.size();i++){
//     cout<<k[i]<<" ";
//   }

//   cout<<endl;
//   viewt(root,a);
// // //   verttraversal(root,a);

//   for(auto i:a){
//     cout<<i<<" ";
//   }
// int mx=0;
// longestsumpath(root,0,mx);
// cout<<endl;
// cout<<mx<<" "<<endl;
// int sum=0;
// int j=0;
// sumonlongestline(root,0,0,j,sum);
// cout<<sum<<" ";
// int count=0;
// int h=3;
// cout<<endl;


// int in[]={3,1,4,0,5,2};
// int pre[]={0,1,3,4,2,5};

// node* root2;
// buildtree(in,pre,root2,6);
// printtree(root2);






//   cout<<endl;
//   bottomview(root,m);

//   for(auto i: m){
//     cout<<i<<" ";
//   }
// view(root,m);
//  for(auto i:m){
//     cout<<i<<" ";
//  }









  
  



  return 0;
}