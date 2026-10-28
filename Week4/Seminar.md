# Семинар 4: Функции. Предаване на параметри по стойност и по адрес

## Какво е функция?

**Функция** (function) е именувана група от инструкции, която изпълнява конкретна задача. Тя може да приема входни данни (**параметри**, parameters) и да връща резултат (**връщана стойност**, return value).

Защо ни трябват функции:

1. **Разделяне на логиката** – програмата се чете като поредица от ясни стъпки (`readInput`, `isValid`, `printResult`).
2. **Преизползване** (reuse) – пишем кода веднъж, извикваме го многократно.
3. **По-лесно тестване и дебъгване** – малките функции се проверяват поотделно.

### Синтаксис

```text
<тип_на_резултата> <име> (<тип1> <параметър1>, <тип2> <параметър2>, ...) {
    <тяло>
}
```

- **Тип на резултата** (return type) – какъв тип стойност връща функцията (`int`, `double`, `bool`, `char`, ...) или `void`, ако не връща нищо.
- **Име** (identifier) – по него извикваме функцията. Добра практика: глагол, който описва действието (`getLength`, `isPrime`, `printLine`).
- **Списък с параметри** – нула или повече, всеки с тип и име, разделени със запетая.
- **Тяло** – инструкциите, които се изпълняват при извикване.

```cpp
#include <iostream>

int sum(int a, int b) {   // a и b са параметри
    return a + b;
}

int main() {
    int x = 5, y = 7;
    int result = sum(x, y);           // x и y са аргументи (arguments)
    std::cout << result << std::endl; // 12
    std::cout << sum(1, sum(2, 3));   // 6 – резултатът от функция може да е аргумент
    return 0;
}
```

> [!NOTE]
> **Параметър** е променливата в дефиницията на функцията (`a`, `b`). **Аргумент** е конкретната стойност/израз, подадена при извикването (`x`, `y`, `2`, `sum(2, 3)`).

> [!TIP]
> В примерите пишем `std::cout`, а не `using namespace std;`. `using namespace std;` внася всички имена от стандартната библиотека в глобалния обхват и лесно води до конфликти – например ако напишем своя функция `swap`, `count` или `max`. В малки учебни програми е допустимо, но е добре да свикнете с `std::`.

---

## Операторът `return`

`return`:
- **прекратява** изпълнението на функцията веднага;
- **връща** стойност към мястото на извикване – извикването се „заменя" с резултата.

```cpp
int max(int a, int b) {
    return a > b ? a : b;
}
```

Кодът след изпълнен `return` не се изпълнява. Това позволява ранно излизане от функцията:

```cpp
#include <iostream>

void printEvenOrOdd(int num) {
    if (num % 2 == 0) {
        std::cout << "Even" << std::endl;
        return; // при void функция return само прекратява изпълнението
    }

    std::cout << "Odd" << std::endl;
}

int main() {
    printEvenOrOdd(4); // Even
    printEvenOrOdd(7); // Odd
}
```

### Функции без резултат – `void`

`void` е „празен тип". Функция с тип `void` не връща стойност – вика се заради ефекта си (печат, промяна на аргументи и т.н.). В нея може да има `return;` без стойност, но не и `return 5;`.

```cpp
#include <iostream>

void helloWorld() {
    std::cout << "Hello World!" << std::endl;
}

int main() {
    helloWorld();
    // int x = helloWorld(); // грешка: void функцията не връща стойност
}
```

> [!WARNING]
> Ако функция, която **не е** `void`, „изпадне" от края на тялото си, без да срещне `return`, поведението е **недефинирано** (undefined behavior). Компилаторът често дава само предупреждение (`-Wreturn-type`), а не грешка! Винаги проверявайте, че **всеки** път през функцията завършва с `return`. Компилирайте с `-Wall`.
>
> ```cpp
> int sign(int x) {
>     if (x > 0) return 1;
>     if (x < 0) return -1;
>     // забравен return 0; за x == 0  -> недефинирано поведение
> }
> ```

> [!NOTE]
> `main` е единственото изключение: ако стигне края си без `return`, автоматично се връща `0`.

### Guard clauses – ранно излизане вместо дълбоко влагане

Когато функция трябва да провери няколко условия за невалидни данни, вместо да влагаме `if`-ове, проверяваме грешните случаи в началото и излизаме веднага.

