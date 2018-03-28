SELECT Sno,Sname                -- ③ 最后在Student关系中取出Sno和Sname
  	FROM    Student                          
 	WHERE Sno  IN
             (SELECT Sno                    -- ② 然后在SC关系中找出选修了3号课程的学生学号
              FROM    SC                        
              WHERE  Cno IN
                     (SELECT Cno             --① 首先在Course关系中找出“信息系统”的课程号，为3号
                       FROM Course           
                       WHERE Cname= '信息系统'                      
		                  )
              );

SELECT Student.Sno,Sname
FROM    Student,SC,Course
WHERE Student.Sno = SC.Sno  AND
	 SC.Cno = Course.Cno AND
	 Course.Cname='信息系统';
