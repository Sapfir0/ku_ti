#include <algorithm>>

void Bubble_sort(int *a, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				std::swap(a[i], a[j]);
		}
	}
}

void Merge_sort(int *a, int n)
{
  int mid = n / 2;
  if (n % 2 == 1)
    mid++;
  int h = 1;

  int *c = new int[n];
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;
    int j = mid;
    int k = 0;
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      {
        if (a[i] < a[j])
        {
          c[k] = a[i];
          i++; k++;
        }
        else {
          c[k] = a[j];
          j++; k++;
        }
      }
      while (i < step)
      {
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n))
      {
        c[k] = a[j];
        j++; k++;
      }
      step = step + h;
    }
    h = h * 2;

    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
  delete[] c;
}

void Qsort(int * mas, int left, int right) {
    //Указатели в начало и в конец массива
    int i = left;
    int j = right;

    //Центральный элемент массива
    int mid = mas[(i+j)/2];

    //Делим массив
    while (i <= j) {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) /*mas[i] < mid*/
        {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) /*mas[j] > mid*/
        {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
			std::swap(mas[i], mas[j]);
            i++;
            j--;
        }
    }

    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > left) {
        //"Левый кусок"
        Qsort(mas, left, j);
    }
    if (i < right) {
        //"Прaвый кусок"
        Qsort(mas, i, right);
    }
}

void Tree_sort (int a[], int size_array)
{
    ;
}

void Radix_sort(int *a, int size_array)
{
  int i;

  // find the max number in the given list.
  // to be used in loop termination part.
  int maxNumber = a[0];
  for (i = 1; i < size_array; i++)
  {
    if (a[i] > maxNumber)
      maxNumber = a[i];
  }

  // run the loop for each of the decimal places
  int exp = 1;
  int *tmpBuffer = new int[size_array];
  while (maxNumber / exp > 0)
  {
    int decimalBucket[10] = {  0 };
    // count the occurences in this decimal digit.
    for (i = 0; i < size_array; i++)
      decimalBucket[a[i] / exp % 10]++;

    // Prepare the position counters to be used for re-ordering the numbers
    // for this decimal place.
    for (i = 1; i < 10; i++)
      decimalBucket[i] += decimalBucket[i - 1];

    // Re order the numbers in the tmpbuffer and later copy back to original buffer.
    for (i = size_array - 1; i >= 0; i--)
      tmpBuffer[--decimalBucket[a[i] / exp % 10]] = a[i];
    for (i = 0; i < size_array; i++)
      a[i] = tmpBuffer[i];

    // Move to next decimal place.
    exp *= 10;

//      cout << "\nPASS   : ";
//      print(a, n);
  }
  delete[] tmpBuffer;
}
