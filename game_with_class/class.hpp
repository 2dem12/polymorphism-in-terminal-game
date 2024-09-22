class Attacker {
public:
    Attacker() : heals_(30), damage_(10) {}
    Attacker(int hp, int dam) : heals_(hp), damage_(dam) {}

    void attack(Attacker& breack) {
        breack.heals_ = std::max(breack.heals_ - damage_, 0);
    }
    bool is_alive() {
        if (heals_ != 0) {
            return true;
        } else {
            return false;
        }
    }

    int cout_hp() {
        return heals_;
    }
protected:
    int heals_, damage_;

};

class Hero : public Attacker {
public:


};

class Enemy : public Attacker {

};

class  Dragon : public Enemy {
public:
    Dragon(char clr) : color_(clr) {}
    virtual ~Dragon() {}


    void set_answer() {
        if (color_ == 'r') {
            try_answer_ = x_ + y_;
        } else if (color_ == 'g') {
            try_answer_ = x_ - y_;
        } else if (color_ == 'b') {
            try_answer_ = x_ * y_;
        }
        std::cin >> answer_;
    }

    bool check_answer() {
        if (answer_ == try_answer_) {
            return true;
        } else {
            return false;
        }
    }

    void question(int x, int y) {
        x_ = x;
        y_ = y;
        if (color_ == 'g' && x_ < y_) std::swap(x_, y_);
        std::cout << x_ << ' ';
        if (color_ == 'r') {
            std::cout << "+";
        } else if (color_ == 'g') {
            std::cout << "-";
        } else if (color_ == 'b') {
            std::cout << "*";
        }
        std::cout << " " << y_ << " = ";
    }

    char get_color() {
        return color_;
    }

private:
    char color_;
    std::string quest_;
    int x_, y_, answer_, try_answer_;
};

class RedDragon : public Dragon {
public:
    RedDragon() : Dragon('r') {}

};

class GreenDragon : public Dragon {
public:
    GreenDragon() : Dragon('g') {}
    std::string get_color() {
        return "green";
    }
};

class BlackDragon : public Dragon {
public:
    BlackDragon() : Dragon('b') {}
    std::string get_color() {
        return "black";
    }
};