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

void parton_level_analysis_10TeV(){
  
  
  //TFile *f0 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_4_0/HZZ_bkg/h_signal/Events/run_03/unweighted_events.root");
  
  
  TFile *f1 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f2 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_2TeV_6TeV/unweighted_events.root");
  
  TFile *f3 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_6TeV_9500GeV/unweighted_events.root");
  
  TFile *f4 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/10TeV_mjj_9500GeV_9900GeV/unweighted_events.root");
  
  TFile *f5 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f6 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_2TeV_6TeV/unweighted_events.root");
  
  TFile *f7 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_6TeV_9500GeV/unweighted_events.root");
  
  TFile *f8 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/10TeV_mjj_9500GeV_9900GeV/unweighted_events.root");

  TFile *f81 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj_inv/Events/10TeV_inv_V_mjj_130_9800/unweighted_events.root");

  TFile *f9 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj/Events/10TeV_mjj_130_9800/unweighted_events.root");

  TFile *f10 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/aa2wjj/Events/10TeV_mjj_130_9800/unweighted_events.root");
  
  
  
  
  TTree *b11 = (TTree*)f1->Get("LHEF");
  TTree *b12 = (TTree*)f2->Get("LHEF");
  TTree *b13 = (TTree*)f3->Get("LHEF");
  TTree *b14 = (TTree*)f4->Get("LHEF");
  
  TTree *b21 = (TTree*)f5->Get("LHEF");
  TTree *b22 = (TTree*)f6->Get("LHEF");
  TTree *b23 = (TTree*)f7->Get("LHEF");
  TTree *b24 = (TTree*)f8->Get("LHEF");
  TTree *b25 = (TTree*)f81->Get("LHEF");

  TTree *b31 = (TTree*)f9->Get("LHEF");
  TTree *b32 = (TTree*)f10->Get("LHEF");
  
  

  //create histograms
  // TH1F *plotvariable_for_code = new TH1F("plot_name","plot_title",nbins,xlow,xup);
  
  
  
  
  
  TH1F *Mjj_plot_bkg1 = new TH1F("Mjj_plot_bkg1","",100,0,10);
  TH1F *Mjj_plot_bkg2 = new TH1F("Mjj_plot_bkg2","",100,0,10);
  
  TH1F *Mjj_plot_bkg3 = new TH1F("Mjj_plot_bkg3","",100,0,10);
  
  
  
	
  

  
	
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

  b25->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
  b25->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
  b25->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
  b25->SetBranchAddress("Particle.M", Particle_M, &b_Particle_M);
  b25->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
  b25->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
  b25->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
  
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
  


  
  //define new variable for plot
  //double tempdR = 999.0;

  //int entries0=s1->GetEntries();
  
  int entries11=b11->GetEntries();
  int entries12=b12->GetEntries();
  int entries13=b13->GetEntries();
  int entries14=b14->GetEntries();
  
  int entries21=b21->GetEntries();
  int entries22=b22->GetEntries();
  int entries23=b23->GetEntries();
  int entries24=b24->GetEntries();
  int entries25=b25->GetEntries();
  
  int entries31=b31->GetEntries();
  int entries32=b32->GetEntries();


  
  
  
  //std::cout <<"entries0:"<<entries0<<std::endl;
  std::cout <<"entries11:"<<entries11<<std::endl;
  std::cout <<"entries12:"<<entries12<<std::endl;
  std::cout <<"entries13:"<<entries13<<std::endl;
  std::cout <<"entries14:"<<entries14<<std::endl;

  std::cout <<"entries21:"<<entries21<<std::endl;
  std::cout <<"entries22:"<<entries22<<std::endl;
  std::cout <<"entries23:"<<entries23<<std::endl;
  std::cout <<"entries24:"<<entries24<<std::endl;
  std::cout <<"entries25:"<<entries25<<std::endl;
  
  std::cout <<"entries31:"<<entries31<<std::endl;
  std::cout <<"entries32:"<<entries32<<std::endl;
  
  vector<double> countnumber_bkg11(13,0);
  vector<double> countnumber_bkg12(13,0);
  vector<double> countnumber_bkg13(13,0);
  vector<double> countnumber_bkg14(13,0);
  vector<double> countnumber_bkg21(13,0);
  vector<double> countnumber_bkg22(13,0);
  vector<double> countnumber_bkg23(13,0);
  vector<double> countnumber_bkg24(13,0);
  vector<double> countnumber_bkg25(13,0);
  vector<double> countnumber_bkg31(13,0);
  vector<double> countnumber_bkg32(13,0);

  vector<double> countnumber_bkg1(1,0);
  vector<double> countnumber_bkg2(1,0);
  
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
	  
    countnumber_bkg11[0]=countnumber_bkg11[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg11);
      countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg11;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
        countnumber_bkg11[j+1]=countnumber_bkg11[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass11"<<std::endl;

  //////////////////////////sample 12//////////////////////////////////////////////////////////////////////
  double weight_bkg12 = 0.00242/50000.0;
  for (int i=0; i<entries12; ++i){
    b12->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg12[0]=countnumber_bkg12[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg12);
      countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg12;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 2000.0) {
        countnumber_bkg12[j+1]=countnumber_bkg12[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass12"<<std::endl;


  //////////////////////////sample 13//////////////////////////////////////////////////////////////////////
  double weight_bkg13 = 4.16e-5/50000.0;
  for (int i=0; i<entries13; ++i){
    b13->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg13[0]=countnumber_bkg13[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg13);
      countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg13;
    }
    
    
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 6000.0) {
        countnumber_bkg13[j+1]=countnumber_bkg13[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass13"<<std::endl;


  //////////////////////////sample 14//////////////////////////////////////////////////////////////////////
  double weight_bkg14 = 6.556e-6/50000.0;
  for (int i=0; i<entries14; ++i){
    b14->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg14[0]=countnumber_bkg14[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg14);
      countnumber_bkg1[0]=countnumber_bkg1[0]+weight_bkg14;
    }

    
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 9500.0 ) {
        countnumber_bkg14[j+1]=countnumber_bkg14[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass14"<<std::endl;
  

  
  //////////////////////////sample 21//////////////////////////////////////////////////////////////////////
  double weight_bkg21 = 0.057/50000.0;
  for (int i=0; i<entries21; ++i){
    b21->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg21[0]=countnumber_bkg21[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg21);
      countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg21;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
        countnumber_bkg21[j+1]=countnumber_bkg21[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass21"<<std::endl;

  //////////////////////////sample 22//////////////////////////////////////////////////////////////////////
  double weight_bkg22 = 0.001145/50000.0;
  for (int i=0; i<entries22; ++i){
    b22->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg22[0]=countnumber_bkg22[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg22);
      countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg22;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 2000.0) {
        countnumber_bkg22[j+1]=countnumber_bkg22[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass22"<<std::endl;


  //////////////////////////sample 23//////////////////////////////////////////////////////////////////////
  double weight_bkg23 = 6.03e-5/50000.0;
  for (int i=0; i<entries23; ++i){
    b23->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg23[0]=countnumber_bkg23[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg23);
      countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg23;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 6000.0) {
        countnumber_bkg23[j+1]=countnumber_bkg23[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass23"<<std::endl;


  //////////////////////////sample 24//////////////////////////////////////////////////////////////////////
  double weight_bkg24 = 8.8e-6/50000.0;
  for (int i=0; i<entries24; ++i){
    b24->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg24[0]=countnumber_bkg24[0]+1;
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg24);
      countnumber_bkg2[0]=countnumber_bkg2[0]+weight_bkg24;
    }
    
    //mCP_Eta_plot_signal->Fill(Particle_Eta[mCP_index]);
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && (j1+j2).M() > 9500.0 ) {
        countnumber_bkg24[j+1]=countnumber_bkg24[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass24"<<std::endl;



  //////////////////////////sample 25//////////////////////////////////////////////////////////////////////
  double weight_bkg25 = 0.00304/20000.0;
  countnumber_bkg25[0]=entries25;
  for (int i=0; i<entries25; ++i){
    b25->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    //countnumber_bkg25[0]=countnumber_bkg25[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg3->Fill((j1+j2).M()/1000,weight_bkg31);
    }
    
    
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 ) {
        countnumber_bkg25[j+1]=countnumber_bkg25[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass25"<<std::endl;




  //////////////////////////sample 31//////////////////////////////////////////////////////////////////////
  double weight_bkg31 = 0.00269/50000.0;
  for (int i=0; i<entries31; ++i){
    b31->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg31[0]=countnumber_bkg31[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      Mjj_plot_bkg3->Fill((j1+j2).M()/1000,weight_bkg31);
    }
    
    
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && Particle_Eta[j0_index] < 2.5 && Particle_Eta[j0_index] > -2.5 && (Particle_PID[j0_index] == 23 || Particle_PID[j0_index] == 24 || Particle_PID[j0_index] == -24)) {
        countnumber_bkg31[j+1]=countnumber_bkg31[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass31"<<std::endl;



  //////////////////////////sample 32//////////////////////////////////////////////////////////////////////
  double weight_bkg32 = 2*0.00342/50000.0;
  for (int i=0; i<entries32; ++i){
    b32->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    countnumber_bkg32[0]=countnumber_bkg32[0]+1;
    // Apply cut
    
    int j1_index = 3;
    int j2_index = 4;
    int j0_index = 2; // the Z/W

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg3->Fill((j1+j2).M()/1000,weight_bkg31);
    }
    
    
    for (int j=0; j<benchmarknumber; ++j){
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && Particle_Eta[j0_index] < 2.5 && Particle_Eta[j0_index] > -2.5 && (Particle_PID[j0_index] == 23 || Particle_PID[j0_index] == 24 || Particle_PID[j0_index] == -24)) {
        countnumber_bkg32[j+1]=countnumber_bkg32[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass32"<<std::endl;

  



  // cutflow
  
  std::cout <<"Total_bkg11:"<<countnumber_bkg11[0]<<"->"<<countnumber_bkg11[0]/countnumber_bkg11[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg11[i+1]<<"->"<<countnumber_bkg11[i+1]/countnumber_bkg11[0]<<std::endl;
  }
  std::cout << std::endl;

  std::cout <<"Total_bkg12:"<<countnumber_bkg12[0]<<"->"<<countnumber_bkg12[0]/countnumber_bkg12[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg12[i+1]<<"->"<<countnumber_bkg12[i+1]/countnumber_bkg12[0]<<std::endl;
  }
  std::cout << std::endl;

  std::cout <<"Total_bkg13:"<<countnumber_bkg13[0]<<"->"<<countnumber_bkg13[0]/countnumber_bkg13[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg13[i+1]<<"->"<<countnumber_bkg13[i+1]/countnumber_bkg13[0]<<std::endl;
  }
  std::cout << std::endl;

  std::cout <<"Total_bkg14:"<<countnumber_bkg14[0]<<"->"<<countnumber_bkg14[0]/countnumber_bkg14[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg14[i+1]<<"->"<<countnumber_bkg14[i+1]/countnumber_bkg14[0]<<std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;



  std::cout <<"Total_bkg21:"<<countnumber_bkg21[0]<<"->"<<countnumber_bkg21[0]/countnumber_bkg21[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg21[i+1]<<"->"<<countnumber_bkg21[i+1]/countnumber_bkg21[0]<<std::endl;
  }
  std::cout << std::endl;
  
  std::cout <<"Total_bkg22:"<<countnumber_bkg22[0]<<"->"<<countnumber_bkg22[0]/countnumber_bkg22[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg22[i+1]<<"->"<<countnumber_bkg22[i+1]/countnumber_bkg22[0]<<std::endl;
  }
  std::cout << std::endl;
  
  std::cout <<"Total_bkg23:"<<countnumber_bkg23[0]<<"->"<<countnumber_bkg23[0]/countnumber_bkg23[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg23[i+1]<<"->"<<countnumber_bkg23[i+1]/countnumber_bkg23[0]<<std::endl;
  }
  std::cout << std::endl;
  
  std::cout <<"Total_bkg24:"<<countnumber_bkg24[0]<<"->"<<countnumber_bkg24[0]/countnumber_bkg24[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg24[i+1]<<"->"<<countnumber_bkg24[i+1]/countnumber_bkg24[0]<<std::endl;
  }
  std::cout << std::endl;

  std::cout <<"Total_bkg25:"<<countnumber_bkg25[0]<<"->"<<countnumber_bkg25[0]/countnumber_bkg25[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg25[i+1]<<"->"<<countnumber_bkg25[i+1]/countnumber_bkg25[0]<<std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;



  std::cout <<"Total_bkg31:"<<countnumber_bkg31[0]<<"->"<<countnumber_bkg31[0]/countnumber_bkg31[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg31[i+1]<<"->"<<countnumber_bkg31[i+1]/countnumber_bkg31[0]<<std::endl;
  }
  std::cout << std::endl;
  
  std::cout <<"Total_bkg1_etaj:"<<countnumber_bkg1[0]<<std::endl;
  std::cout <<"Total_bkg2_etaj:"<<countnumber_bkg2[0]<<std::endl;


  
  std::cout <<"Total_bkg32:"<<countnumber_bkg32[0]<<"->"<<countnumber_bkg32[0]/countnumber_bkg32[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg32[i+1]<<"->"<<countnumber_bkg32[i+1]/countnumber_bkg32[0]<<std::endl;
  }
  std::cout << std::endl;
  
  
 
  // Branching ratio between ax -> gg to ax -> gammagamma
  vector<double> ratioofBR(12,0);
  ratioofBR[0]=9.97e-01/2.22e-03;
  ratioofBR[1]=9.81e-01/2.2e-03;
  ratioofBR[2]=9.7e-01/2.17e-03;
  ratioofBR[3]=9.7e-01/2.16e-03;
  ratioofBR[4]=9.69e-01/2.16e-03;
  ratioofBR[5]=9.69e-01/2.16e-03;
  ratioofBR[6]=9.69e-01/2.157e-03;
  ratioofBR[7]=9.69e-01/2.157e-03;
  ratioofBR[8]=9.69e-01/2.157e-03;
  ratioofBR[9]=9.69e-01/2.157e-03;
  ratioofBR[10]=9.69e-01/2.157e-03;
  ratioofBR[11]=9.69e-01/2.157e-03;
  // compute significance
  vector<double> xs_b1(12,0);
  vector<double> xs_b2(12,0);
  vector<double> xs_s1(12,0);
  vector<double> xs_s2(12,0);
  // *1e6 because fa=1000; mumuax(aa2ax,2*za2ax,zz2ax) + vmvmax(ww2ax) + zax + 2*aw2wax + 2*zw2wax + ww2zax
  /*xs_s[0]=(8.1e-9 + 2*1.24e-11 + 0       + 3.8e-9 + 1.58e-10 + 2*1.13e-6 + 2*7.65e-7 + 2.16e-6)*1e6*ratioofBR[0];
  xs_s[1]=(8.71e-9 + 2*7.73e-10 + 1.3e-11 + 2.96e-10 + 3.8e-10 + 2*2.3e-6 + 2*1.6e-6 + 4.5e-6)*1e6*ratioofBR[1];
  xs_s[2]=(9.22e-9 + 2*1.65e-10 + 5.8e-11 + 9.98e-10 + 9.5e-10 + 2*4.4e-6 + 2*3.2e-6 + 8.9e-6)*1e6*ratioofBR[2];
  xs_s[3]=(9.27e-9 + 2*2.64e-10 + 1.47e-10 + 2.26e-9 + 2.6e-9 + 2*5.25e-6 + 2*3.8e-6 + 1.07e-5)*1e6*ratioofBR[3];
  xs_s[4]=(7.29e-9 + 2*2.7e-10 + 1.98e-10 + 2.8e-9 + 2.3e-9 + 2*3.5e-6 + 2*2.6e-6 + 7.16e-6)*1e6*ratioofBR[4];
  xs_s[5]=(5.32e-9 + 2*2.22e-10 + 1.82e-10 + 2.35e-9 + 2.0e-9 + 2*1.9e-6 + 2*1.45e-6 + 4.0e-6)*1e6*ratioofBR[5];
  xs_s[6]=(3.8e-9 + 2*1.7e-10 + 1.49e-10 + 1.7e-9 + 1.6e-9 + 2*9.1e-7 + 2*6.8e-7 + 1.9e-6)*1e6*ratioofBR[6];
  xs_s[7]=(2.65e-9 + 2*1.24e-11 + 1.14e-10 + 1.09e-9 + 1.1e-9 + 2*3.5e-7 + 2*2.6e-7 + 7.2e-7)*1e6*ratioofBR[7];
  xs_s[8]=(1.79e-9 + 2*8.7e-11 + 8.23e-11 + 6.06e-10 + 7.0e-10 + 2*1e-7 + 2*7.8e-8 + 2.1e-7)*1e6*ratioofBR[8];
  xs_s[9]=(1.15e-9 + 2*5.75e-11 + 5.58e-11 + 2.7e-10 + 3.5e-10 + 2*2e-8 + 2*1.55e-8 + 4.2e-8)*1e6*ratioofBR[9];
  xs_s[10]=(6.7e-10 + 2*3.43e-11 + 3.4e-11 + 8.64e-11 + 1.2e-10 + 2*2e-9 + 2*1.5e-9 + 4.1e-9)*1e6*ratioofBR[10];
  xs_s[11]=(3.035e-10 + 2*1.58e-11 + 1.6e-11 + 1.14e-11 + 1.8e-11 + 2*5e-11 + 2*3.2e-11 + 7.3e-11)*1e6*ratioofBR[11]; */

  xs_s1[0]=(8.1e-9 + 2*1.24e-11 + 0       + 3.8e-9)*1e6*ratioofBR[0]; // *1e6 is to set fa=1, not fa=1000
  xs_s1[1]=(8.71e-9 + 2*7.73e-10 + 1.3e-11 + 2.96e-10)*1e6*ratioofBR[1];
  xs_s1[2]=(9.22e-9 + 2*1.65e-10 + 5.8e-11 + 9.98e-10)*1e6*ratioofBR[2];
  xs_s1[3]=(9.27e-9 + 2*2.64e-10 + 1.47e-10 + 2.26e-9)*1e6*ratioofBR[3];
  xs_s1[4]=(7.29e-9 + 2*2.7e-10 + 1.98e-10 + 2.8e-9)*1e6*ratioofBR[4];
  xs_s1[5]=(5.32e-9 + 2*2.22e-10 + 1.82e-10 + 2.35e-9)*1e6*ratioofBR[5];
  xs_s1[6]=(3.8e-9 + 2*1.7e-10 + 1.49e-10 + 1.7e-9)*1e6*ratioofBR[6];
  xs_s1[7]=(2.65e-9 + 2*1.24e-11 + 1.14e-10 + 1.09e-9)*1e6*ratioofBR[7];
  xs_s1[8]=(1.79e-9 + 2*8.7e-11 + 8.23e-11 + 6.06e-10)*1e6*ratioofBR[8];
  xs_s1[9]=(1.15e-9 + 2*5.75e-11 + 5.58e-11 + 2.7e-10)*1e6*ratioofBR[9];
  xs_s1[10]=(6.7e-10 + 2*3.43e-11 + 3.4e-11 + 8.64e-11)*1e6*ratioofBR[10];
  xs_s1[11]=(3.035e-10 + 2*1.58e-11 + 1.6e-11 + 1.14e-11)*1e6*ratioofBR[11];

  xs_s2[0]=(1.58e-10 + 2*7.3e-10 + 2*1.64e-10 + 5.25e-10)*1e6*ratioofBR[0]; // *1e6 is to set fa=1, not fa=1000
  xs_s2[1]=(3.8e-10 + 2*8.06e-10 + 2*2.04e-10 + 6.32e-10)*1e6*ratioofBR[1];
  xs_s2[2]=(9.5e-10 + 2*8.01e-10 + 2*2.178e-10 + 6.6e-10)*1e6*ratioofBR[2];
  xs_s2[3]=(2.6e-9 + 2*7.36e-10 + 2*2.182e-10 + 6.5e-10)*1e6*ratioofBR[3];
  xs_s2[4]=(2.3e-9 + 2*5.65e-10 + 2*1.87e-10 + 5.1e-10)*1e6*ratioofBR[4];
  xs_s2[5]=(2.0e-9 + 2*4.18e-10 + 2*1.47e-10 + 3.56e-10)*1e6*ratioofBR[5];
  xs_s2[6]=(1.6e-9 + 2*3.03e-10 + 2*1.1e-10 + 2.28e-10)*1e6*ratioofBR[6];
  xs_s2[7]=(1.1e-9 + 2*2.12e-10 + 2*7.75e-11 + 1.3e-10)*1e6*ratioofBR[7];
  xs_s2[8]=(7.0e-10 + 2*1.39e-10 + 2*5.17e-11 + 6.3e-11)*1e6*ratioofBR[8];
  xs_s2[9]=(3.5e-10 + 2*8.4e-11 + 2*3.12e-11 + 2.4e-11)*1e6*ratioofBR[9];
  xs_s2[10]=(1.2e-10 + 2*4.25e-11 + 2*1.58e-11 + 5.46e-12)*1e6*ratioofBR[10];
  xs_s2[11]=(1.8e-11 + 2*1.27e-11 + 2*4.73e-12 + 3.6e-13)*1e6*ratioofBR[11];


  vector<double> f_a(12,0);
   
  for(int i = 0 ; i<benchmarknumber ; ++i){
    xs_b1[i]=1*1.344*countnumber_bkg11[i+1]/countnumber_bkg11[0] + 1*0.00242*countnumber_bkg12[i+1]/countnumber_bkg12[0] + 1*4.16e-5*countnumber_bkg13[i+1]/countnumber_bkg13[0] + 1*6.56e-6*countnumber_bkg14[i+1]/countnumber_bkg14[0] + 1*0.057*countnumber_bkg21[i+1]/countnumber_bkg21[0] + 1*0.00115*countnumber_bkg22[i+1]/countnumber_bkg22[0] + 1*6e-5*countnumber_bkg23[i+1]/countnumber_bkg23[0] + 1*8.8e-6*countnumber_bkg24[i+1]/countnumber_bkg24[0] + 1*3e-3*countnumber_bkg25[i+1]/countnumber_bkg25[0] + 0*0.00269*countnumber_bkg31[i+1]/countnumber_bkg31[0];
    
    xs_b2[i]=0.7*( 0*1.344*countnumber_bkg11[i+1]/countnumber_bkg11[0] + 0*0.00242*countnumber_bkg12[i+1]/countnumber_bkg12[0] + 0*4.16e-5*countnumber_bkg13[i+1]/countnumber_bkg13[0] + 0*6.56e-6*countnumber_bkg14[i+1]/countnumber_bkg14[0] + 0*0.057*countnumber_bkg21[i+1]/countnumber_bkg21[0] + 0*0.00115*countnumber_bkg22[i+1]/countnumber_bkg22[0] + 0*6e-5*countnumber_bkg23[i+1]/countnumber_bkg23[0] + 0*8.8e-6*countnumber_bkg24[i+1]/countnumber_bkg24[0] + 0.00269*countnumber_bkg31[i+1]/countnumber_bkg31[0] + 2*0.00342*countnumber_bkg32[i+1]/countnumber_bkg32[0] );
    // *0.7 refers to Z/W visible decay
    if (xs_b2[i] > 0){
      f_a[i]=sqrt(0.5*sqrt( ( xs_s1[i]*xs_s1[i]*1e7/xs_b1[i] ) + ( xs_s2[i]*xs_s2[i]*0.7*0.7*0.8*0.8*1e7/xs_b2[i] ) ));  // 0.7 is the visible branching ratio of W and Z. 0.8 is for reconstruction efficiency such as eta<2.5
    }
    std::cout <<"f_a:"<<f_a[i]<<std::endl;
  }
  
  
  
  
  
  
  // draw plot
  gStyle->SetPadLeftMargin(0.17); gStyle->SetPadRightMargin(0.05); gStyle->SetPadBottomMargin(0.15);
  gStyle->SetTitleFont(132, "xyz"); 
  gStyle->SetLabelFont(132, "xyz"); 
  gStyle->SetTextFont(132); 
  
  TColor *mumua_color = new TColor(9001,0.317647, 0.654902, 0.752941); //蓝色
  TColor *ff_color = new TColor(9002,0.705882, 0.494118, 0.545098); //褐色
  TColor *ww_color = new TColor(9003,0.1875, 0.54687, 0.347656);  //绿色
  
  
  TCanvas *c110 = new TCanvas();
  Mjj_plot_bkg1->SetStats(0);
  Mjj_plot_bkg2->SetStats(0);
  Mjj_plot_bkg3->SetStats(0);
  
  
  Mjj_plot_bkg1->SetLineColor(9002);
  Mjj_plot_bkg2->SetLineColor(9003);
  Mjj_plot_bkg3->SetLineColor(9001);
  //mCP_Eta_plot_signal3->SetLineColor(8);
  //mCP_Eta_plot_signal4->SetLineColor(4);
  //mCP_Eta_plot_signal5->SetLineColor(6);

  Mjj_plot_bkg1->SetLineWidth(2);
  Mjj_plot_bkg2->SetLineWidth(2);
  Mjj_plot_bkg3->SetLineWidth(2);
 
  
  Mjj_plot_bkg1->GetXaxis()->SetTitle("M_{jj} [TeV]");
  Mjj_plot_bkg1->GetYaxis()->SetTitle("d#sigma/dM_{jj} [pb/TeV]");
  Mjj_plot_bkg1->GetXaxis()->SetTitleSize(0.07);
  Mjj_plot_bkg1->GetYaxis()->SetTitleSize(0.07);
  Mjj_plot_bkg1->GetXaxis()->SetLabelSize(0.06);
  Mjj_plot_bkg1->GetYaxis()->SetLabelSize(0.06);
  Mjj_plot_bkg1->GetXaxis()->SetTitleFont(132);
  Mjj_plot_bkg1->GetYaxis()->SetTitleFont(132);
  Mjj_plot_bkg1->GetYaxis()->SetRangeUser(0.00001,1.0);
  
  Mjj_plot_bkg1->Draw("HIST");
  Mjj_plot_bkg2->Draw("HIST" "same");
  Mjj_plot_bkg3->Draw("HIST" "same");

  TLegend *l_Mjj_plot = new TLegend(0.8,0.7,0.95,0.9);
  l_Mjj_plot->AddEntry(Mjj_plot_bkg1,"#mu#mujj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg2,"#nu_{#mu}#nu_{#mu}jj","l");
  l_Mjj_plot->AddEntry(Mjj_plot_bkg3,"Vjj","l");
  l_Mjj_plot->SetTextFont(132);
  l_Mjj_plot->SetTextSize(0.05);
  l_Mjj_plot->Draw();
  
  
  c110->SetLogy();
  c110->SetTickx();
  c110->SetTicky();
  c110->SetGridx();
  //c110->SaveAs("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/plot_macro/output_plot/Mjj_bkg_plot_10TeV.pdf");
  
  
  
}