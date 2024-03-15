#include <bits/stdc++.h>

using namespace std;

int binarysearch(int left,int right,vector<int> vect,int target){
   int size=left-right+1;
    if(size<=3){
        for(int i=left;i<=right;i++){
            if(vect[i]==target){
                return i;
            }
        }
        return -1;

    }
    if(left<=right){
      int mid=left+(right-left)/2;
    if(vect[mid]==target){
        return mid;
    }
    if(vect[mid]>target){
        return binarysearch(left,mid-1,vect,target);
    }
    if(vect[mid]<target){
        return binarysearch(mid+1,right,vect,target);
    }
    }

    return -1;
    
}
    int minSubarray(vector<int>& nums, int p) {
      
      for(int i=0;i<nums.size();i++){
     if(i==0){
        nums[i]=nums[i]%p;
     }else{
        nums[i]=(nums[i]+nums[i-1])%p;
     }
      }
      int remove=nums[nums.size()-1];
      if(remove==0){
        return 0;
      }
      unordered_map <int,int> np;
      np[0]=-1;
      int res=INT_MAX;
      for(int i=0;i<nums.size();i++){
          int rem=nums[i];
          if(rem<0){
              rem+=p;
          }
          int find=rem-remove;
          if(find<0){
              find+=p;
          }
          if(np.find(find)!=np.end()){
              res=min(i-np[find],res);
              
          }
          np[rem]=i;
      }
   

   if(res==nums.size()){
       return -1;
   }
   else{
       return res;
   }
    }

int leftmost(vector<int> vect,int size,int target){
  int left=0,right=size-1;
  int res=-1;
  int mid=left+(right-left)/2;
  while(left<right){
    
    if(vect[mid]==target){
        res=mid;
        right=mid-1;
    }
    if(vect[mid]>target){
         right=mid-1;

    }
    if(vect[mid]<target){
         left=mid+1;

    }

   mid=left+(right-left)/2;
  }
return res;
}
 int peakIndexInMountainArray(vector<int>& vect) {
        
    int size=vect.size();
    int left=0,right=vect.size()-1;
    int mid=left+(right-left)/2;
    int ans=-1;
    while(left<=right){
        if(vect[mid]>vect[mid-1] and vect[mid]>vect[mid+1]){
            ans=mid;
            break;
        }
   
          else if((vect[mid]<vect[mid+1] )){
            left=mid+1;
        }
        else{
            right=mid;
        }
        mid=left+(right-left)/2;
        
    }
    return ans; 
    }

