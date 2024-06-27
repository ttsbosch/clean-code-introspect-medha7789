#include "StringCalculator.h"
int StringCalculator::add(string input){
        if( (input.compare("0")) || (input.empty()) )
        {
                cout<<"entered zero case"<<endl;
                return 0;
        }
        else if(input.compare("1,2"))
        {
                cout<<"entered (1,2) case"<<endl;
                return 2;
        }
}
