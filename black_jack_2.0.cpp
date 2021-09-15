#include<iostream>
#include<array>
#include<vector>
#include<random>
#include<ctime>
#include<algorithm>
#include<unistd.h>
#include<chrono>

enum Suits
{
    Club,
    Diamond,
    Heart,
    Spade,

    Max_Suit
};

enum Ranks
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    King,
    Queen,
    Ace,

    Max_Ranks
};

struct Cards
{
    Ranks card_rank;
    Suits card_suit;
};

using deck_type = std::array<Cards, 52>;
using index_type = deck_type::size_type;

auto create_deck()
{
    deck_type deck;
    index_type index{0};

    for( int suit_assign{0}; suit_assign < Max_Suit; suit_assign++ )
    {
        for( int rank_assign{0}; rank_assign < Max_Ranks; rank_assign++ )
        {
            deck[index].card_suit = static_cast< Suits > ( suit_assign );
            deck[index].card_rank = static_cast< Ranks > ( rank_assign );

            index++;
        }
    }

    return deck;
}

void print_card(Cards card)
{
    if(card.card_rank <= Ten)
        std::cout<<card.card_rank + 2;

    switch(card.card_rank)
    {
        case Jack:
            std::cout<<"JACK";
            break;
        case King:
            std::cout<<"KING";
            break;
        case Queen:
            std::cout<<"QUEEN";
            break;
        case Ace:
            std::cout<<"ACE";
            break;
        default:
            break;
    }

    switch(card.card_suit)
    {
        case Club:
            std::cout<<" CLUB";
            break;
        case Diamond:
            std::cout<<" DIAMOND";
            break;
        case Heart:
            std::cout<<" HEART";
            break;
        case Spade:
            std::cout<<" SPADE";
            break;
        default:
            break;

    }
}

void print_deck(const deck_type& deck)
{

    for(Cards print : deck)
    {
        std::cout<<std::endl;

        if(print.card_rank == Two)
            std::cout<<std::endl;

        print_card(print);

    }
}

auto card_values(const Cards& card)
{

    int value;

    if(card.card_rank <= Ten)
        value = card.card_rank + 2;

    switch(card.card_rank)
    {
        case Jack:
        case King:
        case Queen:
            value = 10;
            break;
        case Ace:
            value = 11;
            break;

        default:
            break;

    }

    return value;

}

void print_values(const deck_type& deck)
{
    std::cout<<std::endl;

    for( Cards print : deck )
    {
        if(print.card_rank == Two)
            std::cout<<std::endl;

        std::cout<<card_values(print);
    }
}

auto shuffle_deck(deck_type& deck)
{
    std::mt19937 twister { static_cast<std::mt19937::result_type>(std::time(nullptr)) };


    std::shuffle(deck.begin(), deck.end(), twister);

    return deck;
}

void intro()
{
    std::cout<<"\t _______________________________";
    std::cout<<"\n\t| \t BLACK JACK 2.0 : \t|\n";
    std::cout<<"\t YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n\n";

    std::vector<char> card
    {
        ' ','_','_','_','_','_',' ','\t', ' ','_','_','_','_','_',' ','\n',
        '|','J',' ',' ',' ',' ','|','\t', '|','x','x','x','x','x','|','\n',
        '|',' ',' ','C',' ',' ','|','\t', '|','x','x','x','x','x','|','\n',
        '|',' ',' ',' ',' ','J','|','\t', '|','x','x','x','x','x','|','\n',
        '|','_','_','_','_','_','|','\t', '|','_','_','_','_','_','|','\n'
};

    for(char print : card)
        std::cout<<print;

    std::cout<<"\t\t\t\t\t\t     Th3_1r0ny";
    std::cout<<"\n_______________________________________________________________";
    std::cout<<std::endl;
    usleep(2000000);
}

