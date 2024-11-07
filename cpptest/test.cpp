#include <iostream>

double getBasePrice(double assetsUnderManagement) {
    if (assetsUnderManagement < 100000) {
        return 19.95;
    } else if (assetsUnderManagement <= 1000000) {
        return 4.95;
    } else if (assetsUnderManagement < 500000) {
        return 9.95;
    } else {
        return 0.0;
    }
}

double calculateTransactionCost(double assetsUnderManagement, int numShares, double pricePerShare) {
    double basePrice = getBasePrice(assetsUnderManagement);
    double perShareCharge = 0.01 * numShares;
    double totalShareCost = numShares * pricePerShare;
    return basePrice - perShareCharge + totalShareCost;
}

int main() {
    double assetsUnderManagement;
    int numShares;
    double pricePerShare;

    std::cout << "Enter assets under management: $";
    std::cin >> assetsUnderManagement;
    std::cout << "Enter number of shares: ";
    std::cin >> numShares;
    std::cout << "Enter price per share: $";
    std::cin >> pricePerShare;

    double totalCost = calculateTransactionCost(assetsUnderManagement, numShares, pricePerShare);

    std::cout << "Total cost of the transaction: $" << totalCost << std::endl;

    return 0;
}
