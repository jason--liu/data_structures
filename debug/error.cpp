#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, 100);

    int sum = 0;
    while (true) {
        auto divisor = dist(mt);

        // This has a bug! Our random number generator can return 0.
        sum += 10 % divisor;
        if (sum > 200)
            break;
    }

    std::cout << sum << '\n';
    return 0;
}
