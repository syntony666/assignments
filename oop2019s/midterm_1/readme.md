# OOP midterm
#### Spring, 2019
#### 13	April 2019, 1:10 pm – 5:00pm

**Questions:**

Computing with binary numbers is an important part in computer science. So in this test, you have a mission to complete, that is, **to implement a class that can help you do some computation on binary data.**

Please write your **unit tests** in `test/ut_binary.h`, **test's main function** in `test/ut_main.cpp`, and implement the class, **"Binary"**, in `src/binary.h`, according to the following requirements.

**Requirements:**

1. One of the constructors should take a c-style int array as input. For example **int a[2] = {1, 0}** is the input for creating the binary number **10**.  

2. For the **destructor** and any other methods, you need to make sure that **no memory leaks** appear in your program.

3. Please use **deep copy** to write your **copy constructor**.

4. **Please push your program to your gitlab account and go to Jenkins to check the execution result.**

**Example usages of methods:**

    int bits[4]={1,1,0,1};
    Binary bin(bits,4);
    bin.toString(); // "1101"
    bin.toInt();    // 13
    bin.resize(8);  // 00001101
    bin<<3;         // 01101000
    bin<<2;         // 10100000    
    bin>>4;         // 00001010
    bin.setBit(1,1);// 01001010
    bin.setBit(6,0);// 01001000

**Exception situation:**
1. If the binary number is not initialized with binary digits, calling methods that make use of the binary digits should throw an **Exception**.

2. You can assume that all the binary numbers are positive, so if a method generates a negative binary number, it should throw an **Exception**.

3. Resize a binary number to a size (i.e., number of bits) that is smaller than its original size should throw an **Exception**.

4. You cannot set a bit in any position that is out of bound, or the data you want to set is not **0 or 1**. (throw **Exception**)

**Prototypes of classes and functions:**

    class Binary{
        ...
        Binary(){...}                               // 5%
        Binary(int input[],int s){...}              // 10%
        Binary(const Binary & b){...}               // 10%
        ~Binary(){...}                              // 5%
        Binary & operator=(Binary const &b){...}    // 10%
        Binary operator+(Binary const &b){...}      // 5%
        Binary operator-(Binary const &b){...}      // 5%
        Binary operator>>(int a){...}               // 5%
        Binary operator<<(int a){...}               // 5%
        void resize(int new_size){...}              // 10%
        void setBit(int pos,int data){...}          // 10%
        int toInt() const{...}                      // 10%
        std::string toString() const{...}           // 10%
        ...
    };

**Note:**
1. Make sure your code is writen in the required file.
2. The score will be divided into three parts: code(40%), self unit tests(40%), TA's unit tests(20%).
3. You can use this [makefile](makefile)

**Resources allowed to use during the exam:**
-  [cplusplus.com](http://www.cplusplus.com/ "cplusplus.com")
-  [Cambridge Dictionary](https://dictionary.cambridge.org/zht/)
- Your own homework commits. (on Gitlab)

**Attention!! You cannot visit any other website, or you will be considered as cheating.**
