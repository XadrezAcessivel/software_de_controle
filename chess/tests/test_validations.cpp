#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include "../include/motion_validation.hpp"

using namespace std;

vector<string> false_negatives;
vector<string> false_positives;

void run_piece_test_case(string x_origin, string y_origin, string x_destiny,
  string y_destiny, int turn, bool expected, MotionValidation motion_validator,
  string piece_type){
    bool test_result = motion_validator.validate_command(x_origin,
                                                         y_origin,
                                                         x_destiny,
                                                         y_destiny,
                                                         turn);

    if(test_result == false && expected == true){
      string failure_message = "the validation failed moving " + piece_type + " from " +
                                x_origin + " " + y_origin + " to " +
                                x_destiny + " " + y_destiny;
      false_negatives.push_back(failure_message);
    }else if(test_result == true && expected == false){
      string failure_message = "the validation passed moving "+ piece_type +" from " +
                                x_origin + " " + y_origin + " to " +
                                x_destiny + " " + y_destiny;
      false_positives.push_back(failure_message);
    }
}

void test_pawn_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1,2,3,4,5,3,2,1},
    {6,6,6,6,6,6,6,6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {12,12,12,12,12,12,12,12},
    {7,8,9,10,11,9,8,7}};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("SEVEN","ALPHA","SIX","ALPHA",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("SEVEN","ALPHA","FIVE","ALPHA",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("SEVEN","BRAVO","SIX","BRAVO",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("SEVEN","BRAVO","FIVE","BRAVO",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("SEVEN","CHARLIE","SIX","CHARLIE",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("SEVEN","CHARLIE","FIVE","CHARLIE",0, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","ALPHA","THREE","ALPHA",1, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","ALPHA","FOUR","ALPHA",1, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","BRAVO","THREE","BRAVO",1, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","BRAVO","FOUR","BRAVO",1, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","CHARLIE","THREE","CHARLIE",1, true, motion_validator_1, "PAWN");

  run_piece_test_case("TWO","CHARLIE","FOUR","CHARLIE",1, true, motion_validator_1, "PAWN");

  //Capture movement
  int chess_board_2[8][8] = 
   {{1,2,3,4,5,3,2,1},
    {6,6,6,6,6,6,0,6},
    {0,0,12,0,0,0,0,0},
    {12,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,6,0},
    {0,12,0,12,12,12,12,12},
    {7,8,9,10,11,9,8,7}};

  MotionValidation motion_validator_2 = MotionValidation(chess_board_2);
  motion_validator_2.initialize_dictionaries();

  run_piece_test_case("SEVEN","CHARLIE","SIX","CHARLIE",0, true, motion_validator_2, "PAWN");

  run_piece_test_case("SEVEN","ALPHA","FIVE","ALPHA",0, true, motion_validator_2, "PAWN");

  run_piece_test_case("TWO","GOLF","THREE","GOLF",1, true, motion_validator_2, "PAWN");

  //Normal movement
  int chess_board_3[8][8] = 
   {{1 ,2 ,3 ,4 ,5 ,3 ,2 ,1 },
    {6 ,6 ,6 ,6 ,6 ,6 ,0 ,6 },
    {0 ,0 ,12,0 ,0 ,0 ,0 ,0 },
    {12,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,9 ,0 ,0 ,0 ,0 ,6 ,0 },
    {0 ,12,0 ,12,12,12,12,12},
    {7 ,8 ,9 ,10,11,9 ,8 ,7 }};

  MotionValidation motion_validator_3 = MotionValidation(chess_board_3);
  motion_validator_3.initialize_dictionaries();

  run_piece_test_case("SIX","ALPHA","SIX","ALPHA",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SIX","ALPHA","SEVEN","ALPHA",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("FIVE","ALPHA","SEVEN","ALPHA",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SIX","BRAVO","SEVEN","BRAVO",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("FIVE","BRAVO","SEVEN","BRAVO",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SIX","CHARLIE","SEVEN","CHARLIE",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("FIVE","CHARLIE","SEVEN","CHARLIE",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","BRAVO","THREE","BRAVO",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("THREE","ALPHA","THREE","ALPHA",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("THREE","ALPHA","TWO","ALPHA",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("FOUR","ALPHA","TWO","ALPHA",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("THREE","BRAVO","TWO","BRAVO",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("FOUR","BRAVO","TWO","BRAVO",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("THREE","CHARLIE","TWO","CHARLIE",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("FOUR","CHARLIE","TWO","CHARLIE",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","ALPHA","SIX","BRAVO",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","CHARLIE","FIVE","ALPHA",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","GOLF","SIX","BRAVO",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","GOLF","FIVE","BRAVO",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","DELTA","SIX","CHARLIE",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("SEVEN","ALPHA","FIVE","CHARLIE",0, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","BRAVO","THREE","ALPHA",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","DELTA","FOUR","ALPHA",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","ALPHA","THREE","BRAVO",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","CHARLIE","FOUR","BRAVO",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","BRAVO","THREE","CHARLIE",1, false, motion_validator_3, "PAWN");

  run_piece_test_case("TWO","DELTA","FOUR","CHARLIE",1, false, motion_validator_3, "PAWN");
}

void test_king_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1 ,2 ,3 ,4 ,0 ,3 ,2 ,1 },
    {6 ,6 ,6 ,6 ,0 ,6 ,6 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,11,0 ,0 ,5 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,6 ,0 ,0 ,0 },
    {12,12,12,0 ,12,12,12,12},
    {7 ,8 ,9 ,10,0 ,9 ,8 ,7 }};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("FIVE","ECHO","SIX","ECHO",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","SIX","FOXTROT",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","FIVE","FOXTROT",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","FOUR","FOXTROT",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","FOUR","ECHO",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","FOUR","DELTA",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","FIVE","DELTA",0, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","ECHO","SIX","DELTA",0, true, motion_validator_1, "KING");


  run_piece_test_case("FIVE","BRAVO","SIX","BRAVO",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","SIX","CHARLIE",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","FIVE","CHARLIE",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","FOUR","CHARLIE",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","FOUR","BRAVO",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","FOUR","ALPHA",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","FIVE","ALPHA",1, true, motion_validator_1, "KING");

  run_piece_test_case("FIVE","BRAVO","SIX","ALPHA",1, true, motion_validator_1, "KING");

  //Capture movement
  int chess_board_2[8][8] = 
   {{1 ,2 ,3 ,4 ,0 ,3 ,2 ,1 },
    {6 ,6 ,6 ,6 ,0 ,6 ,6 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,11,5 ,12,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,6 ,0 ,0 ,0 },
    {12,12,12,0 ,12,12,12,12},
    {7 ,8 ,9 ,10,0 ,9 ,8 ,7 }};

  MotionValidation motion_validator_2 = MotionValidation(chess_board_2);
  motion_validator_2.initialize_dictionaries();

  run_piece_test_case("FIVE","CHARLIE","FIVE","BRAVO",0, true, motion_validator_2, "KING");

  run_piece_test_case("FIVE","CHARLIE","FIVE","DELTA",0, true, motion_validator_2, "KING");

  run_piece_test_case("FIVE","BRAVO","FIVE","CHARLIE",1, true, motion_validator_2, "KING");

  //Normal movement  
  int chess_board_3[8][8] = 
   {{1 ,2 ,3 ,4 ,5 ,3 ,2 ,1 },
    {6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,6 ,0 ,0 ,0 },
    {12,12,12,0 ,12,12,12,12},
    {7 ,8 ,9 ,10,11 ,9 ,8 ,7 }};

  MotionValidation motion_validator_3 = MotionValidation(chess_board_3);
  motion_validator_3.initialize_dictionaries();
  
  run_piece_test_case("EIGHT","ECHO","SEVEN","ECHO",0, false, motion_validator_3, "KING");

  run_piece_test_case("ONE","ECHO","TWO","ECHO",1, false, motion_validator_3, "KING");
}

void test_rook_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1,2,3,4,5,3,2,0},
    {6,6,6,6,6,6,6,6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,7,0,0,0,1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {12,12,12,12,12,12,12,12},
    {7,8,9,10,11,9,8,7}};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("FIVE","DELTA","THREE","DELTA",1, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","FIVE","ALPHA",1, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","HOTEL","THREE","HOTEL",0, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","HOTEL","FIVE","ECHO",0, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","HOTEL","SIX","HOTEL",0, true, motion_validator_1, "ROOK");

  // Capture movement
  run_piece_test_case("FIVE","HOTEL","TWO","HOTEL",0, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","HOTEL","FIVE","DELTA",0, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","SEVEN","DELTA",1, true, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","FIVE","HOTEL",1, true, motion_validator_1, "ROOK");

  // Normal movement
  run_piece_test_case("FIVE","DELTA","FIVE","DELTA",1, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","THREE","ALPHA",1, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","TWO","DELTA",1, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","FOUR","ALPHA",1, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","THREE","HOTEL",0, false, motion_validator_1, "ROOK");

  run_piece_test_case("TWO","HOTEL","FIVE","ECHO",0, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","DELTA","TWO","DELTA",1, false, motion_validator_1, "ROOK");

  run_piece_test_case("FIVE","HOTEL","SEVEN","HOTEL",0, false, motion_validator_1, "ROOK");
}

void test_knight_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1 ,0 ,3 ,4 ,5 ,3 ,2 ,1 },
    {6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,2 ,0 ,0 ,0 ,0 ,0 ,0 },
    {12,12,12,12,12,12,12,12},
    {7 ,8 ,9 ,10,11,9 ,0 ,7 }};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("EIGHT","GOLF","SIX","HOTEL",0, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("EIGHT","GOLF","SIX","FOXTROT",0, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("ONE","BRAVO","THREE","ALPHA",1, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("ONE","BRAVO","THREE","CHARLIE",1, true, motion_validator_1, "KNIGHT");

  // Capture movement
  run_piece_test_case("THREE","BRAVO","ONE","ALPHA",0, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("THREE","BRAVO","ONE","CHARLIE",0, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("FIVE","FOXTROT","SEVEN","ECHO",1, true, motion_validator_1, "KNIGHT");

  run_piece_test_case("FIVE","FOXTROT","SEVEN","GOLF",1, true, motion_validator_1, "KNIGHT");

  // Normal movement
  run_piece_test_case("THREE","BRAVO","THREE","ALPHA",0, false, motion_validator_1, "KNIGHT");

  run_piece_test_case("THREE","BRAVO","ONE","BRAVO",0, false, motion_validator_1, "KNIGHT");

  run_piece_test_case("THREE","BRAVO","FORTROT","ALPHA",0, false, motion_validator_1, "KNIGHT");

  run_piece_test_case("FIVE","FOXTROT","SEVEN","FOXTROT",1, false, motion_validator_1, "KNIGHT");

  run_piece_test_case("FIVE","FOXTROT","SEVEN","ALPHA",1, false, motion_validator_1, "KNIGHT");
}

void test_bishop_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1 ,2 ,3 ,4 ,5 ,0 ,2 ,1 },
    {6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,6 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 },
    {0 ,0 ,9 ,0 ,6 ,0 ,0 ,0 },
    {12,12,0 ,0 ,12,12,12,12},
    {7 ,8 ,0 ,10,11,9 ,8 ,7 }};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("THREE","CHARLIE","TWO","DELTA",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","SEVEN","GOLF",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","FIVE","ALPHA",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","THREE","GOLF",0, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","SIX","HOTEL",0, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","SIX","DELTA",0, true, motion_validator_1, "QUEEN");

  // Capture movement
  run_piece_test_case("THREE","CHARLIE","EIGHT","HOTEL",1, true, motion_validator_1, "QUEEN");
  
  run_piece_test_case("FOUR","FOXTROT","TWO","HOTEL",0, true, motion_validator_1, "QUEEN");

  // Normal movement
  run_piece_test_case("FOUR","FOXTROT","THREE","ECHO",0, false, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","TWO","BRAVO",1, false, motion_validator_1, "QUEEN");
}

void test_queen_movements(){
  // Normal movement
  int chess_board_1[8][8] = 
   {{1 ,2 ,3 ,3 ,5 ,0 ,2 ,1 },
    {6 ,6 ,6 ,0 ,6 ,6 ,0 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,6 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,4 ,0 ,0 },
    {0 ,0 ,10,0 ,6 ,0 ,0 ,0 },
    {12,12,0 ,0 ,12,12,12,12},
    {7 ,8 ,0 ,9,11,9 ,8 ,7 }};

  MotionValidation motion_validator_1 = MotionValidation(chess_board_1);
  motion_validator_1.initialize_dictionaries();

  run_piece_test_case("THREE","CHARLIE","TWO","DELTA",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","SEVEN","GOLF",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","FIVE","ALPHA",1, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","THREE","GOLF",0, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","SIX","HOTEL",0, true, motion_validator_1, "QUEEN");

  run_piece_test_case("FOUR","FOXTROT","SIX","DELTA",0, true, motion_validator_1, "QUEEN");

  // Capture movement
  run_piece_test_case("THREE","CHARLIE","EIGHT","HOTEL",1, true, motion_validator_1, "QUEEN");
  
  run_piece_test_case("FOUR","FOXTROT","TWO","HOTEL",0, true, motion_validator_1, "QUEEN");

  // Normal movement
  run_piece_test_case("FOUR","FOXTROT","THREE","ECHO",0, false, motion_validator_1, "QUEEN");

  run_piece_test_case("THREE","CHARLIE","TWO","BRAVO",1, false, motion_validator_1, "QUEEN");

  // Normal movement
  int chess_board_2[8][8] = 
   {{1 ,2 ,3 ,0 ,5 ,3 ,2 ,0 },
    {6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,10,0 ,0 ,0 ,4 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
    {12,12,12,12,12,12,12,12},
    {7 ,8 ,9 ,0 ,11,9 ,8 ,7 }};

  MotionValidation motion_validator_2 = MotionValidation(chess_board_2);
  motion_validator_2.initialize_dictionaries();

  run_piece_test_case("FIVE","DELTA","THREE","DELTA",1, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","FIVE","ALPHA",1, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","HOTEL","THREE","HOTEL",0, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","HOTEL","FIVE","ECHO",0, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","HOTEL","SIX","HOTEL",0, true, motion_validator_2, "QUEEN");

  // Capture movement
  run_piece_test_case("FIVE","HOTEL","TWO","HOTEL",0, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","HOTEL","FIVE","DELTA",0, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","SEVEN","DELTA",1, true, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","FIVE","HOTEL",1, true, motion_validator_2, "QUEEN");

  // Normal movement
  run_piece_test_case("FIVE","DELTA","FIVE","DELTA",1, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","THREE","ALPHA",1, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","TWO","DELTA",1, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","FOUR","ALPHA",1, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","THREE","HOTEL",0, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","DELTA","TWO","DELTA",1, false, motion_validator_2, "QUEEN");

  run_piece_test_case("FIVE","HOTEL","SEVEN","HOTEL",0, false, motion_validator_2, "QUEEN");

}

int main(){
  test_pawn_movements();
  test_king_movements();
  test_rook_movements();
  test_knight_movements();
  test_bishop_movements();
  test_queen_movements();

  if(false_negatives.size() != 0){
      cout << "The following test cases have failed when they should pass:" << endl << endl;
    for(auto failure_message : false_negatives){
      cout << failure_message << endl << endl;
    }
  }
  if(false_positives.size() != 0){
      cout << "The following test cases have passed when they should fail:" << endl << endl;
    for(auto failure_message : false_positives){
      cout << failure_message << endl << endl;
    }
  }
  if(false_negatives.size() == 0 and false_positives.size() == 0){
    cout << "Sucessfully passed all tests!!" << endl;
  }
}
