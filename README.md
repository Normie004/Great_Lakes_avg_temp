# Great Lakes Temperature Analysis (2022 & 2020)

## 📄 Description

This C program analyzes daily surface water temperature data for six of North America's Great Lakes (Superior, Michigan, Huron, Erie, Ontario, and St. Clair) from two separate years — **2022** and **2020**. The data is read from text files and the program answers a series of questions involving averages, extremes, seasonal comparisons, and temperature-based activity potential (like swimming).

---

## ✅ Features

The program performs the following operations:

### Question 1:

* Calculates **average annual temperatures** for each lake and for all six combined (2022 data).

### Question 2:

* Identifies the **coldest and warmest lakes** based on annual averages.
* Lists lakes **above and below** the combined average.

### Question 3:

* Reports the **coldest and warmest days** (with actual dates) for each lake in 2022.

### Question 4:

* Determines the **overall coldest and warmest temperatures** among all six lakes and their respective dates.

### Question 5:


## 🧠 How It Works

1. The program reads daily temperature data into arrays for each lake.
2. It performs necessary statistical calculations (min, max, average).
3. Dates are converted from day numbers (1–365) to MM-DD format using the `dayConversion2022()` function.
4. Seasonal analysis is done using index ranges (e.g., days 171–264 for summer).
5. Data from both years is compared to track changes in lake temperatures.



