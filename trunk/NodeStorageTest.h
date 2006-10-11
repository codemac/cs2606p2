#ifndef NODESTORAGETEST_H_
#define NODESTORAGETEST_H_

/**
 * This class tests all of the public methods in the NodeStorage class.
 * 
 * @author jmkline2, buzzfett
 * @version 9.10.06
 */
#include "NodeStorage.h"
using namespace std;
#include <iostream>

class NodeStorageTest :
	public CxxTest::TestSuite 
{
public:
    /**
     * This tests the default constructor.
     */
    void testDefaultConstructor()
    {
        NodeStorage<int> store;
        TS_ASSERT_EQUALS(false, store.gotAnyNodes());
    }
    /**
     * This tests the add method.
     */
     void testAdd()
     {
     	NodeStorage<int> store;
     	Node<int>* node = new Node<int>(); 
     	store.add(node);
     	TS_ASSERT_EQUALS(true, store.gotAnyNodes());
     	delete store.getMeANode();
     	TS_ASSERT_EQUALS(false, store.gotAnyNodes());
     }    
      /**
       * This tests the getMeANode method.
       */
       void testGetMeANode()
       {
       	NodeStorage<int> store;
     	Node<int>* node = new Node<int>(); 
     	Node<int>* node2 = new Node<int>();;
     	store.add(node);
     	Node<int>* temp = store.getMeANode();
     	TS_ASSERT(temp != NULL);
     	delete temp;
     	store.add(node2);
     	temp = store.getMeANode();
     	TS_ASSERT(temp != NULL);
     	delete temp;
       }       
      /**
      * This tests the gotAnyNodes method.
      */
      void testGotAnyNodes()
      {
      	NodeStorage<int> store;
     	Node<int>* node = new Node<int>();; 
     	store.add(node);
     	TS_ASSERT_EQUALS(true, store.gotAnyNodes());
     	delete store.getMeANode();
     	TS_ASSERT_EQUALS(false, store.gotAnyNodes());
      }      
};
#endif /*NODESTORAGETEST_H_*/
