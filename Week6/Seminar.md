# Семинар 6: Масиви и функции

## 1. Подаване на масив във функция

В Седмица 4 видяхме, че обикновените параметри се подават **по стойност** (by value) – функцията получава **копие** и промените в него не се виждат навън. При масивите е различно:

> Когато подаваме масив на функция, **не се копират елементите**. Функцията получава само **адреса на първия елемент** – казваме, че масивът „се разпада“ (array decay) до адрес.

Затова функцията работи директно върху **оригиналния** масив и промените се виждат в извикващата функция.

```cpp
#include <iostream>

void increment(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]++;            // променя ОРИГИНАЛНИЯ масив
    }
}

void incrementNumber(int x) {
    x++;                     // променя само КОПИЕТО
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    int number = 10;

    increment(arr, 4);
    incrementNumber(number);

    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";   // 2 3 4 5
    }
    std::cout << std::endl << number << std::endl; // 10
    return 0;
}
```

Синтаксис:

- При **декларацията** на параметъра пишем празни квадратни скоби: `int arr[]`.
- При **извикването** подаваме само името на масива, **без скоби**: `increment(arr, 4)`, а не `increment(arr[], 4)` или `increment(arr[4], 4)` (последното подава един елемент – и то извън масива!).

> [!NOTE]
> Интуитивно: масивът в паметта е „блок от кутийки една до друга“. На функцията казваме само **къде започва блокът**. Функцията не знае колко са кутийките – затова трябва да ѝ кажем отделно. Точно какво е „адрес“ и как се работи с него ще видим подробно в Седмици 8–9 (указатели). Засега е достатъчно да запомните: **масивите се подават „по адрес“, а не по стойност**.

> [!TIP]
> Число, записано в скобите на параметъра (`void f(int arr[10])`), се **игнорира** от компилатора – `f` може да бъде извикана с масив с произволна дължина. Затова пишем `int arr[]` и подаваме размера отделно.

> [!WARNING]
> Функция **не може да върне масив** с `return` (`int[] f()` не е валиден C++). Ако функцията трябва да „произведе“ масив, подаваме ѝ празен масив като параметър и тя го попълва (вж. раздел 3).

---

## 2. Защо подаваме и размера? `sizeof` проблемът

Тъй като функцията получава само „къде започва масивът“, тя **не знае** колко елемента има в него. Затова винаги подаваме размера като отделен параметър.

Помните ли трика за броя на елементите `sizeof(arr) / sizeof(arr[0])`? Той работи **само там, където масивът е деклариран**. Вътре във функция `arr` вече е просто адрес и `sizeof(arr)` дава размера на адреса (обикновено 8 байта на 64-битова система), а не на масива:

```cpp
#include <iostream>

void printSize(int arr[]) {
    // arr тук е адрес, НЕ масив!
    std::cout << sizeof(arr) << std::endl;                 // 8 (размер на адрес)
    std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl; // 2 – грешно!
}

int main() {
    int arr[10];
    std::cout << sizeof(arr) << std::endl;                 // 40 (10 * 4 байта)
    std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl; // 10 – вярно
    printSize(arr);
    return 0;
}
```

> [!WARNING]
> Никога не смятайте размера на масив с `sizeof` вътре във функция, която го е получила като параметър. Компилаторът често дава предупреждение (`sizeof on array function parameter will return size of 'int *'`) – **четете предупрежденията!**

### Шаблонът `MAX_SIZE` + реален размер

Размерът на статичен масив трябва да е известен по време на компилация. Когато броят на елементите идва от входа, заделяме масив с **максимален** размер и пазим отделно колко елемента реално използваме:

```cpp
#include <iostream>

const int MAX_SIZE = 100;

void readArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size;
    std::cin >> size;

    if (size < 0 || size > MAX_SIZE) {
        std::cout << "Invalid size" << std::endl;
        return 1;
    }

    int arr[MAX_SIZE];         // капацитет – 100
    readArray(arr, size);      // реално използваме само size елемента
    printArray(arr, size);
    return 0;
}
```

