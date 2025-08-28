set title "Yearly Average Land and Ocean Temperatures (1850-2015)"
set xlabel "Year"
set ylabel "Temperature (°C)"


set xrange [1850:2015]


set style line 1 lc rgb '#0060ad' lw 2
set style line 2 lc rgb '#dd181f' lw 1


plot 'yearlyq11_averages.txt' using 1:2 with lines ls 1 title 'Average Land Temperature', \
     'yearlyq11_averages.txt' using 1:3 with lines ls 2 title 'Average Land and Ocean Temperature'