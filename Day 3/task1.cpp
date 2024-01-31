#include<bits/stdc++.h>
using namespace std;

/*
User class for the different type of users like admin, owner
*/
class User{
    string name;
    int  id;
    string gender;
    public:
        User() =default;
        User(string name, string gender, int id){
            this->name = name;
            this->gender = gender;
            this->id = id;
        }
        int getId(){
            return id;
        }
};

/*
Brick is the class which get invisible when 10 bricks of the walls get filled
Its having the comments vector as the different visitors comment on the single brick
There is the contents vector which hold of the paint done on the Brick by the owner or admin
*/
class Brick{
    int id;
    int invisible;
    vector<string> comments;
    vector<string>contents;
    public:
        Brick() = default;
        Brick(int id){
            this->id = id;
            this->invisible = 0;
        }
        void setInvisible(){
            this->invisible = 1;
        }
        void addComment(string comment){
            comments.push_back(comment);
        }
        void addContent(string content){
            contents.push_back(content);
        }
        vector<string> showContent(){
            return contents;
        }
        vector<string>showComment(){
            return comments;
        }
};

/*
Wall is the class which holds the bricks map
It also have the maximum bricks property
*/
class Wall{
    int max_bricks;
    int id;
    unordered_map<int ,Brick>bricks; // here each brick id have the brick object in it
    public:
        Wall(int id){
            this->id = id ;
            this->max_bricks = 90;
            bricks.reserve(max_bricks);
            
        }
        int maxBricks(){ 
            return max_bricks;
        }
        void paintBrick(int brickId, string content){ // paint the brick at the given id with the content
            bricks[brickId].addContent(content);
        }
        vector<vector<string>>showContentWall(){ // show the content on the wall when the owner visits
            vector<vector<string>>tmp;
            for(auto brick: bricks){
                tmp.push_back(brick.second.showComment());
            }
            return tmp;
        }
        int allBricksOccupy(){ // is all the bricks occupy or not 
            for(auto brick:bricks){
                if(brick.second.showContent().size() || brick.second.showComment().size())
                    return false;
            }
            return true;
        }
        int getWallId(){
            return id;
        }
};

/*
City is having the many walls in it.
*/
class City{ 
    int id;
    string city_name; 
    int max_walls;
    unordered_map<int, Wall>walls;
    public:
        City() = default;
        City(int id, string city_name){
            this->id = id;
            this->max_walls =1;
            this->city_name = city_name;
            walls.reserve(max_walls);
        }
        int maxWalls(){
            return max_walls;
        }
        int totalNumberOfBricks(int wallId){ // total number of bricks for the given wall
            return walls[wallId].maxBricks();
        }
        void paintWallBrick(int wallId, string content, int brickId){ 
            walls[wallId].paintBrick(brickId,content);
        }
        vector<vector<string>>showContentCityOfWall(int wallID){ 
            return walls[wallID].showContentWall();
        }
        bool addNewWall(Wall &wall){
            if(wall.allBricksOccupy()){
                walls[wall.getWallId()] = wall;
                return true;
            }
            return false;
        }
};

/*
Owner is the user and could have many walls 
It could have many bricks which he gets from other person
It could have many lovers 
It have the city
*/
class Owner: public User{
    City *city;
    vector<Wall *> walls;
    vector<Brick* >gotBrick;
    vector<Owner*>lovers;
    public:
        Owner() =default;
        Owner(Owner*owner){
            this->city = owner->city;
            this->walls = owner->walls;
            this->gotBrick=owner->gotBrick;
            this->lovers = owner->lovers;
        }
        Owner(City &city, vector<Wall*>wall){
            this->city= new City(city);
            this->walls = walls;
        }
        void recieveTheBrick(Brick*brick){
            gotBrick.push_back(brick);
        }
        int numberOfBricksRecieved(){
            return gotBrick.size();
        }
        void giveBrickTo(Owner *owner){
            lovers.push_back(owner);
        }

};

/*
System have all the function requires to do 
It have cities and owners
*/
class System { 
    int max_city;
    unordered_map<int ,City*>cities;
    unordered_map<int, Owner*>owners;
    public:
        System() =  default;
        System(int max_city){
            this->max_city = max_city;
            cities.reserve(max_city);
        }
        int numberOfCities(){ // number of cities there in the system
            return max_city;
        }
        int totalNumberOfWalls(int cityId){ // total number of walls for dedicated city
            return cities[cityId]->maxWalls();
        }
        int numberOfBricksInWalls(int cityId, int wallId){ // total number of bricks in the given city and particular wall
            return cities[cityId]->totalNumberOfBricks(wallId);
        }
        void paintWallCityBrick(int cityId, int wallId, int brickId, string content){ // paint the wall of the given city and further wall of that city and further the brick of that wall.
            cities[cityId]->paintWallBrick(wallId, content, brickId);
        }
        void addOwner(Owner* owner){ // add owner in the system
            owners[owner->getId()] = owner;
        }
        Owner *HottestGuy(){ // hottest guy in the system
            int max_bricks = 0;
            Owner *winner;
            for(auto owner: owners){
                if(max_bricks<owner.second->numberOfBricksRecieved()){ // one who got maximum bricks is the hottest guy
                    max_bricks = owner.second->numberOfBricksRecieved();
                    winner = new Owner(owner.second);
                }
            }
            return winner;
        }
};

/*
Admin is the user which having all the privelage of the system
*/
class Admin: public User{ 
    public:
        System *system;    
        Admin(){
            system = new System();
        }

};


int main(){
}