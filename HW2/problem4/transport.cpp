//
//  transport.cpp
//  
//
//  Created by I-Hong Hou on 10/2/17.
//

#include "transport.hpp"

int transport(){
    cout << "Which protocol do you want to use? Enter 1 for TCP. Enter 2 for UDP" << endl;
    int ans;
    while(1){
        cin >> ans;
        if(ans == 1){
            TCP();
            break;
        }else if(ans == 2){
            UDP();
            break;
        }else
            cout << "Invalid input" << endl;
            
    }
    return 1;
}
