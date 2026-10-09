# homework-01-2026001425
## The first homework of computer skills:
### 1.GitHub 小项目
项目URL(Uniform Resource Locator):https://github.com/RAJAHKOV/cpp-configuration.git

最终实现的目标：在VScode中配置中文的C++开发环境。

### 2.Binary search
编译：
```bash
g++ -std=c++11 binary-search.cpp -o binary-search
```
运行：
```bash
.\binary-search
```
测试结果：
```bash
missing value: PASS (expected -1, got -1)
middle value: PASS (expected 2, got 2)
first value: PASS (expected 0, got 0)
last value: PASS (expected 4, got 4)
The second test:
missing value: PASS (expected -1, got -1)
The third test:
missing value: PASS (expected -1, got -1)
repeated value: FAIL (expected 13, got 14)
repeated value: PASS (expected 14, got 14)
first value: PASS (expected 0, got 0)
last value: PASS (expected 20, got 20)
a simple value: PASS (expected 11, got 11)
```
解释：第三次测试FAIL的原因是target的数值在数组中重复出现，程序找到了其中一个

说明：

本题的基本思想如题目所述，利用所给出的数组的单调性，分别将左端点、右端点和中点与target进行比较，若查找成功则直接返回(return)下标，不成功则更新左端点或右端点的值。

需要注意的是，若最终左端点大于右端点且仍未查找成功返回，则target不在数组中，返回-1.

复杂度分析：

最坏情况下算法运行的时间复杂度是$` \mathcal{O}(\log n) `$的，其中$` n `$是数组长度。

声明：完成本题未使用任何AI工具。
### 3.Merge sort
编译：
```bash
g++ -std=c++11 merge-sort.cpp -o merge-sort
```
运行：
```bash
.\merge-sort
```
测试结果：
```bash
empty vector: PASS
one value: PASS
mixed values: PASS
already sorted: PASS
reverse order: PASS
negative values: PASS
```
说明：

本题采取了课件中的分治思想(divide and conquer)，把大的问题拆成基本问题，再把基本问题的解合并。具体到这道题来说，就是每次把数组二分，至单个元素，然后递归地往原始数组合并。

复杂度分析：

设解决规模为$` n `$的问题的所需时间为$` T(n) `$，由合并的执行次数为$` 2n `$，那么我们有递归式
```math
T(n)=2T(\frac{n}{2})+2n
```
由[主定理(Master Theorem)](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))，

本算法的时间复杂度为$`\Theta(n \log n)`$，满足题中给出的$`O(n \log n)`$要求。其中$` n `$是数组中元素个数。

声明：完成本题未使用任何AI工具。
### 4.Maximum return
编译：
```bash
g++ -std=c++11 maximum-return.cpp -o maximum-return
```
运行：
```bash
.\maximum-return
```
测试结果：
```bash
crossing optimum: PASS (expected 43, got 43)
increasing prices: PASS (expected 4, got 4)
decreasing prices: PASS (expected -2, got -2)
two prices: PASS (expected 3, got 3)
crossing optimum: PASS (expected 9, got 9)
```
本题使用了和第三题类似的分治算法。每次把差分数组A[i]二分，递归直至单个元素，回溯比较左侧，右侧和横跨左右的数组和的最大值，直至输出最终结果。

复杂度分析：

类似地使用主定理：

设解决规模为$` n `$的问题的所需时间为$` T(n) `$，由计算横跨左右的执行次数的上限为$` n `$，那么我们有递归式
```math
T(n)=2T(\frac{n}{2})+n
```

本算法的时间复杂度为$`\Theta(n \log n)`$，满足题中给出的$`O(n \log n)`$要求。其中$` n `$是交易天数。

声明：完成本题未使用任何AI工具。
### 5.Matrix class
从`/matrix`目录编译
```bash
g++ -std=c++11 main.cpp matrix.cpp -o matrix-demo
```
运行
```bash
.\matrix-demo
```
测试结果
```text
matrix addition: PASS
matrix multiplication: PASS
Matrix a:
1 2
3 4
additional matrix addition test
additional matrix addition test: PASS
A1+B1 result:
9 9
14 14.4
additional matrix multiplication test
additional matrix multiplication test: PASS
A2*B2 result:
19 22
43 50
wrong dimension flag1 exception for matrix addition: PASS
wrong dimension flag2 exception for matrix multiplication: PASS
```
说明：

本题主要补全的部分是成员函数的重载，特别值得注意的是，重载运算符时不应出现类变量的名字，要省略或者用`this`指针代替（C++11已全面兼容`this`指针的使用），另外重载输出的流符号要加`std::ostream`

矩阵大小不匹配时，我使用了try-catch语句，用于用来**捕获程序运行时抛出的异常**，防止程序直接崩溃退出。
**try 里面放可能出错的代码；一旦代码抛出异常，就跳到对应的 catch 块处理错误。**

声明：完成本题的try-catch代码块使用了豆包。通过设置行列不满足运算条件的矩阵加法乘法，验证了结果正确。