int pivotsortedrotatedarr(vector<int> arr){

    int left=0,right=arr.size()-1;
    int mid=left+(right-left)/2;
    int ans=-1;
    while(left<right){
          if(arr[mid]>=arr[left]){
            left=mid+1;
          }
           else{
            if(arr[mid]<arr[mid-1]){
              ans=mid;
            }
            right=mid;
          }
                mid=left+(right-left)/2;
    }
    return left;
}

 int findpeak(vector<int> vect){
        if(vect.size()==1){
            return 0;
        }
        if(vect.size()==2){
            if(vect[0]>vect[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        int low=0, high=vect.size()-1;
        int mid=low+(high-low)/2;

        while(low<high){
            if(vect[mid]<vect[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
           mid=low+(high-low)/2;
        }
        return low;
    }


   
int minSizeSubarray(vector<int>& nums, int target) {
        int acc=accumulate(nums.begin(),nums.end(),0);
          int rem= target % acc;
          int pkt=target/acc;

          int mn=INT_MAX;
          int sum=0;
          map<int,int> np;
          np[0]=-1;
          for(int i=0;i<2*nums.size();i++){
            int    idx=i % nums.size();
              sum+=nums[idx];
              if(np.find(sum-rem)!=np.end()){
                  mn=min(i-np[sum-rem],mn);
                  cout<<i<<" "<<np[sum-rem]<<" "<<mn<<" "<<sum<<endl;
              }
              np[sum]=i;



          }
            if(mn==INT_MAX){
                return -1;
            }
            else{
                return mn+(pkt*nums.size());
            }
}
 int findMaxK(vector<int>& nums) {
        int mx=INT_MIN;
        map<int,int> np;
        for(int i=0;i<nums.size();i++){
            if( np[-nums[i]]!=0){
                mx=max(mx,abs(nums[i]));
          }
          np[nums[i]]++;
        
        }

    
    if(mx==INT_MIN){
            return -1;
        }
        else{
            return mx;
        }
 }

  int search(vector<int>& nums, int target) {
        int low =0,high=nums.size()-1;
        int mid=low+(high-low)/2;
        int ans=-1;
        while(low<high){
            cout<<low <<" "<<high<<" "<<mid<<endl;
           if(nums[mid]==target){
               ans=mid;
               return ans;
           }
           if(nums[low]<=nums[mid]){
               if(nums[low]<=target and target<nums[mid]){
                   high=mid;
               }
               else low=mid+1;

           }
           else{
               if(nums[mid]<target and target<=nums[high]){
                low=mid+1;

               }
               else{
                   high=mid;
               }

           }
         
           mid=low+(high-low)/2;
        }
        if(nums[low]==target) {return high;}

        return ans;
    }
  int rightmost(vector<int> vect ,int target){
        int low=0,high=vect.size()-1;
        int mid=low+(high-low)/2;
        int ans=-1;
        while(low<high){
            if(vect[mid]==target){
                ans=mid;
                cout<<low<<" "<<mid<<" "<<high<<endl;;
                low=mid+1;
            }
            if(vect[mid]>target){
                high=mid;
            }
            if(vect[mid]<target){
                low=mid+1;
            }

            mid=low+(high-low)/2;
        }
        return ans;

    } 

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=m*n-1;
        int mid=low+(high-low)/2;
        while(low<high){
            int r=mid/n,c=mid % n;
            if(matrix[r][c]==target){
                return true;
            }
             if(matrix[r][c]<target){
                low=mid+1;
            }
            if(matrix[r][c]>target){
                
                high=mid;
            }
            cout<<low<<" "<<mid<<" "<<high<<endl;;
            mid=low+(high-low)/2;

        }
     return false;
    } 

void nextPermutation(vector<int>& nums) {
       int j=nums.size()-1;
       while(j>0){
           if(nums[j]>nums[j-1]){
               break;
           }
           j--;
       } 
       if(j==0){
           reverse(nums.begin(),nums.end());
       }
       else{
           int idx=j-1;
           int k=nums.size()-1;
        while(nums[k]<=nums[idx]){
              k--;

       }
       cout<<idx<<" "<<k;
       swap(nums[idx],nums[k]);
       reverse(nums.begin()+idx+1,nums.end());
       }
  }
  vector<int> rightgreater(vector<int> height){
        vector<int> ans(height.size(),0);
        int mx=INT_MIN;
        for(int i=height.size();i>=0;i--){
            
            mx=max(mx,height[i]);
            ans[i]=mx;
            
        }
        return ans;

    }
     vector<int> leftgreater(vector<int> height){
        vector<int> ans(height.size(),0);
        int mx=INT_MIN;
        for(int i=0;i<height.size();i++){
            mx=max(mx,height[i]);
            ans[i]=mx;
        }
        return ans;

    }
    int trap(vector<int>& height) {
        vector<int> r=rightgreater(height),l=leftgreater(height);
        int ans=0;
        for(int i=1;i<height.size()-1;i++){
            ans+=(min(r[i],l[i])-height[i]);


        }
        return ans;
    }
      class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<std::vector<int>> triangle;
    
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }

    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }
};

void path(vector<vector<int>> grid,int i,int j,int &c,string k,vector<string> &v){
        int n=grid.size()-1,m=grid[0].size()-1;
        if(i==n and j==m){
            c++;
            v.push_back(k);
            return ;
        }
        if(i>n||j>m||i<0||j<0||grid[i][j]==1){
            return ;
        }


        grid[i][j]=1;
        k.push_back('R');

        path(grid,i+1,j,c,k,v);
        k.pop_back();
        k.push_back('L');

        path(grid,i-1,j,c,k,v);
        k.pop_back();
        k.push_back('U');
      path(grid,i,j-1,c,k,v);
         k.pop_back();

k.push_back('D');
        
        
        path(grid,i,j+1,c,k,v);
        k.pop_back();
      


    }

     int mn(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> v){
        if(v[i][j]!=-1) return v[i][j];
        if(i==triangle.size()-1){
            return v[i][j]=triangle[i][j];
        }
        return  v[i][j] =triangle[i][j]+min(mn(i+1,j,triangle,v),mn(i+1,j+1,triangle,v));

    }
        int minimumTotal(vector<vector<int>>& tr,int r=0,int c=0) {
        int n=tr.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
        dp[n-1][i]=tr[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<tr[i].size();j++)
            {
                dp[i][j]=tr[i][j];
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    void sortColors(vector<int>& nums) {
         int low =0,mid=low,high=nums.size()-1;
         while(mid<high){
           
             if(nums[mid]==2){
                 while(nums[high]==2){
                     high--;
                 }
                 if(high<mid){
                     break;
                 }
                 
                 swap(nums[mid],nums[high]);
             }
             if(nums[mid]==0){
                 while(nums[low]==0){
                     low++;
                 }
                 if(mid>low){
                     swap(low,mid);

                 }
                 else{
               swap(nums[mid],nums[low]);
                 }



             }
             if(nums[mid]==1){
                 mid++;
             }
             cout<<mid<<" "<<high<<" "<<low<<endl;
         }
    }

     void solve(int i,int lad,int brick,vector<int> heights,int &mx){
         if(i==heights.size()){
             
             return ;
         }
         
         if(lad<0 ||brick<0){
            return ;
         }
         
         
        if(heights[i]>brick and lad==0){
            mx=max(i-1,mx);
        }
        else{
            mx=max(i,mx);
        }
        cout<<lad<<" "<<brick<<" "<<mx<<" "<<i<<endl;
         
          
         solve(i+1,lad-1,brick,heights,mx);
         solve(i+1,lad,brick-heights[i],heights,mx);
     }
        int longestValidParentheses(string s) {
        stack <pair<int,int>> st;
        vector<int> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }
           else if(!st.empty() and st.top().first=='('){
                v.push_back(st.top().second);
                v.push_back(i);
                st.pop();
            }
            
        }
        int len=0;
        int mx=0;

        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]==1){
                len++;
                mx=max(len,mx);
                
            }
            else{
                len=0;
            }
        }
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
        return mx;
    }

        vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> v(n,vector<int>(n));
       int c=1;
       int rs=0,cs=0,re=n-1,ce=n-1;
       while(c<=n*n) {
         for(int i=cs;i<=ce;i++){
           v[rs][i]=c;
           cout<<rs<<" "<<i<<endl;
           
           c++;
         }
         rs++;
         for(int i=rs;i<=re;i++){
             v[i][ce]=c;
             cout<<i<<" "<<ce<<""<<c<<endl;
             
             c++;
         }
         ce--;
         for(int i=ce;i>=cs;i--){
             v[re][i]=c;
             cout<<re<<" "<<i<<""<<c<<endl;
             
             c++;
         }
         re--;
         for(int i=re;i>=rs;i--){
             v[i][cs]=c;
             cout<<i<<" "<<cs<<""<<c<<endl;
           
             c++;
         }
         
         cs++;
       }
       return v;
    }
      int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        
        for(int i=0;i<n;i++){
             if(gas[i]>=cost[i]){
                 int fill=gas[i]-cost[i];;
                 int j=i+1;
                  cout<<fill<<" "<<j<<" "<<i<<endl;
               
                 while(j%n!=i){
                   int  idx=j%n;
                     if(fill-cost[idx]+gas[idx]>=0){
                         fill=fill-cost[idx]+gas[idx];
                         cout<<fill<<" "<<j<<" "<<i<<endl;
                         j++;
                     }
                     else{
                        break;
                     }
                   
                }
                if(j%n==i){
                    return i;
                }
             }
               
        }
        return -1;
    }


    int tostring(string s){
       int ans=0;
       
       for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
        continue;
       }
        ans=ans*10+(s[i]-'0');
       }
       cout<<" num "<<ans<<endl;
       if(s[0]=='-'){
         return -ans;
       }
      return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto  i:tokens){

            if(i=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                cout<<a<<" "<<b<<" "<<a+b<<endl;
                st.push(a+b);

            }

            
           else if(i=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                cout<<a<<" "<<b<<" "<<a+b<<endl;
                st.push(a*b);

            }
            
           else if(i=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                cout<<a<<" "<<b<<" "<<a+b<<endl;
                st.push(a-b);

            }
            
           else if(i=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                cout<<a<<" "<<b<<" "<<a/b<<endl;
                st.push(a/b);

            }

            else {
                cout<<tostring(i)<<endl;
              st.push(tostring(i));
            }
        }

        return st.top();
    }

    int solve(int i,vector<int> nums,vector<int> v){
      if(v[i]!=-1) return v[i];
     if(i>=nums.size()) return v[i]=0;
     

     else {
         return v[i]=max(solve(i+1,nums,v),nums[i]+solve(i+2,nums,v));
     }


}
    int rob(vector<int>& nums) {
        vector<int> v(nums.size()+2,-1);
        return solve(0,nums,v);
        
    }
 int idx(int n,int s){
        int p=n%s;
        if(p<0){
            p+=s;
        }
        return p;
    }
    bool circularArrayLoop(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        int ptr=0;
        v[0]=1;
        int prev=-1;
        while(1){
            int newptr=idx(nums[ptr]+ptr,nums.size());
            
            if(newptr==ptr||prev==newptr){
            return false;
            break;
            } 
            cout<<prev<<" "<<ptr<<" "<<nums[ptr]<<" "<<newptr<<endl;
            prev=ptr;
            ptr=newptr;
            if(v[ptr]==1) return true;
            else v[ptr]=1;
        }

        return false;
    }

      int num(int x){
        int p=10;
        int ans=1;
        while(x>=p){
            p*=10;
            ans++;
        }
        return ans;
    }
    int compress(vector<char>& chars) {
        map<char,int> mp;
        for(int i=0;i<chars.size();i++){
       mp[chars[i]]++;
       cout<<chars[i];

        }
        int sum=0;
        cout<<endl;
        for(auto i:mp){
            cout<<i.second;
            if(i.second==1){
                sum+=1;
            }
            else{
              sum+=2*num(i.second);
            }
        }

        return sum;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int slow = 0, fast = 1, ans = 0;
        while(slow < nums.size() && fast < nums.size()){
            if(nums[fast] - nums[slow] == k){
                slow++;
                fast++;
                ans++;
                while(fast < nums.size() && nums[fast] == nums[fast - 1]) fast++;
            }
            else if(nums[fast] - nums[slow] > k){
                slow++;
                if(fast - slow == 0) fast++;
            }
            else fast++;            
        }
        return ans;
    }
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i=s.length()-1;
        int k=i;
        while(i>0 and s[i-1]>=s[i] ){
            i--;
            cout<<i<<" i"<<endl;
        }
        if(i==0) return -1;
        int j=i-1;
        cout<<i<<" i"<<endl;
        while(s[j]>s[k]){
            k--;
        }
        cout<<j<<" "<<k<<endl;
        swap(s[j],s[k]);
        reverse(s.begin()+k,s.end());
        return stoi(s);
        
    }
  bool isvalid(int n,vector<int> nums,int k){
        int currentsum=0;
        int student=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>n) return false;
            else{
                if(nums[i]+currentsum<=n){
                    currentsum+=nums[i];
                }
                else{
                    student++;
                    currentsum=nums[i];
                }
                if(student>k){
                    return false;
                }
            }
          
        }
        return true;
  }
  

  int maxalloc(vector<int> nums,int k){

   int e=accumulate(nums.begin(),nums.end(),0);
   int s=nums[0];
   int m=s+(e-s)/2;
    while(s<e){
         if(!isvalid(m,nums,k)){
             s=m+1;
         }
         else{
            e=m;

         }
         cout<<m<<endl;
       m=s+(e-s)/2;
    }

   return s;
  }
   
  

    bool ispossible(vector<int> nums,int m,int k){
        int p=nums[0];
        int c=1;
       for(int i=1;i<nums.size()-2;i--){
            
            if(nums[i]-nums[i-1]>m){
               return false;
            }
            if(nums[i+1]-p>m){
                c++;
                p=nums[i];
            }
            if(c>k){
                return false;
            }
       }
    return true;
    }
  int mindist(vector<int> nums,int k){
    
    sort(nums.begin(),nums.end());
    int s=0,e=nums.back()-nums[0];
    int m=s+(e-s)/2;
    while(s<e){
        if(!ispossible(nums,m,k)){
            s=m+1;
        }
        else{
            e=m;
        }
        cout<<m<<endl;;
        m=s+(e-s)/2;
    }

    return s;

  }

  int f(int k,int n){
    if(k>n) return 0;
    if(k==n){
        return 1;
    }
    return f(k+2,n)+f(k+1,n);

  }


