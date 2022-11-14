#ifndef ALPHABETS_H
#define ALPHABETS_H 
#include<vector>

struct Char_Map
{
  char input{};
  std::vector<char> alphabet;
};

using preset_structure = std::vector<std::vector<char>>;

class Alphabets 
{
  private:
    std::vector<char> A 
    {
      ' ',' ','_',' ',' ',      // 0   1   2   3   4
      ' ','/','_',92 ,' ',      // 5   6   7   8   9
      '/',' ',' ',' ',92        // 10  11  12  13  14
    };

    std::vector<char> B
    {
      ' ','_','_',' ',' ',
      '|','_','_',')',' ',
      '|','_','_',')',' '
    };

    std::vector<char> C 
    {
      ' ','_','_',' ',' ',
      '|',' ',' ',' ',' ',
      '|','_','_',' ',' '
    };

    std::vector<char> D
    {
      ' ','_','_',' ',' ',
      '|',' ',' ','|',' ',
      '|','_','_','/',' '
    };

    std::vector<char> E
    {
      ' ','_','_',' ',' ',
      '|','_','_',' ',' ',
      '|','_','_',' ',' '
    };

    std::vector<char> F
    {
      ' ','_','_',' ',' ',
      '|','_','_',' ',' ',
      '|',' ',' ',' ',' '
    };

    std::vector<char> G
    {
      ' ','_','_',' ',' ',
      '|',' ','_','_',' ',
      '|','_','_','/',' '
    };

    std::vector<char> H
    {
      ' ',' ',' ',' ',' ',
      '|','_','_','|',' ',
      '|',' ',' ','|',' '
    };

    std::vector<char> I
    {
      ' ','_','_','_',' ',
      ' ',' ','|',' ',' ',
      ' ','-','-','-',' '
    };

    std::vector<char> J
    {
      ' ','_','_','_',' ',
      ' ',' ','|',' ',' ',
      ' ','_','/',' ',' '
    };

    std::vector<char> K
    {
      ' ',' ',' ',' ',' ',
      '|','/',' ',' ',' ',
      '|',92,' ',' ',' '
    };

    std::vector<char> L
    {
      ' ',' ',' ',' ',' ',
      '|',' ',' ',' ',' ',
      '|','_','_',' ',' '
    };

    std::vector<char> M
    {
      ' ',' ',' ',' ',' ',
      '|',92 ,'/','|',' ',
      '|',' ',' ','|',' '
    };

    std::vector<char> N
    {
      ' ',' ',' ',' ',' ',
      '|',92 ,' ','|',' ',
      '|',' ',92 ,'|',' '
    };

    std::vector<char> O
    {
      ' ','_','_',' ',' ',
      '|',' ',' ','|',' ',
      '|','_','_','|',' '
    };

    std::vector<char> P
    {
      ' ','_','_',' ',' ',
      '|','_','_',')',' ',
      '|',' ',' ',' ',' '
    };

    std::vector<char> Q
    {
      ' ','_','_',' ',' ',
      '|',' ','_','|',' ',
      '|','_','L','|','_'
    };

    std::vector<char> R
    {
      ' ','_',' ',' ',' ',
      '|','_',')',' ',' ',
      '|',' ',92 ,' ',' '
    };

    std::vector<char> S
    {
      ' ','_','_',' ',' ',
      '|','_',' ',' ',' ',
      '_','_','|',' ',' '
    };

    std::vector<char> T
    {
      ' ','_','_','_',' ',
      ' ',' ','|',' ',' ',
      ' ',' ','|',' ',' '
    };

    std::vector<char> U
    {
      '|',' ',' ','|',' ',
      '|',' ',' ','|',' ',
      ' ','-','-',' ',' '
    };

    std::vector<char> V
    {
      ' ',' ',' ',' ',' ',
      92 ,' ',' ',' ','/',
      ' ', 92,'_','/',' '
    };

    std::vector<char> W
    {
      ' ',' ',' ',' ',' ',
      92 ,' ',' ',' ','/',
      ' ',92 ,'^','/',' '
    };

    std::vector<char> X
    {
      ' ',92 ,' ','/',' ',
      ' ',' ','X',' ',' ',
      ' ','/',' ',92 ,' '
    };

    std::vector<char> Y
    {
      ' ',92 ,' ','/',' ',
      ' ',' ','Y',' ',' ',
      ' ',' ','|',' ',' '
    };

    std::vector<char> Z
    {
      ' ','_','_',' ',' ',
      ' ',' ','/',' ',' ',
      ' ','/','_',' ',' '
    };

    preset_structure m_alphabets 
    {
      A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
    };

    std::vector<Char_Map> m_presets
    {
      { 'A', A },
      { 'B', B },
      { 'C', C },
      { 'D', D },
      { 'E', E },
      { 'F', F },
      { 'G', G },
      { 'H', H },
      { 'I', I },
      { 'J', J },
      { 'K', K },
      { 'L', L },
      { 'M', M },
      { 'N', N },
      { 'O', O },
      { 'P', Q },
      { 'R', R },
      { 'S', S },
      { 'T', T },
      { 'U', U },
      { 'V', V },
      { 'W', W },
      { 'X', X },
      { 'Y', Y },
      { 'Z', Z },
    };

  public:
    void print_single_alphabet( char input );
    void print_single_alphabet( std::vector<char> alphabets );
    void print_alphabets_horizontal( int char_count, int end );
    void print_alphabets_vertical( int start, int end );
    void print_user_input( std::vector<int> indices );
    
    std::vector<char> operator[]( char input );
};

#endif
