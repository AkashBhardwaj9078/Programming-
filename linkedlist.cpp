#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int value){
        this->val=value;
        this->next=NULL;

    }
     node(){
        this->val=0;
        this->next=NULL;

    }


};

void addhead(node* &head,int data){
    node * newn=new node(data);
    newn->next=head;
    head=newn;


}
void addtail(node* &temp,int data){
    node* newn=new node(data);
    node* head=temp;
    while(head->next!=NULL) head=head->next;
    
    head->next=newn;
}
void print(node* temp){

node* temp2=temp;
while(temp2!=NULL){
cout<<temp2->val<<" ";
temp2=temp2->next;
} 
cout<<"\n";

}
void insert(node* head,int k,int data){
     node* p=head;
     int h=k-1;
    while(h
     and p->next){
        p=p->next;
        h--;
    }
    node* j= new node(data);
    j->next=p->next;
    p->next=j;
}
int len(node* head){
    int c=0;
    node* temp=head;
    while(temp){
        c++;
        temp=temp->next;
    }
    return c;
}

node* reversellk(node* &head,int k,int len){
    if(head==NULL||len<k||k==1){
        return head;

    }
    int h=k;
    node* prev=NULL;
    node* temp=head;
    while(temp and h--){
       node* front=temp->next;
       temp->next=prev;
       prev=temp;
       temp=front;
    }
    head->next=reversellk(temp,k,len-k);

    return prev;
    



}

node* manipulate(node* &head){
   node* slow=head;node* fast=head;
    node* preslow;
   while(fast){
    preslow=slow;
    slow=slow->next;
    fast=fast->next;
    if(fast) fast=fast->next;
   }
   
   node* half=slow;
   preslow->next=NULL;
   
   
   node* prev=NULL;
//    print(half);
//    print(head);
   while(half){
    node* temp=half->next;
    half->next=prev;
    prev=half;
    half=temp;
   }

   print(prev);
   print(head);
   node * ret=new node();
     node * ans=ret;
   node* t2=head;
   
   while(t2 and prev){
    ret->next=t2;
    t2=t2->next;
    ret=ret->next;

    ret->next=prev;
    prev=prev->next;
    ret=ret->next;


   }

   if(prev){
    ret->next=prev;

   }
   else{
    ret->next=t2;
   }


return ans->next;




}

void removedup(node* ptr){
    if(ptr==NULL||ptr->next==NULL) return;
    node* t=ptr;
  while(ptr->next){
  if(ptr->val==ptr->next->val){
    node* temp=ptr->next;
     ptr->next=temp->next;
  }
  else ptr=ptr->next;
  }
  ptr=t;

}

node* sort012(node* head){
  
  if(head==NULL ||head->next==NULL) return head;
  node* zero=new node();
  node* z=zero;

  node* one=new node();
  node* o=one;
  node* two=new node();
  node* t=two;
  while(head){
    if(head->val==0){
        zero->next=head;
        zero=zero->next;
        // zero->next=new node(0);
        // zero=zero->next;
    }
    else if(head->val==1){
        one->next=head;
        one=one->next;
        // one->next=new node(1);
        // one=zero->next;
    }
    else if(head->val==2){
        two->next=head;
        two=zero->next;
        // two->next=new node(2);
        // two=two->next;
    }
    head=head->next;


  }
  
  if(o->next) zero->next=o->next;
  else if(t->next) zero->next=t->next;
    
  one->next=t->next;
  two->next=NULL;

  return z->next;






}

node* merge(node* &r1,node* &r2){
//   if(r1->val<r2->val){
//     node* head=r1;

//     while(r1->next!=NULL and r2){
//         if(r1->val<=r2->val and r2->val<=r1->next->val){
//              node* next=r2->next;
//              r2->next=r1->next;
//              r1->next=r2;
//              r2=next;
//              r1=r1->next;


//         }
//         else{
//             r1=r1->next;
//         }

//     }
//     if(r2){
//         r1->next=r2;

//     }


//     return head;

//   }
//   else{
//      node* head=r2;

//     while(r2->next!=NULL and r1){
//         if(r2->val<=r1->val and r1->val<=r2->next->val){
//              node* next=r1->next;
//              r1->next=r2->next;
//              r2->next=r1;
//              r1=next;
//              r2=r2->next;


//         }
//         else{
//             r2=r2->next;
//         }

//     }
//     if(r2){
//         r1->next=r2;

//     }


//     return head;
//   }

node* r=new node();
node* head=r;
while(r1 and r2){
    if(r1->val<=r2->val){
        r->next=r1;
        r=r1;
        r1=r1->next;
        
    }
    else{
        r->next=r2;
        r=r2;
        r2=r2->next;

    }

    if(r1) r->next=r1;
    else r->next=r2;

    return head->next;
}


}
bool isbool(node* ret){
    node* slow=ret;
    node* fast=ret;
    // if(!ret and !ret->next){
    //     return 
    // }
    do{
        slow=slow->next;
        if(fast->next)
        fast=fast->next->next;
        else fast->next;
    }
    while(fast and slow and fast!=slow);

    if(fast==NULL ||slow==NULL){
        return false;
    }
    if(fast==slow) return true;
}
// void split(node* &head){

