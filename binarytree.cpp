#include <bits/stdc++.h>
#include "../../../mingw64/include/c++/12.2.0/bits/valarray_after.h"

using namespace std;

class node {
    public:

    int data;
    node* left;
    node* right;

    node(){
        data=0;
        left=NULL;
        right=NULL;
    }

     node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

node* binarytree(node* &root){

    cout<<"Enter value :-"<<endl;
    int n;
    cin>>n;
    if(n==-1 ) {
        
        return NULL;
    }
    
    node* newnode=new node(n);
    
    cout<<"Enter left  value of "<<n<<endl;

    
    newnode->left=binarytree(newnode->left);

    cout<<"Enter right  value of "<<n<<endl;
   
    cout<<n<<endl;
    
    newnode->right=binarytree(newnode->right);

    root=newnode;

    return root;
    
    




}

void traversal(node* &root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* r=q.front();
        q.pop();
        if(r==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
            }
        }
        else{
            cout<<r->data<<" ";
            if(r->left) q.push(r->left);
            if(r->right) q.push(r->right);
        }
    }
}

// void reverseordertraversal(node* root){
//     if(root->left==NULL and root->right==NULL){
//          cout<<root->data<<" ";
//          return ;
//     }

//     if(root->left){
//         reverseordertraversal(root->left);
//     }

//      if(root->right){
//         reverseordertraversal(root->left);
//     }

//     // cout<<root->data<<" ";
// }
void preordertraversl(node* root){
   
   if(root==NULL) return ;

   cout<<root->data<<" ";

   if(root->left){
    preordertraversl(root->left);
   }
   if(root->right){
    preordertraversl(root->right);
   }


}

void postordertraversal(node* root){
   
   if(root==NULL) return ;

   

   if(root->left){
    postordertraversal(root->left);
   }
   if(root->right){
    postordertraversal(root->right);
   }
   cout<<root->data<<" ";


}
void inordertraversal(node* root){
   
   if(root==NULL) return ;

   

   if(root->left){
    inordertraversal(root->left);
   }
   cout<<root->data<<" ";
   if(root->right){
    inordertraversal(root->right);
   }
   


}

void buildtree(node* &root,vector<int>v){
    queue<node*> q;
     int i=0;
    node* rt=new node(v[0]);
    root=rt;
    q.push(root);
    
 

    while(!q.empty()){
        node* r=q.front();
        q.pop();
             i++;
            if(v[i]!=-1){
                node* rleft=new node(v[i]);
                r->left=rleft;
                q.push(r->left);

            }
            i++;
             if(v[i]!=-1){
                node* rright=new node(v[i]);
                r->right=rright;
                q.push(r->right);

            }
            

        
    }
}

void leafcount(node* root,int &p){
       if(root->left==NULL and root->right==NULL){
              p++;
              return ;
       }
       if(root->left){
         leafcount(root->left,p);
       }
          if(root->right){
         leafcount(root->right,p);
       }
      
       
}
int leafcount2(node* root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 1;
    int ans=0;
    if(root->left) ans+=leafcount2(root->left);
    if(root->right) ans+=leafcount2(root->right);

    return ans;

}

int height(node* root){

    if(root==NULL) return 0;
     
    return 1+max(height(root->left),height(root->right));


}

pair<int,int> heightdiameter(node* root){
    if(root==NULL) return {0,0} ;
    pair<int,int> l=heightdiameter(root->left);
    pair<int,int> r=heightdiameter(root->right);

    int h=1+max(l.first,r.first);
    int d=max(l.second,max(r.second,1+l.first+r.first));

    return {h,d};



}
pair<bool,int> balancedtree(node* root){
    if(root==NULL) return {true,0};
    pair<bool,int> l=balancedtree(root->left);
    pair<bool,int> r=balancedtree(root->right);
    bool  bal=l.first and r.first and (abs(l.second-r.second)<=1);
    int h=1+max(l.second,r.second);
    return {bal,h};

}

