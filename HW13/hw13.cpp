// hl5737_hw13.cpp
// Homework 13: Doodlebug

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//////////////////////////  PRE DECLARATIONS  /////////////////////////////////


class World;
class Organism;
class Ant;
class Bug;


//////////////////////////  DEFINE WORLD HERE  ////////////////////////////////


const int DIM_X = 20; 
const int DIM_Y = 20;
const int WORLD_SIZE = DIM_X * DIM_Y;
const char ANT = 'o';
const char BUG = 'X';
const char NONE = '-';
const int BUG_INIT_COUNT = 5;
const int ANT_INIT_COUNT = 100;
const int bug_init_x [BUG_INIT_COUNT] = { 3, 16, 9, 3, 16 }; //  { 1, 3 };  
const int bug_init_y [BUG_INIT_COUNT] = { 7, 7, 10, 13, 13 }; // { 1, 3 };
int ant_init_xy [ANT_INIT_COUNT];


////////////////////////////  Class World  ////////////////////////////////////


class World {
private:
    // private variables
    char world_arr[DIM_Y][DIM_X];
    int time_step;
    vector <Ant> ant_varr;
    vector <Bug> bug_varr;

    // private helper functions
    bool check_bug_init(int coord);
    bool check_ant_init(int coord, int size);
    void random_num_gen();
public:
    friend class Organism; 

    // accessor mutator constructor
    World();
    int get_time_step() { return time_step; }
    void add_time_step() { time_step++; }
    char get_arr(int x, int y) { return world_arr[y][x]; }
    void set_arr(int x, int y, char new_char) { world_arr[y][x] = new_char; }
    int get_bug_varr_size() { return bug_varr.size(); }
    int get_ant_varr_size() { return ant_varr.size(); }
    Bug* get_bug_ptr(int i) {return &bug_varr[i]; }
    Ant* get_ant_ptr(int i) {return &ant_varr[i]; }

    // other functions
    void move_bugs();
    void bugs_status_check();
    void move_ants();
    void ants_status_check();
    void initialize_world();
    void print_world ();
    bool sel_empty_spot(int x, int y, int& new_x, int& new_y);
    bool check_occupancy(char by_this, int at_x, int at_y);
    void kill_critter(char critter, int new_x, int new_y);
    bool out_of_bounds(int x, int y);
};

World::World() {
    for (int i = 0; i < DIM_Y; i++)                 // rows
        for (int j = 0; j < DIM_X; j++)             // columns
            world_arr[i][j] = NONE;  
    
    time_step = 0;
    ant_varr.resize(ANT_INIT_COUNT);
    bug_varr.resize(BUG_INIT_COUNT);
}

bool World::sel_empty_spot(int x, int y, int& new_x, int& new_y) {
    if(check_occupancy(NONE, x, y - 1) 
        && !out_of_bounds(x, y - 1)) {              // above
        new_x = x;
        new_y = y - 1;
        return true;
    }

    else if(check_occupancy(NONE, x, y + 1) 
        && !out_of_bounds(x, y + 1)) {              // below
        new_x = x;
        new_y = y + 1;
        return true;
    }

    else if(check_occupancy(NONE, x - 1, y) 
        && !out_of_bounds(x - 1, y)) {              // left
        new_x = x - 1;
        new_y = y;
        return true;
    }

    else if(check_occupancy(NONE, x + 1, y) 
        && !out_of_bounds(x + 1, y)) {              // right
        new_x = x + 1;
        new_y = y;
        return true;
    }

    return false;
}

bool World::check_bug_init(int coord){              // return true if coord is used
    for (int i = 0; i < BUG_INIT_COUNT; i++)
        if ((bug_init_x[i] + bug_init_y[i] * DIM_X) == coord)
            return true;
    return false;  
}

bool World::check_ant_init(int coord, int size){    // return true if coord is used
    for (int i = 0; i < size; i++)
        if (ant_init_xy[i] == coord)
            return true;
    return false;  
}

