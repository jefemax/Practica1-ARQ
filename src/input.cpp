#include "../include/input.h"

bool keyOnce(int key, bool* keysArray)
{
    if (glfwGetKey(key))
    {
        printf("keysArray[key] %d\n", keysArray[key]);
        if (!keysArray[key])
        {
            keysArray[key] = true;
            printf("keysArray[key]2 %d\n", keysArray[key]);
            printf("true %d\n", key);
            return true;
        }
        if (keysArray[key])
        {
            return false;
        }
    }
    else
    {
        keysArray[key] = false;
        return false;
    }

    return false;
}