#pragma once

class Radians{
public:
    static float FromDegrees(float degree)
    {
        return degree*M_PI/180.0f;
    }

    static float ToDegrees(float radians){
        return radians*180.0f/M_PI;
    }
};