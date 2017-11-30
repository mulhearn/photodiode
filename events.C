
void events(int event = 0){
  gStyle->SetOptStat(0);
  TCanvas * c1 = new TCanvas;

  //int event = 0;
  //int event = 3;
  //int event = 4;
  //int event = 5;
  //int event = 6;

  TFile * f1 = new TFile("pdout.root");
  TTree * edep1 = (TTree*) (f1->Get("edep"))->Clone("edep1");

  for (int iy=0; iy<21; iy++){
    for (int ix=0; ix<21; ix++){
      index = iy * 21 + ix;
      cout << setw(5) << index << " ";
    }
    cout << "\n";
  }

  float gedep[1000];
  edep1->SetBranchAddress("cell_edep", &gedep);
  edep1->GetEntry(event);

  TH2F * h = new TH2F("h","",10,0,10,10,0,10);
  for (int ix=0; ix<10; ix++){  
    for (int iy=0; iy<10; iy++){
      index = iy * 10 + ix;
      //cout << setw(5) << (gedep[index] != 0) << " ";
      cout << setw(12) << gedep[index] << " ";
      h->Fill(1.0*ix,1.0*iy, gedep[index]);
    }
    cout << "\n";
  }

  h->Draw("boxz");
  c1->SaveAs("event.pdf");


}
