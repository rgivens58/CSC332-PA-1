#include <iostream>
#include <tuple>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

int timeBrute(int i, int j) {
    int k = 0;
    for (int l = 1; (long long)l * l <= j; l++)
    {
        if (j % l == 0)
        {
            if (i % l == 0)
            {
                k = max(k, i);
            }
            if (i % (j / l) == 0)
            {
                k = max(k, j/l);
            }
        }
    }
    return k;
}

int main() {
    typedef vector<tuple<int, int>> mytuple;
    srand(time(0));
    mytuple tup[100];
    vector<int> gcds[100];
    vector<float> times[100];
    int a, b;

    for (int i =0; i < 101; ++i) {
        int rand1 = rand();
        int rand2 = rand();
        tup->push_back(tuple<int, int>(rand1, rand2));
    }
    for (mytuple::const_iterator i = tup->begin(); i != tup->end(); ++i ) {
        chrono::high_resolution_clock::time_point startTime = chrono::high_resolution_clock::now();
        a = get<0>(*i);
        b = get<1>(*i);
        if (a > b) {
            gcds->push_back(timeBrute(a, b));
        } else {
            gcds->push_back(timeBrute(b, a));
        }
        cout << startTime << endl;
        cout << time(0) << endl;
        times->push_back(time(0) - startTime);
    }
    /*for (int e = 0; e < 101; ++e) {
        cout << times->at(e) << endl;
        cout << gcds->at(e) << endl;
        cout << endl;
    }*/
}

