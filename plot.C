
{
  gStyle->SetOptStat(0);
  TCanvas c1;
  c1->SetLogy();

  TFile * f1 = new TFile("pdout_m2.root");
  TTree * edep1 = (TTree*) (f1->Get("edep"))->Clone("edep1");  

  TFile * f2 = new TFile("pdout_e2.root");
  TTree * edep2 = (TTree*) (f2->Get("edep"))->Clone("edep2");

  //f1->ls();
  //f2->ls();
 
  TH1F * h1 = new TH1F("h1", "", 100, 0.0, 20);
  TH1F * h2 = new TH1F("h2", "", 100, 0.0, 20);
  //TH1F * h1 = new TH1F("h1", "", 100, 0.0, 100);
  //TH1F * h2 = new TH1F("h2", "", 100, 0.0, 100);

  //edep1->Draw("1000.0*mu_e>>h1"); 
  //edep2->Draw("1000.0*ele_e >> h2");

  //edep1->Draw("1000.0*grid_edep >> h1", "grid_edep > 0.0"); 
  //edep2->Draw("1000.0*grid_edep >> h2", "grid_edep > 0.0");

  edep1->Draw("1000.0*grid_edep >> h1", "grid_edep > 0.0"); 
  edep2->Draw("1000.0*grid_edep >> h2", "grid_edep > 0.0");

  double s1 = h1->GetSumOfWeights();
  double s2 = h2->GetSumOfWeights();
  if (h1 > 0.0) h1->Scale(1.0 / s1);
  if (h2 > 0.0) h2->Scale(1.0 / s2);

  h1->SetXTitle("Energy Deposited [keV]");

  h1->SetLineColor(2);
  h2->SetLineColor(4);

  h1->Draw("H");
  h2->Draw("HSAME");

  c1->SaveAs("edep.pdf");


}
