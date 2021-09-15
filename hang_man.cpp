#include<iostream>
#include<vector>
#include<string>
#include<random>
#include<ctime>
#include<array>

void stick_man()
{
    std::vector<char> hang_man
    {
        '|','_','_','_','_','_','_','_','_','\n',
        '|',' ','/',' ',' ','|','\n',
        '|','/',' ',' ',' ','O','\n',
        '|',' ',' ',' ','/','|',92,'\n',
        '|',' ',' ',' ',47 ,' ',92,'\n',
        '|','\n',
        '|','_','_','_','_','_','_','_','_','\n',
    };

    for(char print : hang_man)
    {
        std::cout<<print;
    }

    std::cout<<"\n\n-----------------------------------------------\n\n";
}

std::array<char, 52> hang_man
    {
        '|','_','_','_','_','_','_','_','_','\n',
        '|',' ','/',' ',' ',' ','\n',
        '|','/',' ',' ',' ',' ','\n',
        '|',' ',' ',' ',' ',' ',' ','\n',
        '|',' ',' ',' ',' ',' ',' ','\n',
        '|','\n',
        '|','_','_','_','_','_','_','_','_','\n',
    };

void attempts(int count)
{

    std::array<int,8> index {0,15, 22, 28, 29, 30, 36, 38};
    std::array<char,8> attempt {' ','|', 'O','/','|',92,'/',92};



    hang_man[index[count]] = attempt[count];

    for (char print : hang_man)
    {
        std::cout<<print;
    }

}

int ran_gen(int init, int end)
{
    std::mt19937 twister { static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::uniform_int_distribution<> generator(init, end);

    return generator(twister);
}


std::vector<char> hints_vector;

void print_hints(std::vector<char> hints_vector)
{
    std::cout<<std::endl;

    std::cout<<"  Hint\n";
    std::cout<<"|\n ->   ";

    for(char print : hints_vector)
    {
        std::cout<<print<<" ";
    }
    
    std::cout<<std::endl;
}

void initial_hint(std::string answer)
{
    std::size_t length { answer.size() };

    hints_vector.resize(length);
    int count{0};

    for (char print : hints_vector)
    {
        hints_vector[count] = '_';
        count++;
    }

    print_hints(hints_vector);

}

void hints(char correct, int index)
{
    int count{0};

    hints_vector[index] = correct;

    print_hints(hints_vector); 
}


std::string categories()
{
    std::vector<std::string> foods {"apple", "pizza", "pie", "omelet"};
    std::vector<std::string> vehicles {"car", "bicycle", "bike", "plane"};
    std::vector<std::string> computers {"asus", "dell", "mac", "acer"};

    int category { ran_gen(0, 2) };

    if (category == 0)
    {
        std::cout<<"\n\t\t -> Food \n";
        return foods[ran_gen(0,3)]; 
    }

    else if (category == 1)
    {
        std::cout<<"\n\t\t -> Vehicle \n";
        return vehicles[ran_gen(0,3)];
    }

    else
    {
        std::cout<<"\n\t\t -> Computer \n";
        return computers[ran_gen(0,3)];
    }

    return 0;
}

std::vector<char> string_char_converter()           //Convert strings into char 
{

    std::string pick { categories() };
    std::vector<char> answer;
    std::size_t size {pick.size()};
    answer.resize(size);

    std::cout<<std::endl;

    initial_hint (pick);        // This function call shows how many letter in the hidden answer for player to guess in given category

    std::cout<<std::endl;
    
    int count{0};

    for(char assign : pick)
    {
        answer[count] = assign;
        count++;
    }

    return answer;
}

char usr_input()
{
    std::cout<<"\n =>> ";
    char usr_input;
    std::cin>>usr_input;

    std::cout<<"\n"<<"_______________________________________________\n";

    return usr_input;
}

int game_situation(int progress, int end_point, int lives)      // Decide whether player wins or lose the game
{
    if (progress == end_point)
    {
        std::cout<<"\n"<<"_______________________________________________\n";
        std::cout<<"\n\n\t\t Congratulation! You Win \n\n";
        std::cout<<" > Thanks for Playing!\n\n";
        std::cout<<"\n"<<"_______________________________________________\n";

        return 0;
    }
    
    else if(lives < 1)
    {
        std::cout<<"\n"<<"_______________________________________________\n";
        std::cout<<"\n\n\t\t GameOver\n\n";
        std::cout<<" > Thanks for Playing\n\n";
        std::cout<<"\n"<<"_______________________________________________\n";

        return 1;
    }

    return 2;
}


int spell_check( std::vector<char> answer )         // Check for user_input with actual answer
{
    int lives { 7 };
    int progress{0};
    std::size_t length { answer.size() };
    int check {0};

    std::cout<<std::endl;

#if 0
    for( char print : answer )
    {
        std::cout<<print;
    }
#endif

    for ( int count{ 0 }; count < lives; )       
    {
        char user_input {usr_input()};
        char corrected_letter;

        for(int search{0}; search < length; search++)
        {

            if(user_input == answer[search] )
           {
              //std::cout<<"\ncorrect\n";
              attempts(check);
              corrected_letter = answer[search];
              answer[search] = 0;
              progress++;

              hints(user_input, search);

              int game {game_situation(progress, length, lives)};
              
              if( game == 0 )
              {
                  return 0;
              }

              else
              {
                  break;
              }      
           }

        
            else if( user_input != answer[search] && search == length - 1)
           {
              //std::cout<<"\nincorrect\n";
              check++;
              attempts(check);
              print_hints(hints_vector);
              

              lives--;
              game_situation(progress, length, lives);
              break;
           }
        }
    }

    return 0;
}


void base_game()
{
    std::vector<char> answer{string_char_converter()};
                                                        // Convert strings(foods,vehicles,etc...) stored inside their categories into a char array...
                                                       // to check usr_input is corrent or not with each letter
    spell_check(answer);
}

void user_interface()
{
    stick_man();
}

int main()
{
    std::cout<<"\n\t\t\t Project Hang Man :\n\n";

    user_interface();

    base_game();

    return 0;
}
