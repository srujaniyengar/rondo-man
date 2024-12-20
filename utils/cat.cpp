#include <iostream>
#include "cat.h"
#include <random>
#include <stdexcept>

void Cat::addCat(const std::string& catAscii) {
    catArr.push_back(catAscii);
}

void Cat::delCat() {
    if (!catArr.empty()) {
        catArr.pop_back();
    } else {
        std::cerr << "Error: No cats to delete." << std::endl;
    }
}

void Cat::delCat(int index) {
    if (index >= 0 && index < static_cast<int>(catArr.size())) {
        catArr.erase(catArr.begin() + index);
    } else {
        std::cerr << "Error: Index out of range." << std::endl;
    }
}

void Cat::dispCat() const {
    for (const auto& cat : catArr) {
        std::cout << cat << std::endl;
    }
}

void Cat::dispCatRand() const {
    if (!catArr.empty()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(0, catArr.size() - 1);
        std::cout << catArr.at(dist(gen)) << std::endl;
    } else {
        std::cerr << "Error: No cats available to display." << std::endl;
    }
}


//cat default arts
Cat::Cat(){
   catArr={
   R"(
       _
       \`*-.
        )  _`-.
       .  : `. .
       : _   '  \
       ; *` _.   `*-._
       `-.-'          `-.
         ;       `       `.
         :.       .        \
         . \  .   :   .-'   .
         '  `+.;  ;  '      :
         :  '  |    ;       ;-.
         ; '   : :`-:     _.`* ;
      .*' /  .*' ; .*`- +'  `*'
      `*-*   `*-*  `*-*'

)"
  ,R"(
   /\_/\
  ( o.o )
   > ^ <
   )"
  ,R"(

    |\__/,|   (`\
  _.|o o  |_   ) )
-(((---(((--------
  )"
  ,R"(
        |\      _,,,---,,_
ZZZzz /,`.-'`'    -.  ;-;;,_
     |,4-  ) )-,_. ,\ (  `'-'
    '---''(_/--'  `-'\_)
  )"
  ,R"(

 _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-
  )"
  ,R"(
      \    /\
       )  ( ')
      (  /  )
       \(__)|
  )"
  ,R"(

 |\__/,|   (`\
 |_ _  |.--.) )
 ( T   )     /
(((^_(((/(((_/
  )"
  ,R"(
("`-''-/").___..--''"`-._
 `6_ 6  )   `-.  (     ).`-.__.`)
 (_Y_.)'  ._   )  `._ `. ``-..-'
   _..`--'_..-_/  /--'_.'
  ((((.-''  ((((.'  (((.-'
  )"
  ,R"(
           __..--''``---....___   _..._    __
 /// //_.-'    .-/";  `        ``<._  ``.''_ `. / // /
///_.-' _..--.'_    \                    `( ) ) // //
/ (_..-' // (< _     ;_..__               ; `' / ///
 / // // //  `-._,_)' // / ``--...____..-' /// / //
  )"
  ,R"(

   |\---/|
   | ,_, |
    \_`_/-..----.
 ___/ `   ' ,""+ \
(__...'   __\    |`.___.';
  (_,...'(_,.`__)/'.....+
  )"
  ,R"(

                   .-.
                  / /
                 / |
   |\     ._ ,-""  `.
   | |,,_/  7        ;
 `;=     ,=(     ,  /
  |`q  q  ` |    \_,|
 .=; <> _ ; /  ,/'/ |
';|\,j_ \;=\ ,/   `-'
    `--'_|\  )
   ,' | /  ;'
  (,,/ (,,/
  )",
  R"(

                                               .--.
                                               `.  \
                                                 \  \
                                                  .  \
                                                  :   .
                                                  |    .
                                                  |    :
                                                  |    |
  ..._  ___                                       |    |
 `."".`''''""--..___                              |    |
 ,-\  \             ""-...__         _____________/    |
 / ` " '                    `""""""""                  .
 \                                                      L
 (>                                                      \
/                                                         \
\_    ___..---.                                            L
  `--'         '.                                           \
                 .                                           \_
                _/`.                                           `.._
             .'     -.                                             `.
            /     __.-Y     /''''''-...___,...--------.._            |
           /   _."    |    /                ' .      \   '---..._    |
          /   /      /    /                _,. '    ,/           |   |
          \_,'     _.'   /              /''     _,-'            _|   |
                  '     /               `-----''               /     |
                  `...-'                                       `...-'
  )",
  R"(
            /)
           //
          //
         ((
          \\
           ))
          //
      _,-'"._
     /_  ,   \
     |   '   /
     \)    ,\'
     '|      \
     /   |   )
    /_   ,  /
   /  _  % (
   ) /    ' \
  /        \_)
  ),    )_   \_  ,
 _/    _/%     \/)
('  __/ \ ___    \,
 \   (   `"-  __  /
  '\  \   ((   >  \
    )  \   '-.-,_='~~~  ~
   ('  /         ' ~~ ~  ~~ ~~
  )",R"(
       ,
       \`-._           __
        \\  `-..____,.'  `.
         :`.         /    \`.
         :  )       :      : \
          ;'        '   ;  |  :
          )..      .. .:.`.;  :
         /::...  .:::...   ` ;
         ; _ '    __        /:\
         `:o>   /\o_>      ;:. `.
        `-`.__ ;   __..--- /:.   \
        === \_/   ;=====_.':.     ;
         ,/'`--'...`--....        ;
              ;                    ;
            .'                      ;
          .'                        ;
        .'     ..     ,      .       ;
       :       ::..  /      ;::.     |
      /      `.;::.  |       ;:..    ;
     :         |:.   :       ;:.    ;
     :         ::     ;:..   |.    ;
      :       :;      :::....|     |
      /\     ,/ \      ;:::::;     ;
    .:. \:..|    :     ; '.--|     ;
   ::.  :''  `-.,,;     ;'   ;     ;
.-'. _.'\      / `;      \,__:      \
`---'    `----'   ;      /    \,.,,,/
                   `----`
  )"

  };
}