bool issame(node* root1,node* root2){
    if((root1==NULL and root2==NULL)){
        return true;
    }
    if((root1!=NULL and root2==NULL)||(root1==NULL and root2!=NULL)){
        return true;
    }
 
    bool ans= (root1->data==root2->data) and issame(root1->left,root2->left) and issame(root1->right,root2->right);
    return ans;
}  

pair<bool,int> issumtree(node* root){
    if(root==NULL) return {true,0};
    pair<bool,int> l=issumtree(root->left);
    pair<bool,int> r=issumtree(root->right);
    bool t=l.first and r.first and (root->data==l.second+r.second);
    return {t,root->data+l.second+r.second};

}

void zigzagtraversal(node* &root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int f=0;
    while(!q.empty()){
        vector<int> v(q.size()-1);
        int n=q.size()-1;
        int i=0;
       while(q.front()!=NULL){
        node* r=q.front();
        q.pop();
        if(f==0){
           v[i]=r->data;
         
        }
        else{
            v[n-1-i]=r->data;
        }
        i++;
        if(r->left) q.push(r->left);
        if(r->right) q.push(r->right);
       }
       q.pop();
       if(!q.empty()) q.push(NULL);
       f=1-f;
       for(auto i:v) cout<<i<<" ";
       cout<<endl;




    }
}
void printleft(node* root){
    if(root->left==NULL and root->right==NULL){
        return ;
    }
    cout<<root->data<<" ";
    if(root->left) printleft(root->left);
    else printleft(root->right);

}
void printleaf(node* root){
    if(root->left==NULL and root->right==NULL){
        cout<<root->data<<" ";
        return ;
    }
    if(root->left) printleaf(root->left);
    if(root->right) printleaf(root->right);

}
void printright(node* root){
    if(root->left==NULL and root->right==NULL){
        return ;
    }
    
    if(root->right) printright(root->right);
    else printright(root->left);
    cout<<root->data<<" ";

}

void boundarytraversal(node* root){
   
    printleft(root);
    printleaf(root);
    printright(root->right);
}
void verticalordertraversal(node* root,int i,int j,map<int,map<int,vector<int>>> &np){
    if(root==NULL) return ;
    np[i][j].push_back(root->data);
    if(root->left) verticalordertraversal(root->left,i-1,j+1,np);
    if(root->right) verticalordertraversal(root->right,i+1,j+1,np);


}

void topview(node* root,int i,int j,map<int,pair<int,int>> &np){
    if(root==NULL) return;
   if(np.find(i)!=end(np)) {
    if(np[i].second>j){
        np[i]={root->data,j};
    }
   }
   else np[i]={root->data,j};
    if(root->left) topview(root->left,i-1,j+1,np);
    if(root->right) topview(root->right,i+1,j+1,np);
}

void leftview(node* root,int i,map<int,int> &lfv){
    if(root==NULL) return ;
    if(lfv.find(i)==end(lfv))
       lfv[i]=root->data;
    if(root->left) leftview(root->left,i+1,lfv);
    if(root->right) leftview(root->right,i+1,lfv);
    
    
}
void sumofnodesonlongestpath(node* root,pair<int,int> &ans,int i,int sum){
    if(root==NULL){
        if(i>ans.second){
            ans={sum,i};
         
         }
         else if(i==ans.second){
            ans.first=max(ans.first,sum);
         }
        return ;
    }
    
     sumofnodesonlongestpath(root->left,ans,i+1,sum+root->data);
     sumofnodesonlongestpath(root->right,ans,i+1,sum+root->data);

}

node* LCA(node* r1,node* r2,node* root){
    if(root==NULL) return NULL ;
    if(root==r1||root==r2){
        return root;
    }
    node* l=LCA(r1,r2,root->left);
    node* r=LCA(r1,r2,root->right);

    if(l!=NULL and r!=NULL){
        return root;
    }
   else if(l!=NULL and r==NULL){
        return l;
    }
   else if(l==NULL and r!=NULL){
        return r;
    }
    else if(l==NULL and r==NULL){
        return NULL;
    }

 return NULL;
}
// void sumK(node* root,int k,int sum,int &c){
   
//     if(sum==k) c++;
//     if(root==NULL) return ;