int numtriangles(vector<int> v){
   if(v.size()<3) return 0;
   sort(v.begin(),v.end());
   int sol=0;
   for(int i=2;i<v.size();i++){
      int l=0,r=i-1;
      while(l<r){
        if(v[l]+v[r]>v[i]){
           sol+=r-l;
            r--;
            
        }
        else{
            l++;
        }
      }



   }
   return sol;



}
int threesum(vector<int> nums,int sum){
  
   if(nums.size()<3){
    if(accumulate(nums.begin(),nums.end(),0)==0){
        return 1;
    }
    else{
        return 0;
    }
   }
   int ans=0;
   for(int i=2;i<nums.size();i++){
    int l=0,r=i-1;
    int ele=sum-nums[i];
    while(l<r){
        if(nums[l]+nums[r]==ele){
            ans++;
            l++;
            
        }
        if(nums[l]+nums[r]>ele){
            r--;
        }
        if(nums[l]+nums[r]<ele){
            l++;
        }

    }

   
   }  




   return ans;


}

int threesumclosest(vector<int> nums,int sum){

   sort(nums.begin(),nums.end());
   int ans=INT_MAX;
   for(int i=0;i<nums.size()-2;i++){
    int ele=abs(sum-nums[i]);
    int l=i+1,r=nums.size()-1;
    while(l<r){

        if(nums[l]+nums[r]<=ele){
            ans=min(ans,ele-(nums[l]+nums[r]));
            l++;
        }
        if(nums[l]+nums[r]>ele){
            ans=min(ans,(nums[l]+nums[r])-ele);
            r--;
        }

    }


   }
   return ans;

}


