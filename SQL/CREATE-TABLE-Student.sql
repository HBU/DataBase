CREATE TABLE Student          
      (Sno   CHAR(9) PRIMARY KEY,        /* 列级完整性约束条件,Sno是主码*/                  
        Sname CHAR(20) UNIQUE,             /* Sname取唯一值*/
        Ssex    CHAR(2),
        Sage   SMALLINT,
        Sdept  CHAR(20)
      ); 
