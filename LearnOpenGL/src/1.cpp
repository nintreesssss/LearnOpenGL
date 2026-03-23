#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

static void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) //检测ESC是否被按下
        glfwSetWindowShouldClose(window, true);
}

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL); //创建窗口对象 前两个参数是窗口的宽和高，第三个参数是窗口标题
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
	glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

	glViewport(0, 0, 800, 600); //设置视口大小 前两个参数是视口左下角的坐标，后两个参数是视口的宽和高

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //注册窗口大小改变的回调函数

    while (!glfwWindowShouldClose(window))
    {
        //输入
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //设置清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT); //清空颜色缓冲

		//检查事件并调用相应的响应函数（键盘输入、鼠标移动等），交换缓冲
        glfwSwapBuffers(window);
		glfwPollEvents();
    }

    glfwTerminate();
    return 0; 
}