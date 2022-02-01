//
//  main.cpp
//  String
//
//  Created by puneet on 07/11/21.
//

#include "String.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    String<char> str{};
    std::cout << str.data() << "\n";
    
    str = "asfd";
    std::cout << str.data() << "\n";
    
    str = "as";
    std::cout << str.data() << "\n";
    
    String<char> str2("aslfowuerj");
    std::cout << str2.data() << "\n";
    
    str = str2;
    std::cout << str2.data() << "\n";
    std::cout << str.data() << "\n";
    
    String<char> str3(std::move(str2));
    std::cout << str3.data() << "\n";
    
    String<char> str4;
    str4 = std::move(str3);
    std::cout << str4.data() << "\n";
    
    return 0;
}