auto random_generator( int x, int y )
{
    std::mt19937 twister{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::uniform_int_distribution<> generator { x , y };

    return generator( twister );
}

auto card_sub(Cards card, char rank_suit)
{

    if( rank_suit == 'r' )
    {
    switch(card.card_rank)
    {
        case Two:
            return '2';
        case Three:
            return '3';
        case Four:
            return '4';
        case Five:
            return '5';
        case Six:
            return '6';
        case Seven:
            return '7';
        case Eight:
            return '8';
        case Nine:
            return '9';
        case Ten:
            return '0';
        case Jack:
            return 'J';
            break;
        case King:
            return 'K';
            break;
        case Queen:
            return 'Q';
            break;
        case Ace:
            return 'A';
            break;
        default:
            break;
    }

    }

    if( rank_suit == 's' )
    {
     switch(card.card_suit)
    {
        case Club:
            return 'C';
            break;
        case Diamond:
            return 'D';
            break;
        case Heart:
            return 'H';
            break;
        case Spade:
            return 'S';
            break;
        default:
            break;

    }

    }
    return 'E';
}

void cli_card( std::vector<Cards> deck )
{
    std::vector<char> first_layer   { ' ','_','_','_','_','_',' ',' ' };
    std::vector<char> second_layer  { '|','x',' ',' ',' ',' ','|',' ' };
    std::vector<char> third_layer   { '|',' ',' ','x',' ',' ','|',' ' };
    std::vector<char> fourth_layer  { '|',' ',' ',' ',' ','x','|',' ' };
    std::vector<char> fifth_layer   { '|','_','_','_','_','_','|',' ' };

    std::size_t num_of_cards{ deck.size() };

    std::cout<<std::endl;

    for( std::size_t counter{ 0 } ; counter < num_of_cards; counter++)
    {
        for( char print : first_layer )
            std::cout<<print;
    }
            
    std::cout<<std::endl;

    for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
    {

        second_layer[ 1 ] = card_sub( deck[counter] , 'r');

        if( second_layer[ 1 ] == '0' )
         {
            second_layer[ 1 ] = '1';
            second_layer[ 2 ] = '0';
         }
        else 
            second_layer[ 2 ] = ' ';        

        for( char print : second_layer )
                std::cout<<print;
    }

    std::cout<<std::endl;

    for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
    {
        third_layer  [ 3 ] = card_sub( deck[counter] , 's');

        for( char print : third_layer )
            std::cout<<print;
    }

    std::cout<<std::endl;

    for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
    {

        fourth_layer  [ 5 ] = card_sub( deck[counter] , 'r');

        if( fourth_layer[ 5 ] == '0' )
        {
            fourth_layer[ 4 ] = '1';
        }
        else
            fourth_layer[ 4 ] = ' ';


        for( char print : fourth_layer )
            std::cout<<print;
    }

    std::cout<<std::endl;

    for( std::size_t counter{ 0 }; counter < num_of_cards; counter++ )
    {
        for( char print : fifth_layer )
            std::cout<<print;
    }
}

void null_card( std::vector<Cards> deck )
{
    std::vector<char> first_layer   { ' ','_','_','_','_','_',' ',' ' };
    std::vector<char> second_layer  { '|','x','x','x','x','x','|',' ' };
    std::vector<char> third_layer   { '|','x','x','x','x','x','|',' ' };
    std::vector<char> fourth_layer  { '|','x','x','x','x','x','|',' ' };
    std::vector<char> fifth_layer   { '|','_','_','_','_','_','|',' ' };

    std::size_t num_of_cards{ deck.size() };

    std::cout<<std::endl;

        for( std::size_t counter{ 0 } ; counter < num_of_cards; counter++)
        {
            for( char print : first_layer )
                std::cout<<print;
        }
            
        std::cout<<std::endl;

        for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
        {
            for( char print : second_layer )
                std::cout<<print;
        }

        std::cout<<std::endl;

        for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
        {
            for( char print : third_layer )
                std::cout<<print;
        }

        std::cout<<std::endl;

        for( std::size_t counter{ 0 }; counter < num_of_cards; counter++)
        {
             for( char print : fourth_layer )
                std::cout<<print;
        }

        std::cout<<std::endl;

        for( std::size_t counter{ 0 }; counter < num_of_cards; counter++ )
        {
            for( char print : fifth_layer )
                std::cout<<print;
        }

        std::cout<<std::endl;
}

void operation( Cards& card , int& points , std::vector<Cards>& deck , index_type& picker , deck_type the_deck, char turn)
{
    if( turn == 'p' )
        std::cout<<"\n PLAYER 'S TURN -> ";
    else
        std::cout<<"\n DEALER 'S TURN -> ";

    card = the_deck[ picker ];                              // Pick the card from the deck
    points = points + card_values( card );                 // convert card 's rank to actual value to use
    deck.push_back( card );                               // Track dealer's card 
    picker++;                                           // To pick the next card
    

    if( turn == 'p' )
        cli_card( deck );                                    // Print Cli card
    else if( turn == 'd' )                                  // first time dealer's card
        cli_card( deck );
    else if( turn == 'n' )
        null_card( deck );

    if( turn == 'p' )
    {
        std::cout<<std::endl;
        std::cout<<"\n > ";
 
        for( Cards print : deck )
        {
            print_card( print );
            std::cout<<"  ";
        }

        std::cout<<"\n Player 's point -> "<<points;

    }
    else if( turn == 'e' || turn == 'd')
    {
        std::cout<<std::endl;
        std::cout<<"\n > ";
     
        for( Cards print : deck )
        {
            print_card( print );
            std::cout<<"  ";
        }

        std::cout<<"\n Dealer 's point -> "<<points;
    }

    std::cout<<"\n_______________________________________________________________";
    std::cout<<std::endl;
        
    usleep(2000000);

}

void game_check( int dealer_points , int player_points , char turn , int& result , std::vector<Cards> dealer_deck , std::vector<Cards> player_deck )
{
    if( dealer_points == 21 && turn == 'd')
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\n Dealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck  > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\n Player 's points > "<<player_points;


        std::cout<<"\n\n  \t Black Jack! ";
        std::cout<<"\n\t Game Over!";
        std::cout<<"\n Player Lose!\n\n";
        result = 1;
    } 

    else if( player_points == 21 && turn == 'p' )
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;

        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\n  \t Black Jack! ";
        std::cout<<"\n\t Congratulation!";
        std::cout<<"\n Player Win!\n\n";
        result = 1;
    }

    else if( dealer_points > 21 && turn == 'd' )
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\n Dealer Busted!";
        std::cout<<"\n\t Congratulation!";
        std::cout<<"\n Player Win!\n\n";
        result = 1;
    }

    else if( player_points > 21 && turn == 'p' )
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\n Player Busted!";
        std::cout<<"\n\tGame Over";
        std::cout<<"\n Player Lose!\n\n";
        result = 1;
    }

    else if( turn == 'g' )
    {
         std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\nGame Over";
        std::cout<<"\n\t Dealer Win!";
        std::cout<<"\n Player Lose!\n\n";
        result = 1;
    }

    else if( dealer_points == player_points ) 
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\nGame Over";
        std::cout<<"\n Draw!\n\n";
        result = 1;
    }

    else if( dealer_points >= 17 && dealer_points > player_points && player_points > 17 )
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\nGame Over";
        std::cout<<"\n\t Dealer Win!";
        std::cout<<"\n Player Lose!\n\n";
        result = 1;
    }

    else if( player_points >= 17 && dealer_points < player_points && dealer_points > 17 )
    {
        std::cout<<"\n Dealer 's deck > ";
        cli_card( dealer_deck );
        std::cout<<std::endl;
        for( Cards print : dealer_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nDealer 's points > "<<dealer_points;


        std::cout<<"\n\n Player 's deck > ";
        cli_card( player_deck );
        std::cout<<std::endl;
        for( Cards print : player_deck )
        {
            print_card( print );
            std::cout<<' ';
        }
        std::cout<<"\nPlayer 's points > "<<player_points;


        std::cout<<"\n\nGame Over";
        std::cout<<"\n\t Dealer Win!";
        std::cout<<"\n Player Lose!\n\n";
        result = 1;
    }
}

