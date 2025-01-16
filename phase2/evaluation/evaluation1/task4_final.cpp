#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

const int MAX_SIZE = 10;

int randNum(int start, int end)
{
    int diff = (end - start);
    int num = ((rand() % diff) + start);
    return num;
}

int getSliceCount(int size)
{

    int slices_count;

    int slices_count_by_5 = size / 5;

    if (slices_count_by_5 == 0)
    {
        slices_count = 1;
    }
    else if (slices_count_by_5 < 10)
    {
        slices_count = slices_count_by_5;
    }
    else
    {
        slices_count = randNum(10, std::min(slices_count_by_5, 200));
    }
    return slices_count;
}

double findSum(const std::vector<double> &vec, int start, int end)
{
    double sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += vec[i];
    }
    return sum;
}

double findSum(const std::vector<double> &vec)
{
    std::vector<double> result;

    int vecSize = vec.size();

    int SLICE = getSliceCount(vecSize);
    std::cout << "Generated random number: " << SLICE << std::endl;

    int sliceSize = vecSize / SLICE;
    // int offset = vecSize % SLICE;
    std::cout << "Number of slices: " << SLICE << std::endl;

    for (int i = 0; i < SLICE; i++)
    {

        int start = i * sliceSize;
        int end = start + sliceSize;
        if (i == (SLICE - 1))
        {
            end = vecSize;
        }

        // if (end > vecSize)
        //{
        //     end = vecSize;
        // }

        double res = findSum(vec, start, end);
        result.push_back(res);
    }

    int finalSum = 0;
    for (int i = 0; i < result.size(); i++)
    {
        // std::cout << "Sum of slice " << (i + 1) << " is: " << result[i] << std::endl;
        finalSum += result[i];
    }
    return finalSum;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    std::vector<double> vec;

    int vecSize;
    std::cout << "Enter number of elements: ";
    std::cin >> vecSize;

    double inputData;
    std::cout << "Enter values:" << std::endl;
    for (int i = 0; i < vecSize; i++)
    {
        // std::cout << "[" << i << "]: "; std::cin >> inputData;
        inputData = 1;
        vec.push_back(inputData);
    }

    double finalSum = findSum(vec);
    std::cout << "Sum of all elements: " << std::setprecision(15) << finalSum << std::endl;
    return 0;
}
