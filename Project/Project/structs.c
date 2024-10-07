#define SIZE 1000

typedef struct Time{
    short hours;
    short minute;
    short second;
}Time;

typedef struct Order{
    long long order_id;
    int quantity;
    double price;
    Time time_stamp;
    char stock_symbol[15];
    char side;
}Order;

//Order Book, currently implemented as an array but can be implemented as an linkedlist for dynamic size

typedef Order order_book[SIZE];

typedef struct Sell_order{
    
 
