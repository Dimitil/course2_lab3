/*************************************************************
	Практическое занятие №3-курс-С110. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"


#define stop __asm nop

book global_book;



void main()
{
//Тема "Старые" потоковые функции стандартной библиотеки
//Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
	printf("Tema. 1. Enter A, B, C\n");

	double A = 0, B = 0, C = 0;
	//scanf("%lf%lf%lf", &A, &B, &C);

//Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
//при изменении x в диапазоне -2 до +2 с шагом 0.5
	double x = -2;
	while(x <= 2)
	{
		double y = A * x * x + B * x + C;
		printf("|x= %6.2lf|%6.2lf|\n", x, y);
		x += 0.5;
	}
	printf("\n");
	stop

		//Тема. Структуры С.	
		//Задание 1.1 Объявите структуру BOOK, описывающую книгу
		//(автор, заглавие, год издания, цена, категория…).
		//Подумайте: какого типа могут быть поля структуры.
		//Подсказка: объявление структуры рекомендуется выносить
		//в заголовочный файл.

			//Задание 1.2. Создайте разными способами (глобальный, локальный, статический,
			//динамический) экземпляры (объекты) типа BOOK (без инициализации).
			//Определите - сколько памяти отводит компилятор под каждый
			//такой объект. Как инициализируются (или не инициализируются) поля
			//структуры. Подумайте: от чего зависит объем выделяемой памяти?

		book local_book;
		static book static_book;
		book* dynamic_book = new book;

		stop

		std::cout << "\nGlobal object: "<<sizeof(global_book);
		std::cout << "\nLocal object: " << sizeof(local_book);
		std::cout << "\nStatic object: " << sizeof(static_book);
		std::cout << "\nDynamic book: " << sizeof(*dynamic_book);

		
			//Задание 1.3. Напишите функцию, выводящую на экран реквизиты книги.
			//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
			//Для вывода на консоль используйте функцию стандартной библиотеки
			//printf
	

			//Задание 1.4. Напишите функцию для формирования полей структуры.
			//Для ввода используйте функцию стандартной библиотеки scanf
			//Замечание: неплохо заложить в такую функцию возможность проверки
			//корректности введенного значения, например, год издания не может быть
			//меьше, чем... (год появления письменности), категорию ползователь
			//должен выбирать из существующих, цена не может быть отрицательной...


			//Используйте структуру BOOK, созданную в предыдущем задании.
			//Для этого достаточно переписать и подключить к проекту файлы
			//book.h и book.cpp

			//Задание 2. Создаем «картотеку».
			//«Картотека» - это массив структур => нужно такой массив создать.
			//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
			//кКаким должен быть такой массив???	


				   

			//Пользователь должен иметь возможность по своему желанию выполнять
			//разные действия с картотекой => нужно такую возможность ему
			//предоставить: это может выглядеть как вывод "меню" (перечень
			//возможных действий и соответствующих реакций пользователя), например:
			//Распечатать содержимое картотеки (1)
			//Ввести новую книгу (2)
			//Удалить существующую(ие) (3)
			//Записать текущее содержимое картотеки в файл (4)
			//Считать из файла содержимое в картотеку (5)
			//...
			//Выход из программы (...)

		CARD_INDEX book_list;		//инициализация картотеки

		book_list.cap = 3;
		book_list.count = 0;
		book_list.pB = new book*;
		*book_list.pB = new book[book_list.cap];

		/*strcpy((*book_list.pB)[0].author, "Tolstoy");
		strcpy((*book_list.pB)[0].title, "WarAndPeace");
		(*book_list.pB)[0].price = 700;
		(*book_list.pB)[0].year = 1955;
		(*book_list.pB)[0].category = ROMANCE;
		book_list.count++;

		strcpy((*book_list.pB)[1].author, "Engels");
		strcpy((*book_list.pB)[1].title, "Anti-During");
		(*book_list.pB)[1].price = 500;
		(*book_list.pB)[1].year = 1995;
		(*book_list.pB)[1].category = SCIENCE_FICTION;
		book_list.count++;

		strcpy((*book_list.pB)[2].author, "Darwin");
		strcpy((*book_list.pB)[2].title, "TheOriginOfSpecie");
		(*book_list.pB)[2].price = 450;
		(*book_list.pB)[2].year = 2009;
		(*book_list.pB)[2].category = SCIENCE_FICTION;
		book_list.count++;*/

		

		stop

	char choice;
	
	do{
		
	printf("\n\n			MENU\n\
		(P)rint all books.\n\
		(A)dd new book.\n\
		(D)elete book.\n\
		(W)rite to file.\n\
		(R)ead from file to base.\n\
		(S)ort by author.\n\
		sort by (T)itle.\n\
		sort by (Y)ear.\n\
		Sort by pr(I)ce.\n\
		sort by (C)ategory.\n\
		(Q)uit.");

	scanf("%c", &choice);

	switch (choice)
	{
	case 'P':
		printAllBooks(&book_list);
		scanf("%*c");
		break;
	case 'A':
		addBook(&book_list);
		scanf("%*c");
		break;
	case 'D':
		deleteBook(&book_list);
		scanf("%*c");
		break;
	case 'W':
		writeToFile(&book_list);
		scanf("%*c");
		break;
	case 'R':
		readFromFile(&book_list);
		printf("\n\nData was read from file\n");
		scanf("%*c");
		break;
	case 'S':
		sortByAuthor(&book_list);
		printf("\n\nData was sorted by aythor\n");
		scanf("%*c");
		break;
	case 'T':
		sortByTitle(&book_list);
		printf("\n\nData was sorted by title\n");
		scanf("%*c");
		break;
	case 'Y':
		sortByYear(&book_list);
		printf("\n\nData was sorted by year\n");
		scanf("%*c");
		break;
	case 'I':
		sortByPrice(&book_list);
		printf("\n\nData was sorted by price\n");
		scanf("%*c");
		break;
	case 'C':
		sortByCategory(&book_list);
		printf("\n\nData was sorted by category\n");
		scanf("%*c");
		break;
	}

	} while (choice!='Q');

	delete[] *book_list.pB;
	delete book_list.pB;
	//Реализуйте посредством функций разные возможности работы с картотекой
	
	// Упрощения:
	//1. пусть автор и заглавие книги состоят из одного слова
	//2. все строки можно задавать латинскими буквами. Если хочется
	//   не только выводить, но и вводить русские символы, следует
	//   а) пользоваться расширенными функциями ввода/вывода - wprintf(), wscanf()
	//   б) хранить строки как расширенные - wchar_t
	//   в) установить кодировку - setlocale(LC_CTYPE, ".866");	
	

	//Подсказка1: для файлового ввода/вывода используйте функции fprintf и fscanf
	//(заголовочный файл <cstdio>



	// Подсказка2: удобно в качестве первого данного в файле хранить количество
	// книг в картотеке
	//Если файл существует и его удалось открыть
	//if()
	//{
	//Чтение данных из файла
	//а) считали количество элементов
	//б) создали массив требуемой размерности
	//в) считали данные из файла в массив
	//}




	//****************************************************************
	//Задание 3. Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.



}