> [!NOTE]
> Винаги подаваме на функциите **реалния** размер (`size`), а не `MAX_SIZE` – иначе ще обходим неинициализирани („боклучави“) стойности.

---

## 3. `const` масиви като параметри. Връщане на резултат чрез параметър

### `const` параметри

Щом функцията работи върху оригинала, тя **може** случайно да го развали. Ако функцията само чете масива (печат, търсене, сума…), маркираме параметъра с `const`. Така компилаторът ни пази:

```cpp
int sum(const int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr[i];
        // arr[i] = 0;  // грешка при компилация: arr е const
    }
    return result;
}
```

Правило:

| Функцията… | Параметър |
| ---------- | --------- |
| само чете масива (печат, търсене, min/max, сума) | `const int arr[]` |
| променя масива (въвеждане, сортиране, обръщане) | `int arr[]` |

> [!TIP]
> `const` е и **документация**: само от сигнатурата `int indexOf(const int arr[], int size, int x)` е ясно, че функцията няма да промени масива. Към `const int arr[]` можем да подадем и масив, деклариран като `const int arr[] = {...}`, а към `int arr[]` – не можем.

### Връщане на няколко резултата

С `return` връщаме **една** стойност. Ако трябват повече резултати, използваме параметри по референция (Седмица 4) или изходен масив:

```cpp
#include <iostream>

// min и max се „връщат“ чрез референции
void findMinMax(const int arr[], int size, int& minValue, int& maxValue) {
    minValue = arr[0];
    maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
}

// попълва result с четните числа от arr; resultSize се „връща“ по референция
void filterEven(const int arr[], int size, int result[], int& resultSize) {
    resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            result[resultSize] = arr[i];
            resultSize++;
        }
    }
}

int main() {
    int arr[] = {5, 8, 1, 4, 7, 10};
    int size = 6;

    int minValue, maxValue;
    findMinMax(arr, size, minValue, maxValue);
    std::cout << minValue << " " << maxValue << std::endl; // 1 10

    int evens[6];          // достатъчно голям – най-много size елемента
    int evensSize;
    filterEven(arr, size, evens, evensSize);
    for (int i = 0; i < evensSize; i++) {
        std::cout << evens[i] << " ";                      // 8 4 10
    }
    std::cout << std::endl;
    return 0;
}
```

> [!WARNING]
> Изходният масив трябва да е **достатъчно голям**, за да побере резултата. Функцията не може да провери това сама – отговорността е на извикващия.

### Функции, които променят размера

Когато функция добавя или изтрива елементи, тя трябва да обнови и размера – подаваме го **по референция**:

```cpp
// премахва елемента на позиция index, като измества останалите наляво
void removeAt(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        return;   // невалиден индекс – не правим нищо
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
```

---

## 4. Декомпозиция на задача на функции

Добрият код се състои от **малки функции, всяка с една ясна задача**. Пример: *„Прочетете N числа и отпечатайте дали масивът е палиндром, както и колко пъти се среща най-голямото число.“*

Вместо един голям `main`, разбиваме на:

```cpp
#include <iostream>

const int MAX_SIZE = 100;

void readArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

bool isPalindrome(const int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int maxElement(const int arr[], int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
    return result;
}

int countOccurrences(const int arr[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int size;
    std::cin >> size;
    if (size <= 0 || size > MAX_SIZE) {
        return 1;
    }

    int arr[MAX_SIZE];
    readArray(arr, size);

    std::cout << (isPalindrome(arr, size) ? "Palindrome" : "Not a palindrome") << std::endl;
    std::cout << countOccurrences(arr, size, maxElement(arr, size)) << std::endl;
    return 0;
}
```

