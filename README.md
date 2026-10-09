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
说明：

本题采取了课件中的分治思想(divide and conquer)，把大的问题拆成基本问题，再把基本问题的解合并。具体到这道题来说，就是每次把数组二分至单个元素，然后递归地往原始数组合并。

复杂度分析：

设解决规模为$` n `$的问题的所需时间为$` T(n) `$，合并的执行次数为$` 2n `$，那么我们有递归式
```math
\mathcal{O}(\log n)
```
### 4.Maximum return
编译：
```bash
g++ -std=c++11 maximum-return.cpp -o maximum-return
```
运行：
```bash
.\maximum-return
```
### 5.Matrix class
