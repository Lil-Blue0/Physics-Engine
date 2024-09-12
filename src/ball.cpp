//
// Created by jacob on 9/12/24.
//
#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <vector>


class Ball {
private:
    float px, py; // position
    float vx, vy; // velocity
    float ax, ay; /// acceleration
    float radius;
    int id;

public:
    Ball(float x, float y, float r) : px(x), py(y), radius(r), vx(0), vy(0), ax(0), ay(0){}

    void update(float deltaTime) {
        vx += ax * deltaTime;
        vy += ay * deltaTime;

        px += vx * deltaTime;
        py += vy * deltaTime;
    }

    sf::CircleShape getShape() const {
        sf::CircleShape shape(radius);
        shape.setPosition(px, py);
        shape.setOrigin(radius, radius);
        return shape;
    }

    void setAcceleration(float ax_, float ay_) {
        ax = ax_;
        ay = ay_;
    }
};

class CirclePhysics {
private:
    std::vector<Ball> balls;

public:
    void addBall(const Ball& ball) {
        balls.push_back(ball);
    }

    void updateAll(float deltaTime) {
        for (Ball& ball: balls) {
            ball.update(deltaTime);
        }
    }

    void renderAll(sf::RenderWindow& window) {
        for (const Ball& ball : balls) {
            window.draw(ball.getShape());
        }
    }

    int getBallCount() const {
        return balls.size();
    }
};




#endif //BALL_H