//    node* slow=head;
//    node* fast=head;
//    print(head);
//    node* pre;
//    do{
//     pre=slow;
//     slow=slow->next;
//     fast=fast->next;
//     if(fast->next!=head) fast=fast->next;
//    }
//    while(fast->next!=head);
//    fast->next=pre->next;
//    pre->next=head;

//    node* temp=head;
//    node* temp2=fast->next;
//    node* temp3=temp2;
//    do{
//     cout<<temp->val<<" ";
//     temp=temp->next;
//    }
//    while(temp->next!=head);
//    cout<<endl;
//    do{
//     cout<<temp2->val<<" ";
//     temp=temp2->next;
//    }
//    while(temp2->next!=temp3);
//    cout<<endl;
   















//v
void midele(stack<int> st,int c,int n,int &ans){
   int ch=n%2==0? n/2:n/2+1;
   if(c==ch){
    ans=st.top();
    st.pop();
    return ;
   }
   int top=st.top();
   st.pop();
   midele(st,c+1,n,ans);
   st.push(top);
}

void addatlast(stack<int> &st,int ele){

    if(st.empty()){
        st.push(ele);
        return;

    }
    int top=st.top();
    st.pop();
    addatlast(st,ele);
    st.push(top);

}
void reverse(stack<int> &st){

    if(st.empty()){
      
        return;

    }
    int top=st.top();
    st.pop();
    reverse(st);
    addatlast(st,top);

}

// void sortedinsert(stack <int> &st,int ele){

//     if(st.empty()||(!st.empty() and st.top()<ele )){
//         st.push(ele);
//     }
//     int num=st.top();
//     st.pop();
//     sortedinsert(st,ele);
//     st.push(num);

// }

// void sortstack(stack<int> &st){
//     if(st.empty()) return;
//     int n=st.top();
//     st.pop();
//     sortstack(st);
//     sortedinsert(st,n);

// }

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}

vector<int> nextsmallerele(vector<int> nums){

    vector<int> v(nums.size());
    stack<int> st;
    st.push(nums.size());
    for(int i=nums.size()-1;i>=0;i--){
        while(st.top()!=nums.size() and nums[st.top()]>nums[i]){
            st.pop();
        }
        v[i]=st.top();
        st.push(i);
    }
  for(auto i:v){
    cout<<i<<" ";
  }
    return v;

}
vector<int> leftnextsmaller(vector<int> nums){

    vector<int> v(nums.size());
    stack<int> st;
    st.push(-1);
    for(int i=0;i<nums.size();i++){
        while(st.top()!=-1 and nums[st.top()]>nums[i]){
            st.pop();
        }

        v[i]=st.top();
        st.push(i);
    }

    // 2,1,5,6,2,3
  for(auto i:v){
    cout<<i<<" ";
  }
    return v;

}
  vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
int areamax(vector<int> nums){
// stack<int> left,right;

// left.push(-1);
// right.push(-1);
vector<int> l,r;
r=nextsmallerele(nums);
l=leftnextsmaller(nums);

// for(int i=0;i<nums.size();i++){


//     while((left.top()!=-1 and  nums[left.top()]>nums[i])){

//         left.pop();

//     }
     
//     l[i]=left.top();
//     left.push(i);
// }

// for(int i=nums.size()-1;i>=0;i--){


//     while((right.top()!=-1 and nums[right.top()]>nums[i])){

//         right.pop();

//     }
//     r[i]=right.top();
//     right.push(i);
// }


for(auto i:l)
cout<<i<<" ";

cout<<endl;
for(auto i:r){
cout<<i<<" ";
}
cout<<endl;

int are=0;
for(int i=0;i<nums.size();i++){
    are=max(are,nums[i]*(r[i]-l[i]-1));
}
return are;

}

