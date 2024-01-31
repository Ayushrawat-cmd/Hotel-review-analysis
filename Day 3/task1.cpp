#include<bits/stdc++.h>
using namespace std;
class User{
    string name;
    int  id;
    string gender;
    public:
        User() {
            cout<<"Sfsdf";
        };
        User(string name, string gender, int id){
            cout<<"user";
            this->name = name;
            this->gender = gender;
            this->id = id;
        }
        int getId(){
            return id;
        }
};

class Brick{
    int id;
    int invisible;
    vector<string> comments;
    vector<string>contents;
    public:
        Brick(){
            cout<<"brick";
            cin>>this->id;
            // this->id = id;
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

class Wall{
    int max_bricks;
    int id;
    unordered_map<int ,Brick>bricks;
    public:
        Wall(){
            cout<<"wal";
            cin>>this->id ;
            this->max_bricks = 90;
            bricks.reserve(max_bricks);
            
        }
        int maxBricks(){
            return max_bricks;
        }
        void paintBrick(int brickId, string content){
            bricks[brickId].addContent(content);
        }
        vector<vector<string>>showContentWall(){
            vector<vector<string>>tmp;
            for(auto brick: bricks){
                tmp.push_back(brick.second.showComment());
            }
            return tmp;
        }
        int allBricksOccupy(){
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

class City{
    int id;
    string city_name;
    int max_walls;
    unordered_map<int, Wall>walls;
    public:
        // City(int id){
        //     this->id = id;
        // }
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
        int totalNumberOfBricks(int wallId){
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
            cout<<"fdfsa";
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
        int numberOfCities(){
            return max_city;
        }
        int totalNumberOfWalls(int cityId){
            return cities[cityId]->maxWalls();
        }
        int numberOfCityInWalls(int cityId, int wallId){
            return cities[cityId]->totalNumberOfBricks(wallId);
        }
        void paintWallCityBrick(int cityId, int wallId, int brickId, string content){
            cities[cityId]->paintWallBrick(wallId, content, brickId);
        }
        void addOwner(Owner* owner){
            owners[owner->getId()] = owner;
        }
        Owner *HottestGuy(){
            int max_bricks = 0;
            Owner *winner;
            for(auto owner: owners){
                if(max_bricks<owner.second->numberOfBricksRecieved()){
                    max_bricks = owner.second->numberOfBricksRecieved();
                    winner = new Owner(owner.second);
                }
            }
            return winner;
        }
};

class Admin: public User{
    public:
        System *system;    
        int editBrick(int cityId, int wallId, int brickId, string content){
            system->paintWallCityBrick(cityId,wallId, brickId, content);
        }

        // Admin(System &system){
        //     this->system = system;
        // }

};

int main(){
    Owner *owner1 = new Owner(new City(), new Wall())   ;
    // City city1(1, "Delhi");
    // Wall wall1;
    // owner1 = new Owner(city1, wall1);
    // cout<<owner1.getId();
    // Owner*owner2;
    // City city2(2, "Uttarakhand");
    // Wall wall2;
    // owner2 = new Owner(city2, wall2);
    // owner1->giveBrickTo(owner2);
    // Admin * admin;
    // admin->system->addOwner(owner1);
    // admin->system->addOwner(owner2);
    // cout<<admin->system->HottestGuy()->getId();
}