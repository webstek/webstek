#include <iostream>
#include <list>

// Custom sort operator
struct customStringCompare {
    bool operator() (const std::string &str1, const std::string &str2) {
        if (str1.length() > str2.length()) {
          return true;
        } else if (str1.length() == str2.length()) {
            return str1 > str2;
        } else {
            return false;
        }
    }
};

// Immutable function for modifying the list
std::list<std::string> listMod(const std::list<std::string> inList, std::list<std::string> addList, std::list<std::string> delList) {
    /* returns a new list of strings with addList added to origList, delList
       removed from that, and sorted longest to shortest, reverse alphabetical 
       if same length. */
    using namespace std;

    // set list to be modified as the copy of the input list
    list outList = inList;
    // add the new items
    outList.merge(addList);

    // remove items on the remove list
    for (string s : delList) {
        outList.remove(s);
    }

    // Custom sort longest string to shortest, reverse alphabetical in ties
    outList.sort(customStringCompare());
    // Remove duplicate elements
    outList.unique();

    return outList;
}

int main() {
    using namespace std;

    // Test lists
    list<string> inList, addList, delList;
    inList = {"red", "green", "orange", "green"};
    addList = {"blue", "cyan", "pink"};
    delList = {"orange", "purple"};

    // Modify the list
    list outList = listMod(inList, addList, delList);

    // Print resulting list
    for (std::string s : outList) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}