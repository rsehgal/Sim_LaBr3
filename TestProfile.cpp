#include "GaussProfile.h"
#include "GaussProfile.h"
#include "TH2F.h"
#include "TApplication.h"
int main()
{

  TApplication *fApp = new TApplication("Test", NULL, NULL);
  GaussProfile *gp   = new GaussProfile;
  TH2F *hist2D       = new TH2F("circle", "circle", 100, -3, 3, 100, -3, 3.);

  for (unsigned int i = 0; i < 100000; i++) {
    gp->SamplePointOnCircle();
    double x = gp->GetX();
    double y = gp->GetY();
    hist2D->Fill(x, y);
  }
  hist2D->Draw();
  fApp->Run();
}
