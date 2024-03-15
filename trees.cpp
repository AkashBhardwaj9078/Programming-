#include <bits/stdc++.h>

using namespace std;

class node{
public :
  int data;
  node* left;
  node* right;

  node(int dat){
    data=dat;
    left=NULL;
    right=NULL;
  }
  

};

node* binary(node* &root){

    cout<<"enter data  ";
    int val;
    cin>>val;
    node* temp= new node(val);
    if(val==-1){
        return NULL;
    }
    else{

        cout<<"enter left value "<<" ";
        temp->left=binary(temp->left);
        cout<<"enter right value "<<" ";
        temp->right=binary(temp->right);

        root=temp;
        return root;

    }



}



void traversal(node* root){

  queue <node*> q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node * p=q.front();
    q.pop();
    if(p==NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
    }
    }
    else{
      cout<<p->data<<" ";
      if(p->left){
        q.push(p->left);
      }
      if(p->right){
        q.push(p->right);
      }
      
    }

  }




}



int binaryserachtree(node* root,int h){
  if(root==NULL){
    return -1;
  }
  if(root->data==h){
    return 0;
  }

  if(root->data>h){
    return binaryserachtree(root->left,h);
  }
  
  if(root->data<h){
    return binaryserachtree(root->right,h);
  }
  
}

void append(node* &root,int val){
  if(root==NULL){
    root=new node(val);
  }
  if(root->data<val){
    append(root->right,val);

  }
  if(root->data>val){
    append(root->left,val);
  }
}
void appendnode(node* &root,node* root2){
  if(root==NULL){
    root=root2;
  }
  if(root->data<root2->data){
    appendnode(root->right,root2);

  }
  if(root->data>root2->data){
    appendnode(root->left,root2);
  }
}


node* constructbunarysearchtree(vector<int> v){
  node* root;
  for(int i=0;i<v.size();i++){
    append(root,v[i]);

  }

  return root;
}


int minval(node* root){

  while(root->left!=NULL){
    root=root->left;
  }
  return root->data;
}


// void deletenode(node* root, int h){
//  node* k=root;
//   while(root->data!=h){
//     if(root->data>h){
//       if(root->left->data!=h){
//         root=root->left;
//       }
//       else{
//         break;
//       }
      
//     }
//     else{
//        if(root->right->data!=h){
//         root=root->right;
//       }
//       else{
//         break;
//       }
//     }
//   }
    
//    if(root->data<h){
//     // right =del
//     node* delright=root->right;
//     if(delright->left==NULL and delright->right==NULL){
//       root->right=NULL;
//     }
//     else if(delright->left==NULL || delright->right==NULL){
//       if(delright->left){
//         root->left=delright->left
//       }
//       else{
//         root->right=delright->right;
//       }
//     }

//    }


  

  
    









// }



bool validbinarysearchtree(node* root){
  if(root==NULL){
    return true;
  }
  bool left=false,right=false;
  if(root->left){
    if(root->left->data<root->data){
        left=true;
    }
  }
  else{
    left=true;

  }
  if(root->right){
    if(root->right->data>root->data){
     right=true;
    }
  }
  else{
    right=true;
  }

 

  
  if(validbinarysearchtree(root->left) and validbinarysearchtree(root->right) and left and right){
  
    return true;
    
  }
  else{
    return false;
  }

}


void validbinarysearchtree2(node* root,int &x, bool p){
  if(root==NULL){
    return;
  }
  validbinarysearchtree2(root->left,x,p);
  if(x>root->data){
    p=false;
  }
  else{
    x=root->data;

  }
  validbinarysearchtree2(root->right,x,p);
}

void inorderksmallest(node* root,int k,vector<int> &v,int & p){
  if(root==NULL){
    return ;
  }
  inorderksmallest(root->left,k,v,p);
  v.push_back(root->data);
  if(v.size()==k-1){
   p=v[k-1];
  }
  inorderksmallest(root->right,k,v,p);

  
}

int mval(node* root){
  while(root->right!=NULL){
    root=root->right;
  }
  return root->data;
}


int pred(node* root,int val){
  while(root->data!=val){
    if(root->data>val){
      root=root->left;
    }
    else{
      root=root->right;
    }

  }
  return mval(root->left);
  // minval(root->right);

  
}

node* lca(node* root,node* root1,node* root2){
if(root==NULL){
return NULL;

}
if(max(root1->data,root2->data)<root->data){
  return lca(root->left,root1,root2);
}
else if(min(root1->data,root2->data)>root->data){
  return lca(root->right,root1,root2);
}
else{

return root;

}

    

}


node* constructbalancedtree(vector<int> v,int i,int j,node* &root){
   int m=i+(j-i)/2;
   root=new node(v[m]);
   
  root->left=constructbalancedtree(v,i,m-1,root->left);
  root->right=constructbalancedtree(v,m+1,j,root->right);


   
   return root;
}






pair<bool,int> balanced(node* root){
if(root==NULL){
  return {true,0};
}
  
 pair left=balanced(root->left);
 pair right=balanced(root->right);
 bool e=abs(left.second-right.second)<=1;
 bool k=left.first and right.first and e;
 int  h=max(left.second,right.second);
 return {k,h};

}


node* trav(node* root,vector <int> v,int &i,int k,int m){
       
        if(i==v.size()){
          return NULL;
        }
        

        if(v[i]>=k and v[i]<=m){

          root=new node(v[i]);
          i++;

          
        root->left=trav(root->left,v,i,k,root->data);
        root->right=trav(root->right,v,i,root->data,m);

        }
        else{
          root=NULL;
        }
        
       return root;

        
        

      



}









int main() {  
    node* root ;
    root =new node(2);
    cout<<root->data;


   
  

  return 0;
}