## C与C++的区别

### Const与指针

|              | 指向常量的指针       | 常指针               | 指向常量的常指针           |
| ------------ | -------------------- | -------------------- | -------------------------- |
| 格式         | const 类型名* 指针名 | 类型名* const 指针名 | const 类型名* const 指针名 |
| 示例         | const int* p = &x;   | int* const p = &x;   | const int* const p = &x;   |
| 可修改的值   | p, x                 | *p, x                | x                          |
| 不可修改的值 | *p                   | p                    | p, *p                      |



### 名字空间与域解析符

``` c++
#include<iostream>
using namespace std;

namespace one {
    int a = 0;
    int b = 0;
}
namespace two {
    int a = 1;
    int b = 1;
}

using namespace one;
// using namespace two;
int main() {
    using two::a;
    a = -100;
    // cout<<b<<endl; error: reference to 'b' is ambiguous
    cout<<a<<endl; // -100
    cout<<one::a<<endl; // 0
}
```

- 当两个同时使用两个命名空间时，若命名空间中含有相同变量名时直接使用会提示错误`error: reference to 'b' is ambiguous`
- 在C++语言中，通过在同名变量前加上域解析符`::`对被隐藏的同名全局变量进行访问



### 内联函数

- 内联函数的出现是为了代替宏定义，以一种更为安全的方式进行**代码替换**

- 工作原理：在程序**编译**时，编译器将程序中出现的内联函数的调用表达式用内联函数的函数体来进行替换

- 内联函数进行的是代码的替换，所以会在编译后增加代码的体量，但节省了调用函数的时间
- 由于内联函数的特性，所以在内联函数中不允许使用循环语句和开关语句；若内联函数中存在这些语句，则编译器优化其为普通函数，对其进行调用和返回
- 类中的成员函数可以理解为内联函数

``` c++
#include<iostream>
#define defineMutiply(x, y) x*y

inline int inlindeMutiply(int x, int y) {
    return x*y;
}

using namespace std;

int main() {
    int define = defineMutiply(3+4, 2+3); // 3+4*2+3 = 14
    int Inline = inlindeMutiply(3+4, 2+3);
    cout<<"define = "<<define<<endl; // define = 14
    cout<<"Inline = "<<Inline<<endl; // Inline = 35
    return 0;
}
```



### 引用

**“变量一样的用法，指针一样的功能”**

格式：

1. 数据类型 &引用名 = 已定义的变量名;

2. 类型名& 函数名(形式参数表);

   ```c++
   int& Fun(const int& x, int &y, int z) {
       z++;
       y = x + y + z;
       return y;
   }
   Fun(a, b, c);
   d = Fun(a, b, c);
   Fun(a, b, c) = 20; //相当于b = 20;
   ```

**注意事项：**

- 声明引用时&表示引用的一个声明，不代表取地址

- 声明引用时必须对它进行初始化，以明确该引用是哪个对象的别名，而且之后引用的别名关系不可改

- 引用只是某个变量的一个别名，所以系统不会为引用分配内存空间

- 引用作为返回值的函数存在特殊要求

  - return 后面只能是变量，而不能是常量或表达式

  - return 后面变量的内存空间再本次函数调用结束后应当仍然存在

  - return 后面不能是常引用

    ```c++
    //常引用
    int a = 0;
    int const &b = a;
    // b++; // error: increment of read-only reference 'b'
    ```

- 不能建立空引用、引用的引用、指向引用的指针、引用数组

  ```c++
  // 错误示范
  int x = 10, a[10];
  void &r = x;
  int &&r = x;
  int &*p = x;
  int &arr[10] = a;
  ```

引用与指针的比较：

|              |                引用                |                  指针                  |
| ------------ | :--------------------------------: | :------------------------------------: |
| 实质         |         变量（对象）的别名         |         指向变量（对象）的地址         |
| 初始化       |           必须进行初始化           |          非必须，事后可以赋值          |
| 可变性       | 一旦成为某个变量的别名，则不可更改 |           可以更改指针的指向           |
| 是否有空值   |    不可为空，一旦声明必须初始化    | 可以置为空指针NULL，表示不指向任何变量 |
| 占用内存情况 |    不额外占用空间，只是所指对象    | 另外占用4字节空间，用来存储变量的地址  |
| 访问方式     |         直接使用引用名访问         |           使用`*指针名`访问            |
| 安全有效性   |     安全，始终为某个变量的别名     |    安全，不一定有效，可能成为野指针    |



### 内存申请管理

使用new申请内存，使用delete释放内存

```c++
int *ptr, *ptrArray;
ptr = new int;// 申请1个int大小的空间
ptr = new int(10); // 申请1个int大小的空间，并赋值为10
ptrArray = new int[10]; // 申请10个int大小的空间，并将数组地址返回给ptr

delete ptr; // 释放指针ptr所指向的空间
// delete ptrArray; // 释放ptrArray所指向的数组的第一个地址，即释放了int大小的空间，不推荐
delete []ptrArray; // 释放ptrArray所指向的数组的全部空间
```

- **建议不要将C++的new、delete和存储管理函数malloc、calloc、free混合使用**

**内存泄露：用new申请的内存必须要用delete来加以释放，否则会导致动态分配的内存无法回收，使得程序占据的内存越来越大**

内存申请的区别：

```c++
/*
	当用户自定义默认构造函数时，以下两种写法都是调用默认构造函数
	当用户没有自定义默认构造函数时，结果不同
*/
T* p = new T(); // 除了调用系统生成的隐含的默认构造函数外，还会为基本数据类型和指针类型的成员用0赋初值
T* p = new T; // 调用系统生成的隐含的默认构造函数
```

创建多维数组：

```c++
// 创建方式
float (*cp)[9][8] = new float[8][9][8];
// 访问方式
*(*(*(cp+i)+j))
```



### void类型指针

void类型指针表示不确定类型的指针，即一种通用类型的指针，任何指针都可以直接赋值给void类型的指针

注意事项：

- 可以定义void类型的指针，但是不能定义void类型的引用和变量