```cpp
// Дълбоко влагане – трудно за четене
double calculateDiscount(double price, int age, bool isMember) {
    double discount = 0.0;
    if (price > 0) {
        if (age >= 0) {
            if (isMember || age > 65) {
                if (price > 100) {
                    discount = price * 0.15;
                } else if (price > 50) {
                    discount = price * 0.10;
                } else {
                    discount = price * 0.05;
                }
            } else if (price > 100) {
                discount = price * 0.05;
            }
        } else {
            std::cout << "Invalid age!" << std::endl;
        }
    } else {
        std::cout << "Invalid price!" << std::endl;
    }
    return discount;
}
```

```cpp
// Guard clauses – същата логика, „плоска" структура
double calculateDiscount(double price, int age, bool isMember) {
    if (price <= 0) {
        std::cout << "Invalid price!" << std::endl;
        return 0.0;
    }
    if (age < 0) {
        std::cout << "Invalid age!" << std::endl;
        return 0.0;
    }
    if (!isMember && age <= 65) {
        return price > 100 ? price * 0.05 : 0.0;
    }

    if (price > 100) return price * 0.15;
    if (price > 50) return price * 0.10;
    return price * 0.05;
}
```

---

## Декларация и дефиниция

- **Декларация** (declaration, прототип) – казва на компилатора, че функция с такова име, тип на резултата и параметри **съществува**. Завършва с `;`, няма тяло. Имената на параметрите не са задължителни.
- **Дефиниция** (definition) – декларация + тяло, т.е. какво всъщност **прави** функцията.

Компилаторът чете файла отгоре надолу. Функция трябва да е поне **декларирана**, преди да бъде извикана.

```cpp
#include <iostream>

int multiply(int, int); // декларация

int main() {
    std::cout << multiply(3, 4) << std::endl; // 12 – компилаторът вече „знае" за multiply
    return 0;
}

int multiply(int a, int b) { // дефиниция
    return a * b;
}
```

> [!WARNING]
> - Без декларацията горе кодът **не се компилира**: в `main` името `multiply` още не е известно.
> - Ако функция е декларирана, но **никъде не е дефинирана**, програмата се компилира, но при свързването (linking) получаваме грешка от свързващия редактор (`undefined reference to 'multiply(int, int)'` при GCC, `Undefined symbols` при Clang) – стига функцията да се извиква.

Декларациите са полезни и когато две функции се извикват взаимно – тогава няма как и двете да са „отгоре".

---

## Обхват (scope) и време на живот

**Обхват** е частта от кода, в която дадено име е видимо. **Време на живот** (lifetime) е периодът, в който променливата реално съществува в паметта.

- **Локални променливи** – декларирани в тялото на функция или в блок `{ ... }`. Видими са от мястото на декларацията до края на блока. Създават се при влизане в блока и се унищожават при излизане.
- **Параметрите** на функцията са локални променливи на тази функция.
- **Глобални променливи** – декларирани извън всички функции. Видими са навсякъде след декларацията си и живеят през цялото изпълнение на програмата.

```cpp
#include <iostream>

int counter = 0; // глобална

void increment() {
    int step = 1;   // локална за increment
    counter += step;
}

int main() {
    increment();
    increment();
    std::cout << counter << std::endl; // 2
    // std::cout << step;              // грешка: step не е видима тук

    for (int i = 0; i < 3; i++) {
        int square = i * i;            // живее само в тялото на цикъла
    }
    // std::cout << i << square;       // грешка: и двете са извън обхват
}
```

### Засенчване (shadowing)

Ако във вътрешен блок декларираме име, което вече съществува отвън, вътрешното **засенчва** външното. Глобалното име можем да достъпим с `::име`.

```cpp
#include <iostream>

int x = 1; // глобална

int main() {
    int x = 10;                 // засенчва глобалната x
    {
        int x = 100;            // засенчва локалната x от main
        std::cout << x << " ";  // 100
    }
    std::cout << x << " ";      // 10
    std::cout << ::x << std::endl; // 1
}
```

> [!WARNING]
> Различни функции **не виждат** локалните променливи една на друга, дори имената да съвпадат. Ако `main` има `int n` и `f` има параметър `int n`, това са **две различни** променливи.

> [!TIP]
> Избягвайте глобални (неконстантни) променливи. Всяка функция може да ги промени и е трудно да се проследи кой какво е направил. Подавайте данните като параметри и връщайте резултат. Глобалните **константи** (`const int MAX_SIZE = 100;`) са напълно приемливи.

