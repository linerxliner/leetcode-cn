/* Complexity
 *   Time: O(n)
 *   Space: O(1)
 */

SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary != (SELECT MAX(Salary) FROM Employee);
