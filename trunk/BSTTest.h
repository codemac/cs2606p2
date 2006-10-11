/**
 * This class tests all of the public methods in the BSTImplementation class.
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#ifndef BSTTEST_H_
#define BSTTEST_H_
#include "BST.h"
#include "DataHolder.h"
#include "Node.h"
using namespace std;
#include <ostream>
class BSTTest :
	public CxxTest::TestSuite 
{
public:
    /**
     * This tests the default constructor.
     */
    void testDefaultConstructor()
    {
        BST<DataHolder> bst;
        TS_ASSERT_EQUALS(0, bst.size());
    }
    /**
     * This tests the add method.
     */
     void testAdd()
     {
     	BST<DataHolder> bst;
    	bst.add(new DataHolder("a", 3, 3));
    	TS_ASSERT_EQUALS(1, bst.size());
    	bst.add(new DataHolder("b", 23, 3));
    	TS_ASSERT_EQUALS(2, bst.size());
    	bst.add(new DataHolder("c", 3, 31));
    	bst.add(new DataHolder("d", 13, 3));
    	TS_ASSERT_EQUALS(4, bst.size());
    	delete bst.removeByName("a");
    	delete bst.removeByName("b");
    	delete bst.removeByName("c");
    	delete bst.removeByName("d");   	
     }
     /**
      * This tests the display method.
      */
      void testDisplay()
      {
      	BST<DataHolder> bst;
      	
     	bst.add(new DataHolder("one", 12, 3));
     	bst.add(new DataHolder("two", 11, 3));
     	bst.add(new DataHolder("three", 10, 3));
     	bst.add(new DataHolder("four", 9, 3));
     	bst.add(new DataHolder("five", 8, 3));
     	bst.add(new DataHolder("six", 7, 3));
     	bst.add(new DataHolder("seven", 6, 3));
     	bst.add(new DataHolder("eight", 5, 3));
     	bst.display(cout);
     	delete bst.removeByName("two");
     	delete bst.removeByName("three");
     	delete bst.removeByName("four");
     	delete bst.removeByName("five");
     	delete bst.removeByName("six");
     	delete bst.removeByName("seven");
     	delete bst.removeByName("eight");
     	delete bst.removeByName("one");
      }    
      /**
       * This tests the remove method.
       */
       void testRemove()
       {
       		BST<DataHolder> bst;
     		bst.add(new DataHolder("f", 2, 2));
     		TS_ASSERT_EQUALS(1, bst.size());
     		delete bst.removeByName("f");
     		TS_ASSERT_EQUALS(0, bst.size());
     		bst.add(new DataHolder("fsdfz", 2, 2));
     		bst.add(new DataHolder("fsdfkkkkkkkkkka", 23, 22));
     		TS_ASSERT_EQUALS(2, bst.size());
     		delete bst.removeByName("fsdfz");
     		TS_ASSERT_EQUALS(1, bst.size());
     		delete bst.removeByName("fsdfkkkkkkkkkka");
    		TS_ASSERT_EQUALS(0, bst.size());
     		bst.removeByName("scv");
     		TS_ASSERT_EQUALS(0, bst.size());
 			
     	 }
       /**
        * This tests the size method.
        */
        void testSize()
        {
        	BST<DataHolder> bst;
     		bst.add(new DataHolder("a", 2, 2));
     		TS_ASSERT_EQUALS(1, bst.size());
     		bst.add(new DataHolder("b", 22, 2));
     		TS_ASSERT_EQUALS(2, bst.size());
     		bst.add(new DataHolder("c", 28, 2));
     		TS_ASSERT_EQUALS(3, bst.size());
     		bst.add(new DataHolder("d", 2, 23));
     		TS_ASSERT_EQUALS(4, bst.size());
     		bst.add(new DataHolder("e", 2, 2));
     		TS_ASSERT_EQUALS(5, bst.size());
     		delete bst.removeByName("a");
    		delete bst.removeByName("b");
    		delete bst.removeByName("c");
     		delete bst.removeByName("d");
     		delete bst.removeByName("e");     		
        }
        /**
         * This tests the clear method.
         */
         void testClear()
         {
         	BST<DataHolder> bst;
         	DataHolder *data = new DataHolder("dsf", 3, 3);
         	DataHolder *dataa = new DataHolder("dsf", 2, 3);
     		bst.add(data);
     		bst.add(dataa);
     		bst.clear();
     		TS_ASSERT_EQUALS(0, bst.size());
     		delete data;
     		delete dataa;
         }     	
};
#endif /*BSTTEST_H_*/