//     sumK(root->left,k,sum+root->data,c);
//     sumK(root->left,k,root->data,c);

//     sumK(root->right,k,sum+root->data,c);
//     sumK(root->right,k,root->data,c);




// }

void sumk(node* root,int k,int &c,vector<int> v){
    if(root==NULL) return ;
    v.push_back(root->data);
    sumk(root->left,k,c,v);
    sumk(root->right,k,c,v);
    int s=0;
    for(int i=v.size()-1;i>=0;i--){
        s+=v[i];
        if(s==k) c++;
    }

    v.pop_back();

}
// node* Kthancestor(node* root,int k, node* r,int p){
//     if(root==NULL and k==-1) return NULL;
//     if(k==1) return root;
//     if(k>1){
//         return Kthancestor(root,k-1,r,p);
//     }
//     if(root==r and k==-1){
//         return Kthancestor(root,p-1,r,p);
//     }
//     node* lef=Kthancestor(root->left,k,r,p);
//     node* rig=Kthancestor(root->right,k,r,p);

//     if(lef==NULL and rig==NULL){
//         return NULL;
//     }
//    else if(lef==r|| rig==r){
//         return root;
//     }
//    else if(lef!=r and lef!=NULL and rig==NULL){
//         return lef;
//     }
//    else if(lef==NULL and rig!=r and rig!=NULL){
//         return rig;
//     }
// }

node* kthancestor(node* root,int &k ,node* r){
      if(root==NULL) return NULL;
      if(root==r){
        return root;
      }

      node* lef=kthancestor(root->left,k,r);
      node* rig=kthancestor(root->right,k,r);

      if(lef!=NULL and rig==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else return lef;

      }
       if(lef==NULL and rig!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else return rig;

      }
      else NULL;


}
void  kthancestor2(node* root,node* r,int k,vector<node*> v,node* &ans){
    if(root==NULL);
    if(root==r){
        if(v.size()<k) ans=NULL;
        else ans= v[v.size()-k];
     
        return ;
    }
    
    v.push_back(root);
    kthancestor2(root->left,r,k,v,ans);
    kthancestor2(root->right,r,k,v,ans);

    v.pop_back();

    
    
}

pair<int,int> nonadjsum(node* root){
     if(root==NULL) return {0,0};
     pair<int,int> l=nonadjsum(root->left);
     pair<int,int> r=nonadjsum(root->right);

     return {root->data+l.second+r.second,max(l.first,l.second)+max(r.first,r.second)};

}

// node* buildtreefromprein(int &i,int ins,int ine,vector<int> in,vector<int> pre){
//     if(i>=pre.size()||(ins<ine)){
//         return NULL;
//     }
//     int element=pre[i++];
//     node* temp=new node(element);
//   int pos=-1;
//     for(int k=0;k<pre.size();k++){
//           if(in[k]==element){
//             pos=k;
//             break;
//           }
//     }
//     temp->left=buildtreefromprein(i,ins,pos-1,in,pre);
//     temp->right=buildtreefromprein(i,pos+1,ine,in,pre);

//     return temp;
// }

// node* buildinpre(int &index,int instart,int inend,vector<int> in,vector<int> pre,map<int,int> np){
//     if(index>=pre.size()||(instart<inend)){
//         return NULL;
//     }
//     int ele=pre[index++];
//     node* temp=new node(ele);
//     int pos=np[ele];

//     temp->left=buildinpre(index,instart,pos-1,in,pre,np);
//     temp->right=buildinpre(index,pos+1,inend,in,pre,np);

//     return temp;

// }

// void  parentmapping(map<node*,node*> &np,node* root,node* &ans,node* target){
//   queue<node*> q;
//   np[root]=NULL;
//   while(!q.empty()){
//     node* t=q.front();
//     if(t==target) ans=t;
//     q.pop();
//     if(t->left){
//         np[t->left]=t;
//         q.push(t->left);
//     }
//     if(t->right){
//         np[t->right]=t;
//         q.push(t->right);
//     }
//   }

// }

