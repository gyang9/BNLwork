for i in -1 -0.5 0 0.5 1 1.5 2 2.5 3; do
  for j in 0 0.1 0.2 0.3 0.5; do
    echo "------------------------------------------------------------ "
    echo "time cut for wbls $i"
    echo "fitting result no less than $j"
    root -l -q plot_tracking.C $i $j
    echo "------------------------------------------------------------ "
  done
done