- void类型的指针只是可以接受任何类型指针变量的赋值，但是不可以直接使用void类型指针访问内存中的内容，需要做一个显示类型转换。

  例如C中的malloc函数的返回是一个void*类型，当进行赋值时需要根据申请空间的变量类型进行转换

  ```c++
  int *p = (int *)malloc(10*sizeof(int)); // 申请一个大小为10的int数组
  ```



### 异常处理

C++语言中异常处理通过以下3步实现：

1. 检查异常（try）
2. 抛出异常（throw）
3. 捕捉异常（catch）

其中抛出异常再可能出现异常的**当前函数**处理，检查异常和捕捉异常在**上级函数**中处理

```c++
#include<iostream>
using namespace std;

int divide(int x, int y) {
    if (y == 0) {
        throw y;
    }
    return x/y;
}

int main() {
    int a = 10, b = 0;
    try {
        divide(a, b);
    }
    catch(int) {
        cout<<"except of divide zero"<<endl;
    }
    cout<<"finished"<<endl;
    return 0;
}
```

throw语句格式：`throw <表达式>; 或 throw ;`

try-catch语句格式：

```c++
try{
    //<被进行异常检查的语句>
}
catch(/*<异常信息类型>或<变量>*/) {
    //<异常处理语句>
}
<catch(/*..*/){
  //...  
}>
```

**注意事项：**

- try块一定要在catch块前面，try和catch块之间不能有任何其他语句
- 可以只有try块，没有catch块，即捕捉到异常后不做处理
- 只能有一个try块，而对应可以有多个catch块，即针对throw出的不同异常来进行分情况处理



## 类与对象

### 类的定义

格式：

```c++
class 类名 {
[private: ]
    // 私有成员变量或成员函数
[protected: ]
    // 保护成员变量或成员函数
public:
    // 公有成员变量或成员函数
};
```

- private为类默认的访问类型
- public、protected和private书写顺序无严格限制

| 访问属性  | 含义     | 作用                                                         |
| --------- | -------- | ------------------------------------------------------------ |
| private   | 私有成员 | 只允许该类的成员函数及友元访问，不能被其他函数访问           |
| protected | 保护成员 | 既允许该类的成员函数及友元访问，也允许其派生类的成员函数访问 |
| public    | 公有成员 | 既允许该类的成员函数访问，也允许类外部的其他函数访问         |

- 在C++中，结构体类型也可以有数据成员和成员函数两大组成部分，其**定义方式与类的定义基本一致**，只是将关键字class替换成struct即可。二者最大的区别就是：**class定义中类成员的默认访问属性为private，而struct定义中结构成员的默认访问属性为public**，因此类的封装和信息隐藏特性要好于结构体



### 类的访问

通过对象来访问类中的成员，方式分为两种：

- 圆点访问形式

  `对象名.成员 或 (*指向对象的指针).成员`

- 指针访问形式

  `对象指针变量名->成员 或 (&对象名)->成员`

**this**指针指向存放当前对象的地址，每个成员函数都存在一个隐含的this指针



### 构造函数与析构函数

构造函数格式：`类名 ([形式参数列表]) 或 类名::类名 ([形式参数列表])`

- 当在类外实现成员函数时，需要加限定符：`类名::`
- **构造函数在对象创建时由系统调用，所以在程序中就不能调用对象的构造函数**
- 构造函数没有返回类型，构造函数名必须与类名相同
- 构造函数为public类型，否则定义对象时无法自动调用构造函数，编译时也会出现错误提示

- 对于一个用户自定义的类，若用户定义时未定义构造函数，则编译器自动生成一个**默认的无参构造函数**，定义对象时会自动调用该构造函数；若用户定义了构造函数，则编译器不会生成无参构造函数。当定义对象时没有提供实际的参数，编译器就会查找无参的构造函数；如果类中已定义了其他有参构造函数而没有定义无参的构造函数，C++编译器就会给出一个错误提示

析构函数格式：`~类名() 或 类名::~类名()`

- **析构函数在对象创建时由系统调用，所以在程序中就不能调用对象的析构函数**

- 析构函数没有返回类型，同时应当声明为public类型，否则编译器会报错
- **每个类中只有一个析构函数，析构函数因为其特点所以不能重载**
- 系统提供一个默认的析构函数，即使不定义析构函数也可以使用，但是当成员变量中含有指针类型的成员时，需要在析构函数中进行内存释放，保证对象生存期结束时释放所有的内存空间



### 深拷贝与浅拷贝

系统为每一个类提供了默认拷贝构造函数，可以实现将源对象所有数据成员的值逐一赋值给目标对象相应的数据成员。但是该拷贝为**浅拷贝**，不能拷贝成员变量中的指针数据类型，只能进行指针的指向，当源对象销毁后指针内存释放，此时目标对象成员变量的指针变为了**悬挂指针**，其所指内存不属于当前程序，析构时报错

当类中没有定义拷贝构造函数时，系统使用默认的拷贝构造函数，当对象作为参数传递时，依然为浅拷贝，如下：

```c++
#include<iostream>
using namespace std;

class Test {
private:
    int a, b;
public:
    Test(){}
    Test(int a, int b):a(a), b(b) {}
    void modify(int a, int b) {
        this->a = a;
        this->b = b;
    }
    void display() {
        cout<<"a = "<<a<<", b = "<<b<<endl;
    }
};

void fun(Test test) {
    test.modify(2, 3);
    test.display(); // a = 2, b = 3
    return;
}

int main() {
    Test t1(1, 2);
    t1.display(); // a = 1, b = 2
    fun(t1);
    t1.display(); // a = 1, b = 2
    return 0;
}
```



### 对象数组

初始化：`Date dt[2] = {Date(2011, 5, 1), Date(2020, 6, 1)}`



### 对象指针

格式：`类名 *对象指针名`

用指针引用对象成员的方法形式：

```c++
指针变量名->成员名 或 (*指针变量名).成员名
(对象数组名+下标)->成员名 或 *(对象数组名+下标).成员名
```



