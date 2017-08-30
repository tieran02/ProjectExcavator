#pragma once

class Radians{
public:
    static float FromDegrees(float degree)
    {
        return degree*static_cast<float>(M_PI)/180.0f;
    }

    static float ToDegrees(float radians){
        return radians*180.0f/static_cast<float>(M_PI);
    }
};