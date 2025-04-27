//E - Commerce Inventory.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class Product {
    int ProductID;
    string Name;
    double Price;

public:

    Product(int ID, string Naam, double Money) {
        ProductID = ID;
        Name = Naam;
        Price = Money;
    }

    int Get_ProductID() {
        return ProductID;
    }

    void Display_Product() {
        cout << "Product ID: " << ProductID << " \t | Name: " << Name << " \t | Price: " << Price << endl;
    }

    string Get_Name() {
        return Name;
    }

    double Get_Price() {
        return Price;
    }

};

class InventorySystem {
public:
    vector<Product> products;

    InventorySystem() {
        products.push_back(Product(101, "ToothPaste\t", 110));
        products.push_back(Product(102, "Potato Chips\t", 50));
        products.push_back(Product(103, "Bread\t\t", 150));
        products.push_back(Product(104, "Tea\t\t", 120));
        products.push_back(Product(105, "Cheese\t\t", 200));
        products.push_back(Product(106, "Samsung Phone\t", 35000));
        products.push_back(Product(107, "Laptop\t\t", 60000));
        products.push_back(Product(108, "LCD Television\t", 45000));
        products.push_back(Product(109, "HeadPhone\t", 1000));
        products.push_back(Product(110, "Novel\t\t", 6000));
    }

    void Display_Products() {
        for (int i = 0; i < products.size(); i++) {
            products[i].Display_Product();
        }
    }
};

class User : public InventorySystem {
private:
    int count;
    vector<Product> user;
    vector<int> quantities;
    int ID;
    string n;
    int quantity;

public:

    User() {
        count = 0;
    }

    void Add_Product() {
        cout << "Enter Product ID To Buy It:" << endl;
        cout << "Enter 0 To Exit." << endl;

        do {
            cout << "Enter Product ID: ";
            cin >> ID;

            if (ID == 0) break;

            int match = 0;

            for (int i = 0; i < products.size(); i++) {
                if (products[i].Get_ProductID() == ID) {
                    int quantity;
                    cout << "Enter Quantity Of Product: ";
                    cin >> quantity;
                    if (quantity > 0) {
                        user.push_back(products[i]);
                        quantities.push_back(quantity);
                        count++;
                        cout << "Product Added To Cart!" << endl;
                    } else {
                        cout << "Invalid Quantity!" << endl;
                    }
                    match++;
                    break;
                }
            }

            if (match == 0) {
                cout << "Sorry! Product Doesn't Matched!" << endl;
            }
        } while (ID != 0);
        if(n.empty()){
            cout << "Enter Destination to Place Your Order: ";
            cin.ignore();
        getline(cin, n);
         }
    }

    void Remove_Product() {
        if (!user.empty()) {
            cout << "Enter Product ID To Remove Product:" << endl;
            cout << "Enter 0 To Exit." << endl;

            do {
                cout << "Enter ID: ";
                cin >> ID;

                if (ID == 0) break;

                for (int i = 0; i < user.size(); i++) {
                    if (user[i].Get_ProductID() == ID) {
                        user.erase(user.begin() + i);
                        quantities.erase(quantities.begin() + i);
                        count--;
                        break;
                    }
                }
            } while (ID != 0);
        }
    }

    void Summary() {
         cout << "Your Total Products Are: " << count << endl;
         long long total = 0;         for (int i = 0; i < user.size(); i++) {
             cout << i + 1 << ". Product ID: " << user[i].Get_ProductID()
                  << "\t Name: " << user[i].Get_Name()
                  << " \t   Quantity: " << quantities[i] << endl;
             total += user[i].Get_Price() * quantities[i];
         }
         cout << "Your Total Amount Is: " << total << endl;
         cout << "Your Order will be delivered at : " << n << endl;
     }

};

int main() {
    User One;
    int choice;
    cout << "\n----- Welcome to E-Commerce Inventory -----" << endl;
    do {
        cout << "\n------ Inventory Menu ------" << endl;
        cout << "1. Display All Products" << endl;
        cout << "2. Add Product To Cart" << endl;
        cout << "3. Remove Product From Cart" << endl;
        cout << "4. View Order Summary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            One.Display_Products();
            break;
        case 2:
            One.Add_Product();
            break;
        case 3:
            One.Remove_Product();
            break;
        case 4:
            One.Summary();
            break;
        case 5:
            cout << "Exiting... Thank You! Your order is on the way..." << endl;
            break;
        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

    return 0;
}
