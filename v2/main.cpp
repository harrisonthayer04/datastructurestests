#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <chrono>

int main(){
    bool state = true;

    while(state){
        std::string user_input;
        int number_of_items = 0;
        std::cout << "Hello, and welcome to Data Structures comparison game!\n";
        std::cout << "Please specify how many objects you would like to fill your data structures with: ";
        std::cin >> user_input;
        number_of_items = std::stoi(user_input);


        std::vector<int> users_vector;
        std::forward_list<int> users_forward_list;
        std::list<int> users_list;


        // Filling the vector
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < number_of_items; i++){
            users_vector.push_back(rand()%10000);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Filling your vector took " << duration.count() << " seconds!\n";

        // Filling the sll
        auto start2 = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < number_of_items; i++){
            users_forward_list.push_front(rand()%10000);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration2 = end2 - start2;
        std::cout << "Filling your sll took " << duration2.count() << " seconds!\n";

        // Filling the dll
        auto start3 = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < number_of_items; i++){
            users_list.push_front(rand()%10000);
        }
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration3 = end3 - start3;
        std::cout << "Filling your dll took " << duration3.count() << " seconds!\n";



    }



    return 1;
}