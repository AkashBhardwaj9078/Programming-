#include <bits/stdc++.h>

using namespace std;


void removemid(stack<int> p,int size,int n){
    if(n==size/2){
        p.pop();
        return;
    }
    int a=p.top();
    p.pop();
    removemid(p,size,n+1);
    p.push(a);
}


void pushatend(stack<int> &p,int v){
    
   

   if(p.empty()){
   p.push(v);
    return;
    
   }
   int n=p.top();
    p.pop();
   pushatend(p,v);
   p.push(n);


   
  




}


void pushatupperbound(stack<int> &p,int x){

  if(p.empty()||(p.top()<=x and !p.empty())){
    p.push(x);
     return;
  }
  int n=p.top();
  p.pop();
  pushatupperbound(p,x);
  p.push(n);

}



bool checkbalancebracket(string s){
   stack<char> p;
   for(int i=0;i<s.length();i++){

    if(s[i]=='{'||s[i]=='('||s[i]=='['){
        p.push(s[i]);
    }
    else{
        
     if(s[i]=='}'){
        if(p.top()=='{'){
            p.pop();
        }
        else{
            return false;
            break;
        }
     }
     if(s[i]==')'){
        if(p.top()=='('){
            p.pop();
        }
        else{
            return false;
            break;
        }
     }
    
      if(s[i]==']'){
        if(p.top()=='['){
            p.pop();
        }
        else{
            return false;
            break;
        }
     }
    
    
      

    }
   }

   if(p.empty()){
    return true;
   }
    
}


void reverse(stack <int> &p){
// log n^2,possible(2*n)  h

    if(p.empty()){
        return;
    }
   int n=p.top();
   p.pop();
   reverse(p);
   pushatend(p,n);
     


  

}


void sort(stack<int> &p){
 map<int,int> m;
 while (!p.empty())
 {
   m[p.top()]++;
   p.pop();
 }

 for(auto i:m){
    for(int j=0;j<i.second;j++){
       p.push(i.first);
    }
 }
 
   

}


void sort2(stack<int> &p){
  
  if(p.empty()){

     
    return;
  }

  int n=p.top();
  p.pop();
  sort2(p);
  pushatupperbound(p,n);
   

}


pair<bool,int> recursioncheck(string &s,int j){
  int count=0;
 for(int i=j;i<s.length();i++){

    if(s[i]=='('){
        pair<bool,int> p=recursioncheck(s,i);
        if(p.first==false){
            return {false,s.length()-1};
            
        }
        else{
            i=p.second+1;
        }
    }
    if( s[i]='-'||s[i]=='*'||s[i]=='/'||s[i]=='+'){
        count++;
    }
    if(s[i]==')'){
        if(count==0 ){
            return {false,i};
          
        }
        else{
            return {true,i};
        }
    }
 }

}

bool  ret(string s){
    
    stack<char> p;

    for(int i=0;i<s.length();i++){
           if(s[i]=='('){
            p.push('(');
           }
           if(s[i]=='/'||s[i]=='*'||s[i]=='+'||s[i]=='-'){
                p.push('0');

           }
           if(s[i]==')'){
            int c=0;
            while(p.top()!='('){
                c++;
                p.pop();
            }
            p.pop();
            if(c==0){
                return false;
                break;
            }
            
           }
      
    }
    return true;
}


int mincost(string s){


    if(s.length()%2!=0){
        return -1;
    }
    else{
        stack<int> p;
        int c=0;

        for(int i=0;i<s.length();i++){
           if(s[i]=='('){
            p.push('(');
           }
           else{
            if(p.empty()){
                p.push('(');
                c++;
            }
            else{
                 p.pop();
            }
           }

        }
        return (p.size()/2)+c;
    }
}



int larg(vector<int> v){


    int m=0;
    stack<int> p;

    for(int i=0;i<v.size();i++){
         

   

    }

    

}

// vector<int> nextsmaller(vector<int> v){
//     stack<int> s;
//     s.push(-1);
//      vector<int> h(v.size());
//     for(int i=v.size()-1;i>=0;i--){
        
//         while( s.top()!=-1 and v[s.top()]>=v[i]){
//             s.pop();

//         }
        
//        h[i]=s.top();
//     //    if(h[i]==-1){
//     //     h[i]=v.size();
//     //    }
//        s.push(v[i]);


       
       

//     }
//     return h;
// }

// vector<int> prevsmaller(vector<int> v){
//     stack<int> s;
//     s.push(-1);
//      vector<int> k(v.size());
//     for(int i=0;i<v.size();i++){
        
//         while( s.top()!=-1 and v[s.top()]>=v[i]){
//             s.pop();

//         }
       
       
//        k[i]=s.top();
//        s.push(v[i]);


       
       

//     }
//     return k;
// }

 





