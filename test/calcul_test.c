/*
int main()
{
    t_vector v1;
    t_vector v2;
    t_vector v3;
    t_vector v4;
    t_vector v5;
    t_vector v6;
    t_vector v7;
    t_matrix matrix;
    float   res;
    
    v1.x = 2;
    v1.y = 2;
    v1.z = 2;
    v2.x = 0.6;
    v2.y = 0.6;
    v2.z = 0.6;
    
    v6.x = 0;
    v6.y = 0;
    v6.z = 0;
    v7.x = 0;
    v7.y = 0;
    v7.z = -1;
    printf("add : [%f, %f, %f]\n", add_vector(v1 , v2).x, add_vector(v1 , v2).y, add_vector(v1 , v2).z);

    eq_vector(&v3, sub_vector(v1 , v2));
    printf("eq : [%f, %f, %f]\n", v3.x, v3.y, v3.z);

    eq_vector(&v4, cross_product(v1 , v2));
    res = scalaire_product(v4, v1);
    printf("eq : [%f, %f, %f]\nres : %f\n", v4.x, v4.y, v4.z, res);
    eq_vector(&v5, normalize(v4));
    printf("NORMALISATION\nnorm v4 = [%f]\nv4 normalise : [%f, %f, %f]\n norm v4 [%f]\n", norme(v4), \
    v5.x, v5.y, v5.z, norme(v5));

    matrix = get_transfo_matrix(v1, v2);
    printf("matrix : \nR[%f,%f,%f]\nUp[%f,%f,%f]\nf[%f,%f,%f]\ncam[%f,%f,%f]\n\n\n", \
    matrix.right.x,matrix.right.y,matrix.right.z,matrix.up.x,matrix.up.y,matrix.up.z,matrix.forward.x,matrix.forward.y,matrix.forward.z,matrix.cam.x,matrix.cam.y,matrix.cam.z);
    
    //eq_vector(&v4, vector_x_matrix(v6, matrix, 1));
    eq_vector(&v5, vector_x_matrix(v7, matrix, 0));
    eq_vector(&v3, normalize(v2));
    printf("cam_orig : [%f, %f, %f]\ncam_dir : [%f,%f,%f]\n", v4.x, v4.y,v4.z, v5.x, v5.y, v5.z);
}*/