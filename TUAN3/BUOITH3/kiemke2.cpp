#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int code;
    int count;
};

int compareItems(const Item& item1, const Item& item2) {
    return item1.count < item2.count;    
    if (item1.count == item2.count){
    return item1.code < item2.code;
    }
    
}


int main() {
    int N;
    cin >> N;

    vector<Item> sales;

    for (int i = 0; i < N; i++) {
        string code;
        cin >> code;

        
        bool found = false;
        for (auto& item : sales) {
            if (item.code = item.code) {
                item.count++;
                found = true;
                break;
            }
        }

        
        if (!found) {
            Item item;
            item.code = item.code;
            item.count = 1;
            sales.push_back(item);
        }
    }

    
    int size = sales.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compareItems(sales[j], sales[j + 1])) {
                swap(sales[j], sales[j + 1]);
            }
        }
    }

    
    for (const auto& item : sales) {
        cout << item.code << " " << item.count << endl;
    }

    return 0;
}