### 对象引用

- 对象引用与一般变量的引用一样，是一个已经定义对象的别名，引用本身不再另外占用内存空间。
- 对象引用只是某对象的别名、引用与它代表的对象共享同一个单元。
- 引用必须在定义时初始化，并且在程序运行过程中不能让引用成为另一个对象的别名



### 友元

友元的三种形式：

- 一个不属于其他任何类的普通函数声明为当前类的友元，称为当前类的**友元函数**
- 一个其他类的成员函数声明为当前类的友元，称为当前类的**友元成员**
- 另一个类声明为当前类的友元，称为当前类的**友元类**

使用友元可以避免频繁调用类的接口函数，提高程序的运行速度，从而提高程序的运行效率

#### 友元函数

形式：`friend 函数返回类型 函数名(形式参数表);`

**注意事项：**

1. 通常友元函数时在类的定义中给出原型声明，声明的位置任意，不受访问属性的限制，声明之后的友元函数在类外面给出完整定义，此时前面不能再加关键字friend
2. 友元函数也可以在类内部直接给出定义，定义的首部相当于原型声明
3. 友元函数的定义和调用方式与普通函数相同
4. 友元函数提供了不同类成员函数之间、类的成员函数与普通函数之间进行数据共享的机制，尤其是一个函数需要访问多个类时，友元函数非常有用
5. 友元毕竟是打破了封装和信息隐藏机制，因此在安全性和效率之间需做折中处理

#### 友元成员

形式：`friend 函数返回类型 友元类名::函数名(形式参数表);` 

**注意事项：**

1. 一个类的成员函数作为另一个类的友元成员时，必须先定义这个类
2. **对于先使用后定义的标识符都应当给出向前引用声明**

#### 友元类

形式：`friend 类名;`

**注意事项：**

1. 友元类的声明是单向的，不具有交换性，即声明友元的类未必是被声明类的友元

2. 友元关系不具备传递性，即A类将B类声明为友元，B类将C类声明为友元，此时C类还不是A类的友元

   ```c++
   class Date{
   private:
       int year, month, day;
   public:
       void getDate();
       friend Person;
   };
   
   class Person {
   public:
       void output(Date &date) {
           date.getDate();
           date.year = 2001;
           date.month = 12;
           date.day = 30;
       }
   };
   ```



## 类中数据的共享与保护

### 静态成员

静态成员包括**静态数据成员**和**静态成员函数**

#### 静态数据成员

静态数据成员声明形式：`static 类型名 静态数据成员名`

静态数据成员访问形式：`类名::公有静态成员变量名; 或 对象名.公有静态成员变量名`

静态数据成员是同类对象共享的，事实上，它在**该类的任何对象被创建前就已经存在**，因此其初始化工作**不能通过类的构造函数**完成，而必须在类定义结束之后进行，默认值为0，静态数据成员是在编译时创建并初始化的。

```c++
class Person{
public: 
    static int total;
};

int Person::total = 1;// 类定义结束之后初始化
```

#### 静态成员函数

静态成员函数声明形式：`static 返回值类型 静态成员函数名(形式参数表)`

静态成员函数访问形式：`类名::静态成员函数名(实际参数表); 或 对象名.静态成员函数名(实际参数表);`



### 共享数据的保护

#### 常数据成员

定义形式：`const 类型名 常数据成员名`

常数据成员的初始化**只能在构造函数的初始化列表**中进行，不能在构造函数的函数体中用赋值等语句实现，而普通数据成员两种方式均可

```c++
class Person {
private:
    const bool sex;
    int age;
public:
    Person(bool sex, int age):sex(sex){// 不可以放到函数体中
        this->age = age;
    }
}
```

**静态常数据成员：**在常数据成员定义**之前**增加一个关键字static

静态常数据成员的初始化不可以放在初始化列表中完成了，与静态数据成员类似，要在类定义结束后单独初始化

```c++
class Person{
public: 
    static const int PI;
};

const int Person::PI = 3.14;// 类定义结束之后初始化
```

#### 常成员函数

声明形式：`类型 函数名(形式参数表) const;`

**注意事项：**

1. 关键字const可以作为与其他成员函数重载的标志，即以下写法正确

   ```c++
   class Test{
   public:    
   	void print(); // 非常对象t.print()默认情况下调用不带const的函数 
   	void print() const;
   }
   ```

2. 常成员函数不能修改本类的数据成员，因此也不能调用该类中未经关键字const修饰的普通成员函数。但是反过来，普通成员函数可以调用常成员函数。

#### 常对象

定义形式：`类名 const 对象名;`  或  `const 类名 对象名;`

**注意事项：**

1. 常对象类比基本数据类型中的常量，在定义常对象时**必须进行初始化**，而且其对象的数据成员值不能修改

2. 常对象只能调用它的常成员函数而不能调用普通的成员函数

   ```c++
   #include<iostream>
   
   using namespace std;
   class Test{
   public:
       void print() {
           cout<<"general print."<<endl;
       }
       void print() const {
           cout<<"const print."<<endl;
       }
   }
   
   int main() {
       const Test t1;
       Test t2;
       t1.print(); // const print.
       t2.print(); // general print.
   }
   ```



## 类与类之间的关系

类与类之间存在3种关系：组合(Composition)、依赖(Dependency)和继承(Inheritance)

组合(Composition)：C类中包含了A类和B类的对象作为成员变量，即**对象成员**

依赖(Dependency)：C类的某个函数实现需要B类的对象作为参数

继承(Inheritance)：C类为B类的**派生类**，B类为C类的**基类**

**UML中类与类之间关系：**

- 依赖关系（实心箭头虚线）
- 作用关系——关联（实线 重数）
- 包含关系——聚集和组合
  - 聚集（部分消失整体存在）（空心菱形 重数）
  - 组合（部分消失则整体消失）（实心菱形 重数）
- 继承关系——泛化（空心三角实线）



### 对象成员

- 对象成员在创建时需要调用构造函数，在退出时需要调用析构函数

