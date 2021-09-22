#include <iostream>
#include <cmath>

using namespace std;

int areaOfTriangle(int b, int h) {
    return (b*h)/2.0f;
}

int sumOfN(int n) {
    return n*(n+1)/2.0f;
}

float findTheRoot(int a, int b, int c) {
    return (-b+sqrt(b*b-4*a*c))/(2.0f*a);
}

int calculateDistance(int u, int v, int a) {
    return (v*v-u*u)/(2*a);
}

int simpleInterest(int P, int T, int R) {
    return P*R*T/100.0f;
}

int volumeOfCilinder(int radius, int height) {
    return 3.1425f * radius * radius * height;
}

float distanceBetweenPoints(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

float areaOfCircle(int radius) {
    return 3.1425*radius*radius;
}

int main(int argc, char** argv) {

    cout << "C++ Expressions" << endl;

    // Area of Triangle
    cout << "Area of triangle b=7, h=5: " << areaOfTriangle(7,5) << endl;

    // Sum of First n Natural Number
    cout << "Sum of n=20: " << sumOfN(20) << endl;

    // Finding roots of a Quadratic Equation a*x^2+b*x+c=0
    cout << "Root of quadratic equation a=3, b=2, c=1: " << findTheRoot(3,2,1) << endl;

    // Calculate Distance
    cout << "Distance for init velocity 10, final velocity 20 and acceleration 1: " << calculateDistance(10, 20, 1) << endl;

    // Calculate Simple Interest
    cout << "Simple interest for principle amount 10, time 5, rate of interest 15:" << simpleInterest(10, 5, 15) << endl;

    // Volume of cylinder
    cout << "Volume of cylinder with radius 10 and height 20:" << volumeOfCilinder(10, 20) << endl;

    //Distance between two points
    cout << "Distance between points A(3,5) and B(7,8): " << distanceBetweenPoints(3,5,7,8) << endl;

    // Area of Circle
    cout << "Area of circle with radius 15: " << areaOfCircle(15) << endl;

    return 0;
}
