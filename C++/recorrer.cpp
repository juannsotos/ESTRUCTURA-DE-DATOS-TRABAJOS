#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> a  = {10,20,30,40,60};
    for (size_t i = 0; i < a.size() ; i++){

    cout << i << " " << a[i] << "\n";
}

return 0;
}

