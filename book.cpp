#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"
#include <cstring>
#include <cstdio>

//Задание 1.3. Напишите функцию, выводящую на экран реквизиты книги.
	//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
	//Для вывода на консоль используйте функцию стандартной библиотеки
	//printf

void printBook(const book &b)
{
	printf("\n\nAuthor:    %s\nTitle:     %s\nYear:      %d\nPrice:     %d\nCategory:  ", b.author, b.title, b.year, b.price);
	switch (b.category)
	{
		case FANTASY:
			printf("Fantasy");
			break;
		case ADVENTURE:
			printf("Adventure");
			break;
		case ROMANCE:
			printf("Romance");
			break;
		case SCIENCE_FICTION:
			printf("Science fiction");
			break;
		case CHILDRENS:
			printf("Childrens");
			break;
		case POETRY: 
			printf("Poetry");
			break;
		case OTHER: 
			printf("Other");
			break;
		default:
			printf("Ooops! Something wrong. We have a problem.");
	}
}

//Задание 1.4. Напишите функцию для формирования полей структуры.
//Для ввода используйте функцию стандартной библиотеки scanf
//Замечание: неплохо заложить в такую функцию возможность проверки
//корректности введенного значения, например, год издания не может быть
//меьше, чем... (год появления письменности), категорию ползователь
//должен выбирать из существующих, цена не может быть отрицательной...

void initBook(book &b)
{
	char buf[80];
	do {
		printf("\nEnter author (20 symbols):\n");
		scanf("%s", buf);
	} while (strlen(buf) > 21);

	strcpy(b.author, buf);

	do {
		printf("\nEnter title (20 symbols):\n");
		scanf("%s", buf);
	} while (strlen(buf) > 21);
	strcpy(b.title, buf);
		
	int year_buf;
	do {
		printf("\nEnter year:\n");
		scanf("%d", &year_buf);
	} while (year_buf < 300 || year_buf > 2020);
	b.year = year_buf;

	int price_buf;
	do {
		printf("\nEnter price:\n");
		scanf("%d", &price_buf);
	} while (price_buf < 0);
	b.price = price_buf;
	
	int choice=3;
	do {
		printf("\nChoose a genre:\n0. Fantasy\n1. Adventure\n2. Romance\n3. Science Fiction\n4. Childrens\n5. Poetry\n6. Other\n");
		scanf("%d", &choice);
	} while (choice < 0 || choice > CATEGORYMAX);
	b.category = static_cast<eCategory>(choice);

	}

void addBook(CARD_INDEX* pCard) 
{
	if (pCard->count >= pCard->cap) //емкость исчерпана
	{ //перераспределяем память...
		pCard->cap *=2;
		book* newB = new book[pCard->cap];
		for (int i = 0; i < pCard->count; i++)
		{
			newB[i] = (*pCard->pB)[i];
		}
		delete[] *pCard->pB;
		*pCard->pB = newB;

	}
	//добавляем книгу в картотеку...
	pCard->count+=1;
	initBook((*pCard->pB)[pCard->count-1]);
}

void printAllBooks(const CARD_INDEX* pCard) 
{
	for (int i = 0; i < pCard->count; i++)
	{
		printf("\n\n%d", i+1);
		printBook((*pCard->pB)[i]);
	}
}

void deleteBook(CARD_INDEX* pCard)
{
	int num;
	printf("\n\nDelete book:\nEnter number of book\n");
	scanf("%d", &num);

	do {
		printf("\nDelete this book:\n");
		printBook((*pCard->pB)[num - 1]);
		char choice;
		printf("\n\nYou are sure? (Y/N)\n");

		scanf("%*c%c", &choice);
		switch (choice)
		{
		case 'N':
			return;
		case 'Y':
			//do delete
			for (int i = num-1; i < pCard->count; i++)
			{
				(*pCard->pB)[i]= (*pCard->pB)[i+1];
			}
			pCard->count--;
			return;
		default:
			printf("\n\nUncorrect answer\n");
		}
	} while (true);
}

