import model ALP_linear_UFO_SK
set group_subprocesses false
generate z z > ax WEIGHTED<=20 , ax > a a
output zz2ax_parton

# launch the run
# Ma=200 GeV
launch zz2ax_parton -n m_200GeV
analysis = OFF
# set parameters
set mass 9000005 200
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=300 GeV
launch zz2ax_parton -n m_300GeV
analysis = OFF
# set parameters
set mass 9000005 300
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5

# Ma=500 GeV
launch zz2ax_parton -n m_500GeV
analysis = OFF
# set parameters
set mass 9000005 500
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=1000 GeV
launch zz2ax_parton -n m_1000GeV
analysis = OFF
# set parameters
set mass 9000005 1000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=2000 GeV
launch zz2ax_parton -n m_2000GeV
analysis = OFF
# set parameters
set mass 9000005 2000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=3000 GeV
launch zz2ax_parton -n m_3000GeV
analysis = OFF
# set parameters
set mass 9000005 3000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=4000 GeV
launch zz2ax_parton -n m_4000GeV
analysis = OFF
# set parameters
set mass 9000005 4000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=5000 GeV
launch zz2ax_parton -n m_5000GeV
analysis = OFF
# set parameters
set mass 9000005 5000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=6000 GeV
launch zz2ax_parton -n m_6000GeV
analysis = OFF
# set parameters
set mass 9000005 6000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=7000 GeV
launch zz2ax_parton -n m_7000GeV
analysis = OFF
# set parameters
set mass 9000005 7000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=8000 GeV
launch zz2ax_parton -n m_8000GeV
analysis = OFF
# set parameters
set mass 9000005 8000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5


# Ma=9000 GeV
launch zz2ax_parton -n m_9000GeV
analysis = OFF
# set parameters
set mass 9000005 9000
set caphi 0.0
# alpha_s(mz)=0.118 alpha_s/8pi=0.0046951
set cgtil 0.0046951  
# alpha_1(mz)=0.0102 alpha_s/8pi=0.0004058
set cbtil 0.0004058  
# alpha_2(mz)=0.03393 alpha_s/8pi=0.00135
set cwtil 0.00135    
update to_full
set hard_survey 4
set run_tag signal
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
set width 9000005 Auto
set bwcutoff 15.0
set cut_decays True
set ptl -1
set etal -1
set pta 10
set etaa 2.5
