for i in 2 3 4 5 6 7 8 9; do
  hadd -f reFirstNtupleTestrun_z-${i}00_1pct_new.root reFirstNtupleTestrun_z-${i}00_1pct_new_*.root
done