---

## Стекова рамка (интуитивно)

Локалните променливи и параметрите се пазят в област от паметта, наречена **стек** (stack). Тя работи на принципа **LIFO** (Last In, First Out) – последното сложено се маха първо, като купчина чинии.

При **всяко извикване** на функция върху стека се слага нова **стекова рамка** (stack frame). В нея се пазят:
- параметрите на функцията (вече копирани/свързани с аргументите);
- **адресът за връщане** (return address) – откъде да продължи програмата, когато функцията приключи;
- локалните променливи на функцията.

Когато функцията приключи (`return` или край на тялото), рамката ѝ се **премахва** и всички нейни локални променливи изчезват. Изпълнението продължава в рамката отдолу – на извикващата функция.

```cpp
void bar() { int b = 3; }

void foo() {
    int f = 2;
    bar();
}

int main() {
    int m = 1;
    foo();
}
```

```text
 main() започва    main вика foo()    foo вика bar()    bar приключи     foo приключи
                                     +-------------+
                                     | bar: b = 3  |
                   +-------------+   +-------------+   +-------------+
                   | foo: f = 2  |   | foo: f = 2  |   | foo: f = 2  |
+-------------+    +-------------+   +-------------+   +-------------+   +-------------+
| main: m = 1 |    | main: m = 1 |   | main: m = 1 |   | main: m = 1 |   | main: m = 1 |
+-------------+    +-------------+   +-------------+   +-------------+   +-------------+
```

Изводи от тази картина:
1. Всяко извикване има **собствени** копия на параметрите и локалните си променливи – затова промяна на параметър по стойност не засяга аргумента (вижте следващия раздел).
2. След като функцията приключи, локалните ѝ променливи **не съществуват** – затова не бива да връщаме референция към локална променлива.
3. Стекът е ограничен (обикновено няколко MB). Безкрайна верига от извиквания (`f` вика `g`, `g` вика `f`, ...) го препълва – **stack overflow**.

---

## Предаване на параметри по стойност (копие)

По подразбиране C++ предава аргументите **по стойност** (pass by value): в стековата рамка на функцията се създава **нова** променлива – параметърът – и в нея се **копира** стойността на аргумента. Каквото и да правим с параметъра, оригиналът не се променя.

```cpp
#include <iostream>

void f(int n) {
    n++;            // увеличава копието
}

int main() {
    int n = 4;
    f(n);
    std::cout << n << std::endl; // 4
}
```

```text
 +---------------------+
 | f:    n = 4 -> 5    |   <- копие, изчезва при край на f
 +---------------------+
 | main: n = 4         |   <- оригиналът не е засегнат
 +---------------------+
```

Предаването по стойност е **безопасно** (функцията не може случайно да развали данните на извикващия) и е правилният избор за малки типове (`int`, `double`, `char`, `bool`), когато не искаме да ги променяме.

Аргументът може да е **произволен израз** – литерал, сума, резултат от друга функция: `f(5)`, `f(a + b)`, `f(sum(1, 2))`.

---

## Референции

**Референция** (reference) е **алтернативно име (псевдоним, alias)** на вече съществуваща променлива. Декларира се с `&` след типа.

```cpp
#include <iostream>

int main() {
    int x = 10;
    int& ref = x;   // ref е друго име за x

    ref += 5;       // променяме x чрез ref
    std::cout << x << std::endl;   // 15

    x = 100;
    std::cout << ref << std::endl; // 100 – ref и x са една и съща променлива
}
```

Правила:
- Референцията **трябва да се инициализира** при декларацията: `int& r;` е грешка.
- След инициализацията тя **не може да бъде пренасочена** към друга променлива. `ref = y;` не „пренасочва" `ref`, а **присвоява** стойността на `y` на `x`.
- Типът трябва да съвпада: `double d = 1.5; int& r = d;` е грешка.
- Неконстантна референция не може да се върже към литерал или временна стойност: `int& r = 5;` е грешка.

---

## Предаване по референция („по адрес")

Ако параметърът е референция, функцията **не получава копие** – параметърът става псевдоним на самия аргумент. Всяка промяна вътре във функцията се отразява на оригинала.

