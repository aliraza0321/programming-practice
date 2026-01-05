  #include <iostream>
#include <queue>
using namespace std;

template <typename T>
class RadixSort {
public:

    // Integer power function (no exp--)
    int intPower(int base, int exp)
    {
        int result = 1;
        while (exp > 0)
        {
            result = result * base;
            exp = exp - 1;
        }
        return result;
    }

    // Extract digit from given position (pos)
    int getDigit(T num, int pos, int base)
    {
        int divisor = intPower(base, pos);
        return (num / divisor) % base;
    }

    // Count digits in any number (no ternary)
    int countDigits(int num, int base)
    {
        if (num == 0)
        {
            return 1;
        }

        int count = 0;
        while (num > 0)
        {
            num = num / base;
            count = count + 1;
        }
        return count;
    }

    // Main Radix Sort
    void sort(T* arr, int n, int base)
    {
        // ---------------- Handle Negative Numbers ----------------
        T minVal = arr[0];
        int i = 1;
        while (i < n)
        {
            if (arr[i] < minVal)
            {
                minVal = arr[i];
            }
            i = i + 1;
        }

        int shift = 0;
        if (minVal < 0)
        {
            shift = -minVal;

            int j = 0;
            while (j < n)
            {
                arr[j] = arr[j] + shift;
                j = j + 1;
            }
        }

        // ---------------- Find Maximum Value ----------------
        T maxVal = arr[0];
        i = 1;
        while (i < n)
        {
            if (arr[i] > maxVal)
            {
                maxVal = arr[i];
            }
            i = i + 1;
        }

        // Digits required
        int k = countDigits(maxVal, base);

        // Create array of queues dynamically
        queue<T>* q = new queue<T>[base];

        // ---------------- Radix Sorting Loop ----------------
        int digit = 0;
        while (digit < k)
        {
            // Insert into buckets
            int a = 0;
            while (a < n)
            {
                int bucketIndex = getDigit(arr[a], digit, base);
                q[bucketIndex].push(arr[a]);
                a = a + 1;
            }

            // Collect elements
            int index = 0;
            int b = 0;

            while (b < base)
            {
                while (!q[b].empty())
                {
                    arr[index] = q[b].front();
                    q[b].pop();
                    index = index + 1;
                }
                b = b + 1;
            }

            digit = digit + 1;
        }

        // ---------------- Remove Shift (restore negatives) ----------------
        if (shift != 0)
        {
            int x = 0;
            while (x < n)
            {
                arr[x] = arr[x] - shift;
                x = x + 1;
            }
        }

        delete[] q;
    }
};

int main()
{
    int n;
    int base;

    cout << "Enter number of elements (n): ";
    cin >> n;

    cout << "Enter base (m): ";
    cin >> base;

    int* arr = new int[n];

    cout << "Enter " << n << " numbers (negative allowed): ";
    int i = 0;
    while (i < n)
    {
        cin >> arr[i];
        i = i + 1;
    }

    RadixSort<int> sorter;
    sorter.sort(arr, n, base);

    cout << "Sorted array: ";
    i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i = i + 1;
    }
    cout << endl;

    delete[] arr;
    return 0;
}
