#include <iostream>

class Marine {
    private:
        static int total_marine_num;

        int hp;
        int coord_x, coord_y;
        bool is_dead;

        const int default_damage;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, int default_damage);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_statuts();
        ~Marine() {
            total_marine_num-=1;
            std::cout << "~Marine() -> marine num : " << total_marine_num <<std::endl;
        };
};

int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num +=1;
};

Marine::Marine(int x, int y) : coord_x(x),coord_y(y), hp(50), default_damage(5), is_dead(false){
    total_marine_num +=1;
};

Marine::Marine(int x, int y, int default_damage) : coord_x(x),coord_y(y), hp(50), default_damage(default_damage), is_dead(false){
    total_marine_num +=1;
};

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
};

int Marine::attack(){
    return default_damage;
};

void Marine::be_attacked(int damage_earn) {
    hp-=damage_earn;
    if(hp<=0) is_dead = true; 
};

void Marine::show_statuts(){
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : (" << coord_x <<","<<coord_y << ")" << std::endl;
    std::cout << "HP : "<<hp << std::endl;
    std::cout << "current total marine num: " << total_marine_num << std::endl;
};

void create_marine() {
    Marine marines(10,10,4);
};

int main(){
    Marine marine1(2,3,5);
    marine1.show_statuts();

    Marine marine2(3,5,10);
    marine2.show_statuts();

    create_marine();

    std::cout << std::endl << "marine1 attack marine2" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_statuts();
    marine2.show_statuts();
};
