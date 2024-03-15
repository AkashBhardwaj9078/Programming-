// #include <bits/stdc++.h>

// using namespace std;

// class hashing{
//     public:
//     vector <list<int>> hashtable;
//     int buckets;
//     hashing(int size){
//         buckets=size;
//         hashtable.resize(size);
//     }
//     int hashvalue(int key){
//         return key%buckets;
//     }
//     void add(int key){
//         hashtable[hashvalue(key)].push_back(key);
//     }
//     list<int>::iterator search(int key){
//         return find(hashtable[hashvalue(key)].begin(),hashtable[hashvalue(key)].end(),key);
//     }
//     void del(int key){
//         if(search(key)!=hashtable[hashvalue(key)].end()){
//           hashtable[hashvalue(key)].erase(search(key));
//         }
        
//     }
// };





// void p(vector <long long> v){
//     vector<long long> h;
//     for(int i=0;i<v.size();i++){
//         vector <long long>::iterator k=upper_bound(v.begin()+i,v.end(),v[i]);
//         int idx=(k-v.begin());
//         // if(idx==v.size()){
//         //     h.push_back(-1);
//         // }
//         // else{
//         //     h.push_back(v[idx]);
//         // }
//         cout<<idx<<" ";
//     }
//     // return h;
// }

// int sum(vector<vector<int>>v,int i,int j,int k,int l){
    
//     int sum=0;
//     for(int a=i;a<=j;a++){
//         for(int b=k;b<=l;b++){
//            sum+=v[a][b];
//         }
//     }
//     return sum;
// }

// void prefixsum(vector<vector <int>> &v,int n,int m){

//     for(int i=0;i<n;i++){
//         for(int j=1;j<n;j++){
//             v[i][j]+=v[i][j-1];
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         for(int j=1;j<n;j++){
//             v[j][i]+=v[j-1][i];
//         }
//     }
    
// }


// int num(vector<vector<int>> v,int i,int j,int k,int l){
//     return v[k][l]-v[k][j]-v[i][l]+v[i][j];


// }


// // int maxsum(vector<vector<int>> v,int i,int j,int k,int l,int n,int m){

// //     if(i<0||j<0||i>n||j>m){
// //         return 0;
// //     }


// // else{
// //     vector<int> h;
   
// // }

    


// // }

// vector<int> ret(int arr[],int n,int k){
  
//   vector<int> h,r;
//   for(int i=0;i<n;i++){
//    h.push_back(arr[i]);
//        if(i==k-1){
//         sort(h.begin(),h.end());
//          r.push_back(h[h.size()-1]);

//        }
//        if(i>k-1){
//         h.erase(h.begin());
//         sort(h.begin(),h.end());
//         r.push_back(h[h.size()-1]);

//        }
       
//   }

//   return r;


// }













// int main(){  
   

    
// //   int p=1;
// //   int countneg=0;
// //     for(int i=0;i<n;i++){
// //         if(arr[i]<n){
// //             countneg+=arr[i];
// //         }
        
// //     }
// //  int mx=INT_MIN;
// //     for(int i=0;i<n;i++){
// //       p*=arr[i];
// //      mx=max(mx,p);
// //      if(arr[i]<0){
// //         countneg--;
// //      }
// //      if(p<0){
// //         if(countneg==0){
// //            p=1;
// //         }
// //         else{

// //         }

// //      }
// //     }


// int arr[]={0,-10,1 ,3,-20};
 
// int n=sizeof(arr)/sizeof(arr[0]);
// sort(arr,arr+n);
// int i=0,j=n-1;
// int r, idx;

// while(i<j){
//     int m=i+(j-i)/2;
//     if(arr[m]>0){
//         j=m-1;
//         r=arr[m];
//         idx=m;
//     }
//     else if(arr[m]<=0){
//         i=m+1;
//     }
   
// }
// if(r>1){
//     cout<<r-1;
// }
// else{
//     int f=0;
//     for(int j=idx;j<n;j++){
//         if(arr[j]!=r){
//           cout<<r;
//           f=1;
//           break;
//         }
//         r++;
//     }
//     if(f==0){
//         cout<<r+1;
//     }
//     else{
//         cout<<r;
//     }
// }

    


  
  





 
 





                                                                     

//   return 0;
// }
#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* pre;

    node(int v){
       this->data=v;
       this->next=NULL;
       this->next=NULL;

    }
};

void insertfront(node* &head,int k, node* &tail){

    node* temp=new node(k);
    temp->next=head;
    head->pre=temp;
    head=temp;


}


