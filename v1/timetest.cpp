#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cmath>

int main(){
    bool state1 = true;


    while(state1){
        std::string user_input = "";
        std::cout << "Choose a test to run, v or input e to exit: ";
        std::cin >> user_input;
        if(user_input == "e"){
            state1 = false;
        }
        if(user_input == "v"){
            bool state2 = true;
            std::vector<int> users_vector;
            std::size_t vector_size = 0;
            std::string temp_input = "";
            std::cout << " \n \nYou have selected the vector function!\n";
            std::cout << "Now, we need some more information...\n";
            std::cout << "How many items would you like in your vector?, please input a valid integer input will not be validated...: ";
            std::cin >> temp_input;
            vector_size = std::stoi(temp_input);
            std::cout << "Great!, we will fill your vector with " << std::to_string(vector_size) << " items!\n";
                for(int i = 0; i < vector_size; i++){
                    users_vector.push_back(rand()%10000);
                    if(i == (std::round(vector_size/4))){
                        std::cout << "25% Filled!\n";
                    }
                    if(i == (std::round(vector_size/2))){
                        std::cout << "50% Filled!\n";
                    }
                    if(i == (std::round((3*vector_size)/4))){
                        std::cout << "75% Filled!\n";
                    }
                }
            int loops = 0;
            while(state2){
                if (loops == 0){
                    std::cout << "Now that we have your vector of " << std::to_string(vector_size) << " we can have some fun with it... We can: \n";
                }
                if(loops > 0 ){
                    std::cout << "Great, we can continue our fun!, Reminder your options are: \n";
                }
                std::cout << "      1. Search to see if a number is in the vector using the search keyword\n";
                std::cout << "      2. Exit the program, and trash out the vector using the exit keyword\n";
                std::cout << "      3. Clear the vector using the clear keyword\n";
                std::cout << "      4. Refill your vector using the fill keyword\n";
                std::cout << "      5. Check the size of your vector using the size keyword\n";
                std::cout << "      6. See inside your vector with the reveal keyword\n";
                std::cout << "Enter a keyword to begin your fun!: ";
                std::cin >> user_input;
                std::cout << "\n\n";
                if(user_input == "exit") state2 = false;
                if(user_input == "search"){
                    std::cout << "You've selected the search function!\n";
                    std::cout << "Your vector contains " << std::to_string(users_vector.size()) << " lovely entries! What would you like us to search for? ";
                    std::cin >> user_input;
                    int goal = std::stoi(user_input);
                    std::vector<int> found_goals_index = {};
                    auto start = std::chrono::high_resolution_clock::now();
                    for(int i = 0; i < users_vector.size(); i++){
                        if(users_vector.at(i) == goal)
                            found_goals_index.push_back(i);
                    }
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> duration = end - start;
                    if(found_goals_index.size() == 0){
                        std::cout << "\n\nOh no!, your number was not found in your vector!";
                    }
                    if(found_goals_index.size() == 1){
                        std::cout << "\n\nCongrats, your number was found at index " << std::to_string(found_goals_index.at(0));
                    }
                    if(found_goals_index.size() > 1){
                        std::cout << "\n\nOh wow, your number was found at all of these indices: ";
                        for(auto index : found_goals_index){
                            std::cout << std::to_string(index) << ", ";
                        }
                    }
                    std::cout << "\nAlso, searching your vector of " << std::to_string(vector_size) << " items took " << duration.count() << " seconds!\n\n\n ";
                    loops = loops + 1;
                }
                if(user_input == "clear"){
                    users_vector.clear();
                    std::cout << "Your vector is now empty!\n\n\n";
                    loops = loops + 1;
                }
                if(user_input == "fill"){
                    std::string temp_user_input;
                    std::cout << "Great, you have selected the refill function\n";
                    std::cout << "How many items do you wish to have in your vector?: ";
                    std::cin >> temp_user_input;
                    vector_size = std::stoi(temp_user_input);
                    std::cout << "Lovely!, we will fill your vector with " << std::to_string(vector_size) << " items!\n";
                    for(int i = 0; i < vector_size; i++){
                        users_vector.push_back(rand()%10000);
                    }
                }
                if(user_input == "size"){
                    std::cout << "Your beautiful vector has a size of " << std::to_string(users_vector.size()) << "\n\n\n";
                    loops = loops + 1;
                }
                if(user_input == "reveal"){
                    for(auto item : users_vector){
                        std::cout << std::to_string(item) << " , ";
                    }
                    std::cout << "\n\n";
                }
            }
        }
    }






    return 1;
}