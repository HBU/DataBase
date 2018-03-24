 	CREATE TABLE  SC
          (Sno  CHAR(9), 
           Cno  CHAR(4),  
           Grade  SMALLINT,
           PRIMARY KEY (Sno,Cno),  
                          /* 主码由两个属性构成，必须作为表级完整性进行定义*/
           FOREIGN KEY (Sno) REFERENCES Student(Sno),
                         /* 表级完整性约束条件，Sno是外码，被参照表是Student */
           FOREIGN KEY (Cno)REFERENCES Course(Cno)
                         /* 表级完整性约束条件， Cno是外码，被参照表是Course*/
        ); 
