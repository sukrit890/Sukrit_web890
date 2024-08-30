# Write your MySQL query statement below

SELECT MAX(Salary) as SecondHighestSalary
FROM Employee
WHERE salary<(
    SELECT MAX(Salary) 
    FROM Employee
);