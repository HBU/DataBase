
--CREATE TABLE StudentInsertLogUser
--(
--  UserName nchar(10),
--  DateAndTime datetime
--)

IF(OBJECT_ID('Student_Time') is not null)        -- 判断名为 Student_Count 的触发器是否存在
DROP TRIGGER Student_Time        -- 删除触发器
GO

CREATE TRIGGER Student_Time
ON Student  	         
AFTER
INSERT
AS 
	declare @UserName    nchar(10)
	declare @DateTime    datetime

	select @UserName = system_user
	select @DateTime = CONVERT(datetime,GETDATE(),120) --2018-04-11 16:33:10

	INSERT INTO StudentInsertLogUser(UserName,DateAndTime)
	VALUES (@UserName,@DateTime)
