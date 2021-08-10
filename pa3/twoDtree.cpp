
/**
 *
 * twoDtree (pa3)
 * slight modification of a Kd tree of dimension 2.
 * twoDtree.cpp
 * This file will be used for grading.
 *
 */

#include "twoDtree.h"

// Node constructor, given.
twoDtree::Node::Node(pair<int,int> ul, pair<int,int> lr, RGBAPixel a)
	:upLeft(ul),lowRight(lr),avg(a),left(NULL),right(NULL)
	{}

// twoDtree destructor, given.
twoDtree::~twoDtree(){
	clear();
}

// twoDtree copy constructor, given.
twoDtree::twoDtree(const twoDtree & other) {
	copy(other);
}


// twoDtree assignment operator, given.
twoDtree & twoDtree::operator=(const twoDtree & rhs){
	if (this != &rhs) {
		clear();
		copy(rhs);
	}
	return *this;
}

twoDtree::twoDtree(PNG & imIn){ 

// YOUR CODE HERE

stats s(imIn);
height = imIn.height();
width = imIn.width();
pair<int, int> p1(0,0);
pair<int, int> p2(height-1, width-1);
//RGBAPixel a = s.getAvg(p1, p2);

root = buildTree(s, p1, p2, true);



}

twoDtree::Node * twoDtree::buildTree(stats & s, pair<int,int> ul, pair<int,int> lr, bool vert) {

// YOUR CODE HERE!!
if ((lr.first - ul.first <= 0) && (lr.second - ul.second <= 0)) {
	Node * retBase = new Node(ul, lr, s.getAvg(ul, lr));
	// retBase->left = NULL;
	// retBase->right = NULL;
	cout << "base case return" << "\n";
	
	return retBase;

} else {
	
	RGBAPixel a = s.getAvg(ul, lr);


	Node * retNode = new Node(ul, lr, a);
	pair<int, int> largerSplit;
	pair<int, int> smallSplit;

	if (vert) {

		if (lr.first - ul.first >= 1) {
			largerSplit = getVS(s, ul, lr);
			smallSplit = getOther(true, ul, largerSplit); //(largerSplit.first+1, ul.second);
		} else {

			pair<int, int> largerSplit = getHS(s, ul, lr);
			smallSplit = getOther(false, ul, largerSplit); //(ul.first, largerSplit.second+1);
		}
	
	} else {

		if (lr.second - ul.second >= 1) {
			pair<int, int> largerSplit = getHS(s, ul, lr);
			smallSplit = getOther(false, ul, largerSplit); //(ul.first, largerSplit.second+1);
		} else {
			largerSplit = getVS(s, ul, lr);
			smallSplit = getOther(true, ul, largerSplit); //(largerSplit.first+1, ul.second);
		}

}
	
vert = !vert;

retNode->left = buildTree(s, ul, largerSplit, vert);

retNode->right = buildTree(s, smallSplit, lr, vert);

return retNode;

}

}

pair<int, int> twoDtree::getVS(stats& s, pair<int, int> ul, pair<int, int> lr) {

	int z;
	int e = lr.second;
	int f = ul.second;
	pair<int, int> p(ul.first, e);
	pair<int, int> k(ul.first+1, f);

	long b = s.getScore(ul, p) + s.getScore(k, lr);
	z = ul.first;

	for (int i = ul.first+1; i < lr.first; i++) {
		pair<int, int> l(i, e);
		pair<int, int> m(i+1, f);
		long c = s.getScore(ul, l) + s.getScore(m, lr);
		if (c <= b) {
			b = c;
			z = i;
		}
	}

	pair<int, int> ret(z, e);
	return ret;

}

pair<int, int> twoDtree::getHS(stats& s, pair<int, int> ul, pair<int, int> lr) {

	int z;
	int e = lr.first;
	int f = ul.first;
	pair<int, int> p(e, ul.second);
	pair<int, int> k(f, ul.second+1);
	long b = s.getScore(ul, p) + s.getScore(k, lr);
	z = ul.second;
	
	for (int i = ul.second+1; i < lr.second; i++) {
		pair<int, int> l(e, i);
		pair<int, int> m(f, i+1);
		long c = s.getScore(ul, l) + s.getScore(m, lr);
		if (c <= b) {
			b = c;
			z = i;
		}
	}
	

	pair<int, int> ret(e, z);
	return ret;

}

pair<int, int> twoDtree::getOther(bool vert, pair<int, int> ul, pair<int, int> lr) {

	if (vert) {
		pair<int, int> vertO(lr.first+1, ul.second);
		return vertO;
	} else {
		pair<int, int> horO(ul.first, lr.second+1);
		return horO;
	}
}

PNG twoDtree::render(){

// YOUR CODE HERE!!
PNG image(height, width);
render(image, root);
return image;

}