void insertlast(node*&head,int k,node* &tail){
    // node* temp=head;
    node* p=new node(k);
    tail->next=p;
    p->pre=tail;
    tail=p;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // temp->next=p;
    // p->pre=temp;

}
void insertatpos(node* &head,int val,int pos,node* tail){

      
      if(pos==1){
        insertfront(head,val,tail);
      }
    

    node* temp=head;
    int c=pos-2;
    node* a=new node(val);
    while(c--){
        temp=temp->next;
    }

    if(temp->next==NULL){
      insertlast(head,val,tail);
    }
    
    else{
    a->next=temp->next;
    temp->next->pre=a;
    a->pre=temp;
    temp->next=a;
    }
   
    

}

void deleteatpos(node* &head,int pos){
 
  node* temp=head;
  int h=0;
  while(h<pos-1){
    temp=temp->next;
    h++;
  }
  node* p=temp->next;
  temp=p->next;
  free(p);

}
int len(node * & head){
    if(head==NULL){
       return 0;
    }
    else {
        return 1+len(head->next);
    }
}

void displayend(node* tail){
    node* t=tail;
    while(t->pre!=NULL){
        cout<<t->data<<" ";
        t=t->pre;
    }

}
void reverse(node* &head,node* & tail){
  node* pre=NULL;

  node* t=head;
  while(t!=NULL){
    node* nex=t->next;
    t->next=pre;
    t->pre=nex;
    
    pre=t;
    t=nex;
  }
  tail=head;
  head=pre;


}

void reversek(node* &head,int k,node* tail){

     node* pr=NULL;
     node* t=head;

     while((k!=0) and t!=NULL){
        node* nex=t->next;

        t->next=pr;
        t->pre=nex;
        t=nex;
        pr=t;
        k--;
     }
      
     if(t!=NULL){
        
           head->next=t;
           t->pre=head;
             head=pr;
     }
     else{
      
      tail=head;
      head=pr;

     }
     

    

}



void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}









class cirnode{
  public:
  int data;
  cirnode* next;
  // cirnode* pre;
  cirnode(int data){
    this->data=data;
    this->next=NULL;
    // this->pre=NULL;

  }




};

void insertcirlist(int data,cirnode* &tail){
  cirnode* temp=new cirnode(data);
  // temp->next=head;
  // head->pre=temp;
  // head=temp;;
  // tail->next=temp;

  // temp->pre=tail;

  if(tail->next!=NULL){
    temp->next=tail->next;
  tail->next=temp;
  tail=temp;
  }
  else{
    tail->next=temp;
    temp->next=tail;
    tail=temp;
  }
  
  }


  
  
  


  
  void cirnodedel(cirnode* &p, int k){
     cirnode* t=p;
    for(int i=0;i<k;i++){
         t=t->next;
    }
   cirnode* r=t->next;
     
     p->next=p->next->next;
     free(r);




  }
  
  
 


  


void displaycir(cirnode* &tail){
   
   

cirnode* t=tail->next;
   do{
    
    cout<<t->data<<" ";
t=t->next;
    
   }
   while(t!=tail->next);






}


void insertfromend(cirnode* tail,int  num,int k){
    cirnode* t=new cirnode(num);
  for(int j=0;j<k-1;j++){
    tail=tail->next;
  }
   

   if(t->next!=tail){
    t->next=tail->next;
 tail->next=t;
   }
   else{
    insertcirlist(num,tail);
   }
 

}


int counted(int arr[],int l,int m,int r){
  int c=0;
  int n1=m-l+1;
  int n2=r-m;
  int a[n1],b[n2];
  for(int i=0;i<n1;i++){
    a[i]=a[l+i]; 
  }
  for(int i=0;i<n2;i++){
    b[i]=a[m+1+i]; 
  }
   int i=0,j=0,k=0;
  while(i<n1 and j<n2){
      if(a[i]<=b[j]){
        arr[k]=a[i];
        k++;
        i++;
      }
      else{
        arr[k]=b[j];
        c+=n1-i;
        k++;
         j++;
      } 

  }
  return c;
}


int countinv(int arr[],int l,int r){
  int inv=0;
  if(l<r){
  int m=l+(r-l)/2;
  inv+=countinv(arr,l,m);
  inv+=countinv(arr,m+1,r);
  inv+=counted(arr,l,m,r);
  }
  return inv;

}







