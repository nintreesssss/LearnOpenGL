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

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
	};

    unsigned int VBO;
	glGenBuffers(1, &VBO); //生成一个缓冲对象，将分配的缓存区的ID存在VBO中
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //绑定缓冲对象，参数1是要绑定的缓冲对象的类型，参数2是要绑定的缓冲对象的ID
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //把用户定义的数据复制到当前绑定的缓冲对象中，参数1是要复制到的缓冲对象的类型，参数2是要复制的数据的大小，参数3是要复制的数据的指针，参数4是指定了我们希望显卡如何管理给定的数据。

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER); //创建一个顶点着色器对象，参数是要创建的着色器对象的类型

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