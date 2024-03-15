#include <bits/stdc++.h>

using namespace std;





void paths(int i,int j,int m,int n,vector <string> &v,string h){
  if(i==m-1 and j==n-1){
      
v.push_back(h);
  }
  else if(i>=m||j>=n||i<0||j<0){
     return;
  }
  else{
    string p=h+'R',q=h+'D',s=h+'L',t=h+'U';
    paths(i+1,j,m,n,v,p);
    paths(i,j+1,m,n,v,q);
    // paths(i-1,j,m,n,v,s);
    // paths(i,j-1,m,n,v,t);
  }
}

// void paths2(vector<vector<int>> v,int i,int j,int m,int n,vector <string> &a,string h){
//   if(i==m-1 and j==n-1){
//     a.push_back(h);
//   }
//   else if(i>=m-1||j>=n-1){
//     return ;
//   }
//   else{
//     if(v[i+1][j]==1){
//       string p=h+'R';
//       paths2(v,i+1,j,m,n,a,p);
//     }
//     if(v[i][j+1]==1){
//       string p=h+'D';
//       paths2(v,i,j+1,m,n,a,p);
//     }
//     // if(v[i-1][j]==1){
//     //   string p=h+'L';
//     //   paths2(v,i-1,j,m,n,a,p);
//     // }
//     // if(v[i][j-1]==1){
//     //   string p=h+'U';
//     //   paths2(v,i+1,j,m,n,a,p);
//     // }
    
    
    
    
//   }
// }


void  trek(vector <string> &v,int i,int j,int m,int n,vector<vector<int>> h,string k){
    if(h[i][j]==0 ||i>=m||j>=n|| i<0||j<0){
        return;
    }
    else if(i==m-1 and j==n-1){
        v.push_back(k);
    }
    else{
       trek(v,i+1,j,m,n,h,k+'R');
       trek(v,i,j+1,m,n,h,k+'D');
       trek(v,i-1,j,m,n,h,k+'L');
       trek(v,i,j-1,m,n,h,k+'U');
    }

}



// void paths2(vector <vector <int>> v,int i,int j,int )

// void fun2(string j,vector <string > &v,vector <string> &h,int k){
//     if(k==j.size()){
//         return ;
//     }
    
//     for(auto i:v){
//         h.push_back(i+j[k]);
//     }
//     fun2(j,v,h,k+1);
    
// }
// void fun1(string num,int k,map<char,string> m, vector <string> &v,vector <string> &d){
//     if(k==num.length()){
//        d=v;
//        return;
//     }
//     vector <string> h;
//     fun2(m[num[k]],v,h,0);
//     v=h;

//     fun1(num,k+1,m,h,d);
// }

void test(vector <int> &p){
 vector <int> k;
 for(int i=0;i<p.size();i++){
    k.push_back(p[i]+3);
 }
 p=k;

}


// int binsearch(vector <int> v){
  
//   int i=0;
//   int j=v.size()-1;
//   if(v[i]<v[j]){
    
//     return i;
//   }
//   while(i<j){
//     int m=i+(j-i)/2;
//     if(v[m]>v[m+1]) {
//       return m+1;
//     }
//     else if(v[m]>v[m-1]){
//       return m;
//     }
//     if(v[m]>v[i]){
//       i=m+1;
//     }else{
//       j=m-1;
//     }
    
//   }
//   return -1;
// }


int findsortedshifted(vector <int> v,int k){
  int i=0,j=v.size()-1;
  while(i<j){
    int m=i+(j-i)/2;
    if(v[m]==k){
      return m;
    }
    if(v[m]>v[i]){
      if(k>=v[i] and k<=v[m]){
        j=m-1;
      }
      else{
        i=m+1;
      }
    }
    else{
      if(k<=v[j] and k>=v[m]){
         i=m+1;
      }
      else{
         j=m-1;
      }
    }

  }
  return -1;
}

