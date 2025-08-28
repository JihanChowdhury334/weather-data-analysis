set title 'Average Land Temperature By Month for 2000-2015'
set xlabel 'Month'
set ylabel 'Average Land Temperature (°C)'
set xtics ("Jan" 0, "Feb" 1, "Mar" 2, "Apr" 3, "May" 4, "Jun" 5, "Jul" 6, "Aug" 7, "Sep" 8, "Oct" 9, "Nov" 10, "Dec" 11)
set grid xtics ytics
set xrange [-1:12]
set yrange[0:16]
# Customizing colors
set style line 1 lc rgb '#4682B4' lt 1 lw 2 pt 7 ps 1.5   # blue
set style fill solid 0.5 border -1
set boxwidth 0.8

# Plotting data
plot "monthlyq10_averages.txt" using 0:2:3 with boxerrorbars title "Value with Uncertainty" linestyle 1
