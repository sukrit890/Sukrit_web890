# Write your MySQL query statement below
with r as(select d.name as department, e.name as employee, e.salary as salary, dense_rank() over (partition by d.name order by e.salary desc) as rn
from employee e
inner join department d on e.departmentid=d.id)

select department,employee,salary 
from r
where rn<4