- **对象与它内部的对象成员具有相同的生命周期**

- 创建一个对象时，构造函数的调用次序是：**首先调用对象成员的构造函数，再调用对象自身的构造函数**，析构时相反

- 对象成员构造函数的调用次序与初始化表中出现的次序无关，它始终**与对象成员在类中定义的次序一致**

  ```c++
  class A {
  private:
      int x;
  public:
      A(int a) {
          x = a;
          cout<<"A: x = "<<a<<endl;
      }
  };
  
  class B {
  private:
      A a1, a2;
      int y;
  public:
      B(int a, int b, int c):a2(b), a1(a) { //当初始化对象成员时，需要写到初始化列表里
          y = c;
          cout<<"B: y = "<<c<<endl;
      }
  };
  
  int main() {
      B obj(10, 20, 30);
      // 执行结果为：
      // A: x = 10
      // A: x = 20
      // B: y = 30
      return 0;
  }
  ```



### 基类与派生类

在面向对象程序设计的语境中，旧类称为**基类**，也称作**父类**，新类称为**派生类**，也称为**子类**

在C++中，一个基类可以派生出多个派生类，一个派生类也可以有多个基类，派生类可作为新的基类，继续派生出新的派生类

**继承**通常分为**单一继承**和**多重继承**两大类。单一继承是指一个派生类只有一个基类，多重继承是指派生类有多个基类。**C++支持多重继承**

```c++
// 基类
class Object1{};
class Object2
// 继承Object1，为Object1的派生类，Student的基类
class People: public Object1 {};
// 继承People，为People的派生类
class Student: public People {};
// 多重继承
class Object3: public Object1, public Object2 {};
```

**继承方式**共有3种：public（公有）、protected（保护）和private（私有），**如果缺省，则默认为私有继承方式**

|                   | 公有成员 | 保护成员 | 私有成员 |
| ----------------- | -------- | -------- | -------- |
| 公有继承public    | 公有成员 | 保护成员 | 不继承   |
| 保护继承protected | 保护成员 | 保护成员 | 不继承   |
| 私有继承private   | 私有成员 | 私有成员 | 不继承   |

**定义一个派生类对象时，构造函数的调用顺序为：**

- 基类的构造函数
- 派生类对象成员的构造函数（按照定义顺序）
- 派生类的构造函数

大部分构造函数需要传入一定的参数来初始化成员，此时需要在派生类构造函数的初始化列表中对基类构造函数进行调用，语法如下：

```c++
/*
<派生类名> (总形式参数表):<基类名1>(<参数表1>), 
					  <基类名2>(<参数表2>)[, ...<基类名n>(<参数表n>)],
					  [<对象成员名1>(<参数表1>), ...],
					  [<其他初始化项>]{
    [<派生类自身数据成员的初始化>]                          
}
*/
class Base{
private:
    int x;
public:
    Base(int x) {
        this->x = x;
    }
};

class Drived: public Base {
private:
    Base b;
public:
    Drived(int x):Base(x), b(x) {}
};
```

注意事项：

- 构造派生类对象时，就要对基类的成员对象和新增成员对象进行初始化
- 如果对基类初始化时，需要调用基类的带有形参表的构造函数时，派生类就必须声明构造函数



### 同名冲突

#### 派生类与基类同名冲突

派生类在定义新成员时，新成员的名称与基类中的某个成员同名，此时同名覆盖原则将发挥作用，即无论是派生类内部成员函数还是派生类对象访问同名成员，如果未加任何特殊标识，则访问的都是派生类中新定义的同名成员

如果派生类内部成员或派生类对象需要访问基类的同名成员，则必须在同名成员前面加上**“基类名::”**进行限定

**注意事项：**

- 通过派生类的指针或引用，访问的是派生类的同名成员，此时同名覆盖原则依然发挥作用
- **基类的指针指向派生类对象时，访问的依然是基类中的同名成员**
- 基类的引用成为派生类对象别名时，访问的也依然是基类中的同名成员

#### 多个直接基类引发的同名冲突

多重继承中多个直接基类中有同名成员，此时派生类中访问这些成员时，将发生同名冲突问题

其解决方案与上种冲突类似，在成员前指明基类名即可

#### 共同祖先基类多重拷贝引发的同名冲突

派生类有多个直接或间接的基类，在这些基类中，有一个基类是其余某些基类的共同祖先，派生类访问这些成员时，将发生同名冲突问题

解决方法：引入**虚基类**

##### 虚基类：从不同路径继承过来的同名数据成员在内存中只有一个副本，同一个函数名也只有一个映射

```c++
class base {
public:
    int var;
}

class base1: virtual public base {
public:
    int var1;
    base1(int var):base(var){}
}

class base2: virtual public base {
public:
    int var2;
    base2(int var):base(var){}
}

class derived: public base1, public base2 {
public:
    derived(int var):base1(var), base2(var), base(var){}
}
```

所有派生类均调用虚基类的构造函数，**但C++规定只有最后一层派生类对虚基类构造函数的调用发挥作用**，即上述例子中，只有derived真正调用，其余均被忽略

**构造一个类的对象一般的顺序：**

1. 如果该类含有直接或间接虚基类，则先执行虚基类的构造函数
2. 如果该类有其他基类，则按照他们在**继承声明列表中出现的次序**，分别执行它们的构造函数，但构造过程中，不再执行他们的虚基类的构造函数
3. 按照定义中出出现的顺序，对派生类中新增的成员对象进行初始化。对类类型的成员对象，如果出现在构造函数初始化列表中，则以其中指定的参数执行构造函数，如未出现，则执行默认构造函数；对于基本数据类型的成员对象，如果出现在构造函数的初始化列表中，则使用其中指定的值为其赋值，否则什么也不做
4. 执行构造函数的函数体



### 赋值兼容规则

赋值兼容就是指需要使用**基类**的地方可以使用其**公有派生类**来代替

理论依据：公有派生类继承了基类中除构造函数、析构函数以外的所有非私有成员，且访问权限也完全相同

常见情形：

