set title 'Average Land Temperature for 19th-20th Centuries'
set xlabel 'Year'
set ylabel 'Average Temperature'
plot 'century_19_20.txt' using 1:2 \
title '19th Century' with lp, \
'century_19_20.txt' using 1:3 \
title '20th Century' with lp, \