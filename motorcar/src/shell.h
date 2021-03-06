#ifndef SHELL_H
#define SHELL_H

#include "wayland-server.h"
#include "wayland-server-protocol.h"
#include "motorcar-server-protocol.h"

#include "scenegraph/output/viewpoint.h"


namespace motorcar {
class Scene;
class Shell
{
public:
    Shell(Scene *scene);
    ~Shell();

    Scene *scene() const;

private:
    Scene *m_scene;
    struct wl_display *m_display;
    static void bind_func(struct wl_client *client, void *data,
                          uint32_t version, uint32_t id);
};
}


#endif // SHELL_H