> [!TIP]
> Добри навици:
> - Име на функция = глагол, който описва какво прави: `readArray`, `printArray`, `indexOf`, `isSorted`, `reverse`.
> - Функция, която отговаря на въпрос „да/не“, връща `bool` и започва с `is`/`has`/`contains`.
> - Функциите **не печатат**, освен ако задачата им е да печатат. `indexOf` връща индекс, а `main` решава какво да отпечата.
> - Линейно търсене връща **индекс** (или `-1`, ако няма такъв елемент), а не `bool` – така информацията е повече.

```cpp
int indexOf(const int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
```

---

## 5. Сортиране

**Сортиране** (sorting) означава да подредим елементите на масива, напр. в нарастващ ред. Ще разгледаме три прости алгоритъма – всички работят **на място** (in-place), т.е. променят подадения масив, без допълнителен масив. Визуализация: [visualgo.net/en/sorting](https://visualgo.net/en/sorting).

За размяна на два елемента използваме собствен `swap` с референции (Седмица 4). В стандартната библиотека има и `std::swap` (в `<utility>`).

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### Bubble sort (метод на мехурчето)

Многократно минаваме през масива и разменяме **съседни** елементи, които са в грешен ред. След всяко минаване най-големият от неподредените елементи „изплува“ в края, затова на всяка следваща итерация обхождаме с един елемент по-малко. Ако при някое минаване не е имало размяна – масивът вече е сортиран и спираме.

```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;   // нямаше размени => масивът е сортиран
        }
    }
}
```

Пример `[5, 1, 4, 2, 8]`:

| Минаване | Масив след минаването |
| :------: | --------------------- |
| 1 | `[1, 4, 2, 5, 8]` |
| 2 | `[1, 2, 4, 5, 8]` |
| 3 | няма размени → край |

### Selection sort (метод на пряката селекция)

На стъпка `i` намираме **най-малкия** елемент в неподредената част `arr[i..size-1]` и го разменяме с `arr[i]`. Лявата част винаги е сортирана и съдържа най-малките елементи.

```cpp
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
```

### Insertion sort (метод на вмъкването)

Както подреждаме карти в ръката: лявата част `arr[0..i-1]` е сортирана; взимаме `arr[i]` и го **вмъкваме** на правилното място, като изместваме по-големите елементи с една позиция надясно.

```cpp
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];   // изместваме надясно
            j--;
        }
        arr[j + 1] = current;
    }
}
```

> [!WARNING]
> В `insertionSort` индексът `j` става `-1`, затова трябва да е `int`, а не `size_t`/`unsigned` – беззнаков тип никога не е отрицателен и `j >= 0` винаги е вярно (безкраен цикъл / излизане извън масива). Редът на условията `j >= 0 && arr[j] > current` също е важен: благодарение на short-circuit не четем `arr[-1]`.

### Сравнение

*Стабилна* (stable) сортировка запазва относителния ред на равните елементи.

| | Bubble sort | Selection sort | Insertion sort |
| --- | :---: | :---: | :---: |
| Най-добър случай | O(n) (с `swapped`) | O(n²) | O(n) |
| Най-лош случай | O(n²) | O(n²) | O(n²) |
| Брой размени | O(n²) | **O(n)** (най-много n − 1) | O(n²) (премествания) |
| Стабилна | да | не | да |
| Кога е добра | учебна цел | когато размените са „скъпи“ | малки или почти сортирани масиви |

> [!NOTE]
> Нотацията O(n²) („от порядъка на n на квадрат“) ще разгледаме по-подробно в Седмица 7 (ефективност на алгоритмите). Засега: при 2 пъти повече елементи тези сортировки работят ~4 пъти по-бавно.

> [!TIP]
> За сортиране в **намаляващ** ред е достатъчно да обърнем сравнението (`<` ↔ `>`).

---

## 6. Двоично търсене

Линейното търсене проверява елементите един по един – в най-лошия случай `n` проверки. Ако масивът е **сортиран**, можем много по-бързо: гледаме средния елемент и **изхвърляме половината** масив на всяка стъпка. При 1 000 000 елемента това са най-много ~20 стъпки!

```cpp
// връща индекс на x в сортирания масив arr или -1, ако го няма
int binarySearch(const int arr[], int size, int x) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;    // x е вдясно
        } else {
            right = mid - 1;   // x е вляво
        }
    }
    return -1;
}
```

> [!NOTE]
> Защо `left + (right - left) / 2`, а не `(left + right) / 2`? Двата израза са математически равни, но `left + right` може да надхвърли максималната стойност на `int` (overflow) при много големи масиви. Първият вариант е безопасен.

> [!WARNING]
> Двоичното търсене работи **само върху сортиран масив**! Ако масивът не е сортиран, резултатът е безсмислен (функцията ще „пропусне“ елемента).

### Lower bound и upper bound

Ако `x` се среща няколко пъти, `binarySearch` връща *някое* от срещанията. Често ни трябва повече:

- **lower bound** – индексът на **първия** елемент, който е `>= x`;
- **upper bound** – индексът на **първия** елемент, който е `> x`.

Ако няма такъв елемент, връщаме `size` („позицията след последния“). Удобно е да пазим полуотворен интервал `[left, right)`:

```cpp
// първият индекс i, за който arr[i] >= x (или size, ако няма такъв)
int lowerBound(const int arr[], int size, int x) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;    // mid може да е отговорът – не го изхвърляме
        }
    }
    return left;
}

// първият индекс i, за който arr[i] > x (или size, ако няма такъв)
int upperBound(const int arr[], int size, int x) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {    // единствената разлика: <=
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

Пример: `arr = [1, 2, 2, 2, 5, 7]`

| `x` | `lowerBound` | `upperBound` | Брой срещания (`upper − lower`) |
| :-: | :----------: | :----------: | :-----------------------------: |
| 2 | 1 | 4 | 3 |
| 3 | 4 | 4 | 0 |
| 0 | 0 | 0 | 0 |
| 10 | 6 | 6 | 0 |

Полезни следствия:

- `x` се среща в масива ⇔ `lowerBound(...) < size && arr[lowerBound(...)] == x`; тогава това е **първото** срещане.
- Последното срещане на `x` е на индекс `upperBound(...) - 1` (ако `x` се среща).
- `lowerBound` е и **позицията, на която да вмъкнем** `x`, така че масивът да остане сортиран.

> [!WARNING]
> Внимавайте с беззнакови индекси (`size_t`) в двоичното търсене: при `right = size - 1` за празен масив или при `right = mid - 1` при `mid == 0` стойността „прескача“ до огромно число и `left <= right` остава вярно. Използвайте `int` за индексите или полуотворения вариант по-горе.

---

## Какво ще отпечата?

**1.** Какво ще отпечата програмата?

```cpp
#include <iostream>

void f(int arr[], int x) {
    arr[0] = 100;
    x = 100;
}

int main() {
    int arr[3] = {1, 2, 3};
    int x = 1;
    f(arr, x);
    std::cout << arr[0] << " " << x << std::endl;
    return 0;
}
```

<details><summary>Отговор</summary>

`100 1` – масивът се подава „по адрес“ и промяната се вижда, а `x` е копие.
</details>

---

**2.** Какво ще отпечата програмата?

```cpp
#include <iostream>

void reverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```

<details><summary>Отговор</summary>

`1 2 3 4 5` – цикълът минава през **целия** масив, затова всяка двойка се разменя два пъти и масивът се връща в изходното състояние. Правилно е `i < size / 2`.
</details>

---

**3.** Ще се компилира ли кодът? Ако не – защо?

```cpp
void fill(const int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}
```

<details><summary>Отговор</summary>

Не. Параметърът е `const int arr[]`, а функцията се опитва да промени елементите му. Трябва да махнем `const`, защото `fill` по смисъл променя масива.
</details>

---

**4.** Какво ще отпечата програмата (на 64-битова система, `int` – 4 байта)?

```cpp
#include <iostream>

int countElements(int arr[]) {
    return sizeof(arr) / sizeof(arr[0]);
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << sizeof(arr) / sizeof(arr[0]) << " " << countElements(arr) << std::endl;
    return 0;
}
```

<details><summary>Отговор</summary>

`6 2` – в `main` `arr` е масив от 24 байта; във функцията `arr` е адрес (8 байта), а `8 / 4 = 2`.
</details>

---

**5.** Какво ще отпечата програмата?

```cpp
#include <iostream>

void swapValues(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int arr[3] = {3, 2, 1};
    swapValues(arr[0], arr[2]);
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}
```

<details><summary>Отговор</summary>

`321` – подаваме **отделни елементи** (`int`), а не масива, при това по стойност. Функцията разменя копията. Трябва `void swapValues(int& a, int& b)`.
</details>

---

**6.** Масивът `[64, 25, 12, 22, 11]` се сортира със *selection sort*. Как изглежда след **първите две** итерации на външния цикъл? А ако е *bubble sort*?

<details><summary>Отговор</summary>

- Selection sort: `[11, 25, 12, 22, 64]` → `[11, 12, 25, 22, 64]`.
- Bubble sort: след 1-во минаване `[25, 12, 22, 11, 64]`, след 2-ро `[12, 22, 11, 25, 64]`.
</details>

---

**7.** Масивът `[5, 2, 4, 6, 1, 3]` се сортира с *insertion sort*. Как изглежда след като сме вмъкнали елементите с индекси 1, 2 и 3?

<details><summary>Отговор</summary>

`[2, 5, 4, 6, 1, 3]` → `[2, 4, 5, 6, 1, 3]` → `[2, 4, 5, 6, 1, 3]` (6 вече е на мястото си).
</details>

---

**8.** Даден е `arr = [3, 3, 5, 8, 8, 8, 10]`. Какво връщат `lowerBound(arr, 7, 8)`, `upperBound(arr, 7, 8)`, `lowerBound(arr, 7, 4)` и `upperBound(arr, 7, 10)`?

<details><summary>Отговор</summary>

`3`, `6`, `2`, `7`. Числото 8 се среща `6 − 3 = 3` пъти; 4 не се среща, но би се вмъкнало на позиция 2; няма елемент `> 10`, затова връщаме `size = 7`.
</details>

---

**9.** Какво ще отпечата програмата?

```cpp
#include <iostream>

int g(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arr[count++] = arr[i];
        }
    }
    return count;
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int newSize = g(arr, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "| " << newSize << std::endl;
    return 0;
}
```

<details><summary>Отговор</summary>

`2 4 6 4 5 6 | 3` – функцията „премества“ четните числа в началото и връща новия логически размер. Елементите след позиция `newSize` остават каквито са били.
</details>

---

**10.** Колко най-много стъпки (итерации на цикъла) прави `binarySearch` върху сортиран масив от 1000 елемента? А линейното търсене?

<details><summary>Отговор</summary>

Двоичното – около 10 (2¹⁰ = 1024 ≥ 1000); линейното – 1000.
</details>

---

## Ресурси

- learncpp: [Passing arrays to functions (17.8 — C-style array decay)](https://www.learncpp.com/cpp-tutorial/c-style-array-decay/)
- learncpp: [Sorting an array using selection sort](https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/)
- cppreference: [Array declaration](https://en.cppreference.com/w/cpp/language/array), [`std::lower_bound`](https://en.cppreference.com/w/cpp/algorithm/lower_bound), [`std::upper_bound`](https://en.cppreference.com/w/cpp/algorithm/upper_bound)
- Визуализация на сортировки: [visualgo.net/en/sorting](https://visualgo.net/en/sorting)
- Визуализация на двоично търсене: [Binary search – cs.usfca.edu](https://www.cs.usfca.edu/~galles/visualization/Search.html)
- [Архив със задачи от контролни и изпити](https://github.com/telinc1/Introduction-To-Programming-Problems/tree/master/resources/tasks/archives)
