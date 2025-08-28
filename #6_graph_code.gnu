set title 'Yearly Temperatures from 1760-2015'
set xlabel 'Year'
set ylabel 'Temperature'
set xrange [1750:2020]
plot 'yearly_averages.txt' every ::2 \
title 'Temperature' with lp