int  minidx(vector <int> v){
  int i=0,j=v.size()-1;
  if(v.size()==1) return v[0];
  if(v[i]<v[j]){
    return i;
  }
  while(i<j){
    int m=i+(j-i)/2;
    if(v[m]>v[m+1]){
      return m+1;
    }
    if(v[m]<v[m-1]){
      return m;
    }
     if(v[m]>v[i]){
        i=m+1;
    }
    else{
         j=m-1;
    }
  }
}



int target (vector <int> v,int k){
   int i=0,j=v.size()-1;

   while(i<j){
    int m=i+(j-i)/2;
    if(v[m]==k){
      return m;
    }
    if(v[m]>v[i]){
         if(v[i]<k and k<=v[m]){
          j=m-1;
         }
         else{
          i=m+1;
         }
    }
    else{
      if(v[m]<=k and k<v[j]){
        i=m+1;
      }
      else{
        j=m-1;
      }
    }
   }

  return -1;
}


int peakindex(vector<int>v){
    if(v.size()==1){
      return 0;
    }
    int i=0,j=v.size()-1;
      
      while(i<j){
        int m=i+(j-i)/2;
        if(v[m]>v[m-1] and v[m]>v[m+1]){
          return m;
        }
        else{
          if(v[m]>v[m+1]){
            j=m-1;
          }
          else{
            i=m+1;
          }
        }
      }
    
}
int mnidx(vector <int> v){
  int i=0,j=v.size()-1;
  if(v.size()==1){ 
    return v[0];
  }
  while(i<j){
    int m=i+(j-i)/2;
    if(v[m]>v[m+1]){
      return m+1;
    }
    if(v[m]<v[m-1]){
      return m;
    }
    if(v[m]>v[i]){
         j=m-1;
    }
    else{
      i=m+1;
    }
  }
}




// int minidx(vector <int> v){
//   int i=0,j=v.size()-1;
//   int r=-1;
//   if(v[i]<v[j]){
//     return i;
//   }

//   int p=v[0];
//   while(i<j){
//     int m=i+(j-i)/2;
//     if(v[m]<p){
//       r=m;
//       j=m-1;
//     }
//     else if(v[m]>=p){
//        i=m+1;
//     }
//   if(i==j){
//     break;
//   }

//   }
//   return r;
// }


// int binsorted(vector <int> v,int key){
//   int i=0,j=v.size()-1;
//   int r=-1;
//   while(i<j){
//     int m=i+(j-1)/2;
//     while(i<j){
//       if(v[m]==key){
//         r=m;
//         break;
//       }
//      else  if(v[m]>=v[i]){
//         if(key>v[i] and key<=v[m]){
//              j=m-1;
//         }
//         else{
//           i=m+1;
//         }
//       }
//       else {
//         if(v[m]<=key and key<=v[j] ){
//           i=m+1;
//         }
//         else{
//           j=m-1;
//         }
//       }

//     }
//   }
//   return r;
// }


// bool ispossible(int m,vector <int> v,int k){
//   int sum=0;
//   int r=1;
//   int i=0;
//   while(i<v.size()-1){
//     if(v[i]+sum<=m){
//       sum+=v[i];
//     }
//     else{
//         sum=v[i];
//         r++;
//         if((r>=k and i!=v.size()) || sum>m){
//             return false ;
//             break; 
//         }
//     }
//     i++;
//   }
//   return true;
// }
int count(vector <int> v,int p ){
 int i=1;
 int m=v[0];
 for(int j=1;j<v.size();j++){
  if(v[j]>=p+m){
     m=v[j];
     i++;
  }

 }
return i;
} 


bool check(vector<int> v,int p,int k){

  if(count(v,p)>=k){
    return true;
  }
  else{
    return false;
  }
}

// int p(string &h){

