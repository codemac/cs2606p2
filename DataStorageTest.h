#ifndef DATASTORAGETEST_H_
#define DATASTORAGETEST_H_

/**
 * This class tests all of the public methods in the DataStorage class.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#include "DataStorage.h"
#include "DataHolder.h"
using namespace std;
#include <iostream>

class DataStorageTest :
	public CxxTest::TestSuite 
{
public:
    /**
     * This tests the default constructor.
     */
    void testDefaultConstructor()
    {
        DataStorage<DataHolder> store;
        TS_ASSERT_EQUALS(false, store.gotAnyNodes());
    }
    /**
     * This tests the add method.
     */
     void testAdd()
     {
     	DataStorage<DataHolder> store;
   		DataHolder* data = new DataHolder("jfdg", 5, 5);
     	store.add(data);
     	TS_ASSERT_EQUALS(true, store.gotAnyNodes());
     	delete store.getMeANode();
     	TS_ASSERT_EQUALS(false, store.gotAnyNodes());
     }
      /**
       * This tests the getMeANode method.
       */
       void testGetMeANode()
       {
       	DataStorage<DataHolder> store;
     	DataHolder* node = new DataHolder("lsdfsz", 5, 5);
     	DataHolder* node2 = new DataHolder("fsjdf", 3, 3);    	
     	store.add(node);
     	DataHolder* temp = store.getMeANode();
     	TS_ASSERT( temp == node );
     	delete temp;    	
     	store.add(node2);
		temp = store.getMeANode();
     	TS_ASSERT(temp == node2);
     	delete temp;
       }
      /**
      * This tests the gotAnyNodes method.
      */
      void testGotAnyNodes()
      {
      	DataStorage<DataHolder> store;
     	DataHolder* node = new DataHolder("fdsf", 4, 4); 
     	store.add(node);
     	TS_ASSERT_EQUALS(true, store.gotAnyNodes());
     	delete store.getMeANode();
     	TS_ASSERT_EQUALS(false, store.gotAnyNodes());
      }
};
#endif /*DATASTORAGETEST_H_*/
