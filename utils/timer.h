#ifndef TIMER_H
#define TIMER_H
#include<chrono>
#include<thread>
#include<iostream>
class Timer{
private:
  int min;
  int sec;
public:
  Timer();
  Timer(int);
  Timer(int,int);
  void setTimer();
};
#endif
