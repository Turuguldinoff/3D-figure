#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<double> norm(vector<double> r)
{
    double length;
    length = sqrt(r[0]*r[0] + r[1]*r[1] + r[2]*r[2]);
    r[0] = r[0] /length;
    r[1] = r[1] /length;
    r[2] = r[2] /length;
    return r;
};

class Geom
{
private: 
    int f;
    double r, x, y,z;
    double e = 0.01;

public:
    Geom(int a = 3){    
        f = a;
    }

    double GetValue(vector<double> re)
    {
        switch (f)
        {
            case 0:
                cout << "r:";
                cin >> r;
                if (re[0]*re[0] + re[1]*re[1] + re[2]*re[2] < r)
                    cout << "Vnytri";
                else if (re[0]*re[0] + re[1]*re[1] + re[2]*re[2] > r)
                    cout << "Snaryji";
                else
                    cout << "Rovno";
                break;
            case 1:
                if (re[0]*re[0] + re[1]*re[1] - re[2]*re[2] < 0)
                    cout << "Vnytri";
                else if (re[0]*re[0] + re[1]*re[1] - re[2]*re[2] > 0)
                    cout << "Snaryji";
                else
                    cout << "Rovno";
                break;
            case 2:
                cout << "r:";
                cin >> r;
                cout << "y:";
                cin >> y;
                if ((re[0]*re[0] + re[2]*re[2] < r) && (re[1] < y || re[1] > 0))
                    cout << "Vnytri";
                else if ((re[0]*re[0] + re[2]*re[2] == r) && (re[1] == y || re[1] == 0))
                    cout << "Rovno";
                else
                    cout << "Snaryji";
                break;
            case 3:
                cout << "x:";
                cin >> x;
                cout << "y:";
                cin >> y;
                cout << "z:";
                cin >> z;
                if (re[0] < x && re[1] < y && re[2] < z)
                    cout << "Vnytri";
                else if (re[0] == x && re[1] == y && re[2] == z)
                    cout << "Rovno";
                else
                    cout << "Snaryji";
                break;
            default:
                cout << "err" << endl;
                break;
        }
                
    }
};

int main()
{
    int f;
    vector<double> v = {0,0,0};
    cout << "Vibor figur: ";
    cin >> f;
    cout << "Point: ";
    cin >> v[0] >> v[1] >> v[2];

    Geom a = Geom(f);
    a.GetValue(v);

    // Geom dist;
    // dist = Geom.GetValue(1, 1, 1);
    return 0;
}
