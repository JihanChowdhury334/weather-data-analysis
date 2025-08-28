# Set title and labels
set title "Yearly Average Temperatures (1850-2015)"
set xlabel "Year"
set ylabel "Temperature (°C)"

# Set data range
set xrange [1850:2015]

# Define line styles and colors
set style line 1 lc rgb '#0060ad' lw 2
set style line 2 lc rgb '#dd181f' lw 1
set style line 3 lc rgb '#32cd32' lw 1

# Plot data
plot 'question_8_yearly_averages.txt' using 1:2 with lines ls 1 title 'Land Average Temperature', \
     'question_8_yearly_averages.txt' using 1:3 with lines ls 2 title 'Land Max Temperature', \
     'question_8_yearly_averages.txt' using 1:4 with lines ls 3 title 'Land Min Temperature'
