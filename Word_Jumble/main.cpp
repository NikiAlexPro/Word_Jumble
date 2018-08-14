#include<iostream>
#include<conio.h>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

enum fields {WORD, HINT, NUM_FIELDS};
const int NUM_WORDS = 5;
const string WORDS[NUM_WORDS][NUM_FIELDS] = {
	{ "ford","Авто производства США" },
{ "audi","Авто производства Германии" },
{ "lamborgini","Авто производства Испании" },
{ "ferarri","Авто производства Италии" },
{ "mersedes","Авто производства Баварии" }
};

int main()
{
	setlocale(0, "RUS");
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	cout << "Welcome to Word Jumble!\n";
	cout << "Введите 'hint' для подсказки\n";
	cout << "Введите 'quit' для выхода из игры\n";
	cout << "Слово :" << jumble;
	string guess; 
	cout << "\n\nВаш ответ: ";
	cin >> guess;
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "\nНеверно!";
		}
		cout << "\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "Вы угадали!";
		_getche();
	}
	if (guess == "quit")
	{
		return 0;
	}
}