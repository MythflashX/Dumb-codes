#include<iostream>
#include<vector>
#include<algorithm> 
#include"alphabets.h" 

void Alphabets::print_single_alphabet( char input )
{
  int count{ 0 };
  std::vector<char> temp;

  switch ( input )
  {
    case 'A': 
      temp = Alphabets::A;
      break;
    case 'B':
      temp = Alphabets::B;
      break;
    case 'C':
      temp = Alphabets::C;
      break;
    case 'D':
      temp = Alphabets::D;
      break; 
    case 'E': 
      temp = Alphabets::E;
      break;
  }

  for( char ascii : temp )
  {
    std::cout<<ascii;
    
    if( count == 4 || count == 9 || count == 15 )
      std::cout<<std::endl;

    count++;
  }
}

void Alphabets::print_single_alphabet( std::vector<char> character )
{
  for( int count{ 0 }; count < 15; count++ )
  {
    std::cout<<character[ count ];

    if( count == 4 || count == 9 || count == 15 )
      std::cout<<std::endl;
  }
}

void Alphabets::print_alphabets_vertical( int start, int end )
{
  for( ; start < end; start++ )
  {
    print_single_alphabet( m_alphabets[ start ] );
    std::cout<<std::endl;
  }
}

void Alphabets::print_alphabets_horizontal( int char_count, int end )
{
  for( int char_count{ 0 }; char_count < end; char_count++ )
  {
    for( int index{ 0 }; index <= 4; index++ )
      std::cout<<m_alphabets[ char_count ][ index ];

    std::cout<<"    ";
  }
  
  std::cout<<std::endl;

  for( int char_count{ 0 }; char_count < end; char_count++ )
  {
    for( int index{ 5 }; index <= 9; index++ )
      std::cout<<m_alphabets[ char_count ][ index ]; 
    
    std::cout<<"    ";
  }

  std::cout<<std::endl;

  for( int char_count{ 0 }; char_count < end; char_count++ )
  {
    for( int index{ 10 }; index <= 15; index++ )
      std::cout<<m_alphabets[ char_count ][ index ];
    
    std::cout<<"    ";
  }
}

void Alphabets::print_user_input( std::vector<int> indices )
{
  std::size_t size{ indices.size() };

  for( int char_count{ 0 }; char_count < size; char_count++ )
  {
    for( int index{ 0 }; index <= 4; index++ )
      std::cout<<m_alphabets[ indices[ char_count ] ][ index ];

    std::cout<<"    ";
  }
  std::cout<<std::endl;

  for( int char_count{ 0 }; char_count < size; char_count++ )
  {
    for( int index{ 5 }; index <= 9; index++ )
      std::cout<<m_alphabets[ indices[ char_count ] ][ index ];

    std::cout<<"    ";
  }

  std::cout<<std::endl;

  for( int char_count{ 0 }; char_count < size; char_count++ )
  {
    for( int index{ 10 }; index <= 15; index++ )
      std::cout<<m_alphabets[ indices[ char_count ] ][ index ];

    std::cout<<"    ";
  }

  std::cout<<std::endl;
}

std::vector<char> Alphabets::operator[]( char input )
{
  auto condition
  {
    [ & ]( const auto& alphabet )
    {
      return alphabet.input == input;
    }
  };

  auto search{ std::find_if( m_presets.begin(), m_presets.end(), condition ) };

  return search->alphabet;
}

