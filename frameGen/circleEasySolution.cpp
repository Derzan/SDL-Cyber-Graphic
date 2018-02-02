#include <iostream>
#include <math.h>
#include "circle.h"

Circle::Circle(const SDL_Point center, const int radiusW, const int radiusH, const SDL_Color color)
              : circleCenter(center), circleRadiusW(radiusW), 
                circleRadiusH(radiusH), circleColor(color)
{
}

void Circle::draw(SDL_Renderer* renderer)
{
    // Draw circles
    SDL_SetRenderDrawColor(renderer, circleColor.r, circleColor.g, circleColor.b, circleColor.a);
    for(float theta = 0; theta < 3.14 * 2; theta+= .001)
    {
            // x = a cos theta and y = b cos theta
            float dx = circleRadiusW * cos(theta);
            float dy = circleRadiusH * sin(theta);

            //std::cout << "x is " << dx << " and y is " << dy << std::endl;

            // If statement originally had circle formula in it, try placing
            // the ellipsis formula into it like how the circle formula was set
            // up.
            //
            // (x^2) + (b^2) = r^2
            // (x^2/a^2) + (y^2/b^2) = 1 -> (x^2*b^2) + (y^2*a^2) = a^2*b^2 
            //if(((dx*dx/(float)circleRadiusW*circleRadiusW) + (dy*dy/(float)circleRadiusH*circleRadiusH)) <= 1)
            //{
                // Determine the a and b of the ellipse formula.

                SDL_RenderDrawPoint(renderer, circleCenter.x + dx, circleCenter.y + dy);
            //}
        
    }
}
