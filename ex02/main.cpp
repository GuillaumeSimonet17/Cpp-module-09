#include "PmergeMe.hpp"

double getTimeDifferenceInMicroseconds(const timeval& startTime, const timeval& endTime)
{
    double startMicroseconds = startTime.tv_sec * 1000000LL + startTime.tv_usec;
    double endMicroseconds = endTime.tv_sec * 1000000LL + endTime.tv_usec;
    
    return endMicroseconds - startMicroseconds;
}

template<typename T>
void merge(T& arr, typename T::iterator leftIt, typename T::iterator midIt, typename T::iterator rightIt) {
    (void)arr;
    T mergedList;
    typename T::iterator left = leftIt;
    typename T::iterator mid = midIt;
    typename T::iterator right = rightIt;
    typename T::iterator it1 = leftIt;
    typename T::iterator it2 = midIt;

    while (it1 != mid && it2 != right) {
        if (*it1 <= *it2) {
            mergedList.push_back(*it1);
            ++it1;
        } else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != mid) {
        mergedList.push_back(*it1);
        ++it1;
    }

    while (it2 != right) {
        mergedList.push_back(*it2);
        ++it2;
    }

    std::copy(mergedList.begin(), mergedList.end(), left);
}

template<typename T>
void mergeSort(T& arr, typename T::iterator left, typename T::iterator right, int k) {
    

    if (std::distance(left, right) > 1) {
        if (std::distance(left, right) < k) {
            typename T::iterator it = left;
            ++it;
            while (it != arr.end()) {
                int key = *it;
                // typename T::iterator j = std::prev(it);
                typename T::iterator j = it;
                std::advance(j, -1);
                while (j >= arr.begin() && *j > key) {
                    *(j + 1) = *j;
                    --j;
                }
                *(j + 1) = key;
                ++it;
            }
        } else {
            // typename T::iterator mid = std::next(left, std::distance(left, right) / 2);
            typename T::iterator mid = left;
            std::advance(mid, std::distance(left, right) / 2);


            mergeSort(arr, left, mid, k);
            mergeSort(arr, mid, right, k);
            merge(arr, left, mid, right);
        }
    }
}

int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "Error: Not enough args" << std::endl; 
        return 1;
    }
    av = &av[1];
    timeval startTime, endTime;
    timeval startTime2, endTime2;

    Pmergeme<std::vector<int> >   vect(ac-1);
    // Pmergeme<std::vector<int> >  v(ac-1);
    // v = vect;
    try {
        vect.setContainer(ac-1, av);
    } catch (const Pmergeme<std::vector<int> >::NegativeNumber& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    Pmergeme<std::deque<int> >   deq(ac-1);
    try {
        deq.setContainer(ac-1, av);
    } catch (const Pmergeme<std::deque<int> >::NegativeNumber& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    int threshold = 16;

    std::cout << "\n---------- VECTOR : ----------\n";
    std::cout << "\nBefore: ";
    // vect.printContainer();
    std::vector<int>::iterator itBv = vect.getContainer().begin();
    std::vector<int>::iterator itEv = vect.getContainer().end();
    gettimeofday(&startTime, NULL);
    mergeSort(vect.getContainer(), itBv, itEv, threshold);
    std::cout << "\nAfter: ";
    // vect.printContainer();
    gettimeofday(&endTime, NULL);
    double delta = getTimeDifferenceInMicroseconds(startTime, endTime);
    std::cout << "\nTime to process a range of " << ac-1 << " elements with std::vector<int> : " << delta << " us\n";

    std::cout << "\n---------- DEQUE : ----------\n";
    std::cout << "\nBefore: ";
    // vect.printContainer();
    std::deque<int>::iterator itBd = deq.getContainer().begin();
    std::deque<int>::iterator itEd = deq.getContainer().end();
    gettimeofday(&startTime2, NULL);
    mergeSort(deq.getContainer(), itBd, itEd, threshold);
    std::cout << "\nAfter: ";
    // deq.printContainer();
    gettimeofday(&endTime2, NULL);
    delta = getTimeDifferenceInMicroseconds(startTime2, endTime2);
    std::cout << "\nTime to process a range of " << ac-1 << " elements with std::deque<int> : " << delta << " us\n";


    return 0;
}

