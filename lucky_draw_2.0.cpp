#include<iostream>
#include<array>
#include<algorithm>
#include<ctime>
#include<random>
#include<vector>

using names_container = std::vector<std::string>;
using numbers_container = std::vector<int>;

struct Data_base
{
    std::string names;
    int number;
};

int get_range()
{
    int usr_input;
    std::cin>>usr_input;

    return usr_input;
}

int main()
{
    std::cout<<"\n\t\t\t\t Project Lucky Draw v.2.0\n\n";

    std::cout<<"\n Register how many people will be participated in this program : ";
    int participators{get_range()};

#if 0
    std::vector<std::string> names_list;
    std::vector<int> numbers_list;
    names_list.resize(participators);
    numbers_list.resize(participators);
            
    int counter{0};

    for(int assign{0}; assign < participators; assign++)
    {
        std::cout<<"\n Enter Participator #"<<counter<<" 's name : ";
        std::cin>>names_list[assign];
        numbers_list[assign] = assign + 2;
        counter++;
    }

    for(std::string name : names_list)
    {
        std::cout<<"\n"<<name;
    }

    std::cout<<std::endl;

    for(int number : numbers_list)
    {
        std::cout<<"\n"<<number;
    }

    std::mt19937 twister{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(names_list.begin(), names_list.end(), twister);
    std::shuffle(numbers_list.begin(), numbers_list.end(), twister);

    std::cout<<std::endl;

    for(int count{0}; count < participators; count++)
    {
        std::cout<<"\n"<<names_list[count]<<" "<<numbers_list[count];
    }
#endif

    std::vector<Data_base> data_base;
    data_base.resize(participators);
    int counter{1};

    for(int assign{0}; assign < participators; assign++)
    {
        std::cout<<"\nRegister participator #"<<counter<<" 's name : ";
        std::cin>>data_base[assign].names;
        data_base[assign].number = assign + 2;

        counter++;
    }

    std::mt19937 twist {static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(data_base.begin(), data_base.end(), twist);

    std::cout<<std::endl;

    for(Data_base print : data_base)
    {
        std::cout<<"\n"<<print.names<<" "<<print.number;
    }

    return 0;
}


