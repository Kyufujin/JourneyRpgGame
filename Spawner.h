#include "raylib.h"
#include "Prop.h"
#include <algorithm>
#include <vector>
#include "Character.h"

class Spawner {

public:
    Spawner(const int propsAmount);
    void initProps();
    void printSpawnerProps(Character knight);
    std::vector<Prop> getProps();
private:
    std::vector<Prop> gameProps{};
    int amount{};
};