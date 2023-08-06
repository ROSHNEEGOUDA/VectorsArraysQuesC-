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


//Given Q queries, check if given number is present in array or not