int trap(vector<int> nums){
   stack<pair<int,int>> st;

   int ans=0;
   for(int i=0;i<nums.size();i++){
     
     while(!st.empty() and st.top().first<nums[i]){
      pair<int,int> c=st.top();
      st.pop();
      if(st.empty()) break;   
      else{
        pair<int,int> l=st.top();
        
        ans+=(i-l.second-1)*(min(nums[i],l.first)-c.first);
cout<<i<<" "<<l.first<<" "<<l.second<<" "<<nums[i]<<" "<<c.first<<" "<<c.second<<" "<<ans<<endl;
      } 
     }

     if(st.empty()||st.top().first>nums[i]){
         st.push({nums[i],i});
     }

// 5,4,3,2,7

   }


return ans;



}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> ans;
    vector<vector<int>> test;
    if(nums.size()==3) {


            if(accumulate(nums.begin(),nums.end(),0)==0){
                 res.push_back(nums);
                 return res;
            }
        }

        else{
                  int sum=0;
       
       sort(nums.begin(),nums.end());
       
        
   for(int i=0;i<nums.size()-2;i++){
           int ele=sum-nums[i];
    int l=i+1,r=nums.size()-1;
    while(l<r){
        if(nums[l]+nums[r]==ele){
            vector<int> sam;
            sam.push_back(nums[i]);
            sam.push_back(nums[l]);
            sam.push_back(nums[r]);
            sort(sam.begin(),sam.end());
            ans.insert(sam);
            test.push_back({nums[i],nums[l],nums[r]});
            while(nums[l]==nums[l+1] and l<r) l++;
            
             r--;
        }

       else if(nums[l]+nums[r]<ele){
             l++;
        }
       else if(nums[l]+nums[r]>ele){
          
            r--;
        }

    }


   }
        }

   
   for(auto i:ans){
    res.push_back(i);
   }
   return test;;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int n= nums.size();
       if(n<3)
       return {};
       if(nums[0]>0)
       return {};
       vector<vector<int>> ans;
       for(int i=0;i<n;i++){
           if(nums[i]>0)
           break;
           if(i>0 && nums[i]==nums[i-1])
           continue;
           int l = i+1, h = n-1, sum=0;
           while(l<h){
               sum = nums[i]+ nums[l]+ nums[h];
               if(sum>0)
               h--;
               else if(sum<0)
               l++;
               else{
                   ans.push_back({nums[i],nums[l], nums[h]});
                   int lo= nums[l], ho = nums[h];
                   while(l<h && lo==nums[l])
                   l++;
                   while(l<h && ho==nums[h])
                   h--;
               }
           }
       }
       return ans;
    }

