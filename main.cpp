//
// Created by Vova on 11/10/21.
//

#include <iostream>
#include <cstdlib>
#include "goverser.h"


using namespace std;

bool preFunc() {
    MyCClass cclass = * new MyCClass;
    MyNewClass myclass = * new MyNewClass;
    myclass.bar = 11;
    myclass.foo = 14;
    myclass.c = cclass;
    Header(&myclass);
    cout << myclass.c.kk;
    return true;
}

bool postFunc(){
    return Footer();
}

bool displayFunc(int spent, bool err) {
    return Display(spent, err);
}

bool filter() {
    return Filter();
}


int main() {
    preFunc();
    displayFunc(10, false);
    postFunc();

    return 0;
}