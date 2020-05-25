#include "Components.h"

void Bullet(Entity* entity,string argument){
    float speed = stod(argument);

    entity->SetPosition(entity->GetX() + sin((3.141592/180)*entity->sprite.getRotation()) * speed,
                        entity->GetY() + cos((3.141592/180)*entity->sprite.getRotation()) * speed);
}
