
enum Postion {x,y};     

struct EnemyInfo
{
    int HP = 1;
    int position[2];
    int id;
    char fig = 'W';
    char missile = '*';

};    


struct PlayerInfo
{
    int HP = 10;
    int position[2];
    int id;
    char fig = 'M';
    char missile[3] = {'*','^','A'};
    int score;
};

struct ItemInfo
{
    char item_fig[4] = {'E','P','$','O'};
    int item_info[4] = {1,1,1,-1};
    int position[4][2]= {{0,0},{0,0},{0,0},{0,0}};

};

struct MapInfo
{
    char fig[2] = {'_','|'};
};