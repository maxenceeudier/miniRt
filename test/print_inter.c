/*int main ()
{
	t_Sphere sp;
	t_vector dir_pix;
	t_vector cam_o;
	t_vector phit;

	sp.center.x = 4;
	sp.center.y = 4;
	sp.center.z = 0;
	sp.radius = 1;

	dir_pix.x = 1;
	dir_pix.y = 1.43785;
	dir_pix.z = 0;

	cam_o.x = 0;
	cam_o.y = 0;
	cam_o.z = 0;

	float inter = inter_sphere(normalize(dir_pix), cam_o, sp, &phit);

	printf("impact: %f\n", inter);
	if (inter)
		printf ("phit: [%f, %f, %f]\n", phit.x, phit.y, phit.z);

}
*/
