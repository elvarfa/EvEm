#include "../include/Application.h"

Application::Application(std::string title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
}

Application::~Application()
{
    delete p;
    delete m;
    delete g;

    glfwTerminate();
}

bool Application::Init()
{
    if (!glfwInit())
        return false;

    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
    if (!this->window)
    {
        glfwTerminate();
        return false;
    }

    g = new GPU();
    m = new Memory(g);
    p = new Processor(g, m);

    return true;
}

void Application::Loop()
{
    while (p->IsRunning() || !glfwWindowShouldClose(window))
    {
        Frame();
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-1, -1);
        glVertex2f(0, 1);
        glVertex2f(1, -1);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::Frame()
{
    unsigned int fclk = p->tClock + 70224;
    do
    {
        p->ProcessOpcode(p->FetchInstruction());
        p->Render();
    } while(p->tClock < fclk);
}

int main(void)
{
    Application app("Test", 800, 600);

    app.Init();
    app.Loop();

    return 0;
}
