#include<iostream>
#include<array>

typedef std::array<std::array<int, 9>, 9> MultiDi_array;

class Base
{
  protected:
    MultiDi_array m_table;
  public:
    Base( MultiDi_array table ) : m_table{ table } {}
    MultiDi_array getTable() const { return m_table; }
    const void print() const;
};

const void Base::print() const
{
  for( int row{0}; row < 9; row++ )
  {
    for( int col{0}; col < 9; col++ )
      std::cout<<m_table[row][col]<<' ';
    std::cout<<std::endl;
  }
    std::cout<<std::endl;
}


class Quiz : public Base
{
  public:
    Quiz( MultiDi_array table ) : Base( table ) {}
};

class Answer : public Base
{
  public:
    Answer( MultiDi_array table ) : Base( table ) {}
    void edit( int &row, int &col, int &usr_inpt );
    void revert( int &row, int &col );
};

void Answer::edit( int &row, int &col, int &usr_inpt )
{
  m_table[row][col] = usr_inpt;
  std::cout<<"EDITED\n";
}

void Answer::revert( int &row, int &col )
{
 m_table[row][col] = 0;
  std::cout<<"REVERTED\n";
}

bool check( int &row, int &col, int &usr_inpt, bool &game, const Base &quiz, const Base &answer );
void user_input( int &row, int &col, int &usr_inpt, int &attempts );
void run();

int main( void )
{
  std::cout<<"\t\t Sudoku \n\n";
  run();

  return 0;
}

void run()
{
  Quiz quiz
  {
    MultiDi_array 
    {
      {
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
      }
    }
  };

  Answer answer
  {
    MultiDi_array 
    {
      {
        { 0,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
        { 1,2,3,4,5,6,7,8,9 },
      }
    }
  };

  int row,col,usr_inpt,attempts{ 3 };
  bool game{ false };
  while ( attempts != 0 && game != true )
  {
    quiz.print();
    answer.print();
    user_input( row, col, usr_inpt, attempts );
    --row,--col;                        // Array Start From 0 but for the convenience of end user so that they can start counting row & col from 1 instead of 0

    answer.edit( row, col, usr_inpt );
    game=true;
    if ( !check( row, col, usr_inpt, game, quiz, answer ) )
    {
      answer.revert( row, col );
      --attempts;
    }
  }
    quiz.print();
    answer.print();

    if( game == true )
      std::cout<<"\nGameOver: You Win\n";
    else if( attempts == 0 )
      std::cout<<"\nGameOver: You Lose\n";
}

void user_input( int &row, int &col, int &usr_inpt, int &attempts )
{
  std::cout<<"Row : Col : Input : Attempts : "<<attempts<<'\n';
  std::cout<<" V     V      V  \n ";
  std::cin>>row>>col>>usr_inpt;
}

bool check( int &row, int &col, int &usr_inpt, bool &game, const Base &quiz, const Base &answer )
{
  for( int n_row{0}; n_row < 9; n_row++ )
  {
    for( int n_col{0}; n_col < 9; n_col++ )
    {
      if( quiz.getTable()[n_row][n_col] != answer.getTable()[n_row][n_col] )
        game = false;
    }
  }

  if( quiz.getTable()[row][col] == answer.getTable()[row][col] )
    return true;
  else
    return false;
}
