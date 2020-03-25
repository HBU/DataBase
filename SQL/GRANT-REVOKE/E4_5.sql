--[例4.5] 把对表SC的INSERT权限授予U5用户，并允许他再将此权限授予其他用户
     
    GRANT INSERT 
    ON SC 
    TO U5
    WITH GRANT OPTION;
