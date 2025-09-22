# 🌍 Climate Data Analysis in C (1750–2015)

Analyze real-world climate records spanning from **1750 to 2015** using C and GNUPlot.  
This project demonstrates importing large CSV datasets, computing averages, identifying extremes, and generating clear visualizations of temperature trends over centuries.

---

## 🚀 Features & Functionality
- **Data Import & Parsing**
  - Reads global temperature data from `GlobalTemperatures.csv`.  
  - Extracts year, month, mean temperature, max, min, uncertainty, and ocean values.  

- **Yearly & Century Averages**
  - Computes yearly averages from 1760–2015.  
  - Aggregates century-wise averages for 18th, 19th, 20th, and 21st centuries.  

- **Monthly Trends**
  - Calculates average temperature for each month (Jan–Dec).  
  - Evaluates patterns across decades and modern years.  

- **Temperature Extremes**
  - Identifies hottest and coldest **months** in the dataset.  
  - Tracks hottest and coldest **years**.  

- **Comparisons & Visualizations**
  - 19th vs 20th century yearly trends (century_19_20.txt).  
  - Annual averages with min/max bands (Q8).  
  - Century-wise min/max/avg comparisons (Q9).  
  - Monthly averages with uncertainty (Q10).  
  - Land vs ocean averages (Q11).  

- **Graphing with GNUPlot**
  - Includes scripts (`#6_graph_code.gnu` → `#11.gnu`) for generating line graphs, comparative charts, and uncertainty plots.  
  - Visualizes historical trends and modern climate shifts with clarity.  

---

## 🧠 What I Practiced & Learned
- **C Programming**
  - File handling with `fopen`, `fgets`, and `sscanf`.  
  - Arrays for aggregating yearly, monthly, and century data.  
  - Structured modular logic for multiple statistical outputs.  

- **Data Analysis Concepts**
  - Averaging over different timescales.  
  - Tracking extremes (hottest/coldest values).  
  - Handling incomplete or uncertain data.  

- **GNUPlot**
  - Automating scientific plotting with `.gnu` scripts.  
  - Comparing datasets with multi-line graphs.  
  - Highlighting trends with error/uncertainty visualization.  

- **Project Workflow**
  - Parsing CSVs into usable structures.  
  - Writing results into multiple `.txt` files.  
  - Feeding outputs into GNUPlot for visualization.  

---

## 📂 Project Structure
```
CPS_PROJECT.c             # Main C program
GlobalTemperatures.csv    # Dataset (1750–2015)
#6_graph_code.gnu         # GNUPlot script Q6
#7_graph_code.gnu         # GNUPlot script Q7
#8_graph_code.gnu         # GNUPlot script Q8
#9_graph_code.gnu         # GNUPlot script Q9
#10.gnu                   # GNUPlot script Q10
#11.gnu                   # GNUPlot script Q11
```

Generated outputs:
```
yearly_averages.txt
century_averages.txt
monthly_averages.txt
century_19_20.txt
question_8_yearly_averages.txt
question_9_data.txt
monthlyq10_averages.txt
yearlyq11_averages.txt
```

---

## 🛠️ Compilation & Usage
```bash
# Compile
gcc CPS_PROJECT.c -o climate_analysis

# Run
./climate_analysis

# Generate graphs with GNUPlot
gnuplot #6_graph_code.gnu
gnuplot #7_graph_code.gnu
...
gnuplot #11.gnu
```

---

## 🎯 Purpose
This project is **not production-ready**, but a **computational learning project** aimed at practicing:  
- CSV parsing in C  
- Statistical aggregation across different timescales  
- Using GNUPlot for visualization  
- Exploring climate change trends over centuries  

---
