#include "Entity.h"

Entity::Entity(string id,sf::Vector2f position){
    this->id = id;
    sprite.setPosition(position);
    velocity = sf::Vector2f(0,0);
    drag = 0;
}

void Entity::SetPosition(float x, float y){
    sprite.setPosition(x,y);
}

void Entity::SetVelocity(float x, float y){
    velocity = sf::Vector2f(x,y);
}

void Entity::SetColor(int r, int g,int b,int alpha){
    sprite.setFillColor(sf::Color(r,g,b,alpha));
}

float Entity::GetDrag(){
    drag = (sprite.getSize().x+sprite.getSize().y)*((velocity.x+velocity.y)/2);

    return drag;
}

float Entity::GetVelocityAngle(){
    if(velocity.x > velocity.y && velocity.x > 0){
        velocityAngle = 90;
    }
    else if(velocity.x > velocity.y && velocity.x < 0){
        velocityAngle = 270;
    }
    else if(velocity.y > velocity.x && velocity.y < 0){
        velocityAngle = 0;
    }
    else if(velocity.y > velocity.x && velocity.y > 0){
        velocityAngle = 180;
    }
    else if(velocity.x == velocity.y && velocity.x < 0 && velocity.y < 0){
        velocityAngle = 315;
    }
    else if(velocity.x == velocity.y && velocity.x < 0 && velocity.y > 0){
        velocityAngle = 225;
    }
    else if(velocity.x == velocity.y && velocity.x > 0 && velocity.y > 0){
        velocityAngle = 135;
    }
    else if(velocity.x == velocity.y && velocity.x > 0 && velocity.y < 0){
        velocityAngle = 45;
    }

    //LogPush("velAngle:"+to_string(velocityAngle));
    //LogPush("vel:"+to_string((velocity.x+velocity.y)/2));
    return velocityAngle;
}

void Entity::SetSize(float x, float y){
    sprite.setSize(sf::Vector2f(x,y));
    sprite.setOrigin(GetWidth()/2,GetHeight()/2);
}

void Entity::AddComponent(string component,string argument){
    components.push_back(make_pair(component,argument));
}

void Entity::SetTexture(string tag,AssetManager& asset){
    if(asset.CheckContent("texture",tag)){
        sprite.setTexture(&(asset.GetTexture(tag)),true);
    }
    else{
        asset.LoadTexture(tag);
        sprite.setTexture(&(asset.GetTexture(tag)),true);
    }
    sprite.setOrigin(GetWidth()/2,GetHeight()/2);
}
