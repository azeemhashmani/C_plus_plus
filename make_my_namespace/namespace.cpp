#include <iostream>
using namespace std;

namespace apples{
     string color = "red";
     int isFruit = true;
}

namespace potatoes{
    string color = "yellow";
    int isFruit = false;
}

namespace tomatoes{
    string color = "red";
    int isFruit = true;
}

int main()
{

    cout << "Apples are " << apples::color << " in color. Is it a fruit ?" << endl;
    cout << apples::isFruit << endl;

    cout << "Potatoes are " << potatoes::color << " in color. Is it a fruit ?" << endl;
    cout << potatoes::isFruit << endl;

    cout << "Tomatoes are " << tomatoes::color << " in color. Is it a fruit ?" << endl;
    cout << tomatoes::isFruit << endl;

    return 0;
}
