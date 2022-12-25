// Lab1_Kyzylova_ConsoleTask4_V11.cpp: определяет точку входа для консольного приложения.
//
/*
***************************************************************************************
*Лабораторная работа №1                                                               *
*Задача №1                                                                            *
*                                                                                     *
*Условие:                                                                             *
*Сравнить эффективность сортировки массивов Tree Sort с классическими сортировками    *
*массивов (Bubble Sort, Insertion Sort, Selection Sort), количество элементов         *
*в массиве не менее 100 тысяч. Определить наиболее эффективную сортировку.            *
*                                                                                     *
*Выполнила:                                                                           *
*Кызылова Полина Андреевна                                                            *
*Группа: ПКТб-20-1                                                                    *
*                                                                                     *
*Дата: 16.02.2021                                                                     *
***************************************************************************************
*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct tree
{
	int a;
	struct tree *left;
	struct tree *right;
};

struct tree *add_to_tree(tree *root, int x)
{
	if (root == NULL)
	{
		root = new tree;
		root->a = x;
		root->left = root->right = 0;
		return root;
	}
	if (root->a < x)
	{
		root->right = add_to_tree(root->right, x);
	}
	else
	{
		root->left = add_to_tree(root->left, x);
	}
	return root;
}

void tree_to_array(tree *root, int a[])
{
	static int max2 = 0;

	if (root == NULL) return;

	tree_to_array(root->left, a);
	a[max2++] = root->a;
	tree_to_array(root->right, a);
	free(root);
}

void sort_tree(int mas[], int y)                                    
{
	tree *root;
	int i;

	root = NULL;
	for (i = 0; i < y; i++)
	{
		root = add_to_tree(root, mas[i]);
	}
	tree_to_array(root, mas);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Задача №4, Вариант №11" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Условие задачи:" << endl;
	cout << "Определить эффективность сортировки массивов" << endl;
	cout << "Tree Sort (Сортировка с помощью бинарного дерева)" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << endl;

	srand(time(0));

	const int n = 100000;
	int i;
	int mas[n];

	for (i = 0; i < n; i++)
	{
		mas[i] = rand() % 1000;
	}

	int TimeStart;
	int TimeEnd;
	unsigned int TimeWork;

	TimeStart = clock();

	sort_tree(mas, n);
	
	TimeEnd = clock();
	TimeWork = TimeEnd - TimeStart;

	cout << "Отсортированный массив:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	
	cout << "------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Скорость выполнения сортировки Tree Sort: " << TimeWork << " милисек." << endl;

	cout << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Лабораторную работу №1 выполнила Кызылова Полина Андреевна" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << endl;

	system("Pause");
	return 0;
}

