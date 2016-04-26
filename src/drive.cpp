#include <iostream>
#include "les_v1.h"
#include <cassert>

int main(int argc, char const *argv[])
{

    SNPtr pHead = NULL;  // nullptr;
    std::string message = "\nActual Length of the list: ";
    int value = 0;
    pushFront(pHead, 1);
    pushFront(pHead, 2);
    pushFront(pHead, 3);
    pushFront(pHead, 4);

    std::cout << message << length(pHead) << "\n\n";

    print(pHead);

    pushBack(pHead, 5);

    print(pHead);

    std::cout << message << length(pHead) << "\n\n";

    front(pHead, value);

    std::cout << "Front value is: "<< value << "\n\n";

    back(pHead, value);

    std::cout << "Back value is: "<< value << "\n\n";

    if(!empty(pHead))
        std::cout << "List isn't empty!\n" << std::endl;
    else{
        std::cout << "List is empty! Contains this values\n"<< std::endl;
        print(pHead);
    }

    clear(pHead);

    print(pHead);

    std::cout << message << length(pHead) << "\n\n";

    std::cout << ">>>Refilling list!\n" << std::endl;
    pushFront(pHead, 1);
    pushFront(pHead, 2);
    pushFront(pHead, 3);
    pushFront(pHead, 4);

    std::cout << message << length(pHead) << "\n\n";

    std::cout << ">>>STARTING POP FRONT!" << std::endl;
    popFront(pHead, value);

    std::cout << "Poped value was: "<< value << "\n\n";

    std::cout << ">>>AFTER POP FRONT!\n" << std::endl;
    print(pHead);
    std::cout << "\n";

    std::cout << message << length(pHead) << "\n\n";

    std::cout << ">>>STARTING POP BACK!\n" << std::endl;
    popBack(pHead, value);

    std::cout << "Poped value was: "<< value << "\n\n";

    std::cout << ">>>AFTER POP BACK!\n" << std::endl;
    print(pHead);
    std::cout << "\n";

    std::cout << message << length(pHead) << "\n\n";

    std::cout << ">>>STARTING SEARCH FOR ITEM 2! \n" << std::endl;
    SNPtr searchedLink = find(pHead, 2);

    std::cout << ">>>ITEM SEARCHED!" << std::endl;
    print(searchedLink);

    std::cout << ">>>STARTING INSERTS! \n" << std::endl;
    insert(pHead, pHead->mpNext, value);

    std::cout << ">>>AFTER INSERT!\n" << std::endl;
    print(pHead);

    std::cout << message << length(pHead) << "\n\n";


    std::cout << "\n";

    std::cout << ">>>STARTING REMOVE! \n" << std::endl;
    remove(pHead, pHead->mpNext, value);

    std::cout << ">>>AFTER REMOVE!\n" << std::endl;
    print(pHead);

    std::cout << message << length(pHead) << "\n\n";

    std::cout << "\n";

	return EXIT_SUCCESS;
}
