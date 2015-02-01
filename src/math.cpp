#include "math.h"
#include <math.h>

#define DEG2RAD 0.0174532925
#define RAD2DEG 57.2957795
#define RN Renderer::Instance()


double Log2(double x) {
    return log(x) / log(2.0);
}

double DegSin(double degrees) {
    return sin(DEG2RAD * degrees);
}

double DegCos(double degrees) {
    return cos(DEG2RAD * degrees);
}

double DegTan(double degrees) {
    return tan(DEG2RAD * degrees);
}

double DegASin(double sin) {
    return asin(sin) * RAD2DEG;
}

double DegACos(double cos) {
    return acos(cos) * RAD2DEG;
}

double DegATan(double tan) {
    return atan(tan) * RAD2DEG;
}

double DegATan2(double y, double x) {
    return atan2(y, x) * RAD2DEG;
}

double WrapValue(double val, double mod) {
    if (mod == 0) return val;
    return val - mod*floor(val / mod);
}


double Angle(double x1, double y1, double x2, double y2) {
    /*
    Utilizaremos la función arcotangente (tenemos una versión en este módulo
    llamada D e g A T a n 2 que utiliza grados sexagesimales en lugar de radianes) para
    devolver el ángulo entre los dos puntos pasados como parámetro. Debemos utilizar la
    función W r a p V a l u e de este mismo módulo para encapsular el resultado en un valor en
    el rango [0, 360) (esta función es similar al operador % (módulo) de C o a la función
    m o d f , pero utiliza valores reales, y asegura que el resultado devuelto sea siempre
    positivo).
    */
    //alto es y2
    //Vuelvo el punto a mi origen de coordenadas
    double t_xp = x2 - x1;
    double t_yp = y1 - y2;
    double t_angle = DegATan2(t_yp, t_xp);
    t_angle = WrapValue(t_angle, 360);
    //t_angle *= RAD2DEG;

    return t_angle;
}

double Distance(double x1, double y1, double x2, double y2) {
    // TAREA: Implementar funcion
    double t_xp = x2 - x1;
    double t_yp = y2 - y1;
    double distancia = sqrt(pow(t_xp, 2) + pow(t_yp, 2));
    return distancia;
}

double Hipotenuse(double x1, double y1)
{
    return sqrt(pow(x1, 2) + pow(y1, 2));
}

bool ValueInRange(double value, double min, double max) {
    return (value >= min) && (value <= max);
}

bool PointInRect(double x, double y, double rectx, double recty, double width, double height) {
    // TAREA: Implementar funcion
    return false;
}

void ClosestPointToRect(double x, double y, double rectx, double recty, double width, double height, double* outx, double* outy) {
    *outx = (x < rectx) ? rectx : (x > rectx + width) ? rectx + width : x;
    *outy = (y < recty) ? recty : (y > recty + height) ? recty + height : y;
}

bool RectsOverlap(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2) {
    // TAREA: Implementar funcion
    return false;
}

void OverlappingRect(double x1, double y1, double width1, double height1, double x2, double y2, double width2, double height2, double* outx, double* outy, double* outwidth, double* outheight) {
    // TAREA: Implementar funcion
}

void TransformIsoCoords(double isoX, double isoY, double isoZ, double* screenX, double* screenY) {
    // TAREA: Implementar funcion
}
