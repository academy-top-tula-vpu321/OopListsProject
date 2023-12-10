#include <iostream>
#include "ListSingle.h"

int main()
{
    ListSingle<int> list;

    list.PushBack(100);
    list.PushFront(200);
    list.PushFront(300);
    list.PushBack(400);
    list.PushBack(500);
    list.Insert(2, 600);

    std::cout << "\n--- list start ----\n";
    list.List();
    std::cout << "--- list finish ----\n\n";

    /*std::cout << "pop = " << list.PopBack() << "\n";
    std::cout << "pop = " << list.PopBack() << "\n";
    std::cout << "pop = " << list.PopBack() << "\n";

    std::cout << "\n--- list start ----\n";
    list.List();
    std::cout << "--- list finish ----\n\n";

    std::cout << "pop = " << list.PopFront() << "\n";
    std::cout << "pop = " << list.PopFront() << "\n";
    std::cout << "pop = " << list.PopFront() << "\n";*/

    std::cout << "remove 4 = " << list.Remove(4) << "\n";

    std::cout << "\n--- list start ----\n";
    list.List();
    std::cout << "--- list finish ----\n\n";

    std::cout << "\n--- iterator start ----\n";
    for (auto it = list.Iterator(); !it.IsEnd(); it.Next())
        std::cout << it.Current() << " ";
    std::cout << "\n--- iterator finish ----\n";

}
