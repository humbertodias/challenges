package problems;

import java.time.DayOfWeek;
import java.time.LocalDate;

/**
 * Created by humberto.dias on 27/06/2017.
 */
public class Problem019 {

    public static int solve ()  {
        int sundayMonths = 0; // number to return; number of months that start with Sunday

		/*
		 * leap year if year is divisible by 4,
		 * but not on a century unless century is divisible by 400
		 */
        boolean leapYear = false;

        int dayOfWeek = 1;    // 1-7, the day of the week

		/*
		 * 1 Jan 1900 is Monday (dayOfWeek = 1),
		 * but we want to start on 1 Jan 1901, which is
		 * one (non-leap year) year later:
		 */
        dayOfWeek += 365%7;

        for (int y=1901; y<=2000; y++) { // years given in problem

            if (y%100 == 0) { // on a century
                leapYear = (y%400 == 0) ? true : false;
            } else {
                leapYear = (y%4 == 0) ? true : false;
            }

            int days = 0; // number of days in the month
            for (int m=1; m<=12; m++) { // months of the year

                if (dayOfWeek == 7) { // SUNDAY!!!
                    sundayMonths++;
                }

                switch (m) { // calculate number of days per month
                    case 2: days = (leapYear) ? 29 : 28; break;
                    case 4: case 6: case 9: case 11: days = 30; break;
                    default: days = 31; break;
                }

                for (int d=1; d<=days; d++) { // days of month
                    dayOfWeek++;
                    if (dayOfWeek > 7) { dayOfWeek = 1; }
                }

            }
        }

        return sundayMonths;
    }

    public static void main(String ... args) {
        System.out.println(solve());
    }

}
