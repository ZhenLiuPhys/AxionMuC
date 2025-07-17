//#include "DataFormats/Math/interface/deltaR.h"
//#include "DataFormats/Math/interface/deltaPhi.h"
#include <vector>
#include <iostream>
#include <math.h>
#include "TH1F.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TH2F.h"
#include <TLatex.h>
//#include "../jj_bkg/Events/run_01/jj_bkg.h"

void parton_level_analysis_10TeV_plot(){
  
  
  //TFile *f0 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_4_0/HZZ_bkg/h_signal/Events/run_03/unweighted_events.root");
  
  
  TFile *f1 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f2 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_2TeV_6TeV/unweighted_events.root");
  
  TFile *f3 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_6TeV_9500GeV/unweighted_events.root");
  
  TFile *f4 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_9500GeV_9900GeV/unweighted_events.root");
  
  TFile *f5 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f6 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_2TeV_6TeV/unweighted_events.root");
  
  TFile *f7 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_6TeV_9500GeV/unweighted_events.root");
  
  TFile *f8 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_9500GeV_9900GeV/unweighted_events.root");

  TFile *f9 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj_inv/Events/10TeV_inv_V_mjj_130_9800/unweighted_events.root");
  TFile *f10 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj/Events/10TeV_mjj_130_9800/unweighted_events.root");
  TFile *f11 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/aa2wjj/Events/10TeV_mjj_130_9800/unweighted_events.root");
  
  

  
  TTree *b11 = (TTree*)f1->Get("LHEF");
  TTree *b12 = (TTree*)f2->Get("LHEF");
  TTree *b13 = (TTree*)f3->Get("LHEF");
  TTree *b14 = (TTree*)f4->Get("LHEF");
  
  TTree *b21 = (TTree*)f5->Get("LHEF");
  TTree *b22 = (TTree*)f6->Get("LHEF");
  TTree *b23 = (TTree*)f7->Get("LHEF");
  TTree *b24 = (TTree*)f8->Get("LHEF");

  TTree *b31 = (TTree*)f9->Get("LHEF");
  TTree *b32 = (TTree*)f10->Get("LHEF");
  TTree *b33 = (TTree*)f11->Get("LHEF");
  
  
  

  //create histograms
  // TH1F *plotvariable_for_code = new TH1F("plot_name","plot_title",nbins,xlow,xup);
  
  
  
  
  
  TH1F *Mjj_plot_bkg1 = new TH1F("Mjj_plot_bkg1","",100,0,10);
  TH1F *Mjj_plot_bkg2 = new TH1F("Mjj_plot_bkg2","",100,0,10);
  
  TH1F *Mjj_plot_bkg3 = new TH1F("Mjj_plot_bkg3","",100,0,10);
  TH1F *Mjj_plot_bkg4 = new TH1F("Mjj_plot_bkg4","",100,0,10);
  TH1F *Mjj_plot_bkg5 = new TH1F("Mjj_plot_bkg5","",100,0,10);
  
  double binwidth = 0.1;
  
	
  

  
	
  static constexpr Int_t kMaxParticle = 6;
  
  Int_t           Particle_PID[kMaxParticle];   //[Particle_]
  Int_t           Particle_Status[kMaxParticle];   //[Particle_]
  Double_t        Particle_E[kMaxParticle];   //[Particle_]
  Double_t        Particle_M[kMaxParticle];   //[Particle_]
  Double_t        Particle_PT[kMaxParticle];   //[Particle_]
  Double_t        Particle_Eta[kMaxParticle];   //[Particle_]
  Double_t        Particle_Phi[kMaxParticle];   //[Particle_]
  
  
  
  TBranch        *b_Particle_PID;   //!
  TBranch        *b_Particle_Status;   //!
  TBranch        *b_Particle_E;   //!
  TBranch        *b_Particle_M;   //!
  TBranch        *b_Particle_PT;   //!
  TBranch        *b_Particle_Eta;   //!
  TBranch        *b_Particle_Phi;   //!
  
  
  
  
  
  b11->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b11->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b11->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b11->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b11->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b11->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b11->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);

  b12->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b12->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b12->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b12->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b12->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b12->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b12->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);

  b13->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b13->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b13->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b13->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b13->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b13->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b13->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);

  b14->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b14->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b14->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b14->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b14->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b14->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b14->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
  b21->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b21->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b21->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b21->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b21->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b21->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b21->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);

  b22->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b22->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b22->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b22->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b22->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b22->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b22->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
  b23->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b23->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b23->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b23->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b23->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b23->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b23->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
  b24->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b24->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b24->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b24->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b24->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b24->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b24->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
  b31->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b31->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b31->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b31->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b31->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b31->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b31->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);

  b32->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b32->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b32->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b32->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b32->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b32->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b32->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
  b33->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b33->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b33->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b33->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b33->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b33->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b33->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  


  
  //define new variable for plot
  //double tempdR = 999.0;

  
  int entries11=b11->GetEntries();
  int entries12=b12->GetEntries();
  int entries13=b13->GetEntries();
  int entries14=b14->GetEntries();
  
  int entries21=b21->GetEntries();
  int entries22=b22->GetEntries();
  int entries23=b23->GetEntries();
  int entries24=b24->GetEntries();
  
  int entries31=b31->GetEntries();
  int entries32=b32->GetEntries();
  int entries33=b33->GetEntries();


  
  
  
  //std::cout <<"entries0:"<<entries0<<std::endl;
  std::cout <<"entries11:"<<entries11<<std::endl;
  std::cout <<"entries12:"<<entries12<<std::endl;
  std::cout <<"entries13:"<<entries13<<std::endl;
  std::cout <<"entries14:"<<entries14<<std::endl;

  std::cout <<"entries21:"<<entries21<<std::endl;
  std::cout <<"entries22:"<<entries22<<std::endl;
  std::cout <<"entries23:"<<entries23<<std::endl;
  std::cout <<"entries24:"<<entries24<<std::endl;
  
  std::cout <<"entries31:"<<entries31<<std::endl;
  std::cout <<"entries32:"<<entries32<<std::endl;
  std::cout <<"entries33:"<<entries33<<std::endl;
  
  
  
  vector<double> benchmark_mass(12,0);
  benchmark_mass[0]=200;
  benchmark_mass[1]=300;
  benchmark_mass[2]=500;
  benchmark_mass[3]=1000;
  benchmark_mass[4]=2000;
  benchmark_mass[5]=3000;
  benchmark_mass[6]=4000;
  benchmark_mass[7]=5000;
  benchmark_mass[8]=6000;
  benchmark_mass[9]=7000;
  benchmark_mass[10]=8000;
  benchmark_mass[11]=9000;

  int benchmarknumber = 12;

  //////////////////////////sample 11//////////////////////////////////////////////////////////////////////
  double weight_bkg11 = 1.344/50000.0;
  for (int i=0; i<entries11; ++i){
    b11->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg11[0]=countnumber_bkg11[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg11 / binwidth);
      //countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg11;
    }
    
      
    
  }
  std::cout <<"pass11"<<std::endl;

  //////////////////////////sample 12//////////////////////////////////////////////////////////////////////
  double weight_bkg12 = 0.00242/50000.0;
  for (int i=0; i<entries12; ++i){
    b12->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg12[0]=countnumber_bkg12[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg12 / binwidth);
      //countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg12;
    }
    
      
    
  }
  std::cout <<"pass12"<<std::endl;


  //////////////////////////sample 13//////////////////////////////////////////////////////////////////////
  double weight_bkg13 = 4.16e-5/50000.0;
  for (int i=0; i<entries13; ++i){
    b13->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg13[0]=countnumber_bkg13[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg13 / binwidth);
      //countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg13;
    }
    
      
    
  }
  std::cout <<"pass13"<<std::endl;


  //////////////////////////sample 14//////////////////////////////////////////////////////////////////////
  double weight_bkg14 = 6.556e-6/50000.0;
  for (int i=0; i<entries14; ++i){
    b14->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg14[0]=countnumber_bkg14[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg14 / binwidth);
      //countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg14;
    }

    
    
    
      
    
  }
  std::cout <<"pass14"<<std::endl;
  

  
  //////////////////////////sample 21//////////////////////////////////////////////////////////////////////
  double weight_bkg21 = 0.057/50000.0;
  for (int i=0; i<entries21; ++i){
    b21->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg21[0]=countnumber_bkg21[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg21 / binwidth);
      //countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg21;
    }
    
    
      
    
  }
  std::cout <<"pass21"<<std::endl;

  //////////////////////////sample 22//////////////////////////////////////////////////////////////////////
  double weight_bkg22 = 0.001145/50000.0;
  for (int i=0; i<entries22; ++i){
    b22->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg22[0]=countnumber_bkg22[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg22 / binwidth);
      //countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg22;
    }
    
    
      
    
  }
  std::cout <<"pass22"<<std::endl;


  //////////////////////////sample 23//////////////////////////////////////////////////////////////////////
  double weight_bkg23 = 6.03e-5/50000.0;
  for (int i=0; i<entries23; ++i){
    b23->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg23[0]=countnumber_bkg23[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg23 / binwidth);
      //countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg23;
    }
    
    
      
    
  }
  std::cout <<"pass23"<<std::endl;


  //////////////////////////sample 24//////////////////////////////////////////////////////////////////////
  double weight_bkg24 = 8.8e-6/50000.0;
  for (int i=0; i<entries24; ++i){
    b24->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg24[0]=countnumber_bkg24[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg24 / binwidth);
      //countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg24;
    }
    
    
      
    
  }
  std::cout <<"pass24"<<std::endl;


  //////////////////////////sample 31//////////////////////////////////////////////////////////////////////
  double weight_bkg31 = 0.003/20000.0;
  for (int i=0; i<entries31; ++i){
    b31->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg31[0]=countnumber_bkg31[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg3->Fill((j1+j2).M()/1000,weight_bkg31 / binwidth);
    }
      
    
  }
  std::cout <<"pass31"<<std::endl;


  //////////////////////////sample 32//////////////////////////////////////////////////////////////////////
  double weight_bkg32 = 0.00269/50000.0;
  for (int i=0; i<entries32; ++i){
    b32->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg32[0]=countnumber_bkg32[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg4->Fill((j1+j2).M()/1000,weight_bkg32 / binwidth);
    }
      
    
  }
  std::cout <<"pass32"<<std::endl;


  //////////////////////////sample 33//////////////////////////////////////////////////////////////////////
  double weight_bkg33 = 2*0.00342/50000.0;
  for (int i=0; i<entries33; ++i){
    b33->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg33[0]=countnumber_bkg33[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg5->Fill((j1+j2).M()/1000,weight_bkg33 / binwidth);
    }
      
    
  }
  std::cout <<"pass33"<<std::endl;

  
  
  
  // draw plot
  gStyle->SetPadLeftMargin(0.17); gStyle->SetPadRightMargin(0.05); gStyle->SetPadBottomMargin(0.15);
  gStyle->SetTitleFont(132, "xyz"); 
  gStyle->SetLabelFont(132, "xyz"); 
  gStyle->SetTextFont(132); 
  

  //原神配色 (璃月)https://zhuanlan.zhihu.com/p/598971518 (须弥)https://zhuanlan.zhihu.com/p/601170660  

  TColor *hutao1_color = new TColor(9002,0.705882, 0.494118, 0.545098); //褐色dark red
  TColor *hutao2_color = new TColor(9004, 0.78824, 0.27843, 0.21569); //红色red
  TColor *ganyu_color = new TColor(9001,0.317647, 0.654902, 0.752941); //蓝色blue
  TColor *naxida_color = new TColor(9003,0.1875, 0.54687, 0.347656);  //绿色green
  
  
  TCanvas *c110 = new TCanvas();
  Mjj_plot_bkg1->SetStats(0);
  Mjj_plot_bkg2->SetStats(0);
  Mjj_plot_bkg3->SetStats(0);
  Mjj_plot_bkg4->SetStats(0);
  Mjj_plot_bkg5->SetStats(0);
  
  
  Mjj_plot_bkg1->SetLineColor(9004); //红色
  Mjj_plot_bkg2->SetLineColor(9002); //褐色
  Mjj_plot_bkg3->SetLineColor(9001); //蓝色
  Mjj_plot_bkg4->SetLineColor(1); //黑色
  Mjj_plot_bkg5->SetLineColor(9003); //绿色

  Mjj_plot_bkg1->SetLineWidth(2);
  Mjj_plot_bkg2->SetLineWidth(2);
  Mjj_plot_bkg3->SetLineWidth(2);
  Mjj_plot_bkg4->SetLineWidth(2);
  Mjj_plot_bkg5->SetLineWidth(2);
 
  
  Mjj_plot_bkg1->GetXaxis()->SetTitle("M_{jj} [TeV]");
  Mjj_plot_bkg1->GetYaxis()->SetTitle("d#sigma/dM_{jj} [pb/TeV]");
  Mjj_plot_bkg1->GetXaxis()->SetTitleSize(0.07);
  Mjj_plot_bkg1->GetYaxis()->SetTitleSize(0.07);
  Mjj_plot_bkg1->GetXaxis()->SetLabelSize(0.06);
  Mjj_plot_bkg1->GetYaxis()->SetLabelSize(0.06);
  Mjj_plot_bkg1->GetXaxis()->SetTitleFont(132);
  Mjj_plot_bkg1->GetYaxis()->SetTitleFont(132);
  Mjj_plot_bkg1->GetYaxis()->SetRangeUser(0.0001,5.0);
  
  Mjj_plot_bkg1->Draw("HIST");
  Mjj_plot_bkg2->Draw("HIST" "same");
  Mjj_plot_bkg3->Draw("HIST" "same");
  Mjj_plot_bkg4->Draw("HIST" "same");
  Mjj_plot_bkg5->Draw("HIST" "same");

  TLegend *l_Mjj_plot = new TLegend(0.8,0.6,0.95,0.9);
  l_Mjj_plot->AddEntry(Mjj_plot_bkg1,"#mu#mujj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg2,"#nu_{#mu}#nu_{#mu}jj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg3,"#slash{V}jj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg5,"#mu#muWjj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg4,"Vjj","l");
  l_Mjj_plot->SetTextFont(132);
  l_Mjj_plot->SetTextSize(0.05);
  l_Mjj_plot->Draw();
  
  
  c110->SetLogy();
  c110->SetTickx();
  c110->SetTicky();
  c110->SetGridx();
  c110->SaveAs("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/plot_macro/output_plot/Mjj_bkg_plot_10TeV.pdf");
  
  
  
}