#include <iostream>
#include <vector>
using namespace std;

vector<double> find_min_max(const vector<double> & oldv);
vector<double> find_min_max(const vector<double> & oldv, int vsize);

int main() {
    // create vector1 to search for min and max
    vector<double> v = { 1.25, 3, 59602, 0, 1, 36, -954, 7 };

    // vector2 = vector returned from function
    vector<double> v_result = find_min_max(v);

    // print results in vector2
    cout << "Min: " << v_result[0] << "\tMax: " << v_result[1] << endl;
    return 0;
}

// driver
vector<double> find_min_max(const vector<double> & oldv) {
    int vsize = oldv.size();                            // find size of v
    vector<double> newv = find_min_max(oldv, vsize);    // call new recursive function
    return newv;
}

// recursive function
vector<double> find_min_max(const vector<double> & oldv, int vsize) {

    vector<double> v (2);

    // base case :      if vsize = 1
    //                  return element as min AND max
    if(vsize == 1) {
        v[0] = oldv[0];
        v[1] = oldv[0];
        return v;
    }

    // recursive case : 
    else {
        vector<double> v2 (2);
        int newsize1 = vsize / 2;
        int newsize2 = vsize / 2;
        
        vector<double> temp_v1 (newsize1);              // 2 new vectors based on vsize
        vector<double> temp_v2;

        if(vsize % 2 == 0)                              // define newsize2       
            temp_v2.resize(newsize2);
        else {
            newsize2++;
            temp_v2.resize(newsize2);
        }

        for (int i = 0; i < newsize1; i++)              // copy elements to respective vectors
            temp_v1[i] = oldv[i];
        for (int i = newsize1; i < vsize; i++) 
            temp_v2[i - newsize1] = oldv[i];
        
        v = find_min_max(temp_v1, newsize1);            // recursive calls
        v2 = find_min_max(temp_v2, newsize2);

        
        if(v[0] > v2[0])                                // compare max and min in vector3 and 4
            v[0] = v2[0];
        if(v[1] < v2[1])
            v[1] = v2[1];

        return v;
    }
    return v;
}