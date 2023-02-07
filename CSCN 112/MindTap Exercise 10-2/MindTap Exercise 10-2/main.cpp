#include <iostream>
#include "productType.h"

using namespace std;

int main() {
    productType prod("Escape", "ABCD-1234", "Ford", 1234, 34.5, 2.4);
    prod.print();

    prod.setQuantitiesInStock(15);
    prod.print();

    prod.setDiscount(11);
    prod.print();
}