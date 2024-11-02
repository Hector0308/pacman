#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[]) {
    std::string reset_position;
    int frame = 0;
     int Cora_x = 250;  
     int Cora_y = 50;
      int direccion = -1;  
    int limite_izq = 233; 
    int limite_der = 280; 

    while (true) {
        int x = frame;
        int y = x * x;
        if (Cora_x <= limite_izq || Cora_x >= limite_der) {
            direccion *= -1;
        }
        Cora_x += direccion;

        auto can = Canvas(500, 200);
        can.DrawBlockCircle(190, 50, 30); 
        can.DrawBlockCircle(215, 25, 6); 
        can.DrawBlockCircle(165, 25, 6); 
        can.DrawPointCircle(180, 41, 1);  
        can.DrawBlockCircle(180, 41, 4);  
        can.DrawPointCircle(200, 41, 1);  
        can.DrawBlockCircle(200, 41, 4); 
        can.DrawPoint(180, 60, 1000);           
        can.DrawPoint(185, 65, 1000);           
        can.DrawPoint(192, 67, 1000);           
        can.DrawPoint(195, 65, 1000);           
        can.DrawPoint(200, 60, 1000); 


         can.DrawBlockCircle(320, 50, 25); 
         can.DrawBlockCircle(335, 35, 4); 
         can.DrawBlockCircle(305, 35, 4); 
         can.DrawBlockCircle(313, 51, 2); 
         can.DrawBlockCircle(328, 51, 2); 
        can.DrawBlockCircle(320, 60, 1); 


        can.DrawPoint(182, 60, 1000);           
        can.DrawPoint(187, 65, 1000);           
        can.DrawPoint(190, 67, 1000);           
        can.DrawPoint(197, 65, 1000);           
        can.DrawPoint(202, 60, 1000); 

         for (int i = 0; i < 100; ++i) {
            int rain_x = rand() % 500;  
            int rain_y = rand() % 200; 
            can.DrawPoint(rain_x, rain_y, 1000);
        }
        
        
        can.DrawPoint(Cora_x - 1, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x - 2, Cora_y - 2, 1000);
        can.DrawPoint(Cora_x - 3, Cora_y - 2, 1000);
        can.DrawPoint(Cora_x - 4, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x - 4, Cora_y, 1000);
        can.DrawPoint(Cora_x - 3, Cora_y + 1, 1000);
        can.DrawPoint(Cora_x - 2, Cora_y + 2, 1000);
       
         can.DrawPoint(Cora_x + 1, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x + 2, Cora_y - 2, 1000);
        can.DrawPoint(Cora_x + 3, Cora_y - 2, 1000);
        can.DrawPoint(Cora_x + 4, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x + 4, Cora_y, 1000);
        can.DrawPoint(Cora_x + 3, Cora_y + 1, 1000);
        can.DrawPoint(Cora_x + 2, Cora_y + 2, 1000);

      
        can.DrawPoint(Cora_x, Cora_y + 4, 1000);
        can.DrawPoint(Cora_x - 1, Cora_y + 3, 1000);
        can.DrawPoint(Cora_x + 1, Cora_y + 3, 1000);

   
        can.DrawPoint(Cora_x - 7, Cora_y, 1000);
        can.DrawPoint(Cora_x - 8, Cora_y + 1, 1000);
        can.DrawPoint(Cora_x - 9, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x - 10, Cora_y + 2, 1000);

  
        can.DrawPoint(Cora_x + 7, Cora_y, 1000);
        can.DrawPoint(Cora_x + 8, Cora_y + 1, 1000);
        can.DrawPoint(Cora_x + 9, Cora_y - 1, 1000);
        can.DrawPoint(Cora_x + 10, Cora_y + 2, 1000);

        
      


       
         



        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Green, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.050s);
        frame++;
    }

    return 0;
}