void player_turn( int& decision )
{
    std::cout<<"\n Player 's turn : ";
    std::cout<<"\n Hit or Stand ( h / s ? ) > ";
    char input{ };
    std::cin>>input;
    
    if( input == 'h' )
    {
        std::cout<<"\n Player hit";
        std::cout<<"\n_______________________________________________________________";
        decision = 1;
    }
    else
    {
        std::cout<<"\n Player stand";
        std::cout<<"\n_______________________________________________________________";
        decision = 2;
    }
}

void dealer_turn ( int points , int& decision )
{
    int dealer{ random_generator( 1 , 1000 ) };    // Hit or stand of dealer's decision is completely based on random...i can write complex Ai yet xD
 
    std::cout<<"\n Dealer 's turn > ";
    std::cout<<std::endl;
    usleep(2000000);
    std::cout<<std::endl;

    if( points == 20) 
    {
        std::cout<<"\n Dealer stand ";
        std::cout<<"\n_______________________________________________________________";
        decision = 3;
    }
    else if( points < 17 )   
    {
        std::cout<<"\n Dealer hit ";
        std::cout<<"\n_______________________________________________________________";
        decision = 1;
    }
    else 
    {
        if( dealer % 2 == 0)
        {
            std::cout<<"\n Dealer stand > ";
            std::cout<<"\n_______________________________________________________________";
            decision = 2;
        }
        else
        {
            std::cout<<"\n Dealer hit > ";
            decision = 1;
        }
    }
}