Това често се нарича **предаване по адрес**: функцията работи с паметта (адреса) на оригиналната променлива, а не със своя собствена. В C++ най-удобният и безопасен начин за това са референциите.

```cpp
#include <iostream>

void incrementCopy(int n)     { n++; }
void incrementRef(int& n)     { n++; }

int main() {
    int x = 5;
    incrementCopy(x);
    std::cout << x << std::endl; // 5
    incrementRef(x);
    std::cout << x << std::endl; // 6
}
```

```text
 incrementCopy(x):              incrementRef(x):
 +------------------+           +------------------+
 | n = 5 -> 6       |           | n  -----------+  |   n е само друго име
 +------------------+           +---------------|--+
 | main: x = 5      |           | main: x = 5 -> 6 |
 +------------------+           +------------------+
```

### Класически пример: `swap`

```cpp
#include <iostream>

void swapByValue(int a, int b) { // НЕ работи – разменя копията
    int temp = a;
    a = b;
    b = temp;
}

void swap(int& a, int& b) {      // работи – a и b са псевдоними на аргументите
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swapByValue(x, y);
    std::cout << x << " " << y << std::endl; // 1 2
    swap(x, y);
    std::cout << x << " " << y << std::endl; // 2 1
}
```

### Кога да подаваме по референция?

1. **Когато функцията трябва да промени аргумента** – `swap`, `readInput(int& day, int& month, int& year)`, нормализиране на стойност и т.н.
2. **Когато трябва да „върнем" повече от една стойност** – функцията връща само една стойност с `return`, но може да попълни няколко параметъра-референции („изходни параметри", output parameters):

```cpp
#include <iostream>

// Връща false, ако делението е невъзможно; иначе попълва частно и остатък
bool divide(int a, int b, int& quotient, int& remainder) {
    if (b == 0) {
        return false;
    }
    quotient = a / b;
    remainder = a % b;
    return true;
}

int main() {
    int q, r;
    if (divide(17, 5, q, r)) {
        std::cout << q << " " << r << std::endl; // 3 2
    }
}
```

3. **За избягване на копиране на „големи" данни** – вижте `const` референции по-долу.

> [!WARNING]
> Към параметър `int&` можем да подадем **само променлива** (lvalue). `swap(x, 5)` и `swap(x, y + 1)` не се компилират – няма „оригинал", който да бъде променен.

> [!NOTE]
> **Указатели** (pointers). В C++ съществува и друг механизъм за „предаване по адрес" – чрез указатели (`int* p = &x;`, `void f(int* p)`), който е наследен от езика C. Указателят е отделна променлива, която пази адрес. Ще ги разгледаме подробно по-късно в курса (около Седмица 8). Засега: **референцията може да се мисли като удобен, винаги валиден псевдоним**, а компилаторът сам се грижи за адресите.

---

## `const` референции

`const T&` означава: „подай ми оригинала, без да го копираш, но **обещавам да не го променям**".

```cpp
#include <iostream>

void print(const int& value) {
    std::cout << value << std::endl;
    // value++; // грешка: value е само за четене
}

int main() {
    int x = 42;
    print(x);      // OK
    print(5);      // OK – const референция може да се върже и към литерал/временна стойност
    print(x + 1);  // OK
}
```

Защо `const &`:
- **Без копиране** – има значение за големи обекти (низове, структури, класове, които ще учим по-късно). За `int`, `char`, `double` копието е евтино и `const &` не носи полза – там подавайте **по стойност**.
- **Безопасност** – компилаторът гарантира, че функцията няма да промени аргумента.
- **Гъвкавост** – приема и литерали, и изрази, за разлика от `T&`.

Обобщение на избора:

| Искаме... | Параметър | Пример |
|-----------|-----------|--------|
| само да прочетем малка стойност | по стойност `T` | `bool isPrime(int n)` |
| да променим аргумента / да върнем няколко резултата | по референция `T&` | `void swap(int& a, int& b)` |
| само да прочетем „голям" обект без копиране | `const T&` | ще го ползваме с `std::string`, структури и др. |

> [!NOTE]
> `const` пред параметър **по стойност** (`int f(const int n)`) само забранява промяна на копието вътре във функцията. За извикващия няма разлика – затова `f(int)` и `f(const int)` са **една и съща функция** (виж overloading).

### Връщане на референция (за любопитните)

