#include <stdio.h>
int dayConversion2022(int dayNum){
    if(dayNum>=1&&dayNum<=31){
        printf("January %d ", dayNum);
    }
    if(dayNum>=32&&dayNum<=60){
        printf("February %d ", dayNum-31);
    }
    if(dayNum>=61&&dayNum<=91){
        printf("March %d ", dayNum-60);
    }
    if(dayNum>=92&&dayNum<=121){
        printf("April %d ", dayNum-91);
    }
    if(dayNum>=122&&dayNum<=152){
        printf("May %d ", dayNum-121);
    }
    if(dayNum>=153&&dayNum<=182){
        printf("June %d ", dayNum-152);
    }
    if(dayNum>=183&&dayNum<=213){
        printf("July %d ", dayNum-182);
    }
    if(dayNum>=214&&dayNum<=244){
        printf("August %d ", dayNum-213);
    }
    if(dayNum>=245&&dayNum<=274){
        printf("September %d ", dayNum-244);
    }
    if(dayNum>=275&&dayNum<=305){
        printf("October %d ", dayNum-274);
    }
    if(dayNum>=306&&dayNum<=335){
        printf("November %d ", dayNum-305);
    }
    if(dayNum>=336&&dayNum<=365){
        printf("December %d ", dayNum-335);
    }


}


