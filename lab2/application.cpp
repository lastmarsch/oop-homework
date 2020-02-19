#include "application.h"
#include "iostream"

using namespace std;

void Application::menu()
{
    cout << "\tMENU:\n";
    cout << "1. Polynom coefficients\n";
    cout << "2. Roots\n";
    cout << "3. Print polynom\n";
    cout << "0. Exit\n";
}

Application::Application()
{

}

int Application::exec()
{
    int ch;
    Polynom p;
    number a, b, c;

    while (true) {
        menu();
        cin >> ch;
        if (ch == 0)
            break;
        switch(ch) {
        case 1:
            // забивают коэффициенты
            cout << "a = ";
            cin >> a;
            while (a == 0) {
                cout << "First coefficient cannot be NULL\na = ";
                cin >> a;
            }
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            p = Polynom(a, b, c);
            break;
        case 2: {
            // вычислить корни
            if (!p.check()) {
                cout << "First, enter coefficients.\n";
                break;
            }
            number x[2];
            int res = p.roots(x);
            if (res == 2)
                cout << "X1 = " << x[0] <<"\nX2 = " << x[1] << endl;
            if (res == 1)
                cout << "X1,X2 = " << x[0] << endl;
            if (res == 0)
                cout << "This equation has no roots.\n";
        }
            break;
        case 3:
            cout << "p(x) = " << p;
            break;
        default:
            break;
        }
    }
    return 0;
}