Функция може да връща и референция: `int& getValue(int& num) { return num; }` – тогава `getValue(x) = 10;` променя `x`. Това е полезно по-нататък (при класове), но крие опасност:

> [!WARNING]
> **Никога не връщайте референция към локална променлива!** След `return` стековата рамка изчезва и референцията сочи към несъществуващ обект – **недефинирано поведение** (dangling reference).
>
> ```cpp
> int& bad() {
>     int local = 42;
>     return local; // компилаторът предупреждава; резултатът е безсмислен
> }
> ```

---

## Претоварване на функции (function overloading)

В C++ можем да имаме **няколко функции с едно и също име**, стига да се различават по **списъка с параметри** – брой и/или типове (и подредбата им). Компилаторът избира подходящата версия по аргументите при извикването.

```cpp
#include <iostream>

int add(int a, int b)          { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c)   { return a + b + c; }

int main() {
    std::cout << add(5, 10) << std::endl;     // 15   -> add(int, int)
    std::cout << add(5.5, 10.2) << std::endl; // 15.7 -> add(double, double)
    std::cout << add(1, 2, 3) << std::endl;   // 6    -> add(int, int, int)
}
```

Как компилаторът избира:
1. Търси **точно съвпадение** на типовете.
2. Ако няма – опитва **повишаване** (promotion): `char`/`bool` → `int`, `float` → `double`.
3. Ако няма – опитва **стандартни преобразувания** (`int` → `double`, `double` → `int`, ...).
4. Ако не намери нищо – грешка при компилация. Ако намери **повече от една еднакво добра** версия – грешка за **двусмислие** (ambiguous call).

```cpp
#include <iostream>

void f(int x)    { std::cout << "int "; }
void f(double x) { std::cout << "double "; }
void f(char x)   { std::cout << "char "; }

int main() {
    f(5);     // int     – точно съвпадение
    f(5.0);   // double  – точно съвпадение
    f('5');   // char    – точно съвпадение
    f(5.0f);  // double  – float се повишава до double
    f(true);  // int     – bool се повишава до int
}
```

> [!WARNING]
> **Не може** да се претоварва само по типа на резултата. Двете функции по-долу имат еднакви параметри – това е **повторна дефиниция** (redefinition) и кодът не се компилира:
> ```cpp
> int getValue()    { return 10; }
> double getValue() { return 10.5; } // грешка
> ```
> Същото важи за `void f(int)` и `void f(const int)` – `const` на параметър по стойност не прави функцията различна.

> [!WARNING]
> **Двусмислие** възниква, когато две версии са еднакво „далеч" от аргументите:
> ```cpp
> void g(long x)   { }
> void g(double x) { }
> // g(5);  // грешка: int -> long и int -> double са еднакво добри преобразувания
>
> void h(int a, double b) { }
> void h(double a, int b) { }
> // h(1, 2); // грешка: всяка версия изисква по едно преобразуване
> ```

> [!TIP]
> Претоварвайте само функции, които правят **едно и също** нещо за различни типове или различен брой данни (`abs(int)` / `abs(double)`, `max` от 2 или 3 числа). Ако правят различни неща – дайте им различни имена.

---

## Параметри по подразбиране (default arguments)

Можем да зададем стойност по подразбиране на един или повече параметри. Ако при извикване не подадем аргумент за тях, се използва тази стойност.

```cpp
#include <iostream>

void printLine(int length = 10, char symbol = '-') {
    for (int i = 0; i < length; i++) {
        std::cout << symbol;
    }
    std::cout << std::endl;
}

int main() {
    printLine();         // ----------
    printLine(5);        // -----
    printLine(3, '*');   // ***
}
```

Правила:
1. Параметрите със стойност по подразбиране трябва да са **в края** на списъка. `void f(int a = 1, int b);` не се компилира.
2. Аргументите се попълват **отляво надясно** и не могат да се прескачат: при `printLine(int length = 10, char symbol = '-')` няма как да зададем само `symbol`.
3. Стойностите по подразбиране се пишат **веднъж** – обикновено в декларацията (ако има такава), а не и в дефиницията.

```cpp
#include <iostream>

void print(int a, int b = 5, char c = 't') {
    std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
    print(4);       // 4 5 t
    print(3, 6);    // 3 6 t
    print(3, '0');  // 3 48 t  <- '0' попълва b (втория параметър), превръща се в int: кодът на '0' е 48
}
```