void twoDtree::render(PNG& edit, Node* subroot) {

	
	

	// if (subroot->left == NULL && subroot->right == NULL) {

	// 	RGBAPixel a = subroot->avg;

	// 	pair<int, int> ul = subroot->upLeft;
	// 	pair<int, int> lr = subroot->lowRight;
	
	// 	for (int i = ul.first; i <=lr.first; i++) {
	// 		for (int j = ul.second; j <= lr.second; j++) {
	// 			//RGBAPixel * change  = edit.getPixel(i,j);
	// 			*edit.getPixel(i,j) = a;
	// 		}
	// 	} 

	// } else if (subroot->left == NULL && subroot->right != NULL) {
	// 	render(edit, subroot->right);
	// } else if (subroot->left != NULL && subroot->right == NULL) {
	// 	render(edit, subroot->left);
	// } else {
	// 	render(edit, subroot->left);
	// 	render(edit, subroot->right);
	// }


	if (subroot->left == NULL && subroot->right == NULL) {

		RGBAPixel a = subroot->avg;

		pair<int, int> ul = subroot->upLeft;
		pair<int, int> lr = subroot->lowRight;
	
		for (int i = ul.first; i <=lr.first; i++) {
			for (int j = ul.second; j <= lr.second; j++) {
				//RGBAPixel * change  = edit.getPixel(i,j);
				*edit.getPixel(i,j) = a;
			}
		} 

	} else {
		render(edit, subroot->left);
		render(edit, subroot->right);
	}

}

int twoDtree::idealPrune(int leaves){

// YOUR CODE HERE!!
int tol = 0;
if (root==NULL) {
	return 0;
} 

bool hi = true;

while (hi) {
	tol = tol + 1;
	if (leaves == pruneSize(tol-1)) {
		hi = false;
	}
}

return tol-1;

}

int twoDtree::pruneSize(int tol){
    
// YOUR CODE HERE!!

if (root == NULL) {
	return 0;
} else {
	return pruneSize(root, tol);
}

}

int twoDtree::pruneSize(Node* subtree, int tol) {

	RGBAPixel a = subtree->avg;
	bool pruneR = false;
	if (subtree->right == NULL) {
		pruneR = prunning(subtree->right, tol, a);
	}

	bool pruneL = false;
	if (subtree->left == NULL) {
		pruneL = prunning(subtree->left, tol, a);
	}
	
	int size = 0;

	if (pruneR && pruneL) {
		size = size + 1;
	} else {
		if (subtree->left == NULL) {
			size = size + pruneSize(subtree->left, tol);
		}

		if (subtree->right == NULL) {
			size = size + pruneSize(subtree->right, tol);
		}	
	}

	return size;

}

int twoDtree::countLeaves(Node* subtree) {

	int size = 0;

	if (subtree == NULL) {
		return 0;
	} 

	if (subtree->left == NULL && subtree->right == NULL) {
		size = size + 1;
	} else if (subtree->left == NULL && subtree->right != NULL) {
		size = size + countLeaves(subtree->right);
	} else if (subtree->left != NULL && subtree->right == NULL) {
		size = size + countLeaves(subtree->left);
	} else {
		size = size + countLeaves(subtree->right) + countLeaves(subtree->left);
	}

	return size;
	
}

void twoDtree::prune(int tol){

// YOUR CODE HERE!!
prune(root, tol);

}

void twoDtree::prune(Node* subtree, int tol) {


	RGBAPixel a = subtree->avg;
	bool pruneR = prunning(subtree->right, tol, a);
	bool pruneL = prunning(subtree->left, tol, a);

	// if (pruneR && pruneL) {
	// 	subtree->left = NULL;
	// 	subtree->right = NULL;
	// } else if (pruneR && !pruneL) {
	// 	subtree->right = NULL;
	// 	prune(subtree->left, tol);
	// } else if (!pruneR && pruneL) {
	// 	subtree->left = NULL;
	// 	prune(subtree->right, tol);
	// } else {
	// 	prune(subtree->left, tol);
	// 	prune(subtree->right, tol);
	// }
	
	if (pruneR && pruneL) {
		subtree->left = NULL;
		subtree->right = NULL;
	} else {
		prune(subtree->left, tol);
		prune(subtree->right, tol);
	}

}

bool twoDtree::prunning(Node* subtree, int tol, RGBAPixel avgPixel) {

	bool ret = true;
	RGBAPixel c = subtree->avg;
	int reddif = avgPixel.r - c.r;
	int greendif = avgPixel.g - c.g;
	int bluedif = avgPixel.b - c.b;
	int dist = ((reddif)*(reddif)) + ((greendif)*(greendif)) + ((bluedif)*(bluedif));
	if (dist <= tol) {
		ret = ret && prunning(subtree->left, tol, avgPixel) && prunning(subtree->right, tol, avgPixel);
	} else {
		ret = false;
	}
	return ret;
}
 


void twoDtree::clear() {

// YOUR CODE HERE!!
	clear(root);
	root = NULL;
	height = 0;
	width = 0;

}

void twoDtree::clear(Node* subRoot) {

	if (subRoot == NULL) {
		return;
	}
        
    clear(subRoot->left);
    clear(subRoot->right);
    delete subRoot;

}

void twoDtree::copy(const twoDtree & orig){

// YOUR CODE HERE!!

root = copy(orig.root);
int h = orig.height;
int w = orig.width;
height = h;
width = w;

}

twoDtree::Node* twoDtree::copy(const Node* subRoot) {

	if (subRoot == NULL) {
		return NULL;
	} else {
		pair<int,int> u = subRoot->upLeft; 
      	pair<int,int> l = subRoot->lowRight;
		RGBAPixel p = subRoot->avg;
		Node * retNode = new Node(u, l, p);
		retNode->left = copy(subRoot->left);
		retNode->right = copy(subRoot->right);
		return retNode; 
	}

}




