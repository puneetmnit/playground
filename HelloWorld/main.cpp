//
//  main.cpp
//  HelloWorld
//
//  Created by puneet on 23/05/16.
//  Copyright © 2016 puneet. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

int main(int argc, const char * argv[]) {
    // insert code here...
    auto f = [](auto&& y){std::cout << "Hello " << y << "!\n";};
    f("asdf");
    
    //std::cout << "Hello, World!\n";
    return 0;
}
