#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_YEAR 1760
#define END_YEAR 2015
#define START_YEAR2 1850
#define END_YEAR2 2015

const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main(void) {
    FILE *GlobalTempsFile = fopen("GlobalTemperatures.csv", "r");
    if (GlobalTempsFile == NULL) {
        printf("Error: could not open file\n");
        exit(-1);
    }

    char buffer[1000];
    char year_str[5], month_str[3];
    int year, month;
    float temperature;
    float yearly_sum[END_YEAR - START_YEAR + 1] = {0};
    int yearly_count[END_YEAR - START_YEAR + 1] = {0};
    float century_sum[4] = {0};
    int century_count[4] = {0};
    float monthly_sum[12] = {0};
    int monthly_count[12] = {0};
    float hottest_temperature = 0;
    float coldest_temperature = 100;
    char hottest_month[20];
    char coldest_month[20];
    int hottest_year, coldest_year;
    float hottest_year_temp = 0;
    float coldest_year_temp = 1000;
    int hottest_year_recorded;
    int coldest_year_recorded;
    double c_19[100];
    double c_20[100];

    for (int i = 0; i < 121; i++) {
        fgets(buffer, sizeof(buffer), GlobalTempsFile);
    }

    while(fgets(buffer, sizeof(buffer), GlobalTempsFile)) {
        sscanf(buffer, "%4s-%2s-%*2s,%f", year_str, month_str, &temperature);
        year = atoi(year_str);
        month = atoi(month_str);
        if (year >= START_YEAR && year <= END_YEAR) {
            int index = year - START_YEAR;
            yearly_sum[index] += temperature;
            yearly_count[index]++;

            if (year >= 1760 && year <= 1799) {
                century_sum[0] += temperature;
                century_count[0]++;
            } else if (year >= 1800 && year <= 1899) {
                century_sum[1] += temperature;
                century_count[1]++;
                c_19[year-1800] = temperature;
            } else if (year >= 1900 && year <= 1999) {
                century_sum[2] += temperature;
                century_count[2]++;
                c_20[year-1900] = temperature;
            } else if (year >= 2000 && year <= 2015) {
                century_sum[3] += temperature;
                century_count[3]++;
            }

            int month_index = month - 1;
            if (year >= 1900 && year <= 2015) {
                monthly_sum[month_index] += temperature;
                monthly_count[month_index]++;
            }

            if (temperature > hottest_temperature) {
                hottest_temperature = temperature;
                strcpy(hottest_month, months[month_index]);
                hottest_year = year;
            }
            if (temperature < coldest_temperature) {
                coldest_temperature = temperature;
                strcpy(coldest_month, months[month_index]);
                coldest_year = year;
            }
        }
    }

    FILE *century_19_20 = fopen("century_19_20.txt", "w");

    for (int i = 0; i < 100; i++) {
        fprintf(century_19_20, "%d %lf %lf\n", i, c_19[i], c_20[i]);
    }

    fclose(century_19_20);
    fclose(GlobalTempsFile);

    FILE *yearly_file = fopen("yearly_averages.txt", "w");
    if (yearly_file == NULL) {
        fprintf(stderr, "Error opening yearly averages file.\n");
        return 1;
    }
    fprintf(yearly_file, "Year\tAverage Temperature\n");
    for (int i = 0; i < END_YEAR - START_YEAR + 1; i++) {
        if (yearly_count[i] > 0) {
            float average_temperature = yearly_sum[i] / yearly_count[i];
            fprintf(yearly_file, "%d\t%.2f\n", START_YEAR + i, average_temperature);

            if (average_temperature > hottest_year_temp) {
                hottest_year_temp = average_temperature;
                hottest_year_recorded = START_YEAR + i;
            }
            if (average_temperature < coldest_year_temp) {
                coldest_year_temp = average_temperature;
                coldest_year_recorded = START_YEAR + i;
            }
        }
    }
    fclose(yearly_file);

    FILE *century_file = fopen("century_averages.txt", "w");
    if (century_file == NULL) {
        fprintf(stderr, "Error opening century averages file.\n");
        return 1;
    }
    fprintf(century_file, "Century\tAverage Temperature\n");
    for (int i = 0; i < 4; i++) {
        if (century_count[i] > 0) {
            float average_temperature = century_sum[i] / century_count[i];
            fprintf(century_file, "%dth\t%.2f\n", i + 18, average_temperature);
        }
    }
    fclose(century_file);

    FILE *monthly_file = fopen("monthly_averages.txt", "w");
    if (monthly_file == NULL) {
        fprintf(stderr, "Error opening century averages file.\n");
        return 1;
    }
    fprintf(monthly_file, "Month\tAverage Temperature\n");
    for (int i = 0; i < 12; i++) {
        if (monthly_count[i] > 0) {
            float average_temperature = monthly_sum[i] / monthly_count[i];
            fprintf(monthly_file, "%s\t%.2f\n", months[i], average_temperature);
        }
    }
    fclose(monthly_file);
    printf("Yearly, century, and monthly averages written to files successfully!\n");
    printf("Hottest month: %s %d (Average Temperature: %.2f)\n", hottest_month, hottest_year, hottest_temperature);
    printf("Coldest month: %s %d (Average Temperature: %.2f)\n", coldest_month, coldest_year, coldest_temperature);
    printf("Hottest year: %d (Average Temperature: %.2f)\n", hottest_year_recorded, hottest_year_temp);
    printf("Coldest year: %d (Average Temperature: %.2f)\n", coldest_year_recorded, coldest_year_temp);

    char year_str2[5], month_str2[3];
    float temperature_max;
    float temperature_min;
    float bull;
    float yearly_sum2[END_YEAR2 - START_YEAR2 + 1] = {0};
    float yearly_sum_max[END_YEAR2 - START_YEAR2 + 1] = {0};
    float yearly_sum_min[END_YEAR2 - START_YEAR2 + 1] = {0};
    int yearly_count2[END_YEAR2 - START_YEAR2 + 1] = {0};

    FILE *GlobalFile = fopen("GlobalTemperatures.csv", "r");
    if (GlobalFile == NULL) {
        printf("Error: could not open file\n");
        exit(-1);
    }

    for (int i = 0; i < 1201; i++) {
        fgets(buffer, sizeof(buffer), GlobalFile);
    }

    while(fgets(buffer, sizeof(buffer), GlobalFile)) {
        sscanf(buffer, "%4s-%2s-%*2s,%f,%f,%f,%f,%f", year_str2, month_str2, &temperature, &bull, &temperature_max, &bull, &temperature_min);
        year = atoi(year_str2);
        if (year >= START_YEAR2 && year <= END_YEAR2) {
            int index = year - START_YEAR2;
            yearly_sum2[index] += temperature;
            yearly_sum_max[index] += temperature_max;
            yearly_sum_min[index] += temperature_min;
            yearly_count2[index]++;
        }
    }

    FILE *yearly_q8__file = fopen("question_8_yearly_averages.txt", "w");
    if (yearly_q8__file == NULL) {
        fprintf(stderr, "Error opening yearly averages file.\n");
        return 1;
    }
    for (int i = 0; i < END_YEAR2 - START_YEAR2 + 1; i++) {
        if (yearly_count2[i] > 0) {
            float average_temperature2 = yearly_sum2[i] / yearly_count2[i];
            float average_temperature_max = yearly_sum_max[i] / yearly_count2[i];
            float average_temperature_min = yearly_sum_min[i] / yearly_count2[i];
            fprintf(yearly_q8__file, "%d\t%.2f\t%.2f\t%.2f\n", START_YEAR2 + i, average_temperature2, average_temperature_max, average_temperature_min);
        }
    }
    fclose(yearly_q8__file);
    fclose(GlobalFile);

    return 0;
}
