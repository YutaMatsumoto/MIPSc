


int main()
{

	int test = 0;

	int arr[ 6 ];

	arr[ 0 ] = 5;

	arr[ 1 ] = 2;

	arr[ 2 ] = 6;

	arr[ 3 ] = 7;

	arr[ 4 ] = 1;

	arr[ 5 ] = 1;
	
	int j;

	int k;

	while( test == 0 )
	{
		test = 0;

		for( j = 0 ; j < 5 ; j = j + 1 )
		{
		
			if( arr[ j ] > arr[ j + 1 ] )
			{
			
				k = arr[ j ];

				arr[ j ] = arr[ j + 1 ];

				arr[ j + 1 ] = k;

				test = 1;

			}
		
		}
	}

	int done = 0;

	return 0;

}
