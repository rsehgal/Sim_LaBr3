#ifndef GAUSS_PROFILE
#define GAUSS_PROFILE

//#include <G4ThreeVector.hh>
#include <TH2F.h>
#include <TRandom3.h>
class GaussProfile{

double x,y,z;
double rad;
TRandom3 *fRnd;

	public:
		GaussProfile(){
			fRnd = new TRandom3;
		}
		double GetX(){return x;}
		double GetY(){return y;}
		double GetZ(){return z;}
		/*
		G4ThreeVector GetG4Vector(){
			return G4ThreeVector(x,y,z);

		}
		*/

		void GetRadius(){
			double dist = 5;
			double theta = fRnd->Gaus(0,M_PI/6.);
			rad = dist*std::tan(theta);
		}

		void FillCircle(){
			double phi = fRnd->Uniform(2*M_PI);
			x = rad * std::cos(phi);
			y = rad * std::sin(phi);
		}

		void SamplePointOnCircle(){
			GetRadius();
			FillCircle();
		}


};

#endif
