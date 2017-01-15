#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

//Creating constants for the price of each root
const float ITEM1_PRICE = 4.50;  //Price of Ginko Root
const float ITEM2_PRICE = 1.23; //Price of Mandrake Root
const float ITEM3_PRICE = 2.39;  //Price of Ginseng Root
const float ITEM4_PRICE = 99.98;  //Price of Square Root
const float ITEM5_PRICE = 0.78;  //Price of Vitamin R Root

const float LOW_AMNT_TAX = 0.50; //Tax for subtotals less than $100
const float MID_AMNT_TAX = 0.27;  //Tax for subtotals less than $300 and more than $100
const float HIGH_AMNT_TAX = 0.02; //Tax for subtotals more than $300
const int SUBMIN = 100;           //Min value of subtoatl range
const int SUBMAX = 300;           //Max value of subtotal range
const int MIN_CHOICE = 1;         //Lowest amount user can take
const int MAX_CHOICE = 6;         //Highest value that user can select
const float ROUND_AMT = 0.005;    //Round amount
const int MACHINE_MAX = 7;        //Max amount that the machine can get from random

//Sizes for each array
const int SAYINGS_SIZE = 7;
const int ITEM_NAMES_SIZE = 5;

const int USER_AMNT_FACTOR = 2;

//Constants for the avaliable version of each item
const string ITEM1 = "1. Ginko Root ($4.50)";
const string ITEM2 = "2. Mandrake Root ($1.23)";
const string ITEM3 = "3. Ginseng Root ($2.39)";
const string ITEM4 = "4. Square Root ($99.98)";
const string ITEM5 = "5. Vitamin R Root ($0.78)";
//Constants for the unavalible versions of each item
const string ITEM1_GONE = "1. Ginko Root ($4.50) NO LONGER AVAILABLE ";
const string ITEM2_GONE = "2. Mandrake Root ($1.23) NO LONGER AVAILABLE ";
const string ITEM3_GONE = "3. Ginseng Root ($2.39) NO LONGER AVAILABLE ";
const string ITEM4_GONE = "4. Square Root ($99.98) NO LONGER AVAILABLE ";
const string ITEM5_GONE = "5. Vitamin R Root ($0.78) NO LONGER AVAILABLE ";

//Constants for the computer messages
const string COMP_AGREE = "Fine! ... but you're gonna be sorry.";
const string COMP_MSG1 = "No, you really want ";
const string COMP_MSG2 = "As my uncle Hal would say, \""
                          "I can't do that for you, Dave. You want \" ";
const string COMP_MSG3 = "Only a loooooser would want THAT."
                         " Try this instead: ";
const string COMP_MSG4 = "WRONG! I'm sure you meant to pick ";
const string COMP_MSG5 = "PPpfffffttt. I think you need ";
const string COMP_MSG6 = "Only idiots choose that. Better to have some ";
const string COMP_MSG7 = "Tss, you must be Homer! Only Homer would want that."
                          "Lisa's preference is ";
//Constant array of the item names
const string item_names[ITEM_NAMES_SIZE] = {"Ginko Root","Mandrake Root",
                                            "Ginseng Root","Square Root",
                                            "Vitamin R Root"};
//Constant array of the item prices
const float PRICES[ITEM_NAMES_SIZE]={ITEM1_PRICE,ITEM2_PRICE,ITEM3_PRICE
                                    ,ITEM4_PRICE,ITEM5_PRICE};
//Constant array of the computer's sayings
const string SAYINGS[SAYINGS_SIZE]={COMP_MSG1,COMP_MSG2,COMP_MSG3,COMP_MSG4,
                                    COMP_MSG5,COMP_MSG6,COMP_MSG7};
#endif
