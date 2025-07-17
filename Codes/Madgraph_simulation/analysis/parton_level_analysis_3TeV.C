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

void parton_level_analysis_3TeV(){
  
  
  //TFile *f0 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_4_0/HZZ_bkg/h_signal/Events/run_03/unweighted_events.root");
  
  
  TFile *f1 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/3TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f2 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2mumujj/Events/3TeV_mjj_2TeV_2900GeV/unweighted_events.root");
  
  
  TFile *f5 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/3TeV_mjj_130GeV_2TeV/unweighted_events.root");
  
  TFile *f6 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2vmvmjj/Events/3TeV_mjj_2TeV_2900GeV/unweighted_events.root");

  TFile *f81 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj/Events/3TeV_eta_larger_2_5_v3/unweighted_events.root");

  TFile *f9 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/mumu2Vjj/Events/3TeV_eta_less_2_5_v3/unweighted_events.root");
  
  TFile *f10 = TFile::Open("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/bkg/aa2wjj/Events/3TeV_mjj_130_2900/unweighted_events.root");
  
  
  //TTree *s1 = (TTree*)f0->Get("LHEF");
  
  
  TTree *b11 = (TTree*)f1->Get("LHEF");
  TTree *b12 = (TTree*)f2->Get("LHEF");
  
  TTree *b21 = (TTree*)f5->Get("LHEF");
  TTree *b22 = (TTree*)f6->Get("LHEF");
  TTree *b25 = (TTree*)f81->Get("LHEF");

  TTree *b31 = (TTree*)f9->Get("LHEF");
  TTree *b32 = (TTree*)f10->Get("LHEF");

  //TTree *b4 = (TTree*)f4->Get("LHEF");
  
  //TTree *b5 = (TTree*)f5->Get("LHEF");
  
  

  //create histograms
  // TH1F *plotvariable_for_code = new TH1F("plot_name","plot_title",nbins,xlow,xup);
  
  
  
  
  
  /*TH1F *Mjj_plot_bkg1 = new TH1F("Mjj_plot_bkg1","",100,0,3);
  TH1F *Mjj_plot_bkg2 = new TH1F("Mjj_plot_bkg2","",100,0,3);
  
  TH1F *Mjj_plot_bkg3 = new TH1F("Mjj_plot_bkg3","",100,0,3);*/
  
	
  

  
	
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
  
  int entries21=b21->GetEntries();
  int entries22=b22->GetEntries();
  int entries25=b25->GetEntries();
  
  int entries31=b31->GetEntries();
  int entries32=b32->GetEntries();


  
  
  
  //std::cout <<"entries0:"<<entries0<<std::endl;
  std::cout <<"entries11:"<<entries11<<std::endl;
  std::cout <<"entries12:"<<entries12<<std::endl;

  std::cout <<"entries21:"<<entries21<<std::endl;
  std::cout <<"entries22:"<<entries22<<std::endl;
  std::cout <<"entries25:"<<entries25<<std::endl;

  std::cout <<"entries31:"<<entries31<<std::endl;
  std::cout <<"entries32:"<<entries31<<std::endl;
  
  
  
  vector<double> countnumber_bkg11(14,0);
  vector<double> countnumber_bkg12(14,0);
  
  vector<double> countnumber_bkg21(14,0);
  vector<double> countnumber_bkg22(14,0);
  vector<double> countnumber_bkg25(14,0);

  vector<double> countnumber_bkg31(14,0);
  vector<double> countnumber_bkg32(14,0);
  

  vector<double> countnumber_bkg1(1,0);
  vector<double> countnumber_bkg2(1,0);
  
  vector<double> benchmark_mass(13,0);

  std::cout << "init countnumber_bkg11[0] = " << countnumber_bkg11[0] << std::endl;
  std::cout << "init countnumber_bkg12[0] = " << countnumber_bkg12[0] << std::endl;
  std::cout << "init countnumber_bkg21[0] = " << countnumber_bkg21[0] << std::endl;
  std::cout << "init countnumber_bkg22[0] = " << countnumber_bkg22[0] << std::endl;
  std::cout << "init countnumber_bkg31[0] = " << countnumber_bkg31[0] << std::endl;

  benchmark_mass[0]=200;
  benchmark_mass[1]=300;
  benchmark_mass[2]=500;
  benchmark_mass[3]=800;
  benchmark_mass[4]=1000;
  benchmark_mass[5]=1200;
  benchmark_mass[6]=1500;
  benchmark_mass[7]=1800;
  benchmark_mass[8]=2000;
  benchmark_mass[9]=2200;
  benchmark_mass[10]=2500;
  benchmark_mass[11]=2700;
  benchmark_mass[12]=2900;

  int benchmarknumber = 13;
  
  //////////////////////////sample 11//////////////////////////////////////////////////////////////////////
  double weight_bkg11 = 0.717/50000.0;
  countnumber_bkg11[0]=entries11;
  for (int i=0; i<entries11; ++i){
    b11->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
    if(i==39526){
      std::cout <<"test10"<<std::endl;
    }
    if(i==39526){
      std::cout <<"test10"<<std::endl;
      //continue;
    }
    //
    // Apply cut
    if(i==49526){
      std::cout <<"test10"<<std::endl;
    }
    int j1_index = 4;
    int j2_index = 5;
    
    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg11);
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
  double weight_bkg12 = 0.0002165/50000.0;
  countnumber_bkg12[0]=entries12;
  for (int i=0; i<entries12; ++i){
    b12->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg1->Fill((j1+j2).M()/1000,weight_bkg12);
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

  
  //////////////////////////sample 21//////////////////////////////////////////////////////////////////////
  double weight_bkg21 = 0.0286/50000.0;
  countnumber_bkg21[0]=entries21;
  for (int i=0; i<entries21; ++i){
    b21->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg21);
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
  double weight_bkg22 = 0.0002106/50000.0;
  countnumber_bkg22[0]=entries22;
  for (int i=0; i<entries22; ++i){
    b22->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    
    // Apply cut
    
    int j1_index = 4;
    int j2_index = 5;

    j1.SetPtEtaPhiM(Particle_PT[j1_index],Particle_Eta[j1_index],Particle_Phi[j1_index],0);
    j2.SetPtEtaPhiM(Particle_PT[j2_index],Particle_Eta[j2_index],Particle_Phi[j2_index],0);
    if (abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5) {
      //Mjj_plot_bkg2->Fill((j1+j2).M()/1000,weight_bkg22);
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



  //////////////////////////sample 25//////////////////////////////////////////////////////////////////////
  double weight_bkg25 = 0.022/20000.0;
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
  double weight_bkg31 = 0.02112/50000.0;
  countnumber_bkg31[0]=entries31;
  for (int i=0; i<entries31; ++i){
    b31->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    
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
      if((j1+j2).M() > benchmark_mass[j]-benchmark_mass[j]*0.05 && (j1+j2).M() < benchmark_mass[j]+benchmark_mass[j]*0.05 && abs(j1.Eta())<2.5 && abs(j2.Eta())<2.5 && abs(Particle_Eta[j0_index]) < 2.5 && (Particle_PID[j0_index] == 23 || Particle_PID[j0_index] == 24 || Particle_PID[j0_index] == -24)) {
        countnumber_bkg31[j+1]=countnumber_bkg31[j+1]+1;

      }
    }
      
    
  }
  std::cout <<"pass31"<<std::endl;




  //////////////////////////sample 32//////////////////////////////////////////////////////////////////////
  double weight_bkg32 = 2*0.00197/50000.0;
  countnumber_bkg32[0]=entries32;
  for (int i=0; i<entries32; ++i){
    b32->GetEntry(i);
    TLorentzVector j1;
    TLorentzVector j2;
	  
    
    //countnumber_bkg32[0]+=1;
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
  std::cout <<"passtest1"<< std::endl;

  std::cout <<"Total_bkg12:"<<countnumber_bkg12[0]<<"->"<<countnumber_bkg12[0]/countnumber_bkg12[0]<<std::endl;
  for (int i = 0; i< benchmarknumber; ++i){
    std::cout <<"m_"<<benchmark_mass[i]<<":"<<countnumber_bkg12[i+1]<<"->"<<countnumber_bkg12[i+1]/countnumber_bkg12[0]<<std::endl;
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
  vector<double> ratioofBR(13,0);
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
  ratioofBR[12]=9.69e-01/2.157e-03;
  // compute significance
  vector<double> xs_b1(13,0);
  vector<double> xs_b2(13,0);
  vector<double> xs_s1(13,0);
  vector<double> xs_s2(13,0);
  //*1e6 because fa=1000; mumuax(aa2ax,2*za2ax,zz2ax) + vmvmax
  xs_s1[0]=(6.9e-9 + 2*1.05e-11 + 2.05e-13 + 2.16e-9)*1e6*ratioofBR[0];
  xs_s1[1]=(6.87e-9 + 2*6.10e-11 + 1.03e-11 + 2.25e-9)*1e6*ratioofBR[1];
  xs_s1[2]=(6.03e-9 + 2*1.08e-10 + 3.78e-11 + 1.87e-9)*1e6*ratioofBR[2];
  xs_s1[3]=(4.52e-9 + 2*1.14e-10 + 5.65e-11 + 1.32e-9)*1e6*ratioofBR[3];
  xs_s1[4]=(3.66e-9 + 2*1.04e-10 + 5.79e-11 + 1.0e-9)*1e6*ratioofBR[4];
  xs_s1[5]=(2.93e-9 + 2*9.05e-11 + 5.47e-11 + 7.38e-10)*1e6*ratioofBR[5];
  xs_s1[6]=(2.06e-9 + 2*6.94e-11 + 4.57e-11 + 4.3e-10)*1e6*ratioofBR[6];
  xs_s1[7]=(1.40e-9 + 2*5.02e-11 + 3.52e-11 + 2.18e-10)*1e6*ratioofBR[7];
  xs_s1[8]=(1.05e-9 + 2*3.91e-11 + 2.83e-11 + 1.24e-10)*1e6*ratioofBR[8];
  xs_s1[9]=(7.64e-10 + 2*2.93e-11 + 2.18e-11 + 6.14e-11)*1e6*ratioofBR[9];
  xs_s1[10]=(4.23e-10 + 2*1.68e-11 + 1.3e-11 + 1.37e-11)*1e6*ratioofBR[10];
  xs_s1[11]=(2.39e-10 + 2*9.69e-12 + 7.6e-12 + 2.52e-12)*1e6*ratioofBR[11];
  xs_s1[12]=(7.6e-11 + 2*3.16e-12 + 2.5e-12 + 2.36e-14)*1e6*ratioofBR[12]; 

  //*1e6 because fa=1000; zax + 2*aw2wax + 2*zw2wax + ww2zax
  xs_s2[0]=(1.5e-9 + 2*2.13e-10 + 2*3.8e-11 + 1.16e-10)*1e6*ratioofBR[0];
  xs_s2[1]=(2.58e-9 + 2*1.9e-10 + 2*3.8e-11 + 1.12e-10)*1e6*ratioofBR[1];
  xs_s2[2]=(2.44e-9 + 2*1.55e-10 + 2*3.42e-11 + 9.42e-11)*1e6*ratioofBR[2];
  xs_s2[3]=(2.13e-9 + 2*1.13e-10 + 2*2.78e-11 + 6.74e-11)*1e6*ratioofBR[3];
  xs_s2[4]=(1.87e-9 + 2*9.15e-11 + 2*2.35e-11 + 5.12e-11)*1e6*ratioofBR[4];
  xs_s2[5]=(1.58e-9 + 2*7.33e-11 + 2*1.95e-11 + 3.74e-11)*1e6*ratioofBR[5];
  xs_s2[6]=(1.12e-9 + 2*5.06e-11 + 2*1.4e-11 + 2.05e-11)*1e6*ratioofBR[6];
  xs_s2[7]=(6.95e-10 + 2*3.28e-11 + 2*9.25e-12 + 9.38e-12)*1e6*ratioofBR[7];
  xs_s2[8]=(4.53e-10 + 2*2.32e-11 + 2*6.62e-12 + 4.75e-12)*1e6*ratioofBR[8];
  xs_s2[9]=(2.259e-10 + 2*1.51e-11 + 2*4.35e-12 + 1.96e-12)*1e6*ratioofBR[9];
  xs_s2[10]=(7.28e-11 + 2*5.8e-12 + 2*1.7e-12 + 2.51e-13)*1e6*ratioofBR[10];
  xs_s2[11]=(4.6e-11 + 2*1.74e-12 + 2*5.1e-13 + 1.74e-14)*1e6*ratioofBR[11];
  xs_s2[12]=(5.3e-14 + 2*9.01e-15 + 2*2.69e-15 + 2.14e-20)*1e6*ratioofBR[12];


  vector<double> f_a(13,0);
   
  for(int i = 0 ; i<benchmarknumber ; ++i){
    xs_b1[i]=0.717*countnumber_bkg11[i+1]/countnumber_bkg11[0] + 0.0002165*countnumber_bkg12[i+1]/countnumber_bkg12[0] + 0.0286*countnumber_bkg21[i+1]/countnumber_bkg21[0] + 0.0002106*countnumber_bkg22[i+1]/countnumber_bkg22[0] + 0.022*countnumber_bkg25[i+1]/countnumber_bkg25[0] + 0.0*0.0221*countnumber_bkg31[i+1]/countnumber_bkg31[0];
    xs_b2[i]=0.7*( 0*0.717*countnumber_bkg11[i+1]/countnumber_bkg11[0] + 0*0.0002165*countnumber_bkg12[i+1]/countnumber_bkg12[0] + 0*0.0286*countnumber_bkg21[i+1]/countnumber_bkg21[0] + 0*0.0002106*countnumber_bkg22[i+1]/countnumber_bkg22[0] + 0.02112*countnumber_bkg31[i+1]/countnumber_bkg31[0] + 2*0.00197*countnumber_bkg32[i+1]/countnumber_bkg32[0] );
    if (xs_b2[i] == 0){
      f_a[i]=sqrt(xs_s1[i]*0.7*1e6/3); // 0.7 is the branching ratio of W/Z visible decay
    }
    if (xs_b2[i] > 0){
      f_a[i]=sqrt(0.5*sqrt( ( xs_s1[i]*xs_s1[i]*1e6/xs_b1[i] ) + ( xs_s2[i]*xs_s2[i]*0.7*0.7*0.8*0.8*1e6/xs_b2[i] ) ));  // 0.7 is the visible branching ratio of W and Z. 0.8 is for reconstruction efficiency such as eta<2.5
    }
    std::cout <<"f_a:"<<f_a[i]<<std::endl;
  }
  
  
  
  
  
  
  // draw plot
  /*
  gStyle->SetPadLeftMargin(0.17); gStyle->SetPadRightMargin(0.05); gStyle->SetPadBottomMargin(0.15);
  gStyle->SetTitleFont(132, "xyz"); 
  gStyle->SetLabelFont(132, "xyz"); 
  gStyle->SetTextFont(132); 
  
  TColor *mumua_color = new TColor(9001,0.317647, 0.654902, 0.752941); 
  TColor *ff_color = new TColor(9002,0.705882, 0.494118, 0.545098); 
  TColor *ww_color = new TColor(9003,0.1875, 0.54687, 0.347656);
  
  
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
  c110->SaveAs("/mnt/e/Madgraph/MG5_aMC_v3_5_8/research/axion_muc/plot_macro/output_plot/Mjj_bkg_plot_3TeV.pdf");*/
  
  
 
  
  
}