int celebrity(vector<vector<int>> nums){

    int n=nums.size();
    stack<int> st;
    for(int i=0;i<n;i++){
       st.push(i);
    }
    while(st.size()>1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(nums[a][b]==1){
            st.push(b);
        }else{
            st.push(a);
        }   
    }
    int l=st.top();
    int ans=l;
    for(int i=0;i<n;i++){
        if(i!=l){
        if(nums[l][i]==1) {
            ans=-1;
            break;
        }

        if(nums[i][l]==0){
            ans=-1;
            break;

        }

        }
        


    }
    return ans;
}


int maxrectangle(vector<vector<int>> mat){

  int n=mat.size(),m=mat[0].size();
  int mx=0;
  for(int i=0;i<n;i++){
    if(i==0){
        mx=max(mx,areamax(mat[0]));

        if(i>0){
            for(int k=0;k<m;k++){
                if(mat[i][k]==0) mat[i][k]=0;
                else{
                    mat[i][k]+=mat[i-1][k];
                }
            }
            mx=max(mx,areamax(mat[i]));
        }


    }
  }

  return mx;
}
int maxprod(vector<int> nums){


int n=0,p=0,z=0;
for(int i=0;i<n;i++){
    if(nums[i]<0) n++;
    if(nums[i]>0) p++;
    if(nums[i]==0) z++;

}
sort(nums.begin(),nums.end());
int k=nums.size()-1;


}

int mooremajority(vector<int> nums){
int ans=nums[0];
int freq=1;
for(int i=1;i<nums.size();i++){
     if(nums[i]==ans){
        freq++;
     }
     else freq--;
     if(freq==0) ans=nums[i],freq=1;

}
freq=0;

for(int i=0;i<nums.size();i++) if(nums[i]==ans) freq++;
if(freq>nums.size()/2) return ans;
else return -1;

}

  int len(node* head){
      int n=0;
      while(head){
          head=head->next;
          n++;
      }
      return n;

    }
    vector<node*> splitListToParts(node* head, int k) {
        int size=len(head);
        vector<node*> v;
        int rem=size%k;
        int vsize=size/k;
        while(head){
            v.push_back(head);
            int k=vsize;
            if(rem>0){
                k++;
                for(int j=0;j<k-1;j++){
                    head=head->next;
                }
                node* newhead=head->next;
                head->next=NULL;
                head=head;
                rem--;
            }
            else{
                for(int i=0;i<k-1;i++){
                    head=head->next;; 
                }
                node* newhead=head->next;
                head->next=NULL;
                head=head;
            }
        }
       return v;
    }

    
int main() {  
  node* head=new node(10);
  addhead(head,9);
  addhead(head,8);
  addhead(head,7);
   addhead(head,6);
  addhead(head,5);
  addhead(head,4);
   addhead(head,3);
  addhead(head,2);
  addhead(head,1);

  vector<node*> v=splitListToParts(head,3);
  cout<<len(head);

//   for(auto i:v){

//   }
//   addhead(head,1);
//     addhead(head,4);
// node* head2=new node(2);
//       addhead(head2,3);
//   addhead(head2,4);

//    addhead(head2,4);
//   addhead(head2,4);
//     addhead(head2,5);
// node* r=manipulate(head);


    // node* tail=head;
    // while(tail->next){
    //     tail=tail->next;
    // }
    // tail->next=head;
    // split(head);
    // print(head);
    // print(head2);
    // print(merge(head,head2));
    // print(sort012(head));
    // stack<int> st;
    // st.push(21);
    // st.push(32);
    // st.push(20);
    // st.push(102);
    // st.push(34);
    // st.push(78);
    // st.push(21);  
    // // int k=1,ans;
    // // midele(st,k,7,ans);
    // // cout<<ans;
    // addatlast(st,2903);
    // reverse(st);
    // int k=st.top();
    // st.pop();
// vector<int>j={2,1,4,3} ,v=nextsmallerele(j);
// vector<int> v={2,1,5,6,2,3},t=nextsmallerele(v);cout<<endl;
// vector<int>  j=leftnextsmaller(v);cout<<endl;
// vector<vector<int>> u= {{0,1,0},{0,0,0},{0,1,0}};
// cout<<celebrity(u);
// cout<<areamax(v);

// for(auto i:v){
//     cout<<i<<" ";
// }
    // sortStack(st);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
  
//   insert(head,2,27);
//   print(head);
//   cout<<"\n";
//   int n=len(head);
//   cout<<n<<endl;
//   node* r=reversellk(head,5,n);
  
//   print(r);
//   cout<<"\n";
//   ;
//   print(manipulate(r));
// print(head);
// removedup(head);
// print(head);

  return 0;
}