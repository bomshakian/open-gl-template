using namespace std;
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std; 

GLFWwindow* initializeWindow(int width, int height, char* windowName){

    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(width,height, windowName, NULL, NULL);
   
    

    return window;
}

void windowSetup(GLFWwindow* window){
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, 1000, 1000);
    glClearColor(0,0,0,1);
}
int main()
{
    GLFWwindow* window = initializeWindow(1000,1000,"Hohmann Transfer");
    if (!window){
        cout << "Failed to create a GFLW window" << endl;
        glfwTerminate();
        return -1;
    }
    windowSetup(window);


    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}