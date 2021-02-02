#include "pet.h"

int main()
{
    std::vector<Pet> pet_list;
   
    Pet name1(BRUNO, DOG, 6);
    Pet name2(STINKY, CAT, 7);
    Pet name3(BOB, RABBIT, 8);
    Pet name4(FAST, HORSE, 9);

    pet_list.push_back(name1);
    pet_list.push_back(name2);
    pet_list.push_back(name3);
    pet_list.push_back(name4);

    for (int i = 0; i < pet_list.size(); i++)
    {
        std::cout << pet_list[i].to_string() << std::endl;
    }

    return 0;
}
