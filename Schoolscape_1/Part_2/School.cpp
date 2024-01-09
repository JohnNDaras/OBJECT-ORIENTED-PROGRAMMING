#include "School.h"

	School::School(){
		this->head = NULL;
		this->size = 0;
	}
	School::~School(){
		
	}
	//ADDS A CLASSROOM TO LIST
	void School::addClassroom(Classroom *p){
		Classroom *temp = this->head;
		//THIS THE FIRST CLASSROOM TO ADD
		if (temp == NULL){
			this->head = p;
			this->head->setNext(NULL);
			this->size++;
		}
		else {//PLACE THE NEW CLASSROOM ON THE HEAD OF THE LIST
			p->setNext(head);
			head = p;
			this->size++;
		}
		
	}
	Classroom *School::getClassroom(int x){
		Classroom *p = this->head;
		//MOVE IN LIST (X HOPS)
		while ((p!=NULL) && (x>0)){
			p = p->getNext();
			x--;
		}
		if (x==0){
			return p;
		}
		else {
			return NULL;
		}
	}
	void School::print(){
		Classroom *p = this->head;
		while (p!=NULL){
			cout << p->message(this->threshold1, this->threshold2);
			p->print();
			p = p->getNext();
		}
	}

	int School::getThreshold1(){
		return this->threshold1;
	}
		int School::getThreshold2(){
			return this->threshold1;
		}
		void School::setThreshold1(int t1){
			this->threshold1 = t1;
		}
		void School::setThreshold2(int t2){
			this->threshold1 = t2;
		}
		//CHOOSE Z KIDS RANDOMLY AND MAKES QUAIET LEVEL TO 0
		void School::changeStatus(int z, Student *S[], int st_size){
			int i;
			int w;
			srand(time(0));
			for (i=0;i<st_size;i++){
				S[i]->setQuiet(1);
			}
			for (i=0;i<z;i++){
				w = rand()%st_size;
				while (S[w]->getQuiet()==0){
					w = rand()%st_size;
				}
				cout << w << endl;
				S[w]->setQuiet(0);
			}
			for (i=0;i<this->size;i++){
				this->getN(i)->updateCounter();
			}	
		}
		Classroom *School::getN(int n){
			Classroom *p = this->head;
			while ((p!=NULL)&&(n>0)){
				n--;
				p = p->getNext();
			}
			return p;
		}
		
		void School::exSwap(int fromClass, int element, int toClassA, int elementA){
			Pair *p1 = this->getN(fromClass)->getSequence()->getN(element);//THE PAIR FROM THE FIRST CLASSROOM
			Pair *p2 = this->getN(fromClass)->getSequence()->getN(elementA);//THE PAIR FROM THE SECOND CLASSROOM
			//MAKING THE SWAP
			Pair *temp;
			temp = p1;
			p1 = p2;
			p2 = temp;
			this->getN(fromClass)->increaseSwaps();
			this->getN(toClassA)->increaseSwaps();
		}
		
		void School::fixIt(){
			int i,j;
			int x,e;
			Classroom *c;
			//Pair *p;
			for (j=0;j<this->size;j++){
				c = this->getN(j);
				for (i=0;i<c->getSequence()->getSize();i++){
					if (c->swapType(i)==1){
						//cout << "Intra Swap" << endl;
						//SWAPING IN THE SEQUENCE
						c->intraSwap(i);
						//INCREASING  THE SWAP COUNTER
						this->getN(j)->increaseSwaps();
						
					}
					else if (c->swapType(i)==2){
						//THE NEXT CLASSROOM NUMBER
						x = (j+1)%this->size;
						e = rand()%this->getN(x)->getSequence()->getSize();
						this->exSwap(j,i,x,e);
						//INCREASING  THE SWAP COUNTER TO BOTH THE SEQUENCES
						this->getN(j)->increaseSwaps();
						this->getN(x)->increaseSwaps();
						//cout << "External Swap" << endl;
					}
					else if (c->swapType(i)==3){
						//CHOOSE THE OTHER CLASSROOM RANDOMLY
						x = rand()%this->size;
						while (x==j){
							x = rand()%this->size;
						}
						//CHOOSE THE SECOND ELEMENT RANDOMLY
						e = rand()%this->getN(x)->getSequence()->getSize();
						this->exSwap(j,i,x,e);
						//INCREASING  THE SWAP COUNTER TO BOTH THE SEQUENCES
						this->getN(j)->increaseSwaps();
						this->getN(x)->increaseSwaps();
						//cout << "Poly External Swap" << endl;
					}
				}
				c = c->getNext();
			}
		}
		
		void School::printQuietLevels(){
			Classroom *p = this->head;
			while (p!=NULL){
				cout << p->getCounter() << endl;
				p = p->getNext();
			}
		}

