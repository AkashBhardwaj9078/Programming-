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

node* buildtreefromprein(int &i,int ins,int ine,vector<int> in,vector<int> pre){
    if(i>=pre.size()||(ins<ine)){
        return NULL;
    }
    int element=pre[i++];
    node* temp=new node(element);
  int pos=-1;
    for(int k=0;k<pre.size();k++){
          if(in[k]==element){
            pos=k;
            break;
          }
    }
    temp->left=buildtreefromprein(i,ins,pos-1,in,pre);
    temp->right=buildtreefromprein(i,pos+1,ine,in,pre);

    return temp;
}

node* buildinpre(int &index,int instart,int inend,vector<int> in,vector<int> pre,map<int,int> np){
    if(index>=pre.size()||(instart<inend)){
        return NULL;
    }
    int ele=pre[index++];
    node* temp=new node(ele);
    int pos=np[ele];

    temp->left=buildinpre(index,instart,pos-1,in,pre,np);
    temp->right=buildinpre(index,pos+1,inend,in,pre,np);

    return temp;

}

void  parentmapping(map<node*,node*> &np,node* root,node* &ans,node* target){
  queue<node*> q;
  np[root]=NULL;
  while(!q.empty()){
    node* t=q.front();
    if(t==target) ans=t;
    q.pop();
    if(t->left){
        np[t->left]=t;
        q.push(t->left);
    }
    if(t->right){
        np[t->right]=t;
        q.push(t->right);
    }
  }

}

void burntree(node* target,map<node*,node*> np,int &c){
    map<node*,int> p;
    p[target]=1;
    queue<node*> q;
    q.push(target);
    
    while(!q.empty()){
           int f=0;
        int s=q.size();
        for(int i=0;i<s;i++){
           

        node* r=q.front();
        q.pop();

        if(r->left){
            if(p[r->left]!=1){
                f=1;
                p[r->left]=1;
                q.push(r->left);
            }
        }
        if(r->right){
            if(p[r->right]!=1){
                f=1;
                p[r->right]=1;
                q.push(r->right);
            }
        }
        if(p[r]!=NULL and p[np[r]]!=1){
            f=1;
            p[np[r]]=1;
            q.push(np[r]);
        }
        
        }
       
        if(f==1){
            c++;
        }

    }

}

void morristraversal(node* root){
    if(root==NULL) return ;
    node* pre;node*curr;
    curr=root;

    while(curr!=NULL){

       if(curr->left==NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
       

       }
       else{
        pre=curr->left;
        while(pre->right!=NULL and pre->right!=curr){
            pre=pre->right;
        }

        if(pre->right==NULL){
            pre->right=curr;
            curr=curr->left;
        }
        else{
            pre->right=NULL;
            cout<<curr->data<<" ";
            curr=curr->right;

        }
       }

    }
    

}

void flattenlist(node* &root){
    if(root==NULL) return ;
    node* pre;node*curr=root;

    while(curr!=NULL){

        // if(curr->left){
        //     pre=curr->left;
        //     while(pre->right){
        //         pre=pre->right;
        //     }
        //     pre->right=curr->right;
        //     curr->right=curr->left;
        // }
        // curr=curr->right;






        if(curr->left==NULL){
           curr=curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL ){
                pre=pre->right;
            }

            if(pre->right==NULL){
                pre->right=curr->right;
                
                curr->right=curr->left;
                curr->left=NULL;;
                curr=curr->right;

            }
            
        }
    }
}



void print(node * root){
 
 while(root){
    cout<<root->data<<" ";
    if(root->left==NULL) cout<<-1<<" ";
    else cout<<root->left->data<<"     ";
    root=root->right;
 }

}



void insertinBST(node* &root,int val){


    if(root==NULL){
        root=new node(val);
        return ;
    }
    if(root->data<val){
        // if(root->right){
        //     insertinBST(root->right,val);
        // }
        // else{
        //    root->right= new node(val);
        // }

        insertinBST(root->right,val);
    }
    else{

        // if(root->left){
        //     insertinBST(root->left,val);
        // }
        // else{
        //    root->right= new node(val);
        // }
        insertinBST(root->left,val);

    }
}
void buildBST(node* &root,vector<int> v){
   for(int i=0;i<v.size();i++){
    insertinBST(root,v[i]);
   }
}

bool searchinBST(node* root,int x){
    if(root==NULL) return false;
    if(root->data=x) return true;
    if(root->data>x) return searchinBST(root->left,x);
    else return searchinBST(root->right,x);
}

int minBST(node* root){
    if(root==NULL) return -1;
    while(root->left){
       root=root->left;
    }

    return root->data;
}

int maxBST(node* root){
     if(root==NULL) return -1;
    while(root->right){
       root=root->right;
    }

    return root->data;
}

int inorderpredecessor(node* root,int x){
    if(root==NULL) return -1;
    if(root->data==x){
        return maxBST(root->left);

    }
    else if(root->data>x) return inorderpredecessor(root->left,x);
    else return inorderpredecessor(root->right,x);
}


