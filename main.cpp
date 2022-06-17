#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std ;

int main () {

    vector <int > vec;
    vec.resize(20);// enter number of team here
    int counter = 0 ;
    auto func = [&](int & a){a= counter; counter++ ;};

    for_each(vec.begin(),vec.end(),func);

//    auto func2= [](const auto & a , const auto &b  ){ return a > b;};
//    sort(vec.begin(),vec.end(),func2);


    vector <string > withWho;
    withWho.resize(vec.size()/2);
    int temp;
    cout << "round 1"<< endl ;
    for ( int i = 0 ; i < vec.size()/2 ; i++) {
        withWho.at(i)+=to_string(vec.at(i))+" ";
    }
    for ( int i = vec.size()/2-1; i >= 0; i-- ) {
        temp= i + vec.size()/2;
        withWho.at(vec.size()/2-i-1)+=to_string(vec.at(temp));
    }

    for (int i = 0 ; i < withWho.size() ;i++){
        cout << withWho.at(i) << endl ;
        withWho.at(i)= " ";
    }

    cout << endl ;
    for ( int k = 0; k <vec.size() -2 ; k++ ) {
        cout << "round " << k+2 << endl;
        rotate(vec.begin() + 1, vec.end() - 1, vec.end());// איפה תתה רוצה לסיים

        for (int i = 0; i < vec.size() / 2; i++) {
            withWho.at(i) += to_string(vec.at(i)) + " ";
        }
        for (int i = vec.size() / 2 - 1; i >= 0; i--) {
            temp = i + vec.size() / 2;
            withWho.at(vec.size() / 2 - i - 1) += to_string(vec.at(temp));
        }

        for (int i = 0; i < withWho.size(); i++) {
            cout << withWho.at(i) << endl;
            withWho.at(i)= " ";
        }
    }


    return 0;
}
