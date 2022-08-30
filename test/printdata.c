/*void	print_data(t_data *data)
{
	t_Objects *temp;

	printf("lumA->ratio : %f | lumA->color->[x, y, z] = [%f, %f, %f]\n", \
	data->lumA->ratio, data->lumA->color.x, data->lumA->color.y, data->lumA->color.z);	
	
	printf("Lum->ratio : %f | Lum->color->[x, y, z] = [%f, %f, %f] | Lum->pos->[x, y, z] = [%f, %f, %f]\n", \
	data->lum->ratio, data->lum->color.x, data->lum->color.y, data->lum->color.z, data->lum->pos.x, data->lum->pos.y, data->lum->pos.z);
	
	printf("cam->fov : %d | cam->dir->[x, y, z] = [%f, %f, %f] | cam->pos->[x, y, z] = [%f, %f, %f]\n", \
	data->cam->fov, data->cam->dir.x, data->cam->dir.y, data->cam->dir.z, data->cam->pos.x, data->cam->pos.y, data->cam->pos.z);
	
	if (data->objects)
	{
		printf("Object : \n");
		temp = data->objects;
		while(temp)
		{
			printf("\tid = %d\n", temp->id);
			if (temp->id == SP)
			{
				printf("\tcenter = [%f, %f, %f] | color = [%f, %f, %f] | radius = %f\n",\
				((t_Sphere *)temp->object)->center.x, ((t_Sphere *)temp->object)->center.y, ((t_Sphere *)temp->object)->center.z, \
				((t_Sphere *)temp->object)->color.x, ((t_Sphere *)temp->object)->color.y, ((t_Sphere *)temp->object)->color.z, \
				((t_Sphere *)temp->object)->radius);
			}
			temp = temp->next;
		}
	}
}*/