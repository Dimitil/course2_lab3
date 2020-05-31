/*************************************************************
	������������ ������� �3-����-�110. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "book.h"


#define stop __asm nop

book global_book;



void main()
{
//���� "������" ��������� ������� ����������� ����������
//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
	printf("Tema. 1. Enter A, B, C\n");

	double A = 0, B = 0, C = 0;
	//scanf("%lf%lf%lf", &A, &B, &C);

//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
//��� ��������� x � ��������� -2 �� +2 � ����� 0.5
	double x = -2;
	while(x <= 2)
	{
		double y = A * x * x + B * x + C;
		printf("|x= %6.2lf|%6.2lf|\n", x, y);
		x += 0.5;
	}
	printf("\n");
	stop

		//����. ��������� �.	
		//������� 1.1 �������� ��������� BOOK, ����������� �����
		//(�����, ��������, ��� �������, ����, ����������).
		//���������: ������ ���� ����� ���� ���� ���������.
		//���������: ���������� ��������� ������������� ��������
		//� ������������ ����.

			//������� 1.2. �������� ������� ��������� (����������, ���������, �����������,
			//������������) ���������� (�������) ���� BOOK (��� �������������).
			//���������� - ������� ������ ������� ���������� ��� ������
			//����� ������. ��� ���������������� (��� �� ����������������) ����
			//���������. ���������: �� ���� ������� ����� ���������� ������?

		book local_book;
		static book static_book;
		book* dynamic_book = new book;

		stop

		std::cout << "\nGlobal object: "<<sizeof(global_book);
		std::cout << "\nLocal object: " << sizeof(local_book);
		std::cout << "\nStatic object: " << sizeof(static_book);
		std::cout << "\nDynamic book: " << sizeof(*dynamic_book);

		
			//������� 1.3. �������� �������, ��������� �� ����� ��������� �����.
			//���������: ��� ����������� ���������� ��������� BOOK � �������.
			//��� ������ �� ������� ����������� ������� ����������� ����������
			//printf
	

			//������� 1.4. �������� ������� ��� ������������ ����� ���������.
			//��� ����� ����������� ������� ����������� ���������� scanf
			//���������: ������� �������� � ����� ������� ����������� ��������
			//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
			//�����, ���... (��� ��������� ������������), ��������� �����������
			//������ �������� �� ������������, ���� �� ����� ���� �������������...


			//����������� ��������� BOOK, ��������� � ���������� �������.
			//��� ����� ���������� ���������� � ���������� � ������� �����
			//book.h � book.cpp

			//������� 2. ������� ����������.
			//���������� - ��� ������ �������� => ����� ����� ������ �������.
			//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
			//������ ������ ���� ����� ������???	


				   

			//������������ ������ ����� ����������� �� ������ ������� ���������
			//������ �������� � ���������� => ����� ����� ����������� ���
			//������������: ��� ����� ��������� ��� ����� "����" (��������
			//��������� �������� � ��������������� ������� ������������), ��������:
			//����������� ���������� ��������� (1)
			//������ ����� ����� (2)
			//������� ������������(��) (3)
			//�������� ������� ���������� ��������� � ���� (4)
			//������� �� ����� ���������� � ��������� (5)
			//...
			//����� �� ��������� (...)

		CARD_INDEX book_list;		//������������� ���������

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
	//���������� ����������� ������� ������ ����������� ������ � ����������
	
	// ���������:
	//1. ����� ����� � �������� ����� ������� �� ������ �����
	//2. ��� ������ ����� �������� ���������� �������. ���� �������
	//   �� ������ ��������, �� � ������� ������� �������, �������
	//   �) ������������ ������������ ��������� �����/������ - wprintf(), wscanf()
	//   �) ������� ������ ��� ����������� - wchar_t
	//   �) ���������� ��������� - setlocale(LC_CTYPE, ".866");	
	

	//���������1: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>



	// ���������2: ������ � �������� ������� ������� � ����� ������� ����������
	// ���� � ���������
	//���� ���� ���������� � ��� ������� �������
	//if()
	//{
	//������ ������ �� �����
	//�) ������� ���������� ���������
	//�) ������� ������ ��������� �����������
	//�) ������� ������ �� ����� � ������
	//}




	//****************************************************************
	//������� 3. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.



}