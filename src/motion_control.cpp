#include "../include/motion_control.hpp"

void MotionControl::get_path(int x_origin, int y_origin, 
    int x_destiny, int y_destiny){

  int dx = abs(x_origin - x_destiny);
  int dy = abs(y_origin - y_destiny);

  string move_x = "G0 X ";
  string move_y = " Y ";

  int old_x_origin = x_origin;
  int old_y_origin = y_origin;

  string first_command;

  if(x_destiny <= x_origin){
    first_command = "G0 X -1 Y 0";
    x_origin--;
    commands_queue.push(first_command);
  }else{
    first_command = "GO X 1 Y 0";
    x_origin++;
    commands_queue.push(first_command);   
  }

  string second_command = move_x;

  if(old_y_origin == y_destiny){
    second_command = "G0 X 0 Y 1";
    y_origin++; 
    commands_queue.push(second_command);
  }else{
    second_command += '0';
    second_command += move_y; 
    if(y_destiny < y_origin){
      second_command += "-";
      y_origin -= (dy - 1);
    }else{
      y_origin += (dy - 1); 
    }

    second_command += (char)((dy - 1) + 48);
    commands_queue.push(second_command);
  }

  string third_command = move_x;

  dx = abs(x_origin - x_destiny);
  dy = abs(y_origin - y_destiny);

  if(old_x_origin == x_destiny){
    third_command = "G0 X 1 Y 0";
    x_origin++;
    commands_queue.push(third_command);
  }else{
    if(x_destiny < old_x_origin){
      third_command += "-";
      x_origin -= dx;
    }else{
      x_origin += dx;
    }

    third_command += (char)((dx)+48);

    third_command += move_y;
    third_command += '0';
    commands_queue.push(third_command);
  } 
  
  string fourth_command = move_x;

  if(y_origin == y_destiny + 1){
    fourth_command += "0 Y -1";
  }else if(y_origin == y_destiny - 1){
    fourth_command += "0 Y 1";
  }

  commands_queue.push(fourth_command);
}

void MotionControl::move_CNC_to_origin_cell(int CNC_x_origin, int CNC_y_origin){
  int CNC_x_destiny;
  int CNC_y_destiny;

  get_path(CNC_x_origin, CNC_y_origin, CNC_x_destiny, CNC_y_destiny);
}

void MotionControl::switch_on_magnet(){
  string switch_on_instruction = "G1";
  commands_queue.push(switch_on_instruction);
}

void MotionControl::switch_off_magnet(){
  string switch_off_instruction = "G2";
  commands_queue.push(switch_off_instruction);
}