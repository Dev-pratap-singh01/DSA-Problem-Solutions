/*import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class A {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(10, 3, 4, 7, 8, 12, 13, 4, 10);

        List<Integer> evenNumbers = numbers.stream()
            .filter(n -> n % 2 == 0)
            .distinct()
            .sorted()
            .collect(Collectors.toList());

        System.out.println("Even Numbers: " + evenNumbers);
    }
}



import java.util.*;
import java.util.stream.*;

public class SquareOfNumbers {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(2, 3, 4, 5, 6);

        List<Integer> squares = numbers.stream()
            .map(n -> n * n)                     
            .collect(Collectors.toList());       

        System.out.println("Squares: " + squares);
    }
}


import java.util.*;
import java.util.stream.*;

public class CountGreaterThanFiveSorted {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(3, 6, 1, 8, 5, 9, 2, 10, 8, 6, 9);

        List<Integer> filteredSorted = numbers.stream()
            .filter(n -> n > 5)        
            .distinct()                
            .sorted()                  
            .collect(Collectors.toList());

        
        long count = filteredSorted.size();

        
        System.out.println("Numbers > 5 (distinct & sorted): " + filteredSorted);
        System.out.println("Count: " + count);
    }
}*/


import java.time.*;
import java.time.format.DateTimeFormatter;

public class DateTimeDemo {
    public static void main(String[] args) {

        
        LocalDate date = LocalDate.of(2025, 7, 7);
        System.out.println("LocalDate: " + date);

        
        LocalTime time = LocalTime.of(14, 30, 0);
        System.out.println("LocalTime: " + time);

        
        LocalDateTime dateTime = LocalDateTime.of(date, time);
        System.out.println("LocalDateTime: " + dateTime);

        
        ZonedDateTime zonedDateTime = ZonedDateTime.of(dateTime, ZoneId.of("Asia/Kolkata"));
        System.out.println("ZonedDateTime: " + zonedDateTime);

       
        LocalDate startDate = LocalDate.of(2022, 1, 1);
        LocalDate endDate = LocalDate.of(2025, 7, 7);
        Period period = Period.between(startDate, endDate);
        System.out.println("Period: " + period.getYears() + " years, " +
                period.getMonths() + " months, " + period.getDays() + " days");

        
        LocalTime startTime = LocalTime.of(9, 0, 0);
        LocalTime endTime = LocalTime.of(14, 30, 0);
        Duration duration = Duration.between(startTime, endTime);
        System.out.println("Duration: " + duration.toHours() + " hours, " +
                duration.toMinutesPart() + " minutes");

        
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String formatted = dateTime.format(formatter);
        System.out.println("Formatted LocalDateTime: " + formatted);
    }
}