> [!WARNING]
> Параметрите по подразбиране и overloading-ът могат да се „сблъскат":
> ```cpp
> void show(int a)            { }
> void show(int a, int b = 0) { }
> // show(1); // грешка: двусмислие – и двете версии пасват
> ```

---

## Пример: преизползваеми функции

### Проверка за просто число

Пример от семинара, **поправен** – оригиналната версия връщаше `false` за 2, `true` за 1 и `true` за 9 (условието беше `i * i < number` вместо `<=`).

```cpp
#include <iostream>

bool isPrime(int number) {
    if (number < 2) {
        return false;          // 0, 1 и отрицателните не са прости
    }
    if (number == 2) {
        return true;
    }
    if (number % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= number; i += 2) { // <= е важно: иначе 9, 25, 49 ... минават за прости
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    for (int i = 0; i <= 30; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl; // 2 3 5 7 11 13 17 19 23 29
}
```

### Случайни числа в интервал

```cpp
#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time
#include <iostream>

int randomBetween(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

int main() {
    std::srand(std::time(0)); // „разбъркваме" генератора веднъж, в началото на програмата

    for (int i = 0; i < 5; i++) {
        std::cout << randomBetween(1, 6) << " "; // хвърляне на зар
    }
    std::cout << std::endl;
}
```

> [!NOTE]
> `std::rand()` връща псевдослучайно число в `[0, RAND_MAX]`. Без `std::srand(...)` всяко пускане дава **същата** редица. `std::rand` е достатъчен за упражнения; в реален код се ползва `<random>`. С `randomBetween` можете да направите проста игра на Blackjack (вижте Бонус задачите).

---

## Какво ще отпечата?

**1.** Какво ще се отпечата?
```cpp
#include <iostream>

void f(int num)  { num += 7; }
void g(int& num) { num += 7; }

int main() {
    int num = 3;
    f(num);
    std::cout << num << std::endl;
    g(num);
    std::cout << num << std::endl;
}
```
<details><summary>Отговор</summary>

```text
3
10
```
`f` променя копие, `g` – оригинала.
</details>

**2.** Какво ще се отпечата?
```cpp
#include <iostream>

int main() {
    f();
    return 0;
}

void f() {
    std::cout << "f()" << std::endl;
}
```
<details><summary>Отговор</summary>

**Не се компилира** – в `main` функцията `f` още не е декларирана. Решение: добавете `void f();` над `main` или преместете дефиницията отгоре.
</details>

**3.** Какво ще се отпечата?
```cpp
#include <iostream>

int num1 = 3;

int foo1(int num2) {
    std::cout << num2;
    return 4 * num1;
}

int main() {
    int num1 = 1;
    std::cout << num1 << std::endl << foo1(num1);
}
```
<details><summary>Отговор</summary>

```text
1
112
```
В `main` локалната `num1` (= 1) засенчва глобалната. `foo1` получава 1 и го печата, но в `foo1` името `num1` е **глобалната** променлива (= 3), затова връща 12. Отпечатва се `1`, нов ред, после `1` (от `foo1`) и `12`. (От C++17 операндите на `<<` се изчисляват отляво надясно.)
</details>

**4.** Какво ще се отпечата?
```cpp
#include <iostream>

int func(int param = 10) {
    return param;
}

int main() {
    std::cout << func() << std::endl;
    std::cout << func(0) << std::endl;
}
```
<details><summary>Отговор</summary>

```text
10
0
```
</details>

**5.** Какво ще се отпечата?
```cpp
#include <iostream>

void printCharNTimes(char c = '*', int n) {
    for (int i = 0; i < n; i++) {
        std::cout << c;
    }
}

int main() {
    printCharNTimes('-', 10);
}
```
<details><summary>Отговор</summary>

**Не се компилира** – параметър със стойност по подразбиране е преди параметър без такава. Правилно: `void printCharNTimes(int n, char c = '*')`.
</details>

**6.** Какво ще се отпечата?
```cpp
#include <iostream>

void f(int p)    { std::cout << p; }
void f(double p) { std::cout << p; }
int f(int p)     { return p; }

int main() {
    f(10);
    f(10.5);
}
```
<details><summary>Отговор</summary>

**Не се компилира** – `void f(int)` и `int f(int)` се различават само по типа на резултата. Това не е overloading, а повторна дефиниция.
</details>

