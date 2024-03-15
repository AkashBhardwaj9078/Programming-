#include <bits/stdc++.h>

using namespace std;

int prt(int arr[],int first,int last){
    int i=first-1;
    int j=first;
    int pivot=arr[last];
    while(j<last){
        if(arr[j]<arr[last]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[last]);
    return i+1;

}
int prtn(int arr[],int first,int last ){
    int i=first-1;
    int j=first;
    while(j<last){
        if(arr[j]<arr[last]){
            i++;
            swap(arr[i],arr[j]);
        }
    } swap(arr[i+1],arr[last]);
    return i+1;
}
void srt(int arr[],int first,int last){
    if(first>last){
        return ;
    }

   srt( arr,first,prtn(arr,first,last)-1);
   srt( arr,prtn(arr,first,last)+1,last);
}


void countsortpos(vector <int> &v , int pos){
    
   
    vector <int> freq(10,0),ans(v.size());
    for(auto i:v){
        freq[(i/pos)%10]++;
    }
    for(int i=1;i<10;i++){
     freq[i]+=freq[i-1];
    }

    for(auto i:v){
        ans[--freq[(i/pos)%10]]=i;
    }
     v=ans;
}
void radix(vector <int> v){
  
  int mx=INT_MIN;
    for(auto i:v){
        mx=max(i,mx);
    }
    for(int i=1;(mx/i)>0;i*=10){
        countsortpos(v,i);
    }
}

void countsort(vector <int> &v){
    int n=v.size();
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        mx=max(mx,v[i]);
    }
    vector <int> ans(n),fre(mx+1,0);
    for(int i=0;i<n;i++){
        fre[v[i]]++;
    }
    for(int i=1;i<mx+1;i++){
        fre[i]+=fre[i-1];
    }
    for(int i=0;i<n;i++){
        ans[--fre[v[i]]]=v[i];
    }
    v=ans;
}

void quicksort(int arr[],int i,int j){
    if(i>j){
        return;
    }
       int p=prt(arr,i,j);
       quicksort(arr,i,p-1);
       quicksort(arr,p+1,j);

}


// int partition(vector <int> &v,int f,int l){
//     int i=f-1;
//     int j=f;
//     while(j<l){
//         if(v[j]<v[l]){
//             i++;
//             swap(v[i],v[j]);
//         }
//         j++;
//     }
//     swap(v[i+1],v[l]);
//     return i+1;
// }


// void qksrt(vector <int> &v,int i,int j){
//      int p=partition(v,i,j);
//      qksrt(v,i,p-1);
//      qksrt(v,p+1,j);
// }



// int pt(int arr[],int f,int l){
//     int i=f-1;
//     int j=f;
//     while(j<l){
//         if(arr[i]<arr[l]){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//   j++;
//     }
//     swap(arr[i+1],arr[j]);
//     return i+1;
// }

// void sort(int arr[],int i,int j){
//     if(i>j){
//         return;
//     }
//     int p=pt(arr,i,j);
//     sort(arr,i,p-1);
//     sort(arr,p+1,j);
// }
int partition(int arr[],int f,int l){
    int i=f-1,k=f;
    for(int k=f;k<l;k++){
        if(arr[k]<arr[l]){
            i++;
        }


    }
    swap(arr[i+1],arr[k]);
    return i+1;

}
void qksrt(int arr[],int i,int j){
    if(i>j){
        return ;
    }
    int p=partition(arr,i,j);
    qksrt(arr,i,p-1);
    qksrt(arr,p+1,j);
}


void cntsrt(vector <int> &v){
     int mx=INT_MIN;
     for(auto i:v){
        mx=max(mx,i);
     }
     vector <int> freq(mx+1,0),ans(v.size());
     for(int i=0;i<v.size();i++){
         freq[v[i]]++;
     }
     for(int i=1;i<mx+1;i++){
        freq[i]+=freq[i-1];
     }
     for(int i=0;i<v.size();i++){
        ans[--freq[v[i]]]=v[i];
     }
     v=ans;
}

void bucketsort(float arr[],int size){
    
    vector <vector <float>> bucket(size,vector<float> ());
    for(int i=0;i<size;i++){
        int j=arr[i]* size;
        bucket[j].push_back(arr[i]);
    }
for(int i=0;i<size;i++){
    int j=arr[i]* size;
    bucket[j].push_back(arr[i]);
}

for(int i=0;i<size;i++){
    if(!bucket.empty()){
        sort(bucket[i].begin(),bucket[i].end());
    }
int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}
//     for(auto i:bucket){
//         if(!i.empty()){
// sort(i.begin(),i.end());
//         }
        
//     }
//     int k=0;
//     for(auto i:bucket){
//         if(!i.empty()){
//             for(int j:i){
//                 arr[k]=j;
//                 k++;
//             }
//         }
//     }
}


int main() {  
//   int  arr[]={5,3,2,4,6,1};
  vector <int> v={3,4,5,2,3,4,2,3,4,5,4,3,2};

  int arr[]={12,34,23,12,34,23,45};
  quicksort(arr,0,6);

//   quicksort(arr,0,n-1);
  
// float arr[]={0.21,0.12,0.23,0.32,0.21,0.12,30.34};
// bucketsort(arr,7);
//  int a=arr[0];
//   for(int i=0;i<n;i++){
//      a=max(a,arr[0]);
//   }
//   int freq[a+1]={0};
//   for(int i=0;i<n;i++){
//     freq[arr[i]]++;
//   }
// //   int j=0;
// //   for(int i=0;i<a+1;i++){
// //     for(int j=0;j<freq[i];j++){
// //        arr[j]=i;
// //        j++;
// //     }
// //   }

// for(int i=1;i<a;i++){
//   freq[i]+=freq[i-1];
// }
// int ans[n];
// for(int i=n-1;i>0;i++){
//     ans[freq[--arr[i]]]=arr[i];
// }
 

for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}
// for(int i=0;i<a+1;i++){
//     cout<<freq[i]<<" ";
// }

  return 0;
}