int main() {  
//  int n1 = 6;int A []= {1, 5, 10, 20, 40, 80};
// int n2 = 5; int B[] = {6, 7, 20, 80, 100};
// int n3 = 8; int C []= {3, 4, 15, 20, 30, 70, 80, 120};

// map<int,int>m,n,p;
// vector<int> v;
// for(int i=0;i<n1;i++){
//   m[A[i]]++;
// }




// cirnode* p=new cirnode(23);
// cirnode* tail=p;
// int num=4;
// insertcirlist(7,tail);   
// insertcirlist(10,tail);
// // cirnodedel(tail,3);
// insertcirlist(19,tail);
// insertcirlist(12,tail);
// insertcirlist(15,tail);
// insertfromend(tail,num,4);
// displaycir(tail);








// node* p=new node(3);
// node* tail=p;
// insertfront(p,2,tail);
// insertfront(p,4,tail);
// insertfront(p,5,tail);

// display(p);
// cout<<endl;
// insertlast(p,40,tail);
// displayend(tail);




// node* p=new node(56);
// node* tail=p;
// insertfront(p,23,tail);
// insertfront(p,24,tail);
// insertfront(p,10,tail);

// display(p);

// cout<<endl;
// // display(p);
// int n=4;
// // int a[n][n]={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};

// int arr[]={5,3,4,5,2,5,6,3,8,1};

// int s=12;
// int sum=0;
// int i=0,j=0;
// vector<pair<int,int>> v;
// while(i<n & j<n){

//   if(sum==s){
//       cout<<i+1<<" "<<j<<cout<<endl;
//   }
//  else if(sum+arr[j]<s){
//     sum+=arr[j];
//     j++;
//   }
//   else{
//     sum-=arr[i];
//     i++;
//   }


// }














// int n=sizeof(arr)/sizeof(arr[0]);
// cout<<countinv(arr,0,n-1);
// int n=7;

// int arr[]={1,5,3,4,3,5,6};
// map<int,pair<int,int>>p;

// for(int i=0;i<n;i++){
//   p[arr[i]].first++;
//   if(p[arr[i]].first==1){
//    p[arr[i]].second=i;
//   }
  
//   if(p[arr[i]].first==2){
//     m=min(p[arr[i]].second,i+1);
//   }
  




// }
// cout<<m;
// int mx=INT_MIN;
// for(int i=0;i<7;i++){
//    mx=max(arr[i],mx);
// }

// int num[mx]={-1};
// int mn=INT_MAX;
// for(int i=0;i<n;i++){
  
//   if(num[arr[i]]!=-1){
//      mn=min(mn,num[arr[i]]);
//   }
//   else{
//    num[arr[i]]=i;
//   }
// }
// if(mn=INT_MAX){
//   cout<<-1;
// }
// else{
//   cout<<mn;
// }














// for(int i=0;i<n2;i++){
//   if(m[B[i]]!=0){
//     n[B[i]]++;
//     n[B[i]]=min(m[B[i]],n[B[i]]);
//   }
  
// }

// for(int i=0;i<n3;i++){
//     if(m[C[i]]!=0){
//       p[C[i]]++;
//       if(m[C[i]]>=p[C[i]]){
//         v.push_back(C[i]);
//       }
      
//     }
// }

// for(auto i:v){
//   cout<<i<<" ";
// }

// vector<int>v;
// int i=0,j=0,k=0;
// while(i<n1 and j<n2 and k<n3){
//   if(A[i]>=B[j] and A[i]>=C[k]){
       
//        while(A[i]>B[j]){
//         j++;
//        }
//        while(A[i]>C[k]){
//         k++;
//        }
       
//        if(A[i]==B[j] and C[k]==B[j] and C[k]==A[i]){
//            v.push_back(A[i]);
//            i++;
//            j++;
//            k++;
//        }



//   }
//   else if(B[j]>=A[i] and B[j]>=C[k]){
       
//        while(B[j]>A[i]){
//         i++;
//        }
//        while(B[j]>C[k]){
//         k++;
//        }
       
//        if(A[i]==B[j] and C[k]==B[j] and C[k]==A[i]){
//            v.push_back(A[i]);
//            i++;
//            j++;
//            k++;
//        }


//   }
//   else  if(C[k]>=B[j] and C[k]>=A[i]){
       
//        while(C[k]>B[j]){
//         j++;
//        }
//        while(A[i]<C[k]){
//         i++;
//        }
       
//        if(A[i]==B[j] and C[k]==B[j] and C[k]==A[i]){
//            v.push_back(A[i]);
//            i++;
//            j++;
//            k++;
//        }


//   }


// for(auto i:v){
//   cout<<i<<" ";
// }
// }

 



  return 0;
}
// 23 7 10 19 12 15 