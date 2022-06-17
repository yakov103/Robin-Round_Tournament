#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std ;

int main () {

    vector <int > vec = {1,2,3,4,5,6};
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
