import model sm-full
set group_subprocesses false
generate a a > w+ j j
add process a a > w- j j
output aa2wjj

# launch the run
launch aa2wjj -n 10TeV_mjj_130_9800
update to_full
set hard_survey 2
set lpp1 -4
set lpp2 4
set nevents 10000
set ebeam1 5000
set ebeam2 5000
set pdlabel1 eva
set pdlabel2 eva
set fixed_fac_scale1 False
set fixed_fac_scale2 False
set dynamical_scale_choice 4
set scalefact 0.5
set dsqrt_shat 100.0
# set cuts
set ptj 10
set etaj 2.5
set drjj 0.4
set mmjj 130
set mmjjmax 9800

launch aa2wjj -n 3TeV_mjj_130_2900
update to_full
set hard_survey 2
set lpp1 -4
set lpp2 4
set nevents 10000
set ebeam1 1500
set ebeam2 1500
set pdlabel1 eva
set pdlabel2 eva
set fixed_fac_scale1 False
set fixed_fac_scale2 False
set dynamical_scale_choice 4
set scalefact 0.5
set dsqrt_shat 100.0
# set cuts
set ptj 10
set etaj 2.5
set drjj 0.4
set mmjj 130
set mmjjmax 2900
