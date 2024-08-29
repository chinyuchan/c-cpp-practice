# 模板的优点
* 整数作为模板参数
  * 整数模板参数是编译期常量
  * 只支持整数和枚举
    * 对每个不同的实例函数，会生成一份代码
  ```
  00000000000011ff W _Z9print_numILi1EEvv
  00000000000012af W _Z9print_numILi2EEvv
  0000000000001257 W _Z9print_numILi5EEvv
  ```
* 编译期优化
  ```
  00000000000013c6 W _Z6sum_toILb0EEii
  0000000000001361 W _Z6sum_toILb1EEii
  ```