- 基类对象 = 公有派生类对象

  赋值后的基类对象只能获得基类成员部分，派生类中新增加的成员不能被基类对象访问

- 指向基类对象的指针 = 公有派生类对象的地址

  利用赋值后的指针可以间接访问派生类中的基类成员

- 指向基类对象的指针 = 指向公有派生类对象的指针

  利用赋值后的指针可以间接访问原指针所指向对象的基类成员

- 基类的引用 = 公有派生类对象，即派生类对象可以初始化基类的引用

**共有派生类可以当基类使用，但是反过来不行**



### 前向引用声明

在引用未定义的类之前，将该类的名字告诉编译器，使编译器知道该符号是一个类名

尽管使用了前向引用声明，但是在提供一个完整的类定义之前，不能定义该类的对象，也不能在内联成员函数中使用该类对象

```c++
class A; // 前向引用声明
class B{
    // A a;// 错误：类A的定义尚不完善
    A *ap;
    A &ai;
};
class A{
    B b;
};
```



### 联合体

格式：`union 联合体名称`

特点：

- 联合体的全部数据成员共享同一组内存单元
- 联合体变量中的成员同时至多只有一个是有意义的
- 联合体的各个对象成员不能有自定义的构造凹函数、自定义的析构函数和重载的复制赋值运算符，对象成员的对象成员也不能有
- 无名联合体没有标记名，只是声明一个成员项的集合，这些成员项具有相同的内存地址，可以由成员项的名字直接访问



## 多态

**多态**是指同样的**消息**被不同类型的**对象**接受时导致不同的行为，最简单的例子就是运算符，使用运算符可以进行各种类型数的运算，不同类型的数得到不同类型的结果

**多态的类型：**

- 重载多态

  指普通函数及类的成员函数的重载都属于重载多态

- 强制多态

  指将一个变元的类型加以变化，以符合一个函数或者操作的要求，例如加法运算符在进行浮点数与整型数相加时，首先进行类强制转换，把整型数变为浮点数再相加

- 包含多态

  指在类族中定义于不同类中的同名成员函数的多态行为，主要通过虚函数来实现

- 参数多态

  与模板类相关联，在使用时必须赋予实际的类型才可以实例化，由此由类模板实例化的各个类都具有相同的操作，而操作对象的类型却各不相同

包含多态和参数多态称为**通用多态**；重载多态和强制多态称为**专用多态**

**多态的实现：**

- 编译时多态（静态联编）：在程序编译阶段就能实现的多态性，可以通过函数重载和运算符重载实现
- 运行时多态（动态联编）：在程序执行阶段实现的多态性，可以通过继承、虚函数、基类的指针或引用等技术来实现

**绑定：**

绑定是指**计算机程序自身彼此关联的过程**，也就是把一个标识符名和一个存储地址联系在一起的过程；用面向对象的术语讲，**就是把一条消息和一个对象的方法相结合的过程**，分为**动态绑定**和**静态绑定**

绑定工作在编译连接阶段完成的情况称为静态绑定，也称早期绑定或前绑定

绑定工作在程序云景阶段完成的情况称为动态绑定，也称晚期绑定或后绑定



### 运算符重载

语法格式：

```c++
// 运算符重载为类的成员函数
返回类型 operator 运算符(形参表) {
    函数体
}
或
// 运算符重载为非成员函数
返回类型 operator 运算符(形参表) {
    函数体
}
```

规则：

- C++中除了`. .* :: ?: sizeof`之外其他都可以重载，且只可以重载已经存在的运算符，不可以创造新的运算符
- **重载之后运算符的优先级和结合性都不会改变**
- 运算符的重载应当与原有功能相似，不能改变原运算符的操作对象个数，同时至少有一个操作对象是自定义类型
- **在可被重载的运算符中，除了赋值运算符“=”以及变形的赋值运算符（如>>=、+=等），其余在基类重载的运算符都能被派生类所继承**

#### 运算符重载为成员函数

语法格式：

```c++
/*
<函数类型> operator <运算符>(<形式参数表>) {
    <函数体>
}
*/
// 前置单目运算符和后置单目运算符的重载最主要的区别就在于重载函数的形参
Object& operator++();// 重载前置单目运算符
Object operator++(int); // 重载后置单目运算符
```

例如：

```c++
#include<iostream>
using namespace std;

class Object {
private:
    int count;
public:
    Object(int count = 0) {
        this->count = count;
    }
    Object& operator ++() {
        (*this).count++;
        return *this;
    }
    Object operator ++(int) {
        Object old = *this;
        ++(*this);
        return old;
    }
    Object operator +(const Object &c) const{
        Object ans(this->count + c.count);
        return ans;
    }
    int getCount() {
        return count;
    }
};

int main() {
    Object a(1), b(2);
    Object c = a+b;
    // a = 1, b = 2
    cout<<"a = "<<a.getCount()<<", b = "<<b.getCount()<<endl;
    a++;
    ++b;
    // a = 2, b = 3
    cout<<"a = "<<a.getCount()<<", b = "<<b.getCount()<<endl;
    // a + b = 5
    cout<<"a + b = "<<(a+b).getCount()<<endl;
    return 0;
}
```

#### 运算符重载为非成员函数

Tips：不一定所有的非成员函数运算符重载都需要声明为类的友元函数，仅在需要访问类的私有成员或保护成员时再这样

语法格式：

```c++
/*
<函数类型> operator <运算符>(<形式参数表>) {
    <函数体>
}
*/
// 前置单目运算符和后置单目运算符的重载最主要的区别就在于重载函数的形参
friend Object& operator++(Object &a);// 重载前置单目运算符
friend Object operator++(Object &a, int); // 重载后置单目运算符
```

例如：

