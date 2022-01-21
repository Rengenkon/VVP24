#include <iostream>
#include <string>

/*
Задание 24.
1. Дана строка, состоящая из русских слов, разделенных пробелами (одним или несколькими). Найти количество слов в строке.
2. Дана строка, состоящая из русских слов, разделенных пробелами (одним или несколькими). Найти длину самого короткого слова.
3. Дана строка, состоящая из русских слов, набранных заглавными буквами и разделенных пробелами (одним или несколькими). Преобразовать каждое слово в строке, заменив в нем все последующие вхождения его первой буквы на символ «.» (точка). Например, слово «МИНИМУМ» надо преобразовать в «МИНИ.У.». Количество пробелов между словами не изменять
4. Дана строка-предложение на русском языке. Подсчитать количество содержащихся в строке гласных букв.
5. Дана строка, содержащая полное имя файла, то есть имя диска, список каталогов (путь), собственно имя и расширение. Выделить из этой строки имя файла (без расширения)
6. Дана строка, содержащая полное имя файла. Выделить из этой строки название последнего каталога (без символов «\»). Если файл содержится в корневом каталоге, то вывести символ «\».
7. Дана строка-предложение. Зашифровать ее, поместив вначале все символы, расположенные на четных позициях строки, а затем, в обратном, все символы, расположенные на нечетных позициях (например, строка «Программа» превратится в «ргамамроП»).

Каждая задача решена в отдельном классе
*/

class z1 {
private:
    std::string s;

public:
    z1(std::string st = "") {
        s = st;
    }

    void foo() {
        int k = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ' && s[i - 1] != ' ') {
                k++;
            }
        }
        std::cout << "Количество слов в троке " << k;
    }
};

class z2 {
private:
    std::string s;

public:
    z2(std::string st = "") {
        s = st;
    }

    void foo() {
        int n = 0, d = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ' ' && s[i-1] != ' ') {
                if (d == -1 || d > i - n) {
                    d = i - n;
                }
            }
            else if (s[i - 1] == ' ') {
                n = i;
            }
        }
        if (s.size() - n < d) {
            d = s.size() - n;
        }
        std::cout << "Длина кротчайшего слова " << d;
    }
};

class z3 {
private:
    std::string s;

public:
    z3(std::string st = "") {
        s = st;
    }

    void foo() {
        int n = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != ' ' && s[i - 1] == ' ') {
                n = i;
            }
            else if (s[n] == s[i]) {
                s[i] = '.';
            }
        }

        std::cout << s;
    }
};

class z4 {
private:
    std::string s;

public:
    z4(std::string st = "") {
        s = st;
    }
    
    void foo() {
        int n = 0;
        std::string sa = "эеоёаяуюыи";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'А' && 'Я' >= s[i]) {
                if (sa.find(s[i] + 32) != -1) {
                    n++;
                }
            }
            else {
                if (sa.find(s[i]) != -1) {
                    n++;
                }
            }
        }

        std::cout << "Гласных букв " << n;
    }
};

class z5 {
private:
    std::string s;

public:
    z5(std::string st = "") {
        s = st;
    }

    void foo() {
        int n = 0, d = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\\') {
                n = i + 1;
            }
            else if (s[i] == '.') {
                d = i;
            }
        }

        std::cout << s << "\n";
        for (int i = n; i < d; i++) {
            std::cout << s[i];
        }
    }
};

class z6 {
private:
    std::string s;

public:
    z6(std::string st = "") {
        s = st;
    }

    void foo() {
        int n = -1, d = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\\') {
                d = n;
                n = i;
            }
        }

        std::cout << s << "\n";
        if (d == -1) {
            std::cout << '\\';
        }
        else {
            for (int i = d + 1; i < n; i++) {
                std::cout << s[i];
            }
        }
        
    }
};

class z7 {
private:
    std::string s;

public:
    z7(std::string st = "") {
        s = st;
    }

    void foo() {
        std::string sz = "";
        for (int i = 1; i < s.size(); i += 2) {
            sz += s[i];
        }
        for (int i = (s.size() - (s.size() + 1) % 2) - 1; i > -1; i -= 2) {
            sz += s[i];
        }
        
        std::cout << sz << "\n";

    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    z1 first("Раз              ные   сло ва");
    z2 second("Слвововововоо слово словоооо");
    z3 third("МИНИМУМ РЕГРЕССИРОВАТЬ");
    z4 fourth("Аоаоао 6");
    z5 fifth("C:\\Users\\Ren\\Desktop\\Лабы\\Введение в программирование\\VP18.txt");
    z6 sixth("C:\\VP18.txt");
    z7 seventh("Шифрование");

    std::cout << "\n Задача 1\n";
    first.foo();
    std::cout << "\n Задача 2\n";
    second.foo();
    std::cout << "\n Задача 3\n";
    third.foo();
    std::cout << "\n Задача 4\n";
    fourth.foo();
    std::cout << "\n Задача 5\n";
    fifth.foo();
    std::cout << "\n Задача 6\n";
    sixth.foo();
    std::cout << "\n Задача 7\n";
    seventh.foo();
}
