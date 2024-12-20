#ifndef TIMER_H
#define TIMER_H
#include<chrono>
#include<thread>
#include<iostream>
class Timer{
private:
  int minutes;
  int seconds;
public:
  Timer();
  Timer(int);
  Timer(int,int);
  void setTimer();
};
#endif
