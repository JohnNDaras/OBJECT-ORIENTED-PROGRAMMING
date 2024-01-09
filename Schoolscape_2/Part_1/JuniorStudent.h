#ifndef JUNIORSTUDENT_H
#define JUNIORSTUDENT_H
//junior type of student
class JuniorStudent : public Student{
		public:
			JuniorStudent(string fn, int f, int c, int i):Student(fn, f, c, i){
				cout << "::Junior Student::" << endl;
			};
			JuniorStudent():Student(){
				cout << "::Junior Student::" << endl;
			};
			//junior student physical status computation
			void computePhysicalStatus(){
				physicalStatus = L * attend;
			}
			static int L; 
		private:
			
			
};


#endif
