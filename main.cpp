//
// Created by Vova on 11/10/21.
//

#include <iostream>
#include <cstdlib>
#include "goverser.h"

using namespace std;

bool preFunc() {
    return Header();
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
    for(int i =0; i<10; i++){
        displayFunc(rand()%100 + 1, rand()%2 == 0);
    }
    postFunc();

    return 0;
}