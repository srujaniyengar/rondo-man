#ifndef CAT_H
#define CAT_H
#include<vector>
#include<string>
class Cat{
  std::vector<std::string> catArr;
  public:
  Cat();
    void addCat(const std::string&);
    void delCat();
    void delCat(int);
    void dispCat() const;
    void dispCatRand() const;
};
#endif