// string minwindow(string s,string t){
//     map<char,int> smap,tmap;
//     for(auto i:t){
//         tmap[i]++;
//     }
//     int idx,mn=INT_MAX;
//     int j=0;
//     int i=0;
//     int matches=0;
//     while(i<s.length()){
//         smap[s[i]]++;
//         if(smap[s[i]]==tmap[s[i]]){
//             matches++;
//         }
        
          
//         while(matches==tmap.size()){
//           mn=min(mn,i-j+1);
//           idx=i;

//             smap[s[j]]--;
//             j++;
//             if(smap[s[j]]!=0 and smap[s[j]]==tmap[s[j]]){
//                 matches--;
//             }
//         }
        

        
        

//         i++;
//     }


// }

int longestsubstring(string s){
  int flag=1;
 
  
  int j=0,i=0;
  while(i<s.length()){
    map<char,int> np;
    int j=i;
    while(j<s.length()){
        np[s[j]]=j;
        if(np.find(s[j])==np.end()||j==s.length()-1){
            cout<<np[s[j]]<<" "<<i<<" "<<j<<" "<<flag<<" "<<s[j]<<endl;
            if(np.find(s[j])!=np.end() and j==s.length()-1){
              flag=max(j-i+1,flag);
            }
            else{
               flag=max(j-i,flag); 
            }
            i=j-1;
            break;
        }
        
      j++;
    }
     if(j==s.length()-1){
        break;
     }

       

  }




return flag;


}