void World::random_num_gen() {
    srand(time(0));
    int temp_coord = 0;

    for (int i = 0; i < ANT_INIT_COUNT; i++) {
        temp_coord += (rand() % ((WORLD_SIZE - temp_coord) / (ANT_INIT_COUNT - i)) + 1);
        while(check_bug_init(temp_coord))           // avoid bugs, add
            temp_coord++;
        while(temp_coord >= WORLD_SIZE              // avoid upper boundary, bug, ants
            || check_bug_init(temp_coord) 
            || check_ant_init(temp_coord, i))
            temp_coord--;
        ant_init_xy[i] = temp_coord;
    }
}

bool World::out_of_bounds(int x, int y) {
    if (x < 0 || x >= DIM_X || y < 0 || y >= DIM_Y)
        return true;
    else return false;
}

void World::print_world() {
    cout << "\n\nWorld at time " << time_step << ":\n\n";

    for (int i = 0; i < DIM_Y; i++) {               // rows, y
        for (int j = 0; j < DIM_X; j++)             // columns, x
            cout << world_arr[i][j] << ' ';
        cout << endl;                               // new line
    }
}

bool World::check_occupancy(char by_this, int at_x, int at_y) {
    if (world_arr[at_y][at_x] == by_this)
        return true;
    return false;
}


/////////////////////////  Class Organism DECLA ///////////////////////////////


class Organism {
protected:
    int x;
    int y;
    int preg_lvl;
public:
    Organism(int the_x, int the_y) : x(the_x), y(the_y), preg_lvl(0) {}
    Organism() : x(0), y(0), preg_lvl(0) {}
    int get_x() const { return x; } 
    int get_y() const { return y; } 
    void set_x(int the_x) { x = the_x; }
    void set_y(int the_y) { y = the_y; }
    int get_preg_lvl() { return preg_lvl; }
    void add_preg_lvl() { preg_lvl++; }
    void reset_preg_lvl() { preg_lvl = 0; }

    // main functions
    virtual void move(World& w) {}

    // helper functions
    void sel_rand_new_spot(int& new_x, int& new_y);
    bool find_critter(World& w, char find_this, int& coord_x, int& coord_y);
    virtual bool should_breed() { return false; }
};


/////////////////////////////  Class Bug DECLA ////////////////////////////////


class Bug : public Organism {
private:
    int starve_lvl;
public:
    Bug (int the_x, int the_y) : Organism (the_x, the_y), starve_lvl(0) {}
    Bug () : Organism (), starve_lvl(0) {}
    int get_starve_lvl() { return starve_lvl; }
    void add_starve_lvl() { starve_lvl++; }
    void reset_starve_lvl() { starve_lvl = 0; }

    // main functions
    virtual void move(World& w);

    // helper functions
    bool should_die();
    virtual bool should_breed();
};


//////////////////////////// Class Ant DECLA //////////////////////////////////


class Ant : public Organism {
public:
    Ant (int the_x, int the_y) : Organism (the_x, the_y) {}
    Ant () : Organism () {}
    virtual void move(World& w);
    virtual bool should_breed();
};


//////////////////////////  Class Organism DEF ////////////////////////////////


bool Organism::find_critter(World& w, char find_this, int& coord_x, int& coord_y) {
    if(!w.out_of_bounds(x, y - 1)
        && w.get_arr(x, y - 1) == find_this){   // find ant above
        coord_x = x;
        coord_y = y - 1;
        return true;
    }

    else if(!w.out_of_bounds(x - 1, y)
        && w.get_arr(x - 1, y) == find_this){   // find ant left
        coord_x = x - 1;
        coord_y = y;
        return true;
    }

    else if(!w.out_of_bounds(x + 1, y)
        && w.get_arr(x + 1, y) == find_this){   // find ant right
        coord_x = x + 1;
        coord_y = y;
        return true;
    }

    else if(!w.out_of_bounds(x, y + 1)
        && w.get_arr(x, y + 1) == find_this){   // find ant below
        coord_x = x;
        coord_y = y + 1;
        return true;
    }
    return false;
}

