#include <iostream>

// 주어진 배열의 모든 원소의 합을 구하는 함수
int GetSum(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum;
}

// 주어진 배열의 모든 원소의 평균을 구하는 함수
float GetAverage(int array[], int size)
{
	return GetSum(array, size) / (float)size;
}

// 주어진 배열을 정렬하는 함수
// intersoin sort 사용
void IntersionSort(int array[], int size)
{
	// 배열의 두 번째 원소부터, 마지막 원소까지 정렬
	for (int n = 1; n < size; n++)
	{
		int target = array[n];
		// n번째 원소와 [n-1, 0]번째 원소를 비교하여, n번째 원소의 자리를 찾음
		for (int i = n-1; i >= 0; i--)
		{
			if (array[i] > array[i+1])
			{
				// swap
				int t = array[i];
				array[i] = array[i+1];
				array[i+1] = t;
			}
			else
			{
				break;
			}
		}
	}
}

// 오름차순
void SortAscending(int array[], int size)
{
	IntersionSort(array, size);
}

// 내림차순
void SortDescending(int array[], int size)
{
	// 오름차순으로 정렬한 다음, 거꾸로 뒤집음
	IntersionSort(array, size);
	for (int n = 0; n < size / 2; n++)
	{
		int t = array[n];
		array[n] = array[size - n - 1];
		array[size - n - 1] = t;
	}
}

int main()
{
	const int NumCount = 5;
	int inputNumbers[NumCount];
	std::cout << "숫자 " << NumCount << "개를 입력 받습니다." << std::endl;

	for (int i = 0; i < 5; i++)
	{
		int temp;
		std::cout << (i + 1) << "번째 숫자 입력: ";
		std::cin >> temp;
		inputNumbers[i] = temp;
	}

	std::cout << "주어진 숫자의 합: " << GetSum(inputNumbers, NumCount) << std::endl;
	std::cout << "주어진 숫자의 평균: " << GetAverage(inputNumbers, NumCount) << std::endl;

	int select;
	do
	{
		std::cout << "배열을 정렬합니다. 1: 오름차순, 2: 내림차순" << std::endl;
		std::cout << "당신의 입력: ";
		std::cin >> select;
	} while (!(select == 1 || select == 2));
	
	if (select == 1)
	{
		SortAscending(inputNumbers, NumCount);
	}
	else // select == 2
	{
		SortDescending(inputNumbers, NumCount);
	}

	std::cout << "정렬된 배열은 다음과 같습니다." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << "번째 숫자: " << inputNumbers[i] << std::endl;
	}

	return 0;
}