int longestsub(string s){

   int flag=1;


map<char,int> np;

int j=0;
for(int i=0;i<s.length();i++){
    np[s[i]]++;
    if(np[s[i]]==2 || i==s.length()-1){
        cout<<np[s[i]]<<" "<<i<<" "<<j<<" "<<flag<<" "<<s[i]<<endl;
         if(np[s[i]]==1 and i==s.length()-1){
              flag=max(i-j+1,flag);
            }
            else{
               flag=max(i-j,flag); 
            }


            while(s[j]!=s[i]) {
            
            np[s[j]]--;
            j++;}
            j++;
    np[s[i]]--;
    }
    
   
}

 return flag;
}

 int lengthOfLongestSubstr(string s) {
        int start = 0;
        int end = 0;
        int res = 0;
        map<char,int> m;
        for(char c: s) {
            if(m.find(c) != m.end() && start <= m[c])
            {
                start = m[c]+1;
            }
            m[c] = end++;
            res = res > (end - start) ? res : (end - start);
        }
        
        return res;
    }



int threesumclosest2(vector<int> nums,int target){
  
int mn=INT_MAX;
int ans=-1;


for(int i=0;i<nums.size()-2;i++){

    int j=i+1,k=nums.size()-1;
    while(j<k){

        int sum=nums[i]+nums[j]+nums[k];
         if(target<sum){
            int diff=abs(target-sum);
            cout<<diff<<" "<<target<<" "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<i<<" "<<j<<" "<<k<<endl;
            if(diff<=mn){
                ans=sum;
                mn=diff;
            }
            j++;
        }
       else if(target>sum){
        int diff=abs(target-sum);
         cout<<diff<<" "<<target<<" "<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<i<<" "<<j<<" "<<k<<endl;
            if(diff<=mn){
                ans=sum;
                mn=diff;
            }
            k--;
        }

        else if(target==sum){
            return target;
        }
        


    }
    

}
return ans;


}




int main() {  
    
  
// vector<int> vect={12,14,21,23,26,29,31,31,31,31,35,35,35,36,39,39,39,39,41,43,44};
vector<int> vect={1,3,5,7,10,11,16,20,23,30,34,60},v={0,1,0,2,1,0,1,3,2,1,2,1},h={8,0,5,0,15,2,0,16},r={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},d={2,3,5,2,3,4,4,1,3,5,2,2,5,1,1,2,5},k={1,500,2,3,4};
vector<vector<int>>  matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
// int p=9;
vector<int> gas={1,2,3,4,5},cost={-2,1,-1,-2,-2};
vector<vector<int>> intervals={{{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0}}};
// sort(intervals.begin(),intervals.end());
// for(auto i:intervals){
//   cout<<i[0]<<" "<<i[1]<<endl;
// }
string s="0P";
int c=0;

 vector<int> pr={10,20,30,40,50},diff={2,4,6,8,10},worker={4,5,6,7};
// cout<<r.size();
// sortColors(h);

// path(intervals,0,0,c,s,str);
// cout<<c<<endl;
// for(auto i:str){
//   cout<<i<<" ";
// }
// int lad=2,brick=10;
// int p=INT_MIN;
// solve(0,lad,brick,h,p);
// cout<<p;
// cout<<nextGreaterElement(2147483486);
// cout<<stoi("4322147483486");
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
// cout<<ptr[i][j]<<" ";
//     }
//     cout<<"\n";
// }
string text="tmmzuxt";
vector<int> books={4,0,5,-5,3,3,0,-4,-5};
vector<int> stalls={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
cout<<threesumclosest2(books,1,-2);
// cout<<trap({5,4,3,2,7});
// for(auto i:threeSum(stalls)){
//     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
// }
// nextPermutation(v);
// cout<<minSubarray(vect,p);

  return 0;
}