void Organism::sel_rand_new_spot(int& new_x, int& new_y) {
    int direction_draw = rand() % 4;            // pick direction >> get 0 - 3

    switch (direction_draw) {
    case 0:                                     // above
        new_x = x;
        new_y = y - 1;
        break;

    case 1:                                     // left
        new_x = x - 1;
        new_y = y;
        break;

    case 2:                                     // right
        new_x = x + 1;
        new_y = y;
        break;

    case 3:                                     // below
        new_x = x;
        new_y = y + 1;
        break;  

    default:
        break;
    }
}


/////////////////////////////  Class Bug DEF  /////////////////////////////////


bool Bug::should_die() {
    if(starve_lvl == 3)
        return true;
    return false;
}

bool Bug::should_breed() {
    if(preg_lvl >= 8)
        return true;
    return false;
}

void Bug::move(World& w) {
    int new_x;
    int new_y;
    bool found_new_spot = false;

    // move condition A: if found ant, direction = first ant
    if(find_critter(w, ANT, new_x, new_y)) {
        found_new_spot = true;
        w.kill_critter(ANT, new_x, new_y);      // kill ant
        reset_starve_lvl();                     // not starving
    }
    
    // move condition B: direction = random
    else {
        sel_rand_new_spot(new_x, new_y);

        if(!w.check_occupancy(BUG, new_x, new_y) // if not occupied and not out of bounds
            && !w.out_of_bounds(new_x, new_y)) { 
            found_new_spot = true;
        }
        add_starve_lvl();
    }
    
    // check if new direction is valid
    if(found_new_spot) {                        // if yes
        
        int old_x = x;                          // save old coord
        int old_y = y;
        
        x = new_x;                              // set new coord
        y = new_y;
        
        w.set_arr(old_x, old_y, NONE);          // update world
        w.set_arr(x, y, BUG);
    }

    // update preg lvl
    add_preg_lvl();
}


////////////////////////////  Class Ant DEF  //////////////////////////////////


void Ant::move(World& w) {

    // assign value based on draw
    int new_x, new_y;
    sel_rand_new_spot(new_x, new_y);

    // if not out of bounds, no ant, no bug
    if (!w.out_of_bounds(new_x, new_y)
        && !w.check_occupancy(ANT, new_x, new_y)
        && !w.check_occupancy(BUG, new_x, new_y)) 
    {                                           
        int old_x = x;                          // means vacant
        int old_y = y;
                                                
        x = new_x;                              // udpate new coord
        y = new_y;
                                                
        w.set_arr(old_x, old_y, NONE);          // update world
        w.set_arr(x, y, ANT);
    }                                           // otherwise coord & world stays the same
    
    add_preg_lvl();                             // update step count
}

bool Ant::should_breed() {
    if(preg_lvl >= 3)
        return true;
    return false;
}


////////////////////////  Other World Functions  //////////////////////////////


void World::move_bugs() {
    for (int i = 0; i < bug_varr.size(); i++)
        bug_varr[i].move(*this);
}

void World::move_ants() {
    for (int i = 0; i < ant_varr.size(); i++)
        ant_varr[i].move(*this);
}

void World::initialize_world(){
    // bugs with defined positions
    for (int i = 0; i < BUG_INIT_COUNT; i++){
        bug_varr[i] = Bug(bug_init_x[i], bug_init_y[i]);
        world_arr[bug_init_y[i]][bug_init_x[i]] = BUG;
    } 

    // random coordinates for ants : 1 - 200 inclusive
    random_num_gen();
    for (int i = 0; i < ANT_INIT_COUNT; i++) {
        int temp_x = ant_init_xy[i] % DIM_X;
        int temp_y = ant_init_xy[i] / DIM_X;
        ant_varr[i] = Ant(temp_x, temp_y);
        world_arr[temp_y][temp_x] = ANT;
    }
}

