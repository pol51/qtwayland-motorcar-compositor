/****************************************************************************
**This file is part of the MotorCar QtWayland Compositor
**
**
**Copyright (C) 2013 Forrest Reiling
**
**
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
**
****************************************************************************/

#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/matrix_access.hpp"
//#include "opengldata.h"
#include <stdio.h>
#include <iostream>
//#include "scenegraph/scene.h""

namespace motorcar{
class WaylandSurfaceNode;
class SceneGraphNode;
class Geometry
{
public:

    static void printMatrix(glm::mat4 m);
    static void printVector(glm::vec3 v);

    struct Ray
    {
        Ray(glm::vec3 p, glm::vec3 d);
        Ray transform(glm::mat4 t) const;
        glm::vec3 p, d;
        glm::vec3 solve(float t) const;
        void print() const;
        void draw(motorcar::SceneGraphNode *parent, glm::vec3 color, glm::mat4 transform = glm::mat4(1));

    };

    struct Plane
    {
        Plane(glm::vec3 p, glm::vec3 n);
        glm::vec3 p, n;
        float intersect(Ray r);
    };

    //represents an axis aligned box centered at the origin, whos full extend in each axis is stored in dimensions
    struct AxisAlignedBox
    {
        AxisAlignedBox(glm::vec3 dimensions);
        glm::vec3 dimensions;
        float intersect(Ray r, float t0, float t1);
    };

    struct Rectangle
    {
        Rectangle(glm::ivec2 size);
        Rectangle();
        virtual ~Rectangle() {}

        virtual glm::ivec2 size() {return m_size;}

    protected:
        glm::ivec2 m_size;

    };

    struct RaySurfaceIntersection
    {
        RaySurfaceIntersection(WaylandSurfaceNode *surfaceNode, glm::vec2 surfaceLocalCoordinates , const Geometry::Ray &ray , float t );
        WaylandSurfaceNode *surfaceNode;
        glm::vec2 surfaceLocalCoordinates;
        Geometry::Ray ray;
        float t;
    };


};

}

#endif // GEOMETRY_H
