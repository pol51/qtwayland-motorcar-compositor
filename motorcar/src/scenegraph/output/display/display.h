#ifndef DISPLAY_H
#define DISPLAY_H
#include "../viewpoint.h"
#include "../../physicalnode.h"
#include "../../../gl/openglcontext.h"
//#include <GLES2/gl2.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>


namespace motorcar {
class WaylandSurface;
class Display : public PhysicalNode, public Geometry::Rectangle
{
public:
    Display(OpenGLContext *glContext, glm::vec2 displayDimensions, PhysicalNode *parent, const glm::mat4 &transform = glm::mat4());
    virtual ~Display();

    //set up  and tear down for drawing, make all calls that need to be made only once per frame
    virtual void prepareForDraw();
    virtual void finishDraw() {}


    //for legacy mouse support
    //projects mouse position into worldpace based on implementation specific details
    virtual Geometry::Ray worldRayAtDisplayPosition(glm::vec2 pixel);

    glm::vec3 worldPositionAtDisplayPosition(glm::vec2 pixel);

    //returns resolution of this display in pixels, inherited from rectangle
    virtual glm::ivec2 size() override;

    //returns the size of this display in meters
    virtual glm::vec2 dimensions() const;


    void addViewpoint(ViewPoint *v);

    std::vector<ViewPoint *> viewpoints() const;


    OpenGLContext *glContext() const;
    void setGlContext(OpenGLContext *glContext);

    virtual GLuint activeFrameBuffer() const {return 0;}
    virtual GLuint depthBufferTexture() const {return 0;}

    GLuint scratchFrameBuffer() const;
    GLuint scratchColorBufferTexture() const;
    GLuint scratchDepthBufferTexture() const;


private:
    std::vector<ViewPoint *> m_viewpoints;
    glm::vec2 m_dimensions;
    OpenGLContext *m_glContext;

protected:
    GLuint m_scratchFrameBuffer, m_scratchColorBufferTexture, m_scratchDepthBufferTexture;





};
}



#endif // DISPLAY_H
