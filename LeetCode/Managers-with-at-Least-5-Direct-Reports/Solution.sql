select m.name from employee e join employee m where e.managerId=m.id group by e.managerId having count(*)>=5;