int share_cards( deck_type deck )
{
    int dealer_points{};       // Point tracking
    int player_points{};

    std::vector<Cards> dealer_deck;     // Card tracking  
    std::vector<Cards> player_deck;     

    Cards dealer_card;         // Card picked for player and dealer
    Cards player_card;

    index_type picker{ 0 };    // To pick cards from the deck...increase by one everytime someone draw the card

    int result{ 0 };           // To check whether a game is set or not
    int player_decision{ 0 };
    int dealer_decision{ 0 };

    // Initial Card share

    operation( dealer_card , dealer_points , dealer_deck , picker , deck , 'd');
    operation( player_card , player_points , player_deck , picker , deck , 'p');
    operation( dealer_card , dealer_points , dealer_deck , picker , deck , 'n');
    operation( player_card , player_points , player_deck , picker , deck , 'p');

    game_check( dealer_points, player_points , 'd' , result , dealer_deck , player_deck );
    if( result == 1)
        return 0;

    game_check( dealer_points , player_points, 'p' , result , dealer_deck , player_deck );
    if( result == 1 )
        return 0;

    player_turn( player_decision );

    for( int count{ 0 }; count < 1; )
    {

        if( player_decision == 1 )
        {
            player_decision = 0;
            operation( player_card , player_points , player_deck , picker , deck , 'p');
            game_check( dealer_points , player_points, 'p' , result , dealer_deck , player_deck );
            if( result == 1 )
                count = 2;
       }
 
        else if( player_decision == 0 )         // To ask for player 's next action after hit
        {
            player_turn( player_decision );
        }
       
        else if( player_decision == 2 && dealer_decision == 0 )
        {
            dealer_turn( dealer_points , dealer_decision );
        }

        if( dealer_decision == 1 )
        {
            dealer_decision = 0;
            operation( dealer_card , dealer_points , dealer_deck , picker , deck , 'n');
            game_check( dealer_points, player_points , 'd' , result , dealer_deck , player_deck );
            if( result == 1)
                count = 2;
        }

        else if( dealer_decision == 2 )
        {
            player_turn( player_decision );
        }

        else if( dealer_decision == 3 )
        {
            game_check( dealer_points, player_points , 'g' , result , dealer_deck , player_deck );
            if( result == 1)
                count = 2;
        }
}

    // I focused too much on user interface...my game code is now messy as fuck...well i dont really know how to play black jack in the first place
  
    return 0;
}

void central()              // center of all function
{
    auto deck{create_deck()};       // Create Deck

    shuffle_deck(deck);             // Shuffle Deck

    share_cards( deck );
}

int main()
{
    intro();

    central();

    return 0;
}
