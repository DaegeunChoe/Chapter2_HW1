#include <iostream>

// �־��� �迭�� ��� ������ ���� ���ϴ� �Լ�
int GetSum(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return sum;
}

// �־��� �迭�� ��� ������ ����� ���ϴ� �Լ�
float GetAverage(int array[], int size)
{
	return GetSum(array, size) / (float)size;
}

// �־��� �迭�� �����ϴ� �Լ�
// intersoin sort ���
void IntersionSort(int array[], int size)
{
	// �迭�� �� ��° ���Һ���, ������ ���ұ��� ����
	for (int n = 1; n < size; n++)
	{
		int target = array[n];
		// n��° ���ҿ� [n-1, 0]��° ���Ҹ� ���Ͽ�, n��° ������ �ڸ��� ã��
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

// ��������
void SortAscending(int array[], int size)
{
	IntersionSort(array, size);
}

// ��������
void SortDescending(int array[], int size)
{
	// ������������ ������ ����, �Ųٷ� ������
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
	std::cout << "���� " << NumCount << "���� �Է� �޽��ϴ�." << std::endl;

	for (int i = 0; i < 5; i++)
	{
		int temp;
		std::cout << (i + 1) << "��° ���� �Է�: ";
		std::cin >> temp;
		inputNumbers[i] = temp;
	}

	std::cout << "�־��� ������ ��: " << GetSum(inputNumbers, NumCount) << std::endl;
	std::cout << "�־��� ������ ���: " << GetAverage(inputNumbers, NumCount) << std::endl;

	int select;
	do
	{
		std::cout << "�迭�� �����մϴ�. 1: ��������, 2: ��������" << std::endl;
		std::cout << "����� �Է�: ";
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

	std::cout << "���ĵ� �迭�� ������ �����ϴ�." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << "��° ����: " << inputNumbers[i] << std::endl;
	}

	return 0;
}