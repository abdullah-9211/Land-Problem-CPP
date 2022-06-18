#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

int max_revenue(unordered_map<int, long> prices, long total_area)
{
    if (total_area <= 0)
        return 0;
    double revenue = -numeric_limits<double>::infinity();
    for (unordered_map<int, long>::iterator i = prices.begin(); i->first <= total_area; i++)
    {
        revenue = max<long>(revenue, i->second + max_revenue(prices, total_area - i->first));
    }

    return revenue;
}

int main()
{
    int width, length;
    long total_area = 0;
    unordered_map<int, long> prices_of_size;
    
    while (total_area < 100 || total_area % 100 != 0)
    {
        cout << "\t\t======================================LAND SIZE ENTRY============================================\n\n";

        cout << "Please enter width of land: ";
        cin >> width;
        cout << endl;

        while (width <= 0 || width % 5 != 0)
        {
            cout << "Invalid input!\nPlease enter positive value which is multiple of 5: ";
            cin >> width;
            cout << endl;
        }

        cout << "Please enter length of land: ";
        cin >> length;
        cout << endl;

        while (length <= 0 || length % 5 != 0)
        {
            cout << "Invalid Input!\nPlease enter positive value which is multiple of 5: ";
            cin >> length;
            cout << endl;
        }


        total_area = width * length;

        cout << "Total Area is: " << total_area << " sq. units" << endl << endl;

        if (total_area < 100 || total_area % 100 != 0)
        {
            cout << "Invalid Land value\nIt should be greater than 100 and a multiple of 100. Please enter values again";
            cout << endl << endl;
        }
    }

    cout << "\t\t======================================PRICES ENTRY============================================\n\n";

    for (int i = 100; i <= total_area + 100; i += 100)
    {
        cout << "Please enter price for chunk of land with size " << i << " sq. units: ";
        cin >> prices_of_size[i];
        cout << endl;
    }

    cout << "Max revenue that can be generated is: " << max_revenue(prices_of_size, total_area) << endl;


    cin.get();
    return 0;
}