**7.** Какво ще се отпечата?
```cpp
#include <iostream>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swap(x, y);
    std::cout << x << " " << y << std::endl;
}
```
<details><summary>Отговор</summary>

```text
1 2
```
Параметрите са копия – размяната става само в стековата рамка на `swap`.
</details>

**8.** Какво ще се отпечата?
```cpp
#include <iostream>

void h(int& a, int& b) {
    a = a + b;
    b = a - b;
}

int main() {
    int x = 3, y = 5;
    h(x, y);
    std::cout << x << " " << y << std::endl;

    int z = 3;
    h(z, z);
    std::cout << z << std::endl;
}
```
<details><summary>Отговор</summary>

```text
8 3
0
```
При `h(z, z)` и `a`, и `b` са псевдоними на **една и съща** променлива `z`: `a = 3 + 3` прави `z = 6`, после `b = a - b` е `6 - 6`, т.е. `z = 0`.
</details>

**9.** Какво ще се отпечата?
```cpp
#include <iostream>

void f(int x)    { std::cout << "int "; }
void f(double x) { std::cout << "double "; }

int main() {
    f('a');
    f(3.14f);
    f(7 / 2);
    f(7 / 2.0);
}
```
<details><summary>Отговор</summary>

```text
int double int double
```
`char` → `int` и `float` → `double` са повишавания (promotion). `7 / 2` е `int` (3), `7 / 2.0` е `double`.
</details>

**10.** Какво ще се отпечата?
```cpp
#include <iostream>

int x = 1;

void g() { x++; }

int main() {
    int x = 10;
    g();
    {
        int x = 100;
        x++;
    }
    std::cout << x << " " << ::x << std::endl;
}
```
<details><summary>Отговор</summary>

```text
10 2
```
`g` вижда само глобалната `x`. Вътрешната `x = 100` живее само в блока.
</details>

**11.** Какво ще се отпечата?
```cpp
#include <iostream>

void increment(const int& value) {
    value++;
}

int main() {
    int a = 5;
    increment(a);
    std::cout << a << std::endl;
}
```
<details><summary>Отговор</summary>

**Не се компилира** – `value` е `const` референция и не може да бъде променяна.
</details>

**12.** Какво ще върне функцията?
```cpp
double f() {
    double num1 = 4;
    double num2 = 4 / 7;
    return (num2-- = ++num1 + 2);
}
```
<details><summary>Отговор</summary>

**Не се компилира** – `num2--` (постфиксен) връща временна стойност (rvalue), на която не може да се присвоява. (Ако беше `--num2`, щеше да се компилира. Забележете също, че `4 / 7` е целочислено деление и дава `0`.)
</details>

**13.** Какво ще се отпечата?
```cpp
#include <iostream>

void print(int a, int b = 5, char c = 't') {
    std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
    print(3, '0');
}
```
<details><summary>Отговор</summary>

```text
3 48 t
```
`'0'` попълва **втория** параметър `b` (тип `int`) – кодът на символа `'0'` е 48.
</details>

**14.** Какво ще се отпечата?
```cpp
#include <iostream>

void h();
void g() { h(); }
void f() { g(); }
void h() { f(); }

int main() {
    f();
}
```
<details><summary>Отговор</summary>

Компилира се, но веригата `f → g → h → f → ...` никога не спира. Всяко извикване добавя нова стекова рамка, докато стекът се препълни – **stack overflow** и програмата се срива. (Без декларацията `void h();` кодът изобщо не би се компилирал.)
</details>

---

## Ресурси

- learncpp.com – [Introduction to functions](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/), [Function return values](https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/), [Introduction to local scope](https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/), [Forward declarations](https://www.learncpp.com/cpp-tutorial/forward-declarations-and-definitions/)
- learncpp.com – [Pass by lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/), [Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)
- learncpp.com – [Introduction to function overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/), [Default arguments](https://www.learncpp.com/cpp-tutorial/default-arguments/)
- learncpp.com – [The stack and the heap](https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/)
- cppreference – [Functions](https://en.cppreference.com/w/cpp/language/functions), [Reference declaration](https://en.cppreference.com/w/cpp/language/reference), [Overload resolution](https://en.cppreference.com/w/cpp/language/overload_resolution), [Default arguments](https://en.cppreference.com/w/cpp/language/default_arguments), [Scope](https://en.cppreference.com/w/cpp/language/scope)
