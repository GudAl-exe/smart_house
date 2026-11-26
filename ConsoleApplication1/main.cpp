#include <iostream>
#include <string>
#include "AutomationRule.hpp"
#include "Controller.hpp"
#include "Device.hpp"
int main()
{
    std::cout << "====== Lab #2. Smart House ======\n";

    Device device{ "some device", 120.0 };

    Device* ptrdevice = new Device{ "other device", 50.0 };

    {
        Controller controller{ "some controller", 160.0 };

        controller.AddDevice(device);

        controller.AddDevice(*ptrdevice);
        
        controller.PrintAllDevices();
        
        controller.TurnOnDevice(device);
        
        controller.TurnOnDevice(*ptrdevice);
        
        controller.TurnOffDevice(device);
        
        controller.TurnOnDevice(*ptrdevice);
        
        controller.TurnOffDevice(*ptrdevice);
        
        controller.AddDevice(device);
        
        controller.RemoveDevice(device);
        
        controller.RemoveDevice(*ptrdevice);
        
        controller.TurnOnDevice(device);
        
        controller.PrintConfig();
    }

    Controller* ptrcontroller = new Controller{ "pointer controller", 100.0 };
    
    ptrcontroller->AddDevice(device);
    
    ptrcontroller->TurnOnDevice(device);
    
    ptrcontroller->TurnOffDevice(device);
    
    
    ptrcontroller->RemoveDevice(device);
    
    delete(ptrcontroller);
    
    delete(ptrdevice);
    
    ptrcontroller = nullptr;
    
    ptrdevice = nullptr;


    Controller** doubleptrcontroller = new Controller*[2];
    
    doubleptrcontroller[0] = new Controller{ "new controller", 100.0 };
    
    doubleptrcontroller[1] = new Controller{ "new controller 2", 200.0 };
    
    for (int i = 0; i < 2; ++i)
    {
        delete doubleptrcontroller[i]; 
    }
    
    delete[] doubleptrcontroller;
}