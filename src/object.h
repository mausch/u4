/*
 * $Id$
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <deque>
#include "coords.h"
#include "tile.h"
#include "types.h"

typedef std::deque<class Object *> ObjectDeque;

typedef enum {
    MOVEMENT_FIXED,
    MOVEMENT_WANDER,
    MOVEMENT_FOLLOW_AVATAR,
    MOVEMENT_ATTACK_AVATAR
} ObjectMovementBehavior;

typedef enum {
    OBJECT_UNKNOWN,
    OBJECT_PERSON,
    OBJECT_CREATURE    
} ObjectType;

class Object {
public:
    Object(ObjectType type = OBJECT_UNKNOWN) :      
      movement_behavior(MOVEMENT_FIXED),
      objType(type),
      map(NULL),
      focused(false),
      visible(true),
      animated(true)
    {}
    
    virtual ~Object() {}    

    // Methods
    const MapTile& getTile() const          { return tile; }
    const MapTile& getPrevTile() const      { return prevTile; }
    const Coords& getCoords() const         { return coords; }
    const Coords& getPrevCoords() const     { return prevCoords; }    
    const ObjectMovementBehavior getMovementBehavior() const    { return movement_behavior; }
    const ObjectType getType() const        { return objType; }
    bool hasFocus() const                   { return focused; }
    bool isVisible() const                  { return visible; }
    bool isAnimated() const                 { return animated; }
    class Map* getMap() const                { return map; }

    void setTile(MapTile t)                 { tile = t; }
    void setPrevTile(MapTile t)             { prevTile = t; }
    void setCoords(Coords c)                { prevCoords = coords; coords = c; }
    void setPrevCoords(Coords c)            { prevCoords = c; }    
    void setMovementBehavior(ObjectMovementBehavior b)          { movement_behavior = b; }
    void setType(ObjectType t)              { objType = t; }
    void setFocus(bool f = true)            { focused = f; }
    void setVisible(bool v = true)          { visible = v; }
    void setAnimated(bool a = true)         { animated = a; }
    void setMap(class Map *m)                { map = m; }

    bool setDirection(Direction d);
    void advanceFrame();
        
    // Properties
protected:
    MapTile tile, prevTile;
    Coords coords, prevCoords;
    ObjectMovementBehavior movement_behavior;
    ObjectType objType;
    class Map *map;
    
    bool focused;
    bool visible;
    bool animated;    
};

#endif
