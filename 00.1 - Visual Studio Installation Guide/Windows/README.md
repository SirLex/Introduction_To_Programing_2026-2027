# Инсталиране на Visual Studio Community 2026

Инструкциите са за Windows. Инсталацията заема около 15 GB място на диска, така че се уверете, че имате достатъчно свободно пространство.

1. Насочете се към страницата [Download Visual Studio](https://visualstudio.microsoft.com/downloads/).

2. Изтеглете версията **Visual Studio Community**.

   <img src="images/VS_Community_Screenshot.png" alt="Изтегляне на Visual Studio Community" width="600">

3. Запазете Visual Studio Installer в папка по ваш избор и го стартирайте.

4. Изберете **Desktop development with C++** и натиснете **Install** в долния десен ъгъл.

   <img src="images/Desktop_Dev_And_Install.png" alt="Избиране на Desktop development with C++ и инсталиране" width="800">

5. След успешна инсталация изберете една от опциите за акаунт. Ако нямате акаунт и не искате да създавате, можете да изберете **Skip and add accounts later**.

   <img src="images/Account_After_Install.png" alt="Избор на акаунт след инсталация" width="600">

6. Вероятно ще ви се покаже прозорецът по-долу. На този етап препоръчваме да изберете **Maybe later**, тъй като AI асистентът може да навреди повече, отколкото да помогне, докато се учите.

   <img src="images/Reject_AI.png" alt="Отказване на GitHub Copilot с Maybe later" width="550">

7. Вече сте готови да създадете първия си проект! В горния десен ъгъл на прозореца трябва да имате бутона **Create a new project** – натиснете го.

   <img src="images/Create_Project.png" alt="Бутон Create a new project" width="200">

8. От списъка с шаблони изберете **Console App** с етикет C++ и натиснете **Next** в долния десен ъгъл. Ако не откривате **Console App**, използвайте търсачката отгоре.

   <img src="images/Console_App.png" alt="Избиране на шаблона Console App за C++" width="700">

9. Въведете име на проекта в полето **Project name**, изберете в коя папка да бъде запазен от полето **Location** и натиснете **Create**. Името на проекта трябва да е на английски (не на шльокавица), без интервали и да подсказва за какво служи проектът, например `SumOfTwoNumbers` вместо `Proekt1` или `Test`.

   <img src="images/Name_of_Project.png" alt="Задаване на име и местоположение на проекта" width="600">

10. Visual Studio автоматично създава файл с примерна програма, която отпечатва "Hello World!". За да я стартирате, натиснете **Ctrl + F5** или зеления бутон **Local Windows Debugger** в горната лента. Ако на екрана се появи конзола с надпис "Hello World!", всичко е инсталирано успешно. След това можете да изтриете коментарите (редовете, започващи с `//`), тъй като те са само пояснения и не влияят на програмата. Собствения си код засега пишете между фигурните скоби `{ }` на `main`, на мястото на реда с `std::cout`.

    <img src="images/Code.png" alt="Примерната програма Hello World във Visual Studio" width="750">