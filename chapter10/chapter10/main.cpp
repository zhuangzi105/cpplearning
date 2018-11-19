//
//  main.cpp
//  chapter10
//
//  Created by 张蓉蓉 on 2018/11/16.
//  Copyright © 2018 gaoss. All rights reserved.
//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;
void ch10_3()
{
    vector<int> ivector;
    cout<<ivector.capacity()<<endl;
    for(size_t i=1;i<100;++i)
    {
        ivector.push_back(3);
        cout<<ivector.capacity()<<endl;
    }
}



struct ge{
    int i=0;
    int operator() ()
    {
        return ++i;
    };
};

template<typename container>
void ch10_5(int n,int m)
{
    container c;
   c.resize(n);

    ge g;
    g.i=0;
    generate(c.begin(),c.end(),ge());
    auto it=c.begin();
  
    while(c.size()>=2 )
    {
//       auto j=distance(it,c.end());//list advance 代价极高，这一行败笔
//        if(j>=m)
//        {
//             advance(it, m-1);
//        }
//        else{
//            it=c.begin();
//            advance(it,(m-1-j)%c.size());
//        }
        int countm=0;
        do{
            ++it;
            if(it==c.end())
            {
                it=c.begin();
            }
            ++countm;
        }while(countm<m-1);
        
       it=c.erase(it);
        if(it==c.end())
        {
            it=c.begin();
        }
    }
    copy(c.begin(), c.end(),ostream_iterator<int>(cout," "));
}

template<typename container>
void ch10_5noerase(int n,int m)
{
    container c;
    c.resize(n);
    ge g;
    g.i=0;
    generate(c.begin(),c.end(),ge());
    auto it=--c.end();
    int i=0;
    int countm=0;
    while(i<n-1)
    {
        countm=0;
        while(countm<m)
        {
           
            ++it;
            if(it==c.end())
            {
                it=c.begin();
            }
            if(*it!=-1)
            {
                ++countm;
            }
        }
        *it=-1;
        ++i;
    }
    c.erase(remove(c.begin(),c.end(),-1),c.end());
    copy(c.begin(), c.end(),ostream_iterator<int>(cout," "));
}
void ch10_5demo()
{
    int n=2000000,m=10;
    //vector
    time_t begin=time(0);
    ch10_5noerase<vector<int>>(n,m);
    time_t end1=time(0);
    cout<<"vector time: "<< end1-begin<<endl;
    //deque
    ch10_5noerase<deque<int>>(n,m);
    time_t end2=time(0);
    cout<<"deque time: "<< end2-end1<<endl;
    
    //list
    ch10_5<list<int>>(n,m);
    time_t end3=time(0);
    cout<<"list time: "<< end3-end2<<endl;
}

template<class T>
void exchange(list<T>& l1, typename list<T>::iterator p1,
              list<T>& l2, typename list<T>::iterator p2)
{
    l1.splice(p1,l2,p2,l2.end());
    l2.splice(l2.end(),l1,p1,l1.end());
//    l1.insert(p1,p2,l2.end());
//    l2.insert(p2,p1,l1.end());
//    l1.erase(p1,l1.end());
//    l2.erase(p2,l2.end());
}

void ch10_6demo()
{
    list<int> l1({1,2,3,4});
     list<int> l2({11,12,13,14});
    exchange(l1,++++l1.begin(),l2,++++l2.begin());
    copy(l1.begin(),l1.end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(l2.begin(),l2.end(),ostream_iterator<int>(cout, " "));
    cout<<endl;
}

#include <stack>
#include <queue>
#include <set>
#include <map>
template<class T>
void ch10_7()
{
    T c;
    cout<<typeid(T).name()<<" ";
    c.push(5);
    c.push(1);
    c.push(4);
    c.push(6);
    cout<<c.top()<<" ";
    c.pop();
    cout<<c.top()<<" ";
    c.pop();
    c.push(2);
    c.push(3);
    cout<<c.top()<<" ";
    c.pop();
    cout<<c.top()<<" ";
    c.pop();
    cout<<endl;
}
void ch10_7demo()
{
    ch10_7<stack<int>>();
    //ch10_7<queue<int>>();
   ch10_7<priority_queue<int,vector<int>,less<int> >>();
}

void ch10_8demo(){
    multiset<char> chars;
    map<char,int> charmap;
    char c;
    while(cin.get(c))
    {
      
      
        size_t count=chars.count(c);
        if(count==0)
            cout<<"not found ";
        else
            cout<<"count: "<<count<<" ";
        cout<<endl;
        chars.insert(c);
        
        int d=++charmap[c];
        if(d==1)
            cout<<"not found ";
        else
            cout<<"count: "<<d-1<<" ";
        cout<<endl;
        
        
    }
    
}

void ch10_9demo()
{
    int array1[]={1,2,3,4,5,6,7,8};
    //vector<int> v1(array1,array1+sizeof(array1)/sizeof(int));
    swap(array1[2],array1[4]);
    iter_swap(array1+2,array1+4);
    swap_ranges(array1, array1+3, array1+1);
  //  rotate(array1,array1+3,array1+6);
    copy(array1,array1+8,ostream_iterator<int>(cout));
    
}
void ch10_10demo()
{
    int array1[]={1,2,3,4,5,6,7,8,11,12};
    int array2[]={11,12,13,14,15,16,17,18,5,6,7};
    set<int> s1(array1,array1+sizeof(array1)/sizeof(int));
    set<int> s2(array2,array2+sizeof(array2)/sizeof(int));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout," "));
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout," "));
     set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), ostream_iterator<int>(cout," "));
}
void ch10_11demo()
{
    int arr[]={1,1,4,4,5};
    vector<int> s(arr,arr+sizeof(arr)/sizeof(int));
    s.erase(unique(s.begin(), s.end()),s.end());
    copy(s.begin(), s.end(), ostream_iterator<int>(cout," "));
    
    list<int> l(arr,arr+sizeof(arr)/sizeof(int));
    

}

#include <random>
    int gerandom()
    {
        static default_random_engine e;
        static uniform_int_distribution<int> u(0,9);
        return u(e);
    }

int power(int x,int y)
{
    int result=1;
    while(y-- >0) result*=x;
    return result;
}

void ch10_12demo()
{
    vector<int> v(100);
    generate(v.begin(),v.end(),gerandom);
    //sort(v.begin(),v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
    cout<<endl;
    transform(v.begin(), v.end(), ostream_iterator<int>(cout," "), bind1st(ptr_fun(power),5));
     cout<<endl;
    transform(v.begin(), v.end(), ostream_iterator<int>(cout," "), bind2nd(ptr_fun(power),7));
     cout<<endl;
    transform(v.begin(),v.end(),v.begin(),ostream_iterator<int>(cout," "),power);

}
int main(int argc, const char * argv[]) {
    //ch10_5demo();
    //ch10_6demo();
   // ch10_7demo();
    //ch10_8demo();
      //ch10_9demo();
    //ch10_10demo();
    //ch10_11demo();
    ch10_12demo();
    return 0;
}
