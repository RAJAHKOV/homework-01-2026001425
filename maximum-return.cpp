#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
int max(int a,int b)
{
    return ((a>=b)? a:b);
}
int max_crossing_sum(const std::vector<int>& changes,
                     int low, int mid, int high)
{
    // TODO: Find the best non-empty subarray that crosses mid.
    (void)changes;
    (void)low;
    (void)mid;
    (void)high;
    int left_sum=INT_MIN,right_sum=INT_MIN,sum=0;
    for (int i=mid;i>=low;i--)
    {
        sum+=changes[i];
        left_sum=max(left_sum,sum);
    }
    sum=0;
    for (int i=mid+1;i<=high;i++)
    {
        sum+=changes[i];
        right_sum=max(right_sum,sum);
    }
    return left_sum+right_sum;
}

int max_subarray_sum(const std::vector<int>& changes, int low, int high)
{
    // TODO: Implement the divide-and-conquer recurrence.
    (void)changes;
    (void)low;
    (void)high;
    if(low<high)
    {
        int mid=(low+high)/2;
        int a1=max_subarray_sum(changes,low,mid);
        int a2=max_subarray_sum(changes,mid+1,high);
        return (max(max(a1,a2),max_crossing_sum(changes,low,mid,high)));
    }
    else
    {
        return changes[low];
    }
}

int maximum_return(const std::vector<int>& prices)
{
    if (prices.size() < 2) {
        throw std::invalid_argument("at least two prices are required");
    }

    std::vector<int> changes(prices.size() - 1);
    for (std::size_t i = 0; i < changes.size(); ++i) {
        changes[i] = prices[i + 1] - prices[i];
    }

    return max_subarray_sum(changes, 0, static_cast<int>(changes.size()) - 1);
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    check(maximum_return({100, 113, 110, 85, 105, 102, 86, 63, 81,
                          101, 94, 106, 101, 79, 94, 90, 97}),
          43,
          "crossing optimum");
    check(maximum_return({1, 2, 3, 4, 5}), 4, "increasing prices");
    check(maximum_return({9, 7, 4, 1}), -2, "decreasing prices");
    check(maximum_return({5, 8}), 3, "two prices");

    // TODO: Add at least one test of your own.
    check((maximum_return({10, 3, 5, 8, 6, 12})),9,"crossing optimum");
    return 0;
}
