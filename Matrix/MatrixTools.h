#pragma once

#include <cctype>
#include <time.h>
#include <type_traits>
#include <cstdint>
#include <iostream>

namespace Matrix
{
	namespace Tools
	{
		template<typename ValueType, typename IsValueValidFunction>
		ValueType GetValueFromUser(const char* message, IsValueValidFunction isValueValid)
		{
			using namespace std;

			ValueType value = 0;
			bool isValueInvalid = true;

			while (isValueInvalid)
			{
				cout << message << ": ";
				cin >> value;

				bool isStreamInFailureState = cin.fail();
				isValueInvalid = isStreamInFailureState || !isValueValid(value);

				if (isValueInvalid)
				{
					if (isStreamInFailureState)
						cin.clear();// ���������� ������ ������ � ������� �����
					cout << "Value is invalid. Try enter again. " << endl;
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			system("cls");

			return value;
		}
	}
}