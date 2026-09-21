# Write your MySQL query statement below
# hame ese custimer ki ids batani hai jisne koi transactions nahi kiye hai 

select v.customer_id , count(customer_id ) as count_no_trans
from Visits v 
left join Transactions t 
on v.visit_id  = t.visit_id 
where t.transaction_id is NULL
group by customer_id;