int maxrain(vector<int> v){
    int m=0;
    // for(int i=0;i<v.size();i++){
    //     for(int j=i;j<v.size();j++){
    //      m=max(abs(i-j)*min(i,j),m); 
    //     }
    // }
    // vector<int> p,q;
    // p=nextsmaller(v);
    // q=prevsmaller(v);

    // for(int i=0;i<v.size();i++){
    //     if(p[i]!=-1){
    //         m=max(m,abs(i-p[i])*min())
    //     }
    // }
}


vector<int> nextsmaller(vector<int> v){
  stack<int> p;
  p.push(-1);
    vector<int> h(v.size());
    for(int i=v.size()-1;i>=0;i--){

        while(p.top()!=-1 and v[p.top()]>v[i]){
            p.pop();
        }
        h[i]=p.top();
        if(h[i]==-1){
            h[i]=v.size();
        }
        p.push(i);

      
    }
    
    return h;
}


vector<int> prevsmaller(vector<int> v){
  stack<int> p;
  p.push(-1);
    vector<int> h(v.size());
    for(int i=0;i<v.size();i++){

        while(p.top()!=-1 and v[p.top()]>v[i]){
            p.pop();
        }
        h[i]=p.top();
        p.push(i);

      
    }
    
    return h;
}

int maxarea(vector<int> v){
    int m=0;
    vector<int> j=nextsmaller(v);
    vector<int> u=prevsmaller(v);



    for(int i=0;i<v.size();i++){

       int r=(j[i]-u[i]+1);
        

        m=max(m,v[i]*r);

    }

    return m;
}



// int cel(vector<vector<int>> m){
     
//      map<int,int> m;

//     for(int i=0;i<m.size();i++){
//           int k=0;
//         // for(int i=0;i<m.size();i++){
//         //   if(i!=j and m[i][j]==1){
//         //       k=1;
//         //   }
//         // }
//         if(count(m[i].begin(),m[i].end(),1)==0){

//             int n=0;
//             for(int j=0;j<m.size();j++){
//               if(m[j][i]==1){
//                  n++;
//               }  
//             }
//             if(n==m.size()-1){
//                 return i;
//                 break;
//             }

//         }
        
//     }
//     return -1;

// }


// int matrixarea(vector<vector<int>> v,int n){

//     for(int i=0;i<n;i++){
         
//     }
// }







// int findcel(vector<vector<int>> v,int n){

//     stack<int> p;
//     for(int i=0;i<n;i++){
//         p.push(i);
//     }
//     while(p.size()>1){
//         int a=p.top();
//         p.pop();
//         int b=p.top();
//         p.pop();
//         if(v[a][b]==1 and v[b][a]==0){
//             p.push(b);

//         }
//         else if(v[b][a]==1 and v[a][b]==0)
//         {
//            p.push(a);
//         }

//     }
//     int h=p.top();
//     bool rowcheck=false;
//    if(count(v[h].begin(),v[h].end(),1)==0){
//       rowcheck=true;
//    }
//    int count=0;
//    for(int i=0;i<n;i++){
//        if(v[i][h]==1){
//         count++;
//        }
//    }
//    if(count==n-1 and rowcheck){
//             return true;

//    }
//    else{
//      return false;
//    }


// }

void line(string s,int i,int n){
    int j=i;
    if(i==1||i==n){
        

        while(j<=s.length()){
            cout<<s[j-1]<<" ";
            for(int i=0;i<n-2;i++){
                cout<<"  ";
            }
            j+=(2*(n-1));
        }

    }
    else{
         
         while(j<=s.length()){
            cout<<s[j-1]<<" ";
            for(int k=0;k<n-1-i;k++){
                cout<<"  ";
            }
            j+=(2*(n-i));
            if(j>=s.length()){
              break;
            }
            cout<<s[j-1]<<" ";
            for(int k=0;k<i-2;k++){
                cout<<"  ";
            }
            j+=(2*(i-1));
         }


    }

    cout<<endl;
}


void disp(string s,int numRows){
    for(int i=1;i<=numRows;i++){
        line(s,i,numRows);
    }

}


string p(vector<int> nums){
      map<int,vector<int>> m;
     for(int i=0;i<nums.size();i++){
        
     }

}





int main() {  
  
//   stack<int> r;
//   r.push(6);
//   r.push(3);
//   r.push(1);
//   r.push(5);
//   r.push(7);


// cout<<r.size();
// sort2(r);
//   while(!r.empty()){
//     cout<<r.top()<<" ";
//     r.pop();
//   }

//   cout<<ret("((a+(b*c)))");
//   string s="))(((())())(";
//   cout<<mincost(s);


// vector<int> v={2,1,6,7,2,3};

// cout<<maxarea(v)<<endl;

// for(int i=0;i<prevsmaller(v).size();i++){
//     cout<<prevsmaller(v)[i]<<" ";
// }

// cout<<endl;
// for(int i=0;i<nextsmaller(v).size();i++){

//     cout<<nextsmaller(v)[i]<<" ";
// }

string p="paypalishiring";
int k=4;
disp(p,k);



  return 0;
}