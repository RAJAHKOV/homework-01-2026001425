#include <iostream>
#include <string>
#include <vector>

int binary_search_index(const std::vector<int>& values, int target)
{
    // TODO: Implement binary search.
    (void)values;
    (void)target;
    int t=values.size();
    int l=0,r=t-1;
    while(l<=r)
    {
        if (values[l]==target)
        {
            return l;
        }
        if (values[r]==target)
        {
            return r;
        }
        int mid=(l+r)/2;
        if (values[mid]==target)
        {
            return mid;
        }
        else
        {
            if (values[mid]<target)
            {
                l=mid+1;
               
            }
            else 
            {
                r=mid-1;
            }
        }
    }
    return -1;
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 6};

    check(binary_search_index(values, 5), -1, "missing value");
    check(binary_search_index(values, 3), 2, "middle value");
    check(binary_search_index(values, 1), 0, "first value");
    check(binary_search_index(values, 6), 4, "last value");

    // TODO: Add at least two boundary tests of your own.
    std::cout << "The second test:" << std::endl;
    const std::vector<int> a2{}; //empty vector checking
    check(binary_search_index(a2, 8), -1, "missing value");


    std::cout << "The third test:" << std::endl;
    const std::vector<int> a3{1,4,6,12,12,17,19,19,25,29,36,39,41,43,43,68,71,78,84,89,97};
    check(binary_search_index(a3, 5), -1, "missing value");
    check(binary_search_index(a3, 43), 13, "repeated value");
    check(binary_search_index(a3, 43), 14, "repeated value");
    check(binary_search_index(a3, 1), 0, "first value");
    check(binary_search_index(a3, 97), 20, "last value");
    check(binary_search_index(a3, 39), 11, "a simple value");
    return 0;
}
