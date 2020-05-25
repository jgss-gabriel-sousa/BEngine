#include "Components.h"

void Gravity(Entity* entity, string argument){
    float speed = 0.0005;

    try{
        speed *= stod(argument);
    }
    catch(std::exception& e){
        LogPush("exception in \"Gravity Component\" argument");
    }
    if(entity->GetVelocity().y < speed*10){
        speed *= entity->sprite.getGlobalBounds().width*entity->sprite.getGlobalBounds().height;
        entity->SetVelocity(entity->GetVelocity().x,entity->GetVelocity().y + speed);
    }
}