void writeToFile(const CARD_INDEX* pCard)
{
	FILE* pFile;
	
	pFile = fopen("book_list.txt", "w");

	if (pFile) {
		fprintf(pFile, "%d", pCard->count);
		for (int i = 0; i < pCard->count; i++)
		{
			fprintf(pFile, "\n%s\n%s\n%d\n%d\n", (*pCard->pB)[i].author, (*pCard->pB)[i].title, (*pCard->pB)[i].year, (*pCard->pB)[i].price);
			switch ((*pCard->pB)[i].category)
			{
			case FANTASY:
				fprintf(pFile, "Fantasy\n");
				break;
			case ADVENTURE:
				fprintf(pFile, "Adventure\n");
				break;
			case ROMANCE:
				fprintf(pFile, "Romance\n");
				break;
			case SCIENCE_FICTION:
				fprintf(pFile, "ScienceFiction\n");
				break;
			case CHILDRENS:
				fprintf(pFile, "Childrens\n");
				break;
			case POETRY:
				fprintf(pFile, "Poetry\n");
				break;
			case OTHER:
				fprintf(pFile, "Other\n");
				break;
			default:
				fprintf(pFile, "Ooops! Something wrong. We have a problem.");
			}
		}
	}
	fclose(pFile);

}

void readFromFile(CARD_INDEX* pCard)
{
	FILE* pFile;
	pFile = fopen("book_list.txt", "r");

	
	if (pFile) {
		fscanf(pFile, "%d", &pCard->count);
		delete[] *pCard->pB;
		*pCard->pB = new book[pCard->count];
		pCard->cap = pCard->count;
		for (int i = 0; i < pCard->count; i++)
		{
			
			fscanf(pFile, "%s", (*pCard->pB)[i].author);
			fscanf(pFile, "%s", (*pCard->pB)[i].title);
			fscanf(pFile, "%d", &(*pCard->pB)[i].year);
			fscanf(pFile, "%d", &(*pCard->pB)[i].price);

			char buf[80];
			fscanf(pFile, "%s", buf);

			if (!strcmp(buf, "Fantasy")) (*pCard->pB)[i].category = FANTASY;
			else if (!strcmp(buf, "Adventure")) (*pCard->pB)[i].category = ADVENTURE;
			else if (!strcmp(buf, "Romance")) (*pCard->pB)[i].category = ROMANCE;
			else if (!strcmp(buf, "ScienceFiction")) (*pCard->pB)[i].category = SCIENCE_FICTION;
			else if (!strcmp(buf, "Childrens")) (*pCard->pB)[i].category = CHILDRENS;
			else if (!strcmp(buf, "Poetry")) (*pCard->pB)[i].category = POETRY;
			else if (!strcmp(buf, "Other")) (*pCard->pB)[i].category = OTHER;
			else 	(*pCard->pB)[i].category = CATEGORYMAX;
			
		}

	}
	fclose(pFile);
}

void sortByAuthor(CARD_INDEX* pCard) {
	for (int i = 1; i < pCard->count+1; i++)
		for (int j = i; j < pCard->count; j++) // пока j>0 и элемент j-1 > j,
		{
			if (strcmp((*pCard->pB)[j - 1].author, (*pCard->pB)[j].author)>0)
			{
					std::swap((*pCard->pB)[j - 1], (*pCard->pB)[j]); 
			}
		}
	
}

void sortByTitle(CARD_INDEX* pCard)
{
	for (int i = 1; i < pCard->count + 1; i++)
		for (int j = i; j < pCard->count; j++) // пока j>0 и элемент j-1 > j,
		{
			if (strcmp((*pCard->pB)[j - 1].title, (*pCard->pB)[j].title) > 0)
			{
				std::swap((*pCard->pB)[j - 1], (*pCard->pB)[j]);
			}
		}
}

void sortByYear(CARD_INDEX* pCard)
{
	for (int i = 1; i < pCard->count + 1; i++)
		for (int j = i; j < pCard->count; j++) // пока j>0 и элемент j-1 > j,
		{
			if ((*pCard->pB)[j - 1].year>(*pCard->pB)[j].year)
			{
				std::swap((*pCard->pB)[j - 1], (*pCard->pB)[j]);
			}
		}
}

void sortByPrice(CARD_INDEX* pCard)
{
	for (int i = 1; i < pCard->count + 1; i++)
		for (int j = i; j < pCard->count; j++) // пока j>0 и элемент j-1 > j,
		{
			if ((*pCard->pB)[j - 1].price > (*pCard->pB)[j].price)
			{
				std::swap((*pCard->pB)[j - 1], (*pCard->pB)[j]);
			}
		}
}

void sortByCategory(CARD_INDEX* pCard)
{
	for (int i = 1; i < pCard->count + 1; i++)
		for (int j = i; j < pCard->count; j++) // пока j>0 и элемент j-1 > j,
		{
			if ((*pCard->pB)[j - 1].category > (*pCard->pB)[j].category)
			{
				std::swap((*pCard->pB)[j - 1], (*pCard->pB)[j]);
			}
		}
}