import model sm-full
generate mu+ mu- > vm vm~ j j 
output mumu2vmvmjj

# launch the run
launch mumu2vmvmjj -n 10TeV_mjj_130GeV_2TeV   
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
set drjj 0.4
set mmjj 130
set mmjjmax 2000

launch mumu2vmvmjj -n 10TeV_mjj_2TeV_6TeV   
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
set drjj 0.4
set mmjj 2000
set mmjjmax 6000

launch mumu2vmvmjj -n 10TeV_mjj_6TeV_9500GeV   
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
set drjj 0.4
set mmjj 6000
set mmjjmax 9500

launch mumu2vmvmjj -n 10TeV_mjj_9500GeV_9900GeV   
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
set drjj 0.4
set mmjj 9500
set mmjjmax 9900

launch mumu2vmvmjj -n 3TeV_mjj_130GeV_2TeV   
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
set drjj 0.4
set mmjj 130
set mmjjmax 2000

launch mumu2vmvmjj -n 3TeV_mjj_2TeV_2900GeV   
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
set drjj 0.4
set mmjj 2000
set mmjjmax 2900