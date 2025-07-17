import model sm-full
generate mu+ mu- > z j j  
add process mu+ mu- > w- j j 
add process mu+ mu- > w+ j j 
output mumu2Vjj

# launch the run
launch mumu2Vjj -n 10TeV_mjj_130_9800   
update to_full
set hard_survey 2
set lpp1 0
set lpp2 0
set nevents 50000
set ebeam1 5000
set ebeam2 5000
# set cuts
set cut_decays True
set ptl -1
set etal -1
set ptj 10
set etaj 2.5
set pta -1
set eta_max_pdg {23:2.5, 24:2.5}
set drjj 0.4
set drjl 0.2
set drll 0.2
set mmjj 130
set mmjjmax 9800

launch mumu2Vjj -n 3TeV_mjj_130_2900   
update to_full
set hard_survey 2
set lpp1 0
set lpp2 0
set nevents 50000
set ebeam1 1500
set ebeam2 1500
# set cuts
set cut_decays True
set ptl -1
set etal -1
set ptj 10
set etaj 2.5
set pta -1
set eta_max_pdg {23:2.5, 24:2.5}
set drjj 0.4
set drjl 0.2
set drll 0.2
set mmjj 130
set mmjjmax 2900
