//
//  main.cpp
//  chapter10
//
//  Created by 张蓉蓉 on 2018/11/16.
//  Copyright © 2018 gaoss. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
void ch11_1()
{
    vector<int> ivector;
    cout<<ivector.capacity()<<endl;
    for(size_t i=1;i<100;++i)
    {
        ivector.push_back(3);
        cout<<ivector.capacity()<<endl;
    }
}
int main(int argc, const char * argv[]) {

    return 0;
}
