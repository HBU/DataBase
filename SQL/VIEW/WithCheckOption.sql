create view View_Stu_1
as
select Sno,Sname,Ssex,Sage,Sdept
from Student
where Sdept='IS'

go

create view View_Stu_2
as
select Sno,Sname,Ssex,Sage,Sdept
from Student
where Sdept='IS'
with check option;

go

insert into View_Stu_1(Sno,Sname,Ssex,Sage)--无With check option: 执行正确。  Sdept会自动补充Null。
values ('95007111','张兰11','F','19')

insert into View_Stu_2(Sno,Sname,Ssex,Sage) --有With check option: 执行错误。  没有Sdept会报错，不能够为Sdept自动补充IS。
values ('950072000','李勇00','F','19')

insert into View_Stu_2(Sno,Sname,Ssex,Sage,Sdept) --有With check option: 执行错误。有Sdept为CS，不正常执行。
values ('951000071','王1五','F2','19','CS')

insert into View_Stu_2(Sno,Sname,Ssex,Sage,Sdept) --有With check option: 执行正确。有Sdept为IS，可以正常执行。
values ('95007211','李勇11','F','19','IS')

select * from Student
select * from View_Stu_1
select * from View_Stu_2

-- 结论：
-- 标准SQL中，view 定义中有 with check option，insert 语句可以自动加条件 Sdept = IS，并最终写入表Student。
-- TSQL中，view 定义中有 with check option，insert并不能完成标准SQL的操作，执行语句会报错；仅能完成对 Sdept的 检查。
-- 也就是说，TSQL中，insert必须写Sdept。当 Sdept = IS 时，正确；Sdept = CS 时，报错。
