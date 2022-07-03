#include "Spawner.h"
#include "raymath.h"
#include <algorithm>
#include <vector>
#include <random>

Spawner::Spawner(const int propsAmount) : amount(propsAmount)
{
    
}
void Spawner::initProps(){
    std::random_device dev;
        for(int i=0; i<amount; i++)
        {
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist6(150.f,800.f);
            gameProps.push_back(
                Prop{
                    Vector2{dist6(rng), dist6(rng)}, 
                    LoadTexture("nature_tileset/Rock.png")}
                );
            
        }
}
void Spawner::printSpawnerProps(Character knight){
    // draw the props
        for (auto prop : gameProps)
        {
            prop.Render(knight.getWorldPos());
        }
}

std::vector<Prop> Spawner::getProps(){    
    return gameProps;
}