```c++
#include<iostream>
using namespace std;

class Object {
private:
    int count;
public:
    Object(int count = 0) {
        this->count = count;
    }
    int getCount() const {
        return count;
    }
    void setCount(int value) {
        count = value;
    }
    friend istream& operator >>(istream &in, Object& a);
    friend ostream& operator <<(ostream &out, Object& a);
    friend Object& operator ++(Object &a);
    friend Object operator ++(Object &a, int);
    friend Object operator +(const Object &a, const Object &b);
};

istream& operator >>(istream &in, Object& a) {
    in>>a.count;
    return in;
}
ostream& operator <<(ostream &out, Object& a) {
    out<<a.count;
    return out;
}
Object& operator ++(Object &a) {
    a.count++;
    return a;
}
Object operator ++(Object &a, int) {
    Object now(a.count);
    ++a;
    return now;
}
Object operator +(const Object &a, const Object &b) {
    return Object(a.count + b.count);
}

int main() {
    Object a, b;
    // input 1 2
    cin>>a>>b;
    // a = 1, b = 2
    cout<<"a = "<<a<<", b = "<<b<<endl;
    a++;
    ++b;
    // a = 2, b = 3
    cout<<"a = "<<a<<", b = "<<b<<endl;
    Object c = a+b;
    // a + b = 5
    cout<<"a + b = "<<c<<endl;
    return 0;
}
```

**注意事项：**

- 前置单目运算符重载为成员函数时没有形参，而后置单目运算符重载为成员函数时需要有一个`int`型的形参
- 输入运算符“>>”和输出运算符“<<”的第一操作数必须是流类对象而非本类对象，所以只能以**友元函数**的形式重载运算符
- 赋值运算符“=”只能被重载为**成员函数**，而且是不能被继承的
- 函数调用运算符“()”可以是带一个或多个右操作数的运算符函数，函数调用运算符重载只能使用**成员函数**



### 虚函数

虚函数是**动态绑定**的基础，虚函数必须是非静态的成员函数，虚函数经过派生之后，在类族中就可以实现运行过程中的多态

根据赋值兼容规则，可以使用派生类的对象代替基类对象。但是当使用基类指针指向派生类对象时，访问到的只是从基类继承过来的同名成员，派生类的出现解决了这个问题，当该同名函数被声明为虚函数时，通过基类指针访问派生类对象同名函数时，得到的是其派生类重写后的同名函数，使属于不同派生类的不同对象产生不同的行为，从而实现运行中的多态

格式：`virtual 函数类型 函数名(形参表)`

**虚函数声明只能出现在类定义中的函数原型声明中，不能在成员函数实现的时候**

**运行过程中的多态**需要满足的条件：

- 类之间满足**赋值兼容规则**
- 要声明**虚函数**
- 由成员函数来调用或者是通过指针、引用来访问虚函数

如果是通过对象名来访问虚函数，则绑定在编译过程中就可以进行（静态绑定），而无需在运行过程中进行

基类指针如何访问被覆盖的基类虚函数？**通过域解析符`::`进行限定**

**几个常见问题：**

- 当基类构造函数调用虚函数时，不会调用派生类的虚函数，因为基类的构造函数调用先于派生类的构造函数调用，当基类构造函数调用时，此时派生类还没有形成一个完整对象
- 当基类析构函数调用虚函数时，不会调用派生类的虚函数，因为基类的析构函数调用晚于派生类的构造函数调用，当基类析构函数调用时，此时派生类对象已经析构完毕

- 虚函数一般不声明为内联函数，因为对虚函数的调用需要动态绑定，而对内联函数的处理是静态的，所以虚函数一般不能以内联函数处理。但将虚函数声明为内联函数也不会引起错误
- 同名虚函数在基类和派生类中其函数原型完全一致，即函数的返回值类型、函数名、形式参数表完全相同，否则无法通过虚函数实现动态多态性
- **对象切片：使用派生类对象复制构造基类对象的行为**。在这种情况下，派生类从基类中继承的成员会被复制，派生类中新增的成员将被忽略，当然，也没有空间给这些成员赋值

#### 虚析构函数

**在C++中，不能声明虚构造函数，但是可以声明虚析构函数**

格式：`virtual ~类名()`

如果一个类的析构函数是虚函数，那么由它派生而来的所有子类的析构函数也是虚函数。析构函数设置为虚函数之后，在使用指针引用时可以动态绑定，实现运行时的多态，保证使用基类类型的指针就能够调用适当的析构函数针对不同的对象进行清理工作



### 纯虚函数与抽象类

抽象类是一个特殊的类，处于类层次的上层，一个抽象类自身无法实例化，也就是说我们无法定义一个抽象类的对象，只能通过继承机制，生成抽象类的非抽象派生类，然后进行实例化

#### 纯虚函数

纯虚函数是一个在基类中声明的虚函数，在基类中没有给出具体的操作，要求其派生类给出各自的定义

**格式：**`virtual 函数类型 函数名(参数表)=0`

**细节：**在基类中其实可以给出纯虚函数的实现，但是即使给出实现，其派生类也要进行覆盖重写，否则无法实例化，**当基类的析构函数被声明为纯属函数时必须给出实现**

#### 抽象类

带有纯虚函数的类被称为抽象类，其主要作用是为它的类族定义一个公共的接口，使他们能够更加有效地发挥多态特性。**抽象类不可以被实例化**

当其派生类给出基类中所有纯虚函数的实现之后，该派生类将不再是一个抽象类，此时可以被实例化；但是当没有实现所有纯虚函数时，其派生类依然为一个抽象类



## 群体类和群体数据组织

**基本数据类型**是C++编译系统预定义的，而自定义类型的数据是由多个基本类型或自定义类型的元素组成的，称为**群体数据**

对于群体数据，仅有系统预定义的操作是不够的，在很多情况下，还需要设计与某些具体问题相关的特殊操作，并按照面向对象的方法将数据与操作封装起来，这就是**群体类**

群体的两种类型：

- **线性群体**：元素按顺序排列有序

- **非线性群体**：不用位置顺序来标识元素

### 函数模板与类模板

模板是C++支持参数化程序设计的工具，通过它可以实现**参数化多态性**

**参数化多态性**：指将程序所处理的对象的类型参数化，使得一段程序可以用于处理多种不同类型的对象

#### 函数模板

定义形式：

