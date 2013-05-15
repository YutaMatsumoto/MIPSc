


int main()
{
	
	int arr[ 6 ];
	
	int test = 0;
	
	int i;

	int j;
	
	!!S

	arr[ 0 ] = 5;

	arr[ 1 ] = 2;

	arr[ 2 ] = 6;

	arr[ 3 ] = 7;

	arr[ 4 ] = 1;

	arr[ 5 ] = 1;
	
	!!S

	while( test == 0 )
	{
		test = 1;

		for( j = 0 ; j < 5 ; j = j + 1 )
		{
			int k;
			
			k = arr[ j ];

			i = arr[ j + 1 ];		

			if( k < i )
			{
				
				int x;

				k = arr[ j ];

				arr[ j ] = arr[ j + 1 ];

				arr[ j + 1 ] = k;

				test = 0;

			}
		
		}
	}

	return 0;

}
