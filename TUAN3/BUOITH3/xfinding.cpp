#include <iostream>
#include <vector>

int main()
{
    int n, x;
    std::cin >> n;
    std::vector<int> a(n);
    int vitri = -1;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            std::cout << i + 1 << " ";
            vitri = i;            
            
        }
    }
    if (vitri == -1)
    {
        std::cout << "NO" << std::endl;
    }
    return 0;
}