void World::bugs_status_check() {
    // pregnancy: add all new babies to the end of array
    int size = bug_varr.size();

    for (int i = 0; i < size; i++)
    {
        if(bug_varr[i].should_breed()) {        // if pregnancy_lvl = 8
            
            int curr_x = bug_varr[i].get_x();   // find an empty cell
            int curr_y = bug_varr[i].get_y();
            int baby_x, baby_y;
            bool found_spot = sel_empty_spot(curr_x, curr_y, baby_x, baby_y);

            if(found_spot) {                    // if found new cell:
                Bug newbug(baby_x, baby_y);     // create new bug with new coord
                bug_varr.push_back(newbug);     // add to varr
                bug_varr[i].reset_preg_lvl();   // reset preg level = 0
                set_arr(baby_x, baby_y, BUG);   // put baby on map
            }
        }
    }

    // starvation: move all dying bugs to end of array
    int num_to_del = 0;
    int swap_ind = bug_varr.size() - 1;
    for (int i = 0; i < size; i++){
        if(bug_varr[i].should_die()) {          // for each that should starve
            kill_critter(BUG, bug_varr[i].get_x(), bug_varr[i].get_y()); // kill critter on map
            bug_varr[i] = bug_varr[swap_ind--]; // replaced by last bug, update ind
            num_to_del++;
        }
    }

    if(num_to_del != 0)                         // remove from vector
        bug_varr.resize(swap_ind + 1);
}

void World::ants_status_check() {
    // pregnancy: add all new babies to the end of array
    int size = ant_varr.size();
    for (int i = 0; i < size; i++){
        if(ant_varr[i].should_breed()) {        // if pregnancy_lvl = 3
            int curr_x = ant_varr[i].get_x();   // find an empty cell
            int curr_y = ant_varr[i].get_y();
            int baby_x, baby_y;
            bool found_spot = sel_empty_spot(curr_x, curr_y, baby_x, baby_y);
        
            if(found_spot) {                    // if found new cell:
                Ant newant(baby_x, baby_y);     // create new bug with new coord
                ant_varr.push_back(newant);     // add to varr
                ant_varr[i].reset_preg_lvl();   // reset level = 0
                set_arr(baby_x, baby_y, ANT);   // put baby on map
            }                                   // else give birth next round and do nothing for now
        }
    }
}

void World::kill_critter(char critter, int at_x, int at_y) { 
    int ind;

    // ANT: does not need to update world since space occupied by bug now
    if(critter == ANT) {
        int size = ant_varr.size();
        for(int i = 0; i < size; i++) {
            if(at_x == ant_varr[i].get_x() && at_y == ant_varr[i].get_y()) {
                ind = i;
                break;
            } 
        }
        ant_varr[ind] = ant_varr[size - 1];     // erase from vector
        ant_varr.resize(size - 1);
    }

    // BUG
    else if(critter == BUG) {
        int size = bug_varr.size();             // find ind
        for(int i = 0; i < size; i++) {
            if(at_x == bug_varr[i].get_x() && at_y == bug_varr[i].get_y()) {
                ind = i;
                break;
            } 
        }
        set_arr(at_x, at_y, NONE);              // update world
        bug_varr[ind] = bug_varr[size - 1];     // erase from vector
        bug_varr.resize(size - 1);
    }
}


/////////////////////////////////// MAIN  /////////////////////////////////////


int main() {
    // initialize world 
    World world;
    world.initialize_world();
    
    // prompt
    cout << "\n\nWelcome to the world of Critters \n";
    world.print_world();
    cout << "\nTo continue, press ENTER\n"
        << "Enter any other symbol to quit\n";

    // while loop to keep going
    string getenter;
    getline(cin, getenter);
    while(getenter.empty()){
    
        world.move_bugs();                      // bugs move
        world.bugs_status_check();
    
        world.move_ants();                      // ants move
        world.ants_status_check();
    
        world.add_time_step();                  // present world
        world.print_world();
    
        cout << "\nTo continue, press ENTER\n"; // keep going?
        getline(cin, getenter);
    }

    return 0;
}
