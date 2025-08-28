# Basic configuration
set title "Century Temperature Comparison"
set ylabel "Temperature (°C)"
set grid

# Custom X-axis
# We place each group of bars manually by specifying the x-axis positions
set style data boxes
set style fill solid 1
set boxwidth 0.1 absolute

# Explicitly set x-axis ticks
set xtics ("19" 19, "20" 20, "21" 21)

# Plot commands
# Calculate positions for the groups. We'll offset each bar in a group by a fixed amount.
plot 'question_9_data.txt' using ($1-0.2):2 with boxes lc rgb"blue" title 'LandAverageTemperature', \
     '' using ($1):3 with boxes lc rgb"red" title 'LandMaxTemperature', \
     '' using ($1+0.2):4 with boxes lc rgb"green" title 'LandMinTemperature'
