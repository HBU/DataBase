--[例4.4] 把查询Student表和修改学生学号的权限授给用户U4
　 
	  	GRANT UPDATE(Sno), SELECT 
		ON  Student 
		TO U4;