// void burntree(node* target,map<node*,node*> np,int &c){
//     map<node*,int> p;
//     p[target]=1;
//     queue<node*> q;
//     q.push(target);
    
//     while(!q.empty()){
//            int f=0;
//         int s=q.size();
//         for(int i=0;i<s;i++){
           

//         node* r=q.front();
//         q.pop();

//         if(r->left){
//             if(p[r->left]!=1){
//                 f=1;
//                 p[r->left]=1;
//                 q.push(r->left);
//             }
//         }
//         if(r->right){
//             if(p[r->right]!=1){
//                 f=1;
//                 p[r->right]=1;
//                 q.push(r->right);
//             }
//         }
//         if(p[r]!=NULL and p[np[r]]!=1){
//             f=1;
//             p[np[r]]=1;
//             q.push(np[r]);
//         }
        
//         }
       
//         if(f==1){
//             c++;
//         }

//     }

// }

void morristraversal(node* root){
    if(root==NULL) return ;
    node* pre;node*curr;
    curr=root;

    while(curr!=NULL){

       if(curr->left==NULL){
       

       }

    }
    

}

int main() {  
  
  node* tree;node* tree2;
  int i=0;
  vector<int> s, v={42,27,82,-1,-1,98,65,-1,-1,96,-1,-1,63,-1,37},p={42,27,63,89,98,-1,37,-1,-1,65,96,-1,-1,-1,-1,-1,-1};
//   tree=binarytree(tree);
s=p;
s[4]=90;
node* r1;node* r2;
vector<int> t={63,-1,37,-1,-1};
vector<int> j={98,65,96,-1,-1,-1,-1};
buildtree(tree,p);
buildtree(tree2,s);
buildtree(r1,t);
buildtree(r2,j);

//   tree->data=12;
//   tree->left->data=23;
//   tree->left->left->data=24;
//   tree->right->data=87;
//   tree->left->left->right->data=25;

// tree->left->left->right->left->data=38;
// tree->left->left->right->right->data=42;


traversal(tree);
cout<<endl;
inordertraversal(tree);
cout<<endl;
postordertraversal(tree);
cout<<endl;
preordertraversl(tree);
cout<<endl;
int c=0;
leafcount(tree,c);
cout<<c<<endl;
cout<<leafcount2(tree)<<endl;
cout<<height(tree)<<endl;
pair<int,int> h=heightdiameter(tree);
cout<<h.first<<" "<<h.second<<endl;
pair<bool,int> b=balancedtree(tree);
cout<<b.first<<" "<<b.second<<endl;
cout<<issame(tree,tree2)<<endl;
pair<bool,int> m=issumtree(tree);
cout<<m.first<<" "<<m.second<<endl;
zigzagtraversal(tree);

boundarytraversal(tree);
map<int,map<int,vector<int>>> np;
verticalordertraversal(tree,0,0,np);
cout<<endl;
for(auto i:np){
    for(auto j:i.second){
        for(auto k:j.second)
        cout<<k<<" ";
    }
}
cout<<endl;
map<int,pair<int,int>> top;
topview(tree,0,0,top);
for(auto i:top) cout<<i.second.first<<" ";
cout<<endl;
map<int,int> lfv;
leftview(tree,0,lfv);

for(auto i:lfv) cout<<i.second<<" ";
cout<<endl;
pair<int,int> ans={0,0};
sumofnodesonlongestpath(tree,ans,0,0);
cout<<ans.first<<" "<<ans.second<<endl;
// cout<<endl;
// traversal(r1);
// cout<<endl<<endl;;
// traversal(r2);
// cout<<endl<<endl;;
pair<int,int> y=nonadjsum(tree);

cout<<y.first<<" "<<y.second<<endl;
vector<int> in={3,1,4,0,5,2},pre={0,1,3,4,2,5};
map<int,int> np3;
for(int i=0;i<6;i++){
    np3[in[i]]=i;
}
int index=0;
node* ans2=buildinpre(index,0,5,in,pre,np3);

// traversal(ans2);
cout<<ans2->data;
// cout<<LCA(r1,r2,tree)->data;

  return 0;
}