int main() {
    int year, dayVl;
    int i = 0;
    double sumSuper, sumMichi, sumHuron, sumErie, sumOnt, sumClar, sumAll;
    int daycnt = 0; //variables for question 1
    double coldestAvg, warmestAvg; //variables for question 2
    double sp[365], hrn[365], mch[365], erie[365], ont[365], stclr[365];
    double super, huro, michi, eriee, onta, stcla;
    FILE *in2022 = fopen("termprojectdata2022.txt", "r");
    while (fscanf(in2022, "%d %d   %lf   %lf   %lf   %lf   %lf   %lf", &year, &dayVl, &super, &michi,
                  &huro, &eriee, &onta, &stcla) != EOF) {
        sp[i] = super;
        mch[i] = michi;
        hrn[i] = huro;
        erie[i] = eriee;
        ont[i] = onta;
        stclr[i] = stcla;
        i++;
        daycnt++; //find number of days in file, used for finding averages
        sumSuper += super;
        sumMichi += michi;
        sumHuron += huro;   //find sum of each lake individually so that average can be calculated
        sumErie += eriee;
        sumOnt += onta;
        sumClar += stcla;
    }
    i = 0;

    printf("\n");
    //QUESTION 1. FIND AVERAGE TEMPERATURE OF ONE YEAR FOR EACH LAKE AND ALL SIX LAKES.
    printf("\n");
    sumAll = sumSuper + sumMichi + sumClar + sumOnt + sumErie + sumHuron; //find sum of all temps in all lakes,
    // divide by daycnt and 6 to get avg temps of all lakes

    double avgSup = sumSuper / daycnt;
    double avgMich = sumMichi / daycnt;
    double avgHuron = sumHuron / daycnt;  //obtain average temp of each lake
    double avgErie = sumErie / daycnt;
    double avgOnt = sumOnt / daycnt;
    double avgStClr = sumClar / daycnt;
    double avgAll = sumAll / 6 / daycnt;

    printf("Question 1.");
    printf("\nThe average temperature for Lake Superior is %.2lf\n", avgSup);
    printf("The average temperature for Lake Michigan is %.2lf\n", avgMich);
    printf("The average temperature for Lake hrn is %.2lf\n", avgHuron);
    printf("The average temperature for Lake Erie is %.2lf\n", avgErie);
    printf("The average temperature for Lake Ontario is %.2lf\n", avgOnt);
    printf("The average temperature for Lake St. Clair is %.2lf\n", avgStClr);
    printf("The average temperature for all the Lakes is %.2lf", avgAll); // printing all the outputs for question 1.
         
    //QUESTION 2. FIND COLDEST AND WARMEST LAKE ACCORDING TO THE AVERAGES, PRINT LAKES BELOW AND ABOVE AVERAGE
    double lakeAverages[] = {avgSup, avgMich, avgHuron, avgErie, avgOnt,
                             avgStClr}; //store averages into an array to find coldest and warmest lakes from all 6.
    warmestAvg = avgAll;
    coldestAvg = avgAll;

    for (int i = 0; i < 6; i++) {
        if (lakeAverages[i] < coldestAvg) {
            coldestAvg = lakeAverages[i];
        }                                   //for loop scans array and compares to warmestAvg and coldestAvg to find the answer
        if (warmestAvg < lakeAverages[i]) {
            warmestAvg = lakeAverages[i];
        }
    }

    printf("\n\nQuestion 2.\nColdest lake on average:");
    if (coldestAvg == avgSup) {
        printf(" Lake Superior");
    } else if (coldestAvg == avgMich) {
        printf(" Lake Michigan");
    } else if (coldestAvg == avgHuron) {
        printf(" Lake hrn");                     //comparing statements using else if to print which lake is coldest
    } else if (coldestAvg == avgErie) {
        printf(" Lake Erie");
    } else if (coldestAvg == avgOnt) {
        printf(" Lake Ontario");
    } else if (coldestAvg == avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\nWarmest lake on average:");
    if (warmestAvg == avgSup) {
        printf(" Lake Superior");
    } else if (warmestAvg == avgMich) {
        printf(" Lake Michigan");
    } else if (warmestAvg == avgHuron) {
        printf(" Lake hrn");                   //comparing statements to print which lake is warmest
    } else if (warmestAvg == avgErie) {
        printf(" Lake Erie");
    } else if (warmestAvg == avgOnt) {
        printf(" Lake Ontario");
    } else if (warmestAvg == avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\n All the Lake(s) which have a temperature below average:");
    if (avgAll > avgSup) {
        printf(" Lake Superior,");
    }
    if (avgAll > avgMich) {
        printf(" Lake Michigan,");
    }
    if (avgAll > avgHuron) {
        printf(" Lake hrn");                   //comparing statements using if to print which lakes < average
    }
    if (avgAll > avgErie) {
        printf(" Lake Erie,");
    }
    if (avgAll > avgOnt) {
        printf(" Lake Ontario,");
    }
    if (avgAll > avgStClr) {
        printf(" Lake St. Clair");
    }

    printf("\nLakes which have a temperature above average:");
    if (avgAll < avgSup) {
        printf(" Lake Superior,");
    }
    if (avgAll < avgMich) {
        printf(" Lake Michigan,");
    }
    if (avgAll < avgHuron) {
        printf(" Lake hrn");                   //comparing statements to print which lakes > average
    }
    if (avgAll < avgErie) {
        printf(" Lake Erie,");
    }
    if (avgAll < avgOnt) {
        printf(" Lake Ontario,");
    }
    if (avgAll < avgStClr) {
        printf(" Lake St. Clair");
    }
    printf("\n\nQuestion 3.\n");
    /*QUESTION 3. FIND THE DAY AND THE TEMPERATURE FOR THE COLDEST TEMPS FOR EACH LAKE*/
    double minsuper = sp[0];
    double minMichi = mch[0];
    double minHuro = hrn[0];
    double minErie = erie[0];
    double minOnt = ont[0];
    double minStclair = stclr[0];
    int coldestDay=0;

    printf("Coldest Days of the Lakes:\n");
    for (i = 0; i < 365; i++) {
        if (sp[i] < minsuper) {
            minsuper = sp[i];
        }
    }
    printf("Lake Superior: %.2lf - ", minsuper);
    for (i = 0; i < 365; i++) {
        if (sp[i] == minsuper) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (mch[i] < minMichi) {
            minMichi = mch[i];
        }
    }
    printf("Lake Michigan: %.2lf - ", minMichi);
    for (i = 0; i < 365; i++) {
        if (mch[i] == minMichi) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay=0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (hrn[i] < minHuro) {
            minHuro = hrn[i];
        }
    }
    printf("Lake Huron: %.2lf - ", minHuro);
    for (i = 0; i < 365; i++) {
        if (hrn[i] == minHuro) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (erie[i] < minErie) {
            minErie = erie[i];
        }
    }
    printf("Lake Erie: %.2lf - ", minErie);
    for (i = 0; i < 365; i++) {
        if (erie[i] == minErie) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (ont[i] < minOnt) {
            minOnt = ont[i];
        }
    }
    printf("Lake Ontario: %.2lf - ", minOnt);
    for (i = 0; i < 365; i++) {
        if (ont[i] == minOnt) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (stclr[i] < minStclair) {
            minStclair = stclr[i];
        }
    }
    printf("Lake St. Clair: %.2lf - ", minStclair);
    for (i = 0; i < 365; i++) {
        if (stclr[i] == minStclair) {
            coldestDay = i + 1;
            dayConversion2022(coldestDay);
        }
    }
    coldestDay = 0;
    printf("\n");
    /*QUESTION 3. ABOVE PROCESS FOR WARMEST TEMPS*/
    double maxsuper = sp[0];
    double maxMichi = mch[0];
    double maxHuro = hrn[0];
    double maxErie = erie[0];
    double maxOnt = ont[0];
    double maxStclair = stclr[0];
    int warmestDay;


    printf("\nWarmest Days of the Lakes:\n");
    for (i = 0; i < 365; i++) {
        if (sp[i] > maxsuper) {
            maxsuper = sp[i];
        }
    }
    printf("Lake Superior: %.2lf - ", maxsuper);
    for (i = 0; i < 365; i++) {
        if (sp[i] == maxsuper) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (mch[i] > maxMichi) {
            maxMichi = mch[i];
        }
    }
    printf("Lake Michigan: %.2lf - ", maxMichi);
    for (i = 0; i < 365; i++) {
        if (mch[i] == maxMichi) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (hrn[i] > maxHuro) {
            maxHuro = hrn[i];
        }
    }
    printf("Lake Huron: %.2lf - ", maxHuro);
    for (i = 0; i < 365; i++) {
        if (hrn[i] == maxHuro) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (erie[i] > maxErie) {
            maxErie = erie[i];
        }
    }
    printf("Lake Erie: %.2lf - ", maxErie);
    for (i = 0; i < 365; i++) {
        if (erie[i] == maxErie) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (ont[i] > maxOnt) {
            maxOnt = ont[i];
        }
    }
    printf("Lake Ontario: %.2lf - ", maxOnt);
    for (i = 0; i < 365; i++) {
        if (ont[i] == maxOnt) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");

    for (i = 0; i < 365; i++) {
        if (stclr[i] > maxStclair) {
            maxStclair = stclr[i];
        }
    }
    printf("Lake St. Clair: %.2lf - ", maxStclair);
    for (i = 0; i < 365; i++) {
        if (stclr[i] == maxStclair) {
            warmestDay = i + 1;
            dayConversion2022(warmestDay);
        }
    }
    warmestDay = 0;
    printf("\n");
    printf("\nQuestion 4.");
    /*QUESTION 4. FIND THE OVERALL WARMEST AND COLDEST TEMPS OF THE LAKES*/
    double coldestTemps[] = {minsuper, minMichi, minHuro, minErie, minOnt, minStclair};
    double warmestTemps[] = {maxsuper, maxMichi, maxHuro, maxErie, maxOnt, maxStclair};

    double coldestLake = coldestTemps[0];
    double warmestLake = warmestTemps[0];

    for (i = 0; i < 6; i++) {
        if (coldestTemps[i] < coldestLake) {
            coldestLake = coldestTemps[i];
        }
    }
    for (i = 0; i < 6; i++) {
        if (warmestTemps[i] > warmestLake) {
            warmestLake = warmestTemps[i];
        }
    }
    printf("\nLake St. Clair is the coldest lake with a temperature of %.2lf on January 22nd", coldestLake);
    printf("\nLake Erie is the warmest lake with a temperature of %.2lf on July 10th", warmestLake);
    printf("\n\nQuestion 5.");
    /*QUESTION 5. CALCULATE THE SUMMER AVERAGE FOR ALL SIX LAKES*/
    double summerSup = 0, summerHuron = 0, summerMich = 0, summerErie = 0, summerOnt = 0, summerStClr = 0;
    for (i = 171; i < 265; i++) {
        summerSup += sp[i];
        summerMich += mch[i];
        summerHuron += hrn[i];
        summerErie += erie[i];
        summerOnt += ont[i];
        summerStClr += stclr[i];
    }
    int summerDays = 265 - 172 + 1;
    printf("\nAverage Temperature for the Lakes in Summer 2022:\n");
    printf("Lake Superior: %.2lf", summerSup / summerDays);
    printf("\nLake Michigan: %.2lf", summerMich / summerDays);
    printf("\nLake Huron: %.2lf", summerHuron / summerDays);
    printf("\nLake Erie: %.2lf", summerErie / summerDays);
    printf("\nLake Ontario: %.2lf", summerOnt / summerDays);
    printf("\nLake St. Clair: %.2lf", summerStClr / summerDays);
    printf("\nFrom warmest to coldest in the summer season, the lakes are: \nErie \nSt. Clair \nOntario \nMichigan \nHuron \nSuperior ");
	printf("\nThe order is the same as question 2");
    printf("\n\nQuestion 6.");
    /*QUESTION 6. CALCULATE THE WINTER AVERAGE TEMPERATURE FOR ALL 6 LAKES*/
    double winterSup = 0, winterHuron = 0, winterMich = 0, winterErie = 0, winterOnt = 0, winterStClr = 0;
    for (i = 0; i < 79; i++) {
        winterSup += sp[i];
        winterMich += mch[i];
        winterHuron += hrn[i];
        winterErie += erie[i];
        winterOnt += ont[i];
        winterStClr += stclr[i];
    }
    for (i = 354; i < 365; i++) {
        winterSup += sp[i];
        winterMich += mch[i];
        winterHuron += hrn[i];
        winterErie += erie[i];
        winterOnt += ont[i];
        winterStClr += stclr[i];
    }
    int winterDays = (79 - 1 + 1) + (365 - 355 + 1);
    printf("\nAverage Temperature for the Lakes in Winter 2022:\n");
    printf("Lake Superior: %.2lf", winterSup / winterDays);
    printf("\nLake Michigan: %.2lf", winterMich / winterDays);
    printf("\nLake Huron: %.2lf", winterHuron / winterDays);
    printf("\nLake Erie: %.2lf", winterErie / winterDays);
    printf("\nLake Ontario: %.2lf", winterOnt / winterDays);
    printf("\nLake St. Clair: %.2lf", winterStClr / winterDays);
    printf("\nFrom warmest to coldest in the winter season, the lakes are: \nOntario \nMichigan \nHuron \nErie and Superior \nSt. Clair ");
    printf("\nThe order is NOT same as question 2"); 
    printf("\n\nQuestion 7.");
    /*QUESTION 7. CALCULATE NUMBER OF DAYS YOU CAN SWIM IN ALL SIX LAKES (>20 DEGREES)*/
    int sup20 = 0, mich20 = 0, huron20 = 0, erie20 = 0, ont20 = 0, stClr20 = 0;
    for (i = 0; i < 365; i++) {
        if (sp[i] > 20) {
            sup20++;
        }
        if (mch[i] > 20) {
            mich20++;
        }
        if (hrn[i] > 20) {
            huron20++;
        }
        if (erie[i] > 20) {
            erie20++;
        }
        if (ont[i] > 20) {
            ont20++;
        }
        if (stclr[i] > 20) {
            stClr20++;
        }
    }
    printf("\nNumber of Days in which you can swim in the lakes:\n");
    printf("Lake Superior: %d days", sup20);
    printf("\nLake Michigan: %d days", mich20);
    printf("\nLake Huron: %d days", huron20);
    printf("\nLake Erie: %d days", erie20);
    printf("\nLake Ontario: %d days", ont20);
    printf("\nLake St. Clair: %d days", stClr20);
    printf("\n\nQuestion 8.");
    /*QUESTION 8. CALCULATE NUMBER OF DAYS LAKES ARE FROZEN (<0 DEGREES)*/
    int sup0=0, mich0=0, huron0=0 , erie0=0, ont0=0 , stClr0=0 ;
    for (i = 0; i < 365; i++) {
        if (sp[i] < 0) {
            sup0++;
        }
        if (mch[i] < 0) {
            mich0++;
        }
        if (hrn[i] < 0) {
            huron0++;
        }
        if (erie[i] < 0) {
            erie0++;
        }
        if (ont[i] < 0) {
            ont0++;
        }
        if (stclr[i] < 0) {
            stClr0++;
        }
    }
    printf("\nNumber of days in which the lakes are frozen:\n");
    printf("Lake Superior: %d days", sup0);
    printf("\nLake Michigan: %d days", mich0);
    printf("\nLake Huron: %d days", huron0);
    printf("\nLake Erie: %d days", erie0);
    printf("\nLake Ontario: %d days", ont0);
    printf("\nLake St. Clair: %d days", stClr0);
    printf("\n\nQuestion 9.");
    /*QUESTION 9. REPEAT QUESTION 1 BUT WITH ANOTHER FILE CONTAINING 2020 DATA*/
    year = 0;
    dayVl = 0;
    double supe2020, huro2020, michi2020, eriee2020, onta2020, stclir2020;
    double sumSuper2020, sumMichi2020, sumHuron2020, sumErie2020, sumOnt2020, sumClar2020, sumAll2020;
    int dayCount2020 = 0;
    FILE *in2020 = fopen("termprojectdata2020.txt", "r");
    while (fscanf(in2020, "%d %d   %lf   %lf   %lf   %lf   %lf   %lf", &year, &dayVl, &supe2020, &michi2020,
                  &huro2020, &eriee2020, &onta2020, &stclir2020) != EOF) {
        dayCount2020++; //acquire number of days in file, used for finding averages
        sumSuper2020 += supe2020;
        sumMichi2020 += michi2020;
        sumHuron2020 += huro2020;   //find sum of each lake individually so that average can be found
        sumErie2020 += eriee2020;
        sumOnt2020 += onta2020;
        sumClar2020 += stclir2020;

    }
    sumAll2020 = sumSuper + sumMichi + sumClar + sumOnt + sumErie + sumHuron; //obtain sum of all temps in all lakes,
    // divide by daycnt and 6 to get avg temp of lakes

    double avgSup2020 = sumSuper2020 / dayCount2020;
    double avgMich2020 = sumMichi2020 / dayCount2020;
    double avgHuron2020 = sumHuron2020 / dayCount2020;  //obtain average temp of each lake individually
    double avgErie2020 = sumErie2020 / dayCount2020;
    double avgOnt2020 = sumOnt2020 / dayCount2020;
    double avgStClr2020 = sumClar2020 / dayCount2020;
    double avgAll2020 = sumAll2020 / 6 / dayCount2020;

    double supDiff = avgSup-avgSup2020;
    double MichDiff = avgMich-avgMich2020;
    double HuronDiff = avgHuron-avgHuron2020;
    double ErieDiff = avgErie-avgErie2020;
    double OntDiff = avgOnt-avgOnt2020;
    double StClrDiff = avgStClr-avgStClr2020;

    printf("\n");
    printf("| Lake      | 2022 Average | 2020 Average | Difference  |");
    printf("\n---------------------------------------------------------");
    printf("\n| Superior  | %.2lf         | %.2lf         | %.2lf       |", avgSup, avgSup2020, supDiff);
    printf("\n| Michigan  | %.2lf         | %.2lf        | %.2lf       |", avgMich, avgMich2020, MichDiff);
    printf("\n| Huron     | %.2lf         | %.2lf         | %.2lf       |", avgHuron, avgHuron2020, HuronDiff);
    printf("\n| Erie      | %.2lf        | %.2lf        | %.2lf       |", avgErie, avgErie2020, ErieDiff);
    printf("\n| Ontario   | %.2lf        | %.2lf        | %.2lf       |", avgOnt, avgOnt2020, OntDiff);
    printf("\n| St. Clair | %.2lf        | %.2lf        | %.2lf       |", avgStClr, avgStClr2020, StClrDiff);

return(0);
}






