#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

void input_arr(char*);
void check_arr(const char*);
void find_max_length_words(char*, const char*);

int main()
{
	try
	{
		char MyArr[301];
		char MySeparator[302];
		std::cout << "input string" << '\n';
		input_arr(MyArr);
		check_arr(MyArr);
		std::cout << "input separators" << '\n';
		input_arr(MySeparator);
		strcat(MySeparator, " " );
		find_max_length_words(MyArr, MySeparator);
	}
	catch (const char* msq)
	{
		std::cout << msq;
	}
}
void input_arr(char* myarr)
{
	std::cin.getline(myarr, 301);
}
void check_arr(const char* myarr)
{
	if (strlen(myarr) == 0)
	{
		throw "string is empty";
	}
}
void find_max_length_words(char* MyArr, const char* MySeparator)
{
	size_t size = strlen(MyArr);
	char PrintArr[301] = "";
	char TempArr[301] = "";
	size_t size_sep = strlen(MySeparator);
	int16_t max_length = 0;
	int16_t temp_length = 0;
	bool check = true;
	bool check_bacspace;
	for (size_t i = 0; i < size; ++i)
	{
		check_bacspace = false;
		for (size_t k = 0; k < size_sep; ++k)
		{
			if (MyArr[i] == MySeparator[k])
			{
				MyArr[i] = ' ';
				k = size_sep;
			}
		}
		if (MyArr[i] == ' ')
		{
			temp_length = 0;
			TempArr[0] = '\0';
			check_bacspace = true;
		}
		else if (MyArr[i] != ' ')
		{
			++temp_length;
			size_t len = strlen(TempArr);
			TempArr[len] = MyArr[i];
			TempArr[len + 1] = '\0';
			for (size_t j = 0; j < temp_length -1;++j)
			{
				if (TempArr[j] > TempArr[j + 1])
				{
					check = false;
					break;
				}
			}
			if (temp_length == max_length)
			{
				if (check)
				{
					strcat(PrintArr, TempArr);
					strcat(PrintArr, " ");
				}
			}
			if (temp_length > max_length)
			{
				if (check)
				{
					max_length = temp_length;
					PrintArr[0] = '\0';
					strcat(PrintArr, TempArr);
					strcat(PrintArr, " ");
				}
			}
		}
		if (check_bacspace == true)
		{
			check = true;
		}
	}
	for (size_t i = 0; i < strlen(PrintArr); ++i)
	{
		std::cout << PrintArr[i];
	}
}