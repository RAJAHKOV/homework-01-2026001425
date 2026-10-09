#include <iostream>
#include <string>
#include <vector>

void merge(std::vector<double>& values, int left, int mid, int right)
{
    // TODO: Merge the sorted ranges [left, mid] and [mid + 1, right].
    (void)values;
    (void)left;
    (void)mid;
    (void)right;
    std::vector<double> temp1,temp2;
    for (int i=left;i<=mid;i++)
    {
        temp1.push_back(values[i]); //copy the first half
    }
    for (int i=mid+1;i<=right;i++)
    {
        temp2.push_back(values[i]); //copy the rest numbers
    }
    int index=left,i1=0,i2=0;
    do 
    {
        if (temp1[i1]<=temp2[i2])
        {
            values[index++]=temp1[i1];
            i1++;
        }
        else
        {
            values[index++]=temp2[i2];
            i2++;
        }
    }
    while((i1<temp1.size())&&(i2<temp2.size())); //comparing and conquering
    if (i1==temp1.size())
    {
        while(index<=right)
        {
            values[index]=temp2[i2++];
            index++;
        };
    }
    if (i2==temp2.size())
    {
        while(index<=right)
        {
            values[index]=temp1[i1++];
            index++;
        }
    }
    return;
}

void merge_sort(std::vector<double>& values, int left, int right)
{
    // TODO: Implement the recursive divide-and-conquer algorithm.
    (void)values;
    (void)left;
    (void)right;
    if (left<right)//divide
    {
        int mid=(left+right)/2;
        merge_sort(values,left,mid);//recursion
        merge_sort(values,mid+1,right);//recursion
        merge(values,left,mid,right);
    }
}

void print_check(const std::vector<double>& actual,
                 const std::vector<double>& expected,
                 const std::string& label)
{
    std::cout << label << ": " << (actual == expected ? "PASS" : "FAIL") << '\n';
}

void run_test(std::vector<double> values,
              const std::vector<double>& expected,
              const std::string& label)
{
    if (!values.empty()) {
        merge_sort(values, 0, static_cast<int>(values.size()) - 1);
    }
    print_check(values, expected, label);
}

int main()
{
    run_test({}, {}, "empty vector");
    run_test({4.0}, {4.0}, "one value");
    run_test({3.0, -1.0, 2.0, 2.0, 0.0},
             {-1.0, 0.0, 2.0, 2.0, 3.0},
             "mixed values");
    run_test({1.0, 2.0, 3.0, 4.0},
             {1.0, 2.0, 3.0, 4.0},
             "already sorted");
    run_test({4.0, 3.0, 2.0, 1.0},
             {1.0, 2.0, 3.0, 4.0},
             "reverse order");

    // TODO: Add at least one test of your own.
    std::vector<double> t1{-6.8,-4.5,-3.0,-8.7};
    run_test(t1,{-8.7,-6.8,-4.5,-3.0},"negative values");
    return 0;
}
