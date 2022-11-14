#include<iostream> 
#include<string>
#include<vector>
#include"alphabets.h"

void check_command_line_arguments( int argc, char* argv[] )
{
  std::cout<<"There are "<<argc<<" arguments:\n";

  for( int count{ 0 }; count < argc; count++ )
    std::cout<<count<<' '<<argv[ count ]<<'\n';

  std::string input_string{ argv[ 1 ] };

  for( char c : input_string )
    std::cout<<c<<',';
}
std::vector<int> linker( int argc, char* argv[] );

int main( int argc, char* argv[] )
{
  std::cout<<std::endl;
  Alphabets one;
  one.print_single_alphabet( 'C' );
  std::cout<<std::endl;
  one.print_alphabets_vertical( 0, 5 );
  std::cout<<std::endl;
  one.print_alphabets_horizontal( 0, 5 );
  std::cout<<std::endl;
  one.print_single_alphabet( one[ 'J' ] );

  check_command_line_arguments( argc, argv );

  one.print_user_input( linker( argc, argv ) );

  return 0;
}

std::vector<int> linker( int argc, char* argv[] )
{
  std::string input_string{ argv[ 1 ] }; 
  std::vector<int> indices;

  for( char c : input_string )
  {
    switch ( c )
    {
      case 'A':
        indices.push_back( 0 );
        break; 
      case 'B':
        indices.push_back( 1 );
        break; 
      case 'C': 
        indices.push_back( 2 );
        break; 
      case 'D':
        indices.push_back( 3 );
        break; 
      case 'E':
        indices.push_back( 4 ); 
        break; 
      case 'F':
        indices.push_back( 5 );
        break;
      case 'G':
        indices.push_back( 6 );
        break; 
      case 'H':
        indices.push_back( 7 );
        break; 
      case 'I': 
        indices.push_back( 8 );
        break; 
      case 'J':
        indices.push_back( 9 );
        break; 
      case 'K':
        indices.push_back( 10 ); 
        break; 
      case 'L':
        indices.push_back( 11 );
        break;
      case 'M':
        indices.push_back( 12 );
        break; 
      case 'N':
        indices.push_back( 13 );
        break; 
      case 'O': 
        indices.push_back( 14 );
        break; 
      case 'P':
        indices.push_back( 15 );
        break; 
      case 'Q':
        indices.push_back( 16 ); 
        break; 
      case 'R':
        indices.push_back( 17 );
        break;
      case 'S':
        indices.push_back( 18 );
        break; 
      case 'T':
        indices.push_back( 19 );
        break; 
      case 'U': 
        indices.push_back( 20 );
        break; 
      case 'V':
        indices.push_back( 21 );
        break; 
      case 'W':
        indices.push_back( 22 ); 
        break; 
      case 'X':
        indices.push_back( 23 );
        break;
      case 'Y':
        indices.push_back( 24 );
        break; 
      case 'Z':
        indices.push_back( 25 );
        break; 
    }
  }

  for( int index : indices )
    std::cout<<"\n Indices -> "<<index;
  std::cout<<std::endl<<std::endl;

  return indices;
}


