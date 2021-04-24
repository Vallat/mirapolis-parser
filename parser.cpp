#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	wchar_t length[1024], link[10000], path[10000], read_link[10000], read_path[10000];
	long int len = 1;
	FILE* file = fopen("input.txt","r");
	if (file == NULL) {
		std::cout << "You need file \"input.txt\"!";
		return 0;
	}

	std::cout << "Started downloading, please wait... \n";
	fgetws(read_link, 10000, file);
	*wcschr(read_link, '\n') = '\0';
	fgetws(read_path, 10000, file);
	*wcschr(read_path, '\n') = '\0';
	fgetws(length, 1024, file);
	len = wcstol(length, NULL, 10);
	for (int i = 1; i <= len; i++) {
		swprintf(link, 10000, L"%simg%d.png", read_link, i);
		swprintf(path, 10000, L"%s%d.png", read_path, i);
		URLDownloadToFile(0, link, path, 0, 0);
	}
	fclose(file);
	std::cout << "Downloaded " << len << " images successfuly! :)\n";
	std::cout << "\nPress any key to continue...";
	_getch();
}