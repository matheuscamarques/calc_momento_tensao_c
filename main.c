#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// POINTS OPERATIOS
typedef struct Point3D{
    double x;
    double y;
    double z;
} Point3D;


Point3D make_point_3d(double x, double y, double z){
    Point3D p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

// VECTOR OPERATIOS
typedef struct Vector3D{
    double x;
    double y;
    double z;
} Vector3D;

Vector3D make_vector_3d(Point3D p1, Point3D p2){
    Vector3D v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    v.z = p2.z - p1.z;
    return v;
}


double calc_vector_module(Vector3D v){
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

Vector3D calc_vectorial_product(Vector3D v1, Vector3D v2){
    Vector3D v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return v;
}

Vector3D calc_scalar_product(double scalar, Vector3D v){
    Vector3D u;
    u.x = scalar * v.x;
    u.y = scalar * v.y;
    u.z = scalar * v.z;
    return u;
}

// Momento = r x F OPERATIONS
Vector3D calc_momento(double tensao, Point3D pO, Point3D pA , Point3D pB){
    Vector3D vCA = make_vector_3d(pB, pA);
    double mod_vCA = calc_vector_module(vCA);
    Vector3D tensao_CA = calc_scalar_product(tensao/mod_vCA, vCA) ;
    // printf("Tensao CA(%2.f, %2.f, %2.f) \n", tensao_CA.x, tensao_CA.y, tensao_CA.z);
    Vector3D vOC = make_vector_3d(pO, pB);
    Vector3D momento_OC = calc_vectorial_product(vOC,tensao_CA);
    return momento_OC;
}

int main(int argc, char const *argv[])
{

    double pOx = 0,  
    pOy = 0,
    pOz = 0,

    pAx = 0,
    pAy = 0,
    pAz = 0,

    pCx = 0,
    pCy = 0,
    pCz = 0;

    double tensao = 1065;

    printf("Digite as coordenadas do ponto O: x y z\n");
    scanf("%lf %lf %lf", &pOx, &pOy, &pOz);
    
    printf("Digite as coordenadas do ponto A: x y z\n");
    scanf("%lf %lf %lf", &pAx, &pAy, &pAz);
    
    printf("Digite as coordenadas do ponto C: x y z\n");
    scanf("%lf %lf %lf", &pCx, &pCy, &pCz);

    printf("Tensão no cabo: ");
    scanf("%lf", &tensao);
    // ORIGEM
    
    Point3D pO = make_point_3d(pOx, pOy, pOz);
    Point3D pA = make_point_3d(pAx, pAy, pAz);
    Point3D pC = make_point_3d(pCx, pCy, pCz);
    
    Vector3D momento_OC = calc_momento(tensao, pO, pA, pC);
    printf("Momento OC(%2.f, %2.f, %2.f) \n", momento_OC.x, momento_OC.y, momento_OC.z);
    /* code */
    return 0;
}





