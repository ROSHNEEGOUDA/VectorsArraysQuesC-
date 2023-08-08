//Find total number of pairs in array whose sum is equal to given value x
#include<iostream>
using namespace std;
int main()
{
    int array[]={3,4,6,7,1}; // 3+4=7 6+1=7
    int trgtsum=5;
    int sz=5;
    int pairs=0;
    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz;j++)
        {
            if(array[i]+array[j]==trgtsum)
            {
                pairs++;
            }
        }
    }
    cout<<pairs<<endl;
    return 0;
}


//number of triplets whose sum is equal to given value x
// so, like the above ques but with 3 loops 
#include<iostream>
using namespace std;
int main()
{
    int array[]={3,1,2,4,0,6};
    int trgtsm=5;
    int siz=6;
    int triplet=0;
    for(int i=0;i<siz;i++)
    {
        for(int j=i+1;j<siz;j++)
        {
            for(int k=j+1;k<siz;k++)
            {
                if(array[i]+array[j]+array[k]==trgtsm)
                {
                    triplet++;
                }
            }
        }
    }
    cout<<triplet<<endl;
    return 0;
}


//Find unique number in a given array where all elements are being repeated twice with one value being unique
#include<iostream>
using namespace std;
int main()
{
    int array[]={2,3,1,3,2,4,1};
    int size=7;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(array[i]==array[j])
            {
                array[i]=array[j]=-1;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        if(array[i]>0)
        {
            cout<<array[i]<<endl;
        }
    }
    return 0;
}


//Finding the second largest element in a given array
#include<iostream>
using namespace std;
int largest_ele_index(int array[],int sizee)
{
    int max=INT_MIN; //INT_MIN is a constant variable given so that we can compare with other integers in C++
    int maxindx=-1;
    for(int i=0;i<sizee;i++)
    {
        if(array[i]>max)
        {
            max=array[i];
            maxindx=i;
        }
    }
    return maxindx;
}
int main()
{
    int array[]={1,2,3,5,7,6,1};
    int indxoflargst=largest_ele_index(array,6);
    array[indxoflargst]=-1;
    int indxofseclargest=largest_ele_index(array,6);
    cout<<array[indxofseclargest]<<endl;
    return 0;
}


//Rotate the given array'a' by k steps, where k is non-negative.(k can be greater than the size of array also)
//[1,2,3,4,5] let k=2
//step1 5,1,2,3,4
//step2 4,5,1,2,3
//we can consider n-k and k steps
#include<iostream>
using namespace std;
int main()
{
    int array[]={1,2,3,4,5};
    int n=5;
    int k=2;
    k=k%n;
    int ansarray[5];
    int j=0;
    for(int i=n-k;i<n;i++)
    {
        ansarray[j++]=array[i];
    }
    for(int i=0;i<=k;i++)
    {
        ansarray[j++]=array[i];

    }
    for(int i=0;i<n;i++)
    {
        cout<<ansarray[i]<<" ";
    }
    cout<<endl;
}
//output is 4 5 1 2 3


//The above ques can be solved by vectors having a built in function for reverse
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int k=2;
    k=k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.end()+k);
    reverse(v.begin()+k,v.end());
    for(int a:v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
}


//Given an array of integers of size n. Answer q queries where you need to print sum of values in a given range of indices from l to r(both will be included)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        v[i+=v[i-1]];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        ans=v[r]-v[l-1];
        cout<<ans<<endl;
    }
    return 0;
}


//Check if we can partition the array into two subarrays with equal sum. ie; prefix sum of a part of the array is equal to the suffix sum of rest of the array
//5
//6 2 4 3 1
//tot=16
prefix=6+2=8
//sum sum=8
#include<iostream>
#include<vector>
using namespace std;
bool  checkprefx(vector<int> &v)
{
    int tot=0;
    for(int i=0;i<v.size();i++)
    {
        tot=tot+v[i];
    }
    int prefix=0;
    for(int i=0;i<v.size();i++)
    {
        prefix+=v[i];
        int suffix=tot-prefix;
        if(suffix==prefix)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    cout<<checkprefx(v)<<endl;
}


//Given an integers array 'a' return the prefix sum/running sum in array without creating a new array
//[ 5, 4, 1, 2, 3]
// 5, 9, 10, 12, 15
#include<iostream>
#include<vector>
using namespace std;
void runningsum(vector<int> &v)
{
    for(int i=1;i<v.size();i++)
    {
        v[i]+=v[i-1];
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    runningsum(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


//Given 2 arrays of size m and n sorted in increasing order. Merge them into a single sorted array of size m+n
#include<iostream>
using namespace std;
int main()
{
    int ar1[]={1,6,7,10};
    int ar2=[]={0,1,3,8,11,12,15,18}
    int n=4;
    int m=8;
    int res[m+n];
    int i=0;
    int j=0;
    int k=0;
    while(i<m and j<n) 
    {//both i & j within limits
        if(ar1[i]<ar2[j])
    {
        res[k]=ar1[i];
        k++;
        i++;
    }
    else{
        res[k]=ar2[j];
        k++;
        j++;
    }
    }
while(i<m)
{//ar1 is exhausted & we have ele left
    res[k]=ar1[i];
    i++;
    k++;
}
while(j<n)
{
    //ar2 is exhausted & we have some ele left
    res[k]=ar2[j];
    k++;
    j++;
}
for(int i=0;i<(m+n);i++)
{
    cout<<res[i]<<" ";
}
    return 0;
}


//Given Q queries, check if given number is present in array or not

