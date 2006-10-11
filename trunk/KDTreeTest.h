/**
 * This class tests all of the public methods in the BSTImplementation class.
 * @author jmkline2
 * @version 3-28-06
 */
#ifndef KDTreeTEST_H_
#define KDTreeTEST_H_
#include "KDTree.h"
#include "DataHolder.h"
#include "Node.h"
using namespace std;
#include <ostream>

class KDTreeTest :
	public CxxTest::TestSuite 
{
public:
    /**
     * This tests the default constructor.
     */
    void testDefaultConstructor()
    {
        KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
        TS_ASSERT_EQUALS(0, kdt.size());
    }
    
    /**
     * This tests the add method.
     */
     void testAdd()
     {
     	DataHolder *d1 = new DataHolder("fdsf", 3, 3);
     	DataHolder *d2 = new DataHolder("right", 23, 3);
     	DataHolder *d3 = new DataHolder("rightright", 3, 31);
     	DataHolder *d4 = new DataHolder("rightrightright", 13, 3);
     	DataHolder *d5 = new DataHolder("left", 2, 3);
     	DataHolder *d6 = new DataHolder("leftleft", 2, 1);
     	DataHolder *d7 = new DataHolder("leftright", 1, 5);
     	KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
    	kdt.add(d1);
    	TS_ASSERT_EQUALS(1, kdt.size());
    	kdt.add(d2);
    	TS_ASSERT_EQUALS(2, kdt.size());
    	kdt.add(d3);
    	kdt.add(d4);
    	TS_ASSERT_EQUALS(4, kdt.size());
    	kdt.add(d5);
    	TS_ASSERT_EQUALS(5, kdt.size());
    	kdt.add(d6);
    	TS_ASSERT_EQUALS(6, kdt.size());
    	kdt.add(d7);
    	TS_ASSERT_EQUALS(7, kdt.size());
    	//kdt.display(std::cout);
    	delete kdt.removeByCoords(d1);
    	delete kdt.removeByCoords(d2);
    	delete kdt.removeByCoords(d3);
    	delete kdt.removeByCoords(d4);
    	delete kdt.removeByCoords(d5);
    	delete kdt.removeByCoords(d6);
    	delete kdt.removeByCoords(d7);
    	
     }
     /**
      * This tests the remove method.  It is a small test since we switched the
      * numbers within our same test to try out different situations.
      */
     void testRemove()
     {
     	KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
     	DataHolder *d1 = new DataHolder("root", 3, 3);
     	DataHolder *d2 = new DataHolder("right", 5, 3);
     	DataHolder *d3 = new DataHolder("rightright", 3, 5);
     	DataHolder *d4 = new DataHolder("rightrightright", 13, 5);
     	DataHolder *d5 = new DataHolder("rightrightrightright", 5, 7);
     	DataHolder *d6 = new DataHolder("left", 2, 3);
     	DataHolder *d7 = new DataHolder("leftleft", 2, 1);
     	DataHolder *d8 = new DataHolder("leftright", 1, 5);
    	kdt.add(d1);
    	kdt.add(d2);
    	kdt.add(d3);
    	kdt.add(d4);
    	kdt.add(d5);
    	kdt.add(d6);
    	kdt.add(d7);
    	kdt.add(d8);
    	TS_ASSERT_EQUALS(8, kdt.size());
    	kdt.display(std::cout);
    	delete kdt.removeByCoords(d1);
    	TS_ASSERT_EQUALS(7, kdt.size());
    	kdt.display(std::cout);
    	delete kdt.removeByCoords(d2);
    	delete kdt.removeByCoords(d3);
    	delete kdt.removeByCoords(d4);
    	delete kdt.removeByCoords(d5);
    	delete kdt.removeByCoords(d6);
    	delete kdt.removeByCoords(d7);
    	delete kdt.removeByCoords(d8);
     }
     
    /**
     * This tests find parent. it is a private method, so once we tested to make
     * sure it ran properly, the test was commented out.
     *
     void testFindParent()
     {
     	KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
    	DataHolder* dr = new DataHolder("right", 23, 3);
    	DataHolder* droot = new DataHolder("fdsf", 3, 3);
    	DataHolder* drr = new DataHolder("rightright", 3, 31);
    	DataHolder* drrr = new DataHolder("rightrightright", 13, 3);
    	DataHolder* dl = new DataHolder("left", 2, 3);
    	DataHolder* dll = new DataHolder("leftleft", 2, 1);
    	DataHolder* dlr = new DataHolder("leftright", 1, 5);
    	
    	Node<DataHolder>* rrr = new Node<DataHolder>(drrr, NULL, NULL);
    	Node<DataHolder>* rr = new Node<DataHolder>(drr, rrr, NULL);
    	Node<DataHolder>* ll = new Node<DataHolder>(dll, NULL, NULL );
    	Node<DataHolder>* lr = new Node<DataHolder>(dlr, NULL, NULL);
    	Node<DataHolder>* l = new Node<DataHolder>(dl, lr, ll );
    	Node<DataHolder>* r = new Node<DataHolder>(dr, rr, NULL);
    	Node<DataHolder>* root = new Node<DataHolder>(droot, r, l);
    	TS_ASSERT_EQUALS(rr, kdt.findParent(root, rrr));
    	TS_ASSERT_EQUALS(r, kdt.findParent(root, rr));
    	TS_ASSERT(!kdt.findParent(root, root));
    	TS_ASSERT_EQUALS(l, kdt.findParent(root, ll));
    	TS_ASSERT_EQUALS(l, kdt.findParent(root, lr));
    	TS_ASSERT_EQUALS(root, kdt.findParent(root, l));
    	TS_ASSERT_EQUALS(root, kdt.findParent(root, r));
    	//kdt.display(std::cout);
     }*/   
      /**
       * This tests find level. it is a private method, so once we tested to make
       * sure it ran properly, the test was commented out.
       *
      void testFindLevel()
      {
			KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
			kdt.add(new DataHolder("fdsf", 3, 3));
			TS_ASSERT_EQUALS(0, kdt.findLevel(kdt.root, kdt.root, 0));
			kdt.add(new DataHolder("right", 23, 3));
			TS_ASSERT_EQUALS(1, kdt.findLevel(kdt.root, kdt.root->right, 0));
			kdt.add(new DataHolder("rightright", 3, 31));
			TS_ASSERT_EQUALS(2, kdt.findLevel(kdt.root, kdt.root->right->right, 0));
			kdt.add(new DataHolder("rightrightright", 13, 3));
			TS_ASSERT_EQUALS(3, kdt.findLevel(kdt.root, kdt.root->right->right->right, 0));
			kdt.add(new DataHolder("left", 2, 3));
			TS_ASSERT_EQUALS(1, kdt.findLevel(kdt.root, kdt.root->left, 0));
			kdt.add(new DataHolder("leftleft", 2, 1));
			TS_ASSERT_EQUALS(2, kdt.findLevel(kdt.root, kdt.root->left->left, 0));
			kdt.add(new DataHolder("leftright", 1, 5));
			TS_ASSERT_EQUALS(2, kdt.findLevel(kdt.root, kdt.root->left->right, 0));
			//kdt.display(std::cout);
      }*/
      
      /**
       * This tests the remove method.
       */
       void testDisplay()
       {
	     	KDTree<DataHolder, DataHolder::DataComparator> kdt(2);
	     	DataHolder* d1 = new DataHolder("fdsf", 3, 3);
	     	DataHolder* d2 = new DataHolder("right", 23, 3);
	     	DataHolder* d3 = new DataHolder("rightright", 3, 31);
	     	DataHolder* d4 = new DataHolder("rightrightright", 13, 3);
	     	DataHolder* d5 = new DataHolder("left", 2, 3);
	     	DataHolder* d6 = new DataHolder("leftleft", 2, 1);
	     	DataHolder* d7 = new DataHolder("leftright", 1, 5);
	    	kdt.add(d1);
	    	TS_ASSERT_EQUALS(1, kdt.size());
	    	kdt.add(d2);
	    	TS_ASSERT_EQUALS(2, kdt.size());
	    	kdt.add(d3);
	    	kdt.add(d4);
	    	TS_ASSERT_EQUALS(4, kdt.size());
	    	kdt.add(d5);
	    	TS_ASSERT_EQUALS(5, kdt.size());
	    	kdt.add(d6);
	    	TS_ASSERT_EQUALS(6, kdt.size());
	    	kdt.add(d7);
	    	TS_ASSERT_EQUALS(7, kdt.size());
	    	kdt.display(std::cout);    
	    	delete kdt.removeByCoords(d1);
	    	delete kdt.removeByCoords(d2);
	    	delete kdt.removeByCoords(d7);
	    	delete kdt.removeByCoords(d3);
	    	delete kdt.removeByCoords(d4);
	    	delete kdt.removeByCoords(d5);
	    	delete kdt.removeByCoords(d6);
       }
       
   
};
#endif /*BSTTEST_H_*/