int inordersuccessor(node* root,int x){
    if(root==NULL) return -1;
    if(root->data==x){
        return minBST(root->right);

    }
    else if(root->data>x) return inordersuccessor(root->left,x);
    else return inordersuccessor(root->right,x);
}
// int inorderpredecesor(node* root,int x){

//     if(root==NULL) return -1;
//     if(root->data==x){
//         return maxBST(root->left);
//     }
//     if(root->data>x) return inorderpredecesor(root->left,x);
//     else return inorderpredecesor(root->right,x);



// }
// int inordersuccessor(node* root,int x){

//     // if(root==NULL) return -1;
//     if(root->data==x){
//         return minBST(root->right);
//     }
//     else if(root->data>x) return inordersuccessor(root->left,x);
//     else return inordersuccessor(root->right,x);



// }

node* deletenodeBST(node* root,int x){
    if(root==NULL) return root;
    if(root->data==x){
        if(root->left==NULL and root->right==NULL){
            delete root;
            return root;
        }
         if(root->left!=NULL and root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;;
        }
         if(root->left==NULL and root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL and root->right!=NULL){
            int mn=minBST(root->right);
            root->data=mn;
            root->right=deletenodeBST(root->right,mn);
            return root;

        }
    }
    else if(root->data<x){
        root->right=deletenodeBST(root->right,x);
        return root;
    }
    else {
        root->left=deletenodeBST(root->left,x);
         return root;}
}

// void deletenodeBST(node* &root,int x){
//     if(root==NULL) return;
//     if(root->data==x){
//         if(root->left){
//         int mn=maxBST(root->left);
//          root->data=mn;
//          deletenodeBST(root->left,mn);
//         }
//         else if(root->right){
//             int mx=minBST(root->right);
//             deletenodeBST(root->right,mx);
//         }
//         else root=NULL;
//     }
//     else if(root->data>x){
//         deletenodeBST(root->left,x);
//     }
//     else deletenodeBST(root->right,x);


// }

// pair<int,pair<int,bool>> validateBST(node* root){

    
 
// pair<int,pair<int,bool>> l=validateBST(root->left);
// pair<int,pair<int,bool>> r=validateBST(root->right);
// bool p=l.second.second and r.second.second and (root->data>root->) and (root->data<r.first) and ;
// int mx=r.second.first;

// }
void validateBST(node*  root,int &a,bool &ans){
    if(root==NULL) return;
     validateBST(root->left,a,ans);
    if(root->data<a) {
        if(ans==true) ans=false;
    } 
    else a=root->data;
    validateBST(root->left,a,ans);
}

void validmorrisBST(node* root,int &a ,bool &ans){
    node* curr;node* pre;
    curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            if(curr->data<a and ans==true) ans=false;
            else a=root->data;
           curr= curr->right;
        }
        else{
            pre=curr->left;
            while(pre->right!=NULL and pre->right!=curr) pre=pre->right;

            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                if(curr->data<a and ans==true) ans=false;
                pre->right=NULL;

                curr=curr->right;
            }
        }
    }
}

void validBST(node* root,pair<int,int> range, bool &ans){
    if(root==NULL) return ;
    if(root-> data>range.second ||root->data<range.first) ans=false;
    int a=range.first,b=range.second;
    validBST(root->left,{range.first,root->data},ans);
    validBST(root->right,{root->data,b},ans);

}

bool isBST(node* root,int mn,int mx){
    if(root==NULL) return true;
    if(root->data>mn and root->data<mx){
        bool l=isBST(root->left,mn,root->data);
        bool r=isBST(root->right,root->data,mx);
        return l and r;
    }

    else return false;

}

void kthsmallest(node* root,int &k,int &ans){
    if(root==NULL) return;
    if(root->left) kthsmallest(root->left,k,ans);
    k--;
    if(k==0) ans=root->data;
    if(root->right) kthsmallest(root->right,k,ans); 


}


int kthsmall2(node* root,int &i,int k){
    if(root==NULL) return -1;
    int l=kthsmall2(root->left,i,k);
    if(l==-1) i++;
    if(i==k) return root->data;
    return kthsmall2(root->right,i,k);

}

node* bstLCA(node* root,int a,int b){
    if(root==NULL) return NULL;
    while(root!=NULL){

    if(root->data>max(a,b)){
       root=root->right;
    }
    else if(root->data<min(a,b)){
       root=root->left;
    }
    else {
       return root;
    }

    }
   return root;
}

void inorderparsing(node* r,vector<int> &v){
    if(r==NULL) return ;
   
    inorderparsing(r->left,v);
    v.push_back(r->data);
 
    inorderparsing(r->right,v);
}
bool tsum(vector<int> v,int tar){
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]<tar) i++;
        else if(v[i]+v[j]>tar) j--;
        else return true;
    }
    return false;
}
bool twosum(node* root,int target){
    // if(root==NULL) return false;
    // if(root->data>target) return twosum(root->left,target);
    // else if(root->data<target) return twosum(root->right,target);
    vector<int> v;
    inorderparsing(root,v);
    return tsum(v,target);
    // else{
    //     map<int,int> h;
    //     bool p=false;
    //     inorderparsing(root,h,target,p);
    //     return p;



    // }


}


