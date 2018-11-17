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
void ch11_3()
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
void ch11_5(int n,int m)
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
void ch11_5noerase(int n,int m)
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
int main(int argc, const char * argv[]) {
    int n=2000000,m=10;
    //vector
    time_t begin=time(0);
    ch11_5noerase<vector<int>>(n,m);
    time_t end1=time(0);
    cout<<"vector time: "<< end1-begin<<endl;
    //deque
    ch11_5noerase<deque<int>>(n,m);
    time_t end2=time(0);
    cout<<"deque time: "<< end2-end1<<endl;
    
    //list
    ch11_5<list<int>>(n,m);
    time_t end3=time(0);
    cout<<"list time: "<< end3-end2<<endl;
    return 0;
}