//   if(h.length()<2){
//     return 0;
//   }
//   else if(h.find("10")!=string::npos and h.find("01")!=string::npos){
//     return 1+ max(p(h.erase(h.find("10"),2)),p(h.erase(h.find("01"),2)));
//   }
//   else if(h.find("10")!=string::npos and h.find("01")==string::npos){
//     return 1+p(h.erase(h.find("10"),2));
//   }
//   else if(h.find("10")==string::npos and h.find("01")!=string::npos){
//     return 1+p(h.erase(h.find("01"),2));
//   }
//    else if(h.find("10")==string::npos and h.find("01")==string::npos){
//     return 0;
//   }
 
// }


int p(string h){
  if(h.length()<2){
    return 0;

  }
  else if(h.find("10")!=string::npos and h.find("01")!=string::npos){
    string j=h,k=h;
    j.erase(j.find("10"),2);
    k.erase(k.find("01"),2);
    return 1+max(p(j),p(k));
  }
  else if(h.find("10")!=string::npos and h.find("01")==string::npos){
     string j=h;
     j.erase(j.find("10"),2);
     return 1+p(j);
  }
 else if(h.find("10")==string::npos and h.find("01")!=string::npos){
    string k=h;
    k.erase(k.find("01"),2);
    return 1+p(k);
  }
  else if(h.find("10")==string::npos and h.find("01")==string::npos){
    return 0;
  }
}


void sums(vector <int> v,int i,vector <int> &h,int sum){
  if(i==v.size()){
    h.push_back(sum);
  }
  else{
    sums(v,i+1,h,sum+v[i]);
    sums(v,i+1,h,sum);
  }
}


vector <int> a(vector <int> p,int j){
  vector <int> k;
  if(j==p.size()){
    k.push_back(0);
    return k;

  }
  else{

    for(auto i:a(p,j+1)){
      k.push_back(i+p[j]);
      k.push_back(i);
    }
  }
  return k;
}



void  fun3(string s,int j,vector <string> v,vector <string> &h){
           
           if(j==s.length()){
            return ;
           }
           else{
            for(auto i:v){
              h.push_back(i+s[j]);
            }
            fun3(s,j+1,v,h);
           }

}

void fun4(string s,int i,vector<string> v,vector <string> &h,map<char,string> m){
  vector <string> p;
  if(i==s.length()){
    h=v;
    return;
  }
  else{
    fun3(m[s[i]],0,v,p);
    v=p;
    fun4(s,i+1,v,h,m);
  }

}

// int closesttomidsum(vector <int> v){
//   int sum=0;
//   for(int i=0;i<v.size();i++){
//    sum+=v[i];
//   }
//   int mid=sum/2;
//   vector<int> k;
//   possiblesums(v,k,0,0);
//   sort(k.begin();k.end())
// }


// int minutes(string s,map<char,int> &m,int k,int count){
//   if(count==3){
//     return 0;
//   }



// }



int midx(vector <int> v){
  int i=0,j=v.size()-1;
  while(i>j){
      int m=i+(j-1)/2;
      if(v[m]<v[m-1]){
        return m;
      }
      else if(v[m]>v[m+1]){
        return m+1;
      }
      else{
        if(v[m]<v[m+1]){
          i=m+1;
        }
        else{
          j=m-1;
        }
      }
  }
  return -1;
}


void ret(vector<int> &v,int i){
 if(i==v.size()){
  return;
 }
 else{
  v[i]+=v[i-1];
  ret(v,i+1);
 }
}


int minutes(string s,map<char,int> m,int k,int count,int len){
  if(count==3){
    return 0;
  }
  else if(s.length()==1){
     m[s[0]]++;
     if(m[s[0]]==k){
      count++;
      if(count==3){
        return 1;
      }
      else{
        return len;
      }
     }
  }
  else if(s.length()>1){
    map<char,int > n=m,p=m;
    int cnt1=count,cnt2=count;
    n[s[0]]++;
    if(n[s[0]]==k){
      cnt1++;
    }
    p[s[s.length()-1]]++;
    if(p[s[s.length()-1]]==k){
      cnt2++;
    }
    string j=s.substr(0,s.length()-1),q=s.substr(1,s.length()-1);
    return 1+min(minutes(j,n,k,cnt1,len),minutes(q,p,k,cnt2,len));
  }
}