```c++
/*
template<模块参数表>     模块参数表：class(或typename) 
类型名 函数名(参数表) {
    函数体的定义
}
*/
template<class T>
T abs(T x) {
    return x < 0 ? -x:x;
}
```

函数模板与重载是密切相关的，从函数模板产生的相关函数都是同名的，编译器用重载的方法调用相应的函数

函数模板与函数的区别：

1. 函数在编译时不会产生任何目标代码，只有模板生成的实例会生成目标代码
2. 被多个源文件引用的函数模板，应当连同函数体一同放在头文件中，而不能像普通函数那样只将声明放在头文件中
3. 函数指针也只能指向模板的实例，不能指向模板本身

#### 类模板

使用类模板使用户可以为类定义一种模式，使得类中的某些数据成员、某些成员函数的参数、返回值或局部变量能取任何类型（包括系统预定义和用户自定义的）

定义格式：

```c++
template<模板参数表>
class 类名 {
    类成员声明
}
```

如果需要在类模板外定义其成员函数，则要采用以下的形式：

```c++
template<模板参数表>
类型名 类名<模板参数标识符列表>::函数名(参数表)
```

类模板的使用：

```c++
// 模板名<模板参数表> 对象名1,...,对象名n;
vector<int> v;
```



### 线性群体

线性群体中的元素次序与其位置关系是对应的，在线性群体中，又可按照访问元素的不同方法分为**直接访问**、**顺序访问**和**索引访问**

对可直接访问的线性群体，我们可以直接访问群体中的任何一个元素，而不必访问该元素之前的元素

对顺序访问的线性群体，只能按照元素的排列顺序从头开始依次访问各个元素

数组、链表、栈、队列



## 泛型程序设计与C++标准模板库

泛型程序设计，就是编写不依赖于具体数据类型的程序，在C++中，模板是泛型程序设计的主要工具

泛型程序设计的思想是将算法从特定的数据结构中抽象出来，使算法成为通用的、可以作用于各种不同的数据结构

以函数模板形式实现的通用算法与各种通用**容器**结合，提高了软件的复用性

我们可以用**概念**来描述泛型程序设计中作为参数的数据类型所需具备的功能，这里的**”概念“**是泛型程序设计的一个术语，它的内涵是这些功能，它的外延是具备这些功能的所有数据类型

具备一个概念所需要功能的数据类型称为这一概念的一个**模型**

对于两个不同的概念A和B，如果概念A所需求的所有功能也是概念B所需求的功能（即概念B的模型一定是概念A的模型），那么就说概念B是概念A的子模型

#### STL的四种基本组件：

- 容器
  - 容器是容纳、包含一组元素的对象
  - 容器类库中包括7种基本容器：vector、deque、list、set、mutiset、map和mutimap
- 迭代器
  - 迭代器提供了顺序访问容器中每个元素的方法
  - 对迭代器可以使用++运算符来获得指向下一个元素的迭代器，可以使用*运算符访问每一个迭代器所指向的元素，部分迭代器允许通过--运算符来获得上一个元素的迭代器
  - 使用独立于STL容器的迭代器，需要包含头文件\<itertor\>
- 函数对象
  - 函数对象是一个行为类似函数的对象，对它可以像调用函数一样调用
  - 任何普通的函数和重载了”()“运算符的类的对象都可以作为函数对象使用，函数对象是泛化的函数
  - 使用STL的函数对象，需要包含头文件\<functional\>
- 算法
  - STL包括70多个算法，包括查找、排序、消除、计数、比较、变换、置换和容器管理
  - 这些算法的一个最重要的特性就是它们的统一性，并且可以广泛用于不同的对象和内置的数据类型
  - 使用STL的算法，需要包含头文件\<algorithm\>



## 流类库与输入输出

### 流的概念

在C++中，将数据从一个对象到另一个对象的流动抽象为“流”，从流中获取数据的操作称为提取操作，向流中添加数据的操作称为插入操作，数据的输入与输出就是通过I/O流来实现的

当程序与外界环境进行信息交换时，存在着两种对象，一个是程序中的对象，另一个是文件对象

**流是一种抽象，它负责在数据的生产者和数据的消费者之间建立联系，并管理数据的流动**

流涉及的范围很广，凡是数据从一个地方传输到另一个地方的操作都是流的操作，像网络数据交换、进程数据交换等都是流操作，流操作也可以针对一个字符串进行，**一般意义下的读操作在流数据抽象中被称为（从流中）提取，写操作被称为（向流中）插入**



### 输出流

一个输出流对象是信息流动的目标，最重要的3个输出流是ostream，ofstream和ostringstream

预先定义的ostream类对象用来完成向标准设备的输出：

- cout是标准输出流
- cerr是标准错误输出流，没有缓冲，发送给它的内容立即被输出
- clog类似于cerr，但是有缓冲，缓冲区满时被输出



### 输入流

一个输入流对象是数据流出的源头，3个最重要的输入流类是istream，ifstream和istringstream

预先定义的istream对象cin用来挖成从标准输入设备的输入

ifstream支持磁盘文件输入，很多格式化选项和成员函数都可以应用于ifstream对象，基类ios和istream的所有功能都包括在ifstream中

```c++
//读取一行赋值给str
getline(cin, str);
//一个巧妙的重定向输入输出
freopen("in.in", "r", stdin);//从in.in文件中读取输入
freopen("out.out", "w", stdout);//向out.out文件中写入输出
```



### 输入输出流

一个iostream对象可以是数据的源或目的，有两个重要的I/O流类都是从iostream派生的，它们是fstream和stringstream，这些类继承了前面描述的istream和ostream类的功能

fstream支持磁盘文件输入和输出，如果需要在同一个程序中从一个特定磁盘文件读并写到该磁盘文件，可以构造一个fstream对象，**一个fstream对象是有两个逻辑子流的单个流，两个子流一个用于输入，另一个用于输出**

stringstream类支持面向字符串的输入和输出，可以用于对同一个字符串的内容交替读写，同样是由两个逻辑子流构成



