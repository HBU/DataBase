
--CREATE TABLE StudentInsertLog
--(
--Numbers INT
--)

IF(OBJECT_ID('Student_Count') is not null)        -- 判断名为 Student_Count 的触发器是否存在
DROP TRIGGER Student_Count        -- 删除触发器
GO

CREATE TRIGGER Student_Count
ON Student  	         
AFTER
INSERT
AS 
    INSERT INTO StudentInsertLog(Numbers)
	  SELECT COUNT(*) FROM Student
