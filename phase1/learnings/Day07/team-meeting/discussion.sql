-- job_title based number_of_employees
select job_title,
       count(*) as count_employees
  from employees
 group by job_title;

    -- city_id based number_of_employees
select city_id,
       count(*)
  from employees
 group by city_id;

    -- find number_of_employees, total salary based on job title, 
select job_title,
       count(*) as number_of_employees,
       sum(salary) as sum_of_salary
  from employees
 group by job_title;


    -- find number_of_employees, total salary
    -- min salary, max salary, average salary
select count(*) as number_of_employees,
       sum(salary) as total_salary,
       min(salary) as minimum_salary,
       max(salary) as maximum_salary,
       avg(salary) as average_salary
  from employees;


    -- find total salary each deparment id wise 
select department_id,
       sum(salary) as sum_department_salary
  from employees
 group by department_id;

    -- find number of employees, total salary, min salary, max salary, average salary 
    -- each deparment id wise 
select department_id,
       count(*) as number_of_employees,
       sum(salary) as total_salary,
       min(salary) as minimum_salary,
       max(salary) as maximum_salary,
       avg(salary) as average_salary
  from employees
 group by department_id;

    -- find emp name, country name
    -- inner join
select employees.name as employee_name,
       countries.name as country_name
  from employees
 inner join cities
on employees.city_id = cities.id
 inner join countries
on cities.country_id = countries.id;

    -- left join
select employees.name as employee_name,
       countries.name as country_name
  from employees
  left join cities
on employees.city_id = cities.id
  left join countries
on cities.country_id = countries.id;