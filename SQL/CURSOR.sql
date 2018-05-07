IF (exists (select * from sys.objects where name = 'proc_cursor'))
    DROP PROCEDURE proc_cursor
GO
CREATE PROCEDURE proc_cursor -- 存储过程
AS
DECLARE @Sno char(9)--定义变量
DECLARE @Sname char(20)--定义变量

DECLARE mycursor CURSOR FOR select Sno,Sname from Student --声明游标

OPEN mycursor  --打开游标

FETCH NEXT FROM mycursor INTO @Sno,@Sname

WHILE(@@FETCH_STATUS=0)  --遍历所有的数据
BEGIN
	PRINT '游标成功取出一条数据:'
	PRINT @Sno
	PRINT @Sname
	PRINT '********************'
	FETCH NEXT FROM mycursor INTO @Sno,@Sname  --取下一条游标数据
END

CLOSE mycursor --关闭游标

DEALLOCATE mycursor --删除游标
GO

EXEC proc_cursor
GO