#include <iostream>
#include "matplotlibcpp.h"
#include <cmath>
namespace plt = matplotlibcpp;


int main(){
const double pi = 3.14159265359;
double r1 = 1.0;
double r2 = 1.0;
double m1 = 190000000000.0;
double m2 = 10.0;
double distance = 10.0;
int points = 100;
int a = -10;
int b = 10;
double x1 = distance;
double x2 = -distance;
double y1 = 0.0;
double y2 = 0.0;
double G = 0.00000000006673;
double col_threshold = 2.0;
std::vector<double> x, y; // for body 1
std::vector<double> u, v; // for body 2


// Calculating distance
double dx = x2 - x1;
double dy = y2 - y1;

// Calculating Force
double r_square = sqrt((dx*dx)+(dy*dy));
double F = ((G*m1*m2)/r_square);

// Angle (theta) between m1 and m2
double theta; 

    if (dy == 0.0) {
        if (dx >= 0.0) {
            theta = 0.0;  // Horizontal alignment to the right
        } else {
            theta = 180.0;  // Horizontal alignment to the left
        }
    } else {
        theta = std::atan2(dy, dx);
    }

    
// Horizontal and Vertical components of F
 double F_x = F*cos(theta);
 double F_y = F*sin(theta);


 // Horizontal and Vertical compoments of acceleration
 double a_x1 = F_x/m1;
 double a_x2 = -F_x/m2;
 double a_y1 = F_y/m1;
 double a_y2 = -F_y/m2;

// velocity calculations

double initial_vel_x1 = -1.0;
double initial_vel_x2 = 1.0;
double initial_vel_y1 = -1.0;
double initial_vel_y2 = 1.0;  
//* Attempting a loop for the sim
double total_steps = 1000.0;
double step_size = 1;
for (double i = 0.0; i<total_steps;i+= step_size){
    // Clear the vectors for fresh plot
    

    double final_vel_x1 = initial_vel_x1 + (a_x1*step_size);
    double final_vel_x2 = initial_vel_x2 + (a_x2*step_size);
    double final_vel_y1 = initial_vel_y1 + (a_y1*step_size);
    double final_vel_y2 = initial_vel_y2 + (a_y2*step_size);
    
    //Position change
    x1 = x1 + (final_vel_x1*step_size) - (0.5*a_x1*(step_size*step_size));
    x2 = x2 + (final_vel_x2*step_size) - (0.5*a_x2*(step_size*step_size)); 
    y1 = y1 + (final_vel_y1*step_size) - (0.5*a_y1*(step_size*step_size));
    y2 = y2 + (final_vel_y2*step_size) - (0.5*a_y2*(step_size*step_size));
    

    //Update distance
    dx = x2 - x1;
    dy = y2 - y1;
    
     
    // std::cout << abs(dx) << "\n";
    if (std::sqrt(dx * dx + dy * dy) < r1+r2) {
    std::cout << "Collision detected. Aborting.\n";
    return 0;
}
    
    // Updating Force
    r_square = sqrt((dx*dx)+(dy*dy));
    F = ((G*m1*m2)/r_square);
    
    // Updating angle (theta) between m1 and m2
     

        if (dy == 0.0) {
            if (dx >= 0.0) {
                theta = 0.0;  // Horizontal alignment to the right
            } else {
                theta = 180.0;  // Horizontal alignment to the left
            }
        } else {
            theta = std::atan2(dy,dx);
        }

    // Updating Horizontal and Vertical components of F
    F_x = F*cos(theta);
    F_y = F*sin(theta);

    // Updating Horizontal and Vertical compoments of acceleration
    a_x1 = F_x/m1;
    a_x2 = -F_x/m2;
    a_y1 = F_y/m1;
    a_y2 = -F_y/m2;

    std::cout<<"initial velocity x: " << initial_vel_x1 << " " << initial_vel_x2<<"\n";
    std::cout<<"initial velocity y: " << initial_vel_y1 << " " << initial_vel_y2<<"\n";
    std::cout<<"final velocity x: " << final_vel_x1 << " " << final_vel_x2<<"\n";
    std::cout<<"final velocity y: " << final_vel_y1 << " " << final_vel_y2<<"\n";
    std::cout<<"x1 x2 y1 y2: "<<x1<<" "<<x2<<" "<<y1<<" "<< y2<<"\n";
    std::cout<<"dx dy: "<< dx<<" " <<dy<<"\n";
    std::cout<<"Fx Fy: "<<F_x<<" "<<F_y<<"\n";
    std::cout<<"ax1 ax2 ay1 ay2: "<<a_x1<<" "<<a_x2<<" "<<a_y1<<" "<<a_y2<<"\n";
    std::cout<<"\n";
    // Updating initial velocity calculation for next round

    initial_vel_x1 = final_vel_x1;
    initial_vel_x2 = final_vel_x2;
    initial_vel_y1 = final_vel_y1;
    initial_vel_y2 = final_vel_y2; 

    x.push_back(x1);
    y.push_back(y1);
    u.push_back(x2);
    v.push_back(y2);
    
  
    plt::clf();
    //plt::xlim(-200,200);
    //plt::ylim(-200,200);
    plt::plot(x,y);
    plt::plot(u,v,"--");
   
    
    
    
    plt::pause(0.1);
    
    
   
}
  plt::show();

    return 0;
}