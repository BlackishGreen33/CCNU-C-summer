#include<stdio.h>
#include<math.h>
#define PI 3.14
int main(){
    double r, h, s_cylinder, s_cone, v_cylinder, v_cone;
    printf("Enter the radius and height of the cylinder: ");
    scanf("%lf %lf", &r, &h);
    s_cylinder = 2 * PI * r * h + 2 * PI * r * r;
    v_cylinder = PI * r * r * h;
    s_cone = PI * r * sqrt(r * r + h * h) + PI * r * r;
    v_cone = 1.0 / 3 * PI * r * r * h;
    printf("The surface area of the cylinder is %.2lf\n", s_cylinder);
    printf("The volume of the cylinder is %.2lf\n", v_cylinder);
    printf("The surface area of the cone is %.2lf\n", s_cone);
    printf("The volume of the cone is %.2lf", v_cone);
    return 0;
}
