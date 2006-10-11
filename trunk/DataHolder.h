/**
 * This class holds the data that we are given.  For this project, the data consists
 * of a  a string and a coordinate pair.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef DATAHOLDER_H_
#define DATAHOLDER_H_
class DataHolder
{
	public:
		/**
		 * Our comparator class.
		 */
		class DataComparator
		{
			public:
			/**
			 * true if coordinates are equal.
			 */
			static bool equals(DataHolder* left, DataHolder* right)
			{
				return ((left->x == right->x) && (left->y == right->y));
			}
			/**
			 * true if left is >= to the right.
			 */
			static bool gte(DataHolder* left, DataHolder* right, int key)
			{
				if ( key == 0 )
				{
					return left->x >= right->x;
				}
				else return left->y >= right->y;
			}
			/**
			 * true if x or y is >= to the right.
			 */
			static bool gte(int x, int y, DataHolder* right, int key)
			{
				if ( key == 0 )
				{
					return x >= right->x;
				}
				else return y >= right->y;
			}
			/**
			 * true if x or y is <= to the right.
			 */
			static bool lte(int x, int y, DataHolder* right, int key)
			{
				if ( key == 0 )
				{
					return x <= right->x;
				}
				else return y <= right->y;
			}
			/**
			 * true if left is < right.
			 */
			static bool lt(DataHolder* left, DataHolder* right, int key)
			{
				if ( key == 0 )
				{
					return left->x < right->x;
				}
				else return left->y < right->y;
			}
		};
		//These are the public variables.
		string name; //name of the city
		int x,y; //x,y coords
		DataHolder* next; //pointer to the next DataHolder object
// -------------------------------------------------------------------------
	/**
	 * Default constructor.
	 */
	DataHolder::DataHolder()
	{
		name = "";
		x = 0;
		y = 0;	
		next = NULL;
	} 
/**
 * This constructor creates a dataholder object with the given city name
 * and coordinates.
 */
	DataHolder::DataHolder(string city, int xcoord, int ycoord)
	{
		name = city;
		x = xcoord;
		y = ycoord;
		next = NULL;
	}
	/**
	 * Deconstructor.
	 */
	DataHolder::~DataHolder()
	{
	}
};
#endif /*DATAHOLDER_H_*/
