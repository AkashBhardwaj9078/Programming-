#include <bits/stdc++.h>

using namespace std;

// class node{
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int data){
//         data=data;
//         left=NULL;
//         right=NULL;
//     }


// };


// node* binarytree(node* &root){
//     cout<<"Enter root"<<" ";
//     int data;
//     cin>>data;
//     root=new node(data);
//     if(data==-1){
//         return NULL;
//     }
    
    
//     cout<<"Enter left value of "<<data;
//     root->left=binarytree(root->left);
//     cout<<"Enter right value of "<<data;
//     root->right=binarytree(root->right);
    

//    return root;
// }

// void printtree(node* &root){
      
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         node* temp=q.front();
//         q.pop();
//         if(temp==NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
           
//         }
        
//      else{
//                 cout<<temp->data<<" ";
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }


//     }

    


// }





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


void inordertraversal(node* &root){
    if(root==NULL){
        return;
    }

    if(root->left){
       inordertraversal(root->left);
    }
    
    cout<<root->data<<" ";
    if(root->right){
       inordertraversal(root->right);
    }
    

}

void preordertraversal(node* &root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
      preordertraversal(root->left);
    }

    if(root->right){
     preordertraversal(root->right);
    }
    
    
    

}


void postordertraversal(node* &root){
    if(root==NULL){
        return;
    }
    if(root->left){
       postordertraversal(root->left);
    }
    if(root->right){
       postordertraversal(root->right);
    }
    
    
    
    cout<<root->data<<" ";

}

void zigzag(node* &root,vector<vector<int>>&v){
    queue<node*> q;
    q.push(root);
    int c=1;
    while(!q.empty()){
        int size=q.size();
        vector<int> h(size);
        for(int i=0;i<size;i++){
            node* temp=q.front();
            q.pop();
            if(c==0){
                h[i]=temp->data;
            }
            else{
                h[size-i-1]=temp->data;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        
        }
        c=1-c;
        v.push_back(h);


    }
   


}


void leftraversal(node* &root){

if(root==NULL||(root->left==NULL and root->right==NULL)){
    return ;
}


cout<<root->data<<" ";
if(root->left){
    leftraversal(root->left);
}
else{
    leftraversal(root->right);
}

}


void leaves(node* &root){
    
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    if(root->left){
        leaves(root->left);
    }
    if(root->right){
        leaves(root->right);
    }
    

}





void righttraversal(node* &root){
      
      if(root==NULL||(root->left==NULL and root->right==NULL)){
        return ;
      }
      
      if(root->right){
        righttraversal(root->right); 
      }
      else{
        righttraversal(root->left);
      }

      cout<<root->data<<" ";










}


void bottomview(node* &root,vector<int> &v){
          map<int,int> m;
          queue<pair<node*,int>> q;
          q.push({root,0});

          while(!q.empty()){
           pair<node*,int> temp=q.front();
           q.pop();
           m[temp.second]=temp.first->data;

           if(temp.first->left){
             q.push({temp.first->left,temp.second-1});
           }
           if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
           }

          }


          for(auto i:m){
            v.push_back(i.second);
          }
}


void topview(node* &root,vector<int> &v){
          map<int,int> m;
          queue<pair<node*,int>> q;
          q.push({root,0});

          while(!q.empty()){
           pair<node*,int> temp=q.front();
           q.pop();

           if(m.find(temp.second)==m.end()){
            m[temp.second]=temp.first->data;
           }
          

           if(temp.first->left){
             q.push({temp.first->left,temp.second-1});
           }
           if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
           }

          }


          for(auto i:m){
            v.push_back(i.second);
          }
}

void leftview(node* &root,vector<int> &v){
          map<int,int> m;
          queue<pair<node*,int>> q;
          q.push({root,0});

          while(!q.empty()){
           pair<node*,int> temp=q.front();
           q.pop();

           if(m.find(temp.second)==m.end()){
            m[temp.second]=temp.first->data;
           }
          

           if(temp.first->left){
             q.push({temp.first->left,temp.second+11});
           }
           if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
           }

          }


          for(auto i:m){
            v.push_back(i.second);
          }
}

void  rightview(node* &root,vector<int> &v){
          map<int,int> m;
          queue<pair<node*,int>> q;
          q.push({root,0});

          while(!q.empty()){
           pair<node*,int> temp=q.front();
           q.pop();

           
          m[temp.second]=temp.first->data;
           
          

           if(temp.first->left){
             q.push({temp.first->left,temp.second+11});
           }
           if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
           }

          }


          for(auto i:m){
            v.push_back(i.second);
          }
}


void leftview(node* &root,vector<int> &v){
          map<int,int> m;
          queue<pair<node*,int>> q;
          q.push({root,0});

          while(!q.empty()){
           pair<node*,int> temp=q.front();
           q.pop();

           if(m.find(temp.second)==m.end()){
            m[temp.second]=temp.first->data;
           }
          

           if(temp.first->left){
             q.push({temp.first->left,temp.second+11});
           }
           if(temp.first->right){
            q.push({temp.first->right,temp.second+1});
           }

          }


          for(auto i:m){
            v.push_back(i.second);
          }
}


void longestsumpath(node* root,int sum,int &mx){
    if(root==NULL){
        return;
    }
    if(root->left and root->right){
        mx=max(mx,sum);
    }

    if(root->left){
        longestsumpath(root->left,sum+root->data,mx);
    }
    if(root->right){
        longestsumpath(root->right,sum+root->data,mx);
    }

}

void longestlinepath(node* root,int &summx,int n,int sum,int &mx){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        if(n>=mx){
            summx=
        }
    }
}




void boundarytraversal(node* root){
    leftraversal(root);
    leaves(root);
    righttraversal(root->right);
}




int main() {  
    node* root;
    root=binarytree(root);
    printtree(root);
   inordertraversal(root);
   cout<<endl;
   preordertraversal(root);
   cout<<endl;
   postordertraversal(root);
   cout<<endl;
   vector<vector<int>> v;
   zigzag(root,v);
   for(auto i:v){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
   boundarytraversal(root);


  return 0;
}