## 异常处理

由于环境条件和用户操作的正确性是没有百分之百保证的，所以在设计程序时，就要充分考虑到各种意外情况，并给与恰当的处理

### 异常处理的基本思想

程序运行中的有些错误是可以预料但不可避免的，例如内存空间不足、硬盘上的文件被移动、打印机未连接好等由系统运行环境造成的错误。这时要力争做到允许用户排除环境错误，继续运行程序；至少要给出适当的提示信息，这就是异常处理程序的任务

C++的异常处理机制使得异常的引发和处理不必在同一函数中，这样底层的函数可以着重解决具体问题，而不必过多地考虑对异常的处理，上层调用者可以在适当的位置设计对不同类型异常的处理



### C++异常处理的实现

C++语言提供对处理异常情况的内部支持，**try，throw和catch语句就是C++语言中用于实现异常处理的机制**

如果某段程序中发现了自己不能处理的异常，就可以使用throw表达式抛掷这个异常，将它抛掷给调用者

throw的操作数表示异常类型语法上与return语句的操作数相似，如果程序中有多种要抛掷的异常，应该用不同的操作数类型来相互区别



### 异常处理的过程

1. 程序通过正常的顺序执行到达try语句，然后执行try块内的保护段
2. 如果在保护段执行期间没有引起异常，那么跟在try块后的catch子句就不执行；程序从异常被抛掷的try块后跟随的最后一个catch子句后面的语句继续执行下去
3. 程序执行到一个throw表达式时，**一个异常对象会被创建**；若异常的抛出点本身在一个try子句内，则该try语句后的catch子句会按顺序检查异常类型是否与声明的类型匹配；若异常抛出点本身不在任何try子句内，或抛出的异常与各个catch子句所声明的类型皆不匹配，则结束当前函数的执行，回到当前函数的调用点，把调用点作为异常的抛出点，然后重复这一过程。此处理继续下去，直到异常成功被一个catch语句捕获
4. 如果始终未找到与被抛掷异常匹配的catch子句，最终main函数会结束执行，则运行库函数**terminate**将被自动调用，而函数terminate的默认功能是终止程序
5. 如果找到了一个匹配的catch子句，则catch子句后的符合语句会被执行，复合语句执行完毕后，当前的try块（包括try子句和一系列catch子句）即执行完毕



### 异常处理的语法

表达式语法：

```c++
// throw表达式语法
throw 表达式
    
// try块语法
try 
    复合语句
catch (异常声明)
    复合语句
catch (异常声明)
    复合语句
    ...
```

**注意事项：**

- catch语句可以有多个，分别对应不同返回类型的异常

- 如果异常类型声明是一个省略号(...)，catch子句便处理所有类型的异常，这段处理程序必须是try块的最后一段处理程序，否则会报错

  `error: '...' handler must be the last handler for its try block[-fpermissive]`

- catch子句的异常声明中也允许不给出异常参数名称

- 为了加强程序的可读性，使函数的用户能够方便地知道所使用的函数会抛掷哪些异常，可以在函数的声明中列出这个函数可能抛掷的所有异常类型

  ```c++
  //该函数能够而且只能抛掷出类型为A,B,C,D及其子类型的异常
  void fun() throw(A, B, C, D);
  //该函数能够抛掷出任何类型的异常
  void fun();
  //该函数不抛掷任何类型的异常
  void fun() throw();
  
  /*
  如果一个函数抛出了他的异常接口声明所不允许抛出的异常时，unexpected函数会被调用，该函数的默认行为是调用terminate函数中止程序，当然用户也可以定义自己的unexpected函数，替换默认函数
  */
  ```

  

### 异常处理中的构造与析构

在程序中，找到一个匹配的catch异常处理后，如果catch子句的异常声明是一个**值参数**，则其初始化方式是**复制被抛掷的异常对象**；如果catch子句的异常声明是一个**引用**，则其初始化方式是**使该引用指向异常对象**

C++异常处理的真正功能，不仅在于它能够**处理各种不同类型的异常**，还在于它**具有为异常抛掷前构造的所有局部对象自动调用析构函数的能力**

异常被抛出后，从进入try块（与截获异常的catch子句相对应的那个try块）起，到异常被抛掷前，这期间在栈上构造（且尚未析构）的所有对象都会被**自动析构**，析构的顺序与构造的顺序相反，这一过程称为栈的**解旋**

```c++
#include<iostream>
#include<string>

using namespace std;

class MyExpection {
public:
    MyExpection(const string &message):message(message) {}
    ~MyExpection() {}
    const string &getMessage() const {
        return message;
    }

private:
    string message;
};

class Demo {
public:
    Demo() {cout << "Constructor of Demo" << endl;}
    ~Demo() {cout << "Destructor of Demo" << endl;}
};

void func() throw(MyExpection) {
    Demo d;
    cout << "Throw MyExpection in func()" << endl;
    throw MyExpection("exception thrown by func()");
}

int main() {
    cout << "In main function" << endl;
    try {
        func();
    } catch(MyExpection &e) {
        cout << "Caught an exception:" << e.getMessage() << endl;
    }
    cout << "Resume the exception of main()" << endl;
    return 0;
}
/*
Output:
    In main function
    Constructor of Demo
    Throw MyExpection in func()
    Destructor of Demo
    // 先解旋，后处理异常
    Caught an exception:exception thrown by func()
    Resume the exception of main()
*/
```



### 标准程序库异常处理

C++标准提供了一组标准异常类，这些类以基类Exception开始，标准程序库抛出的所有异常，都派生于该基类

该基类提供一个`what()`方法，用来返回错误信息：

```c++
virtual const char* what() const throw();
```

`runtime_error`和`logic_error`是一些具体的异常类的基类，它们分别表示两大异常：

- `logic_error`：可以在程序中被预先检测到的异常，能够被避免
  - out_of_range
  - length_error
  - invalid_argument
  - domain_error
- `runtime_error`：表示那些难以被预先检测的异常
  - underflow_error
  - overflow_error
  - range_error