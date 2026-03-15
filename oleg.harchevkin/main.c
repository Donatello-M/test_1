#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <locale.h>
#endif

#define LEN 15 // Длина демонстрационного массива

// ====+++==== Вспомогательные функции, листай дальше ====+++====

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define randint(a, b) (rand() % (b - a + 1) + a)

bool date_is_valid(int year, int month, int day)
{
    /*
     * Валидатор даты
     */
    static const int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12 || day < 1)
        return false;

    int dim = month_days[month - 1]; // дней в месяце

    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        dim = 29;

    if (day > dim)
        return false;

    return true;
}

#define TEXT_START_CAPACITY 16

char *get_string()
{
    /*
     * Функция получения строки произвольной длины
     */
    size_t cap = TEXT_START_CAPACITY;
    size_t len = 0;
    char *buf = malloc(cap * sizeof(char));

    if (!buf)
    {
        free(buf);
        return NULL;
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        char *tmp;

        if (c == L'\n')
            break;

        buf[len] = c;
        len++;

        if (len == cap)
        {
            cap *= 2;
            tmp = realloc(buf, cap * sizeof(char));
            if (!tmp)
            {
                free(buf);
                return NULL;
            }
            buf = tmp;
        }
    }
    buf[len] = 0;
    return buf;
}

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void press_any_key()
{
    /*
     * Кросс-платформенный "Press ANY key to continue"
     */
    printf("Press ANY key\n");
#ifdef _WIN32
    INPUT_RECORD record;
    DWORD events;
    for (;;)
    {
        ReadConsoleInputA(GetStdHandle(STD_INPUT_HANDLE), &record, 1, &events);
        if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown)
            return;
    }
#else
    int c;
    read(STDIN_FILENO, &c, 1);
#endif
}

// ====+++==== Задания ====+++====

int day_of_week(int year, int month, int day)
{
    /*
     * Возвращает день недели, где 0 - Понедельник и т.д.
     * Алгоритм Zeller's congruence
     */
    int h = day;
    if (month < 3)
    {
        month += 12; // месеца от 3 (март), до 14 (февраль)
        year--;      // начинаем год с марта
    }
    int K = year % 100; // год в текущем веке
    int J = year / 100; // текущий век

    h += (13 * (month + 1)) / 5;
    h += K + K / 4 + J / 4 - 2 * J;

    return ((h - 2) % 7 + 7) % 7;
}

void reverse_arr_int(int *arr, int n)
{
    /*
     * Разворачивает массив arr[n]
     */
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}

void cyclic_shift(int *arr, int n, int k)
{
    /*
     * Циклический сдвиг массива arr[n] на k (положительное направление - вправо)
     */
    k = ((k % n) + n) % n; // приводим к диапозону [0, n-1]
    reverse_arr_int(arr, n);
    reverse_arr_int(arr, k);
    reverse_arr_int(arr + k, n - k);
}

char *max_palindrome(char *s, int *m)
{
    /*
     * Ищет максимальный палиндром в строке
     * На вход получает строку s
     * Возвращает указатель на начало палиндрома в данной строке и его длину m
     */
    int n = strlen(s);
    char *s2 = malloc((n * 2 + 2) * sizeof(char));
    int *p = malloc((n * 2 + 1) * sizeof(int)); // Радиусы палиндромов

    for (int i = 0; i <= n; ++i) // Разбавляем строку, чтобы все палиндромы стали нечетными
    {
        s2[i * 2] = 0xff; // Разделитель
        s2[i * 2 + 1] = s[i];
    }

    int r = 0;       // Правый край последнего палиндрома
    int c = 0;       // Центр последнего палиндрома
    int c_max = 0;   // Центр максимального палиндрома
    int len_max = 1; // Длина максимального палиндрома

    for (int i = 1; i <= (n * 2); ++i)
    {
        if (r > i) // Если в пределах прошлого палиндрома, можем пропустить часть проверок
                   // Пример: (# A #)B(# A #)
                   //                ^   ^ ^
                   //                c   i r
                   // # - Разделитель
            p[i] = MIN(p[2 * c - i], r - i);
        else
            p[i] = 0;

        while (0 <= (i - p[i] - 1) && (i + p[i] + 1) <= (n * 2) && // Пока в пределах строки
               s2[i - p[i] - 1] == s2[i + p[i] + 1])               // и символы совпадают
        {
            p[i]++;
        }

        if (p[i] + i > r) // Если новый палиндром правее
        {
            c = i;
            r = i + p[i];
        }

        if (len_max < p[i]) // Проверяем на максимальность
        {
            len_max = p[i];
            c_max = i;
        }
    }
    free(s2);
    free(p);
    *m = len_max;
    return s + (c_max - len_max) / 2;
}

// ====+++==== Main ====+++====

int main()
{
#ifdef _WIN32
    setlocale(LC_ALL, ".65001"); //utf-8
#endif
    printf("Задание №1\n");

    int day, month, year;
    while (1)
    {
        day = 0;
        month = 0;
        year = 0;
        printf("Введите дату в формате дд.мм.гггг: ");
        int count = scanf("%d.%d.%d", &day, &month, &year);

        int c;
        while ((c = getchar()) != EOF)
            if (c == '\n')
                break;

        if (count == 3 && date_is_valid(year, month, day))
            break;

        printf("НЕВЕРНАЯ ДАТА!!!\n");
    }

    static const char *days_of_week[] = {
        "понедельник",
        "вторник",
        "среда",
        "четверг",
        "пятница",
        "суббота",
        "воскресение",
    };

    printf("День недели: %s\n", days_of_week[day_of_week(year, month, day)]);

    printf("\nЗадание №2\n");

    int X[LEN];
    for (int i = 0; i < LEN; i++)
        X[i] = randint(-100, 100);

    printf("Исходный массив: \n");
    for (int i = 0; i < LEN; i++)
        printf("%*d ", 4, X[i]);
    printf("\n");

    int k;
    while (1)
    {
        k = 0;
        printf("Введите величину сдвига: ");
        int count = scanf("%d", &k);

        int c;
        while ((c = getchar()) != EOF)
            if (c == '\n')
                break;

        if (count == 1)
            break;

        printf("НЕВЕРНЫЙ ВВОД!!!\n");
    }

    cyclic_shift(X, LEN, k);

    printf("Сдвинутый массив:\n");
    for (int i = 0; i < LEN; i++)
        printf("%*d ", 4, X[i]);
    printf("\n");

    printf("\nЗадание №3\n");

    printf("Введите строку для поиска палиндрома: ");
    char *s = get_string();
    int m;
    char *pal = max_palindrome(s, &m);
    printf("Результат: ");
    for (int i = 0; i < m; i++)
        putchar(pal[i]);

    printf("\nДлина: %d\n", m);

    press_any_key();
}