# Write your MySQL query statement below

select (select distinct salary from Employee order by salary desc limit 1,1) as SecondHighestSalary
;


#LIMIT 1, 1 → pehli row skip, agali row return.



#LIMIT 1 OFFSET 1 → same kaam, bas likhne ka doosra tarika.



#SELECT (subquery) → agar subquery koi row nahi deti, toh NULL milta hai.