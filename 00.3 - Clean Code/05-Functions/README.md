[← Към съдържанието](../README.md)

# 5. Функции

## 5.1 Интервали

Между името на функцията и отварящата скоба няма интервал – нито при декларирането, нито при извикването. Така функцията се различава от `if`, `for` и `while`, при които интервал има.

```cpp
// Лошо
int sum (int a, int b)
cout << sum (3, 5);

// Добре
int sum(int a, int b)
cout << sum(3, 5);
```

## 5.2 Преизползване на код

Когато един и същ код се повтаря на няколко места, изнесете го във функция. Така той се пише и поправя само на едно място.

```cpp
// Лошо
int main() {
    int a, b;
    cin >> a >> b;

    int digitsA = 0;
    while (a > 0) {
        digitsA++;
        a /= 10;
    }

    int digitsB = 0;
    while (b > 0) {
        digitsB++;
        b /= 10;
    }
    ...
}

// Добре
int countDigits(int number) {
    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;

    int digitsA = countDigits(a);
    int digitsB = countDigits(b);
    ...
}
```

## 5.3 Една функция – една задача

Всяка функция трябва да върши едно нещо. Най-честото разделение е на вход, обработка и изход: една функция чете данните, друга пресмята резултата, трета го извежда, а `main` само ги свързва.

```cpp
// Лошо
void readAndPrintFactorial() {
    int n;
    do {
        cin >> n;
    } while (n < 0);

    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    cout << n << "! = " << result << endl;
}

// Добре
int readNonNegativeNumber() {
    int number;
    do {
        cin >> number;
    } while (number < 0);
    return number;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void printFactorial(int n, long long result) {
    cout << n << "! = " << result << endl;
}

int main() {
    int n = readNonNegativeNumber();
    long long result = factorial(n);
    printFactorial(n, result);
}
```

Сега `factorial` може да се използва навсякъде, а не само когато числото се въвежда от клавиатурата и резултатът се извежда на екрана.

Признаци, че една функция върши твърде много:

- има повече от около 20 реда;
- в името ѝ има „and“, например `readAndPrint`;
- приема много параметри.

## 5.4 Подаване по референция

Подавайте параметър по референция само когато функцията трябва да промени аргумента. Иначе го подавайте по стойност.

```cpp
// Лошо – функцията не променя a и b
int sum(int& a, int& b) {
    return a + b;
}

// Добре
int sum(int a, int b) {
    return a + b;
}

// Добре – функцията трябва да промени a и b
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

## 5.5 Ранен `return`

Когато резултатът е ясен рано, върнете го веднага, вместо да влагате останалия код в `if`.

```cpp
// Лошо
bool isPrime(int number) {
    bool result = false;
    if (number >= 2) {
        result = true;
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                result = false;
                break;
            }
        }
    }
    return result;
}

// Добре
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
```

## 5.6 Директно връщане на условието

Когато функцията връща `true` или `false` според едно условие, върнете директно условието.

```cpp
// Лошо
bool isEven(int number) {
    if (number % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

// Добре
bool isEven(int number) {
    return (number % 2 == 0);
}
```

---

[← Предишна тема: Условия и цикли](../04-Conditions-And-Loops/README.md) | [Към съдържанието](../README.md) | [Следваща тема: Коментари →](../06-Comments/README.md)
