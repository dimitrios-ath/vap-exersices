#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct location
{
	char name[400];
	int max_distance;
};

struct town
{
	char name[400];
	int x;
	int y;
};

double square(float num)
{
	return num*num;
}

int main()
{
	int n;
	scanf("%d",&n);
	if (n>=2 && n<=1000)
	{
		struct town towns[n];
		for (int i=0; i<n; i++)
			scanf("%s %d %d",towns[i].name, &towns[i].x, &towns[i].y);

		struct location current_location;
		scanf("%s %d",current_location.name, &current_location.max_distance);

		int current_town_id;
		for (int i=0; i<n; i++)
			if (strcmp(current_location.name,towns[i].name)==0)
			{
				current_town_id=i;
				break;
			}

		double min_distance=current_location.max_distance;
		int shortest_path_town_a_id,shortest_path_town_b_id;
		double distances[n][n];

		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				double distance = sqrt(square(towns[j].x-towns[i].x)+square(towns[j].y-towns[i].y));
				distances[i][j] = distance;
				if (distance<min_distance && i!=j && i>j) // if (current_town_id==i && distance<min_distance && i!=j)
				{
					min_distance = distance;
					shortest_path_town_a_id = j;
					shortest_path_town_b_id = i;				}
			}
		}

		// Shortest path is 17.49 km between Thessaloniki and Xanthi
		printf("Shortest path is %.2f km between %s and %s\n", min_distance, towns[shortest_path_town_a_id].name, towns[shortest_path_town_b_id].name);
		for (int i=0; i<n; i++)
		{
			if (distances[current_town_id][i]!=0 && distances[current_town_id][i]<=current_location.max_distance)
			{
				printf("Feasible path of %.2f km to %s\n", distances[current_town_id][i], towns[i].name);
			}
			//	Feasible path of 17.49 km to Xanthi
		}

		/*
		for (int i=0; i<n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%f ", distances[i][j]);
			}
			printf("\n");
		}
		*/
	}
	return 0;
}

// 4 Thessaloniki 27 28 Athens 65 78 Patra 78 96 Xanthi 12 19 Thessaloniki 28