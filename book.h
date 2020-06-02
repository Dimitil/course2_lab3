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
	book* pB;		//��������� �� ���������
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



void sort(CARD_INDEX* pCard, int (const book& b1, const book& b2));

int cmpAuthor(const book& b1, const book& b2);
int cmpTitle(const book& b1, const book& b2);
int cmpCategory(const book& b1, const book& b2);
int cmpPrice(const book& b1, const book& b2);
int cmpYear(const book& b1, const book& b2);