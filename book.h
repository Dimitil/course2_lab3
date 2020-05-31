#pragma once

//�������� ��������� BOOK, ����������� �����
//(�����, ��������, ��� �������, ����, ����������).
enum  eCategory{FANTASY, ADVENTURE, ROMANCE,\
SCIENCE_FICTION, CHILDRENS, POETRY, OTHER, CATEGORYMAX};

struct book{

	char author[20];
	char title[20];
	int year;
	int price;
	eCategory category;

};

struct CARD_INDEX{
	book** pB;		//��������� �� ���������
	size_t count;   //���������� ���� � ���������
	size_t cap;		//������� ���������
};

void printBook(const book& b);
void initBook(book& b);

void addBook(CARD_INDEX* pCard);
void printAllBooks(const CARD_INDEX* pCard);
void deleteBook(CARD_INDEX* pCard);
void writeToFile(const CARD_INDEX* pCard);
void readFromFile(CARD_INDEX* pCard);
void sortByAuthor(CARD_INDEX* pCard);
void sortByTitle(CARD_INDEX* pCard);
void sortByYear(CARD_INDEX* pCard);
void sortByPrice(CARD_INDEX* pCard);
void sortByCategory(CARD_INDEX* pCard);