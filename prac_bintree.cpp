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
            lca(n1,n2,root->right,v1,v3,v4);
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

     return {r.first+s.first+root->data,max(r.first,r.second)+max(s.first,s.second)};

}





    


int main() { 

  node* root=NULL;
  root= binarytree(root);
  printtree(root);
  cout<<endl;
  vector<int> v;
  store(v,root);


  for(auto i:v){
    cout<<i<<" ";
  }
  cout<<endl;
  vector<int> k,a,m;
  boundarytrav(root, k);

  for(int i=0;i<k.size();i++){
    cout<<k[i]<<" ";
  }

  cout<<endl;
  viewt(root,a);
// //   verttraversal(root,a);

  for(auto i:a){
    cout<<i<<" ";
  }
int mx=0;
longestsumpath(root,0,mx);
cout<<endl;
cout<<mx<<" "<<endl;
int sum=0;
int j=0;
sumonlongestline(root,0,0,j,sum);
cout<<sum<<" ";
int count=0;
int h=3;
cout<<endl;
// countksum(root,h,0,count);

cout<<count;





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