node* balancedBST(vector<int> in,int i,int j){
    if(i<=j){
       int s=i+(j-i)/2;
       node* temp=new node(in[s]);
       temp->left=balancedBST(in,i,s-1);
       temp->right=balancedBST(in,s+1,j);
       return temp;

    }
    else{
        return NULL;
    }
}

node* preorderBST(vector<int> v,int &i,int mn,int mx){
    if(i>=v.size()) return NULL;
    if(v[i]>mn and v[i]<mx){
        int ele=v[i++];
        node* temp=new node(ele);
        temp->left=preorderBST(v,i,mn,ele);
        temp->right=preorderBST(v,i,ele,mx);
        return temp;

    }
    else return NULL;
}


node* merge2bst(node* bst1,node* bst2){
    vector<int> v1,v2,v3;
    inorderparsing(bst1,v1);
    inorderparsing(bst2,v2);

    int i=0,j=0;
    
    while(i<v1.size() and j<v2.size()){
        if(v1[i]<v2[j]){
           v3.push_back(v1[i++]);
        }
        else v3.push_back(v2[j++]);


    }
    while(i<v1.size()){
        v3.push_back(v1[i++]);
    }
    while(j<v1.size()){
        v3.push_back(v1[j++]);
       
}

return balancedBST(v3,0,v3.size()-1);

}

node* convert2sortedDLL(node* root,node* &head){

    if(head==NULL) return NULL;
    convert2sortedDLL(root->left,head);
    root->right=head;
    if(!head) head->left=root;
    head=root;
    convert2sortedDLL(root->left,head);
    
}

node* mergetwosortedDLL(node* head1,node* head2){
    node* head=NULL; node* tail=NULL;
    while(head1!=NULL and head2!=NULL){

        if(head1->data<head2->data){
           if(head==NULL){
              head=head1;
              tail=head1;
              head1=head1->right;
           }
           else{
              tail->right=head1;
              head1->left=tail;
              tail=head1;
              head1=head1->right;
           }

        }
        else{

           if(head==NULL){
              head=head2;
              tail=head2;
              head2=head2->right;
           }
           else{
              tail->right=head2;
              head2->left=tail;
              tail=head2;
              head2=head2->right;

           }

        }
       
    }

    while(head1!=NULL){
        
        // if(head==NULL){
        //       head=head1;
        //       tail=head1;
        //       head1=head1->right;
        //    }
        // else{
        //       tail->right=head1;
        //       head1->left=tail;
        //       head1=head1->right;
        //    }

       tail->right=head1;
       head1->left=tail;

    }

    while(head2!=NULL){
        
           if(head==NULL){
              head=head2;
              tail=head2;
              head2=head2->right;
           }
           else{
              tail->right=head2;
              head2->left=tail;
              head2=head2->right;

           }

    }

    return head;
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
cout<<endl;
morristraversal(tree);
cout<<endl;
flattenlist(tree);
print(tree);
cout<<endl;
vector<int> vtr={10,7,5,17,16,19,9};
node* bst=NULL;

buildBST(bst,vtr);
traversal(bst);
cout<<endl;
cout<<searchinBST(bst,17);
cout<<endl;
cout<<minBST(bst)<<" "<<maxBST(bst)<<endl;
// cout<<inorderpredecessor(bst,10)<<" "<<inordersuccessor(bst,10)<<endl;
cout<<minBST(bst->right)<<" "<<maxBST(bst->left)<<endl;
// bst=deletenodeBST(bst,17);
// traversal(bst);
cout<<endl;
bool req=true,req2=true,req3=true;
int d=-1,de=-1;
vector<int> vect={5,4,8,2,6,10,3,7};
node* bst2=NULL;
buildBST(bst2,vect);
traversal(bst2);
cout<<endl;
validBST(bst2,{INT_MIN,INT_MAX},req3);
validateBST(bst2,d,req);
validmorrisBST(bst2,de,req2);
cout<<req<<" "<<req2<<" "<<req3<<endl;
cout<<isBST(bst,INT_MIN,INT_MAX)<<" "<<isBST(bst2,INT_MIN,INT_MAX)<<endl;
int ans6=0,p2=3;
kthsmallest(bst2,p2,ans6);
cout<<ans6<<endl;
cout<<twosum(bst2,10)<<endl;
vector<int> v21={12,14,1,6,19,20,23,25,27,28,29,30,32,33,35};
node* tr=balancedBST(v21,0,14);
traversal(tr);
cout<<endl;
int i21=0;
node* tr2=preorderBST(v21,i21,INT_MIN,INT_MAX);
traversal(tr2);
cout<<endl;
node* tr3=merge2bst(bst,bst2);
traversal(tr3);
cout<<endl;
inordertraversal(tr3);

// int index=0;
// node* ans2=buildinpre(index,0,5,in,pre,np3);

// // traversal(ans2);
// cout<<ans2->data;
// cout<<LCA(r1,r2,tree)->data;   

  return 0;
}