int ans(string s,map<char,int> m,int k,int count,int len){
  if(minutes( s, m,k, count,len)>len){
    return -1;
  }
  else{
    return minutes( s, m,k, count,len);
  }
}

// void prefixrow(vector<vector<int>> &v,int j){
//   if(j==v.size()) return;
//       ret(v[j],1);
//       prefixrow(v,j+1);


// }

// void prefixcolumn(vector<vector<int>>&v,int k){

//   if(k==v.size()) return ;
//      for(int i=0;i<v.size();i++){
//        v[k][i]=+=v[k-1][i];
//      }

//  prefixcolumn(v,k+1);

// }


void store(char w,string h,vector <string> &v,int i){

  
  if(i==h.length()){
     string d=(h.substr(0,i)+w);
    v.push_back(d);
    
  }
  
  else{

    
      string d=(h.substr(0,i)+w+h.substr(i,h.length()-(i)));
    v.push_back(d);
    
     
    
    

    store(w,h,v,i+1);

  }
}

// void permutate(string p,int i,vector <string>&v){
//   if(i==p.length()){
//     return ;
//   }
//   else{
//     string s=p;
//     s.erase(i,1);
//     //  store(p[i],s,v,0);
//     //  permutate(p,i+1,v);
//   }
  
// }

void permutate(string s,string h,vector <string> k){
  
  if(s==""){
    k.push_back(h);
  }
  else{
    for(int i=0;i<s.length();i++){
      string r=s.substr(i+1);
      string l=s.substr(0,i);
      permutate((l+r),(s[i]+""),k);
    }
  }

}


int main() {  
 
   

  //  int j=v[4]-v[0];
  //  int i=0;
  //  int r;
  //  while(i<j){
  //   int m=i+(j-i)/2;
  //   if(check(v,m,3)){
  //     r=m;
  //     i=m+1;
  //   }
  //   else{
  //     j=m-1;
  //   }
  //  }



//   test(p);
// vector<vector<int>> v={{1,1,0,0},{0,1,1,1},{1,1,1,0},{0,0,1,1}};


// cout<<v.size();


// paths2(v,0,0,4,4,k,h);

// for(auto i:k){
//   cout<<i<<" ";
// }



// vector <int> v={1,2,3,4},p;
// int sum=0;

// sums(v,0,p,0);
// for(auto i:p){
//   cout<<i<<" ";
// }
// cout<<endl;

// vector <string> h;
// string p="";
// paths(0,0,2,3,h,p);
// for(auto i:h){
//   cout<<i<<" ";
// }
vector<string> h;
string k="lkj";
// permutate(k,"",h);
store(k[i],k.substr(0,i)+k.substr(i+1),h,0);

for(int i=0;i<k.length();i++){
 
}
for(auto i:h){
 
  
}


// for(auto i:a(v,0)){
//   cout<<i<<" ";
// }
//  map<char,string>m;
//  m['2']="abc";
//  m['3']="def";
//  m['4']="ghi";
//  m['5']="jkl";
//  m['6']="mno";
//  m['7']="pqrs";
//  m['8']="tuv";
//  m['9']="xyz";
//  string num="23";


// string p="2335";
// vector <string> v={""},h;


//  fun4(num,0,v,h,m);
//  for(auto i:h){
//   cout<<i<<" ";
//  } 




// vector <int> v={12,34,67,90};
// int sum=0;
// for(int i=0;i<v.size();i++){
//   sum+=v[i];
// }
// int i=0,j=sum;
// int r=0;
// while(i<j){
//   int m=i+(j-i)/2;
//   if(ispossible(m,v,2)){
//     r=m;
//      j=m-1;
//   }
//   else{
//     i=m+1;
//   }
// }


// map<char,int> m;int k=2;
// int p=0;





  return 0;
}